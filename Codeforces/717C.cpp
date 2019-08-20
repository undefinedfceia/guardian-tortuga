#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define pb push_back
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define dprint(v) cout << #v"=" << v << endl
#define endl "\n"

const int MOD = 10007;

bool comp(int a, int b){
	return a > b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,a;
    cin >> n;
    vector<int> t;
    forn(i, n){
		cin >> a;
		t.pb(a);
	}
    sort(t.begin(), t.end(), comp);
    ll sum = 0; 
    forn(i, (n/2)){
		sum += (t[i] % MOD) * (t[n-1-i] % MOD);
		sum = sum % MOD;
	}
	sum *= 2;
	sum = sum % MOD;
	if( n % 2 != 0)
		sum += (t[n/2] % MOD) * (t[n/2] % MOD);
	sum = sum % MOD;
	cout << sum % MOD << endl; 
	return 0;
}
