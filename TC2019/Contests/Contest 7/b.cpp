#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define forr(i,a,b) for(ll i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define zero(v) memset(v,0,sizeof(v))
#define pb push_back
#define fst first
#define snd second
#define sz(c) ((int)c.size())
#define endl "\n";
#define printInLine(a,n) forn(i,n){cout << i << ">>" << a[i] << " ";}cout << endl;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 6250000;

ll suma[MAXN], sumb[MAXN];
ll m;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	zero(suma);
	zero(sumb);
	int n;
	int a[2500],b[2500],c[2500],d[2500];
	cin >> n;
	forn(i,n)
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	m=0;
	forn(i,n){
		forn(j,n){
			suma[m] = a[i]+b[j];
			sumb[m] = c[i]+d[j];
			m++;
		}
	}
	sort(sumb,sumb+m);
	ll count=0;
	forn(i,m){
		pair< ll*, ll*> q = equal_range(sumb,sumb+m,-1*suma[i]);
		count += (q.snd-sumb)-(q.fst-sumb);
	}
	cout << count << endl;
	return 0;
}
