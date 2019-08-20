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
    cin >> n;
    string s;
    cin >> s;
    ll countR1 = 0; //Rojo par
    ll countB1 = 0; //Negro impar
    ll countR2 = 0; //Rojo impar
    ll countB2 = 0; //Negro par
    forn(i,n){
		if(s[i] == 'r' && i%2==0)
			countR1++;
		if(s[i] == 'b' && i%2!=0)
			countB1++;
		if(s[i] == 'r' && i%2!=0)
			countR2++;
		if(s[i] == 'b' && i%2==0)
			countB2++;
	}
	ll c1 = min(countR1,countB1) + abs(countR1-countB1); //Rojo impar Negro par
	ll c2 = min(countR2,countB2) + abs(countR2-countB2); //Rojo par Negro impar
	cout << min(c1,c2) << endl;
	return 0;
}
