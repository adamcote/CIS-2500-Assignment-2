#include <stdio.h>
#include <stdlib.h>
#include "a2_q2.h"


int main () {
   printf(" ---------------------------\n");
   printf("        Question 2a         \n");
   printf(" ---------------------------\n");


   struct Double_Array * a1 = double_array(6, 9);
   randomize_array(a1, 0.0, 10.0);
   printf("the address of a1 is %p\n ", a1);
   print_struct(a1, "the structure pointed to by a1 is:\n ");


   struct Double_Array * a2 = a1;
   printf("the address of a2 is %p\n ", a2);
   print_struct(a2, "The structure pointed to by a2 is:\n\n ");


   struct Double_Array * a_shallow = shallow_copy(a1);
   printf("the address of a_shallow is %p\n ", a_shallow);
   print_struct(a_shallow, "The structure pointed to by a_shallow is: ");


   struct Double_Array * a_deep = deep_copy(a1);
   printf("the address of a_deep is %p\n ", a_deep);
  
   print_struct(a_deep, "The structure pointed to by a_deep is:\n ");


   printf(" ---------------------------\n");
   printf("        Question 2b        \n");
   printf(" ---------------------------\n");


   a1 -> array[0][1] = 100.0;
   a2 -> array[1][2] = 200.0;
   a_shallow -> array[2][3] = 300.0;
   a_deep -> array[3][4] = 400.0;
   print_struct(a1, "A1");
   print_struct(a2, "A2");
   print_struct(a_shallow, "A_Shallow");
   print_struct(a_deep, "A_Deep");


   printf(" ---------------------------\n");
   printf("        Question 2c     \n");
   printf(" ---------------------------\n");


   struct Double_Array * b1 = double_array(6, 9);
   randomize_array(b1, 10.0, 20.0);


   a2 -> array = b1 -> array;
   print_struct(a1, "A1");
   print_struct(a2, "A2");
   print_struct(a_shallow, "A_Shallow");
   print_struct(a_deep, "A_Deep");
   print_struct(b1, "B1");
   a1 -> array[0][1] = 5000.0;
   a2 -> array[1][2] = 6000.0;
   a_shallow -> array[2][3] = 7000.0;
   a_deep -> array[3][4] = 8000.0;
   b1 -> array[4][5] = 9000.0;
   print_struct(a1, "A1");
   print_struct(a2, "A2");
   print_struct(a_shallow, "A_Shallow");
   print_struct(a_deep, "A_Deep");
   print_struct(b1, "B1");
    for (int i = 0; i < a_shallow -> row_size; i++) {
       free(a_shallow -> array[i]);
   }
   free(a_shallow -> array);
   free_array(a2);
 
   free(a_shallow);




   free(b1);


   free_array(a_deep);

}
