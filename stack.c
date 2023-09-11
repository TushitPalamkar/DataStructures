#include<stdio.h>
#include<stdlib.h>
struct student
{
    int rollno,marks;
};
struct stack 
{
    unsigned int size;
    unsigned int top;
    struct student * sarr;
};

char isempty(struct stack * s)
{
    if((*s).top==-1)
    return 1;
    else 
    return 0;
}
char isfull(struct stack * s)
{
    if((*s).top==((*s).size-1))
    return 1;
    else
    return 0;
}
void push(struct stack * s , struct student * x)
{
    if((*s).top==(*s).size-1)
    {
        printf("Stack overflow!");
    }
    else{
        (*s).top++;
        (*s).sarr[(*s).top]=*x;
    }
}
void pop(struct stack * s)
{
    struct student temp;
    if((*s).top==-1)
    printf("Stack underflow!");
    else{
    temp=(*s).sarr[(*s).top];
    (*s).top--;
    }
}
void peek(struct stack * s)
{
    if(isempty(s))
    printf("Stack underflow!");
    else
    {
        struct student temp;
        temp=(*s).sarr[(*s).top];
        printf("\n");
        printf("Roll no :%d\n",temp.rollno);
        printf("Marks : %d",temp.marks);
    }
    
    
}
int main()
{
    int choice,x;
    struct stack * st = (struct stack *)malloc(sizeof(struct stack));
    printf("Enter the size of the stack: ");
    scanf("%d",&((*st).size));
    (*st).top=-1;
    struct student * sarr=(struct student *)malloc(sizeof(struct student));
    st->sarr=(struct student *)malloc((st->size)* sizeof(struct student));
    do{
    printf("***********MENU***********\n");
    printf("1.IsEmpty\n2.IsFull\n3.Push\n4.Pop\n5.Peek\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        if(isempty(st)==1)
        printf("Stack is empty\n");
        break;
        case 2:
        if(isfull(st)==1)
        printf("Stack is full\n");
        break;
        case 3:
        printf("Enter the rollno to be pushed: ");
        scanf("%d",&((*sarr).rollno));
        printf("Enter the marks to be pusehd: ");
        scanf("%d",&((*sarr).marks));
    
        push(st,sarr);
        break;
        case 4:
        pop(st);
        break;
        case 5:
        peek(st);
        printf("\n");
        break;
    }
    }while(1);
    
}