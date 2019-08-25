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
vector<ii> sol;
int n,m,a[50][50],b[50][50];

bool check_index(int i, int j){
	return !(i - 1 < 0 || j -1 < 0 || i > n-1 || j > m-1); 
}

bool check_one(int i, int j){
	bool t1 = a[i][j] && a[i+1][j] && a[i][j+1] && a[i+1][j+1];
	if(t1){
		sol.pb({i+1,j+1});
		b[i][j] = b[i+1][j] = b[i][j+1] = b[i+1][j+1] = 1;
	}
	return t1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>> n >>m;
    zero(b);
    forn(i,n)
		forn(j,m)
			cin>>a[i][j];
    forn(i,n-1){
		forn(j,m-1){
			if(a[i][j]){
				check_one(i, j);
			}
		}
	}
	bool r = true;
    forn(i,n)
		forn(j,m)
			r = r && b[i][j] == a[i][j];
	if(r){
		cout << sz(sol) << endl;		
		for(ii v : sol)
			cout << v.fst << " " << v.snd << endl;
	}else{
		cout << -1 << endl;
	}
	return 0;
}
