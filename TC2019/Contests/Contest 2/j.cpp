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

const int MAXN=100010;
const double M = 0.74999999999;
double a[MAXN];

double sum(double i){
	return (1/(i*(i+2)*(i+1)));
}

double calc_a(int i){
	if(a[i] != 0.0)
		return a[i];
	double b = sum(((double)i))+calc_a(i-1);
	a[i] = b;
	return b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    zero(a);
    a[0] = 0; a[1] = (double)2/(double)3;
    calc_a(MAXN);
	int T,n;
	cin >> T;
	cout << fixed;
	cout << setprecision(11);
	forn(t,T){
		cin >> n;
		if(n>1000000){
			cout << M << endl;
			continue;
		}
		if(n>MAXN){
			double r = a[MAXN-1];
			forr(i,MAXN,n+1)
				r += sum(((double)i));
			cout << r << endl;
			continue;
		}
		cout << calc_a(n) << endl;
	}
	return 0;
}
