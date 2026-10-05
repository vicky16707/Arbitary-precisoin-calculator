#include "apc.h"
#include<stdio.h>
#include<stdlib.h>

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    if(*head2==NULL)return FAILURE;
    //for zero as a divisor
    if((*head2)->data == 0 && (*head2)->next == NULL)
        return FAILURE;

    Dlist  *temp1=*head1;

    int flag=0,count=0;

    Dlist *temph=NULL,*tempt=NULL;
    Dlist *subh=NULL,*subt=NULL;

    while(temp1!=NULL)
    {
        if(temph==NULL)
        {
            insert_last(&temph,&tempt,temp1->data);

        }
        else
        {
            if(temph->data == 0 && temph == tempt)
                temph->data=temp1->data;
            else
                insert_last(&temph,&tempt,temp1->data);

        }
        count=0;
        while(temph!=NULL&&compare(&temph, head2)>=0)
        {
            subh=NULL;
            subt=NULL;

            sub_mag(&temph,&tempt,head2,tail2,&subh,&subt);
            Dlist *temp = temph;
            //free temp
            while(temp != NULL)
            {
                Dlist *next = temp->next;
                free(temp);
                temp = next;
            }
            temph=subh;
            tempt=subt;

            count++;
        }
        //adding quotient for the final result
        if(count!=0||flag)
        {
            
            insert_last(headR,tailR,count);
            // if((*headR)->data==0)
            // {
            //    *headR=(*headR)->next;
            //    (*headR)->prev=NULL;
            //     free(t);
            // }

            flag=1;
        }
        temp1=temp1->next;
    }
    if(*headR==NULL) insert_last(headR,tailR,0);
    
     while(*headR != NULL &&
          (*headR)->data == 0 &&
          (*headR)->next != NULL)
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
