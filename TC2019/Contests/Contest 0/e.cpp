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
//#define endl "\n"

bool e[13], b[13], o[13], c[13];

void setArray(int a, string s){
	if(s == "espada") e[a] = 1;
	if(s == "basto")  b[a] = 1;
	if(s == "oro")    o[a] = 1;
	if(s == "copa")   c[a] = 1;
	return;
}

bool check33(){
	return ((e[6] && e[7]) || (b[6] && b[7]) || (o[6] && o[7]) || (c[6] && c[7]));
}

bool checkNumber(int x){
	return(e[x] || b[x] || o[x] || c[x]);
}

int getEnvidoPalo(bool* a){
	int r = 0, count = 0;
	for(int i = 7; i > 0; i--){
		if(count==2)break;
		if(*(a+i)){
			count++;
			r+=i;
		}
	}
	for(int i = 12; i > 9; i--){
		if(count==2)break;
		if(*(a+i)){
			count++;
		}
	}
	if(count==2) r += 20;
	return r;
}

int getEnvido(){
	return max(getEnvidoPalo(e), max(getEnvidoPalo(b), max(getEnvidoPalo(o), getEnvidoPalo(c))));
}	

int maxCard(){
	dforn(i,6){
		if(e[i] || b[i] || o[i] || c[i])
			return i;
	}
	return 0;
}

int bruteForce(int n1, int n2, int n3, string s1, string s2, string s3){
	string palos[] = {"espada","basto","oro","copa"};
	zero(e);zero(b);zero(o);zero(c);
	setArray(n2,s2);setArray(n3,s3);
	int maxEnvido = 0, newEnvido;
	forn(i,4){
		forr(j,1,13){
			if(!(palos[i] == s2 && j==n2) && !(palos[i] == s3 && j==n3) && j!= 8 && j!=9){
				setArray(j,palos[i]);
				newEnvido = getEnvido();
				if(newEnvido > maxEnvido){
					maxEnvido = newEnvido;
				}
			}
			zero(e);zero(b);zero(o);zero(c);
			setArray(n2,s2);setArray(n3,s3);
		}
	}
	zero(e);zero(b);zero(o);zero(c);
	setArray(n1,s1);setArray(n2,s2);setArray(n3,s3);
	forn(i,4){
		forr(j,1,13){
			if(!(palos[i] == s1 && j==n1) && !(palos[i] == s3 && j==n3) && j!= 8 && j!=9){
				setArray(j,palos[i]);
				newEnvido = getEnvido();
				if(newEnvido > maxEnvido){
					maxEnvido = newEnvido;
				}
			}
			zero(e);zero(b);zero(o);zero(c);
			setArray(n1,s1);setArray(n3,s3);
		}
	}
	zero(e);zero(b);zero(o);zero(c);
	setArray(n1,s1);setArray(n2,s2);setArray(n3,s3);	
	forn(i,4){
		forr(j,1,13){
			if(!(palos[i] == s2 && j==n2) && !(palos[i] == s1 && j==n1) && j!= 8 && j!=9){
				setArray(j,palos[i]);
				newEnvido = getEnvido();
				if(newEnvido > maxEnvido){
					maxEnvido = newEnvido;
				}
			}
			zero(e);zero(b);zero(o);zero(c);
			setArray(n1,s1);setArray(n2,s2);
		}
	}
	return maxEnvido;
}
int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(nullptr);
    int n1,n2,n3,oldEnvido;
    string s1,s2,s3;
    while(cin >> n1 >> s1 >> n2 >> s2 >> n3 >> s3, n1 != -1){
		zero(e);zero(b);zero(o);zero(c);
		setArray(n1,s1);setArray(n2,s2);setArray(n3,s3);
		oldEnvido = getEnvido();
		if(check33()){
			cout << 0 << endl;
			continue;
		}
		if(checkNumber(6) || checkNumber(7)){
			cout << (33-oldEnvido) << endl;
			continue;
		}
		cout << (maxCard()+7+20)-oldEnvido << endl;
		//cout << bruteForce(n1,n2,n3,s1,s2,s3) - oldEnvido << endl;
	}
    return 0;
}

//Cantidad de puntos mas alto a conseguir: 33 (6+7) (esto si tengo un 6 o un 7)
//Segunda cantidad de puntos a conseguir: el nro mas alto + 7

//33 - (7-6) 0
//32 - (7+5) 1
//(31) - (6+5) (7-4) 2
//30 (7-3) (6-4) 3
//29 (7-2) (6-3) (5-4) 4
//28 (7-1) (6-2) (5-3)


