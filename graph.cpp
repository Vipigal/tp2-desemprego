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
		for (const auto &v : _conexao){
			cout<<v.first<<" ";
			for (const auto &i : v.second){
				cout<<i<<" ";
			}
			cout<<endl;
		}
}

int Grafo::greedyPair(){
	int matches{0};
	std::unordered_set<std::string> cargos_empregados;

	for(const auto &usuario : _conexao){
		for(const auto &cargo : usuario.second){
			if(cargos_empregados.count(cargo) == 0 ){
				matches++;
				cargos_empregados.insert(cargo);
				break;
			}
		}
	}
	
	return matches;
}

bool Grafo::encontrarCaminhoAumentante(const std::string& u, std::unordered_set<std::string>& visitado, std::unordered_map<std::string, std::string>& par){
	if (visitado.count(u) != 0)
		return false;
	
	visitado.insert(u);

	for (const auto& v : _conexao[u]){
		if (par[v].empty() || encontrarCaminhoAumentante(par[v], visitado, par)){
			par[v] = u;
			return true;
		}
	}

	return false;
}

int Grafo::exactPair(){
	std::unordered_map<std::string, std::string> par;
  int matches = 0;

	for (const auto& usuario : _conexao) {
		std::unordered_set<std::string> visitado;
		if (encontrarCaminhoAumentante(usuario.first, visitado, par))
			matches++;
	}
	
	return matches;

}

