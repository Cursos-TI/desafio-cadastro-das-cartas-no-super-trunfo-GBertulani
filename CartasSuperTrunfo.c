#include <stdio.h>
#include <string.h>

// Definir a estrutura para uma carta
typedef struct {
    char codigo[4];
    char nome[30];
    int populacao;
    float area;
    float PIB;
    int pontos_turisticos;
} Carta;

// Função para imprimir uma carta
void imprimir_carta(Carta carta) {
    printf("Código: %s\n", carta.codigo);
    printf("Nome: %s\n", carta.nome);
    printf("População: %d\n", carta.populacao);
    printf("Área: %f\n", carta.area);
    printf("PIB: %f\n", carta.PIB);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
}

// Função para cadastrar uma carta
Carta cadastrar_carta() {
    Carta nova_carta;
    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", nova_carta.codigo);
    printf("Digite o nome da cidade: ");
    scanf("%s", nova_carta.nome);
    printf("Digite a população: ");
    scanf("%d", &nova_carta.populacao);
    printf("Digite a área: ");
    scanf("%f", &nova_carta.area);
    printf("Digite o PIB: ");
    scanf("%f", &nova_carta.PIB);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &nova_carta.pontos_turisticos);
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