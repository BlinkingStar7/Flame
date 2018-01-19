#include <bits/stdc++.h>
using namespace std;

int A[15];
int main() {
	int t = 1;
	for (int i=0; i<3; ++i) {
		int tt;
		scanf("%d", &tt);
		t*=tt;
	}

	while (t) {
		A[t%10]++;
		t/=10;
	}

	for (int i=0; i<10; ++i)
		printf("%d\n", A[i]);
	return 0;
}

