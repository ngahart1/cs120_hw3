#include <stdio.h>
#include <string.h>
#include "menu_options.h"
#include "linked_list.h"

void do_p (struct node *cur){
  //Prints all courses in the catalog
  while (cur != NULL){
    print_course(cur);
    cur = cur->next;
  } //end while
} //end do_p

void do_c (struct node *cur) {
  //Print specified course only
  printf("Please enter the course identifier (xx.ddd.nnn): ");
  char identifier[11];
  scanf("%s", identifier);
  char division[3] = {identifier[0], identifier[1], '\0'};
  int department = 100*(identifier[3]-48) + 10*(identifier[4]-48) + (identifier[5]-48);
  int number = 100*(identifier[7]-48) + 10*(identifier[8]-48) + (identifier[9]-48);
  int found = 0;
  while (!found && cur != NULL) {
    int curdept = cur->c.department;
    int curnumber = cur->c.number;
    if (strcmp(cur->c.division, division) == 0 && curdept==department && curnumber==number) {
      printf("%1.1f %s\n", cur->c.credit, cur->c.name);
      found = 1;
    }//end if
    cur = cur->next;
  }//end while
  if (!found){
    puts("Absent");
  }//end if
} //end do_c

void do_t (struct node *cur) {
  printf("Please enter the course identifier (xx.ddd.nnn): ");
  char identifier[11];
  scanf("%s", identifier);
  char division[3] = {identifier[0], identifier[1], '\0'};
  int department = 100*(identifier[3]-48) + 10*(identifier[4]-48) + (identifier[5]-48);
  int number = 100*(identifier[7]-48) + 10*(identifier[8]-48) + (identifier[9]-48);

  char dummy = scanf("%c", &dummy);
  printf("Please enter the desired course title (32 character maximum): ");
  char new_title[33];
  scanf("%[^\n]", new_title);

  int found = 0;
  while (!found && cur != NULL){
    int curdept = cur->c.department;
    int curnumber = cur->c.number;
    if (strcmp(cur->c.division, division) == 0 && curdept==department && curnumber==number) {
      strcpy(cur->c.name, new_title);
      found=1;
    }//end if
    cur = cur->next;
  }//end while
  if (found) {puts("Updated");}
  else {puts("Absent");}
} //end do_t

void do_r (struct node *cur) {
  printf("Please enter the course identifier (xx.ddd.nnn): ");
  char identifier[11];
  scanf("%s", identifier);
  char division[3] = {identifier[0], identifier[1], '\0'};
  int department = 100*(identifier[3]-48) + 10*(identifier[4]-48) + (identifier[5]-48);
  int number = 100*(identifier[7]-48) + 10*(identifier[8]-48) + (identifier[9]-48);

  printf("Please enter the new credit amount: ");
  float new_credit;
  scanf("%f", &new_credit);

  int found = 0;
  while (!found && cur != NULL){
    int curdept = cur->c.department;
    int curnumber = cur->c.number;
    if (strcmp(cur->c.division, division) == 0 && curdept==department && curnumber==number) {
      cur->c.credit = new_credit;
      found=1;
    }//end if
    cur = cur->next;
  }//end while
  if (found) {puts("Updated");}
  else {puts("Absent");}
}//end do_r 
