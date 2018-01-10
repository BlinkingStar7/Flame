#include <bits/stdc++.h>
using namespace std;

const int MAX = 3e5+5;
int N;
pair<int, int> A[MAX];

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	return a.second != b.second ? a.second < b.second : a.first > b.first;
}
int main() {
	scanf("%d", &N);

	for (int i=0; i<N; ++i) {
		int x, r;
		scanf("%d%d", &x, &r);
		A[i] = make_pair(x-r, x+r);
	}

	sort(A, A+N, cmp);

	map<int, int> m;
	int ans = 0;
	for (int i=0; i<N; ++i) {
		if (m.find(A[i].second) != m.end() && m[A[i].second] <= A[i].first)
			++ans;

		if (m.find(A[i].first) != m.end())
			m[A[i].second] = m[A[i].first];
		else
			m[A[i].second] = A[i].first;
	}

	printf("%d\n", ans+N+1);
	return 0;
}
