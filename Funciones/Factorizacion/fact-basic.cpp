vector<ll> factorize(ll m){
  if(m==1) return{};
  vector<ll> fact;
  for(ll a=2; a*a<=m; a++){
    while(m%a==0){
      fact.push_back(a);
      m/=a;
    }
  }
  if(m!=1) fact.push_back(m);
  return fact;
}

