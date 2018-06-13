#include <iostream>
#include <vector>
#include <fstream>

#include "matrizadj.h"
#include "vertice.h"

using namespace std;

Matrizadj abre_grafo(vector<Vertice> grafo);

int main()
{
    Matrizadj matriz_adj;
    vector<Vertice> grafo;

    matriz_adj = abre_grafo(grafo);
    matriz_adj.print_matriz();
}

const vector<string> explode(const string& s, const char& c)
{
    string buff{""};
    vector<string> v;

    for(auto n:s){
        if(n != c) buff+=n; else
        if(n == c && buff != "") { v.push_back(buff); buff = ""; }
    }
    if(buff != "") v.push_back(buff);
    return v;
}

Vertice inicializa_vertice(int nome, int duracao){
    Vertice aux;
    aux.setId(nome);
    aux.setDuracao(duracao);
    aux.setEarly_final(0);
    aux.setEarly_start(0);
    aux.setFolga(0);
    aux.setLate_final(0);
    aux.setLate_start(0);
    return aux;
}

Matrizadj abre_grafo(vector<Vertice> grafo){
    Matrizadj m_aux;
    ifstream leitura;
    char linha[20];
    vector<string> read;
    string aux, caminho;
    int atividade, duracao, precedente, atual = 0, n_vertices=0;
    Vertice vertice;

    cout<< endl << " > Informe o caminho do arquivo com o grafo:" << endl;
    cout<<"->> ";
    cin>>caminho;
    leitura.open("C:/Users/Guilherme/Documents/Univali/7 Periodo/Grafos/M3/Grafos-master/Grafos_Peso_arestas/m1.txt");
    if(!leitura.is_open( )){
        cout<< "Nao foi possivel abrir arquivo!" << endl;
        leitura.clear( );
    }
    while (leitura.getline(linha,20)) {
        n_vertices++;
    }
    m_aux.setN_vertices(n_vertices+1);
    m_aux.inicializa_matriz(); // Inicializa tudo com zero matriz adj
    leitura.close();
    leitura.open("C:/Users/Guilherme/Documents/Univali/7 Periodo/Grafos/M3/Grafos-master/Grafos_Peso_arestas/m1.txt");
    if(!leitura.is_open( )){
        cout<< "Nao foi possivel abrir arquivo!" << endl;
        leitura.clear( );
    }
    int vetor_prececdentes[n_vertices-1] = {};
    while (leitura.getline(linha,20)) {
        read = explode(linha,',');
        aux = read.front(); atividade = atoi(aux.c_str()); read.erase(read.begin()); // primeira coluna da tabela indica a atividade
        cout<<"Atual = "<<atual<<endl;
        aux = read.front(); duracao = atoi(aux.c_str()); read.erase(read.begin());
        cout<<"D = "<<duracao<<endl;
        vertice = inicializa_vertice(atividade,duracao);
        grafo.push_back(vertice);
        while(!read.empty()){
            aux = read.front(); precedente = atoi(aux.c_str()); read.erase(read.begin());
            if(precedente != 0){
                cout<<"p = "<<precedente-1<<endl;
                vetor_prececdentes[precedente-1] = -1;
                m_aux.add_vertice(precedente-1,atual,grafo.at(precedente-1).getDuracao());
            }
        }
        atual++;
    }
    for(int i=0;i<n_vertices;i++){
        if(vetor_prececdentes[i] != -1)
            m_aux.add_vertice(i,n_vertices,grafo.at(i).getDuracao());
    }
    leitura.close();
    return m_aux;
}
