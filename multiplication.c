#include "apc.h"
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>


int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	Dlist *temp1;//temp to the tail1
    Dlist *temp2;//temp to the tail2
    Dlist *l3h=NULL,*l3t=NULL;
    

    
    int data=0,carry,count=0;
    for (temp2 = *tail2; temp2 != NULL; temp2 = temp2->prev)
    {
        temp1=*tail1;
        carry=0;
        l3h = NULL;
        l3t = NULL;
        //tail data multiply with all hte nodes at temp1
        while ( temp1 != NULL)
        {
            data=temp1->data * temp2->data + carry;
            insert_first(&l3h,&l3t,(data%10));
            carry=data/10;
            temp1=temp1->prev;
        }
        if(carry!=0){
            insert_first(&l3h,&l3t,carry);
        }
        //adding hte zeros fo the next next iterations
        for (int i = 0; i < count; i++)
        {
            insert_last(&l3h, &l3t, 0);
        }
        //temp product value
        if(*headR==NULL){
            *headR=l3h; 
            *tailR=l3t;

        }
        else{
            Dlist *tempH = NULL;
            Dlist *tempT = NULL;

            add_mag(headR, tailR,
                     &l3h, &l3t,
                     &tempH, &tempT);

            Dlist *temp = *headR;
                //freeing the temp
            while (temp != NULL)
            {
                Dlist *next = temp->next;
                free(temp);
                temp = next;
            }
            temp = l3h;

            while(temp != NULL)
            {
                Dlist *next = temp->next;
                free(temp);
                temp = next;
            }

            l3h = NULL;
            l3t = NULL;

            *headR = tempH;
            *tailR = tempT;


        }
        count++;
    }
    while(*headR != NULL && (*headR)->data == 0 && (*headR)->next != NULL)
    {
        Dlist *temp = *headR;

        *headR = (*headR)->next;

        (*headR)->prev = NULL;

        free(temp);
    }


    if(sign1 != sign2)
        return NEGATIVE;
    return SUCCESS;



}
