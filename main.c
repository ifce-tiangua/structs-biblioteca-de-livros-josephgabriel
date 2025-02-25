#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[100];
    char isbn[20];
    float preco;
    int score;
    char editora[100];
} TLivro;

typedef TLivro* PLivro;


PLivro livro_criar(int Qt) {
    return (PLivro) malloc(Qt * sizeof(TLivro));
}


void livro_ler(PLivro livros, int Qt) {
    for (int i = 0; i < Qt; i++) {

        scanf(" %s", livros[i].nome);

        scanf(" %s", livros[i].isbn);

        scanf(" %f", &livros[i].preco);

        scanf(" %d", &livros[i].score);

        scanf(" %s", livros[i].editora);
    }
}


void livro_exibir(PLivro livros, int Qt) {

    for (int i = 0; i < Qt; i++) {
        printf("\nLivro %d:\n", i + 1);
        printf("Nome: %s\n", livros[i].nome);
        printf("ISBN: %s\n", livros[i].isbn);
        printf("Preco: R$ %.2f\n", livros[i].preco);
        printf("Score: %d\n", livros[i].score);
        printf("Editora: %s\n", livros[i].editora);
    }
}


void livro_destruir(PLivro livros) {
    free(livros);
}

int main() {
    int Qt;
    scanf("%d", &Qt);

    PLivro livros = livro_criar(Qt);
    if (livros == NULL) {
        return 1;
    }

    livro_ler(livros, Qt);
    livro_exibir(livros, Qt);
    livro_destruir(livros);

    return 0;
}
