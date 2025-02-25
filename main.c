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
        scanf(" %[^\n]", livros[i].nome);
        scanf(" %s", livros[i].isbn);
        scanf(" %f", &livros[i].preco);
        scanf(" %d", &livros[i].score);
        scanf(" %[^\n]", livros[i].editora);
    }
}


void livro_exibir(PLivro livros, int Qt) {
    for (int i = 0; i < Qt; i++) {
      if (i==0){
            printf("Livro %d:\n", i+1);
               } else {
                printf("\nLivro %d:\n", i + 1);
                  }
      printf("Nome: %s\n", livros[i].nome);
      printf("ISBN: %s\n", livros[i].isbn);
      printf("Preço: R$ %.2f\n", livros[i].preco);
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
        printf("Sem livros\n");
        return 1;
    }

    livro_ler(livros, Qt);
    livro_exibir(livros, Qt);
    livro_destruir(livros);

    return 0;
}
