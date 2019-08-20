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


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    ll a;
    cin >> n;
    forn(i,n){
		cin >> a;
		if(a%188==0)
			cout << 4 << endl;
		if(a%432==0)
			cout << 0 << endl;
		if(a%100==0)
			cout << 2 << endl;
		if(a%765==0)
			cout << 1 << endl;
	}
	return 0;
}
