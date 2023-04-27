#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Definição da estrutura Idoso
struct Idoso
{
    string nome;
    int id;
    int idade;
};

// Função para realizar a ordenação dos idosos utilizando o algoritmo QuickSort
void quickSort(vector<Idoso> &idosos, int inicio, int fim)
{
    if (inicio < fim)
    {
        int pivo = fim;
        int esq = inicio - 1;
        int dir = fim;

        while (true)
        {
            do
            {
                esq++;
            } while (idosos[esq].idade < idosos[pivo].idade);

            do
            {
                dir--;
            } while (idosos[dir].idade > idosos[pivo].idade && dir > inicio);

            if (esq >= dir)
            {
                break;
            }
            else
            {
                swap(idosos[esq], idosos[dir]);
            }
        }

        swap(idosos[esq], idosos[fim]);
        quickSort(idosos, inicio, esq - 1);
        quickSort(idosos, esq + 1, fim);
    }
}

// Função para Apresentar os Idosos Cadastrados;
void apresentarIdosos(vector<Idoso> &idosos)
{
    for (int i = 0; i < idosos.size(); i++)
    {
        cout << "Nome: " << idosos[i].nome << endl;
        cout << "Idade: " << idosos[i].idade << endl;
        cout << "ID: " << idosos[i].id << endl;
        cout << endl;
    }
}

// Função para realizar a busca binária em um vetor ordenado
int buscaBinaria(vector<Idoso> &vetor, int chave)
{
    int inicio = 0;
    int fim = vetor.size() - 1;

    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;

        if (vetor[meio].id == chave)
        {
            return meio;
        }
        else if (vetor[meio].id < chave)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }

    return -1; // chave não encontrada
}

// Função para realizar a ordenação dos idosos utilizando o algoritmo Bubble Sort
void bubbleSort(vector<Idoso> &idosos)
{
    int n = idosos.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (idosos[j].idade > idosos[j + 1].idade)
            {
                swap(idosos[j], idosos[j + 1]);
            }
        }
    }
}

// Função para mostrar o menu de opções
void mostrarMenu()
{
    cout << "Escolha uma opção:" << endl;
    cout << "1 - Cadastrar idosos" << endl;
    cout << "2 - Ordenar idosos por idade com QuickSort" << endl;
    cout << "3 - Ordenar idosos por idade com BubbleSort" << endl;
    cout << "4 - Procurar idoso por ID" << endl;
    cout << "5 - Apresentar todos os idosos cadastrados" << endl;
    cout << "6 - Sair" << endl;
    cout << endl;
}

int main()
{
    int userResponseSorter = 0;
    int userResponse;
    vector<Idoso> idosos;
    int n;

    do
    {
        mostrarMenu();
        cin >> userResponse;

        switch (userResponse)
        {
            case 1:
                cout << "Quantos idosos deseja cadastrar? ";
                cin >> n;

                for (int i = 0; i < n; i++)
                {
                    Idoso novoIdoso;

                    cout << "Digite o nome do " << i + 1 << "o idoso: ";
                    cin >> novoIdoso.nome;

                    cout << "Digite a idade do " << i + 1 << "o idoso: ";
                    cin >> novoIdoso.idade;

                    cout << "Digite o ID do " << i + 1 << "o idoso: ";
                    cin >> novoIdoso.id;

                    idosos.push_back(novoIdoso);

                    cout << endl;
                }
                break;
            case 2:{
                quickSort(idosos, 0, idosos.size() - 1);
                }break;
            case 3:{
                bubbleSort(idosos);
                }break;
            case 4:{
                int idBusca;
                cout << "Digite o ID do idoso que deseja buscar: ";
                cin >> idBusca;

                int indice = buscaBinaria(idosos, idBusca);
                if (indice == -1)
                {
                    cout << "Idoso não encontrado!" << endl;
                }
                else
                {
                    cout << "Nome: " << idosos[indice].nome << endl;
                    cout << "Idade: " << idosos[indice].idade << endl;
                    cout << "ID: " << idosos[indice].id << endl;
                    cout << endl;
                }
                }break;
            case 5:{
                apresentarIdosos(idosos);
                }break;
            case 6:{
                cout << "Saindo do programa..." << endl;
                }break;
            default:{
                cout << "Opção inválida!" << endl;
                }break;
        }

    } while (userResponse != 6);

    return 0;
}