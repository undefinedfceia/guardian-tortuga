#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define pb push_bac
#define fst first
#define snd second
typedef long long ll;
typedef pair<int,int> ii;
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define dprint(v) cout << #v"=" << v << endl
#define endl "\n"

const int MAXN=100100;
const int s = 1000000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int a[s],n,b;
    forn(i,s)
		a[i] = i;
	cin >> n;
	forn(i,n){
		cin >> b;
		a[b] = -1;
	}
	int i = 0, j = 1;
	
    return 0;
}

