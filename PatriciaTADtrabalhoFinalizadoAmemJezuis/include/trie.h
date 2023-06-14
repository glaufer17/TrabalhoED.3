#ifndef TRIE_H
#define TRIE_H

#define MAX_CHAR 26

typedef struct No {
    int ehFolha;
    char chave;
    struct No* filhos[MAX_CHAR];
} No;

typedef struct ArvorePatriciaTrie {
    No* raiz;
} ArvorePatriciaTrie;

ArvorePatriciaTrie* criarArvore();

No* criarNo(char chave);

int indice(char c);

void inserir(No** raiz, const char* palavra);

int buscar(No* raiz, const char* palavra);

int noVazio(No* novoNo);

No* removerAuxiliar(No* novoNo, const char* palavra, int profundidade);

void removerPalavra(No** raiz, const char* palavra);

void liberarArvoreAuxiliar(No* raiz);

void liberarArvore(ArvorePatriciaTrie* arvore);

void imprimirArvoreAuxiliar(No* raiz, int nivel);
void imprimirArvore(ArvorePatriciaTrie* arvore);

#endif /* TRIE_H */