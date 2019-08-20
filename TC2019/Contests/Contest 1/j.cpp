#include <bits/stdc++.h>

#define forr(i,a,b) for(int i=a; i < b; i++)
#define forn(i,n) forr(i,0,n)

using namespace std;

int main(){
	long long n;
	long long a[101];
	long long b[101];
	forn(i,101)
		a[i] = i*i;
	partial_sum(a,a+101,b);
	while(cin >> n, n!=0){
		cout << b[n] << endl;
	}
	return 0;
}
