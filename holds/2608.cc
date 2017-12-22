#include <bits/stdc++.h>
using namespace std;

int val[300];
char A[20];

int main() {
	char t[] = "IVXLCDM";
	int tt[] = {1,5,10,50,100,500,1000};

	for (int i=0; i<7; ++i)
		val[t[i]] = tt[i];

	int ans = 0;
	for (int i=0; i<2; ++i) {
		scanf("%s", A);
		
		for (int j=0; A[j]; ++j) {
			if (val[A[j]] < val[A[j+1]]) {
				ans += val[A[j+1]] - val[A[j]];
				++j;
			}
			else {
				ans += val[A[j]];
			}
		}
	}

	printf("%d\n", ans);

	for (int i=6; i>=0; i-=2) {
		int num = ans/tt[i]%10;
		if (num == 4) printf("%c%c", t[i], t[i+1]);
		else if (num == 9) printf("%c%c", t[i], t[i+2]);
		else {
			if (num >= 5) printf("%c", t[i+1]);
			for (int j=0; j<num%5; ++j)
				printf("%c", t[i]);
		}
	}
	
	return 0;
}

