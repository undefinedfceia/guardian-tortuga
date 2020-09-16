#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define zero(v) memset(v,0,sizeof(v))
#define sz(c) ((int)c.size())
#define fst first
#define second snd
#define pb push_back
#define endl "\n"
#define dprint(v) cout << #v"=" << v << endl
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

ll a[101];

bool comp(ll a, ll b){
	return a > b;
}

int main(){
	ll n,m;
	zero(a);
	cin >> n >> m;
	forn(i,n)
		cin >> a[i];
	sort(a,a+101,comp);
	int i = 0;
	while(m>0 && i<n){
		m = m - a[i];
		i++;
	}
	cout << i << endl;
	return 0;
}
