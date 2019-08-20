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
typedef long long ll;
typedef pair<int,int> ii;
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define dprint(v) cout << #v"=" << v << endl
#define endl "\n"

const int MAXN=100100;
int n;

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(nullptr);
    long long n;
    cin >> n;
    long long a[n];
    forn(i,n)
		cin >> a[i];
	/*long long b[n];
	partial_sum(a,a+n,b);
	*/
	vector<pair<int,int> > intervalos;
	long long i=0;
	forn(k,n){
		if(a[k] < 0){
			intervalos.pb({i,k});
			i=k+1;
		}	
	}
	intervalos.pb({i,n});
	
	forn(k,sz(intervalos)){
		ll suma = 0;
		forr(j, intervalos[k].fst, intervalos[k].snd)
			suma += a[j];
		cout << suma << " ";
		if(intervalos[k].snd != n)
			cout << a[intervalos[k].snd]<< " ";
	}
	
    return 0;
}
/*10
23 1 -2 4 5 -1 0 1 2 10*/
