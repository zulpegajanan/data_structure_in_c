#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node* left;
struct node* right;
};
struct node* newNode(int data)
{
struct node* node
= (struct node*)malloc(sizeof(struct node));
node->data = data;
node->left = NULL;
node->right = NULL;
return (node);
}
int isBST(struct node * root){
    static struct node *prev=NULL;
    if(root !=NULL)
    {
        if(!isBST(root->left))
          {return 0;}
        if(prev !=NULL && root->data <= prev->data)
          {return 0;}
        prev=root;
        return isBST(root->right);
    }
    else {return 1;}
}
struct node * search( struct node * root,int key){
    if(root!=NULL)
       { 
    if(root->data==key)
       {printf(" key is present ");}
    else if(root->data > key){
        search(root->left,key);
    }
    else{
        search(root->right,key);
    }
       }
    else{
        printf("key is not present");
    }
}
void print_leaf(struct node * root){
    if(root!=NULL){
        if(root->right==NULL && root->left==NULL){
            printf("%d ",root->data);
        }
        else{
            print_leaf(root->left);
            print_leaf(root->right);
        }
    }
}
void printInorder(struct node* node)
{
if (node == NULL)
return;
printInorder(node->left);
printf("%d ", node->data);
printInorder(node->right);
}
void insert(struct node *root, int key){
   struct node *prev = NULL;
   while(root!=NULL){
       prev = root;
       if(key==root->data){
           printf("Cannot insert %d, already in BST", key);
           return;
       }
       else if(key<root->data){
           root = root->left;
       }
       else{
           root = root->right;
       }
   }
   struct node* new = newNode(key);
   if(key<prev->data){
       prev->left = new;
   }
   else{
       prev->right = new;
   }
}
struct node *inOrderPredecessor(struct node* root){
    root = root->left;
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}
struct node *deleteNode(struct node *root, int value){
    struct node* iPre;
    if (root == NULL){
        return NULL;
    }
    if (root->left==NULL&&root->right==NULL){
        free(root);
        return NULL;
    }
    //searching for the node to be deleted
    if (value < root->data){
        root-> left = deleteNode(root->left,value);
    }
    else if (value > root->data){
        root-> right = deleteNode(root->right,value);
    }
    //deletion strategy when the node is found
    else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}

int maxDepth(struct node* node)
{
    if (node == NULL)
        return -1;
    else {
        
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
 
        
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

int main()
{
  int rut;
  printf("enter root value of tree ");
  scanf("%d",&rut);
struct node* root = newNode(rut);
int z,ok;
printf("how many nodes present in tree :");
scanf("%d",&z);
while(z--){
    printf("enter number ");
    scanf("%d",&ok);
    insert(root, ok);
}
int ch;
do{
   printf("\n >>>");
   printf("\n 1. checking tree is BST or not ");
   printf("\n 2. searching element  ");
   printf("\n 3. printing all leaf node ");
   printf("\n 4. height of tree");
   printf("\n 5. insertion ");
   printf("\n 6. deletion");
   printf("\n 7. display");
   printf("\n 8. exit ");
   int ch;
   printf("\n\tENTER YOUR CHOICE :");
   scanf("%d",&ch);
   switch(ch){
       case 1:{
           if(isBST(root)){
               printf("given tree is BST👍");
           }
           else {printf("given tree is not BST");}
           
           break;
       }
       case 2:{
               int key;
               printf("enter the number which you want to search ");
               scanf("%d",&key);
               search(root,key);
           break;
       }
       case 3:{
           printf("\nleaf nodes are  ");
              print_leaf(root);
              break;
       }
      case 4:{
          printf("height from 0 to n\n");
          printf("Height of tree is %d", maxDepth(root));
          break;
      }
      case 5:{
          printf("number which you want to insert ");
          int kk;
          scanf("%d",&kk);
          insert(root, kk);
          break;
      }
      case 6:{
          int test;
          printf("enter value ");
          scanf("%d",&test);
          deleteNode(root, test);
          break;
      }
      case 7:{
          printInorder(root);
              break;
      }
       case 8:{
           exit;
       }
       default:{
           printf("enter correct choice ");
       }
   }
}while(ch!=10);
}
