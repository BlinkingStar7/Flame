#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6+5;
int N, ans, A[MAX], B[MAX];

int main() {
	scanf("%d", &N);

	for (int i=0; i<N; ++i) {
		scanf("%d%d", &A[i], &B[i]);
	}

	sort(A, A+N);
	sort(B, B+N);

	int a=0, b=0, num=0, pos=0; 
	while (a<N || b<N) {
		if (b==N || (a<N && A[a]<B[b])) {
			if (num) ans += A[a] - pos;
			num++;
			pos = A[a++];
		}
		else {
			if (num) ans += B[b] - pos;
			num--;
			pos = B[b++];
		}
	}

	printf("%d\n", ans);
	return 0;
}

	
