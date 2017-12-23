#include <bits/stdc++.h>
using namespace std;

int N, M, A[1000][1000];
int dy[4] = {1,0,-1,0}, dx[4] = {0,1,0,-1};
int ay, ax;

void f(int y, int x, int num, int d) {
	A[y][x] = num;
	if (num == 1) return;
	if (num == M) {
		ay = y;
		ax = x;
	}

	int yy = y+dy[d], xx = x+dx[d];
	if (yy>=N || xx>=N || yy<0 || xx<0 || A[yy][xx] != 0)
		d = (d+1)%4;

	f(y+dy[d], x+dx[d], num-1, d);
}

int main() {
	scanf("%d%d", &N, &M);

	f(0, 0, N*N, 0);
	for (int i=0; i<N; ++i) {
		for (int j=0; j<N; ++j)
			printf("%d ", A[i][j]);
		printf("\n");
	}
	printf("%d %d\n", ay+1, ax+1);
}
