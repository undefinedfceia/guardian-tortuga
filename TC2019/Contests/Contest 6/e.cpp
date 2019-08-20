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
typedef long long ll;
typedef pair<int,int> ii;
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define dprint(v) cout << #v"=" << v << endl
#define endl "\n"

const int MAXN=10010;
vector<ll> g[MAXN];

vector<int> BFS(int nodoInicial, int n){
	int t;
	queue<int> cola;
	vector<int> distancias(n,n);
	cola.push(nodoInicial);
	distancias[nodoInicial] = 0;
	while(!cola.empty()){
		t = cola.front();
		cola.pop();
		for(unsigned int i = 0; i < g[t].size(); i++){
			if(distancias[g[t][i]] == n){
				distancias[g[t][i]] = distancias[t]+1;
				cola.push(g[t][i]);
			}
		}
	}
	return distancias;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,m,a,b;
    cin >> n >> m;
    forn(i,m){
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
    vector<int> dist = BFS(1,n+1);
    vector<int>::iterator it;
    ll count = 0;
    for(it = dist.begin()+1; it != dist.end(); it++){
		count += (*it < n) ? 1 : 0;
	}
    if(count == n && (n-1)==m)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
    return 0;
}
