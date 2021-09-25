#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
	string linea;
	string entero;
	ifstream archivo("grafo_p.txt", ios::in);

	if (!archivo) {
		cout << "no se pudo abrir el archivo grafo_p.txt" << endl;
		exit(1);
	}

	// luego se agregan las adyacencias salientes y entrantes:
	while (archivo >> linea) {
		stringstream s(linea);
		while (getline(s, entero, ',')) {
			int d = stoi(entero);
			cout << d << ',';
		}
		cout << endl;
	}
	return 0;
}
