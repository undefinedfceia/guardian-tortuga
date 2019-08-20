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


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, count=0;
    cin>> n;
    
    ll c[n], t[n], sync[n];
    forn(i, n)
		cin>> c[i];
	forn(j, n)
		cin >> t[j];
	if(c[0] != t[0] || c[n-1] != t[n-1]){
		cout<<"No"<< endl;
		return 0;
	}
	forn(k, n){
		if(c[k] == t[k])
			count++;
	}
	if(count == n){
		cout << "Yes"<< endl;
		return 0;
	}else{///////////////////////////////
		sync[0]= c[0];
		sync[n-1]= c[n-1];
		forr(l,1, n-1){
			sync[l] = c[l-1]+c[l+1]-c[l];
		}/////////////////////////////
		
	} 
		
		
    return 0;
}

