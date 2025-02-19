#include <iostream>
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

///////////////////////////////////////////////////////////////////////////
/*==============funçoes para implementar as funcionalidades==============*/
///////////////////////////////////////////////////////////////////////////

void cadastrar_city()
{
    cout << "Funionalidade em construcao" << endl;
}

void cadastrar_road(){
    cout << "Funionalidade em construcao" << endl;
}

void centro_poke(){
    cout << "Funionalidade em construcao" << endl;
}

void cadastrar_poke(){
    cout << "Funionalidade em construcao" << endl;
}

void remover_poke(){
    cout << "Funionalidade em construcao" << endl;
}

void listar_poke_nome(){
    cout << "Funionalidade em construcao" << endl;
}

void listar_poke_tipo(){
    cout << "Funionalidade em construcao" << endl;
}

void contar_poke_tipo(){
    cout << "Funionalidade em construcao" << endl;
}

void find_near_poke(){
    cout << "Funionalidade em construcao" << endl;
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
                centro_poke();
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