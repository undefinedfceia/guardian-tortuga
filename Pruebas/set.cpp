#include <bits/stdc++.h>

#define forr(i, a, b) for(int i = 0; i < b; i++)
#define forn(i, n) forr(i, 0, n)
#define zero(v) memset(v, 0, sizeof(v))

using namespace std;

bool comp(int a, int b){
	return a < b;
}

template <class T> struct compPropia : binary_function <T,T,bool> {
  bool operator() (const T& x, const T& y) const {return x<y;}
};

int main(){
	set <int, compPropia <int> > a; 
	a.insert(20);
	a.insert(2);
	a.insert(20);
	a.insert(1);
	set <int, greater <int> > :: iterator itr; 
	cout << "\nThe set gquiz1 is : "; 
    for (itr = a.begin(); itr != a.end(); ++itr) 
    { 
        cout << '\t' << *itr; 
    } 
    cout << endl; 
    cout << endl; 
	return 0;
}
