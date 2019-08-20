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


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    int a[n];
    forn(i,n)
		cin >> a[i];
	int M = *(max_element(a,a+n));
	int m = *(min_element(a,a+n));
	if(M - m <= k){
		cout << "YES" << endl;
		forn(i,n){
			forn(j,a[i])
				cout << ((j+1)%k == 0 ? k : (j+1)%k) << " ";
			cout << endl;
		}
	}	
	else
		cout << "NO" << endl;
    return 0;
}
