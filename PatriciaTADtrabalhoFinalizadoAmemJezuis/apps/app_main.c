#include <stdio.h>
#include "trie.h"

int main() {
    ArvorePatriciaTrie* arvore = criarArvore();

    // Inserindo palavras na árvore
    inserir(&(arvore->raiz), "plan");
    inserir(&(arvore->raiz), "play");
    inserir(&(arvore->raiz), "post");
    inserir(&(arvore->raiz), "poll");

    // Imprimindo a árvore Patricia
    printf("Arvore Patricia:\n");
    imprimirArvore(arvore);
    printf("\n");

    // Buscando palavras na árvore
    buscar(arvore->raiz, "plan"); 
    buscar(arvore->raiz, "play"); 
    buscar(arvore->raiz, "post"); 
    buscar(arvore->raiz, "poll"); 
    buscar(arvore->raiz, "test"); 

    // Removendo uma palavra da árvore
    removerPalavra(&(arvore->raiz), "play");
    printf("\nApos a remocao de 'play':\n");
    imprimirArvore(arvore);
    printf("\n");

    // Buscando palavras na árvore novamente
    buscar(arvore->raiz, "plan");
    buscar(arvore->raiz, "play");
    buscar(arvore->raiz, "post");
    buscar(arvore->raiz, "poll");
    buscar(arvore->raiz, "test");

    // Liberando a memória da árvore
    liberarArvore(arvore);

    return 0;
}
