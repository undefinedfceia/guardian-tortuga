#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=(a); i<(b); i++)
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

const int MAXN=100100;

ll dist_normal(ii a, ii b){
	ll in = (b.fst - a.fst)*(b.fst - a.fst) + (b.snd - a.snd)*(b.snd - a.snd);
	ll dou = (long)sqrt(in)*(long)sqrt(in);
	if(dou == in)
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    vector< pair<ll,ll> > puntos;
    vector<ll> dan;
    vector<ll> man;
    ll a,b,d,m;
    int n;
    cin >> n;
    forn(i,n){
		cin >> a >> b;
		puntos.pb({a,b});
	}
	ll count=0;
	forn(i, sz(puntos)){
		forr(j,i,sz(puntos)){
			puntos[i] - puntos[j];
		}
	}
	cout << count << endl;
	return 0;
}
