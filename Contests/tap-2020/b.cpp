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
    cin.tie(nullptr);

    int n, d, l, r, c;

    cin >> n;

    int tablero[10][10];
    zero(tablero);

    bool valido = true;

    forn(i, n) {
        cin >> d >> l >> r >> c;

        r -= 1;
        c -= 1;

        if(d) {
            forr(j, r, r + l) {
                valido &= j >= 0 && j < 10 && c >= 0 && c < 10;
                if(valido){
                    valido &= ! tablero[j][c];
                    if(valido) {
                        tablero[j][c] = 1;
                    } else {
                        cout << "N" << endl;
                        return 0;
                    }
                } else {
                    cout << "N" << endl;
                    return 0;
                }
            }
        } else {
            forr(j, c, c + l) {
                valido &= j >= 0 && j < 10 && c >= 0 && c < 10;
                if(valido){
                    valido &= ! tablero[r][j];
                    if(valido) {
                        tablero[r][j] = 1;
                    } else {
                        cout << "N" << endl;
                        return 0;
                    }
                } else {
                    cout << "N" << endl;
                    return 0;
                }
            }
        }
    }

    if(valido)
        cout << "Y" << endl;
    else
        cout << "N" << endl;

	return 0;
}
