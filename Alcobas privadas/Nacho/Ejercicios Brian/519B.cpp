#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define zero(v) memset(v,0,sizeof(v))
#define sz(c) ((int)c.size())
#define dprint(v) cout << #v" = " << v << endl
#define endl "\n"
#define fst first
#define snd second
#define pb push_back
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

int main(){
	ios::sync_with_stdio(0);
	int n,a;
	ll sum = 0;
	ll suma = 0;
	ll sumb = 0;
	cin >> n;
	forn(i,n){ cin >> a; sum += a; }
	forn(i, (n-1) ){ cin >> a; suma += a; } 
	forn(i, (n-2) ){ cin >> a; sumb += a; }
	cout << sum - suma << endl;
	cout << suma - sumb << endl;  
	return 0;
}
