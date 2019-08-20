
#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(ll i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define pb push_bac
#define fst first
#define snd second
typedef long long ll;
typedef pair<int,int> ii;
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define dprint(v) cout << #v"=" << v << endl
#define endl "\n"

const ll MOD=1000000007;


ll expmod(ll b, ll e, ll m){
	b=b%m;
	if(!e) return 1;
	ll q = expmod(b, e/2, m); q = (q*q) % m;
	return e%2 ? (b*q) % m : q;
}

ll euclid(ll a, ll b, ll& x, ll& y){ // a*(x+k*(b/d))+b*(y-k*(a/d))=d
	if(!b){x=1;y=0;return a;}          // (for any k)
	ll d=euclid(b,a%b,x,y);
	ll t=y;y=x-(a/b)*y;x=t;
	return d;
}

ll inv(ll a, ll m){
    ll x, y, d = euclid(a, m, x, y);
    if(d < 0)x = -x, y = -y, d = -d;
    return (x%MOD + MOD)%MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    ll a,k,r=0;
    cin >> a >> k;
    if((((a%MOD)+MOD)%MOD) == 0){
		cout << 1 << endl;
		return 0;
	}
    if((((a%MOD)+MOD)%MOD) == 1){
		cout << ((k+1)%MOD) << endl;
		return 0;
	}
    r = expmod(a,k+1, MOD) -1;
    r = ((r % MOD) + MOD) % MOD;
    //ll x = inv(a-1,MOD);
    ll x = expmod(a-1, MOD-2, MOD);
    x = ((x%MOD)+MOD) % MOD;
    r = r*x;
    r = ((r%MOD)+MOD)%MOD;
	cout << r << endl;
    return 0;
}
