#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node * next;
    int data;
};
struct sll
{
    struct node * head;
};

char isempty(struct sll * l)
{
    if((*l).head==NULL)
    {
    return 1;
    }
    else
    return 0;    
}
void traverse(struct sll * a)
{
    struct node * n;
    n= (*a).head;
    while(n!=NULL)
    {
        printf("%2d",n->data);
        n=n->next;
    }

}
void addfront(struct sll * b, struct node * s)
{
    
    (*s).next=(*b).head;
    (*b).head=s;
}
void addend(struct sll * c , struct node * m)
{
    struct node * n;

    
    n=(*c).head;
    while((*n).next!=NULL)
    {
        n=(*n).next;
    }
    (*n).next=m;
}
void deletefront(struct sll * p)
{
    struct node * x;
    x=(*p).head;
    (*p).head=(*(*p).head).next;
    free(x);
}
void deleteend(struct sll * k)
{
    struct node * n;
    struct node * m;
   (*m).next=NULL;
    n= (*k).head;
    while(n->next!=m)
    {
        n=(*n).next;
    }
    (*n).next=NULL;
    free(m);
}
void main()
{
    int choice;
    struct node * n;
    struct sll * s;
    struct sll S;
    s=&S;
    (*s).head=NULL;
    n=NULL;
    while(1)
    {
    printf("****************MENU****************\n");
    do{
    printf("1.isempty\n2.Traverse\n3.addfront\n4.addend\n5.deletefront\n6.deleteend\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: 
        
        if(isempty(s)==1)
        printf("Empty list\n");
        break;

        case 2: 
        if(isempty(s)==1)
        printf("Can't be traversed\n");
        else
        {
        traverse(s);
        printf("\n");
        }
        break;

        case 3: 
        
        struct node * n =(struct node *)malloc(sizeof(struct node));
        printf("Enter the data to be added: ");
        scanf("%d",&n->data);
        (*n).next=NULL;
        if((*s).head==NULL)
        printf("List is empty, adding in the front of the list");
        else
        addfront(s,n);
        break;

        case 4: 
    
        struct node * m =(struct node *)malloc(sizeof(struct node));
        printf("Enter the data to be added:");
        scanf("%d",&((*m).data));
        (*m).next=NULL;
        if((*s).head==NULL)
        printf("List is empty, adding at the end");
        else
        addend(s,m);
        break;

        case 5: 
        if((*s).head==NULL)
        printf("List is empty, cannot delete from the front of the list");
        else
        deletefront(s);
        break;

        case 6: 
        if((*s).head==NULL)
        printf("List is empty, cannot delete from the end of the list");
        else
        deleteend(s);
        break;

    }
    }while(1);
}
}