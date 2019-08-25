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
	map<ii> laptop;
	set<int> price;
	set<int> quality;
	set<int>::iterator it;
	set<int>::iterator it2;
	cin >> n;
	int a,b;
	forn(i,n){
		cin >> a >> b;
		price.insert({a,b});
		quality.insert({b,a});
		laptop.insert({a,b});
	}
	//Tengo ordenado de menor a mayor los sets
	cout << "Poor Alex" << endl;
	return 0;
}
