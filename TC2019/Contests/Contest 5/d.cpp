#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(long long i=(a); i<(b); i++)
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

ll mcm(ll a, ll b){
  return (a/gcd(a,b))*b;
}

#define MAXP 1001000	//no necesariamente primo
int criba[MAXP+1];
void crearcriba(){
	int w[] = {4,2,4,2,4,6,2,6};
	for(int p=25;p<=MAXP;p+=10) criba[p]=5;
	for(int p=9;p<=MAXP;p+=6) criba[p]=3; 
	for(int p=4;p<=MAXP;p+=2) criba[p]=2;
	for(int p=7,cur=0;p*p<=MAXP;p+=w[cur++&7]) if (!criba[p]) 
		for(int j=p*p;j<=MAXP;j+=(p<<1)) if(!criba[j]) criba[j]=p;
}

vector<int> primos;

void buscarprimos(){
	crearcriba();
	forr (i,2,MAXP+1) if (!criba[i]) primos.push_back(i);
}

map<ll,ll> fact2(ll n){ //O (lg n)
	map<ll,ll> ret;
	while (criba[n]){
		ret[criba[n]]++;
		n/=criba[n];
	}
	if(n>1) ret[n]++;
	return ret;
}

//Usar asi:  divisores(fac, divs, fac.begin()); NO ESTA ORDENADO
void divisores(const map<ll,ll> &f, vector<ll> &divs, map<ll,ll>::iterator it, ll n=1){
    if(it==f.begin()) divs.clear();
    if(it==f.end()) { divs.pb(n);  return; }
    ll p=it->fst, k=it->snd; ++it;
    forn(_, k+1) divisores(f, divs, it, n), n*=p;
}

ll phi(ll n){
	double a = n;
	map<ll,ll> fac2 = fact2(n);
	map<ll,ll>::iterator it2;
	for(it2 = fac2.begin(); it2 != fac2.end(); it2++){
		a *= 1 -(1/(double)(it2->fst)); 
	}
	return a;
}

ll tabla_phi[MAXP];

void llenar_phi(){
	forr(i,1,MAXP)
		tabla_phi[i] = phi(i);
}

int main() {
	buscarprimos();
	llenar_phi();
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    ll T;
	cin >> T;
    forn(t,T){
		ll n;
		cin >> n;
		ll result = 0;
		map<ll,ll> fac = fact2(n);
		vector<ll> divs;
		vector<ll>::iterator it;
		divisores(fac,divs,fac.begin());
		for(it = divs.begin(); it != divs.end(); it++){
			result = result + tabla_phi[*it] * (*it);
		}
		result++;
		result = result*n;
		result = result/2;
		cout << result << endl;
	}
    return 0;
}
