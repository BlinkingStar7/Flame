#include <bits/stdc++.h>
using namespace std;

int main() {
	scanf("%s", A);

	for (int i=strlen(A)-1; i>=0; --i) {
		if (A[i] >= '4' || (A[i] == '3' && A[i+1] >= '5'))
			dp[i] = dp[i+1];
		else
			dp[i] = dp[i+1] + dp[
