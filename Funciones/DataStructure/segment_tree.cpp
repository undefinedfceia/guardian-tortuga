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
