#include <iostream>
#include "cadastros.hpp"
#include "pokedex.hpp"

using namespace std;

//void pra interface de interação com o user
void show_menu(){

    cout << "\nOla cacador de pokemons, o que gostaria de acessar? " << endl;
    cout << "\na. Cadastrar cidade; " << endl;
    cout << "b. Cadastrar estrada; " << endl;
    cout << "c. Buscar centro pokemon; " << endl;
    cout << "d. Cadastrar pokemon; " << endl;
    cout << "e. Remover pokmemon; " << endl;
    cout << "f. Listar pokemons; " << endl; //por ordem alfabética de nome
    cout << "g. Listar pokemon; " << endl; //por ordem alfabética de tipo
    cout << "h. Contar pokemons de cada tipo; " << endl; 
    cout << "i. Encontrar pokemons proximos; " << endl;
    cout << "s. Encerrar pokedex; \n" << endl;
}

int main (){

    //declaração de variáveis
    char opcoes;

    //estrutura de repetição da interface
    while(1){
        
        show_menu();

        cin >> opcoes;
        cout << "\n";

        switch(opcoes){     //switch case pra seleção de opções du user
            case 'a':
            {
                cadastrar_city();
                break;
            }

            case 'b':
            {
                cadastrar_road();
                break;
            }

            case 'c':
            {
                buscar_centro_poke();
                break;
            }

            case 'd':
            {
                cadastrar_poke();
                break;
            }

            case 'e':
            {
                remover_poke();
                break;
            }

            case 'f':
            {
                listar_poke_nome();
                break;
            }

            case 'g':
            {
                listar_poke_tipo();
                break;
            }

            case 'h':
            {
                contar_poke_tipo();
                break;
            }

            case 'i':
            {
                find_near_poke();
                break;
            }

            case 's': // caso queira sair
            {
                cout << "Programa encerrado. \n" << endl;
                return 0;
            }

        }

    }

    return 0;
}

// ./pokedex pra rodar no powerShell aqui no VsCode já estando no
//diretorio

/*
Mas pra rodar no CMD é necessário que voce vá para o diretorio 
onde voce salvou o projeto com o comando:

cd C:\Users\Gustavo\Documents\Codigos\Poked-xC04
-------esse é o diretorio no meu caso.----------

Estando no diretorio é so colocar pokedex.exe que vai rodar.
*/