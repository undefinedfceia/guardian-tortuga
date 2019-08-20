#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
typedef pair<int,int> ii;
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define dprint(v) cout << #v"=" << v << endl
#define endl "\n"

const int MAXN = 500000;

vector<pair<int,int> > g[MAXN];  // u->[(v,cost)]

ll dist[MAXN];
bool visit[MAXN];

void dijkstra(int x){
	memset(dist,-1,sizeof(dist));
	priority_queue<pair<ll,int> > q;
	dist[x]=0;q.push(mp(0,x));
	while(!q.empty()){
		x=q.top().snd;ll c=-q.top().fst;q.pop();
		if(dist[x]!=c)continue;
		forn(i,(int)g[x].size()){
			int y=g[x][i].fst,c=g[x][i].snd;
			if(dist[y]<0||dist[x]+c<dist[y])
				dist[y]=dist[x]+c,q.push(mp(-dist[y],y));
		}
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    zero(visit);
    forn(i, MAXN)
		dist[i] = 500000;
    int n,a,b,t;
    cin >> n >> a >> b >> t;
    string s;
	cin >> s;
	int cost;
    forn(i,n){
		cost = 1+a;
		cost += (s[i] == 'w') ? b : 0;
		g[i+2].pb({i+1,cost});
		g[i].pb({i+1,cost});
	}
	dijkstra(1);
	forn(i,n){
		cout << dist[i] << endl;
	}
	return 0;
}
