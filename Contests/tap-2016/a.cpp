#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=a;i<b;i++) 
#define forn(i,n) forr(i,0,n)
#define zero(v) memset(v,0,sizeof(v))
#define sz(c) ((int)c.size())
#define fst first
#define snd second
#define pb push_back
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define dprint(v) cout << #v " = " << v << endl
#define endl "\n"
#define MOD 1000000007
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

int main(){ 	
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	string s;
	cin >> s;
	forn(i, sz(s)){
		if(s[i] == 'i'){
			cout << "N" << endl;
			return 0;
		}
	}
	cout << "S" << endl;
	return 0;
}
