#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	return b==0 ? a : gcd(b, a%b);
}

int main() {
	int A, B;
	scanf("%d%d", &A, &B);

	int G = gcd(A,B);
	int L = A/G*B;

	printf("%d\n%d\n", G, L);
	return 0;
}

