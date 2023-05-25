#include <iostream>
#include <unordered_map>
#include <vector>

#define INF 0x3f3f3f3f

using namespace std;

void imprimeMap(const unordered_map<string, vector<string>> &map){
		for (auto v : map){
			cout<<v.first<<" ";
			for (auto i : v.second){
				cout<<i<<" ";
			}
			cout<<endl;
		}
}

int main(int argc, char const *argv[]) {
    int num_usuarios{0}, num_empregos{0}, num_qualificacoes{0};
		//Metodo de armazenamento será um hashMap de chave string e um vector de strings como valor {matheus: [cto, cfo], ...}
		unordered_map<string, vector<string>> tb_usuario_emprego; 
		string usuario, cargo;

		cin>>num_usuarios>>num_empregos>>num_qualificacoes;
		while(cin>>usuario>>cargo){
			tb_usuario_emprego[usuario].push_back(cargo);
		}

		imprimeMap(tb_usuario_emprego);

    return 0;
}
