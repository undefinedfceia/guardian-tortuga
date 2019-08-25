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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t,b,p,f,h,c;
    cin>>t;
    forn(i,t){
		cin>>b >> p >> f >> h >>c;
		int b1 = (b % 2 == 0) ? b : b-1;
		if(h>c)
		{
			int may=min(p,b1/2);
			int may1=min(b1/2-may,f);
			cout<<may*h+may1*c<<endl;	
		}
		else
		{
			int may=min(f,b1/2);
			int may1=min(p,b1/2-may);
			cout<<may*c+may1*h<<endl;
		}
	}
	return 0;
}

