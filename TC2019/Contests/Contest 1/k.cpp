#include <bits/stdc++.h>

#define forr(i,a,b) for(int i=a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define endl "\n"

using namespace std;
	
int rec(int *a, int *b, int n, int k){
	forn(i,n){
		b[i+1] = a[b[i+1]];
	}
	bool r = true;
	forn(i,n){
		r = r && b[i+1] == b[b[i+1]];
	}
	k++;
	if(r){
		cout << "*********" << endl;
		forn(i,n){
			cout << b[b[i+1]] << " ";
		}
		return k;
	}
		
	else
		return rec(a,b,n,k);
}

int main(){
	int a[220];
	int b[220];
	int n;
	ios::sync_with_stdio(0);
    cin.tie(nullptr);
	cin >> n;
	forn(i,n){
		cin >> a[i+1];
		b[i+1] = a[i+1];
	}
	bool r = true;
	forn(i,n){
		r = r && a[i+1] == a[a[i+1]];
	}
	if(r){
		forn(i,n){
			cout << a[a[i+1]] << " ";
		}
		cout << 1 << endl;	
		return 0;
	}
	cout << rec(a,b,n,1) << endl;
	return 0;
}
