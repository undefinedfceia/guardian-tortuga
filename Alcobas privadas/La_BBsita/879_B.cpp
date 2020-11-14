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

int main() 
{
    ios::sync_with_stdio(0);
    int n, list[500];
    ll k;
    cin>>n>>k;
    int a, max = 0, pos_max = 0;
    int wins = 0, current_winner;
    bool flag=true;
    forr(i,0,n)
    {
        cin>>a;
        if (max < a){
            max = a;
            pos_max = i;
        }
        list[i]=a;
    }
    if (pos_max < k || n < k)
        cout<<max;
    else
    {
        current_winner = list[0];
        wins = 0;
        forr(i, 1, n)
        {
            if (list[i] < current_winner)
                wins++;
            else
                {
                    current_winner = list[i];
                    wins = 1;
                }
            if (wins == k){
                cout<<current_winner;
                flag = false;
                break;}
        }
        if (flag)
            cout<<current_winner;
    }
    

}