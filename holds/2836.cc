#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<pair<int, int> > v;
int main() {
	scanf("%d%d", &N, &M);

	for (int i=0; i<N; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		
		if (a > b) v.push_back(make_pair(b, a));
	}
	
	sort(v.begin(), v.end());

	int l = -1, r = -1;
	long long ans = 0;
	for (int i=0; i<v.size(); ++i) {
		if (v[i].first > r) {
			ans += r-l;
			l=v[i].first;
		}
		r = max(r, v[i].second);
	}
	ans += r-l;
	printf("%lld\n", ans*2+M);
	return 0;
}
