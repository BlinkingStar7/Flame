#include <bits/stdc++.h>
using namespace std;

int main() {
	int sum = 0, minVal = 101;
	for (int i=0; i<7; ++i) {
		int t;
		scanf("%d", &t);
		if (t%2) {
			sum += t;
			minVal = min(minVal, t);
		}
	}

	if (sum == 0) printf("-1\n");
	else printf("%d\n%d\n", sum, minVal);
	return 0;
}

