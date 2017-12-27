#include <bits/stdc++.h>
using namespace std;

int N, A[105][105], dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0}, ans;
int main() {
	scanf("%d", &N);

	for (int i=0; i<N; ++i) {
		int y, x;
		scanf("%d%d", &y, &x);

		for (int j=y; j<y+10; ++j)
			for (int k=x; k<x+10; ++k)
				A[j][k] = 1;
	}

	for (int i=1; i<=100; ++i) for (int j=1; j<=100; ++j) if (A[i][j]) {
		for (int d=0; d<4; ++d) {
			int ii=i+dy[d], jj=j+dx[d];
			if (A[ii][jj] == 0) ++ans;
		}
	}

	printf("%d\n", ans);
	return 0;
}


