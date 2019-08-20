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

ll x,y;

ll euclid(ll a, ll b, ll& x, ll& y){ // a*(x+k*(b/d))+b*(y-k*(a/d))=d
	if(!b){x=1;y=0;return a;}          // (for any k)
	ll d=euclid(b,a%b,x,y);
	ll t=y;y=x-(a/b)*y;x=t; 
	return d;
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("input.in", "r", stdin);
	freopen("output.o", "w", stdout);
    int t;
    ll n,p;
    cin >> t;
    forn(z,t){
		cin >> n >> p;
		if(n>=p){
			cout << 0 << endl;
			continue;
		}
		ll r=1;
		forr(i,n+1,p)
			r = (r * i)%p;
		r=(r+p)%p;
		euclid(r,p,x,y);
		r = x*-1;
		cout << (r+p)%p << endl;
	}
    return 0;
}
