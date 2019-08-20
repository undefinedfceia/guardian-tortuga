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
 
bool getA(string s){
	int count=0;
	if( (s.find("*") != string::npos)){
		count++;
		count += ((s.find("*", s.find("*")+1) != string::npos)) ? 1 : 0;
	}
	return count > 1;
}
 
bool get1A(string s){
	int count=0;
	if( (s.find("*") != string::npos)){
		count++;
		count += ((s.find("*", s.find("*")+1) != string::npos)) ? 1 : 0;
	}
	return count == 1;
}
 
bool comp(int a, int b){
	return a >= b;
}
int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    string s;
    int rows = 0;
    int cols = 0;
    int c=0,r=0;
    forn(i,n){
		cin >> s;
		if(getA(s)){
			rows++;
			r = i;
		}
		if(rows == 2)
			break;
		if(get1A(s)){
			forn(j,m){
				if(s[j] == '*'){
					if(cols >= 1 && c!=j)
						cols++, r=i;
					if(cols==0)
						cols++,c=j;
				}
			}
		}
	}
	if(rows == 0 && cols <= 2){
		cout << "YES" << endl;
		cout << r+1 << " " << c+1 << endl;
		return 0;
	}
	if(rows >= 2 || cols >= 2){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	cout << r+1 << " " << c+1 << endl;
    return 0;
}

// Se rompe en 3 2 *. .* .*
