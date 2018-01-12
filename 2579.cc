#include <bits/stdc++.h>
using namespace std;

int main() {
	scanf("%d", &N);

	for (int i=0; i<N; ++i) {
		scanf("%d", &A[i]);
	}

	for (int i=0; i<N; ++i) for (int j=0; j<2; ++j) {
		int bef = 0;
		if (i>=1 && j>=1) bef = max(bef, A[i-1][j-1]);
		if (
