#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node * next;
    int data;
   
   
};
struct stack{
struct node * top;
};
 

char isempty(struct stack * s)
{
    if((*s).top==NULL)
    {
        return 1;
   
    }
    else
    return 0;
}
void push(struct stack *s, struct node * n )
{
    
    
    (*n).next=(*s).top;
    (*s).top=n;

   
}
struct node pop(struct stack * s)
{
    struct node * n;
    struct node temp;
    n=(*s).top;
    (*s).top=(*n).next;
    temp = *n;
    free(n);
}

struct node * peek(struct stack * s)
{
    printf("%d", (*(*s).top).data);
}
int main()
{
    int opchoice;
    struct stack * st;
    struct stack S;
    st= &S;

    
    while(1)
  {

    printf("*********************MENU*********************\n");   
    do{
    
    printf("1.Push\n2.Pop\n3.Peek\n4.isempty\n");
    scanf("%d", &opchoice);
    
    switch(opchoice)
    {
      case 1:
        struct node * n;
        n=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data of new node: ");
        scanf("%d", &((*n).data));
        

        push(st,n);
                
        break;

      case 2:
        if( (isempty(st)==1))
        {
          printf("Selected stack is empty. Can not pop an empty stack.\n");
        }
        else
        {
                    struct node nd;
           nd= pop(st);
        }
        break;
      case 3:
        if( (isempty(st)==1))
        {
          printf("Selected stack is empty. Can not peek in an empty stack.\n");
        }
        else
        {  
                    struct node * n;
          n=peek(st);
          printf("\n");
        }
        break;
      case 4:
      if((isempty(st)==1))
      {
          printf("Empty stack\n");
      }
      else
      printf("Stack is not empty\n");
    }
    }while(1);
  }
  return 0;
}