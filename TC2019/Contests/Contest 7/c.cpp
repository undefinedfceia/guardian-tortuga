#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(ll i=(a); i<(b); i++)
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

ll dist(ll x, ll y, ll ox, ll oy){
	return sqrt((x-ox)*(x-ox)+(y-oy)*(y-oy));
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(nullptr);
    string s;
    ll ox = 0,oy = 0;
    ll distancia = 0;
    bool first = true;
    cout << fixed;
    cout << setprecision(3);
    while(cin >> s){
		while(s[0] != '(') cin >> s;
		int n = s.length();s[0] = ' ';s[n-1] = ' ';
		ll x = stof(s)*100000;
		cin >> s;
		n = s.length();
		s[n-1] = ' ';
		ll y = stof(s)*100000;
		if(!first){
			distancia += dist(x,y,ox,oy); 
			cout << "The salesman has traveled a total of " << ((double)distancia)/100000 << " kilometers." << endl;
		}else{
			first = false;
		}
		ox = x; oy= y;
	}
	return 0;
}
