//Neil Gahart

#include <stdio.h>
#include <string.h>
#include "linked_list.h"

int main(int argc, char *argv[]){
  FILE *input = fopen(argv[1],"r");
  if (input == NULL){
    puts("Could not open file");
    return 1;
  }
  int current; //arbitrary initializer
  // struct node courses; //this will be the linked list of courses
  int counter = 0;
  while (1){
    current = fgetc (input);
     if (current == EOF){
       break;
      } //end if
      else if (current == '\n'){
	printf("\n");
	counter = 0;
      } //end else if
      else {
	printf("%c",current);
	counter++;
      } //end else
  }//end first while
  
}//end main
