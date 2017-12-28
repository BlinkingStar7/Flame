#include <bits/stdc++.h>
using namespace std;

const int MAX = 10005;
int N, A[MAX];
vector<pair<int, int> > ans;

void sw(int a, int b) {
	while (a < b) {
		swap(A[a], A[b]);
		a++, b--;
	}
}

void Solve(int cur) {
	if (cur > 3) return;
	bool fin = 1;
	for (int i=1; i<=N; ++i) {
		if (A[i] != i) {
			fin = 0;
			break;
		}
	}

	if (fin) {
		while (ans.size() < 3)
			ans.push_back(make_pair(1, 1));

		for (auto it : ans)
			printf("%d %d\n", it.first, it.second);
		exit(0);
	}

	vector<int> st;
	st.push_back(1);
	for (int i=1; i<=N; ++i) {
		if (abs(A[i]-A[i+1]) != 1) {
			st.push_back(i);
			st.push_back(i+1);
		}
	}
	st.pop_back();

	sort(st.begin(), st.end());
	st.erase(unique(st.begin(), st.end()), st.end());

	if (cur == 2 && st.size() > 6) return;
	if (cur == 1 && st.size() > 10) return;
	for (int i=0; i<st.size(); ++i) for (int j=i+1; j<st.size(); ++j) {
		int a = st[i], b = st[j];
		sw(a, b);
		ans.push_back(make_pair(a, b));
		Solve(cur+1);
		ans.pop_back();
		sw(a, b);
	}
}


int main() {
	scanf("%d", &N);

	for (int i=1; i<=N; ++i)
		scanf("%d", &A[i]);
	A[N+1] = -123;
	Solve(0);
	return 0;

}
