#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define zero(v) memset(v,0,sizeof(v))
#define sz(c) ((int) c.size())
#define dprint(v) cout << #v"=" << v << endl
#define fst first
#define snd second
#define pb push_back
#define endl "\n"
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 1000000000;

int main(){
	ios::sync_with_stdio(0);
	int n; 
	set<ii> precio;
	set<ii> calidad;
	cin >> n;
	int a,b;
	forn(i,n){
		cin >> a >> b;
		precio.insert({a,b});
		calidad.insert({b,a});
	}
	for(ii v : precio){
		set<ii>::iterator next = calidad.upper_bound({v.snd, MAXN});
		cout << next->fst << " " << next->snd << endl;
		while(next != calidad.end() && v.snd <= next->fst){
			next++;
		}
		if(next != calidad.end()){
			cout << "Happy Alex" << endl;
			return 0;
		}
	}
	cout << "Poor Alex" << endl;
	return 0;
}
