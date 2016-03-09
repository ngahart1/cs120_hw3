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
  
int transc_compare (struct transcript *t1, struct transcript *t2) {
  //Wish to determine which of the two nodes comes first
  //-100: nodes are exactly the same
  //0: nodes are from same semester
  //1: t1 is from earlier semester
  //2: t2 is from earlier semester
  int year_diff = t1->year - t2->year; //if 0, same. if >0, t1 is later. if <0, t2 is later
  int season_diff = t1->season - t2->season; //if 0, same. if >0, t1 is spring and t2 is fall.
  int same_course = course_equal(t1->n, t2->n); //1 if nodes are same, 0 otherwise
  if (year_diff==0 && season_diff==0 && same_course==1) {
    return -100;
  }
  else if (year_diff == 0 && season_diff == 0) {
    return 0;
  }
  else {
    if (year_diff > 0) {
      return 2;
    }
    else if (year_diff < 0) {
      return 1;
    }
    else { //year_diff == 0
      if (season_diff > 0) {
	return 1;
      }
      else if (season_diff < 0) {
	return 2;
      }
      else { //year_diff == 0 and season_diff == 0
	return 0;
      } //end else
    } //end else
  } //end else 
} //end transc_compare
