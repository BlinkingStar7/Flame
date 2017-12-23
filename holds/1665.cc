#include <bits/stdc++.h>
using namespace std;

const int MAX = 1005;
int N, M, A[MAX][2], B[MAX][2];
int main() {
	scanf("%d", &N);
	for (int i=0; i<N; ++i)
		scanf("%d%d", &A[i][0], &A[i][1]);

	scanf("%d", &M);
	for (int i=0; i<M; ++i)
		scanf("%d%d", &B[i][0], &B[i][1]);

	vector<pair<int, int> > v;
	for (int i=0; i<N; ++i) for (int j=0; j<M; ++j) {
		v.push_back(make_pair(A[i][0]+B[j][0], 1));
		v.push_back(make_pair(A[i][0]+B[j][1]+1, -1));
		v.push_back(make_pair(A[i][1]+1+B[j][0], -1));
		v.push_back(make_pair(A[i][1]+1+B[j][1]+1, 1));
	}
	sort(v.begin(), v.end());

	int d = 0, cur = 0, bef = 0, best = 0, ans;
	for (auto it : v) {
		cur += d*(it.first - bef);
		bef = it.first;
		d += it.second;
		if (cur > best) {
			best = cur;
			ans = it.first;
		}
	}

	printf("%d\n", ans-2);
	return 0;
}
