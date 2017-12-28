#include <bits/stdc++.h>
using namespace std;

const int MAX = 505, MOD = 1000;
int N, P[MAX], D[MAX], G[MAX], memo[MAX][MAX];
int Solve(int a, int b) {
	int &ret = memo[a][b];
	if (ret != -1) return ret;

	ret = 0;
	for (int next=max(a,b)+1; next<N-1; ++next) {
		if (P[next] - P[a] <= D[a]) ret = (ret + Solve(next, b))%MOD;
		if (G[next] && P[next] - P[b] <= D[next]) ret = (ret + Solve(a, next))%MOD;
	}

	if (P[N-1] - P[a] <= D[a] && P[N-1] - P[b] <= D[N-1])
		ret = (ret + 1)%MOD;

	return ret;
}

int main() {
	scanf("%d", &N);
	
	for (int i=0; i<N; ++i)
		scanf("%d%d%d", &P[i], &D[i], &G[i]);

	memset(memo, -1, sizeof(memo));
	printf("%d\n", Solve(0, 0));

	return 0;
}

