#define INF 1000000007
int n,m;
bool a[8][8];
int dist[8][8];
int CANT_MOVE = 4;
pair<int,int> mov[CANT_MOVE];

void inimove(void){
    mov[0].x = 0; mov[0].y = 1;
    mov[1].x = 0; mov[1].y = 0;
    mov[2].x = 1; mov[2].y = 1;
    mov[3].x = 1; mov[3].y = 0;
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

int main(){
    inimove();
    forn(i,8) forn(j,8) dist[i][j] = INF;
    n = m = 8;
    bfs();
}