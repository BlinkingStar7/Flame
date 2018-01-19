#include <bits/stdc++.h>
using namespace std;

const int MAX = 305;
int N, A[MAX], dp[MAX][3];

int main() {
	scanf("%d", &N);

	for (int i=1; i<=N; ++i) {
		scanf("%d", &A[i]);
	}

	for (int i=1; i<=N; ++i) for (int j=1; j<=2; ++j) {
		if (j>=1)
			dp[i][j] = dp[i-1][j-1] + A[i];
		if (i>=2 && j==1) {
			for (int k=0; k<=2; ++k)
				dp[i][j] = max(dp[i][j], dp[i-2][k] + A[i]);
		}
	}

	printf("%d\n", max(dp[N][1], dp[N][2]));
	return 0;
}

