#include <bits/stdc++.h>
using namespace std;

int N, A[105];
int main() {
	scanf("%d", &N);
	for (int i=0; i<N; ++i)
		A[i] = i+1;

	for (int i=0; i<N; ++i) {
		int t;
		scanf("%d", &t);
		for (int j=0; j<t; ++j)
			swap(A[i-j], A[i-j-1]);
	}

	for (int i=0; i<N; ++i)
		printf("%d ", A[i]);

	return 0;
}
