struct Double_Array {
   double ** array;
   int row_size;
   int col_size;
}
typedef Double_Array;
Double_Array * double_array (int row, int col);
void randomize_array(struct Double_Array *, double, double);
double rand_double(double a, double b);
void print_array(struct Double_Array * da);
void free_array(struct Double_Array *da);
void swap_rows(struct Double_Array *, int var_one, int var_two);
void swap_columns(struct Double_Array * da, int var_one, int var_two);
