#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void crearArchivo() {
    ofstream archivo("Data/registros.txt");
    if (archivo.is_open()) {
        cout << "Archivo creado exitosamente en la carpeta Data." << endl;
        archivo.close();
    } else {
        cerr << "Error al crear el archivo." << endl;
    }
}

void llenarArchivo(int N) {
    ofstream archivo("Data/registros.txt", ios::app);  // Abrir en modo de anexado
    if (archivo.is_open()) {
        for (int i = 0; i < N; ++i) {
            string nombre, cedula, correo;
            cout << "Ingrese nombre: ";
            cin >> nombre;
            cout << "Ingrese cedula: ";
            cin >> cedula;
            cout << "Ingrese correo: ";
            cin >> correo;
            archivo << nombre << " " << cedula << " " << correo << endl;
        }
        archivo.close();
    } else {
        cerr << "Error al abrir el archivo para escribir." << endl;
    }
}

void leerArchivo() {
    ifstream archivo("Data/registros.txt");
    if (archivo.is_open()) {
        string nombre, cedula, correo;
        while (archivo >> nombre >> cedula >> correo) {
            cout << "Mi nombre es " << nombre << ", numero de cedula: " << cedula 
                 << ", mi correo es " << correo << endl;
        }
        archivo.close();
    } else {
        cerr << "Error al abrir el archivo para leer." << endl;
    }
}

int main() {
    crearArchivo();
    
    int N;
    cout << "Ingrese el numero de registros: ";
    cin >> N;
    llenarArchivo(N);
    
    leerArchivo();

    return 0;
}