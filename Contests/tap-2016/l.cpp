#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=a;i<b;i++) 
#define forn(i,n) forr(i,0,n)
#define zero(v) memset(v,0,sizeof(v))
#define sz(c) ((int)c.size())
#define fst first
#define snd second
#define pb push_back
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define dprint(v) cout << #v " = " << v << endl
#define endl "\n"
#define MOD 1000000007
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

bool comp(int a, int b){
	return a > b;
}
//Bajaste 1 ant
int calificador(int ANT, int NEW){	
	int ANS;
	if(NEW==ANT-1)
		ANS=1;
	if(NEW==ANT-2)
		ANS=2;
	if(NEW==ANT+1)
		ANS=3;
	if(NEW==ANT+2)
		ANS=4;
	return ANS;
}

bool B1(int ANT, int NEW){
	return NEW==ANT-1 || NEW==ANT-2;
}

bool B2(int ANT, int NEW){
	return NEW==ANT-1 || NEW==ANT-2;
}

bool S1(int ANT, int NEW)
{
	return NEW==ANT-2 || NEW==ANT+1 || NEW==ANT+2;
}

bool S2(int ANT, int NEW)
{
	return NEW==ANT-1 || NEW==ANT+1 || NEW==ANT+2;
}
// 1=B1 2=B2 3=S1 4=S2
int main(){ 	
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int N,K;
	cin>>N>>K;
	int C[K];
	cin>>C[0];
	cin>>C[1];
	int IDANT = calificador(C[0],C[1]);
	bool seguimo=1;
	int i;
	if(C[1]!=1 && C[1]!=2 && C[0]!=C[1]){
		for(i = 2; i<K && seguimo; i++){
			cin>>C[i];
			if(C[i]==1 || C[i]==2)
				if(i < K-1)
					break;
			if(C[i-1]==C[i])
				break;
			if(IDANT==1)
				seguimo=B1(C[i-1],C[i]);
			else if(IDANT==2)
				seguimo=B2(C[i-1],C[i]);
			else if(IDANT==3)
				seguimo=S1(C[i-1],C[i]);
			else if(IDANT==4)
				seguimo=S2(C[i-1],C[i]);
			IDANT=calificador(C[i-1],C[i]);
		}
	}
	if ( i < K )
		cout << "N" << endl;
	else if (seguimo)
		cout << "S" << endl;
	else
		cout<<"N"<<endl;
	return 0;
}
