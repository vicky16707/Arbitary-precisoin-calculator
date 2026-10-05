#include "apc.h"
#include<stdio.h>
#include<stdlib.h>

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{   //same sign
    if(sign1 == sign2)
    {
        int cmp = compare(head1, head2);

        sub_mag(head1, tail1,head2, tail2,headR, tailR);

        if(cmp == 0){
            return SUCCESS;
        }
        if(sign1 == 1){
            if(cmp < 0)
                return NEGATIVE;
        }
        else{
            if(cmp > 0)
                return NEGATIVE;
        }

        return SUCCESS;
    }
    //different sign
    add_mag(head1, tail1,head2, tail2,headR, tailR);
    if(sign1 == -1){
        return NEGATIVE;
    }

    return SUCCESS;
  
}
int sub_mag(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR){
    Dlist *temp1;
    Dlist *temp2;

    int borrow=0,data,result;

    result=compare(head1,head2);
    if(result == 0){                                                                                                            
        insert_first(headR,tailR,0);       
        return SUCCESS;
    }
    if(result>0){
        temp1=*tail1;
        temp2=*tail2;
    }
    else {
        temp1=*tail2;
        temp2=*tail1;
        
        
    }
     while(temp1 != NULL)
    {
        data = temp1->data - borrow;
        if(temp2 != NULL) {
            data = data - temp2->data;
            temp2 = temp2->prev;
        }

        if(data < 0)
        {
            data = data + 10;
            borrow = 1;
        }
        else{
            borrow = 0;
        }
        insert_first(headR, tailR, data);
        temp1 = temp1->prev;
    }

    while(*headR != NULL &&
          (*headR)->data == 0 &&
          (*headR)->next != NULL)
    {
        Dlist *temp = *headR;

        *headR = (*headR)->next;

        (*headR)->prev = NULL;

        free(temp);
    }

    return SUCCESS;
}