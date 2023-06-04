#include <iostream>
#include "graph.hpp"
#include <chrono>

#define INF 0x3f3f3f3f

using namespace std;

int main(int argc, char const *argv[]) {
    int num_usuarios{0}, num_empregos{0}, num_qualificacoes{0};

		string usuario, cargo;
		cin>>num_usuarios>>num_empregos>>num_qualificacoes;
		Grafo* tb_usuario_emprego = new Grafo(num_usuarios);

		while(cin>>usuario>>cargo){
			tb_usuario_emprego->adicionaAresta(usuario, cargo);
		}

		// auto start = chrono::steady_clock::now();
		
		cout<<"Guloso: "<<tb_usuario_emprego->greedyPair()<<endl;
		cout<<"Exato: "<<tb_usuario_emprego->exactPair()<<endl;

		// auto end = chrono::steady_clock::now();
    // cout << "Elapsed time in milliseconds: "
    //     << chrono::duration_cast<chrono::milliseconds>(end - start).count()
    //     << " ms" << endl;


		// tb_usuario_emprego->imprimir();

    return 0;
}
