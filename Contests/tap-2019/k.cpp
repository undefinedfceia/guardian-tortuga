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

enum status {openA, openB, closeA, closeB};

struct event{
    status s;
    long long L, R, pos;

    event(status s, long long L, long long R, long long pos) : s(s), L(L), R(R), pos(pos) {}
    bool operator<(const event& e) const {
        if(pos == e.pos) return s < e.s;
        return pos < e.pos;
    }
};

bool comp(event a, event b){
	return a < b;
}

int main(){ 	
	//ios::sync_with_stdio(0);
	//cin.tie(nullptr);
	int n;
	cin >> n;
	vector<event> e;
	vector<event>::iterator it;
	ll l, r;
	string g;
	forn(i,n){
		cin >> g >> l >> r;
		if( g == "J"){
			e.pb(event(openA, l, r, l));
			e.pb(event(closeA, l, r, r));
		}else{
			e.pb(event(openB, l, r, l));
			e.pb(event(closeB, l, r, r));
		}
	}
	set<event*> opensA, opensB;
	sort(e.begin(), e.end(), comp);
	ll m = 0;
	for( it = e.begin(); it != e.end(); it++){
		event v = *it;
		if(v.s == openA)
			opensA.insert(&v);
		if(v.s == openB)
			opensB.insert(&v);
		if(v.s == closeA){
			if(sz(opensB) > 0){			
				ll iz = max((*opensB.begin())->L, v.L);
				ll der = min((*opensB.begin())->R, v.R);
				m = max(abs(der - iz), m);
			}
			opensA.erase(*opensA.find(&v));
		}
		if(v.s == closeB){
			if(sz(opensA) > 0){
				ll iz = max((*opensA.begin())->L, v.L);
				ll der = min((*opensA.begin())->R, v.R);
				m = max(abs(der - iz), m);
			}
			opensB.erase(*opensB.find(&v));
		}
	}
	cout << m << endl;
	return 0;
}
