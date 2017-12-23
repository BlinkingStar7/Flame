#include <bits/stdc++.h>
using namespace std;

int B[1005];
int main() {
	int best = -1, sum=0;
	for (int i=0; i<10; ++i) {
		int t;
		scanf("%d", &t);
		sum += t;
		B[t]++;

		if (best == -1 || B[t] > B[best]) {
			best = t;
		}
	}

	printf("%d\n%d\n", sum/10, best);
	return 0;
}



