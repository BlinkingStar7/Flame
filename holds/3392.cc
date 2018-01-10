#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4+5;
struct Event {
	int x, y, yy, op;
	Event() {}
	Event(int _x, int _y, int _yy, int _op) : x(_x), y(_y), yy(_yy), op(_op) {}

	bool operator < (const Event& e) const{
		return x < e.x;
	}
} A[2*MAX];
int N, cnt[12*MAX], seg[12*MAX], ans;

void update(int nn, int x, int y, int xx, int yy, int v) {
	if (yy<x || y<xx) return;

	if (xx<=x && y<=yy)
		cnt[nn] += v;
	else {
		int mid = (x+y)>>1;
		update(nn*2, x, mid, xx, yy, v);
		update(nn*2+1, mid+1, y, xx, yy, v);
	}

	if (cnt[nn]) seg[nn] = y-x+1;
	else seg[nn] = x == y ? 0 : (seg[nn*2] + seg[nn*2+1]);
}

int main() {
	scanf("%d", &N);

	for (int i=0; i<N; ++i) {
		int x, y, xx, yy;
		scanf("%d%d%d%d", &x, &y, &xx, &yy);
		A[i] = Event(x, y, yy-1, 1);
		A[i+N] = Event(xx, y, yy-1, -1);
	}

	sort(A, A+2*N);

	for (int i=0; i<2*N; ++i) {
		int dx = i == 0 ? 0 : (A[i].x - A[i-1].x);
		int len = seg[1];
		ans += dx*len;
		update(1, 0, 3*MAX-1, A[i].y, A[i].yy, A[i].op);
	}

	printf("%d\n", ans);
	return 0;
}
