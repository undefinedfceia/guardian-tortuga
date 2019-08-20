#include <bits/stdc++.h>

#define forr(i,a,b) for(int i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define zero(v) memset(v, 0, sizeof(v))
#define endl "\n"
#define dprint(v) cout << #v"=" << v << endl

using namespace std;

void printBarrita(int k, int progress){
	if(progress == 100){
		cout << "********100%********" << endl;
		return;
	}
	int cant = 2;
	string p = to_string(progress)+"%";
	if(10 <= progress && progress < 100)
		cant = 3;
	char s[] = "--------------------";
	forn(i,k)
		s[i] = '*';
	forr(i, 9, 9+cant)
		s[i] = p[i-9];
	cout << string(s) << endl;
}

int aprox(long long a, long long b, long long c){
	long long r = (a*c)/b;
	long long d = (a*c)% b;
	if(2*d >= b)
		return r+1;
	return r;
}

int main(){
	//freopen("output.o", "w", stdout);
    ios::sync_with_stdio(0);
	long long m, n;
	while(cin >> m >> n, m != -1 && n != -1){
		int k = aprox(m,n,20);
		int d = aprox(m,n,100);
		printBarrita(k, d);
	}
	return 0;
}
