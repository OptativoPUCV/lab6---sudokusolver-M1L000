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
   for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++){
         if(n->sudo[i][j] == 0){
            continue;
         }
         for(int k = 0; k < 9; k++){
            if(n->sudo[i][k] == n->sudo[i][j] && k != j){
               return 0;
            }
         }
         for(int l = 0; l < 9; l++){
            if(n->sudo[l][j] == n->sudo[i][j] && l != i){
               return 0;
            }

         }
         for(int k = 0; k < 3; k++){
            for(int l = 0; l < 3; l++){
               if(n->sudo[i/3*3 + k][j/3*3 + l] == n->sudo[i][j] && (i/3*3 + k != i || j/3*3 + l != j)){
                  return 0;
               }

            }

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
                   int k = 1;
                   while(k < 10)
                      {
                         Node* adj2 = copy(n);
                         adj2->sudo[i][j] = k;
                         if(is_valid(adj2) == 1) pushBack(list, adj2);
                         k++;
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



Node* DFS(Node* initial, int* cont) {
    Stack* s = createStack();
    push(s, initial);

    while (!is_empty(s)) {
        Node* n = top(s);
        pop(s);

        if (is_final(n)) {
            return n;
        }

        List* adj = get_adj_nodes(n);
        Node* aux = first(adj);
        while (aux) {
            push(s, aux);
            aux = next(adj);
        }

        clean(adj);
    }

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