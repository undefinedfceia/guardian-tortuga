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

vector<ii> calle;
vector<ii>::iterator it;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int T;
    cin >> T;
    forn(t, T){
		int n;
		ll a,b;
		cin >> n >> a >> b;
		char s[n];
		cin >> s;
		calle.clear();
		int current = s[0] - '0';
		int count = 1;
		bool allZero = 1;
		forr(i, 1, n){
			if(current == (s[i]-'0'))
				count++;
			else{
				allZero = 0;
				calle.pb({current, count});
				count = 1;
				current = s[i] - '0';
			}
		}
		if(allZero){
			cout << a*n + b*(n+1) << endl;;
			continue;
		}
		//calle.pb({current, count});
		ll cost = 0;
		// v.fst = 1 o 0 y en v.snd esta la cantidad
		for(it = calle.begin() + 1; it != calle.end(); it++){
			ii v = *it;
			if(v.fst)
				cost += b*(v.snd+1);
			else{
				if(v.snd  != 1)
					cost += min(2*a, b*(v.snd-1));
			}
		}
		cost += a*(n+2) + b*(n+1);
		cout << cost << endl;
	}
	return 0;
}
