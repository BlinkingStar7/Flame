#include <bits/stdc++.h>
using namespace std;

pair<int, string> A[3];
int three, N, cur[3], best[3], use[3];

int f(int a, int b, int c, int q) {
	int num;
	memset(use, 0, sizeof(use));

	num = min(q, a-b);
	use[0] += num;
	q -= num;
	if (q == 0) return a;

	num = min(q, (b-c)*2);
	use[0] += num/2 + (num%2 ? 1 : 0);
	use[1] += num/2;
	q -= num;
	if (q == 0) return a + (num+1)/2;

	use[0] += q/3 + (q%3 >= 1 ? 1 : 0);
	use[1] += q/3 + (q%3 >= 2 ? 1 : 0);
	use[2] += q/3;
	return a + (b-c) + 2*(q/3) + q%3;
}

int main() {
	for (int i=0; i<3; ++i)
		cin >> A[i].second;

	N = A[0].second.size();
	for (int i=0; i<N; ++i) {
		char t[3];
		for (int j=0; j<3; ++j) t[j] = A[j].second[i];

		if (t[0] != t[1] && t[1] == t[2]) A[0].first++;
		else if (t[1] != t[0] && t[0] == t[2]) A[1].first++;
		else if (t[2] != t[0] && t[0] == t[1]) A[2].first++;
		else if (t[0] != t[1] && t[1] != t[2] && t[2] != t[0]) three++;
	}

	sort(A, A+3, greater<pair<int, string> >());

	/*
	for (int i=0; i<3; ++i)
		cout <<  A[i].second << " " << A[i].first << endl;
	cout << three << endl;
	 */

	int cur[3], bestVal = 1e5+5;
	for (int i=0; i<3; ++i) cur[i] = A[i].first;
	while (1) {
		if (cur[0] < cur[1]) break;
		int cand = f(cur[0], cur[1], cur[2], three);
		if (cand < bestVal) {
			bestVal = cand;
			for (int i=0; i<3; ++i) best[i] = cur[i];
		}
		cur[0]--;
		cur[1]++, cur[2]++;
	}
	f(best[0], best[1], best[2], three);

	printf("%d\n", bestVal);
	for (int i=0; i<N; ++i) {
		char t[3];
		for (int j=0; j<3; ++j) t[j] = A[j].second[i];

		if (t[0] != t[1] && t[1] == t[2]) {
			if (best[0]) { putchar(t[1]); best[0]--; }
			else putchar(t[0]);
		}
		else if (t[1] != t[0] && t[0] == t[2]) putchar(t[0]);
		else if (t[2] != t[0] && t[0] == t[1]) putchar(t[0]);
		else if (t[0] != t[1] && t[1] != t[2] && t[2] != t[0]) {
			if (use[0]) { putchar(t[0]); use[0]--; }
			else if (use[1]) { putchar(t[1]); use[1]--; }
			else if (use[2]) { putchar(t[2]); use[2]--; }
		}
		else putchar(t[0]);
	}


	return 0;
}



