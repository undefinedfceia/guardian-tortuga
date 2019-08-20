const int MAXN=10010;
vector<ll> g[MAXN];

vector<int> BFS(int nodoInicial, int n){
	int t;
	queue<int> cola;
	vector<int> distancias(n,n);
	cola.push(nodoInicial);
	distancias[nodoInicial] = 0;
	while(!cola.empty()){
		t = cola.front();
		cola.pop();
		for(unsigned int i = 0; i < g[t].size(); i++){
			if(distancias[g[t][i]] == n){
				distancias[g[t][i]] = distancias[t]+1;
				cola.push(g[t][i]);
			}
		}
	}
	return distancias;
}