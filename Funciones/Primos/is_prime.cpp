bool is_prime(int m){
  for(int a=2; a*a<=m; a++){
    if(m%a==0)
      return false;
  }
  return true;
}