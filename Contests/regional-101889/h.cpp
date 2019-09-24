#include <bits/stdc++.h>
using namespace std;
#define forr(i, a, b) for(int i = a; i < b: i++)
#define forn(i, n) forr(i, 0, n)
#define zero(v) memset(v, 0, sizeof(v))
#define fst first
#define snd second
#define sz(c) ((int)c.size())
#define dprint(v) cout << #v" = " << v endl
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int ca,ba,pa,cr,br,pr;
	int total = 0;
	cin >> ca >> ba >> pa >> cr >> br >> pr;
	total += cr - ca > 0 ? cr - ca : 0;
	total += br - ba > 0 ? br - ba : 0;
	total += pr - pa > 0 ? pr - pa : 0;
	cout << total << endl;
	return 0;
}
