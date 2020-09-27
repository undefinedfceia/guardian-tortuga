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
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define dprint(v) cout << #v"=" << v << endl
#define endl "\n"
#define tab "\t"
 
const int MAXN=100100;
 
int bfs(int source, int search){
    ll node;
    queue<int> q;
    ll dist[MAXN];
    bool visited[MAXN];
 
    forn(i, MAXN){ 
        dist[i] = MAXN;
        visited[i] = false;
    }
 
    dist[source] = 0;
    visited[source] = false;
 
    q.push(source);
 
    while(!q.empty()) {
        node = q.front();
        if(node < 0)
            continue;
        if(visited[node])
            continue;
        visited[node] = true;
        q.pop();
        if(node == search)
            break;
        if((node - 1) >= 0 ){
            if(!visited[node - 1]){
                q.push(node - 1);
                dist[node - 1] = dist[node] + 1;
            }
        }
        if(node > search)
            continue;
        if(!visited[node * 2]){
            q.push(node * 2);
            dist[node * 2] = dist[node] + 1;
        }
    }
    return dist[search];
}
 
int main() {
    ios::sync_with_stdio(0);
    // cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    if (m > n)
        cout << bfs(n, m) << endl;
    else if (n == m)
        cout << 0 << endl;
    else 
        cout << n - m << endl;
	return 0;
}
