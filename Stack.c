#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct node{
 char val;
 struct node *lchild, *rchild;
} NODE;


typedef struct node1{
 NODE * data;
 struct node1 * next;
} STACK;



STACK * top = NULL;

NODE * CreateNode(char val){
 NODE * ptr = (NODE *) malloc(sizeof(NODE));
 ptr -> val = val;
 ptr -> lchild = NULL;
 ptr -> rchild = NULL;
 return ptr;
}



void push(NODE * node){
  STACK * p = (STACK *) malloc(sizeof(STACK));
  p -> data = node; 
  if(top == NULL)  
        p -> next = NULL;     
  else   
        p -> next = top;   
  top=p; 
}

NODE * pop()  
{  
    NODE * item;  
    STACK *ptr = top;  
    if (top == NULL)   
        printf("Underflow");  
    else  
    {  
        item = top->data;  
        top = top->next;  
        free(ptr);    
    }  
    return item;
}  

void display()  
{  
    int i;  
    STACK *ptr = top;
    if(ptr == NULL)  
    {  
        printf("Stack is empty\n");  
    }  
    else  
    {  
        while(ptr!=NULL)  
        {  
            printf("%c ",ptr->data -> val);  
            ptr = ptr->next;  
        }  
        printf("\n");
    }  
}  

void inorder(NODE * root)
{
   if(root != NULL)
   {
     inorder(root -> lchild);
     printf("%c ", root -> val);
     inorder(root -> rchild);
   }
}

void preorder(NODE * root)
{
   if(root != NULL)
   {
     printf("%c ", root -> val);
     preorder(root -> lchild);
     preorder(root -> rchild);
   }
}

void postorder(NODE * root)
{
   if(root != NULL)
   {
     postorder(root -> lchild);
     postorder(root -> rchild);
     printf("%c ", root -> val);
   }
}



NODE * postfix()
{
  char Exp[100];
  printf("Enter the POSTFIX Expression : ");
  scanf("%s", Exp);
  
  int i = 0;
  for(i = 0 ; i < strlen(Exp); i++){
     if(isalpha(Exp[i]))
        push(CreateNode(Exp[i]));
     else{
       NODE * operand = CreateNode(Exp[i]);
       operand -> rchild = pop();
       operand -> lchild = pop();
       push(operand);
     }
     display();
  }
  
  NODE * root = pop(); 
  return root;
}

NODE * prefix()
{
  char Exp[100];
  printf("Enter the PREFIX Expression : ");
  scanf("%s", Exp);
  int i = 0;
  for(i = strlen(Exp) -1 ; i >= 0; i--){
    if(isalpha(Exp[i]))
      push(CreateNode(Exp[i]));
    else{
      NODE * operand = CreateNode(Exp[i]);
      operand -> lchild = pop();
      operand -> rchild = pop();
      push(operand);
    }
    //display();
  }
  NODE * root = pop();
  return root;
}


int main(){
  int choice = 0;
  NODE * root;
  while(choice != 6)
  {
    printf("\n\n1. Enter Prefix Expression \n2. Enter postfix Expression \n3. Inorder Traversal \n4. Preorder Traversal \n5. Postorder Traversal\n6. Exit \nEnter Your Choice : ");
  scanf("%d", &choice);
    switch(choice)
	  {
	      case 1 : root = prefix();
		       break;
	      case 2 : root = postfix();
		       break;
	      case 3 : inorder(root);
		       break;
	      case 4 : preorder(root);
		       break;
	      case 5 : postorder(root);
		       break;
	      default : printf("Invalid Option");
	  }
  }
	  
}







