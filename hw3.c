//Neil Gahart
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.h"
#include "menu_options.h"

int main(int argc, char *argv[]){
  if (argc == 0) {
    puts("Need to include file");
  }
  FILE *input = fopen(argv[1],"r");
  if (input == NULL){
    puts("Could not open file");
    return 1;
  }
  int current; //arbitrary initializer
  node *head = {NULL, NULL}; //this will be the linked list of courses
  int counter = 0;
  char line[47];
  while (1){
     current = fgetc (input);
     if (current == EOF){
       break;
      } //end if
      else if (current == '\n'){
	line[counter]='\0';
	//printf("%s \n", line);
	node *new = new_node(line);
	if (head == NULL){
	  head = new;
	}//end if
	else {
	  node *temp = head;
	  while (temp->next != NULL){
	    temp = temp->next;
	  }
	  temp->next = new;
	} //end else
	memset(&line[0], 0, sizeof(line));
	counter = 0;
      } //end else if
      else {
	//printf("%c",current);
	line[counter] = current;
	counter++;
      } //end else
  }//end while

  char choice;
  while(1) {
    printf("Please enter your choice: ");
    scanf("%c", &choice);
    if (!isspace(choice)) {
    choice = toupper(choice);
    if (choice == 'P'){
      do_p(head);
    }//end if
    else if (choice == 'C') {
      do_c(head);
    }
    else if (choice == 'T') {
      do_t(head);
    }
    else if (choice == 'R') {
      do_r(head);
    }
    
    else if (choice == 'Q') {
      return 0;
    }
    else {
      puts("Invalid input");
    }
    }
  } //end while
}//end main
