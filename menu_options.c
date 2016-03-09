#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menu_options.h"
#include "linked_list.h"

void do_a (struct transcript *t, struct node *cur) {
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
      found = 1;
      break; //is this the thing to do??????????????
    }//end if
    cur = cur->next;
  }//end while
  if (!found){
    puts("Invalid");
    return;
  }//end if
  printf("Please enter the semester (yyyy.s): ");
  char sem[7];
  scanf("%s", sem);
  int semester = 1000*(sem[0]-48)+100*(sem[1]-48)+10*(sem[2]-48)+(sem[3]-48);
  char season = sem[5];
  printf("Please enter grade (Gg): ");
  char Gg[3];
  char grade = Gg[0];
  char grade_extra = Gg[1];
  struct transcript *fresh = malloc(sizeof(struct transcript));
  if (fresh == NULL){
    puts("Failed to allocate a node");
    return;
  } //end if

  fresh->n = cur; ////////ERROR POSSIBILITY
  fresh->year = semester;
  fresh->season = season;
  fresh->grade = grade;
  fresh->grade_extra = grade_extra;
  fresh->next = NULL; //initializer
  
  //Now, need to go through and insert new node in appropriate place
  if (t == NULL) {
    t = fresh;
  } //end if
  else {
    //int inserted = 0;
    transcript *temp = t;
    if (temp->next == NULL) { //this is the case of only a single node in the list
      int comp = transc_compare(fresh, temp);
      if (comp == -100) {
	puts("present");
      }
      else if (comp == 0 || comp == 1) {
	fresh->next = temp;
	puts("added");
	return;
      }
      else { //comp == 2
	temp -> next = fresh;
	puts("added");
	return;
      } //end else
    } //end if
    else { //ie at least two nodes in the list
      if (transc_compare(temp, fresh) == 2 || transc_compare(temp, fresh) == 0){
	//in this case, fresh should go at the front of the list
	fresh->next = temp;
      }
      transcript *temp2 = temp->next;
      while (1) {  
	//int comp_before = transc_compare(temp, fresh);
	int comp_after = transc_compare(temp2, fresh);
	if (comp_after == -100) {
	  puts("present");
	  return;
	}
	if (comp_after == 0 || comp_after == 2) {
	  temp->next = fresh;
	  fresh->next = temp2;
	  puts("added");
	  return;
	} //end if
	else if (temp2->next == NULL) { //temp2 is last node in list
	  if (comp_after == 1) {
	    temp2->next = fresh;
	    puts("added");
	    return;
	  } //end if
	} //end else if
	else { 
	  temp = temp->next;
	  temp2 = temp2->next;
	}
      }//end while
    }//end else
  }//end else
}//end do_a

void do_p (struct node *cur){
  //Prints all courses in the catalog
  while (cur != NULL){
    print_course(cur);
    cur = cur->next;
  } //end while
  char dummy;
  scanf("%c", &dummy);
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

  char dummy = scanf("%c", &dummy); //gets the newline character
  printf("Please enter the desired course title (32 character maximum): ");
  char new_title[33];
  scanf("%[^\n]", new_title);
  dummy = scanf("%c", &dummy); //gets the newline character
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
  char dummy;
  scanf("%c", &dummy); //gets newline character
  
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
