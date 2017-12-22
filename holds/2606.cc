#include <bits/stdc++.h>
using namespace std;

int N, M, V[105];
vector<int> adj[105];
int dfs(int cur) {
	V[cur] = true;

	int ret = 1;
	for (int next : adj[cur]) if (!V[next]) {
		ret += dfs(next);
	}

	return ret;
}

int main() {
	scanf("%d%d", &N, &M);

	for (int i=0; i<M; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	printf("%d\n", dfs(1) - 1);
	return 0;
}


