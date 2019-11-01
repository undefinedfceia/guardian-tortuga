#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=a;i<b;i++) 
#define forn(i,n) forr(i,0,n)
#define zero(v) memset(v,0,sizeof(v))
#define sz(c) ((int)c.size())
#define fst first
#define snd second
#define pb push_back
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define dprint(v) cout << #v " = " << v << endl
#define endl "\n"
#define MOD 1000000007
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

bool comp(int a, int b){
	return a > b;
}

int main(){ 	
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int n,l,c;
	cin >> n >> l >> c;
	int col = ceil(((float)n/(float)l));
	int a[n];
	forn(i, n)
		cin >> a[i];
	sort(a,a+n,comp);
	int m = 0;
	int part = ceil((float)n/(float)col);
	forn(i, n){
		if(part*i < n)
			m += a[part*i];
	}
	if(m <= c)
		cout << 'S' << endl;
	else
		cout << 'N' << endl;
	return 0;
}
