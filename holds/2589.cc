#include <bits/stdc++.h>
using namespace std;

const int MAX = 55;
int N, M, V[MAX][MAX], dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0}, maxVal;
char A[MAX][MAX];

int main() {
	scanf("%d%d", &N, &M);
	
	for (int i=1; i<=N; ++i) {
		scanf("%s", &A[i][1]);
	}

	for (int i=1; i<=N; ++i) for (int j=1; j<=M; ++j) if (A[i][j] == 'L') {
		queue<pair<int, int> > q;
		q.push(make_pair(i, j));

		memset(V, -1, sizeof(V));
		V[i][j] = 0;

		while (!q.empty()) {
			int y = q.front().first, x = q.front().second;
			q.pop();

			for (int d=0; d<4; ++d) {
				int yy = y+dy[d], xx = x+dx[d];
				if (A[yy][xx] == 'L' && V[yy][xx] == -1) {
					q.push(make_pair(yy, xx));
					V[yy][xx] = V[y][x] + 1;
					if (V[yy][xx] > maxVal) maxVal = V[yy][xx];
				}
			}
		}
	}

	printf("%d\n", maxVal);
	return 0;
}
