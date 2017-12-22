#include <bits/stdc++.h>
using namespace std;

int sum, A[10];
int main() {
	for (int i=0; i<5; ++i) {
		scanf("%d", &A[i]);
		sum += A[i];
	}

	sort(A, A+5);

	printf("%d\n%d\n", sum/5, A[2]);
	return 0;
}
