#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=a;i<b;i++) 
#define forn(i,n) forr(i,0,n)
#define zero(v) memset(v,0,sizeof(v))
#define sz(c) ((int)c.size())
#define fst first
#define snd second
#define pb push_back
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define dprint(v) cout << #v " = " << v << endl
#define endl "\n"
#define MOD 1000000007
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN=10010;
vector<ll> g[MAXN];
vector<bool> visit;

void DFS(int node){
	visit[node] = true;
	for(unsigned int i=0; i < g[node].size();i ++){
		int current = g[node][i];
		if(visit[current]){
			DFS(current);
		}
	}
}

int main(){ 	
	//ios::sync_with_stdio(0);
	//cin.tie(nullptr);
	int n,m,a,b;
    cin >> n >> m;
    forn(i,m){
		cin >> a >> b;
		g[b].pb(a);
	}
	forn(i, n+1){
		if(sz(g[i]) == 0)
			continue;
		vector<ll>::iterator it;
		for(unsigned int j=0; j < g[i].size();j ++){
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
