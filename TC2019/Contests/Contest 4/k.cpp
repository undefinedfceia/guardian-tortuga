#include <bits/stdc++.h>
using namespace std;
#define dprint(v) cerr << #v"=" << v << endl //;)
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define pb push_back
#define fst first
#define snd second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;

struct Mat {
    vector<vector<double> > vec;
    Mat(int n): vec(n, vector<double>(n) ) {}
    Mat(int n, int m): vec(n, vector<double>(m) ) {}
    vector<double> &operator[](int f){return vec[f];}
    const vector<double> &operator[](int f) const {return vec[f];}
    int size() const {return sz(vec);}
    Mat operator+(Mat &b) { ///this de n x m entonces b de n x m
        Mat m(sz(b),sz(b[0]));
        forn(i,sz(vec)) forn(j,sz(vec[0])) m[i][j] = vec[i][j] + b[i][j];
        return m;    }
    Mat operator*(const Mat &b) { ///this de n x m entonces b de m x t
        int n = sz(vec), m = sz(vec[0]), t = sz(b[0]);
        Mat mat(n,t);
        forn(i,n) forn(j,t) forn(k,m) mat[i][j] += vec[i][k] * b[k][j];
        return mat;    }
    double determinant(){//sacado de e maxx ru
        double det = 1;
        int n = sz(vec);
        Mat m(*this);
        forn(i, n){//para cada columna
            int k = i;
            forr(j, i+1, n)//busco la fila con mayor val abs
                if(abs(m[j][i])>abs(m[k][i])) k = j;
            if(abs(m[k][i])<1e-9) return 0;
            m[i].swap(m[k]);//la swapeo
            if(i!=k) det = -det;
            det *= m[i][i];
            forr(j, i+1, n) m[i][j] /= m[i][i];
            //hago 0 todas las otras filas
            forn(j, n) if (j!= i && abs(m[j][i])>1e-9)
                forr(k, i+1, n) m[j][k]-=m[i][k]*m[j][i];
        }
        return det;
    }
};

int main(){
	int N;
	cin >> N;
	forn(i, N){
		ll WX, WY, WZ, XY, ZX, YZ;
		ll V, A, r, SWYZ, SWZX, SWXY, SXYZ, WYZ, WZX, WXY, XYZ;
		cin >> WX >> WY >> WZ >> XY >> ZX >> YZ;
		Mat m(5);
		forn(i,5){
			m[i][i] = 0;
			m[0][i] = 1;
			m[i][0] = 1;
		}
		m[2][1] = m[1][2] = WX*WX;
		m[3][1] = m[1][3] = WY*WY;
		m[4][1] = m[1][4] = WZ*WZ;
		m[3][2] = m[2][3] = XY*XY;
		m[4][2] = m[2][4] = XZ*XZ;
		m[4][3] = m[3][4] = YZ*YZ;
		
		m.determinant(); //DETERMINANTE DEVUELVE DOUBLE - NO GUARDAR AL PEDO
		
		cout << fixed;
		cout << setprecision(4);
		cout << r << endl;
	}
}
