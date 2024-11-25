#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct livro {
	
	char nome[100];
	char isbn[20];
	float preco;
	int score;
	char editora[50];
} plivro;

    plivro* livro_aloc(int qtde) {
    
    plivro* vetorLivros = (plivro*)malloc(qtde * sizeof(plivro));

    return vetorLivros;
}

void livro_ler(plivro* livros){
	
	fgets(livros->nome, sizeof(livros->nome), stdin);
	livros->nome[strcspn(livros->nome, "\n")] = '\0';
	
	fgets(livros->isbn, sizeof(livros->isbn), stdin);
    livros->isbn[strcspn(livros->isbn, "\n")] = '\0';
	
	scanf("%f", &livros -> preco);
	getchar();
	
	scanf("%d", &livros -> score);
	getchar();
	
    fgets(livros->editora, sizeof(livros->editora), stdin);
    livros->editora[strcspn(livros->editora, "\n")] = '\0';
}

void livro_exibe(plivro* livros){
	printf("Nome: %s\n", livros -> nome);
	printf("ISBN: %s\n", livros -> isbn);
	printf("Preço: R$ %.2f\n", livros -> preco);
	printf("Score: %d\n",  livros -> score);
	printf("Editora: %s\n", livros -> editora);
	
}


void livro_desaloca(plivro* livros){
	
	free(livros);
	
}

int main() {
	
    int qtdeLivros;
    int i;

    scanf("%d", &qtdeLivros);
    getchar();

    plivro* livros = livro_aloc(qtdeLivros);

    for ( i = 0; i < qtdeLivros; i++) {
        livro_ler(&livros[i]);
    }

    for ( i = 0; i < qtdeLivros ; i++) {
        printf("\nLivro %d:\n", i + 1);
        livro_exibe(&livros[i]);
    }
    
if( i < qtdeLivros){
	printf("\n");
}
    livro_desaloca(livros);

    return 0;
}

