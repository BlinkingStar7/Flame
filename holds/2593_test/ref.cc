#include <bits/stdc++.h>
using namespace std;

int A[6];
int main() {
	for (int i=0; i<5; ++i)
		scanf("%d", &A[i]);


	for (int i=A[1]; i<=A[0]; i+=A[2])
		if (i >= A[3] && i%A[4] == A[3]%A[4]) {
			printf("Yes\n");
			return 0;
		}
	printf("No\n");

	return 0;
}

