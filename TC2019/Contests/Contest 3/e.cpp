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

const int MAXN=2200;
int homo[MAXN];

bool is_homo(int a, int b){
	if((homo[a] == homo[b] && homo[a] != 0) || a == b)
		return true;
	if(!homo[a]){
		if(!homo[b])
			homo[a] = 1;
		else
			homo[a] = (homo[b] == 1) ? 2 : 1;
	}
	if(!homo[b])
		homo[b] = (homo[a] == 1) ? 2 : 1;
	return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t,n,s,a,b;
    cin >> t;
    forn(i,t){
		cin >> n >> s;
		zero(homo);
		bool hetero = true;
		forn(j,s){
			cin >> a >> b;
			hetero = !is_homo(a,b);
			if(!hetero)
				break;
		}
		cout << "Scenario #" << i+1 << ":" << endl;
		if(hetero)
			cout << "No suspicious bugs found!" << endl;
		else
			cout << "Suspicious bugs found!" << endl;
	}
    return 0;
}
