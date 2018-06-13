#include "matrizadj.h"

int Matrizadj::getN_vertices() const
{
    return n_vertices;
}

void Matrizadj::setN_vertices(int value)
{
    n_vertices = value;
}

int **Matrizadj::getMatriz() const
{
    return matriz;
}

void Matrizadj::setMatriz(int **value)
{
    matriz = value;
}

void Matrizadj::inicializa_matriz()
{
    this->matriz = new int* [this->n_vertices]; // DEve ser definido o tamanho antes
    for (int i = 0; i < this->n_vertices; i++){
        this->matriz[i] = new int [this->n_vertices];
        for(int j = 0; j < this->n_vertices; j++){
            this->matriz[i][j] = 0;
        }
    }
}

Matrizadj::Matrizadj()
{

}

void Matrizadj::add_vertice(int origem, int destino, int valor)
{
    this->matriz[origem][destino] = valor;
}

void Matrizadj::print_matriz()
{
    for(int i = 0; i < n_vertices; i++){
        cout<< endl;
        for(int j = 0; j < n_vertices; j++){
            cout<<" " << matriz[i][j];
        }
    }
}

