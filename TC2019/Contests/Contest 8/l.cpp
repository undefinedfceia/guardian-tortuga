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
    int n;
    string home,temp,x="XXX",y="YYY";
    cin >> n;
    cin >> home;
    multimap<string,string> f;
    multimap<string,string>::iterator it;
    forn(i,n){
		cin >> temp;
		x[0]=temp[0];x[1]=temp[1];x[2]=temp[2];
		y[0]=temp[5];y[1]=temp[6];y[2]=temp[7];
		f.insert({x,y});
	}
	string k = home;
	while(it = f.find(k), it != f.end()){
		k = it->snd;
		f.erase(it);
	} 
	if(k == home)
		cout << "home" << endl;
	else
		cout << "contest" << endl;
	return 0;
}
