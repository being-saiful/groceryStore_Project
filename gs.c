#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#define max 5000


struct node
{   int data;
    struct node *forward;
    struct node *backward;
}*first,*store;
int main()
{
    int n,choice,data,str;
    while(1)
    {
        printf("Press 1 to show available products : \n");
        printf("Press 2 to create your shopping list : \n");
        printf("Press 3 to display the bill : \n");
        printf("Press 4 to exit from the portal : \n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1 :
            printf("Available products are : %s ",avilableproducts());
            getchar();
            break;
        case 2 :
            printf("How many products do you want to buy : ");
            scanf("%d",&n);
            createlist(n);
            break;
        case 3 :

        case 4 :
            exit(0);
            break;
        default :
            printf("Press 1,2 or 3 ");
        }
    }
}
void createlist(int n)
{
    struct node *newnode,*store;
    int i,data;
    first=(struct node *)malloc(sizeof(struct node));
    if(first==NULL)
    {
        printf("Can't store data");
    }
    else
    {
        printf("Enter data for node 1 : ");
        scanf("%d",&data);
        first->data=data;
        first->forward=NULL;
        store=first;
        for(i=2;i<=n;i++)
        {
            newnode=(struct node *)malloc(sizeof(struct node));
            if(newnode==NULL)
            {
                printf("Can't store data");
                break;
            }
            else
            {
                printf("Enter data for node %d : ",i);
                scanf("%d",&data);
                newnode->data=data;
                newnode->backward=store;
                newnode->forward=NULL;
                store->forward=newnode;
                store=store->forward;
            }
        }
    }
    printf("LIST CREATED SUCCESSFULLY \n");
}
void displaylist()
{
    struct node *store;
    if(first==NULL)
    {
        printf("ERROR!");
    }
    else
    {
        store=first;
        while(store!=NULL)
        {
            printf("Your anticipated data = %d \n",store->data);
            store=store->forward;
        }
    }
}
char *availableproducts()
{
    int max = 100;
    char *str=(char *)malloc(sizeof(char)*max);
    *(str+0)="Biscuits";
    *(str+1)="Cold Drinks";
    *(str+2)="Chips";
    *(str+3)="Chocolates";
    *(str+4)='\0';
    return str;
}

