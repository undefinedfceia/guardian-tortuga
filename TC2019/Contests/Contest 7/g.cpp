#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(ll i=(a); i<(b); i++)
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

#define INF 1000000007

int n,m;
bool a[8][8];
int dist_alfil[8][8];
int dist_torre[8][8];
int dist_caballo[8][8];
int CANT_MOVE_ALFIL = 4;
int CANT_MOVE_CABALLO = 8;
int CANT_MOVE_TORRE = 4;
pair<int,int> mov_alfil[CANT_MOVE_ALFIL];
pair<int,int> mov_torre[CANT_MOVE_TORRE];
pair<int,int> mov_caballo[CANT_MOVE_CABALLO];

void inimove(void){
    mov_caballo[0].x = -1; mov_caballo[0].y = 2;
    mov_caballo[1].x = 1; mov_caballo[1].y = 2;
    mov_caballo[2].x = -2; mov_caballo[2].y = 1;
    mov_caballo[3].x = 2; mov_caballo[3].y = 1;
    mov_caballo[4].x = -1; mov_caballo[4].y = -2;
    mov_caballo[5].x = 1; mov_caballo[5].y = -2;
    mov_caballo[6].x = 2; mov_caballo[6].y = -1;
    mov_caballo[7].x = -2; mov_caballo[7].y = -1;
    mov_alfil[0].x = 1; mov_alfil[0].y = 1; 
    mov_alfil[1].x = -1; mov_alfil[1].y = 1; 
    mov_alfil[2].x = 1; mov_alfil[2].y = -1; 
    mov_alfil[3].x = -1; mov_alfil[3].y = -1;
    mov_torre[0].x = 0; mov_torre[0].y = -1;
    mov_torre[0].x = 0; mov_torre[0].y = 1;
    mov_torre[0].x = 1; mov_torre[0].y = 0;
    mov_torre[0].x = -1; mov_torre[0].y = 0;
}

bool ok(pair<int,int> movement, pair<int,int> a){
    return movement.x+a.x>=0 and movement.x+a.x<n and movement.y+a.y>=0 and movement.y+a.y<m;  
}

void bfs_caballo(void){
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
        for(int i=0;i<CANT_MOVE;i++){
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

void bfs_alfil(void){
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
        for(int i=0;i<CANT_MOVE;i++){
           for(int z = 1; z<8; z++){
				if(ok(mov[i],current)){
					pair<int,int> vecino =make_pair(mov[i].x*z+current.x,mov[i].y*z+current.y);
					if(!visit[vecino.x][vecino.y]){
						q.push(vecino);
						padre[vecino.x][vecino.y] = current;
						visit[vecino.x][vecino.y] = true;
					}
				}
			}
        }  
    }
}

void bfs_torre(void){
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
        for(int i=0;i<CANT_MOVE;i++){
			for(int z = 1; z<8; z++){
				if(ok(mov[i],current)){
					pair<int,int> vecino =make_pair(mov[i].x*z+current.x,mov[i].y*z+current.y);
					if(!visit[vecino.x][vecino.y]){
						q.push(vecino);
						padre[vecino.x][vecino.y] = current;
						visit[vecino.x][vecino.y] = true;
					}
				}
			}			
        }  
    }
}
int main(){
    inimove();
    forn(i,8) forn(j,8) dist_alfil[i][j] = INF;
    forn(i,8) forn(j,8) dist_torre[i][j] = INF;
    forn(i,8) forn(j,8) dist_caballo[i][j] = INF;
    n = m = 8;
    //bfs();
}
