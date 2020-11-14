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

const int MAXN=3;
#define MAXP 100000000	//no necesariamente primo

int criba[MAXP+1];

void crearcriba(){
	int w[] = {4,2,4,2,4,6,2,6};
	for(int p=25;p<=MAXP;p+=10) criba[p]=5;
	for(int p=9;p<=MAXP;p+=6) criba[p]=3; 
	for(int p=4;p<=MAXP;p+=2) criba[p]=2;
	for(int p=7,cur=0;p*p<=MAXP;p+=w[cur++&7]) if (!criba[p]) 
		for(int j=p*p;j<=MAXP;j+=(p<<1)) if(!criba[j]) criba[j]=p;
}

vector<int> primos;
void buscarprimos(){
	crearcriba();
	forr (i,2,MAXP+1) if (!criba[i]) primos.push_back(i);
}


//factoriza bien numeros hasta MAXP^2
map<ll,ll> fact(ll n){ //O (cant primos)
	map<ll,ll> ret;
	forall(p, primos){
		while(!(n%*p)){
			ret[*p]++;//divisor found
			n/=*p;
		}
	}
	if(n>1) ret[n]++;
	return ret;
}

//factoriza bien numeros hasta MAXP
map<ll,ll> fact2(ll n){ //O (lg n)
	map<ll,ll> ret;
	while (criba[n]){
		ret[criba[n]]++;
		n/=criba[n];
	}
	if(n>1) ret[n]++;
	return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    ll M, N, K;

    cin >> M >> N >> K;

    ll n[1000];
    
    forn(i, N) {
        cin >> n[i];
    }

    ll E[1000][MAXN];
    map<ll,ll> D[10000];
    map<ll,ll> facts, facts2;
    map<ll,ll>::iterator it;
    ll e;
    vector<ll> m;
    vector<ll>::iterator mit;

    forn(i, K) {
        forn(j, MAXN) {  
            cin >> E[i][j];
        }
        e = E[i][1] = n[E[i][1] - 1];
        if(e >= MAXP)
            facts = fact(e);
        else
            facts = fact2(e);
        D[i] = facts;
    }

    int t = 0;

    forn(i, K ) {
        facts = D[i];
        for(it = facts.begin(); it != facts.end(); ++it) {
            cout << it->fst << tab << it-> snd << tab << E[i][1] << endl;
            if(E[i][2] == it->first) {
                t = 1;
                forr(k, i + 1, K) {
                    
                    if(E[k][0] == E[i][0] && ((D[k].find(it->snd)->fst)) != E[k][2])
                        t = 0;
                }
            }
            if(t == 1)
                m.pb(it->snd);
        }
    }

    sort(m.begin(), m.end());

    for(mit = m.begin(); mit != m.end(); mit++) {
        cout << *mit << " ";
    }
    cout << endl;

	return 0;
}
