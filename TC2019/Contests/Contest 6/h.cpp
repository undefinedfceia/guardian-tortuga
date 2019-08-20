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
typedef long long ll;
typedef pair<int,int> ii;
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define dprint(v) cout << #v"=" << v << endl
#define endl "\n"

const int MAXN=100100;

ll oper(ll a, ll b){
  if(b<a) swap(a,b);
  if(a==0) return b;
  else{
    return oper(b%a,a);
  }
}

int NEUT = 0;

struct STree { // [cerrado-abierto), defininir "oper" y "NEUT"
vector<ll> st;int n;
STree(int n): st(4*n+5,NEUT), n(n) {}
void upd(int k, int s, int e, int p, ll v){
if(s+1==e){st[k]=v;return;}
int m=(s+e)/2;
if(p<m)upd(2*k,s,m,p,v);
else upd(2*k+1,m,e,p,v);
st[k]=oper(st[2*k],st[2*k+1]);
}
ll query(int k, int s, int e, int a, int b){
if(s>=b||e<=a)return NEUT;
if(s>=a&&e<=b)return st[k];
int m=(s+e)/2;
return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
}
void upd(int p, ll v){upd(1,0,n,p,v);}
ll query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree st(n);st.upd(i,v);st.query(s,e);


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n, q, type, l, r, x, y, j;
    cin >> n;
    STree st(n);
    int a;
    bool guardar;
    forn(i, n){
    cin>>a;
    st.upd(i, a);
  }
  cin>> q;
  forn(i, q){
    cin >> type;
    if(type == 1){//consulta
      cin >> l >> r >> x;
      guardar = st.query(l, r) == x;
      if(guardar){
        cout << "YES" << endl;
        continue;
      }
      while(l <= r){
        
        
        
      }
      if(guardar)
        cout << "YES" << endl;
      else 
        cout << "NO" << endl;
    }
    if(type==2){//update
      cin >>j >> y;
      st.upd(j, y);
    }
    
  }
    
    return 0;
}
