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

void print_solution(int points[2], int games[2], int last_winner) {
    if(!last_winner) {
        cout << games[0] << " (" << points[0] << "*) - " << games[1] << " (" << points[1] << ")" << endl;
    } else {
        cout << games[0] << " (" << points[0] << ") - " << games[1] << " (" << points[1] << "*)" << endl;
    }
}

void print_last_solution(int games[2]) {
    if( games[0] >= 2 || games[1] >= 2) {
        if( games[0] >= games[1]) {
            cout << games[0] << " (winner) - " << games[1] << endl;
        } else {
            cout << games[0] << " - " << games[1] << " (winner)" << endl;;
        }
    } else {
        cout << games[0] << " - " << games[1] << endl;
    }
}

bool check_end_game(int points[2], int last_winner) {
    return (points[last_winner] >= 5 && abs(points[0] - points[1]) >= 2) || points[last_winner] >= 10;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    string match;
    cin >> match;
    
    char winner = match[0];
    int last_winner = !(winner == 'S');
    int points[2] = {0, 0};
    int games[2] = {0, 0};
    int i = 1;
    
    if(winner != 'Q') {
        points[last_winner] += 1;
    } else {
        print_solution(points, games, last_winner);
        winner = match[i];
        last_winner = !(winner == 'S');
        points[last_winner] += 1;
        i += 1;
    }

    winner = match[i];

    while( winner != '\0' ) {
        if( winner != 'Q' && (games[0] < 2 && games[1] < 2) ){

            if( winner == 'R' )
                last_winner = !last_winner;

            points[last_winner] += 1;

            if( check_end_game(points, last_winner) ) {
                points[0] = points[1] = 0;
                games[last_winner] += 1;
            }

        } else {
            if (winner == 'Q') {
                if( i != (match.length() - 1) && (games[0] < 2 && games[1] < 2) )
                    print_solution(points, games, last_winner);
                else
                    print_last_solution(games);
            }
        }
        winner = match[++i];
    }
	return 0;
}