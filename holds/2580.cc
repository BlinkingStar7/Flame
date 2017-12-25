#include <bits/stdc++.h>
using namespace std;

int A[10][10], row[10][10], col[10][10], box[10][10], choice[10][10];
void Solve() {
	int y = -1, x = -1;
	for (int i=0; i<9; ++i) for (int j=0; j<9; ++j) {
		if (A[i][j] == 0) {
			int t = 0;
			for (int num=1; num<=9; ++num) 
				if (!row[i][num] && !col[j][num] && !box[i/3*3+j/3][num])
					t++;
			choice[i][j] = t;
			if (y == -1 || choice[y][x] > choice[i][j]) {
				y = i;
				x = j;
			}
		}
	}

	if (y == -1) {
		for (int i=0; i<9; ++i) for (int j=0; j<9; ++j)
			printf("%d%c", A[i][j], j==8 ? '\n' : ' ');
		exit(0);
	}

	for (int num=1; num<=9; ++num) if (!row[y][num] && !col[x][num] && !box[y/3*3+x/3][num]) {
		row[y][num] = true;
		col[x][num] = true;
		box[y/3*3+x/3][num] = true;

		A[y][x] = num;
		Solve();
		A[y][x] = 0;

		row[y][num] = false;
		col[x][num] = false;
		box[y/3*3+x/3][num] = false;
	}

}


int main() {
	for (int i=0; i<9; ++i) for (int j=0; j<9; ++j) {
		scanf("%d", &A[i][j]);

		if (A[i][j]) {
			row[i][A[i][j]] = true;
			col[j][A[i][j]] = true;
			box[i/3*3+j/3][A[i][j]] = true;
		}
	}

	Solve();

	return 0;
}

