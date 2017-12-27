#include <bits/stdc++.h>
using namespace std;

int main() {
	char A[33];
	scanf("%s", A);
	int c=1, a=0, f=1;
	stack<int> st;
	for (int i=0; A[i]; ++i) {
		if (A[i] == '(') c*=2, f=1, st.push(0);
		else if (A[i] == '[') c*=3, f=1, st.push(1);
		else if (A[i] == ')') {
			if (st.top() != 0) return printf("0\n"), 0;
			st.pop();
			if (f) {
				f=0;
				a+=c;
			}
			c/=2;
		}
		else {
			if (st.top() != 1) return printf("0\n"), 0;
			st.pop();
			if (f) {
				f=0;
				a+=c;
			}
			c/=3;
		}
	}

	if (!st.empty())
		printf("0\n");
	else
		printf("%d\n", a);
	return 0;
}
