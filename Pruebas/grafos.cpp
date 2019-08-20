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

const int MAXN=100100;
int n;

vector<int> BFS(vector<vector<int>> &lista, int nodoInicial){
	int n = lista.size(),t;
	queue<int> cola;
	vector<int> distancias(n,n);
	cola.push(nodoInicial);
	distancias[nodoInicial] = 0;
	while(!cola.empty()){
		t = cola.front();
		cola.pop();
		for(int i = 0; i < lista[t].size(); i++){
			if(distancias[lista[t][i] == n){
				distancias[lista[t][i] = distancias[t]+1;
				cola.push(lista[t][i];
			}
		}
	}
	return distancias;
}

int main() {
    freopen("input.in", "r", stdin);
    ios::sync_with_stdio(0);
    while(cin >> n){
    
    }
    return 0;
}
