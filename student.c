#include "stuheader.h"
void main()
{
SLL *headptr=0;
char op;
int c;
while(1)
{
printf("\033[15C\033[4m\033[32m************STUDENT RECORD MENU***********\n\033[0m");
printf("\n\033[15C\033[36ma/A :add new record\n\033[15Cd/D :delete a record\n\033[15Cs/S :show the list\n\033[15Cm/M :modify a Record\n\033[15Cv/V :save\n\033[15Ce/E :exit\n\033[15Ct/T :sort the list\n\033[15Cl/L :delete all the records\n\033[15Cr/R :reverse the list\n\n\033[0m");
printf("Enter your choice:");
while(1){
scanf(" %c",&op);
if(op=='a'||op=='A'||op=='d'||op=='D'||op=='s'||op=='S'||op=='m'||op=='M'||op=='v'||op=='V'||op=='e'||op=='E'||op=='t'||op=='T'||op=='l'||op=='L'||op=='r'||op=='R')
{
break;
}
else
printf("Pls enter correct choice:");
}
switch(op)
{
case 'A':add_end(&headptr);break;
case 'D':delete_node(&headptr);break;
case 'S':print_node(headptr);break;
case 'M':modify_list(headptr);break;
case 'V':save_file(headptr);break;
case 'E':exit(0);
case 'T':sort_list(headptr);break;
case 'L':delete_all(&headptr);break;
case 'R':reverse_list(headptr);
case 'a':add_end(&headptr);break;
case 'd':delete_node(&headptr);break;
case 's':print_node(headptr);break;
case 'm':modify_list(headptr);break;
case 'v':save_file(headptr);break;
case 'e':exit(0);
case 't':sort_list(headptr);break;
case 'l':delete_all(&headptr);break;
case 'r':reverse_list(headptr);break;
}
}
}
/* add at begin*/
void add_end(SLL **ptr)
{
int c;
c=count_node(*ptr);
SLL *new,*last;
new=malloc(sizeof(SLL));
printf("enter name and percentage:\n");
printf("%d ",c+1);
scanf("%s%f",new->name,&new->marks);
new->next=0;
new->rollno=c+1;
if(*ptr==0)
{
*ptr=new;
}
else
{
last=*ptr;
while(last->next)
last=last->next;
last->next=new;
}
}



/* print node */
void print_node(SLL *ptr)
{
printf("**************************************\n");
if(ptr==0)
{
printf("No record found\n");
printf("**************************************\n");
return;
}
else
{
while(ptr)
{
printf("Roll no:%d\nName:%s\nPercentage:%f\n\n",ptr->rollno,ptr->name,ptr->marks);
ptr=ptr->next;
}
}
printf("**************************************\n\n");
}
/*save into file*/
void save_file(SLL *ptr)
{
char ch;
printf("S/s:save and exit\nE/e:exit without saving\n");
while(1)
{
scanf(" %c",&ch);
if(ch=='S'||ch=='s'||ch=='E'||ch=='e')
break;
else
printf("Enter correct choice:");
}
if(ch=='S'||ch=='s')
{
if(ptr==0)
{
printf("no records found\n");
return;
}
FILE *fp;
fp=fopen("student.dat","w");
while(ptr)
{
fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
ptr=ptr->next;
}
printf("data saved in file\n");
fclose(fp);
}
else if(ch=='E'||ch=='e')
{
printf("exiting without saving\n");
exit(0);
}
}
/* read from file*/
void read_file(SLL **ptr)
{
SLL *new,*last;
FILE *fp;
fp=fopen("data","r");
if(fp==0)
{
printf("file is not present\n");
return;
}
while(1)
{
new=malloc(sizeof(SLL));
if(fscanf(fp,"%d%s%f",&new->rollno,new->name,&new->marks)==-1)
break;
new->next=0;
if(*ptr==0)
*ptr=new;
else
{
last=*ptr;
while(last->next)
last=last->next;

last->next=new;
}
}
}
/*count node*/
int count_node(SLL *ptr)
{int c=0;
while(ptr)
{
c++;
ptr=ptr->next;
}
return c;
}
/* sort the data*/
void sort_list(SLL *ptr)
{
char ch;
printf("Enter\nN/n:sort with name\nP/p:sort with percentage\n");
while(1)
{
scanf(" %c",&ch);
if(ch=='N'||ch=='n'||ch=='P'||ch=='p')
break;
else
printf("Enter correct choice\n");
}
if(ch=='N'||ch=='n')
sort_name(ptr);
else if(ch=='P'||ch=='p')
sort_percent(ptr);
}
void sort_percent(SLL *ptr)
{int c,i,j;
SLL temp,*p1=ptr,*p2;
if(ptr==0){
printf("no data\n");
return;
}
c=count_node(ptr);
for(i=0;i<(c-1);i++)
{p2=p1->next;
for(j=0;j<c-i-1;j++)
{
if(p2->marks>p1->marks)
{
temp.rollno=p1->rollno;
strcpy(temp.name,p1->name);
temp.marks=p1->marks;

p1->rollno=p2->rollno;
strcpy(p1->name,p2->name);
p1->marks=p2->marks;

p2->rollno=temp.rollno;
strcpy(p2->name,temp.name);
p2->marks=temp.marks;
}
p2=p2->next;
}
p1=p1->next;
}
}

