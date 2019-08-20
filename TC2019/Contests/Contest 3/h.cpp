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

const int MAXN=110;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,m,buf;
    cin >> n;
    int a[MAXN];
    int b[MAXN];
    zero(a);
    zero(b);
    forn(i,n){
		cin >> buf;
		a[buf]++;
	}	
	cin >> m;
    forn(i,m){
		cin >> buf;
		b[buf]++;
	}
	int count = 0;
	forr(i, 1,MAXN-1){
		while(b[i]&&a[i-1]){
			count++;
			b[i]--;
			a[i-1]--;
		}
		while(b[i]&&a[i]){
			count++;
			b[i]--;
			a[i]--;
		}
		while(b[i]&&a[i+1]){
			count++;
			b[i]--;
			a[i+1]--;
		}
	}
	cout << count << endl;
	return 0;
}
