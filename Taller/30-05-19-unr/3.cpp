#include <bits/stdc++.h>

#define forr(i, a, b) for(int i = a; i < b; i++)
#define forn(i, n) forr(i, 0, n)
#define zero(v) memset(v, 0, sizeof(v))

using namespace std;

char check(int a, int b){
	int r = a - b;
	if(r < 65)
		r = r + 26;
	return ((char)r);
}

int main(){
	long long n, m;
	int j=0;
	char c[55];
	cin >> n;
	forn(i, n){
		j = 0;
		cin >> c >> m;
		while(c[j] != '\0'){
			
			c[j] = check((int)c[j], m);
			j++;
		}
		string s(c);
		cout << s << endl;
	}
	return 0;
}
