#include <bits/stdc++.h>
using namespace std;

const int MAX = 1005;
int N, M, dp[MAX], bt[MAX], ans[MAX], an, A[MAX], nn, V[MAX];
vector<pair<int, int> > adj[MAX];

void dfs(int cur) {
	V[cur] = true;
	for (auto it : adj[cur]) {
		int next = it.first;
		if (!V[next])
			dfs(next);
	}

	A[nn++] = cur;
}
	
int main() {
	scanf("%d%d", &N, &M);

	for (int i=0; i<M; ++i) {
		int p, q, r;
		scanf("%d%d%d", &p, &q, &r);
		--p, --q;

		adj[p].push_back(make_pair(q, r));
	}

	dfs(0);

	for (int i=N-1; i>=0; --i) {
		for (auto it : adj[A[i]]) {
			int cand = dp[A[i]] + it.second;
			if (cand > dp[it.first]) {
				dp[it.first] = cand;
				bt[it.first] = A[i];
			}
		}
	}

	printf("%d\n", dp[0]);
	ans[an++] = 0;
	for (int i=bt[0]; i != 0; i=bt[i])
		ans[an++] = i;
	ans[an++] = 0;

	for (int i=an-1; i>=0; --i)
		printf("%d ", ans[i]+1);
	return 0;
}
