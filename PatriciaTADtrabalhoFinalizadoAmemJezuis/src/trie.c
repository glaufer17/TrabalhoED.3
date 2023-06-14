#include "trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ArvorePatriciaTrie* criarArvore() {
    ArvorePatriciaTrie* arvore = (ArvorePatriciaTrie*)malloc(sizeof(ArvorePatriciaTrie));
    arvore->raiz = NULL;
    return arvore;
}

No* criarNo(char chave) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->ehFolha = 0;
    novoNo->chave = chave;
    for (int i = 0; i < MAX_CHAR; i++) {
        novoNo->filhos[i] = NULL;
    }
    return novoNo;
}

int pegarIndice(char c) {
    return c - 'a';
}

void inserir(No** raiz, const char* palavra) {
    if (*raiz == NULL) {
        *raiz = criarNo('\0');
    }

    No* noAtual = *raiz;
    int tamanho  = strlen(palavra);
    int i = 0;
    
    while (i < tamanho ) {
        int index = pegarIndice(palavra[i]);
        if (noAtual->filhos[index] == NULL) {
            noAtual->filhos[index] = criarNo(palavra[i]);
        }
        noAtual = noAtual->filhos[index];
        i++;
    }
    noAtual->ehFolha = 1;
}

int buscar(No* raiz, const char* palavra) {
    if (raiz == NULL) {
        return 0;
    }

    printf("Buscando '%s': ", palavra);

    No* noAtual = raiz;
    int tamanho  = strlen(palavra);
    int i = 0;

    while (i < tamanho ) {
        int index = pegarIndice(palavra[i]);
        if (noAtual->filhos[index] == NULL) {
            printf("Nao encontrado\n");
            return 0;
        }
        noAtual = noAtual->filhos[index];
        i++;
    }
    printf("Encontrado\n");
    return (noAtual != NULL && noAtual->ehFolha);
}

int noVazio(No* novoNo) {
    for (int i = 0; i < MAX_CHAR; i++) {
        if (novoNo->filhos[i] != NULL) {
            return 0;
        }
    }
    return 1;
}

No* removerAuxiliar(No* novoNo, const char* palavra, int profundidade) {
    if (novoNo == NULL) {
        return NULL;
    }

    if (profundidade == strlen(palavra)) {
        if (novoNo->ehFolha) {
            novoNo->ehFolha = 0;
        }
        if (noVazio(novoNo)) {
            free(novoNo);
            novoNo = NULL;
        }
        return novoNo;
    }

    int index = pegarIndice(palavra[profundidade]);
    novoNo->filhos[index] = removerAuxiliar(novoNo->filhos[index], palavra, profundidade + 1);

    if (noVazio(novoNo) && novoNo->ehFolha == 0) {
        free(novoNo);
        novoNo = NULL;
    }
    return novoNo;
}

void removerPalavra(No** raiz, const char* palavra) {
    if (*raiz == NULL) {
        return;
    }
    *raiz = removerAuxiliar(*raiz, palavra, 0);
}

void liberarArvoreAuxiliar(No* raiz) {
    if (raiz == NULL) {
        return;
    }

    for (int i = 0; i < MAX_CHAR; i++) {
        if (raiz->filhos[i] != NULL) {
            liberarArvoreAuxiliar(raiz->filhos[i]);
        }
    }

    free(raiz);
}

void liberarArvore(ArvorePatriciaTrie* arvore) {
    if (arvore == NULL) {
        return;
    }

    liberarArvoreAuxiliar(arvore->raiz);
    free(arvore);
}

void imprimirArvoreAuxiliar(No* raiz, int nivel) {
    if (raiz == NULL) {
        return;
    }

    for (int i = 0; i < nivel; i++) {
        printf("  ");
    }

    if (raiz->chave == '\0') {
        printf("RAIZ\n");
    } else {
        printf("%c\n", raiz->chave);
    }

    for (int i = 0; i < MAX_CHAR; i++) {
        if (raiz->filhos[i] != NULL) {
            imprimirArvoreAuxiliar(raiz->filhos[i], nivel + 1);
        }
    }
}

void imprimirArvore(ArvorePatriciaTrie* arvore) {
    if (arvore == NULL || arvore->raiz == NULL) {
        printf("A arvore esta vazia.\n");
        return;
    }

    imprimirArvoreAuxiliar(arvore->raiz, 0);
}
