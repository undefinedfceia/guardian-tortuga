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
	long long t, m, rep,q;
	string s, a;
	s = "";
	cin >> t;
	forn(i,t){
		cin >> m;
		forn(j, m){
			cin >> rep;
			cin >> a;
			forn(k, rep)
				s += a;
		}
		cin >> q;
		string query;
		long long ia, ib;
		forn(j,q){
			cout << "Case " << i << ":" << endl;
			cin >> query >> ia >> ib;
			if(query == "F"){
				forr(k, ia, ib)
					s[k] = '1';
			}
			if(query == "E"){
				forr(k, ia, ib)
					s[k] = '0';
			}
			if(query == "I"){
				forr(k, ia, ib)
					s[k] = s[k] == '1' ? '0' : '1';
			}
			if(query == "s"){
				long long count = 0;
				forr(k, ia, ib)
					count += s[k] == '1' ? 1 : 0;
				cout << "Q" << j << ": " << count << endl; 
			}
		}
	}
	
	return 0;
}

