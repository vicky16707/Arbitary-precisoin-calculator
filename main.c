/*-------------------------------------------------------------------------------------------------------------------------------------------
TITLE        : Arbitrary Precision Calculator (APC)

Description :
              This project implements an Arbitrary Precision Calculator using
              doubly linked lists. It performs arithmetic operations on very
              large numbers that cannot be handled by the normal integer data
              types in C.

              Each digit of the number is stored in a node of a doubly linked
              list. The project supports addition, subtraction, multiplication,
              and division of large numbers.

              The project also handles positive and negative numbers by
              maintaining the sign separately from the magnitude of the number.

Features    :
              1. Perform addition of large numbers.
              2. Perform subtraction of large numbers.
              3. Perform multiplication of large numbers.
              4. Perform division of large numbers.
              5. Perform arithmetic operations beyond the range of standard C integer data types.

Data Structure:
              Double Linked List

Operations  :
              +  Addition
              -  Subtraction
              x  Multiplication
              /  Division

Start Date  : 27/8/2026
End Date    : 06/9/2026

Name        : Vignesh .N
Register_no : 26010_020
--------------------------------------------------------------------------------------------------------------------------------------------*/
#include "apc.h"
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int sign1=1,sign2=1;
int main(int argc,char *argv[])
{
	if(argc != 4)
    {
        printf("Usage: ./APC.out number1 operator number2\n");
        return 0;
    }
      
	Dlist *head1=NULL, *tail1=NULL;
    Dlist *head2=NULL, *tail2=NULL; 
    Dlist *headR=NULL,*tailR=NULL;


	char operator = argv[2][0];
	char str1[100],str2[100];
	strcpy(str1,argv[1]);
	strcpy(str2,argv[3]);
	//first number
	sign1=1;
	int start1=0;
	if(str1[0]=='+'){
		sign1=1;
		start1=1;
	}
	else if(str1[0]=='-'){
		sign1=-1;
		start1=1;
	}
	//second number
	sign2=1;
	int start2=0;
	if(str2[0]=='+'){
		sign2=1;
		start2=1;
	}
	else if(str2[0]=='-'){
		sign2=-1;
		start2=1;
	}


	char *temp_argv[4];
	temp_argv[0]=argv[0];
	temp_argv[1]=str1+start1;
	temp_argv[2]=argv[2];
	temp_argv[3]=str2+start2;

	digit_to_list(&head1, &tail1,&head2, &tail2,temp_argv);
	int result=SUCCESS;

	switch (operator)
	{
		case '+':

			result=addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
			
			break;

		case '-':	

			result=subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR);
			
			
			break;

		case 'x':	

			result=multiplication(&head1,&tail1,&head2,&tail2,&headR,&tailR);
			break;
			

		case '/':
			result=division(&head1,&tail1,&head2,&tail2,&headR,&tailR);
			
			
			break;

		default:
			printf("Invalid Input:-( Try again...\n");
			return 0;
	}


	if(result==FAILURE){
		printf("Error: Division by zero\n");
	}
	
	if(result==NEGATIVE) printf("-");
	if(headR!=NULL){
		Dlist *temp=headR;
		while(temp != NULL)
		{
			printf("%d", temp->data);
			temp= temp->next;
		}
		
	}
	printf("\n");
	
	return 0;
}
	


//converts the argv alues to the linked list
void digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[]){

	int i=0,data;

	char *str1=argv[1];
	while(str1[i]!='\0'){
		if(isdigit(str1[i])){
			data=str1[i]-'0';
		}
		else if(str1[i]>='a'&&str1[i]<='f'){
			data=str1[i]-'a'+10;
		}
		else if(str1[i]>='A'&&str1[i]<='F'){
			data=str1[i]-'A'+10;
		}
		else{
			i++;
			continue;
		}
		insert_last(head1,tail1,data);
		i++;
	}

	i=0;

	char *str2=argv[3];
	while(str2[i]!='\0'){
		if(isdigit(str2[i])){
			data=str2[i]-'0';
		}
		else if(str2[i]>='a'&&str2[i]<='f'){
			data=str2[i]-'a'+10;
		}
		else if(str2[i]>='A'&&str2[i]<='F'){
			data=str2[i]-'A'+10;
		}
		else{
			i++;
			continue;
		}
		insert_last(head2,tail2,data);
		i++;
	}


}
//insert a new node at the beginning of hte list
int insert_last(Dlist **head,Dlist **tail,int data){
	
	Dlist *new=malloc(sizeof(Dlist));
	if(!new)return FAILURE;

	new->data=data;
	if(*head==NULL&&*tail==NULL){
		new->prev=NULL;
		new->next=NULL;
		*head=new;
		*tail=new;
		return SUCCESS;
	}
	Dlist *temp=*tail;
	
	new->next=NULL;
	new->prev=temp;
	temp->next=new;
	
	*tail=new;
	return SUCCESS;

}
//insert a new node at the end of hte list
int insert_first(Dlist **head,Dlist **tail,int data){
	Dlist *new=malloc(sizeof(Dlist));
	if(!new)return FAILURE;

	new->data=data;
	if(*head==NULL&&*tail==NULL){
		new->prev=NULL;
		new->next=NULL;
		*head=new;
		*tail=new;
		return SUCCESS;
	}
	Dlist *temp=*head;
	
	new->prev=NULL;
	new->next=temp;
	temp->prev=new;
	
	*head=new;
	return SUCCESS;

}
//comare the two numbers which is greatest
int compare(Dlist **head1,  Dlist **head2)
	{
		int count1=0,count2=0;
		
		Dlist *temp1=*head1;
		Dlist *temp2=*head2;

		while(temp1){
			count1++;
			temp1=temp1->next;
		}
		while(temp2){
			count2++;
			temp2=temp2->next;
		}

		temp1=*head1;
		temp2=*head2;

		if(count1>count2) return 1;
		if(count1<count2) return -1;

		if(count1==count2) {
				while(temp1 != NULL)
			{

				if(temp1->data>temp2->data) return 1;
				if(temp1->data<temp2->data) return -1;
				temp1=temp1->next;
				temp2=temp2->next;
			}
		}

		return 0;
	}


