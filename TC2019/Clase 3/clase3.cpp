#include<bits/stdc++.h>
#define forr(i, a, b) for(int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define zero(v) memset(v, 0, sizeof(v))
typedef long long ll;
#define endl "\n"


vector<int> graph[10000];
	// n <= 10000

#define x first
#define y second
#define INF 1000000007
using namespace std;
int T,n,m;
char c;
bool a[182][182];
int dist[182][182];
pair<int,int> mov[4];
void inimove(void){
    mov[0].x = -1; mov[0].y = 0;
    mov[1].x = 1; mov[1].y = 0;
    mov[2].x = 0; mov[2].y = -1;
    mov[3].x = 0; mov[3].y = 1;
}
bool ok(pair<int,int> movement, pair<int,int> a){
    return movement.x+a.x>=0 and movement.x+a.x<n and movement.y+a.y>=0 and movement.y+a.y<m;  
}
void bfs(void){
    bool visit[182][182];
    int nivel[182][182];
    pair<int,int> padre[182][182];
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
        for(int i=0;i<4;i++){
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
int main(){
    inimove();
    cin>>T;
    for(int k=0;k<T;k++){
        cin>>n>>m;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++){
            cin>>c;
            a[i][j] = c=='1'? true : false;
        }
        memset(dist,INF,sizeof(dist));
        bfs();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j) cout<<" ";
                cout<<dist[i][j];
            }
            cout<<endl;
        }
    }
}
	
	
