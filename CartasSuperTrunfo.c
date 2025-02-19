#include <stdio.h>
#include <string.h>

// Definir a estrutura para uma carta
typedef struct {
    char codigo[4];            // Código da carta 
    char nome[30];             // Nome da cidade
    int populacao;             // População da cidade
    float area;                // Área da cidade em km²
    float PIB;                 // Produto Interno Bruto da cidade
    int pontos_turisticos;     // Número de pontos turísticos na cidade
} Carta;

// Função para imprimir uma carta
void imprimir_carta(Carta carta) {
    printf("Código: %s\n", carta.codigo);                // Imprime o código da carta
    printf("Nome: %s\n", carta.nome);                    // Imprime o nome da cidade
    printf("População: %d\n", carta.populacao);          // Imprime a população da cidade
    printf("Área: %f\n", carta.area);                    // Imprime a área da cidade
    printf("PIB: %f\n", carta.PIB);                      // Imprime o PIB da cidade
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos); // Imprime o número de pontos turísticos
}

// Função para cadastrar uma carta
Carta cadastrar_carta() {
    Carta nova_carta;                                       // Declara uma nova carta
    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", nova_carta.codigo);                         // Lê o código da carta
    printf("Digite o nome da cidade: ");
    scanf("%s", nova_carta.nome);                           // Lê o nome da cidade
    printf("Digite a população: ");
    scanf("%d", &nova_carta.populacao);                     // Lê a população da cidade
    printf("Digite a área: ");
    scanf("%f", &nova_carta.area);                          // Lê a área da cidade
    printf("Digite o PIB: ");
    scanf("%f", &nova_carta.PIB);                           // Lê o PIB da cidade
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &nova_carta.pontos_turisticos);             // Lê o número de pontos turísticos
    return nova_carta;                                      // Retorna a nova carta cadastrada
}

int main() {
    int quantidade;
    printf("Digite a quantidade de cartas a serem cadastradas: ");
    scanf("%d", &quantidade);                               // Lê a quantidade de cartas a serem cadastradas

    Carta cartas[quantidade];                               // Declara um array de cartas

    // Cadastro das cartas
    for (int i = 0; i < quantidade; i++) {
        printf("\nCadastro da carta %d:\n", i + 1);
        cartas[i] = cadastrar_carta();                      // Chama a função para cadastrar uma carta e armazena no array
    }

    // Exibir as cartas cadastradas
    for (int i = 0; i < quantidade; i++) {
        printf("\nCarta %d:\n", i + 1);
        imprimir_carta(cartas[i]);                          // Chama a função para imprimir uma carta
    }

    return 0;                                               // Finaliza o programa
}
