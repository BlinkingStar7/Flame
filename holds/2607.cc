#include <bits/stdc++.h>
using namespace std;

int N, n[300], ans;
char A[105], B[105];
int main() {
	scanf("%d", &N);

	scanf("%s", A);
	for (int i=0; A[i]; ++i)
		n[A[i]]++;

	for (int i=0; i<N-1; ++i) {
		scanf("%s", B);
		int nn[300] = {};
		for (int j=0; j<B[j]; ++j)
			nn[B[j]]++;

		int a=0, b=0;
		for (int j='A'; j<='Z'; ++j)
			if (n[j] > nn[j]) a += n[j]-nn[j];
			else if (nn[j] > n[j]) b += nn[j] - n[j];

		if ((a+b)<=1 || (a==1 && b==1))
			++ans;
	}

	printf("%d\n", ans);
	return 0;
}
