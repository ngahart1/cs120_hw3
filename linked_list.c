//Neil Gahart
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"


struct node *new_node (const char *input) {
  //input is one line of input from the text file. ex: EN.550.171 4.0 Discrete Mathematics
  //returns a node with correct payload and a successor pointer to NULL
  struct node *fresh = malloc(sizeof(struct node));
  if (fresh == NULL){
    puts("Failed to allocate a node");
    return NULL;
  } //end if

  //Get division
 
  char division[3];
  division[0] = input[0];
  division[1] = input[1];
  division[2] = '\0';
  strcpy(fresh->c.division, division);

  int department = 0;
  department += (input[3]-48)*100;
  department += (input[4]-48)*10;
  department += (input[5]-48)*1;
  fresh->c.department = department;

  int number = 0;
  number += (input[7]-48)*100;
  number += (input[8]-48)*10;
  number += (input[9]-48)*1;
  fresh -> c.number = number;

  float credit=0;
  credit += (input[11]-48)*1;
  credit += (input[13]-48)*.1;
  fresh -> c.credit = credit;
  
  char name[33];
  for (int i=15; i<15+32; i++) {
      name[i-15] = input[i];
  }//end for
  name[32] = '\0';
  strcpy(fresh->c.name, name);
  
  fresh->next = NULL;
  return fresh;
} //end new_node

void print_course (struct node *cur) {
    printf("%s", cur->c.division);
    printf(".%d.%d %1.1f %s\n", cur->c.department, cur->c.number, cur->c.credit, cur->c.name);
}//end print_courses

int course_equal (struct node *node1, struct node *node2) {
  //returns 1 if the two input nodes are the same, 0 otherwise
  int ok=1;
  if (strcmp(node1->c.division, node2->c.division) != 0) {ok=0;}
  if (node1->c.department != node2->c.department) {ok=0;}
  if (node1->c.number != node2->c.number) {ok=0;}
  if (node1->c.credit != node2->c.credit) {ok=0;}
  if (strcmp(node1->c.name, node2->c.name) != 0) {ok=0;}
  return ok;
}//end course_equal
  
    
