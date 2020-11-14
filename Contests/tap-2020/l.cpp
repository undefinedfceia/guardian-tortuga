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

const int MAXN=40;
char sopa[MAXN][MAXN];
int resultado[MAXN][MAXN];
int resultado_bckp[MAXN][MAXN];
int L, C, N;

bool in_bounds(ii pair) {
    return pair.fst >= 0 && pair.fst < L && pair.snd >= 0 && pair.snd < C;
}

bool search_path(ii offset, ii position, string s) {
    // cout << s << tab << "offset: " << offset.first << " " << o
    if(s == "")
        return true;
    if(!in_bounds(position))
        return false;

    int index = s.find(sopa[position.fst][position.snd]);
    if(index == string::npos)
        return false;
    s.erase(s.begin() + index);
    return search_path(offset, ii(position.fst + offset.fst, position.snd + offset.snd), s);
}

void mark_path(ii offset, ii position, int deepth){
    if(deepth <= 0)
        return;
    resultado[position.fst][position.snd] += 1;
    deepth -= 1;
    return mark_path(offset, ii(position.fst + offset.fst, position.snd + offset.snd), deepth);
}

void clean_result() { 
    forn(l, L) {
        forn(c, C) {
            if(abs(resultado[l][c] - resultado_bckp[l][c]) > 1)
                resultado[l][c] = resultado_bckp[l][c] + 1;
        }
    }
}

void search_anagram(string s, ii pos) {

    ii offset = ii(0, 1);
    string word = s;
    if(search_path(offset, pos, word)) {
        mark_path(offset, pos, word.length());
    }

    offset = ii(1, 1);
    word = s;
    if(search_path(offset, pos, word)) {
        mark_path(offset, pos, word.length());
    }

    offset = ii(-1, 1);
    word = s;
    if(search_path(offset, pos, word)) {
        mark_path(offset, pos, word.length());
    }

    offset = ii(1, 0);
    word = s;
    if(search_path(offset, pos, word)) {
        mark_path(offset, pos, word.length());
    }

    offset = ii(-1, 0);
    word = s;
    if(search_path(offset, pos, word)) {
        mark_path(offset, pos, word.length());
    }

    offset = ii(1, -1);
    word = s;
    if(search_path(offset, pos, word)) {
        mark_path(offset, pos, word.length());
    }

    offset = ii(0, -1);
    word = s;
    if(search_path(offset, pos, word)) {
        mark_path(offset, pos, word.length());
    }

    offset = ii(-1, -1);
    word = s;
    if(search_path(offset, pos, word)) {
        mark_path(offset, pos, word.length());
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> L >> C;

    forn(i, L) {
        forn(j, C)
            cin >> sopa[i][j];
    }

    cin >> N;
    
    zero(resultado);
    string word;

    // cout << "********************" << endl;
    // forn(l, L) { 
    //     forn(c, C) {
    //         cout << sopa[l][c] << tab;
    //     }
    //     cout << endl;
    // }
    // cout << "********************" << endl << endl;

    forn(n ,N) {
        cin >> word;

        forn(l, L) { 
            forn(c, C) {
                resultado_bckp[l][c] = resultado[l][c];
            }
        }

        forn(i, L) {
            forn(j, C){
                if(word.find(sopa[i][j]) != string::npos ) {
                    search_anagram(word, ii(i, j));
                }
            }
        }

        // cout << "********************" << endl;
        // forn(l, L) { 
        //     forn(c, C) {
        //         cout << resultado[l][c] << tab;
        //     }
        //     cout << endl;
        // }
        // cout << "********************" << endl << endl;

        clean_result();

        // cout << "********************" << endl;
        // forn(l, L) { 
        //     forn(c, C) {
        //         cout << resultado[l][c] << tab;
        //     }
        //     cout << endl;
        // }
        // cout << "********************" << endl << endl;
    }

    int special_characters = 0;

    forn(i, L){
        forn(j, C) { 
            if(resultado[i][j] > 1)
                special_characters += 1;
        }
    }

    cout << special_characters << endl;

	return 0;
}