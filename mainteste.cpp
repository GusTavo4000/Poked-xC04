#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <locale.h>
using namespace std;

#define cidade 11 // quantidade de cidades
int grafo[cidade][cidade];

struct town {
    string nome;
    bool centro_poke;
    int codigo_cidade;
};

struct pokemon {
    string nome;
    string tipo;
    int codigo_poke;
    int loc_X;
    int loc_Y;
};

typedef int KeyType;
typedef int ValueType;

struct DataType {
	KeyType key;
	ValueType value;
};

struct Node {
	DataType data;
	Node * right;
	Node * left;
};

void insert(Node *& curr, DataType data){	
	if(curr == NULL){
		curr = new Node;
		curr->data = data;
		curr->right = NULL;
		curr->left = NULL;
	} else {
		if(data.key >= curr->data.key){
			insert(curr->right, data);
		} else if(data.key < curr->data.key) {
			insert(curr->left, data);
		}		
	}	
}

void show_ordered(Node * curr, pokemon pokedex[]){
	if(curr == NULL) return;
	show_ordered(curr->left, pokedex);
	int idx = curr->data.value;
	cout << "- Nome: " << pokedex[idx].nome
		 << ", Tipo: " << pokedex[idx].tipo
		 << ", Número: " << pokedex[idx].codigo_poke
		 << ", Localização: (" << pokedex[idx].loc_X << ", " << pokedex[idx].loc_Y << ")\n";
	show_ordered(curr->right, pokedex);
}

int contar_por_tipo(Node * curr, pokemon pokedex[], string tipo){
	if(curr == NULL) return 0;
	int idx = curr->data.value;
	int cont = (pokedex[idx].tipo == tipo) ? 1 : 0;
	return cont + contar_por_tipo(curr->left, pokedex, tipo) + contar_por_tipo(curr->right, pokedex, tipo);
}

int gerar_chave(string str) {
	int soma = 0;
	for (char c : str) soma += int(c);
	return soma;
}

town cadastro[10];
pokemon pokedex[100];
int total_pokemons = 0;
Node *arvore_nome = NULL;
Node *arvore_tipo = NULL;

void carregar_arvores() {
	arvore_nome = NULL;
	arvore_tipo = NULL;
	for (int i = 0; i < total_pokemons; i++) {
		insert(arvore_nome, {gerar_chave(pokedex[i].nome), i});
		insert(arvore_tipo, {gerar_chave(pokedex[i].tipo), i});
	}
}

void listar_por_nome_arvore() {
	if (total_pokemons == 0) {
		cout << "Nenhum Pokémon cadastrado.\n";
		return;
	}
	carregar_arvores();
	cout << "\nLista de Pokémons ordenados por NOME (via árvore):\n";
	show_ordered(arvore_nome, pokedex);
}

void listar_por_tipo_arvore() {
	if (total_pokemons == 0) {
		cout << "Nenhum Pokémon cadastrado.\n";
		return;
	}
	carregar_arvores();
	cout << "\nLista de Pokémons ordenados por TIPO (via árvore):\n";
	show_ordered(arvore_tipo, pokedex);
}

void contar_tipo_arvore() {
	if (total_pokemons == 0) {
		cout << "Nenhum Pokémon cadastrado.\n";
		return;
	}
	cin.ignore();
	string tipo;
	cout << "Digite o tipo de Pokémon a ser contado: ";
	getline(cin, tipo);
	carregar_arvores();
	int qtd = contar_por_tipo(arvore_tipo, pokedex, tipo);
	cout << "Quantidade de Pokémons do tipo '" << tipo << "': " << qtd << endl;
}

void cadastrar_city() {
    for (int i = 0; i < cidade; i++) {
        for (int j = 0; j < cidade; j++) {
            grafo[i][j] = 90;
        }
    }

    grafo[0][1] = 45; grafo[1][0] = 45;
    grafo[2][1] = 1;  grafo[1][2] = 1;
    grafo[3][2] = 21; grafo[2][3] = 21;
    grafo[4][3] = 49; grafo[3][4] = 49;
    grafo[5][4] = 53; grafo[4][5] = 53;
    grafo[6][4] = 54; grafo[4][6] = 54;
    grafo[6][5] = 23; grafo[5][6] = 23;
    grafo[7][5] = 6;  grafo[5][7] = 6;
    grafo[6][7] = 8;  grafo[7][6] = 8;
    grafo[6][9] = 10; grafo[9][6] = 10;
    grafo[7][8] = 7;  grafo[8][7] = 7;
    grafo[8][4] = 51; grafo[4][8] = 51;
    grafo[9][7] = 5;  grafo[7][9] = 5;
    grafo[10][1] = 2; grafo[1][10] = 2;
    grafo[10][9] = 7; grafo[9][10] = 7;

    int i = 0;
    bool quero_cadastrar = 1;
    cin.ignore();

    while (quero_cadastrar) {
        cout << "Digite o nome da cidade: ";
        getline(cin, cadastro[i].nome);
        cout << "Digite o código da cidade: ";
        cin >> cadastro[i].codigo_cidade;
        cout << "Essa cidade tem um centro Pokémon? (1 para sim, 0 para não): ";
        cin >> cadastro[i].centro_poke;
        cout << "Gostaria de cadastrar uma nova cidade? (1 para sim, 0 para não): ";
        cin >> quero_cadastrar;
        cin.ignore();
        i++;
    }
}

