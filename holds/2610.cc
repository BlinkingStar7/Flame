#include <bits/stdc++.h>
using namespace std;

const int INF = 1e5;
int N, M, D[105][105], maxVal[105], V[105];
vector<int> ans;

int dfs(int cur) {
	V[cur] = true;

	maxVal[cur] = 0;
	for (int i=0; i<N; ++i) if (D[cur][i] != INF)
		maxVal[cur] = max(maxVal[cur], D[cur][i]);

	int ret = cur;
	for (int next=0; next<N; ++next) if (D[cur][next] != INF && !V[next]) {
		int cand = dfs(next);
		if (maxVal[cand] < maxVal[ret])
			ret = cand;
	}

	return ret;
}

int main() {
	scanf("%d%d", &N, &M);

	for (int i=0; i<N; ++i) for (int j=0; j<N; ++j)
		D[i][j] = i == j ? 0 : INF;

	for (int i=0; i<M; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		D[a][b] = D[b][a] = min(D[b][a], 1);
	}
	
	for (int k=0; k<N; ++k)	for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
		D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
	}

	for (int i=0; i<N; ++i) if (!V[i]) {
		ans.push_back(dfs(i));
	}

	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int it : ans)
		printf("%d\n", it+1);

	return 0;
}
