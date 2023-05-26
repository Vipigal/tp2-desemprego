#include "graph.hpp"
#include <iostream>

using namespace std;

Grafo::Grafo(int numVertices){
  _numVertices = numVertices;
	_numArestas = 0;
}

void Grafo::adicionaAresta(vertice chave, vertice valor){ //O(1)
	_conexao[chave].push_back(valor);
	_numArestas++;
}

void Grafo::removeAresta(vertice chave, vertice valor){ //O(n)
	for(vector<string>::iterator it = _conexao[chave].begin(); it!=_conexao[chave].end();it++){
		if(*it==valor){
			_conexao[chave].erase(it);
			_numArestas--;
		}
	}

}

bool Grafo::existeAresta(vertice chave, vertice valor){ //O(n)
	for(vector<string>::iterator it = _conexao[chave].begin(); it!=_conexao[chave].end();it++){
		if(*it==valor){
			return true;
		}
	}
	return false;
}

int Grafo::getNumVertices() const{
	return _numVertices;
}
int Grafo::getNumArestas() const{
	return _numArestas;
}


void Grafo::imprimir() const{
		for (auto v : _conexao){
			cout<<v.first<<" ";
			for (auto i : v.second){
				cout<<i<<" ";
			}
			cout<<endl;
		}
}

int Grafo::greedyPair(){

}