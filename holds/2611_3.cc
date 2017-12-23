#include <bits/stdc++.h>
using namespace std;

const int MAX = 1005;
int N, M, dp[MAX], in[MAX], prv[MAX];
vector<pair<int, int> > adj[MAX];

void f(int cur) {
	if (--in[cur]) return;

	for (int i=0; i<adj[cur].size(); ++i) {
		if (dp[cur] + adj[cur][i].second > dp[adj[cur][i].first]) {
			dp[adj[cur][i].first] = dp[cur] + adj[cur][i].second;
			prv[adj[cur][i].first] = cur;
		}
		f(adj[cur][i].first);
	}
}

int main() {
	scanf("%d%d", &N, &M);

	for (int i=0; i<M; ++i) {
		int a, b, r;
		scanf("%d%d%d", &a, &b, &r);
		if (b == 1) b = 0;
		adj[b].push_back(make_pair(a, r));
		in[a]++;
	}

	in[0] = 1;
	f(0);

	printf("%d\n", dp[1]);
	for (int i=1; i; i=prv[i])
		printf("%d ",i);
	printf("1\n");
	return 0;
}
