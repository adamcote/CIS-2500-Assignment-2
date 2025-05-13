#include <stdio.h>
#include <stdlib.h>
#include "a2_q2.h"


struct Double_Array * shallow_copy(struct Double_Array * to_copy) {
   struct Double_Array * new_array = malloc(sizeof(struct Double_Array));
   new_array -> row_size = to_copy -> row_size;
   new_array -> col_size = to_copy -> col_size;
   new_array -> array = to_copy -> array;


   return new_array;
}
struct Double_Array * deep_copy (struct Double_Array * to_copy) {
   struct Double_Array * new_array = double_array(to_copy -> row_size, to_copy -> col_size);
   // new_array -> row_size = to_copy -> row_size;
   // new_array -> col_size = to_copy -> col_size;
   for (int i = 0; i < to_copy -> row_size; i++) {
        for (int j = 0; j < to_copy -> col_size; j++) {
            new_array -> array[i][j] = to_copy -> array[i][j];
          
        }
    }


   return new_array;


  
}


void print_struct(struct Double_Array * to_copy, char * header) {
   printf("%s\n", header);
   printf("struct address = %p\n", to_copy);
   printf("row size =  %d, col size = %d\n", to_copy -> row_size, to_copy -> col_size );
   printf("array address = %p\n", to_copy -> array);
   printf("\n");
   print_array(to_copy);
   printf("\n\n");
}
