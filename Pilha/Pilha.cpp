/*
Atividade Etruturada para AV2
Parte 4 
Estrutura de dados do tipo pilha
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"

// Estrutura 
struct no {
       char numero[20];
       char nome[50];
       char telefone_1[15];
       char telefone_2[15];
       char email_1[50];
       char email_2[50];
       bool inalteravel;
       struct no *proximo;
       struct no *anterior;
};

typedef struct no Lista; // Definição do tipo

void menu();
void cabecalho();
void buscarContato(Lista*, char[]);
void editarContato(Lista*);
void alterarTelefone(Lista*);
void alterarEmail(Lista*);
void alterarNome(Lista*);
void marcarInalteravel(Lista*);
void inicializarAgenda(Lista**); // Inicializa a lista com NULL
void empilharPrimeiro(Lista**, char[], char[], char[], char[], char[], char[], bool); // Insere o primeiro contato
void empilhar(Lista*, char[], char[], char[], char[], char[], char[], bool); // Insere o contato no final da pilha
void desempilhar(Lista*,Lista**); // Remove o contato no final da pilha
void imprimirAgenda(Lista*); // Exibe o conteúdo da agenda

int contador = 0; // Variável global
const int LIMITE = 20; // Constante global
Lista *ptrPrimeiro; // Ponteiro Global 

int main(){
    
    menu(); // Chamada do menu
    
    system("pause");
    
    return 0;
}

//---------------------------------------------------------
void menu(){
     
     Lista *agenda; // Ponteiro externo do tipo lista
     bool acabou = false, acabou_2 = false;
     int opcao, opcao_2;
     // Variáveis locais para armazenar na lista 
     char num[20] ,nome[50], tel_1[15], tel_2[15], email_1[50], email_2[50];
     bool inalt;
     do{
          system("cls");
          cabecalho();
          printf("\n");
          printf("1 - Inicializar Agenda\n");
          printf("2 - Empilhar Primeiro\n");
          printf("3 - Empilhar\n");
          printf("4 - Desempilhar\n");
          printf("5 - Imprimir Agenda\n");
          printf("6 - Editar Contato\n");
          printf("7 - Marcar Contato Como Inalteravel\n");
          printf("8 - Buscar Contato\n");
          printf("9 - Sair\n\n");
          printf("Opcao: ");
          scanf("%d",&opcao);
          
          switch(opcao){
          case 1:
               inicializarAgenda(&agenda);
               break;
          case 2:
               printf("\n--------------------------------\n");
               printf("Numero: ");
               scanf("%s",&num);
               printf("\n");
               printf("Nome: ");
               scanf("%s",&nome);
               printf("\n");
               printf("Telefone-1: ");
               scanf("%s",&tel_1);
               printf("\n");
               printf("Telefone-2: ");
               scanf("%s",&tel_2);
               printf("\n");
               printf("E-mail-1: ");
               scanf("%s",&email_1);
               printf("\n");
               printf("E-mail-2: ");
               scanf("%s",&email_2);
               printf("\n");
               
               printf("Deseja marcar o contato como inalteravel?\n\n");
                     do{     
                       printf("1 - Sim\n");
                       printf("2 - Nao\n\n");
                       printf("Opcao: ");
                       scanf("%d",&opcao_2);
                       
                       switch(opcao_2){
                       case 1:
                            inalt = true;
                            acabou_2 = true;
                            break;
                       case 2:
                            inalt = false;
                            acabou_2 = true;
                            break;
                       default:
                            printf("\n");
                            printf("---------------\n");
                            printf("Opcao invalida!\n");
                            printf("---------------\n\n");
                            break;               
                       }
                   }while(!acabou_2);
               
               
               empilharPrimeiro(&agenda,num,nome,tel_1,tel_2,email_1,email_2,inalt);
               break;
          case 3:
               printf("\n--------------------------------\n");
               printf("Numero: ");
               scanf("%s",&num);
               printf("\n");
               printf("Nome: ");
               scanf("%s",&nome);
               printf("\n");
               printf("Telefone-1: ");
               scanf("%s",&tel_1);
               printf("\n");
               printf("Telefone-2: ");
               scanf("%s",&tel_2);
               printf("\n");
               printf("E-mail-1: ");
               scanf("%s",&email_1);
               printf("\n");
               printf("E-mail-2: ");
               scanf("%s",&email_2);
               printf("\n");
               
               printf("Deseja marcar o contato como inalteravel?\n\n");
                     do{
                       printf("1 - Sim\n");
                       printf("2 - Nao\n\n");
                       printf("Opcao: ");
                       scanf("%d",&opcao_2);
                       
                       switch(opcao_2){
                       case 1:
                            inalt = true;
                            acabou_2 = true;
                            break;
                       case 2:
                            inalt = false;
                            acabou_2 = true;
                            break;
                       default:
                            printf("\n");
                            printf("---------------\n");
                            printf("Opcao invalida!\n");
                            printf("---------------\n\n");  
                            break;               
                       }
                   }while(!acabou_2);
               
               empilhar(agenda,num,nome,tel_1,tel_2,email_1,email_2,inalt);
               break;
          case 4:
               desempilhar(agenda,&agenda);
               break;
          case 5:
               imprimirAgenda(agenda);
               break;
          case 6:
               editarContato(agenda);
               break;
          case 7:
               marcarInalteravel(agenda);
               break;
          case 8:
               printf("\n");
               printf("Digite o nome do contato: ");
               scanf("%s",&nome);
               buscarContato(agenda,nome);
               break;
          case 9:
               acabou = true;
               break;
          default:
               printf("\n");
               printf("---------------\n");
               printf("Opcao invalida!\n");
               printf("---------------\n\n");
               system("pause");   
               break;     
          }
          
     }while(!acabou);
     
}
//---------------------------------------------------------
void buscarContato(Lista *plista, char nome[50]){
     Lista *auxiliar, *auxiliar_2;
     bool achou = false;
     auxiliar = plista;
     
     while(auxiliar != NULL){
           if(strcmp(auxiliar->nome,nome) == 0){
                auxiliar_2 = auxiliar;
                achou = true;
                }
           auxiliar = auxiliar->proximo;
     }
     
     if(achou){
           printf("-----------------------------------\n");
           printf("Numero: %s\n", auxiliar_2->numero);
           printf("Nome: %s\n", auxiliar_2->nome);
           printf("Telefones: %s/%s\n",auxiliar_2->telefone_1,auxiliar_2->telefone_2);
           printf("E-mails: %s/%s\n", auxiliar_2->email_1,auxiliar_2->email_2);
           printf("-----------------------------------\n");
           system("pause");
           
     }else{
           printf("\n");
           printf("-----------------------\n");
           printf("Contato nao encontrado!\n");
           printf("-----------------------\n\n");
           system("pause");
     }
}
//---------------------------------------------------------
void editarContato(Lista *plista){
     int opcao = 0;
     bool acabou = false;
     
     do{
         system("cls");
         cabecalho();
         printf("1 - Alterar telefone\n");
         printf("2 - Alterar e-mail\n");
         printf("3 - Alterar nome\n");
         printf("4 - Voltar\n\n");
         printf("Opcao:");
         scanf("%d",&opcao);
         
         switch(opcao){
         case 1:
              alterarTelefone(plista);
              break;  
         case 2:
              alterarEmail(plista);
              break;
         case 3:
              alterarNome(plista);
              break;
         case 4:
              acabou = true;
              break;
         default:
                 printf("\n");
                 printf("---------------\n");
                 printf("Opcao invalida!\n");
                 printf("-----------------\n\n");
                 system("pause");
              break;
         }
    }while(!acabou);
}
//---------------------------------------------------------
void alterarTelefone(Lista *plista){
     bool achou = false,acabou = false;     
     int opcao;
     Lista *auxiliar, *auxiliar_2;
     auxiliar = plista;
     char numero[20], novonumero[20];
     
     printf("\n");
     printf("Numero do contato: ");
     scanf("%s",&numero);
     
     while(auxiliar != NULL){
          
          if(strcmp(auxiliar->numero,numero) == 0){
                achou = true;
                auxiliar_2 = auxiliar;
          }
          auxiliar = auxiliar->proximo;                 
     }
     
         if(achou){
               if(auxiliar_2->inalteravel == false){              
                   do{
                       system("cls");
                       cabecalho();
                       printf("Qual telefone deseja alterar?\n\n");
                       printf("1 - Telefone-1\n");          
                       printf("2 - Telefone-2\n");
                       printf("3 - Voltar\n\n");
                       printf("Opcao: ");
                       scanf("%d",&opcao);
                       
                       switch(opcao){
                       case 1:
                            
                            printf("\n");
                            printf("Digite o novo numero: ");
                            scanf("%s",&novonumero);
                            
                            strcpy(auxiliar_2->telefone_1,novonumero);
                            
                            plista = auxiliar_2;
                            
                            printf("\n");
                            printf("------------------\n");
                            printf("Telefone alterado!\n");
                            printf("------------------\n\n");
                            system("pause");
                            acabou = true;
                            break;
                       case 2:
                            
                            printf("\n");
                            printf("Digite o novo numero: ");
                            scanf("%s",&novonumero);
                            
                            strcpy(auxiliar_2->telefone_2,novonumero);
                            
                            plista = auxiliar_2;
                            
                            printf("\n");
                            printf("------------------\n");
                            printf("Telefone alterado!\n");
                            printf("------------------\n\n");
                            system("pause");
                            acabou = true;
                            break;
                       case 3:
                            acabou = true;
                            break;
                       default:
                            printf("\n");
                            printf("---------------\n");
                            printf("Opcao invalida!\n");
                            printf("---------------\n\n");
                            system("pause");
                            break;
                       }         
                   }while(!acabou);
               }else{
                     printf("\n\n");
                     printf("-----------------------------------\n");
                     printf("Esse contato nao pode ser alterado!\n");
                     printf("-----------------------------------\n\n");
                     system("pause");
                     }       
         }else{
               printf("\n\n");
               printf("-----------------------\n");
               printf("Contato nao encontrado!\n");
               printf("-----------------------\n\n");
               system("pause");
               }
}
//---------------------------------------------------------
void alterarEmail(Lista *plista){
     
     bool achou = false,acabou = false;     
     int opcao;
     Lista *auxiliar, *auxiliar_2;
     auxiliar = plista;
     char numero[20], novoemail[50];
     
     printf("\n");
     printf("Numero do contato: ");
     scanf("%s",&numero);
     
     while(auxiliar != NULL){
          
          if(strcmp(auxiliar->numero,numero) == 0){
                achou = true;
                auxiliar_2 = auxiliar;
          }
          auxiliar = auxiliar->proximo;                 
     }
     
         if(achou){
               if(auxiliar_2->inalteravel == false){        
               
                   do{
                       system("cls");
                       cabecalho();
                       printf("Qual email deseja alterar?\n\n");
                       printf("1 - E-mail-1\n");          
                       printf("2 - E-mail-2\n");
                       printf("3 - Voltar\n\n");
                       printf("Opcao: ");
                       scanf("%d",&opcao);
                       
                       switch(opcao){
                       case 1:
                            
                            printf("\n");
                            printf("Digite o novo e-mail: ");
                            scanf("%s",&novoemail);
                            
                            strcpy(auxiliar_2->email_1,novoemail);
                            
                            plista = auxiliar_2;
                            
                            printf("\n");
                            printf("----------------\n");
                            printf("E-mail alterado!\n");
                            printf("----------------\n\n");
                            system("pause");
                            acabou = true;
                            break;
                       case 2:
                            
                            printf("\n");
                            printf("Digite o novo e-mail: ");
                            scanf("%s",&novoemail);
                            
                            strcpy(auxiliar_2->email_2,novoemail);
                            
                            plista = auxiliar_2;
                            
                            printf("\n");
                            printf("----------------\n");
                            printf("E-mail alterado!\n");
                            printf("----------------\n\n");
                            system("pause");
                            acabou = true;
                            break;
                       case 3:
                            acabou = true;
                            break;
                       default:
                            printf("\n");
                            printf("---------------\n");
                            printf("Opcao invalida!\n");
                            printf("---------------\n\n");
                            system("pause");
                            break;
                       }         
                   }while(!acabou);
               
               }else{
                     printf("\n\n");
                     printf("-----------------------------------\n");
                     printf("Esse contato nao pode ser alterado!\n");
                     printf("-----------------------------------\n\n");
                     system("pause");
                     }              
         }else{
               printf("\n\n");
               printf("-----------------------\n");
               printf("Contato nao encontrado!\n");
               printf("-----------------------\n\n");
               system("pause");
               }
}
//---------------------------------------------------------
void alterarNome(Lista *plista){
     
     bool achou = false,acabou = false;     
     int opcao;
     Lista *auxiliar, *auxiliar_2;
     auxiliar = plista;
     char numero[20], novonome[50];
     
     printf("\n");
     printf("Numero do contato: ");
     scanf("%s",&numero);
     
     while(auxiliar != NULL){
          
          if(strcmp(auxiliar->numero,numero) == 0){
                achou = true;
                auxiliar_2 = auxiliar;
          }
          auxiliar = auxiliar->proximo;                 
     }

     if(achou){
          if(auxiliar_2->inalteravel == false){
              printf("\n");
              printf("Digite o novo nome: ");
              scanf("%s",&novonome);
              printf("\n");    
              
              strcpy(auxiliar_2->nome,novonome);
              
              printf("--------------\n");
              printf("Nome alterado!\n");
              printf("--------------\n\n");     
              system("pause");
              
              plista = auxiliar_2;
          }else{
               
               printf("\n\n");
               printf("-----------------------------------\n");
               printf("Esse contato nao pode ser alterado!\n");
               printf("-----------------------------------\n\n");
               system("pause");
          }
          
     }else{
           printf("\n\n");
           printf("-----------------------\n");
           printf("Contato nao encontrado!\n");
           printf("-----------------------\n\n");
           system("pause");
           }
}
//---------------------------------------------------------
void marcarInalteravel(Lista *plista){
     
     char numero[50];
     Lista *auxiliar, *auxiliar_2;
     bool achou = false;
     auxiliar = plista;
     
     printf("\n");
     printf("Digite o numero do contato: ");
     scanf("%s",&numero);
     
     while(auxiliar != NULL){
           
           if(strcmp(auxiliar->numero,numero) == 0){
                achou = true;
                auxiliar_2 = auxiliar;
          }
          auxiliar = auxiliar->proximo;           
     }               
     
     if(achou){
     
           auxiliar_2->inalteravel = true;
           plista = auxiliar_2;
           
           printf("\n");
           printf("----------------\n");
           printf("Contado marcado!\n");
           printf("----------------\n\n");
           system("pause");
           
     }else{
           
           printf("\n");
           printf("-----------------------\n");
           printf("Contato nao encontrado!\n");
           printf("-----------------------\n\n");
           system("pause");
           
           }
     
}
//---------------------------------------------------------
void inicializarAgenda(Lista **plista){
    
    *plista = NULL;      
     printf("\n\n");
     printf("--------------------\n");
     printf("Agenda inicializada!\n");
     printf("--------------------\n\n");
     system("pause");
     
}
//---------------------------------------------------------
void empilharPrimeiro(Lista **plista, char pnum[20], char pnome[50], char ptel_1[15], char ptel_2[15], char pemail_1[50], char pemail_2[50], bool inalt){
     
     if(contador <= LIMITE){
         Lista *auxiliar;
          
         // Alocação de memória
         auxiliar = (Lista *)malloc(sizeof(Lista));
         
         strcpy(auxiliar->numero,pnum);
         strcpy(auxiliar->nome,pnome);
         strcpy(auxiliar->telefone_1,ptel_1);
         strcpy(auxiliar->telefone_2,ptel_2);
         strcpy(auxiliar->email_1,pemail_1);
         strcpy(auxiliar->email_2,pemail_2);
         auxiliar->inalteravel = inalt;
         auxiliar->proximo = NULL;
         auxiliar->proximo = NULL;
         
         *plista = auxiliar;
         
         ptrPrimeiro = auxiliar;
         
         contador++;
         
         printf("\n\n");
         printf("-------------------\n");
         printf("Contato adicionado! \n");
         printf("-------------------\n\n");
         system("pause");
     }else{
         
         printf("\n");
         printf("---------------------------------------\n");          
         printf("Nao e possivel adicionar mais contatos!\n");
         printf("---------------------------------------\n\n");
         system("pause");
     }
     
}

//---------------------------------------------------------
void empilhar(Lista *plista, char pnum[20], char pnome[50], char ptel_1[15], char ptel_2[15], char pemail_1[50], char pemail_2[50], bool inalt){
     
     if(contador <= LIMITE){
         Lista *auxiliar; 
         
         // Alocação de memória
         auxiliar = (Lista *)malloc(sizeof(Lista));

          while(plista->proximo != NULL){            
             plista = plista->proximo; // Último nó
    	 }
         
         strcpy(auxiliar->numero,pnum);
         strcpy(auxiliar->nome,pnome);
         strcpy(auxiliar->telefone_1,ptel_1);
         strcpy(auxiliar->telefone_2,ptel_2);
         strcpy(auxiliar->email_1,pemail_1);
         strcpy(auxiliar->email_2,pemail_2);
         auxiliar->inalteravel = inalt;
         auxiliar->proximo = NULL;
         auxiliar->anterior = plista;
                
         plista->proximo = auxiliar;
     
         contador++;
         
         printf("\n\n");
         printf("-------------------\n");
         printf("Contato adicionado!\n");
         printf("-----------------\n\n");
         system("pause");
     }else{
         
         printf("\n");  
         printf("---------------------------------------\n");        
         printf("Nao e possivel adicionar mais contatos!\n");
         printf("---------------------------------------\n\n");
         system("pause");
     }
     
}

//---------------------------------------------------------
 void desempilhar(Lista *plista, Lista **plista2){    
     Lista *auxiliar;
     
     while(plista->proximo != NULL){
           auxiliar = plista; // Auxiliar recebe o pnúltimo nó da lista
           plista = plista->proximo; // plista recebe o endereço do último nó da lista                     
           }
     
     
     if(plista == ptrPrimeiro){
           *plista2 = NULL;
     }else{
           auxiliar->proximo = NULL; // O pnúltimo nó passa a ser o último nó da lista 
           free(plista); // Destrói o último nó da lista
     }
     
     contador--;
     
     printf("\n\n");
     printf("-----------------\n");
     printf("Contato removido! \n");
     printf("-----------------\n\n");
     system("pause");
     
}

//---------------------------------------------------------
void imprimirAgenda(Lista *plista){
     
     
     // Vai para o último nó
     while(plista->proximo != NULL){
     		plista = plista->proximo;
	 }
     
     
     if(plista == NULL){
           printf("\n\n");
           printf("------------\n");
           printf("Lista vazia! \n");
           printf("------------\n\n");
           system("pause");   
        
     }else{
         printf("\n");
         printf("===================================\n");
         printf("*******Listagem de Contatos********\n");
         printf("===================================\n\n");
         
        
         while(plista->anterior != NULL){
               
               printf("-----------------------------------\n");
               printf("Numero do contato: %s\n", plista->numero);
               printf("Nome: %s\n", plista->nome);
               printf("Telefones: %s/%s\n", plista->telefone_1, plista->telefone_2);
               printf("E-mails: %s/%s\n", plista->email_1, plista->email_2);
               printf("-----------------------------------\n");  
               
               plista = plista->anterior;
         }
         
         system("pause");      
           
     }
}


