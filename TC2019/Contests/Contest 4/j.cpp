#include <bits/stdc++.h>

using namespace std;

#define forr(i,a,b) for(int i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define zero(v) memset(v,0,sizeof(v))
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())

typedef pair<int,int> ii;

int main(){
	int t;
	cin >> t;
	forn(z,t){
		int w,h,n, a, b;
		cin >> w >> h >> n;
		vector<int> x;
		vector<int> y;
		vector<int> xi,yi;
		if(n==0){
			cout << w*h << endl;
			continue;
		}
		forn(g,n){
			cin >> a >> b;
			x.pb(a);
			y.pb(b);
		}
		sort(x.begin(),x.end());
		sort(y.begin(),y.end());
		xi.pb(x[0]-1);
		yi.pb(y[0]-1);
		forn(i,n-1){
			xi.pb(x[i+1]-x[i]-1);
			yi.pb(y[i+1]-y[i]-1);
		}
		xi.pb(w-x[sz(xi)-1]);
		yi.pb(h-y[sz(yi)-1]);
		/*forn(i,sz(xi)){
			cout << xi[i] << " " << yi[i] << endl;
		}*/
		cout << ((*max_element(xi.begin(),xi.end()))*(*max_element(yi.begin(),yi.end()))) << endl;			
	}
	return 0;
}
