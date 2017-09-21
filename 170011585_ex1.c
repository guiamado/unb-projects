/*
 Nome do Arquivo: Exercício 1 de alocação dinâmica
 Nome do Aluno: Guilherme Amado da Silva
 Matrícula: 170011585
 Descrição: O codigo a seguir requer do usuario a quantidade de profissoes,
            tamanho do nome a ser digitado.Isso utilizando alocaçao dinamica
            como pedido no comando da questao.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{

 	int* codigo;   
 	char* nome;

} Profissao;

int main(){
   
    int numProf;
    int tamanhoNome; 
    int i,r;
    
    printf("Digite a quantidade de profissoes a serem adicionadas: ");
    scanf("%d",&numProf);
  
    Profissao* profissoes = (Profissao *) malloc(numProf*sizeof(Profissao));

    for(i=0 ; i<numProf ; i++)
    {   
   
        profissoes[i].nome  = (char *)  malloc(100*sizeof(char));
        profissoes[i].codigo    = (int *) malloc(sizeof(int));

        printf("Digite o nome: "); 
        scanf("%100[^\n]s", profissoes[i].nome);
        printf("Digite o codigo da profisao: ");
        scanf("%d", profissoes[i].codigo);

       //----------------
        // printf("Digite a quantidade de letras a serem adicionadas: ");
       // scanf("%d",&tamanhoNome);
       // scanf("%%tamanhoNome%[^\n]s", profissoes[i].nome);
       //-----------------
       // printf("Digite o nome: "); 
       // scanf("%100[^\n]s", profissoes[i].nome);
    }

    for (r=0 ; r<numProf ; r++)
    {
        printf("Nome:%s\n ",profissoes[r].nome);
        printf("Codigo da profissao: %d\n ",*profissoes[r].codigo);
    }
    for(i=0 ; i<numProf ; i++)
    {
        free(profissoes[i].codigo);
        free(profissoes[i].nome);
    }
    free(profissoes);
}
