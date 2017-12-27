#include <bits/stdc++.h>
using namespace std;

int N, A[10005];
vector<pair<int, int> > ans;

void sw(int a, int b) {
	for (int i=a, j=b; i<j; ++i, --j)
		swap(A[i], A[j]);
}

void Solve() {
	if (ans.size() > 2) return;
	int f = -1;
	for (int i=1; i<=N; ++i)
		if (A[i] != i) {
			f = i;
			break;
		}

	if (f == -1) {
		if (ans.size() == 2) {
			for (auto it : ans) 
				printf("%d %d\n", it.first, it.second);
			exit(0);
		}
		ans.push_back(make_pair(1, 1));
		Solve();
	}

	int a = f, b = A[f];
	if (a > b) swap(a, b);
	sw(a, b);
	ans.push_back(make_pair(a, b));
	Solve();
	ans.pop_back();
	sw(a, b);

	int a = f, b = A[f];
	if (a > b) swap(a, b);
	sw(a, b);
	ans.push_back(make_pair(a, b));
	Solve();
	ans.pop_back();
	sw(a, b);

	for (int i=N; i>=1; --i)
		if (A[i] != i) {
			f = i;
			break;
		}

	a = f, b = A[f];
	if (a > b) swap(a, b);
	sw(a, b);
	ans.push_back(make_pair(a, b));
	Solve();
	ans.pop_back();
	sw(a, b);
}

int main() {
	scanf("%d", &N);
	for (int i=1; i<=N; ++i)
		scanf("%d", &A[i]);

	Solve();
	return 0;
}


