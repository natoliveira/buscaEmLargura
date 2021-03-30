
#include <iostream>
#include <list>
#include <queue> // fila

using namespace std;

class Grafo
{
    int P;
    list<int> *adj;

public:
    explicit Grafo(int P);
    void adicionarAresta(int p1, int p2);


    void bfs(int p);
};

Grafo::Grafo(int P)
{
    this->p = P;
    adj = new list<int>[P];
}

void Grafo::adicionarAresta(int p1, int p2)
{
    adj[p1].push_back(p2);
}

void Grafo::bfs(int p)
{
    queue<int> fila;
    bool visitados[P];

    for(int i = 0; i < P; i++)
        visitados[i] = false;

    cout << "Visitando vertice " << p << " ...\n";
    visitados[p] = true;

    while(true)
    {
        list<int>::iterator it;
        for(it = adj[p].begin(); it != adj[p].end(); it++)
        {
            if(!visitados[*it])
            {
                cout << "Visitando vertice " << *it << " ...\n";
                visitados[*it] = true;
                fila.push(*it);
            }
        }

        if(!fila.empty())
        {
            p = fila.front();
            fila.pop();
        }
        else
            break;
    }
}

int main()
{
    int P = 12;

    Grafo grafo(P);


    grafo.adicionarAresta(1, 2);
    grafo.adicionarAresta(1, 7);
    grafo.adicionarAresta(1, 8);
    grafo.adicionarAresta(2, 6);
    grafo.adicionarAresta(2, 3);
    grafo.adicionarAresta(3, 4);
    grafo.adicionarAresta(3, 5);
    grafo.adicionarAresta(8, 9);
    grafo.adicionarAresta(8, 12);
    grafo.adicionarAresta(9, 10);
    grafo.adicionarAresta(9, 11);

    grafo.bfs(1);

    return 0;
