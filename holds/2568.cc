#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5+5;
pair<int, int> A[MAX];
int N, B[MAX], t[MAX], size;
bool cmp(const pair<int, int> & a, const pair<int, int> &b) {
	return a.second < b.second;
}

int main() {
	scanf("%d", &N);

	for (int i=0; i<N; ++i)
		scanf("%d%d", &A[i].first, &A[i].second);

	sort(A, A+N, cmp);

	for (int i=0; i<N; ++i) {
		int pos = upper_bound(B, B+size, A[i].first) - B;
		B[pos] = A[i].first;
		t[i] = pos;
		if (pos == size) {
			size++;
		}
	}

	vector<int> ans;
	size--;
	for (int i=N-1; i>=0; --i) 
		if (t[i] == size) {
			size--;
		}
		else
			ans.push_back(A[i].first);

	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i=0; i<ans.size(); ++i)
		printf("%d\n", ans[i]);

	return 0;
}
