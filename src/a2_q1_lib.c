#include <stdio.h>
#include <stdlib.h>
#include "a2_q1.h"
#include <time.h>


/*
* Program Name: a2_q1_lib.c
* Author: Adam Cote
* Last Update: February 10, 2020
* Function: displays functions for question 1 of assignment 2 (working description)
* Compilation: make all
* Execution: ./a2_q1
*/


struct Double_Array * double_array (int row, int col) {
   struct Double_Array * da = malloc(sizeof(struct Double_Array)); /* da means pointer to struct Double_Array */
    double ** array_one = malloc(sizeof(double *) * row);
    for (int i = 0; i< row; i++) {
        array_one[i] = malloc(sizeof(double) * col);
    }


    da -> array = array_one;
    da -> row_size = row;
    da -> col_size = col;
    return da;
   
}


void randomize_array(struct Double_Array * da, double var_one, double var_two) {
    srand(time(NULL));
    for (int i = 0; i < da -> row_size; i++) {
        for (int j = 0; j < da -> col_size; j++) {
            da -> array[i][j] = rand_double(var_one, var_two);
        }
    }
}


double rand_double(double a, double b) {
   if (b > a) {
       return (double) rand() / (double) RAND_MAX * (b-a) + a;
   }
   else if ( b < a) {
      return (double) rand() / (double) RAND_MAX * (b-a) + a;
   }


   return (double) rand() / (double) RAND_MAX * a;
}


void print_array(struct Double_Array * da) {
   for (int i = 0; i < da -> row_size; i++) {
        for (int j = 0; j < da -> col_size; j++) {
            printf("%.1lf  ", da -> array[i][j]);
        }
        printf("\n");
   }
}


void free_array(struct Double_Array * da) {
   double ** array = da -> array;
   for (int i = 0; i < da -> row_size; i++) {
       free(array[i]);
       }
   free(array);
   free(da);
}


void swap_rows(struct Double_Array * da, int var_one, int var_two) { /* swap memory addresses instead of doing each one double by double */
   double * temp = da -> array[var_one]; /* sets temp equal to the original value of array[var_one] */
   da -> array[var_one] = da -> array[var_two]; /* sets array[var_one] equal to the memory address of array[var_two] */
   da -> array[var_two] = temp; /* sets array[var_two] equal to the original value of array[var_one] */
   /*Q1a: This approach works by swapping the pointers to the two arrays. Conversely, the other method would involve individually swapping each double, column by column.
   With this approach, we can avoid having to make loops altogether. */


}


void swap_columns(struct Double_Array * da, int var_one, int var_two) {
   for (int i = 0; i < da -> row_size; i++) {
       double temp = da -> array[i][var_one];
       da -> array[i][var_one] = da -> array[i][var_two];
       da -> array[i][var_two] = temp;
/*Q1b: In the array, there are already rows in a variable. That is the first part of the 2D array. I am storing a pointer to a row. There is no such array for storing columns. 4
This function has to go into the array and individually swap them. */


   }
}
