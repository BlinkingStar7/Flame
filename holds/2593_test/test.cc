#include <bits/stdc++.h>
using namespace std;

const int MAX = 105;

int x, y, N, A[2][2];
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
	scanf("%d", &N);

	for (int i=1; i<=2; ++i) for (int j=0; j<2; ++j)
		scanf("%d", &A[i][j]);


	for (int i=1; i<=2; ++i) for (int j=i+1; j<=2; ++j) {
		long long a=A[i][0], b=A[i][1], c=A[j][0], d=A[j][1];

		long long g = gcd(b, d);
		if ((c-a)%g) continue;
		if (a == c) {
			printf("Yes\n");
			return 0;
		}
			

		long long root = a + b*x*((c-a)/g);
		long long mod = abs(b*(d/g));

		int r = ((root-max(a,c))%mod + mod)%mod;
		if (r <= N-max(a,c)) {
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");

	return 0;
}
