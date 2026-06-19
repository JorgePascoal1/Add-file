



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REGISTOS 100

typedef struct {
    int codigo;
    char descricao[100];
    float valor;
} Registo;

// Protótipos das funções
int carregarDados(Registo dados[]);
void cadastrarRegisto(Registo dados[], int *total);
void listarDados(Registo dados[], int total);
void ordenarCodigo(Registo dados[], int total);
void ordenarDescricao(Registo dados[], int total);
void ordenarValor(Registo dados[], int total);
int pesquisaLinear(Registo dados[], int total, char descricao[]);
int pesquisaBinaria(Registo dados[], int total, int codigo);
void menuPesquisa(Registo dados[], int total);
void gravarTexto(Registo dados[], int total);
void gravarBinario(Registo dados[], int total);

int main() {
    Registo dados[MAX_REGISTOS];
    int total = 0, opcao;

    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1 - Carregar ficheiro\n");
        printf("2 - Cadastrar registos\n");
        printf("3 - Listar registos\n");
        printf("4 - Ordenar por codigo\n");
        printf("5 - Ordenar por descricao\n");
        printf("6 - Ordenar por valor\n");
        printf("7 - Pesquisar registo\n");
        printf("8 - Guardar ficheiro texto\n");
        printf("9 - Guardar ficheiro binario\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: /* carregarDados */ break;
            case 2: cadastrarRegisto(dados, &total); break;
            case 3: listarDados(dados, total); break;
            case 4: /* ordenarCodigo */ break;
            case 5: /* ordenarDescricao */ break;
            case 6: /* ordenarValor */ break;
            case 7: menuPesquisa(dados, total); break;
            case 8: /* gravarTexto */ break;
            case 9: /* gravarBinario */ break;
            case 0: printf("\nPrograma encerrado.\n"); break;
            default: printf("\nOpcao invalida!\n");
        }
    } while(opcao != 0);

    return 0;
}

// --- CADASTRO ---
void cadastrarRegisto(Registo dados[], int *total) {
    if(*total >= MAX_REGISTOS) {
        printf("\nLimite maximo atingido!\n");
        return;
    }
    printf("\nCodigo: ");
    scanf("%d", &dados[*total].codigo);
    getchar();
    printf("Descricao: ");
    fgets(dados[*total].descricao, 100, stdin);
    dados[*total].descricao[strcspn(dados[*total].descricao, "\n")] = '\0';
    printf("Valor: ");
    scanf("%f", &dados[*total].valor);
    (*total)++;
    printf("\nRegisto cadastrado com sucesso!\n");
}

// --- LISTAGEM VERTICAL ---
void listarDados(Registo dados[], int total) {
    if (total == 0) { printf("\nNenhum registo encontrado.\n"); return; }
    printf("\n--- LISTA DE REGISTOS ---\n");
    for(int i = 0; i < total; i++) {
        printf("Registo [%d]\n", i + 1);
        printf("  Codigo: %d\n", dados[i].codigo);
        printf("  Descricao: %s\n", dados[i].descricao);
        printf("  Valor: %.2f\n", dados[i].valor);
        printf("--------------------------\n");
    }
}

// --- PESQUISA ---
int pesquisaLinear(Registo dados[], int total, char descricao[]) {
    for (int i = 0; i < total; i++) {
        if (strcasecmp(dados[i].descricao, descricao) == 0) return i;
    }
    return -1;
}

int pesquisaBinaria(Registo dados[], int total, int codigo) {
    int inicio = 0, fim = total - 1;
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (dados[meio].codigo == codigo) return meio;
        if (dados[meio].codigo < codigo) inicio = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}

void menuPesquisa(Registo dados[], int total) {
    int tipo, codigo, resultado;
    char busca[100];
    printf("\n1 - Por Codigo\n2 - Por Descricao\nEscolha: ");
    scanf("%d", &tipo);
    if (tipo == 1) {
        printf("Digite o codigo: ");
        scanf("%d", &codigo);
        resultado = pesquisaBinaria(dados, total, codigo);
    } else {
        printf("Digite a descricao: ");
        getchar();
        fgets(busca, 100, stdin);
        busca[strcspn(busca, "\n")] = '\0';
        resultado = pesquisaLinear(dados, total, busca);
    }
    if (resultado != -1) {
        printf("\nENCONTRADO:\n Codigo: %d\n Descricao: %s\n Valor: %.2f\n", 
               dados[resultado].codigo, dados[resultado].descricao, dados[resultado].valor);
    } else {
        printf("\nRegisto nao encontrado!\n");
    }
}

// Funções pendentes (Stub)
int carregarDados(Registo d[]) { return 0; }
void ordenarCodigo(Registo d[], int t) {}
void ordenarDescricao(Registo d[], int t) {}
void ordenarValor(Registo d[], int t) {}
void gravarTexto(Registo d[], int t) {}
void gravarBinario(Registo d[], int t) {}
