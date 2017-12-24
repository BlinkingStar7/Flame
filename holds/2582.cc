#include <bits/stdc++.h>
using namespace std;

int N, B[35], ans;
char A[35][35];

void Solve(int cur) {
	if (cur == N) {
		int cand = 0;
		for (int i=0; i<N; ++i)
			cand += min(B[i], N-B[i]);
		cand = min(cand, N*N-cand);
		ans = min(cand, ans);
		return;
	}

	int cand = 0;
	for (int i=0; i<N; ++i)
		cand += min(B[i], N-B[i]);

	if (cand >= ans) return;

	for (int i=0; i<N; ++i)
		B[i] += A[cur][i] == 'T';

	Solve(cur+1);

	for (int i=0; i<N; ++i)
		B[i] += (A[cur][i] == 'T' ? -1 : 1);

	Solve(cur+1);

	for (int i=0; i<N; ++i)
		B[i] -= A[cur][i] == 'H';
}

int main() {
	scanf("%d", &N);

	int num = 0;
	for (int i=0; i<N; ++i) {
		scanf("%s", &A[i][0]);
		for (int j=0; j<N; ++j)
			num += A[i][j] == 'T';
	}

	ans = num;
	Solve(0);
	printf("%d\n", ans);
	return 0;
}

