#include<bits/stdc++.h>
typedef long long ll;
const int MAXN = 1000000000;

using namespace std;

//algoritmo para determinar si m es primo
bool is_prime(int m){
  for(int a=2; a*a<=m; a++){
    if(m%a==0)
      return false;
  }
  return true;
}

vector<ll> factorize(ll m){
  if(m==1) return{};
  vector<ll> fact;
  for(ll a=2; a*a<=m; a++){
    while(m%a==0){
      //assert(is_prime(a)); (agrega en log m)
      fact.push_back(a);
      m/=a;
    }
  }
  if(m!=1) fact.push_back(m);
  return fact;
}

bool criba[MAXN];
ll criba2[MAXN];

void fill_criba(){
  memset(criba, -1, sizeof(criba));;
  criba[0]=false;
  criba[1]=false;
  for(int i=2; i<MAXN; i++){
    if(criba[i]){
      for(int j=2*i; j<MAXN; j+=i)
        criba[j]=false;
    }
  }
}

//criba2 hace lo mismo que criba pero cuando es primo -1 y si no vale 
//menor multiplo primo 
void fill_criba2(){
  memset(criba2, -1, sizeof(criba2));
  criba2[0] = 0;
  criba2[1] = 1;
  for(int i=2;i<MAXN;i++){
    if(criba2==-1){
      for(int j=i;j<MAXN;j+=i)
        criba2[j]=i;
    }
  }
}

vector<ll> factorize_criba2(ll m){
  vector<ll> fact2;
  ll pos = m;
  while(pos != 1){
    fact2.push_back(criba2[pos]);
    pos/= criba2[pos];
  }
  sort(fact.begin(, facr.end()));
  return fact;  
}

ll gcd(ll a, ll b){
  if(b<a) swap(a,b);
  if(a==0) return b;
  else{
    return gcd(b%a,a);
  }
}

ll mcm(ll a, ll b){
  return (a/gcd(a,b))*b;
}

vector<ll> all_divisors(ll m){
  vector<ll> divs;
  for(ll a=1; a*a<=m;a++){
    if(m%a==0){
      
    }
  }
}

int main(){
  ll m;
  scanf("%lld", &m);
  if(is_prime(m)) puts("ES PRIMO");
  else puts("NO ES PRIMO");
  
  
  
  return 0;
}
