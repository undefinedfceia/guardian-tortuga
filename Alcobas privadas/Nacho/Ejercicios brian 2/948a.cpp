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
char pasture[510][510];

bool is_valid_cell(int i, int j, int R, int C){
    return i >=0 && j >= 0 && i < R && j < C;
}

bool check_cell(int i, int j, int R, int C) {
    bool result = true;
    if(is_valid_cell(i - 1, j, R,C)){
        result &= pasture[i - 1][j] != 'W';
        if(result && pasture[i - 1][j] == '.')
            pasture[i - 1][j] = 'D';
    }
    if(is_valid_cell(i + 1, j, R,C)){
        result &= pasture[i + 1][j] != 'W';
        if(result && pasture[i + 1][j] == '.')
            pasture[i + 1][j] = 'D';
    }
    if(is_valid_cell(i, j - 1, R,C)){
        result &= pasture[i][j - 1] != 'W';
        if(result && pasture[i][j - 1] == '.')
            pasture[i][j - 1] = 'D';
    }
    if(is_valid_cell(i, j + 1, R,C)){
        result &= pasture[i][j + 1] != 'W';
        if(result && pasture[i][j + 1] == '.')
            pasture[i][j + 1] = 'D';
    }
    return result;
}

bool get_answer(int R, int C) {
    bool result = true;
    forn(i, R){
        forn(j, C){
            if(pasture[i][j] == 'S') {
                result &= check_cell(i, j, R, C);
            }
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    // cin.tie(nullptr);
    int R,C;
    cin >> R >> C;
    
    forn(i, R){
        forn(j, C){
            cin >> pasture[i][j];
        }
    }

    bool result = get_answer(R, C);

    cout << (result ? "Yes" : "No") << endl;

    if(result){
        forn(i, R){
            forn(j, C){
                cout << pasture[i][j];
            }
            cout << endl;
        }
    }
	return 0;
}
