#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define zero(v) memset(v,0,sizeof(v))
#define sz(v) ((int)v.size())
#define pb push_back
#define fst first
#define snd second
#define dprint(v) cout << #v " = " << v << endl
#define endl "\n"
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

int main(){
	ios::sync_with_stdio(0);
	string s, o = "";
	vector<int>	v;
	cin >> s;
	forn(i, sz(s))
		if(s[i] != '+')
			v.pb(s[i]-'0');
	sort(v.begin(),v.end());
	forn(i, sz(v)){
		o += v[i] + '0';
		o += '+';
	}
	o[sz(o)-1] = ' ';
	cout << o << endl;
	return 0;
}
