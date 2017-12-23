#include <bits/stdc++.h>
using namespace std;

const int MAX = 1005;
int N, M, dp[MAX], bt[MAX], ans[MAX], an; 
vector<pair<int, int> > adj[MAX];
	
int main() {
	scanf("%d%d", &N, &M);

	for (int i=0; i<M; ++i) {
		int p, q, r;
		scanf("%d%d%d", &p, &q, &r);
		--p, --q;

		adj[p].push_back(make_pair(q, -r));
	}


	for (int z=0; z<=N; ++z) {
		for (int i=0; i<N; ++i) {
			for (auto it : adj[i]) {
				int next = it.first, w = it.second;
				if (z != N && next == 0) continue;
				int cand = dp[i] + w;
				if (cand < dp[next]) {
					dp[next] = cand;
					bt[next] = i;
				}
			}
		}
	}

	printf("%d\n", -dp[0]);
	ans[an++] = 0;
	for (int i=bt[0]; i != 0; i=bt[i])
		ans[an++] = i;
	ans[an++] = 0;

	for (int i=an-1; i>=0; --i)
		printf("%d ", ans[i]+1);
	return 0;
}
