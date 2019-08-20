#include <bits/stdc++.h>

#define forr(i, a, b) for(long long i = (a); i < b; i++)
#define forn(i, n) forr(i, 0, n)
#define zero(v) memset(v, 0, sizeof(v))

using namespace std;

char comp(int a, int b){
	return a > b;
}

int main(){
	long long s;
	cin >> s;
	long long a[s], b[s], c = 0;
	long long max = 0;
	forn(i,s){
		cin >> a[i];
	}
	sort(a, a+s, comp);
	forn(i,s){
		cin >> b[i];
	}
	sort(b,b+s,comp);
	forn(i, s){
		if(b[max] - a[i] > 0){
			max++;
			c++;
		}
	}
	cout << c << endl;
	return 0;
}

