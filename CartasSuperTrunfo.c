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
    float densidade_populacional; // Densidade Populacional (calculada)
    float PIB_per_capita;         // PIB per Capita (calculado)
} Carta;

// Função para calcular propriedades
void calcular_propriedades(Carta *carta) {
    carta->densidade_populacional = carta->area > 0 ? carta->populacao / carta->area : 0; // Evitar divisão por zero
    carta->PIB_per_capita = carta->populacao > 0 ? carta->PIB / carta->populacao : 0;     // Evitar divisão por zero
}

// Função para imprimir uma carta
void imprimir_carta(Carta carta) {
    printf("Código: %s\n", carta.codigo);
    printf("Nome: %s\n", carta.nome);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f\n", carta.PIB);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade_populacional);
    printf("PIB per Capita: %.2f\n", carta.PIB_per_capita);
}

// Função para cadastrar uma carta
Carta cadastrar_carta() {
    Carta nova_carta;
    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", nova_carta.codigo);
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nova_carta.nome);
    printf("Digite a população: ");
    scanf("%d", &nova_carta.populacao);
    printf("Digite a área (em km²): ");
    scanf("%f", &nova_carta.area);
    printf("Digite o PIB: ");
    scanf("%f", &nova_carta.PIB);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &nova_carta.pontos_turisticos);

    // Calcular propriedades
    calcular_propriedades(&nova_carta);

    return nova_carta;
}

int main() {
    int quantidade;
    printf("Digite a quantidade de cartas a serem cadastradas: ");
    scanf("%d", &quantidade);

    Carta cartas[quantidade];

    // Cadastro das cartas
    for (int i = 0; i < quantidade; i++) {
        printf("\nCadastro da carta %d:\n", i + 1);
        cartas[i] = cadastrar_carta();
    }

    // Exibir as cartas cadastradas
    for (int i = 0; i < quantidade; i++) {
        printf("\nCarta %d:\n", i + 1);
        imprimir_carta(cartas[i]);
    }

    return 0;
}