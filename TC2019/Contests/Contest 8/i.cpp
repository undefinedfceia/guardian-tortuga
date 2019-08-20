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

const int MAXN=100010;

int main() {
    int m,n = 0;
	ll s;
    int a[MAXN];    
    zero(a);
    while(cin >> m){
		if(m == 0){ zero(a); cout << endl; n = 0; s = 0; continue; }
		if(m == -1 && n == 0) { continue; }
		if(m == -1){ 
			int media = s/n;
			n--;
			s-=media;
			media=s/n;
			cout << media << endl;
			//s = s-media;
			
			//a[media] = 0;
			continue;
		}
		a[m]++;
		s = s+m;
		n++;
	}
	return 0;
}
