int GCD(int n, int d[]){
	int a = __gcd(d[0], d[1]);
	forr(i, 1, n-1){
		if(__gcd(d[i], d[i+1]) < a)
			a = __gcd(d[i], d[i+1]);
	}
	return a;
}
