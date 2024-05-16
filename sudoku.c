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

int is_valid(Node* n)
{
   int i, j, k;

    // Verificar filas
    for (i = 0; i < 9; i++) {
        int seen[10] = {0}; // Arreglo para marcar los números vistos en la fila
        for (j = 0; j < 9; j++) {
            int num = n->sudo[i][j];
            if (num != 0) {
                if (seen[num] == 1) {
                    return 0; // Número repetido en la fila
                }
                seen[num] = 1;
            }
        }
    }

    // Verificar columnas
    for (j = 0; j < 9; j++) {
        int seen[10] = {0}; // Arreglo para marcar los números vistos en la columna
        for (i = 0; i < 9; i++) {
            int num = n->sudo[i][j];
            if (num != 0) {
                if (seen[num] == 1) {
                    return 0; // Número repetido en la columna
                }
                seen[num] = 1;
            }
        }
    }

    // Verificar submatrices de 3x3
    for (i = 0; i < 9; i += 3) {
        for (j = 0; j < 9; j += 3) {
            int seen[10] = {0}; // Arreglo para marcar los números vistos en la submatriz
            for (k = 0; k < 9; k++) {
                int num = n->sudo[i + k / 3][j + k % 3];
                if (num != 0) {
                    if (seen[num] == 1) {
                        return 0; // Número repetido en la submatriz
                    }
                    seen[num] = 1;
                }
            }
        }
    }

    return 1; // El estado es válido
}


List* get_adj_nodes(Node* n)
{
   List* list=createList();
   int contador = 1;
   int i,j;
   for(i=0;i<9;i++)
      for(j = 0; j<9;j++)
         if(n->sudo[i][j] == 0)
         {
            while(contador < 10)
               {
                  Node* adj = copy(n);
                  adj->sudo[i][j] = contador;
                  pushBack(list,adj);
                  contador++;  
               }
         }   
   return list;
}


int is_final(Node* n){
    return 0;
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