#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(ll i=(a); i<(b); i++)
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

const int MAXN=100;

int b[MAXN];

int cantUnos(ll a){
	int count = 0;
	forn(i,64)
		count += (a>>i)&1;
	return count;
}
void fill_cantUnos(){
	forn(i,MAXN)
		b[i] = cantUnos(i);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    ll l,h,x,a;
    fill_cantUnos();
    while(cin >> l >> h >> x, !(l==0 && h ==0 && x==0)){
		int count = 0;
		forr(i,l,h+1){
			int ni = 0;
			a=i;
			while(a!=1){
				if(a<MAXN)
					a = b[a];
				else
					a = cantUnos(a);
				ni++;
			}
			if(ni==x)
				count++;
		}
		cout << count << endl;
	}
	return 0;
}
