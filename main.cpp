#include <iostream>
#include <locale.h> // Possibilitar a acentuação.

using namespace std;

#define cidade (11) // quantidade de cidades
int grafo[cidade][cidade];

struct town
{
    string nome;
    bool centro_poke;
    int codigo_cidade;
};

// void pra interface de interação com o usuário
void cadastrar_city()
{

    // grafo pro cadastro das cidades
    int caminho, origem, destino;
    for (int i = 0; i < cidade; i++)
    {
        for (int j = 0; j < cidade; j++)
        {
            grafo[i][j] = -1;
        }
    }
    /*
    cidade 1 = Indiro Plateau
    cidade 2 = Viridian City
    cidade 3 = pallet town
    cidade 4 = cinnabar island
    cidade 5 = fuschia city
    cidade 6 = vermillion city
    cidade 7 = lavender town
    cidade 8 = saffron cty
    cidade 9 = celadon city
    cidade 10 = cerulean city
    ciadade 11 = pewter city

    */
    // ponderando o grafo beleza
    grafo[0][1] = 45;
    grafo[1][0] = 45;
    grafo[2][1] = 1;
    grafo[1][2] = 1;
    grafo[3][2] = 21;
    grafo[2][3] = 21;
    grafo[4][3] = 49;
    grafo[3][4] = 49;
    grafo[5][4] = 53;
    grafo[4][5] = 53;
    grafo[6][4] = 54;
    grafo[4][6] = 54;
    grafo[6][5] = 23;
    grafo[5][6] = 23;
    grafo[7][5] = 6;
    grafo[5][7] = 6;
    grafo[6][7] = 8;
    grafo[7][6] = 8;
    grafo[6][9] = 10;
    grafo[9][6] = 10;
    grafo[7][8] = 7;
    grafo[8][7] = 7;
    grafo[8][4] = 51;
    grafo[4][8] = 51;
    grafo[9][7] = 5;
    grafo[7][9] = 5;
    grafo[10][1] = 2;
    grafo[1][10] = 2;
    grafo[10][9] = 7;
    grafo[9][10] = 7;

    town cadastro[10]; // struct para cadastro de cidades

    int i = 0;
    for (i; i < 11; i++)
    {
        cout << "Digite o nome da cidade: " << endl;
        cin >> cadastro[i].nome;
        cout << "\n";

        cout << "Digite o codigo da cidade: " << endl;
        cin >> cadastro[i].codigo_cidade;
        cout << "\n";

        cout << "Essa cidade tem um centro pokemon? (1 para sim e 0 para não)" << endl;
        cin >> cadastro[i].centro_poke;
        cout << "\n";
    }
    
    
    int distancia =-1;
    int posicao_centro = -1;
    
    for(j=0; j<11; j++){
        if(grafo["centro"][j]!=-1){
            if(grafo["centro"][j]<=distancia)
            distancia = grafo["centro"][j];
            posicao_centro = j;
        }
    }
    cout << "A cidade mais proxima do centro pokemon é: " << cadastro[posicao_centro].nome << " e a distancia é de: " << distancia << "km" << endl;
    
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
    cout << "s. Encerrar pokedex; \n"
         << endl;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

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
            cout << "Programa encerrado. \n"
                 << endl;
            return 0;
        }
        }
    }

    return 0;
}