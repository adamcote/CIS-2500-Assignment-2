#include <stdio.h>
#include <stdlib.h>
#include "a2_q1.h"
#include <time.h>


int main () {
   printf(" ---------------------------\n");
   printf("        Question 1           \n");
   printf(" ---------------------------\n");


   Double_Array * d = double_array(6, 9);
   randomize_array(d, 1, 57);
   print_array(d);
 
   srand(time(NULL));


   int c1 = rand() %  9;
   int c2 = rand() % 9;
   int r1 = rand() % 6;
   int r2 = rand() % 6;


   swap_rows(d, r1, r2);
   printf("\n%d and %d were swapped.\n\n", r1, r2);
   print_array(d);


   swap_columns(d, c1, c2);
   printf("\n%d and %d were swapped.\n", c1, c2);
   printf("\n");
  
   print_array(d);
   printf("\n\n\n");


   free_array(d);
   return 0;
}

