#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define pb push_back
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define dprint(v) cout << #v"=" << v << endl
#define endl "\n"

const int MAXN=100100;

int a[5500];
 
bool check(int n){
	forn(i,n)
		if (a[i] == 1 || a[i] == 2) return true;
	return false;
}

bool isConfused(ll a, ll b, ll c){
	if(a==1 && b==0)
		return false;
	if(a==1 && c != 0)
		return true;
	if(a==2 && b==0)
		return false;
	if(a==2 && b>0 && b < 7 && c != 0)
		return true;
	return false;
}

int tabla[MAXN];
bool is_tabla[MAXN];

ll f(int i,int n){
	if(is_tabla[i])
		return tabla[i];
	if(i==n || i==n-1) return 1;
	int z = (i==n-2) ? 1 : a[i+2];
	if(isConfused(a[i], a[i+1], z)){
		int c = f(i+2,n);
		int b = f(i+1,n);
		is_tabla[i] = true;
		tabla[i] = b+c;
		return b+c;
	}
	int a = f(i+1,n);
	is_tabla[i] = true;
	tabla[i] = a;
	return a;
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(nullptr);
    string s;
    zero(a);
    while(cin >> s, s != "0"){
		int n = s.length();
		forn(i,n)
			a[i] = s[i]-'0';
		if(!check(n)){
			cout << 1 << endl;
			continue;
		}
		zero(tabla);
		zero(is_tabla);
		cout << f(0,n) << endl;
	}
	return 0;
}
