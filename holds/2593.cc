#include <bits/stdc++.h>
using namespace std;

const int MAX = 105;
int N, M, aa, bb, A[MAX][2], x, y, V[MAX], prv[MAX];
vector<int> adj[MAX];

int gcd(int a, int b) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	int ret = gcd(b, a%b);
	int xx = y;
	int yy = x-a/b*y;
	x = xx, y = yy;
	return ret;
}

int main() {
	scanf("%d%d", &N, &M);

	for (int i=1; i<=M; ++i) for (int j=0; j<2; ++j)
		scanf("%d", &A[i][j]);

	scanf("%d%d", &aa, &bb);
	swap(aa, bb);
	if (aa == bb) {
		printf("0\n");
		return 0;
	}

	for (int i=1; i<=M; ++i) for (int j=i+1; j<=M; ++j) {
		int a=A[i][0], b=A[i][1], c=A[j][0], d=A[j][1];

		int g = gcd(b, d);
		if ((c-a)%g) continue;
		if (a == c) {
			adj[i].push_back(j);
			adj[j].push_back(i);
			continue;
		}
			

		long long root = a + b*x*((c-a)/g);
		long long mod = abs(b*(d/g));

		int r = ((root-max(a,c))%mod + mod)%mod;
		if (r <= N-max(a,c)) {
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
	}

	for (int i=1; i<=M; ++i) {
		if (aa >= A[i][0] && aa%A[i][1] == A[i][0]%A[i][1])
			adj[0].push_back(i);
		if (bb >= A[i][0] && bb%A[i][1] == A[i][0]%A[i][1])
			adj[i].push_back(M+1);
	}


	queue<int> q;
	q.push(0);
	memset(V, -1, sizeof(V));
	V[0] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : adj[cur])
			if (V[next] == -1) {
				V[next] = V[cur] + 1;
				prv[next] = cur;
				q.push(next);
			}
	}

	if (V[M+1] == -1) {
		printf("-1\n");
		return 0;
	}

	printf("%d\n", V[M+1]-1);
	for (int i=prv[M+1]; i; i=prv[i])
		printf("%d\n", i);
	return 0;
}
