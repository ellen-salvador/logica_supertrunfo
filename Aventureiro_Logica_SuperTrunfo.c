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

int main() {
    // Cadastro das cartas (pode alterar os valores para testar)
    Carta carta1 = {"Brasil", 211000000, 8515767.0, 1847000.0, 15, 0};
    Carta carta2 = {"Argentina", 44938712, 2780400.0, 449663.0, 8, 0};

    // Calcula densidade demográfica
    carta1.densidade = carta1.populacao / carta1.area;
    carta2.densidade = carta2.populacao / carta2.area;

    int opcao;
    printf("=== SUPER TRUNFO ===\n");
    printf("Comparando:\n1 - %s\n2 - %s\n\n", carta1.pais, carta2.pais);
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    int vencedor = 0; // 1 = carta1, 2 = carta2, 0 = empate

    switch(opcao) {
        case 1: // População
            printf("\nPopulação:\n%s: %d\n%s: %d\n", carta1.pais, carta1.populacao, carta2.pais, carta2.populacao);
            if (carta1.populacao > carta2.populacao)
                vencedor = 1;
            else if (carta2.populacao > carta1.populacao)
                vencedor = 2;
            break;
        case 2: // Área
            printf("\nÁrea:\n%s: %.2f\n%s: %.2f\n", carta1.pais, carta1.area, carta2.pais, carta2.area);
            if (carta1.area > carta2.area)
                vencedor = 1;
            else if (carta2.area > carta1.area)
                vencedor = 2;
            break;
        case 3: // PIB
            printf("\nPIB:\n%s: %.2f\n%s: %.2f\n", carta1.pais, carta1.pib, carta2.pais, carta2.pib);
            if (carta1.pib > carta2.pib)
                vencedor = 1;
            else if (carta2.pib > carta1.pib)
                vencedor = 2;
            break;
        case 4: // Pontos Turísticos
            printf("\nPontos Turísticos:\n%s: %d\n%s: %d\n", carta1.pais, carta1.pontos_turisticos, carta2.pais, carta2.pontos_turisticos);
            if (carta1.pontos_turisticos > carta2.pontos_turisticos)
                vencedor = 1;
            else if (carta2.pontos_turisticos > carta1.pontos_turisticos)
                vencedor = 2;
            break;
        case 5: // Densidade Demográfica (menor vence)
            printf("\nDensidade Demográfica:\n%s: %.6f\n%s: %.6f\n", carta1.pais, carta1.densidade, carta2.pais, carta2.densidade);
            if (carta1.densidade < carta2.densidade)
                vencedor = 1;
            else if (carta2.densidade < carta1.densidade)
                vencedor = 2;
            break;
        default:
            printf("Opção inválida!\n");
            return 1;
    }

    // Exibe resultado
    if (vencedor == 1)
        printf("\nResultado: %s venceu!\n", carta1.pais);
    else if (vencedor == 2)
        printf("\nResultado: %s venceu!\n", carta2.pais);
    else
        printf("\nResultado: Empate!\n");

    return 0;
}