void sort_name(SLL *ptr)
{int c,i,j;
SLL temp,*p1=ptr,*p2;
if(ptr==0){
printf("no data\n");
return;
}
c=count_node(ptr);
for(i=0;i<(c-1);i++)
{p2=p1->next;
for(j=0;j<c-i-1;j++)
{
if(strcmp(p2->name,p1->name)<0)
{
temp.rollno=p1->rollno;
strcpy(temp.name,p1->name);
temp.marks=p1->marks;

p1->rollno=p2->rollno;
strcpy(p1->name,p2->name);
p1->marks=p2->marks;

p2->rollno=temp.rollno;
strcpy(p2->name,temp.name);
p2->marks=temp.marks;
}
p2=p2->next;
}
p1=p1->next;
}
}
void reverse_list(SLL *ptr)
{int c,i,j;
SLL temp,*p1=ptr,*p2;
if(ptr==0){
printf("no data\n");
return;
}
c=count_node(ptr);
for(i=0;i<(c/2);i++)
{p2=ptr;
for(j=0;j<c-i-1;j++)
p2=p2->next;

temp.rollno=p1->rollno;
strcpy(temp.name,p1->name);
temp.marks=p1->marks;

p1->rollno=p2->rollno;
strcpy(p1->name,p2->name);
p1->marks=p2->marks;

p2->rollno=temp.rollno;
strcpy(p2->name,temp.name);
p2->marks=temp.marks;
p1=p1->next;
}
}
/* delete all */
void delete_all(SLL **ptr)
{
if(*ptr==0)
{
printf("no records present\n");
return;
}
int c=0;
SLL *del;
del=*ptr;
while(del)
{
*ptr=del->next;
free(del);
sleep(1);
printf("record:%d deleted\n",++c);
del=*ptr;
}
printf("All records are deleted\n");
}
void delete_node(SLL **ptr)
{char ch;
	printf("R/r:enter rollno to delete\nN/n:Enter name to delete\n");
	while(1){
	scanf(" %c",&ch);
		if(ch=='R'||ch=='r'||ch=='N'||ch=='n')
			break;
		else
			printf("Enter correct choice:");
	}
	switch(ch)
	{
		case 'R':delete_rollno(ptr);break;
		case 'r':delete_rollno(ptr);break;
		case 'N':delete_name(ptr);break;
		case 'n':delete_name(ptr);break;
	}
}
void delete_rollno(SLL **ptr)
{
	if(*ptr==0)
	{
		printf("No records present\n");
		return;
	}
	int num;
	printf("Enter the rollno to delete:");
	scanf("%d",&num);
	SLL *del=*ptr;
	SLL *prev;
	while(del)
	{
		if(del->rollno==num)
		{
			if(del==*ptr)
				*ptr=del->next;
			else
				prev->next=del->next;
			printf("Record deleted\n");
			free(del);
			return;
		}
		prev=del;
		del=del->next;
	}
	printf("rollno not present\n");
}
void delete_name(SLL **ptr)
{
	int c=0;
	if(*ptr==0)
	{
		printf("No records present\n");
		return;
	}
	char num[20];
	printf("enter the name to delete:");
	scanf("%s",num);
	SLL *del=*ptr;
	SLL *prev;
	while(del)
	{
		if(strcmp(del->name,num)==0)
			c++;
		del=del->next;
	}
	del=*ptr;
	if(c>1)
	{	
		printf("\nMore than 1 record present with same name\n");
		printf("********************************\n");
		while(del)
		{
			if(strcmp(del->name,num)==0)
				printf("Rollno:%d\nname:%s\nPercentage:%f\n\n",del->rollno,del->name,del->marks);
			del=del->next;
		}
		printf("*********************************\n");
		delete_rollno(ptr);
		return;
	}
	else if(c==1)
	{
		while(del)
		{
			if(strcmp(del->name,num)==0)
			{
				if(del==*ptr)
					*ptr=del->next;
				else
					prev->next=del->next;
				free(del);
				printf("Record deleted\n");
				return;
			}
			prev=del;
			del=del->next;
		}
		printf("name not present\n");
	}
}
void modify_list(SLL *ptr)
{
char ch;
printf("Enter Which record to search for modification\n");
printf("R/r:to search roll no\nN/n:to search a name\nP/p:percentage based\n");
while(1)
{
scanf(" %c",&ch);
if(ch=='R'||ch=='r'||ch=='N'||ch=='n'||ch=='P'||ch=='p')
break;
else
printf("Enter correct choice:\n");
}
if(ch=='R'||ch=='r')
modify_rollno(ptr);
else if(ch=='N'||ch=='n')
modify_name(ptr);
else if(ch=='P'||ch=='p')
modify_percent(ptr);
}
void modify_rollno(SLL *ptr)
{
	if(ptr==0)
	{
		printf("No records present\n");
		return;
	}
	int num;
	printf("Enter the rollno to modify:");
	scanf("%d",&num);
	SLL *mod=ptr;
	while(mod)
	{
		if(mod->rollno==num)
		{
		printf("Enter the new name and marks:\n");
		scanf("%s%f",mod->name,&mod->marks);
		printf("modified\n");
		return;
		}
		mod=mod->next;
	}
	printf("rollno not present\n");
}
void modify_name(SLL *ptr)
{
	if(ptr==0)
	{
		printf("No records present\n");
		return;
	}
	char num1[20];
	int c=0;
	SLL *mod=ptr;
	printf("Enter the name to modify:");
	scanf("%s",num1);
	while(mod)
	{
		if(strcmp(mod->name,num1)==0)
			c++;
		mod=mod->next;
	}
	mod=ptr;
	if(c>1)
	{	
		printf("\nMore than 1 record present with same name\n");
		printf("********************************\n");
		while(mod)
		{
			if(strcmp(mod->name,num1)==0)
				printf("Rollno:%d\nname:%s\nPercentage:%f\n\n",mod->rollno,mod->name,mod->marks);
			mod=mod->next;
		}
		printf("*********************************\n");
	modify_rollno(ptr);
	}
	else if(c==1)
	{
	while(mod)
	{
		if(strcmp(mod->name,num1)==0)
		{
		printf("Enter the new name and marks:\n");
		scanf("%s%f",mod->name,&mod->marks);
		printf("modified\n");
		return;
		}
		mod=mod->next;
	}
	printf("name not matched\n");
	}
}

void modify_percent(SLL *ptr)
{
	if(ptr==0)
	{
		printf("No records present\n");
		return;
	}
	float num1;
	int c=0;
	SLL *mod=ptr;
	printf("Enter percentage to modify\n");
	scanf("%f",&num1);
	while(mod)
	{
		if((mod->marks==num1))
			c++;
		mod=mod->next;
	}
	mod=ptr;
	if(c>1)
	{	
		printf("\nMore than 1 record present with same name\n");
		printf("********************************\n");
		while(mod)
		{
			if(mod->marks==num1)
				printf("Rollno:%d\nname:%s\nPercentage:%f\n\n",mod->rollno,mod->name,mod->marks);
			mod=mod->next;
		}
		printf("*********************************\n");
	modify_rollno(ptr);
	}
	else if(c==1)
	{
	while(mod)
	{
		if(mod->marks==num1)
		{
		printf("Enter the new name and marks:\n");
		scanf("%s%f",mod->name,&mod->marks);
		printf("modified\n");
		return;
		}
		mod=mod->next;
	}
	printf("percentage not matched\n");
	}
}
