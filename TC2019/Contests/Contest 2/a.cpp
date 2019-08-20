#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define pb push_bac
#define fst first
#define snd second
typedef long long ll;
typedef pair<int,int> ii;
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define dprint(v) cout << #v"=" << v << endl
#define endl "\n"

const int MAXN=100100;
const int s = 1000000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    char s[220];
    cin >> s;
    forn(i, (int)(220-2)){
		if(s[i] == 'W' &&  s[i+1] == 'U' && s[i+2] == 'B')
			s[i]=s[i+1]=s[i+2] = ' ';
	}
	char * v = strtok(s," ");
	while(v != NULL){
		cout << v << " ";
		v = strtok(NULL, " ");
	}
	cout << endl;
    return 0;
}

