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

bool hasName(string s){
	int count = 0;
	string names[] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
	forn(i,5){
		if( (s.find(names[i]) != string::npos)){
			count++;
			count += ((s.find(names[i], s.find(names[i])+names[i].length()) != string::npos)) ? 1 : 0;
		}
	}
	return count == 1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    string s;
    cin >> s;
	if(hasName(s))
		cout << "YES" << endl; 
	else
		cout << "NO" << endl; 
    return 0;
}
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaDanil
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaOlyaSlava
