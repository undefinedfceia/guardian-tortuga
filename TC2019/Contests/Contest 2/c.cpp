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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
	int n;
	cin >> n;
	int k = (n-1)/2;
	ll a[n];
	forn(i, n)
		cin >> a[i];
	ll b[n], c[n], d[k];
	forn(i, k)
		d[i] = a[n-i-1] - a[i];
	forn(i, k){
		if(d[i]%2 != 0){
			cout << "NO" << endl;
			return 0;
		}
	}
	forn(i, k){
		b[n-i-1] = d[i]/2;
		b[i] = -1 * b[n-i-1];	
	}
	b[k]=0;
	forn(i, n)
		c[i] = a[i] - b[i];
	c[k] = a[k];		
	cout << "YES" << endl;
	forn(i, n)
		cout << b[i] << " ";
	cout << endl;	
	forn(i, n)
		cout << c[i] << " ";
	cout << endl;
    return 0;
}
