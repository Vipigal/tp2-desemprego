#ifndef GRAPH_HPP
#define GRAPH_HPP

using namespace std;
#include <string>

#define vertice string
#define INF 0x3f3f3f3f

#include <queue>
#include <vector>
#include <unordered_map>

class Grafo {
private:
  int _numVertices;
  int _numArestas;
  unordered_map<string, vector<string>> _conexao;

public:
  /**
   * @brief Constrói um novo objeto Grafo
   *
   * @param numVertices Número de vértices do grafo
   */
  Grafo(int numVertices);

  /**
   * @brief Adiciona uma aresta v1-v2 no grafo.
   *
   * @param v1 identificador do vértice 1
   * @param v2 identificador do vértice 2
   */
  void adicionaAresta(vertice chave, vertice valor);

  /**
   * @brief Remove uma aresta do grafo.
   *
   * @param v1 identificador do vértice 1
   * @param v2 identificador do vértice 2
   */
  void removeAresta(vertice v1, vertice v2);

  /**
   * @brief Checa se existe uma aresta no grafo.
   *
   * @param v1 identificador do vértice 1
   * @param v2 identificador do vértice 2
   * @return true
   * @return false
   */
  bool existeAresta(vertice v1, vertice v2);

  /**
   * @brief Getter para o numero total de vértices do grafo
   *
   */
  int getNumVertices() const;

  /**
   * @brief Getter para o numero total de arestas do grafo
   *
   */
  int getNumArestas() const;

  /**
   * @brief Imprime todas as conexoes vertice-aresta do grafo.
   *
   */
  void imprimir() const;

	int greedyPair();

};

#endif // GRAPH_HPP
