#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	int ans=0, c=0;
	for (int i=0; i<N; ++i) {
		int t;
		scanf("%d", &t);
		if (t) ans += ++c;
		else c = 0;
	}
	printf("%d\n", ans);
	return 0;
}


