#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

int dist[500][500];
int graph[500][500];
int last;

bool path[500][500];
bool vertex[500];

const int MAXN=100100;

int minDistance(bool sptSet[], int V, int src){ 
   int min = INT_MAX, min_index = 1;  
   for (int v = 0; v < V; v++) 
     if (sptSet[v] == false && dist[src][v] <= min) 
         min = dist[src][v], min_index = v;   
   return min_index; 
} 

void dijkstra(int src, int V){ 
	if(!vertex[src]) return;
	bool sptSet[V];
	for (int i = 0; i < V; i++) 
		dist[src][i] = INT_MAX, sptSet[i] = false; 
	dist[src][src] = 0; 
	for (int count = 0; count < V-1; count++) { 
		int u = minDistance(sptSet, V,src); 
		sptSet[u] = true; 
		if(!vertex[u]) continue;
		for (int v = 0; v < V; v++){
			if(!vertex[v]) continue;
			if (!sptSet[v] && graph[u][v] && dist[src][u] != INT_MAX && dist[src][u]+graph[u][v] < dist[src][v]){
				dist[src][v] = dist[src][u] + graph[u][v];
				path[src][v] = true;
			}  
		}
	}
} 

ll sum;
ll sum(int n){
	ll sum = 0;
	forn(i,n){
		if(!vertex[i]) continue;
		if(last != -1){
			if(path[i][last])
				dijkstra(i,n);
		}else
			dijkstra(i,n);
		forn(j,n){
			if(!vertex[j]) continue;
			sum += (dist[i][j] != INT_MAX) ? dist[i][j] : 0;
		}
	}
	return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,w;
    last = -1;
    sum = 0;
    cin >> n;
    zero(vertex);
    zero(path);
    forn(i,n)
		vertex[i] = true;
    forn(i, n){
		forn(j,n){
			cin >> w;
			graph[i][j] = w;
		}
	}
	int x;
	forn(i,n){
		cout << sum(n) << " ";
		cin >> x;
		last = x-1;
		vertex[x-1] = false;
		/*forn(j,n){
			graph[j][x-1] = 0;
			graph[x-1][j] = 0;
		}*/
 	}
	cout << endl;
	return 0;
}
