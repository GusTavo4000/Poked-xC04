#include <iostream>
using namespace std;

//void pra interface 
void show_menu(){

    cout << "a. Cadastrar cidade; " << endl;
    cout << "b. Cadastrar estrada;" << endl;
    cout << "c. Buscar centro pokemon; " << endl;
    cout << "d. Cadastrar pokemon; " << endl;
    cout << "e. Remover pokmemon; " << endl;
    cout << "f. Listar pokemons;" << endl; //por ordem alfabética de nome
    cout << "g. Listar pokemon; " << endl; //por ordem alfabética de tipo
    cout << "h. Contar pokemons de cada tipo; " << endl; 
    cout << "g. Encontrar pokemons proximos; " << endl;

}

void cadastrar_city()
{
    cout << "Funionalidade em contrução" << endl;
}

void cadastrar_road(){
    cout << "Funionalidade em contrução" << endl;
}

void centro_poke(){
    cout << "Funionalidade em contrução" << endl;
}

void cadastrar_poke(){
    cout << "Funionalidade em contrução" << endl;
}

void remover_poke(){
    cout << "Funionalidade em contrução" << endl;
}

void listar_poke_nome(){
    cout << "Funionalidade em contrução" << endl;
}

void listar_poke_tipo(){
    cout << "Funionalidade em contrução" << endl;
}

void contar_poke_tipo(){
    cout << "Funionalidade em contrução" << endl;
}

void find_near_poke(){
    cout << "Funionalidade em contrução" << endl;
}


int main (){

    //declaração de variáveis
    char opcoes;
    string cidade;

    //estrutura de repetição da interface
    while(1){
        show_menu();

        cin >> opcoes;
        cin.ignore();

        switch(opcoes){     //switch case pra seleção de opções du user
            case 'a':
            {
                cadastrar_city();
                break;
            }

            // case 'b':
            // {
            //     //fgsgjsifgdirg
            // }

            // case 'c':
            // {
            //     <
            // }

            // case 's': // caso queira sair
            // {
            //     return 0;
            // }

        }


    }








    return 0;
}
