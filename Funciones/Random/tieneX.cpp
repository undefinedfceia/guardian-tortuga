int tieneX(int u, int x){
	int g = u%10;
	if(u%x == 0) return 1;
	while (u > 0){
		g=u%10;
		if(u%10 == x)
			return 1;
		else
			u = (u-g)/10;
	}
	return 0;
}
