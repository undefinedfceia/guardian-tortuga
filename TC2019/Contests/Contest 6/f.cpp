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

bool getA(string s){
	int count=0;
	if( (s.find("*") != string::npos)){
		count++;
		count += ((s.find("*", s.find("*")+1) != string::npos)) ? 1 : 0;
	}
	return count > 1;
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    string s;
    set<int> row;
    set<int> col;
    int r,c,d;
    forn(i,n){
		cin >> s;
		if(getA(s)){
			row.insert(i);
			c = i;
			continue;
		}
		forn(j,m){
			if(s[j] == '*'){
				if(col.find(j) == col.end())
					r = i;
				else
					d = j;
				col.insert(j);
				
			}	
		}
	}
	if(row.size() == 0 && col.size() == 2){
		cout << "YES" << endl;
		cout << r+1 <<  " " << d+1 << endl;
		return 0;
	}
	if(row.size() > 2 || col.size() > 2){
		cout << "NO" << endl;
		return 0;
	}
	if(row.size() == 1){
		if(col.size() == 1){
			cout << *row.begin()+1 <<  " " << c+1 << endl;
		}else{
			cout << *row.begin()+1 <<  " " << c+1 << endl;
		}
	}else{
		if(col.size() == 1){
			cout << r+1 <<  " " << *col.begin()+1 << endl;
		}else{
			cout << r+1 <<  " " << c+1 << endl;
		}
	}
    return 0;
}

