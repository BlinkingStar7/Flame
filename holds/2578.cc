#include <bits/stdc++.h>
using namespace std;

int A[5][5], B[15], n;
int main() {
	for (int i=0; i<5; ++i) for (int j=0; j<5; ++j)
		scanf("%d", &A[i][j]);

	for (int it=0; it<25; ++it) {
		int t;
		scanf("%d", &t);

		for (int i=0; i<5; ++i) for (int j=0; j<5; ++j) {
			if (A[i][j] == t) {
				if (++B[i] == 5) ++n;
				if (++B[j+5] == 5) ++n;
				if (i == j && ++B[10] == 5) ++n;
				if (i+j == 4 && ++B[11] == 5) ++n;
			}
		}
		if (n >= 3) { printf("%d\n", it+1); break; }
	}
	return 0;
}
