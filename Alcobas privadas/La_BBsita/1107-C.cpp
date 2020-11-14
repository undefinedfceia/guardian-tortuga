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

ll comp(ll a, ll b){
return a < b;
}



ll highest_damage(ll damage_list[], int array_length , ll k)
{
    ll sum = 0;
    forn(i, array_length)
        sum = sum + damage_list[i];
    return sum;
}


int main() 
{
    ios::sync_with_stdio(0);
    ll n, k;
    cin>>n>>k;
    ll damages_list[n], dmg = 0;
    forn(i, n)
        cin>>damages_list[i];
    char button, current_char;
    ll consecutives = 0;
    cin>>button;
    ll consecutive_damage[n];
    zero(consecutive_damage);
    consecutive_damage[0] = damages_list[0];
    consecutives++;
    current_char = button;
    forr(i, 1, n){
        cin>>button;
        if (current_char != button){
            dmg = dmg + highest_damage(consecutive_damage, consecutives, k);
            zero(consecutive_damage);
            consecutive_damage[0] = damages_list[i];
            consecutives = 1;
            current_char = button;
            }
        else {
            if (consecutives < k){
                consecutive_damage[consecutives] = damages_list[i];
                consecutives++;}
            else
            {
                sort(consecutive_damage, consecutive_damage + k, comp);
                if(damages_list[i] > consecutive_damage[0])
                    consecutive_damage[0] = damages_list[i];
            }
        }

    }
    dmg = dmg + highest_damage(consecutive_damage, consecutives, k);
    cout<<dmg;
}