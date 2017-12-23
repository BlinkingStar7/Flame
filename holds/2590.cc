#include <bits/stdc++.h>
using namespace std;

int main() {
	int A[10];
	for (int i=1; i<=6; ++i)
		scanf("%d", &A[i]);

	int ans = A[6] + A[5] + A[4] + (A[3]+3)/4;
	int t = A[2];

	A[2] -= min(A[2], A[4]*5);

	if (A[3]%4 == 1) A[2] -= min(A[2], 5);
	if (A[3]%4 == 2) A[2] -= min(A[2], 3);
	if (A[3]%4 == 3) A[2] -= min(A[2], 1);

	ans += (A[2]+8)/9;
	A[1] -= min(A[1], ans*36 - A[6]*36 - A[5]*25 - A[4]*16 - A[3]*9 - t*4);

	ans += (A[1]+35)/36;

	printf("%d\n", ans);
	return 0;
}


	


