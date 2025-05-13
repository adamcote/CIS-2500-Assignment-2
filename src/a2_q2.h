#include <stdio.h>
#include <stdlib.h>
#include "a2_q1.h"


struct Double_Array * shallow_copy(struct Double_Array * to_copy);
struct Double_Array * deep_copy (struct Double_Array * to_copy);
void print_struct(struct Double_Array * to_copy, char * header);