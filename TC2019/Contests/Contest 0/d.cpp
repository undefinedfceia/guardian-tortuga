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

const int MAXN=100100;

vector<pair<int,int> > g[MAXN];  // u->[(v,cost)]
vector<pair<int,int> > t[MAXN];  // u->[(v,cost)]

ll dist[MAXN];
void dijkstra(int x){
	memset(dist,-1,sizeof(dist));
	priority_queue<pair<ll,int> > q;
	dist[x]=0;q.push({0,x});
	while(!q.empty()){
		x=q.top().snd;ll c=-q.top().fst;q.pop();
		if(dist[x]!=c)continue;
		forn(i, sz(g[x])){
			int y=g[x][i].fst,c=g[x][i].snd;
			if(dist[y]<0||dist[x]+c<dist[y])
				dist[y]=dist[x]+c,q.push({-dist[y],y});
		}
	}
}

int main() {
    //freopen("input.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,m,x,y,u,v,w;
    cin >> n >> m >> x >> y;
	forn(i,m){
		cin >> u >> v >> w;
		g[u].pb({v,w});
	}
	forn(i,n){
		cin >> v >> w;
		t[i].pb({v,w});
	}
	dijkstra(x);
	cout << dist[y] << endl;
    return 0;
}
	
