#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

void hacerCeroArr(int* arr)
{
   for(int i = 0; i < 10; i++)
      {
         arr[i] = 0;
      }
}


int is_valid(Node* n){
   int arr[10];
   hacerCeroArr(arr);
   for(int i = 0; i < 9; i++)
      {
         for(int j = 0; j < 9; j++)
            {
               if(n->sudo[i][j] != 0)
               {
                  if(arr[n->sudo[i][j]] == 0)
                  {
                     arr[n->sudo[i][j]] = 1;
                  }
                  else
                  {
                     return 0;
                  }
               }
               
            }
         hacerCeroArr(arr);
      }   

   int k=4,p; 
   for(p=0;p<9;p++){
       int i=3*(k/3) + (p/3) ;
       int j=3*(k%3) + (p%3) ;
      if(n->sudo[i][j] != 0)
      {
         if(arr[n->sudo[i][j]] == 0)
         {
            arr[n->sudo[i][j]] = 1;
         }
         else
         {
            return 0;
         }
      }
   }
   
    return 1;
}


List* get_adj_nodes(Node* n){
    List* list=createList();
    for(int i = 0; i < 9; i++)
       {
          for(int j = 0; j < 9; j++)
             {
                if(n->sudo[i][j] == 0)
                {
                   int k = 0;
                   while(k < 10)
                      { 
                         k++;
                         Node* adj2 = copy(n);
                         adj2->sudo[i][j] = k;
                         pushBack(list, adj2);
                      }
                   return list;
                }
             }
       }
    
    return list;
   
    
}


int is_final(Node* n){
   for(int i = 0; i < 9; i++)
      {
         for(int j = 0; j < 9; j++)
            {
               if(n->sudo[i][j] == 0)
                  return 0;
            }
      }
   
    return 1;
}

Node* DFS(Node* initial, int* cont){
   
   
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/