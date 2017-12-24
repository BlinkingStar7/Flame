#include <bits/stdc++.h>
using namespace std;

int A, B;
int main() {
	scanf("%d%d", &A, &B);

	int sum = 0, fst;
	for (int i=A; i<=B; ++i) {
		if (i == 1) continue;
		int j;
		for (j=2; j*j<=i; ++j)
			if (i%j == 0) break;

		if (j*j > i) {
			if (sum == 0) fst = i;
			sum += i;
		}
	}

	printf("%d\n", sum ? sum : -1);
	if (sum) printf("%d\n", fst);
	return 0;
}
