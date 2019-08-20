#include <bits/stdc++.h>

#define forr(i,a,b) for(int i=a; i < b; i++)
#define forn(i,n) forr(i,0,n)

using namespace std;
bool comp(bool *x, int n, int a, int k){
	vector<int> intervalo;
	int c = 0;
	forn(i,n){
		if(x[i]){
			intervalo.push_back(c);
			c = 0;
		}else{
			c++;
		}
	}
	intervalo.push_back(c);
	vector<int>::iterator it;
	int posibles = 0;
	for(it = intervalo.begin(); it != intervalo.end(); it++)
		posibles += (*it >= a) ? 1 : 0; 
	return  posibles >= k;
}

int main(){
	int n,m;
	int k,a;
	cin >> n >> k >> a >> m;
	long long tablero[m];
	forn(i,m)
		cin >> tablero[i];
	bool x[n] = {0};
	forn(i,m){
		x[tablero[i]-1] = 1;
		if(!comp(x,n,a,k)){
			cout << i+1 << endl;
			return 0;
		}
	}
		
	
	return 0;
}

