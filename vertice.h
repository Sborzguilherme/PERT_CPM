#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>

using namespace std;

class Vertice
{
private:
    int id;
    int duracao;
    int early_start;
    int late_start;
    int early_final;
    int late_final;
    int folga;

public:
    Vertice();
    int getId() const;
    void setId(int &value);
    int getDuracao() const;
    void setDuracao(int value);
    int getEarly_start() const;
    void setEarly_start(int value);
    int getLate_start() const;
    void setLate_start(int value);
    int getEarly_final() const;
    void setEarly_final(int value);
    int getLate_final() const;
    void setLate_final(int value);
    int getFolga() const;
    void setFolga(int value);
};

#endif // VERTICE_H
