#include "apc.h"
#include<stdio.h>

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
    //same sign
    if(sign1==sign2){
        add_mag(head1, tail1,head2, tail2,headR, tailR);
        if(sign1==-1)
            return NEGATIVE;
        return SUCCESS;
    }
    int cmp = compare(head1, head2);
    //different sign
    sub_mag(head1, tail1,head2, tail2,headR, tailR);

    if(cmp == 0){
        return SUCCESS;
    }

    if(cmp > 0){
        if(sign1 == -1)
            return NEGATIVE;
    }
    else{
        if(sign1 == 1)
            return NEGATIVE;
    }

    return SUCCESS;
	
}
int add_mag(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR)
{
    Dlist *temp1=*tail1;
    Dlist *temp2=*tail2;
    int carry=0,data=0;
    
    while(temp1||temp2)
    {
        if(temp1!=NULL && temp2!=NULL){

            data=temp1->data+temp2->data+carry;
            insert_first(headR,tailR,(data%10));
            carry=data/10;
            temp1=temp1->prev;
            temp2=temp2->prev;
        }
        else if(temp1!=NULL){
            
            data=temp1->data+carry;
            insert_first(headR, tailR, data % 10);

            carry = data / 10;

            temp1 = temp1->prev;
        }
        else if(temp2!=NULL){

            data=temp2->data+carry;
            insert_first(headR, tailR, data % 10);

            carry = data / 10;

            temp2 = temp2->prev;
        }
        
        
    }
    if(carry){
        insert_first(headR,tailR,carry);      
    }
    return SUCCESS;
}
