#include "vertice.h"


int Vertice::getDuracao() const
{
    return duracao;
}

void Vertice::setDuracao(int value)
{
    duracao = value;
}

int Vertice::getId() const
{
    return id;
}

void Vertice::setId(int &value)
{
    id = value;
}

int Vertice::getEarly_start() const
{
    return early_start;
}

void Vertice::setEarly_start(int value)
{
    early_start = value;
}

int Vertice::getLate_start() const
{
    return late_start;
}

void Vertice::setLate_start(int value)
{
    late_start = value;
}

int Vertice::getEarly_final() const
{
    return early_final;
}

void Vertice::setEarly_final(int value)
{
    early_final = value;
}

int Vertice::getLate_final() const
{
    return late_final;
}

void Vertice::setLate_final(int value)
{
    late_final = value;
}

int Vertice::getFolga() const
{
    return folga;
}

void Vertice::setFolga(int value)
{
    folga = value;
}

Vertice::Vertice()
{

}
