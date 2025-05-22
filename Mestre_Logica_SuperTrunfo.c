#include <stdio.h>
#include <string.h>

typedef struct {
    char pais[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
} Carta;

void exibe_menu(int skip) {
    printf("Escolha o atributo para comparar:\n");
    if (skip != 1) printf("1 - População\n");
    if (skip != 2) printf("2 - Área\n");
    if (skip != 3) printf("3 - PIB\n");
    if (skip != 4) printf("4 - Pontos Turísticos\n");
    if (skip != 5) printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
}

float valor_atributo(Carta c, int atributo) {
    switch(atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontos_turisticos;
        case 5: return c.densidade;
        default: return 0;
    }
}

const char* nome_atributo(int atributo) {
    switch(atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "";
    }
}

int main() {
    // Cadastro das cartas (pode alterar os valores para testar)
    Carta carta1 = {"Brasil", 211000000, 8515767.0, 1847000.0, 15, 0};
    Carta carta2 = {"Argentina", 44938712, 2780400.0, 449663.0, 8, 0};

    // Calcula densidade demográfica
    carta1.densidade = carta1.populacao / carta1.area;
    carta2.densidade = carta2.populacao / carta2.area;

    int atributo1 = 0, atributo2 = 0;

    printf("=== SUPER TRUNFO ===\n");
    printf("Comparando:\n1 - %s\n2 - %s\n\n", carta1.pais, carta2.pais);

    // Escolha do primeiro atributo
    exibe_menu(0);
    scanf("%d", &atributo1);
    while (atributo1 < 1 || atributo1 > 5) {
        printf("Opção inválida! Tente novamente.\n");
        exibe_menu(0);
        scanf("%d", &atributo1);
    }

    // Escolha do segundo atributo (não pode ser igual ao primeiro)
    exibe_menu(atributo1);
    scanf("%d", &atributo2);
    while (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        printf("Opção inválida! Tente novamente.\n");
        exibe_menu(atributo1);
        scanf("%d", &atributo2);
    }

    // Comparação dos atributos
    float v1_a1 = valor_atributo(carta1, atributo1);
    float v2_a1 = valor_atributo(carta2, atributo1);
    float v1_a2 = valor_atributo(carta1, atributo2);
    float v2_a2 = valor_atributo(carta2, atributo2);

    int vencedor_a1 = 0, vencedor_a2 = 0;
    // Regra especial para densidade demográfica (menor vence)
    if (atributo1 == 5) {
        vencedor_a1 = (v1_a1 < v2_a1) ? 1 : (v2_a1 < v1_a1) ? 2 : 0;
    } else {
        vencedor_a1 = (v1_a1 > v2_a1) ? 1 : (v2_a1 > v1_a1) ? 2 : 0;
    }
    if (atributo2 == 5) {
        vencedor_a2 = (v1_a2 < v2_a2) ? 1 : (v2_a2 < v1_a2) ? 2 : 0;
    } else {
        vencedor_a2 = (v1_a2 > v2_a2) ? 1 : (v2_a2 > v1_a2) ? 2 : 0;
    }

    float soma1 = v1_a1 + v1_a2;
    float soma2 = v2_a1 + v2_a2;

    printf("\nAtributos escolhidos:\n");
    printf("%s: %s = %.2f | %s = %.2f\n", nome_atributo(atributo1), carta1.pais, v1_a1, carta2.pais, v2_a1);
    printf("%s: %s = %.2f | %s = %.2f\n", nome_atributo(atributo2), carta1.pais, v1_a2, carta2.pais, v2_a2);

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", carta1.pais, soma1);
    printf("%s: %.2f\n", carta2.pais, soma2);

    // Resultado final
    if (soma1 > soma2)
        printf("\nResultado: %s venceu!\n", carta1.pais);
    else if (soma2 > soma1)
        printf("\nResultado: %s venceu!\n", carta2.pais);
    else
        printf("\nResultado: Empate!\n");

    return 0;
}