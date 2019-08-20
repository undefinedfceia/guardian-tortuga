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
#define MAXP 1000500	//no necesariamente primo

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


int main() {
	buscarprimos();
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,m,a;
    cin >> n >> m;
    int col[m];
    int fil[n];
    zero(col);
    zero(fil);
    forn(i,n){
		forn(j,m){
			cin >> a;		
			a = *lower_bound(primos.begin(), primos.end(), a) - a;
			col[j] += a;
			fil[i] += a;
		}
	}
	int min1 = *min_element(col, col+m);
	int min2 = *min_element(fil, fil+n);
	cout << min(min1, min2) << endl;
	return 0;
}

