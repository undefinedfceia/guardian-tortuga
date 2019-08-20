#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define pb push_bac
#define fst first
#define snd second
typedef long long ll;
typedef pair<int,int> ii;
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define dprint(v) cout << #v"=" << v << endl
//#define endl "\n"
#define x first
#define y second
#define INF 1000000007
int n,m;

bool a[8][8];
int dist[8][8];
pair<int,int> mov[8];

void inimove(void){
    mov[0].x = -1; mov[0].y = 2;
    mov[1].x = 1; mov[1].y = 2;
    mov[2].x = -2; mov[2].y = 1;
    mov[3].x = 2; mov[3].y = 1;
    mov[4].x = -1; mov[4].y = -2;
    mov[5].x = 1; mov[5].y = -2;
    mov[6].x = 2; mov[6].y = -1;
    mov[7].x = -2; mov[7].y = -1;
}

bool ok(pair<int,int> movement, pair<int,int> a){
    return movement.x+a.x>=0 and movement.x+a.x<n and movement.y+a.y>=0 and movement.y+a.y<m;  
}

void bfs(void){
    bool visit[8][8];
    int nivel[8][8];
    pair<int,int> padre[8][8];
    memset(visit,false,sizeof(visit));
    queue<pair<int,int> > q;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(a[i][j]){
        pair<int,int> node = make_pair(i,j);
        q.push(make_pair(i,j));
        nivel[node.x][node.y] = -1;
        padre[node.x][node.y] = node;
        visit[node.x][node.y] = true;
    }
    while(q.size()){
        pair<int, int> current = q.front();
        q.pop();
        pair<int,int> mi_padre = padre[current.x][current.y];
        nivel[current.x][current.y] = nivel[mi_padre.x][mi_padre.y]+1;
        dist[current.x][current.y] = min(dist[current.x][current.y],nivel[current.x][current.y]);
        for(int i=0;i<8;i++){
            if(ok(mov[i],current)){
                pair<int,int> vecino =make_pair(mov[i].x+current.x,mov[i].y+current.y);
                if(!visit[vecino.x][vecino.y]){
                    q.push(vecino);
                    padre[vecino.x][vecino.y] = current;
                    visit[vecino.x][vecino.y] = true;
                }
            }
        }  
    }
}


int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(nullptr);
    inimove();
    forn(i,8) forn(j,8) dist[i][j] = INF;
    n = m = 8;
    bfs();
    string c,d;
    while(cin >> c >> d){
		int is,js, i,j;
		is = c[0]-'a';
		i = d[0]-'a';
		js = c[1]-'0' -1 ;
		j = d[1]-'0' -1;
		zero(a);
		forn(i,8) forn(j,8) dist[i][j] = INF;
		a[is][js] = 1;
		bfs();
		cout << "To get from " << c << " to " << d << " takes "<< dist[i][j] << " knight moves."<< endl;
	}
    return 0;
}
