#include <iostream>
#include <locale.h> // Possibilitar a acentuação.

using namespace std;


#define cidade (11) // quantidade de cidades
int grafo[cidade][cidade];

// void pra interface de interação com o usuário
void cadastrar_city()
{   
    
    //grafo pro cadastro das cidades
    int caminho, origem, destino;
    for(int i = 0; i< cidade; i++){
        for(int j = 0; j< cidade; j++){
            grafo[i][j] = -1;
        }
    }
    grafo[1][2] = 45;
    grafo[2][1] = 45;

    
}

void cadastrar_road()
{
    cout << "Funcionalidade em construcao" << endl;
}

void buscar_centro_poke()
{
    cout << "Funcionalidade em construcao" << endl;
}

void cadastrar_poke()
{
    cout << "Funcionalidade em construcao" << endl;
}
void remover_poke()
{
    cout << "Funcionalidade em construcao" << endl;
}

void listar_poke_nome()
{
    cout << "Funcionalidade em construcao" << endl;
}

void listar_poke_tipo()
{
    cout << "Funcionalidade em construcao" << endl;
}

void contar_poke_tipo()
{
    cout << "Funcionalidade em construcao" << endl;
}

void find_near_poke()
{
    cout << "Funcionalidade em construcao" << endl;
}

void show_menu()
{
    
    cout << "\nOla cacador de pokemons, o que gostaria de acessar? " << endl;
    cout << "\na. Cadastrar cidade; " << endl;
    cout << "b. Cadastrar estrada; " << endl;
    cout << "c. Buscar centro pokemon; " << endl;
    cout << "d. Cadastrar pokemon; " << endl;
    cout << "e. Remover pokmemon; " << endl;
    cout << "f. Listar pokemons; " << endl; // por ordem alfabética de nome
    cout << "g. Listar pokemon; " << endl;  // por ordem alfabética de tipo
    cout << "h. Contar pokemons de cada tipo; " << endl;
    cout << "i. Encontrar pokemons proximos; " << endl;
    cout << "s. Encerrar pokedex; \n" << endl;
}

int main()
{
    
    cadastrar_city();
    
    
    // declaração de variáveis
    char opcoes;
    
    // estrutura de repetição da interface
    while (1)
    {

        show_menu();

        cin >> opcoes;
        cout << "\n";

        switch (opcoes)
        { // switch case pra seleção de opções du user
        case 'a':
        {
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
            cout << "Programa encerrado. \n"
                 << endl;
            return 0;
        }
        }
    }

    return 0;
}