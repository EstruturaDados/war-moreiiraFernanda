// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
#include <stdio.h>
#include <string.h> 

// Estrutura que representa um território, contendo:
// - Nome (até 29 caracteres + '\0')
// - Cor (até 9 caracteres + '\0')
// - Tropas (inteiro)
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

// Função auxiliar para limpar o buffer de entrada do teclado,
// evitando problemas ao usar scanf seguido de fgets.
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int numTerritorios, i;
    
    // Solicita ao usuário o número de territórios
    printf("Digite o número de territórios: ");
    scanf("%d", &numTerritorios);
    limparBufferEntrada();

    // Aloca dinamicamente um vetor de estruturas do tipo Territorio
    struct Territorio *territorios = malloc(numTerritorios * sizeof(struct Territorio));
    

    // Loop para preencher os dados de cada território
    for (i = 0; i < numTerritorios; i++) {
        printf("Digite o nome do território %d: ", i + 1);
        fgets(territorios[i].nome, sizeof(territorios[i].nome), stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = 0; // Remove o '\n'

        printf("Digite a cor do território %d: ", i + 1);
        fgets(territorios[i].cor, sizeof(territorios[i].cor), stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = 0;  // Remove o '\n'

        printf("Digite o número de tropas no território %d: ", i + 1);
        scanf("%d", &territorios[i].tropas);
        limparBufferEntrada(); // Evita problemas de leitura na próxima iteração
    }

    // Exibição dos dados cadastrados
    printf("\nInformações dos territórios:\n");
    for (i = 0; i < numTerritorios; i++) {
        printf("Território %d: Nome: %s, Cor: %s, Tropas: %d\n", 
               i + 1, territorios[i].nome, territorios[i].cor, territorios[i].tropas);
    }

    // Libera a memória alocada dinamicamente
    free(territorios);

    return 0; // Finaliza o programa corretamente
}