void buscar_centro_poke() {
    int distancia = 90;
    int posicao_centro = -1;
    int cod_cidade;
    cout << "Digite o código da cidade: ";
    cin >> cod_cidade;
    for (int j = 0; j < cidade; j++) {
        if (grafo[j][cod_cidade] != -1 && grafo[j][cod_cidade] <= distancia) {
            distancia = grafo[j][cod_cidade];
            posicao_centro = cod_cidade;
        }
    }
    cout << "A cidade mais próxima do centro Pokémon é: " << cadastro[posicao_centro].nome
         << " e a distância é de: " << distancia << " km\n";
}

void cadastrar_road() {
    cout << "Funcionalidade em construção\n";
}

void cadastrar_poke() {
    bool quero_cadastrar = 1;
    while (quero_cadastrar) {
        cin.ignore();
        cout << "Digite o nome do Pokémon: ";
        getline(cin, pokedex[total_pokemons].nome);
        cout << "Digite o tipo do Pokémon: ";
        getline(cin, pokedex[total_pokemons].tipo);
        cout << "Digite o número da Pokédex: ";
        cin >> pokedex[total_pokemons].codigo_poke;
        cout << "Digite a localização (X Y): ";
        cin >> pokedex[total_pokemons].loc_X >> pokedex[total_pokemons].loc_Y;
        total_pokemons++;
        cout << "Deseja cadastrar outro Pokémon? (1-Sim / 0-Não): ";
        cin >> quero_cadastrar;
    }
}

void remover_poke() {
    if (total_pokemons == 0) {
        cout << "Nenhum Pokémon cadastrado.\n";
        return;
    }
    cin.ignore();
    string nome;
    cout << "Digite o nome do Pokémon a ser removido: ";
    getline(cin, nome);
    bool encontrado = false;
    for (int i = 0; i < total_pokemons; i++) {
        if (pokedex[i].nome == nome) {
            for (int j = i; j < total_pokemons - 1; j++) {
                pokedex[j] = pokedex[j + 1];
            }
            total_pokemons--;
            encontrado = true;
            cout << "Pokémon '" << nome << "' removido com sucesso.\n";
            break;
        }
    }
    if (!encontrado) {
        cout << "Pokémon '" << nome << "' não encontrado.\n";
    }
}

void find_near_poke() {
    if (total_pokemons == 0) {
        cout << "Nenhum Pokémon cadastrado.\n";
        return;
    }
    float x, y;
    cout << "Digite sua localização atual (X Y): ";
    cin >> x >> y;
    int contador = 0;
    float raio_quadrado = 0.01;
    for (int i = 0; i < total_pokemons; i++) {
        float dx = pokedex[i].loc_X - x;
        float dy = pokedex[i].loc_Y - y;
        float distancia2 = dx * dx + dy * dy;
        if (distancia2 <= raio_quadrado) {
            contador++;
        }
    }
    cout << "Total de Pokémons próximos: " << contador << "\n";
}

void show_menu() {
    cout << "\nOla caçador de Pokémons, o que gostaria de acessar?\n";
    cout << "a. Cadastrar cidade\n";
    cout << "b. Cadastrar estrada\n";
    cout << "c. Buscar centro Pokémon\n";
    cout << "d. Cadastrar Pokémon\n";
    cout << "e. Remover Pokémon\n";
    cout << "f. Listar Pokémons (por nome)\n";
    cout << "g. Listar Pokémons (por tipo)\n";
    cout << "h. Contar Pokémons por tipo\n";
    cout << "i. Encontrar Pokémons próximos\n";
    cout << "s. Encerrar Pokédex\n";
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    char opcoes;
    while (true) {
        show_menu();
        cin >> opcoes;
        switch (opcoes) {
        case 'a': cadastrar_city(); break;
        case 'b': cadastrar_road(); break;
        case 'c': buscar_centro_poke(); break;
        case 'd': cadastrar_poke(); break;
        case 'e': remover_poke(); break;
        case 'f': listar_por_nome_arvore(); break;
        case 'g': listar_por_tipo_arvore(); break;
        case 'h': contar_tipo_arvore(); break;
        case 'i': find_near_poke(); break;
        case 's': cout << "Programa encerrado.\n"; return 0;
        default: cout << "Opção inválida.\n";
        }
    }
    return 0;
}
