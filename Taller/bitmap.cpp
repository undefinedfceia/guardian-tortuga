#include <bits/stdc++.h>

#define forr(i, a, b) for(int i = a; i < b; i++)
#define forn(i, n) forr(i, 0, n)
#define zero(v) memset(v, 0, sizeof(v))

using namespace std;

vector<int> BFS(vector<vector<int> > &lista, int nodoInicial){
	int n = lista.size(),t;
	queue<int> cola;
	vector<int> distancias(n,n);
	cola.push(nodoInicial);
	distancias[nodoInicial] = 0;
	while(!cola.empty()){
		t= cola.front();
		cola.pop();
		forn(i, (int)lista[t].size()){
			if(distancias[lista[t][i]] == n){
				distancias[lista[t][i]] = distancias[t]+1;
				cola.push(lista[t][i]);
			}
		}
	}
	return distancias;
}


int main(){
	vector< vector<int> > lista;
	vector< pair<int,int> > entrada;
	int t,n,m,temp;
	string s;
	cin >> t;
	forn(k, t){
		lista.clear();
		entrada.clear();
		cin >> n >> m;
		vector<int> max(m,500);
		forn(i,n){
			cin >> s;
			forn(j,m){
				temp = s[j] - '0';
				if(temp == 1){
					entrada.push_back(pair<int,int>(i,j));
				}
			}
			lista.push_back(max);
		}
		
		forn(i, (int)entrada.size())
			lista[entrada[i].first][entrada[i].second] = 0;
		for(unsigned i = 0; i < lista.size(); i++){
			for(unsigned j = 0; j < lista[i].size(); j++)
				cout << lista[i][j] << " ";
			cout << endl;
		}
		
		vector<int> distancias = BFS(lista, 1);
		forn(i, (int)distancias.size()){
			cout << distancias[i] << " ";
		}
		
	}
	return 0;
}
