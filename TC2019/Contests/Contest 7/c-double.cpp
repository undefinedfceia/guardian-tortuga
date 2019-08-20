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

long double dist(long double x, long double y, long double ox, long double oy){
	return hypotl((x-ox),(y-oy));
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(nullptr);
    string s,s2;
    long double ox = 0,oy = 0;
    long double distancia = 0;
    bool first = true;
    cout << fixed;
    cout << setprecision(3);
    while(cin >> s){
		while(s[0] != '(') cin >> s;
		cin >> s2;
		s[0] = ' ';
		s[s.length()-1] = ' ';
		s2[s2.length()-1] = ' ';
		s2[s2.length()-2] = ' ';
		long double x = stod(s);
		long double y = stod(s2);
		//cout << x << " " << y << endl;
		if(!first){
			distancia += dist(x,y,ox,oy); 
			cout << "The salesman has traveled a total of " << distancia << " kilometers." << endl;
		}else
			first = false;
		ox = x; oy= y;
	}
	return 0;
}
