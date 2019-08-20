#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define zero(v) memset(v,0,sizeof(v))
#define sz(c) ((int)c.size())
#define dprint(v) cout << #v" = " << v << endl
#define endl "\n"
#define fst first
#define snd second
#define pb push_back
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 10;
const string MAX = "zzzzzzzzzzzz";

string a,b;
string aprefix[MAXN];
string bprefix[MAXN];
	
void getPrefix(){
	aprefix[0] = a[0];
	bprefix[0] = b[0];
	forr(i, 1,sz(a))
		aprefix[i] = a[i] + aprefix[i-1];
	forr(i, 1,sz(b))
		bprefix[i] = b[i] + bprefix[i-1];
	forn(i, sz(a))
		reverse(aprefix[i].begin(), aprefix[i].end());
	forn(i, sz(b))
		reverse(bprefix[i].begin(), bprefix[i].end());
}

int main(){
	ios::sync_with_stdio(0);
	cin >> a >> b;
	getPrefix();
	string min = MAX;
	string s;
	forn(i, sz(a)){
		forn(j, sz(b)){
			s = aprefix[i] + bprefix[j];
			if(s < min) min = s;
		}
	}
	cout << min << endl;
	return 0;
}
