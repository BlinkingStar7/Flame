#include <bits/stdc++.h>
using namespace std;

const int MAX = 3005;
int N, A[MAX], X, Y;
int memo[MAX][MAX], cost[MAX][MAX], psum[MAX];

int Solve(int bef, int cur) {
	if (cur == N+1) {
		return (psum[N]-psum[bef] - (N-bef)*A[bef])*X;
	}

	int &ret = memo[bef][cur];
	if (ret != -1) return ret;

	ret = Solve(bef, cur+1);
	ret = min(ret, Solve(cur, cur+1) + Y + cost[bef][cur]);

	return ret;
}

int main() {
	scanf("%d", &N);
	for (int i=1; i<=N; ++i) {
		scanf("%d", &A[i]);
	}
	scanf("%d%d", &X, &Y);

	sort(A, A+N+1);
	for (int i=1; i<MAX; ++i) {
		psum[i] = A[i] + psum[i-1];
	}

	for (int i=0; i<=N; ++i) {
		queue<int> q;
		int c = 0;
		for (int j=i+2; j<=N; ++j) {
			q.push(A[j-1]);
			c += q.size() * (A[j] - A[j-1]);
			
			while (!q.empty()) {
				int cur = q.front();
				if (cur-A[i] <= A[j]-cur) {
					c += (cur-A[i]) - (A[j]-cur);
					q.pop();
				}
				else
					break;
			}

			cost[i][j] = c*X;
		}
	}

	memset(memo, -1, sizeof(memo));
	printf("%d\n", Solve(0, 1));
	return 0;
}



