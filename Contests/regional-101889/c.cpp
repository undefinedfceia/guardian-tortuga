#include <bits/stdc++.h>
using namespace std;
#define forr(i, a, b) for(int i = a; i < b; i++)
#define forn(i, n) forr(i, 0, n)
#define zero(v) memset(v, 0, sizeof(v))
#define fst first
#define snd second
#define sz(c) ((int)c.size())
#define dprint(v) cout << #v" = " << v << endl
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int k,n;
	cin >> k >> n;
	int a[k],b;
	zero(a);
	forn(i, n){
		cin >> b;
		a[b-1] += 1; 
	}
	set<int> grupo;
	forn(i,k)
		grupo.insert(a[i]);
	if(grupo.size() > 3){
		cout << "*" << endl;
		return 0;
	}
	//CARDINAL DE GRUPO ES 3 2
	if(grupo.size() == 3){
		// -x +y
		int Mi = max_element(a,a+k) - a;
		int mi = min_element(a,a+k) - a;
		if(a[Mi] - a[mi] > 2){
			cout << "*" << endl;
			return 0;
		}
		cout << "-" << Mi + 1 << " +" << mi  + 1 << endl;
		return 0;
	}
	//CARDINAL 2
	//-x o +x
	int Mi = max_element(a,a+k) - a;
	int mi = min_element(a,a+k) - a;
	if(a[Mi] - a[mi] > 2){
		cout << "*" << endl;
		return 0;
	}else if(a[Mi] - a[mi] == 2){
		cout << "-" << Mi  + 1 << " +" << mi  + 1 << endl;
		return 0;
	}else{
		int Mc = 0;
		int mc = 0;
		/*forn(i, k){
			
			Mc += (a[i] == a[Mi]) ? 1 : 0; 
			mc += (a[i] == a[mi]) ? 1 : 0; 
		}
		dprint(a[Mi]);
		dprint(a[mi]);
		dprint(Mc);
		dprint(mc);
		forn(i,k)
			cout << a[i] <<  " ";
		cout << endl;*/
		if(Mc - mc == 0){
			cout << "+" << mi  + 1 << endl;
			return 0;
		}
		if(abs(Mc - mc) == 1){
			if(Mc == 1)
				cout << "-" << Mi  + 1 << endl;
			else
				cout << "+" << mi  + 1 << endl;
			return 0;
		} 
		if(abs(Mc - mc) == 2){
			cout << "-" << Mi  + 1 << " +" << mi + 1 << endl;
			return 0;
		}
		cout << "*" << endl;
		return 0;
	}
	return 0;
}
