#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[3];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
    float pib_per_capita;
} Carta;

int main() {
    // Cadastro das cartas (pode alterar os valores para testar)
    Carta carta1 = {"SP", "C1", "São Paulo", 12300000, 1521.11, 800000.0, 10};
    Carta carta2 = {"RJ", "C2", "Rio de Janeiro", 6000000, 1182.30, 400000.0, 8};

    // Calcula densidade e PIB per capita
    carta1.densidade = carta1.populacao / carta1.area;
    carta2.densidade = carta2.populacao / carta2.area;
    carta1.pib_per_capita = carta1.pib / carta1.populacao;
    carta2.pib_per_capita = carta2.pib / carta2.populacao;

    // Escolha do atributo para comparação (altere para "populacao", "area", "pib", "densidade", "pib_per_capita")
    char atributo[] = "populacao";

    printf("Comparação de cartas (Atributo: %s):\n", atributo);
    printf("Carta 1 - %s (%s): ", carta1.nome, carta1.estado);
    if (strcmp(atributo, "populacao") == 0)
        printf("%d\n", carta1.populacao);
    else if (strcmp(atributo, "area") == 0)
        printf("%.2f\n", carta1.area);
    else if (strcmp(atributo, "pib") == 0)
        printf("%.2f\n", carta1.pib);
    else if (strcmp(atributo, "densidade") == 0)
        printf("%.2f\n", carta1.densidade);
    else if (strcmp(atributo, "pib_per_capita") == 0)
        printf("%.2f\n", carta1.pib_per_capita);

    printf("Carta 2 - %s (%s): ", carta2.nome, carta2.estado);
    if (strcmp(atributo, "populacao") == 0)
        printf("%d\n", carta2.populacao);
    else if (strcmp(atributo, "area") == 0)
        printf("%.2f\n", carta2.area);
    else if (strcmp(atributo, "pib") == 0)
        printf("%.2f\n", carta2.pib);
    else if (strcmp(atributo, "densidade") == 0)
        printf("%.2f\n", carta2.densidade);
    else if (strcmp(atributo, "pib_per_capita") == 0)
        printf("%.2f\n", carta2.pib_per_capita);

    // Lógica de decisão
    int vencedor = 0; // 1 = carta1, 2 = carta2, 0 = empate
    if (strcmp(atributo, "densidade") == 0) {
        if (carta1.densidade < carta2.densidade)
            vencedor = 1;
        else if (carta2.densidade < carta1.densidade)
            vencedor = 2;
    } else if (strcmp(atributo, "populacao") == 0) {
        if (carta1.populacao > carta2.populacao)
            vencedor = 1;
        else if (carta2.populacao > carta1.populacao)
            vencedor = 2;
    } else if (strcmp(atributo, "area") == 0) {
        if (carta1.area > carta2.area)
            vencedor = 1;
        else if (carta2.area > carta1.area)
            vencedor = 2;
    } else if (strcmp(atributo, "pib") == 0) {
        if (carta1.pib > carta2.pib)
            vencedor = 1;
        else if (carta2.pib > carta1.pib)
            vencedor = 2;
    } else if (strcmp(atributo, "pib_per_capita") == 0) {
        if (carta1.pib_per_capita > carta2.pib_per_capita)
            vencedor = 1;
        else if (carta2.pib_per_capita > carta1.pib_per_capita)
            vencedor = 2;
    }

    // Exibe resultado
    if (vencedor == 1)
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
    else if (vencedor == 2)
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
    else
        printf("Resultado: Empate!\n");

    return 0;
}