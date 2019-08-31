#include <bits/stdc++.h>
#include <unistd.h>

unsigned int microseconds;
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	vector<int> v;
	//Insertar
	int a  = 5;
	v.push_back(a); //guarda en la ultima posición, en este caso, 0.
	v.push_back(6); //guarda en la ultima posición, en este caso, 1.
	v.push_back(7); //guarda en la ultima posición, en este caso, 2.
	v.push_back(8); //guarda en la ultima posición, en este caso, 3.
	v.push_back(9); //guarda en la ultima posición, en este caso, 4.
	
	//Obtener
	cout << v[0] << endl;
	
	//Recorrer
	
	//Forma exclusiva para vectores
	for(unsigned int i = 0; i < v.size(); i++){
		cout << v[i] << endl;
	}
	
	//Forma generica para estructuras de la STL
	vector<int>::iterator it;
	
	for(it = v.begin(); it != v.end(); it++){
		cout << *it << endl;
	}
	//
	return 0;
}
