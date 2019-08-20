	#include <bits/stdc++.h>
	using namespace std;
	#define dprint(v) cerr << #v"=" << v << endl //;)
	#define forr(i,a,b) for(int i=(a); i<(b); i++)
	#define forn(i,n) forr(i,0,n)
	#define dforn(i,n) for(int i=n-1; i>=0; i--)
	#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
	#define sz(c) ((int)c.size())
	#define zero(v) memset(v, 0, sizeof(v))
	#define pb push_back
	#define fst first
	#define snd second
	#define endl "\n"
	typedef long long ll;
	typedef unsigned long long ull;
	typedef pair<int,int> ii;

ll gcd(ll a, ll b){return a?gcd(b%a,a):b;}

#define MAXP 1000050	//no necesariamente primo
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

map<ll,ll> fact(ll n){ //O (lg n)
	map<ll,ll> ret;
	while (criba[n]){
		ret[criba[n]]++;
		n/=criba[n];
	}
	if(n>1) ret[n]++;
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(nullptr);
	buscarprimos();
	int n,a,b;
	cin >> n;
	forn(i,n){
		cin >> a >> b;
		map<ll,ll> fa = fact(gcd(a,b));
		map<ll,ll>::iterator it;
		long long d=1;
		for(it = fa.begin(); it != fa.end(); it++)
			d = d*(it->second+1);
		cout << d << endl;
	}
	return 0;
}
