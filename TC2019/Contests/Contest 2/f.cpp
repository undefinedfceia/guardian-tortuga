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
typedef long long ll;
typedef pair<int,int> ii;
#define endl "\n"
#define MAXP 10000000	//no necesariamente primo

int criba[MAXP+1];

void crearcriba(){
	int w[] = {4,2,4,2,4,6,2,6};
	for(int p=25;p<=MAXP;p+=10) criba[p]=5;
	for(int p=9;p<=MAXP;p+=6) criba[p]=3; 
	for(int p=4;p<=MAXP;p+=2) criba[p]=2;
	for(int p=7,cur=0;p*p<=MAXP;p+=w[cur++&7]) if (!criba[p]) 
		for(int j=p*p;j<=MAXP;j+=(p<<1)) if(!criba[j]) criba[j]=p;
} 

vector<ll> primos;
set<ll> primos2;

void buscarprimos(){
	crearcriba();
	forr (i,2,MAXP+1) if (!criba[i]) primos.push_back(i);
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(nullptr);
	buscarprimos();
	vector<ll>::iterator it;
	for(it = primos.begin(); it != primos.end(); ++it)
		primos2.insert((*it)*(*it));
	int n; 
	cin >> n;
	ll a;
	forn(i,n){
		cin >> a;
		if(primos2.find(a) != primos2.end())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
