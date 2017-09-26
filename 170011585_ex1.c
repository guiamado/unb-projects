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
    int procuraCodigo, encontrou=0;
    printf("Digite a quantidade de profissoes a serem adicionadas: ");
    scanf("%d",&numProf);
  
    Profissao* profissoes = (Profissao *) malloc(numProf*sizeof(Profissao));

    for(i=0 ; i<numProf ; i++)
    {   
   
        printf("Digite a quantidade de letras a serem adicionadas: ");
        scanf("%d",&tamanhoNome);
        profissoes[i].nome  = (char *)  malloc((tamanhoNome+1)*sizeof(char));
        profissoes[i].codigo    = (int *) malloc(sizeof(int));

        printf("Digite o nome: "); 
        scanf("%s", profissoes[i].nome);
        printf("Digite o codigo da profisao: ");
        scanf("%d", profissoes[i].codigo);

	printf("%s\n",profissoes[i].nome);
       //----------------
        // printf("Digite a quantidade de letras a serem adicionadas: ");
       // scanf("%d",&tamanhoNome);
       // scanf("%%tamanhoNome%[^\n]s", profissoes[i].nome);
       //-----------------
       // printf("Digite o nome: "); 
       // scanf("%100[^\n]s", profissoes[i].nome);
    }
    printf("Digite o codigo da profissao que deseja buscar:");
    scanf("%d",&procuraCodigo);
    for(i=0;i<numProf;i++)
    {
	if(procuraCodigo == *profissoes[i].codigo){
		printf("%s\n",profissoes[i].nome);
		encontrou = 1;
	}
	
    }
    if (encontrou==0)
	    printf("Profissao nao encontrada\n");

   // for (r=0 ; r<numProf ; r++)
   // {
    //    printf("Nome:%s\n ",profissoes[r].nome);
      //  printf("Codigo da profissao: %d\n ",*profissoes[r].codigo);
   // }
    for(i=0 ; i<numProf ; i++)
    {
        free(profissoes[i].codigo);
        free(profissoes[i].nome);
    }
    free(profissoes);
}
