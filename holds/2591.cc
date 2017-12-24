#include <bits/stdc++.h>
using namespace std;

char A[44];
int dp[44];
int main() {
	scanf("%s", A);

	dp[strlen(A)] = 1;
	for (int i=strlen(A)-1; i>=0; --i) {
		if (A[i] != '0') {
			dp[i] = dp[i+1];
			if (A[i] <= '2' || (A[i] == '3' && A[i+1] && A[i+1] <= '4'))
				dp[i] += dp[i+2];
		}
	}

	printf("%d\n", dp[0]);
	return 0;
}


