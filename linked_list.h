//Neil Gahart

#ifndef LINKED_LIST_INCLUDED
#define LINKED_LIST_INCLUDED
typedef struct course {
  char division[3];
  int department;
  int number;
  float credit;
  char name[33];
}Course; //end struct

typedef struct node {
  struct course c;
  struct node *next; //link to successor node
} node; //end struct

typedef struct transcript {
  struct node *n;
  int year;
  char season;
  char grade;
  char grade_extra;
  struct transcript *next;
} transcript;
  
struct node *new_node(const char *input);
void print_course (struct node *cur);
int course_equal (struct node *node1, struct node *node2);
int transc_compare (struct transcript *t1, struct transcript *t2);

#endif
