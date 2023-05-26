#include <iostream>
#include "graph.hpp"

#define INF 0x3f3f3f3f

using namespace std;

int main(int argc, char const *argv[]) {
    int num_usuarios{0}, num_empregos{0}, num_qualificacoes{0};
		//Metodo de armazenamento será um grafo modelado como hashMap de chave string e um vector de strings como valor {matheus: [cto, cfo], ...}
		string usuario, cargo;
		cin>>num_usuarios>>num_empregos>>num_qualificacoes;
		Grafo* tb_usuario_emprego = new Grafo(num_usuarios);

		while(cin>>usuario>>cargo){
			tb_usuario_emprego->adicionaAresta(usuario, cargo);
		}

		cout<<"Guloso: "<<tb_usuario_emprego->greedyPair();
		// cout<<"Exato: "<<tb_usuario_emprego->exactPair();

		tb_usuario_emprego->imprimir();

    return 0;
}
