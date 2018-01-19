#include <bits/stdc++.h>
using namespace std;

int A[10], B[10][10], ans;
bool Solve(int x) {
	for (int i=0; i<6; ++i) for (int j=0; j<6; ++j) {
		bool can = true;
		for (int t=0; t<x; ++t) for (int tt=0; tt<x; ++tt)
			if (B[i+t][j+tt]) {
				can = false;
				break;
			}

		if (can) {
			for (int t=0; t<x; ++t) for(int tt=0; tt<x; ++tt)
				B[i+t][j+tt] = true;
			return true;
		}
	}

	return false;
}

int main() {
	for (int i=1; i<=6; ++i)
		scanf("%d", &A[i]);

	memset(B, 1, sizeof(B));

	while (1) {
		bool end = true;
		for (int i=1; i<=6; ++i)
			end = end && (A[i] == 0);

		if (end) break;
		++ans;

		for (int i=0; i<6; ++i)
			for (int j=0; j<6; ++j)
				B[i][j] = 0;

		for (int i=6; i>=1; --i) {
			for (int j=A[i]; j>=1; --j) {
				if (Solve(i))
					--A[i];
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
