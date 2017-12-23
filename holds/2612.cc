#include <bits/stdc++.h>
using namespace std;

const int MAX = 1005;
int N, M, an, bn, dp[MAX][MAX];
char A[MAX], B[MAX], aa[MAX], bb[MAX];

int main() {
	scanf("%d%s%d%s", &N, A, &M, B);

	int ii = N-1, jj = M-1;
	for (int i=N-1; i>=0; --i) for (int j=M-1; j>=0; --j) {
		dp[i][j] = max(dp[i][j], max(dp[i+1][j], dp[i][j+1])-2);
		dp[i][j] = max(dp[i][j], dp[i+1][j+1] + (A[i]==B[j] ? 3 : -2));

		if (dp[i][j] > dp[ii][jj])
			ii = i, jj = j;

	}

	printf("%d\n", dp[ii][jj]);
	while (dp[ii][jj]) {
		if (dp[ii][jj] == dp[ii+1][jj]-2) aa[an++] = A[ii++];
		else if (dp[ii][jj] == dp[ii][jj+1]-2) bb[bn++] = B[jj++];
		else aa[an++] = A[ii++], bb[bn++] = B[jj++];
	}

	printf("%s\n%s\n", aa, bb);
	return 0;
}
