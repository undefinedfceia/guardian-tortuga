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
#define tab "\t"

const int MAXN=100100;
const int FACT = 9;

int factorial(int n){
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

int solution(int n, int coins[], int i) {
    if (n == 0)
        return 0;
    if (coins[i] > n)
        return solution(n, coins, i - 1);
    return 1 + solution(n - coins[i], coins, i);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;

    cin >> n;

    int coins[FACT];

    forn(i, FACT) {
        coins[i] = factorial(i);
    }
    
    cout << solution(n, coins, FACT - 1) << endl;

	return 0;
}
