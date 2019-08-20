#include <bits/stdc++.h>

#define forr(i, a, b) for(int i = a; i < b; i++)
#define forn(i, n) forr(i, 0, n)
#define zero(v) memset(v, 0, sizeof(v))

using namespace std;

int main(){
	long long max, a, j;
	max = -1;
	j = 0;
	forn(i, 100){
		cin >> a;
		if(a > max){
			max = a;
			j = i;
		}
	}
	j++;
	cout << max << endl << j << endl;
	return 0;
}
