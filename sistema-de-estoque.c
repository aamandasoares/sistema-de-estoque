#include <stdio.h>
#include <string.h>
#define AS_PRODUTOS 100

// Define a estrutura do produto
typedef struct {
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
} Produto;

Produto estoque[AS_PRODUTOS];
int total_produtos = 0;

void cadastrarProduto() {
    if (total_produtos >= AS_PRODUTOS) {
        printf("\nErro: Estoque cheio!\n");
        return;
    }
    
    printf("\n--- Cadastrar Produto ---\n");
    printf("Código: ");
    scanf("%d", &estoque[total_produtos].codigo);
    getchar(); // Limpa o buffer do teclado
    
    printf("Nome: ");
    fgets(estoque[total_produtos].nome, 50, stdin);
    estoque[total_produtos].nome[strcspn(estoque[total_produtos].nome, "\n")] = 0; // Remove o '\n'
    
    printf("Quantidade: ");
    scanf("%d", &estoque[total_produtos].quantidade);
    
    printf("Preço: R$ ");
    scanf("%f", &estoque[total_produtos].preco);
    
    total_produtos++;
    printf("Produto cadastrado com sucesso!\n");
}

void listarEstoque() {
    if (total_produtos == 0) {
        printf("\nO estoque está vazio.\n");
        return;
    }
    
    printf("\n--- Lista de Estoque ---\n");
    for (int i = 0; i < total_produtos; i++) {
        printf("ID: %d | Nome: %s | Qtd: %d | Preço: R$ %.2f\n", 
               estoque[i].codigo, estoque[i].nome, estoque[i].quantidade, estoque[i].preco);
    }
}

int main() {
    int opcao;
    
    do {
        printf("\n--- SISTEMA DE ESTOQUE ---\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Listar Estoque\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1: cadastrarProduto(); break;
            case 2: listarEstoque(); break;
            case 3: printf("Saindo do sistema...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while(opcao != 3);
    
    return 0;
}