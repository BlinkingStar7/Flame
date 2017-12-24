#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5+5;
int N, ori[6], cur[5], best[5], B[5], C[5], Case[MAX];
char A[3][MAX];
int f() {
	int t = ori[3];

	int tt = min(t, cur[0]-cur[1]); 
	C[0] += tt;
	t -= tt;
	if (t == 0) return cur[0];

	if (t < 2*(cur[1]-cur[2])) {
		C[0] += t/2;
		C[1] += (t+1)/2;
		return cur[0] + (t+1)/2;
	}

	C[0] += cur[1]-cur[2];
	C[1] += cur[1]-cur[2];
	t -= 2*(cur[1]-cur[2]);

	C[0] += t/3 + (t%3 >= 1);
	C[1] += t/3 + (t%3 >= 2);
	C[2] += t/3;

	return cur[0] + cur[1] - cur[2] + 2*(t/3) + t%3;
}

int main() {
	for (int i=0; i<3; ++i)
		scanf("%s", &A[i][0]);

	N = strlen(A[0]);
	for (int i=0; i<N; ++i) {
		Case[i] = -1;
		if (A[0][i] != A[1][i] && A[1][i] == A[2][i]) ori[0]++, Case[i]=0;
		if (A[1][i] != A[0][i] && A[0][i] == A[2][i]) ori[1]++, Case[i]=1;
		if (A[2][i] != A[0][i] && A[0][i] == A[1][i]) ori[2]++, Case[i]=2;
		if (A[0][i] != A[1][i] && A[1][i] != A[2][i] && A[2][i] != A[0][i]) ori[3]++, Case[i]=3;
	}

	for (int i=1; i>=0; --i) for (int j=0; j<=i; ++j) {
		if (ori[j] < ori[j+1]) {
			swap(ori[j], ori[j+1]);
			for (int k=0; k<N; ++k)
				swap(A[j][k], A[j+1][k]);
		}
	}

	for (int i=0; i<3; ++i) cur[i] = ori[i];

	int bestVal = MAX;
	while (1) {
		if (cur[0] < cur[1]) break;
		int cand = f();
		if (cand < bestVal) {
			bestVal = cand;
			for (int i=0; i<3; ++i)
				best[i] = cur[i];
		}
		cur[0]--;
		cur[1]++, cur[2]++;
	}

	B[0] += ori[0] - best[0];

	printf("%d\n", bestVal);
	for (int i=0; i<N; ++i) {
		if (Case[i] == -1) putchar(A[0][i]);
		else if (Case[i] == 3) {
			for (int j=0; j<3; ++j) if (C[j]) {
				C[j]--;
				putchar(A[j][i]);
				break;
			}
		}
		else {
			if (B[Case[i]]) { B[Case[i]]--; putchar(A[Case[i]][i]); }
			else putchar(A[(Case[i]+1)%3][i]);
		}
	}

	return 0;
}

