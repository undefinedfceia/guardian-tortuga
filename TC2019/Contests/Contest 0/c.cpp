#include <bits/stdc++.h>

#define forr(i,a,b) for(int i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define zero(v) memset(v, 0, sizeof(v))

using namespace std;

bool comp(long long a, long long b){
	return a > b;
}
int main(){
	int n;
	while(cin >> n, n != -1){
		long long x[n];
		long long p[n];
		zero(p);
		forn(i,n)
			cin >> x[i];
		sort(x, x+n, comp);
		p[0]=1;
		p[n-1]=2;
		forr(i, 1,n){
			if(x[i+1] < x[i] && p[i+1] == 0)
				p[i+1]=1;
			if(x[n-(i+2)] > x[n-i-1] && p[n-(i+2)] == 0)
				p[n-(i+2)] = 2;
		}
		forn(i,n)
			cout << x[i] << " " << p[i] << endl;
	}
	return 0;
}
