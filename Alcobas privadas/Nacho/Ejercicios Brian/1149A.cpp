#include <bits/stdc++.h>
using namespace std;
#define forr(i, a, b) for(ll i = a; i<b; i++)
#define forn(i, n) forr(i,0,n)
#define zero(v) memset(v,0,sizeof(v))
#define sz(c) ((int)c.size())
#define pb push_back
#define fst first
#define snd second
#define dforn(i,n) for(int i=n; i > -1; i--)
#define dprint(v) cout << #v"=" << v << endl
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;

const int MAXN = 501000;
int criba[MAXN+1];

void crearcriba(){
	int w[] = {4,2,4,2,4,6,2,6};
	for(int p=25;p<=MAXN;p+=10) criba[p]=5;
	for(int p=9;p<=MAXN;p+=6) criba[p]=3;
	for(int p=4;p<=MAXN;p+=2) criba[p]=2;
	for(int p=7,cur=0;p*p<MAXN;p+=w[cur++&7]) if(!criba[p])
		for(int j=p*p;j<=MAXN;j+=(p<<1)) if(!criba[j]) criba[j]=p;
}

vector<int> primos;

void buscarprimos(){
	crearcriba();
	forr(i,2,MAXN+1) if(!criba[i]) primos.push_back(i);
}

int main(){
	ios::sync_with_stdio(0);
	buscarprimos();
	int n, c1=0, c2=0, a;
	cin >> n;
	int s[n];
	forn(i,n){
		cin >> a;
		c1 += a == 1; c2 += a == 2;
	}
	s[0] = (c2 > 0) ? 2 : 1;
	if(c2 > 0) c2--;
	int sum = s[0];
	int j = 1;
	int nextPrime = 2;
	while(j < n){
		if(sum >= nextPrime){
			nextPrime = *upper_bound(primos.begin(),primos.end(), sum);
		}
		if((sum + 2) <= nextPrime && c2>0){
			s[j] = 2;
			sum += 2;
			c2--;
			j++;
			continue;
		}
		if((sum + 1) <= nextPrime && c1>0){
			s [j] = 1;
			sum += 1;
			c1--;
			j++;
			continue;
		}
		if(c1 == 0 && c2 > 0){
			s [j] = 2;
			sum += 2;
			c2--;
			j++;
			continue;
		}
		if(c2 == 0 && c1 > 0){
			s[j] = 1;
			sum += 1;
			c1--;
			j++;
			continue;
		}
	}
	forn(i,n)
		cout << s[i] << " ";
	cout << endl;
	return 0;
}
