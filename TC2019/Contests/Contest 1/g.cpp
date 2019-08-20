#include <bits/stdc++.h>

#define forr(i,a,b) for(int i=a; i < b; i++)
#define forn(i,n) forr(i,0,n)

using namespace std;

int main(){
	long long n,s, count = 0;
	cin >> n >> s;
	if(n==1){
		cout << s << endl;
		return 0;
	}
	if(n==2){
		if(s%2 == 0)
			cout << s/2 << endl;
		else
			cout << (s/2)+1 << endl;
		return 0;
	}
	while(s > 0 && n > 0){
		if(s-n*(s/n) >= 0){
			count = count + (s/n);
			s = s-n*(s/n);
			n = s;
		}else{
			n = s;
		}
	}
	cout << count << endl;
	return 0;
}
