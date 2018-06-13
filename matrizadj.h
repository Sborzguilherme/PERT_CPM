#ifndef MATRIZADJ_H
#define MATRIZADJ_H

#include <iostream>

using namespace std;

class Matrizadj
{
private:
    int n_vertices;
    int **matriz;

public:
    Matrizadj();
    int getN_vertices() const;
    void setN_vertices(int value);
    int **getMatriz() const;
    void setMatriz(int **value);

    void inicializa_matriz();
    void add_vertice(int origem, int destino, int valor);
    void print_matriz();

};

#endif // MATRIZADJ_H
