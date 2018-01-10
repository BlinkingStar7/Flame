#include <bits/stdc++.h>
using namespace std;

int main() {
	int A, B;
	scanf("%d%d", &A, &B);
	int t = B;

	while (t) {
		printf("%d\n", A*(t%10));
		t/=10;
	}

	printf("%d\n", A*B);
	return 0;
}

