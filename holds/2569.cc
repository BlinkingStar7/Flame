#include <bits/stdc++.h>
using namespace std;

int N, V[1005], ans;
pair<int, int> A[1005];

int main() {
	scanf("%d", &N);

	for (int i=0; i<N; ++i) {
		scanf("%d", &A[i].first);
		A[i].second = i;
	}

	sort(A, A+N);
	for (int i=0; i<N; ++i) if (!V[i]) {
		int num = 0;
		for (int cur=i; !V[cur]; cur=A[cur].second) {
			V[cur] = true;
			ans += A[cur].first;
			++num;
		}
		ans += min((num-2)*A[i].first, A[i].first + (num+1)*A[0].first);
	}
	printf("%d\n", ans);
	return 0;
}
