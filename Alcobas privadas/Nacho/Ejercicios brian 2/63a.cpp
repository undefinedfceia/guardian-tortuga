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

int main() {
    ios::sync_with_stdio(0);
    // cin.tie(nullptr);
    int n;
    cin >> n;

    string name, type;

    vector<string> wc;
    vector<string> m;
    vector<string> r;
    vector<string> c;
    vector<string>::iterator it;

    forn(i, n) {
        cin >> name >> type;
        if( type.compare("woman") == 0 || type.compare("child") == 0)
            wc.push_back(name);
        if( type.compare("man") == 0)
            m.push_back(name);
        if( type.compare("rat") == 0)
            r.push_back(name);
        if( type.compare("captain") == 0)
            c.push_back(name);
    }

    for(it = r.begin(); it != r.end(); ++it)
        cout << *it << endl;
    for(it = wc.begin(); it != wc.end(); ++it)
        cout << *it << endl;
    for(it = m.begin(); it != m.end(); ++it)
        cout << *it << endl;
    for(it = c.begin(); it != c.end(); ++it)
        cout << *it << endl;
	return 0;
}