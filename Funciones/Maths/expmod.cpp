ll expmod(ll b, ll e, ll m){
	b%=m;
	if(!e) return 1;
	ll q = expmod(b, e/2, m); q = (q*q) % m;
	return e%2 ? (b*q) % m : q;
}
