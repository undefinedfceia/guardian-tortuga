#include <bits/stdc++.h>
using namespace std;
#define forr(i, a, b) for(int i = a; i < b; i++)
#define forn(i, n) forr(i, 0, n)
#define zero(v) memset(v,0, sizeof(v))
#define fst first
#define snd second
#define dprint(v) cout << #v " = " << v <<endl
#define endl "\n"
#define pb push_back
#define sz(c) ((int)c.size())
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;

string notas[] = {"DO", "DO#", "RE", "RE#", "MI", "FA", "FA#", "SOL", "SOL#",
"LA", "LA#", "SI"};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int n;
	string s;
	cin >> n >> s;
	int i = find(notas,notas+12, s) - notas;
	cout << notas[(( i - n) % 12 + 12) % 12] << endl;
	return 0;
}
