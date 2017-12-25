#include <bits/stdc++.h>
using namespace std;

int main() {
	int maxVal = -1, pos;
	for (int i=0; i<81; ++i) {
		int t;
		scanf("%d", &t);

		if (maxVal < t) {
			maxVal = t;
			pos = i;
		}
	}

	printf("%d\n%d %d\n", maxVal, pos/9+1, pos%9+1);
	return 0;
}

