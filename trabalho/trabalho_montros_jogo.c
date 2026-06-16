#include <stdio.h>
#include <string.h>
#include <windows.h>


struct Monstro {
    int id;
    char nome[50];
    int level;
};

int main() {
    struct Monstro lista[10];
    int qtd = 0; 
    int opcao = 0;

    while (opcao != 6) {
        printf("\n--- INICIO DO JOGO ---\n");
        printf("1. Cadastrar Monstro\n");
        printf("2. Listar Monstros\n");
        printf("3. Buscar por ID\n");
        printf("4. Atualizar Monstro\n");
        printf("5. Excluir Monstro\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); 

        
        if (opcao == 1) {
            if (qtd >= 10) {
                printf("Erro: O limite de 10 monstros foi atingido.\n");
            } else {
                int id_novo;
                int achei_repetido = 0;

                printf("Digite o ID do monstro: ");
                scanf("%d", &id_novo);
                getchar();

                
                for (int i = 0; i < qtd; i++) {
                    if (lista[i].id == id_novo) {
                        achei_repetido = 1;
                        break;
                    }
                }

                if (achei_repetido == 1) {
                    printf("Erro: Esse ID ja esta cadastrado.\n");
                } else {
                    lista[qtd].id = id_novo;

                    printf("Digite o nome da especie: ");
                    fgets(lista[qtd].nome, 50, stdin);
                    lista[qtd].nome[strcspn(lista[qtd].nome, "\n")] = '\0';

                    printf("Digite o level do monstro: ");
                    scanf("%d", &lista[qtd].level);
                    getchar();

                    qtd++;
                    printf("Monstro cadastrado com sucesso!\n");
                }
            }
        }

        
        else if (opcao == 2) {
            if (qtd == 0) {
                printf("Nao ha nenhum monstro cadastrado.\n");
            } else {
                printf("\n--- LISTA DE MONSTROS ---\n");
                for (int i = 0; i < qtd; i++) {
                    printf("Posicao %d -> ID: %d | Nome: %s | Level: %d\n", i, lista[i].id, lista[i].nome, lista[i].level);
                }
            }
        }

        
        else if (opcao == 3) {
            if (qtd == 0) {
                printf("Nao ha monstros cadastrados para buscar.\n");
            } else {
                int id_busca;
                int encontrado = 0;

                printf("Digite o ID do monstro que procura: ");
                scanf("%d", &id_busca);

                for (int i = 0; i < qtd; i++) {
                    if (lista[i].id == id_busca) {
                        printf("Monstro encontrado na posicao %d:\n", i);
                        printf("ID: %d | Nome: %s | Level: %d\n", lista[i].id, lista[i].nome, lista[i].level);
                        encontrado = 1;
                        break;
                    }
                }

                if (encontrado == 0) {
                    printf("Erro: Monstro com ID %d nao encontrado.\n", id_busca);
                }
            }
        }

        
        else if (opcao == 4) {
            if (qtd == 0) {
                printf("Nao ha monstros para atualizar.\n");
            } else {
                int id_alterar;
                int encontrado = 0;

                printf("Digite o ID do monstro que deseja alterar: ");
                scanf("%d", &id_alterar);

                for (int i = 0; i < qtd; i++) {
                    if (lista[i].id == id_alterar) {
                        printf("Monstro encontrado. Digite os novos dados:\n");
                        
                        printf("Novo Nome: ");
                        getchar();
                        fgets(lista[i].nome, 50, stdin);
                        lista[i].nome[strcspn(lista[i].nome, "\n")] = '\0';

                        printf("Novo Level: ");
                        scanf("%d", &lista[i].level);
                        getchar();

                        printf("Monstro atualizado com sucesso!\n");
                        encontrado = 1;
                        break;
                    }
                }

                if (encontrado == 0) {
                    printf("Erro: ID nao encontrado.\n");
                }
            }
        }

        
        else if (opcao == 5) {
            if (qtd == 0) {
                printf("Nao ha monstros para excluir.\n");
            } else {
                int id_deletar;
                int encontrado = 0;

                printf("Digite o ID do monstro que quer excluir: ");
                scanf("%d", &id_deletar);

                for (int i = 0; i < qtd; i++) {
                    if (lista[i].id == id_deletar) {
                        encontrado = 1;

                        
                        for (int j = i; j < qtd - 1; j++) {
                            lista[j].id = lista[j + 1].id;
                            strcpy(lista[j].nome, lista[j + 1].nome);
                            lista[j].level = lista[j + 1].level;
                        }

                        qtd--; 
                        printf("Monstro deletado com sucesso!\n");
                        break;
                    }
                }

                if (encontrado == 0) {
                    printf("Erro: Monstro nao encontrado.\n");
                }
            }
        }

        
        else if (opcao == 6) {
            printf("Saindo do programa...\n");
        } 
        
       
        else {
            printf("Opcao invalida! Tente de 1 a 6.\n");
        }
    }

    return 0;
}