#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)

int main() {
    string s;
	cin >> s;
	long long count = 0;
	long long count2 = 0;
	forn(i,(int)s.length()){
		if(s[i]=='B'){
			count++;
		}else{
			count2+=count;
		}
	}
	cout << count2 << endl;
	return 0;
}

