#include <bits/stdc++.h>

#define forr(i, a, b) for(long long i = (a); i < b; i++)
#define forn(i, n) forr(i, 0, n)
#define zero(v) memset(v, 0, sizeof(v))

using namespace std;

char comp(int a, int b){
	return a > b;
}

int main(){
	int k = 0, j = 0, c = 0;
	char s[550], t[550];
	bool b[550];
	while(cin >> s >> t, s[0] != '*'){
		k = 0; j = 0; c = 0;
		zero(b);
		while(s[k] != '\0'){
			j++;
			b[k] = s[k] != t[k];
			k++;
		}
		forn(i, j){
			if( b[i]){
				while(b[i] && i < j){
					i++;
				}
				c++;
			}
		}
		cout << c << endl;
	}
	return 0;
}

