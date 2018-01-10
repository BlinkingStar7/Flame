#include <bits/stdc++.h>
using namespace std;

const int MAX = 8e4;
int T, N, fw[MAX];
pair<int, int> A[MAX];

int q(int p) {
	int ret = 0;
	for (; p; p-=p&-p)
		ret += fw[p];
	return ret;
}

void u(int p, int v) {
	for (; p<MAX; p+=p&-p)
		fw[p] += v;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);

		vector<int> v;
		for (int i=0; i<N; ++i) {
			scanf("%d%d", &A[i].first, &A[i].second);
			A[i].first = -A[i].first;
			v.push_back(A[i].second);
		}

		sort(A, A+N);
		sort(v.begin(), v.end());

		long long ans = 0;
		memset(fw, 0, sizeof(fw));
		for (int i=0; i<N; ++i) {
			int p = lower_bound(v.begin(), v.end(), A[i].second) - v.begin() + 1;
			ans += q(p);
			u(p, 1);
		}

		printf("%lld\n", ans);
	}

	return 0;
}
