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
