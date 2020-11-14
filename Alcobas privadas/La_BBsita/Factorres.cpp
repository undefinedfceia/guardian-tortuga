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



vector<ll> factorize(ll m){
  vector<ll> fact;
  for(ll a=5; a*a<=m; a++){
    if(m%a==0 & m/a >=5){
      fact.push_back(a);
      fact.push_back(m/a);
    }
  }
  return fact;
}



int main() {
    ios::sync_with_stdio(0);
    int k;
    string phrase, vowels;
    vector <ll>::iterator it;
    vector <ll> facts;
    cin>>k;
    ll i=0,j=0;
    if (k<25){
      cout<<-1;
      return 0;} 
    facts = factorize(k);
    if (facts.empty())
    {
      cout<<-1;
      return 0;
    }
    phrase = "";
    vowels = "aeiou";
    it = facts.begin();
    for(i=0; i<*it; i++)
    {
      for (j=0; j< *(it + 1); j++)
      {
        phrase = phrase + vowels[(i+j)%5];
      }
    }
    cout<<phrase;
	  return 0;
}
