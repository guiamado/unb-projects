/*
 Nome do Arquivo: Exercício 2 de alocação dinâmica
 Nome do Aluno: Guilherme Amado da Silva
 Matrícula: 170011585
 Descrição: O codigo a seguir requer que o programa leia certos dados de N funcionários,
            e imprima uma lista de funcionarios que ganham salario acima da media geral.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{

 	char* nome;
    char* cargo;
    char* departamento;
    float* salario;
    char* admissao;

} Funcionario;

int main(){
   
    int numProf;
    int tamanhoNome; 
    int i,r;
    float media =0.0;
    
    printf("Digite a quantidade de funcionarios a serem adicionados: ");
    scanf("%d",&numProf);
  
    Funcionario* funcs = (Funcionario *) malloc(numProf*sizeof(Funcionario));

    for(i=0 ; i<numProf ; i++)
    {   
   
        funcs[i].nome  = (char *)  malloc(100*sizeof(char));
        funcs[i].cargo    = (char *) malloc(sizeof(char));
    }

    for(i=0 ; i<numProf ; i++)
    {
        printf("Digite o nome: "); 
        scanf("%100s[^\n]", funcs[i].nome);
        printf("Digite o codigo da profisao: ");
        scanf("%100s[^\n]", funcs[i].cargo);


        printf("Digite o departamento: ");
        scanf("%100s[^\n]", funcs[i].departamento);

        printf("Digite a data de admissao(dd/mm/aaaa): ");
        scanf("%10s[^\n]", funcs[i].admissao);

        printf("Digite o salario: "); 
        scanf("%f",(float *)funcs[i].salario);
    }

//calculando a media
    for (r=0 ; r<numProf ; r++)
    {
        media= media +(float *) funcs[r].salario;
    }

    for (r=0 ; r<numProf ; r++)
    media = media / numProf;
//-------------

    for (r=0 ; r<numProf ; r++)
    {
        printf("Nome:%s\n ",funcs[r].nome);
        printf("Cargo: %s\n ",funcs[r].cargo);
        if((float *)funcs[r].salario > media)
            printf("Salario:%f\n",*funcs[r].salario);
    }
    for(i=0 ; i<numProf ; i++)
    {
        free(funcs[i].cargo);
        free(funcs[i].nome);
    }
    free(funcs);
}
