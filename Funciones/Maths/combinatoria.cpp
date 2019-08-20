const int MAXN = 200;

#define MOD 1000000007;

//Luego de llamar a combinatoria(), comb queda: (MÓDULO 10^9 +7)
//comb[i][k]= i tomados de a k
long long comb[MAXN+1][MAXN+2];

/* combinatoria : Void
 * Genera el triangulo de pascal hasta la fila MAXN
 * Como a partir de la fila ~60 los valores no entran en un long long
 * se guarda la información módulo 10^9+7
 * SE LLAMA UNA SOLA VEZ esta función
 */
void combinatoria(){
	forn(i, MAXN+1){ //comb[i][k]=i tomados de a k
		comb[i][0]=comb[i][i]=1;
		forr(k, 1, i) 
			comb[i][k]=(comb[i-1][k]+comb[i-1][k-1])%MOD;
	}
}

void outputTrianguloPascal(){
	forn(i, MAXN+1){
		cout << "FILA: " << i << endl;
		forn(k, i){
			cout << comb[i][k] << "\t";
		}
		cout << endl;
	}
}

int main(){
	combinatoria();
	outputTrianguloPascal();
	return 0;
}

