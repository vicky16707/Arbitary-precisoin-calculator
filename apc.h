#ifndef APC_H
#define APC_H


#define SUCCESS 0
#define NEGATIVE -2
#define FAILURE -1
 

typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
	
}Dlist;
//it is declared as the extern which we can use this in the multiple files
//we dont want to declare this again and again
extern int sign1;
extern int sign2;
void digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[]);

int addition(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

int subtraction(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

int multiplication(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

int division(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);
int insert_last(Dlist **head,Dlist **tail,int data);
int insert_first(Dlist **head,Dlist **tail,int data);
int compare(Dlist **head1,  Dlist **head2);
//adding the two number without thier signs
int add_mag(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR);
//subracting the two number without thier signs
//magnitude means numbers without the signs
int sub_mag(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR);

#endif
