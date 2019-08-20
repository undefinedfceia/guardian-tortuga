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

const ll MAXN = 10000000000000;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> a;
    ll b;
    forn(i,n){
		cin >> b;
		a.pb(b);
	}
	ll min = *min_element(a.begin(),a.end());
	vector<ll>::iterator j = find(a.begin(),a.end(), min);
	vector<ll>::iterator k;
	vector<ll> dist;
	while(j != a.end()){
		k = find(j+1,a.end(),min);
		if(k != a.end())
			dist.pb((k-a.begin())-(j-a.begin()));
		j = k;
	}
	cout << *(min_element(dist.begin(), dist.end())) << endl;
    return 0;
}
