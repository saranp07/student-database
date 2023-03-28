#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
typedef struct student{
int rollno;
char name[20];
float marks;
struct student *next;
}SLL;
void add_begin(SLL **);
void print_node(SLL *);
void add_end(SLL **);
void add_middle(SLL **);
void save_file(SLL *);
void read_file(SLL **);
int count_node(SLL *);
void sort_list(SLL *);
void sort_name(SLL*);
void sort_percent(SLL *);
void reverse_list(SLL *);
void modify_list(SLL *);
void modify_rollno(SLL *);
void modify_name(SLL *);
void modify_percent(SLL *);
void delete_all(SLL **);
void delete_node(SLL **);
void delete_rollno(SLL **ptr);
void delete_name(SLL **ptr);
