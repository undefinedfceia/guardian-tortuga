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
int matrixEmployees[110][110];
int n, m;

int comp(int a, int b) {
    return a < b;
}

bool are_neighbours(int lang_a[], int lang_b[], int a, int b) {
    sort(lang_a, lang_a + a, comp);
    sort(lang_b, lang_b + b, comp);
    bool found = false;

    forn(i, a) {
        
        if(found)
            break;

        forn(j, b) {
            found = lang_a[i] == lang_b[j];

            if(found)
                break;

            if(lang_a[i] > lang_b[j])
                break;
        }
    }

    return found;
}

vector<int> BFS(ii root) {
    bool visited[n][n];
    vector<int> visited_vector;
    queue<ii> q;
    ii node;

    q.push(node);
    visited_vector.pb(root.fst);
    visited[root.fst, root.snd];


    forn(i, n) {
        forn(j, n) {
            visited[i][j] = false;
        }
    }

    while(!q.empty()) {
        node = q.front();
        q.pop();

        if(visited[node.fst][node.snd])
            continue;
        
        visited[node.fst][node.snd] = true;

        forr(i, node.snd, n) {
            if (matrixEmployees[node.fst][i] == 1 && !visited[node.fst][i]) {
                q.push(ii(i, i));
                visited_vector.pb(i);
            }
        }
    }

    return visited_vector;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(nullptr);

    cin >> n >> m;

    int employeesLanguages[n][m];
    int employeesLanguagesSize[n];

    forn(i, n) {
        cin >> employeesLanguagesSize[i];
        forn(j, employeesLanguagesSize[i]) {
            cin >> employeesLanguages[i][j];
        }
    }

    zero(matrixEmployees);
    bool are_neigh;

    forn(i, n) {
        forr(j, i, n) {
            are_neigh = are_neighbours(employeesLanguages[i], employeesLanguages[j], employeesLanguagesSize[i], employeesLanguagesSize[j]);
            matrixEmployees[i][j] = are_neigh;
            matrixEmployees[j][i] = are_neigh;
        }
    }

    bool found_employees[n];

    forn(i, n) {
        found_employees[i] = false;
    }

    vector<int>::iterator it;
    int partitions = -1;

    forn(i, n) {
        forn(j, n) {
            cout << matrixEmployees[i][j] << tab;
        }
        cout << endl;
    }


    forn(i, n) { 
        cout << "i:" << i << endl;
        if(!found_employees[i]) {
            vector<int> founds = BFS(ii(i, i));
            for(it = founds.begin(); it != founds.end(); ++it) {
                cout << *it << tab;
                found_employees[(*it)] = true;
            }

            partitions += 1;

            cout << endl;
            forn(i, n) {
                cout << found_employees[i] << tab;
            }
            cout << endl << "*******" << endl;
        }
    }

    cout << partitions << endl;


	return 0;
}