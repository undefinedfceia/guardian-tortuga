#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define forr(i,a,b) for(ll i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int,int> ii;
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define dprint(v) cout << #v"=" << v << endl
#define endl "\n"

ll gcd(ll a, ll b){
  if(b<a) swap(a,b);
  if(a==0) return b;
  else{
    return gcd(b%a,a);
  }
}

vector<ll> factorize(ll m){
  if(m==1) return{};
  vector<ll> fact;
  for(ll a=2; a*a<=m; a++){
    while(m%a==0){
      fact.push_back(a);
      m/=a;
    }
  }
  if(m!=1) fact.push_back(m);
  return fact;
}

//Usar asi:  divisores(fac, divs, fac.begin()); NO ESTA ORDENADO
void divisores(const map<ll,ll> &f, vector<ll> &divs, map<ll,ll>::iterator it, ll n=1){
    if(it==f.begin()) divs.clear();
    if(it==f.end()) { divs.pb(n);  return; }
    ll p=it->fst, k=it->snd; ++it;
    forn(_, k+1) divisores(f, divs, it, n), n*=p;
}

bool comp(ll a, ll b){
	return a>=b;
}
int main() {
	buscarprimos();
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    ll n,k;
    cin >> n >> k;
    if(k==1){
		cout << n << endl;
		return 0;
	}
	map<ll,ll> f = fact(n);
	vector<ll> divs;
	divisores(f,divs,f.begin());
    sort(divs.begin(),divs.end(),comp);
    ll a = 0;
    for(ll i: divs){
		if(((k+1)) > ((n/i)*2)/k)
			continue;
		forr(j,1,k){
			a+=j*i;
			cout << j*i << " ";
		}
		break;
	}
	if(a==0){
		cout << -1 << endl;
		return 0;
	}
	if(n-a != 0)
		cout << n-a << endl;
	else
		cout << endl;
    return 0;
}
