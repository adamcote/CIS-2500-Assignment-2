# a2_q1.c and a2_q1_lib.c - Name of programs that contain first question

#Descriptions

a2_q1.c contains the main function. This function prints out the 'Question 1' header, randomly intializes the array and prints it out from the strucure.
It also randomly swaps two rows through the use of the swap_rows function found in a2_q1_lib.c. After the user is informed of which rows were swapped, the program will use the swap_columns function to
randomly swap two columns. After the columns have been swapped, the user will be informed and three blank lines will be printed out in order to improve the program's spacing. 

a2_q1_lib.c contains all other functions that are used in the main program. The first function, double_array, returns a pointer to a custom struct called Double_Array.
This structure holds the row size and the column size that is used in other functions. The second function, randomize_array, takes a Double_Array struct and two values of type double. The struct
then initializes each element of the array to a randomly generated value between the two input values. The third function, print_array, takes a Double_Array struct pointer and prints the array
with each element displaying 1 decimal place, with the column elements lining up vertically. The fourth function, free_array, takes a Double_Array struct pointer and frees the struct as well as
the array inside of it. The fifth function, swap_rows, contains a struct Double_Array pointer, and two int values. The two int values are row numbers that are swapped. The methods used in this
function are explained below. The final function is called swap_columns and swaps two int values much like the previous function. The one major difference with this function is discussed in 
more detail below.

Q1a: This approach works by swapping the pointers to the two arrays. The first line, double * temp = da -> array[var_one], briefly is set to the original memory address of var_one. The second line,
da -> array[var_one] = da -> array[var_two];, sets the position of var_one equal to the position of var_two. The final line, da -> array[var_two] = temp;, sets var_two equal to temp, 
the original position of var_one. Hence, the swap is complete. Conversely, the other method would involve individually swapping each double, column by column. With this approach, we can avoid 
having to make loops altogether.

Q1b: In the array, there are already rows in a variable. That is the first part of the 2D array. I am storing a pointer to a row. There is no such array for storing columns. 
Therefore, instead of assuming that we can set rows quickly, this function has to go into the array and individually swap values. 

#Source Files
a2_q1.h - required functions for source code
a2_q1_lib.c - source code
a2_q1.c - main program
Makefile

#Compilation
make all

#Execution
./a2_q1

#a2_q2.c and a2_q2_lib.c - Name of programs that contain second question

#Descriptions

a2_q2_c contains the main function. This function prints out the headers, 'Question 2a', Question 2b', and 'Question 2c', in the required format. Question 2a uses a variable, a1, to hold a 
Double_Array struct with a 6 x 9 array. a1's memory address and structure is printed out through the use of a printf statement. a1's structure it points to is printed through the use of print_struct,
a function found in a2_q1_lib.c. The same is done for variables called a2, a_shallow, and a_deep. Question 2b sets a1[0][1] to 100.0, a2[1][2] equal to 200.0, a_shallow[2][3] equal to 39.0, 
and a_deep[3][4] to 400.0. The variables are printed out and three blank lines are printed out to assist spacing. Question 2c creates a variable, b1, and holds a Double_Array struct with a 
6 x 9 array. b1 is randomly initialized to variables between 10.0 and 20.0. After a2 -> array is set equal to b1 -> array, the four variables are printed out. For the second part of this question,
a1[0][1] is set to 5000.0, a2[1][2] is set to 6000.0, a_shallow[2][3] is set to 700.0, a_deep[3][4] is set to 8000.0, and b1[4][5] is set to 9000.0. Then, the four variables are printed with these
adjustments.

Q2b: The results show that a1, a2, and a_shallow all have the exact same output. a1 and a2 both have the same struct and array addresses. a_shallow has the same array address, but not the same struct address.
a_deep prints out perfectly without any errors. a1 and a2 are the same because of the line struct Double_Array * a2 = a1. The function of this line is explained in more detail for Q2c. a_shallow has the same array address because of the shallow copy's function. This is also explained in Q2c.
Since Q2c has the same conditions as Q2b apart from b1, that will explain why this portion of the question acts the way it does. 

Q2c: The results show that a1, a2, and b1 all print out the same output. A_shallow also prints out 100 and 200 from 2b as well as 700. A_deep is the only function that works exactly as intended.
This occurs because of the lines struct Double_Array * a2 = a1; and a2 -> array = b1 -> array. 
The first line sets the pointer of a2 equal to a1. Because of this, the struct and array addresses for both a1 and a2 are the same.
The second line sets a2 -> array equal to b1 -> array. Unlike a typical pointer operation, this sets the elements of a2 and b1 equal to each other. This is why b1 has the same array address, but not the same struct address. 
A_shallow points to the same information as a1 in Q2b because the line struct Double_Array * a_shallow = shallow_copy(a1) makes a_shallow and a1 from Q2b point to the same information.
a2_q2_lib.c contains two functions outside of the main function, shallow_copy and deep_copy. A_deep prints out correctly because the new pointer (effectively, new information) is stored in the structure copy.
shallow_copy returns a copy of the Double_Array struct that is passed in (has a different pointer value) but holds the same content. Any change to the interior of either the new or the oold
struct should be reflected in the other automatically, even though the pointersto the two structs are different. deep_copy returns a copy of the Double_Array struct that is passed in (has a different pointer value) but holds the same content. Now, however, any change to the interior of one struct should not be reflected in the other. 
print_struct prints out a header on the first line, the struct address, the row and column sizes, the array address, and a blankline to help with spacing. The sixth line prints the array and the seventh leaves two blank lines for spacing purposes.

Q2d: First, the program frees a_shallow through a for loop. In this program, a_shallow is the only function that is malloc'd at any point. In a2_q2_lib.c, struct Double_Array * new_array = malloc(sizeof(struct Double_Array)) is contained within this function. The others are freed because the malloc also points to them. However, we don't need a for loop for these variables as they are not directly malloc'd.
