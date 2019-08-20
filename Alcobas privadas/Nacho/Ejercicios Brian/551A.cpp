#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v,0,sizeof(v))
#define dprint(v) cout << #v"=" << v << endl
#define endl "\n"
#define fst first
#define snd second
#define pb push_back
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 2003;

bool comp(int a, int b){
	return a < b;
}
	
int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	int a[n];
	int b[MAXN];
	int bsuma[MAXN+1];
	zero(b);
	int max = 0;
	forn(i,n){
		cin >> a[i];
		b[a[i]]++;
		if(a[i] > max) max = a[i];
	}
	bsuma[0] = b[0];
	forr(i, 1,MAXN)
		bsuma[i] = bsuma[i-1] + b[i];
	forn(i, n){
		cout << 1 + (n - bsuma[a[i]]) << " ";
	}
	cout << endl;
	return 0;
}
