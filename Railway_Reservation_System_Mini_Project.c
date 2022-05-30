


#include<stdio.h>
#include<stdlib.h>
#define size 3


typedef struct NODE
{
	int reg_no;
	int age;
	char name[20];
	char source[20];
	char destination[20];
	int price;
	struct NODE *next;
} node;

node* deq();           //dequeue
int create();          //creation of node 
int reserve(node*);    //for booking
int cancel(int);       //cancel the booking
void enq(node*);       //dequeue operation
void display();        //display details
 

node *start;           
node *front;           //deletion happens at the front end of the queue
node *rear;            //insertion happens at the rear end of the queue
int count=0;           
int num=0; 

int create( )
{
	node *new;
	new=(node *)malloc(sizeof(node));
	new->reg_no=1;
	
	printf("Name: ");
	scanf("%s", new->name);
	printf("Age : ");
	
	scanf("%d", &new->age);
    if(new->age>=90 || new->age<=10) {
        free(new);
        return -1;
    }
    
    printf("starting location:");
    scanf("%s", new->source);
    
    printf("destination location:");
    scanf("%s", new->destination);
    
	start=new;
	new->next=NULL;
	num++;
    return 1;
	
}

int reserve(node *start)
{
	int temp;
	if(start==NULL)              //there is no any node in queue
	{   
   		temp = create(start);    //then create new node
		 return temp;
	}
	else 
	{
	node *temp, *new_node;
	temp=start;
	while(temp->next!=NULL)   //traversing till last node
	{ 
	  temp=temp->next;
	}
	
	new_node=(node *)malloc(sizeof(node));  //dynamic memeory assining
	
	printf("Name: ");                       //now get the information about the passenger
	scanf("%s", new_node->name);
	
	printf("Age : ");
	scanf("%d", &new_node->age);
	
    if(new_node->age >=90 || new_node->age<=10) {
        return -1;
    }
    
    printf("starting location:");
    scanf("%s", new_node->source);
    
    printf("destination location:");
    scanf("%s", new_node->destination);
    
	new_node->next=NULL;                     //assining last node connection as NULL
	if(num<=size)                            //reservation is available
	{
		num++;
		new_node->reg_no=num;
		temp->next=new_node;
		
		return 1;
	}
	else
	{
		enq(new_node);                      //inserting new node in waiting list
		return 0;
	}
}
}


int cancel(int reg)
{
	node *ptr, *preptr, *new;
	ptr=start;
	preptr=NULL;
	if(start==NULL)
	
	return -1;
	if(ptr->next==NULL && ptr->reg_no==reg)
		{
		start=NULL;
// 		num--;
		free(ptr);
		return 1;
		
		}
		
	else{	
	while(ptr->reg_no!=reg && ptr->next!=NULL)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		if(ptr==NULL && ptr->reg_no!=reg)
			return -1;
		else
			preptr->next=ptr->next;
		free(ptr);
		new=deq();
		while(preptr->next!=NULL)
			preptr=preptr->next;
		preptr->next=new;
		num--;
		return 1;
	
	}
}

void enq(node *new_node)
{
	if(rear==NULL)
	{
		rear=new_node;
		rear->next=NULL;
		front=rear;
	}
	else
	{
		node *temp;
		temp=new_node;
		rear->next=temp;
		temp->next=NULL;
		rear=temp;
	}
	count++;
}

node* deq()
{
	node *front1;
	front1=front;
	if(front==NULL)
		return NULL;
	else
	{
	    count-- ;
		if(front->next!=NULL)
		{
			front=front->next;
			front1->next=NULL;
			return front1;
		}
		else
		{
			front=NULL;
			rear=NULL;
			
			return front1;
		}
	}	
}


void display()
{
	node *temp;
	temp=start;
	printf("\nReg._No.\tName\tage\tsource\tdestination");
	while(temp!=NULL)
	{
	    
	    
		printf("\n %d\t\t%s\t%d\t%s\t%s", temp->reg_no,temp->name,temp->age,temp->source,temp->destination);
		temp=temp->next;
    }
    
}

int main()
{
	int choice, status=0,canc=0, reg=0;
	start=NULL;
	rear=NULL;
	front=NULL;
	
	
	
	printf("\t\t\t**RAILWAY RESERVATION**\t\t\t\t\n");
	int ch =0;
	while(ch!=4)
	{
	printf("\n\nDo you want to - \n 1. Book a ticket \n 2. Cancel Booking \n 3. Display passenger details \n 4. exit\n\n");
	scanf("%d", &choice); 
	switch(choice)
	{	
		case 1 :  status=reserve(start);
	              if(status==0)
	                printf("\nBooking Full!! \nYou are added to waiting list. Waiting list number %d", count);
	              else if(status == -1) {
                      printf("\n age not eligible");
                  }
                  else
	                printf(" \nBooking Successful!!! Enjoy your journey! Your Reg No is %d\n\n", num);
	                
	              break;
	        
	    case 2:   printf(" \n Give the Registration number to be cancelled\n");
	              scanf(" %d", &reg);
	              if(reg>num)
	              printf("Invalid!!");
	              else
	              {
	              canc=cancel(reg);
	              if(canc==-1)
	              	printf("\nRegistration number invalid!!\n");
	              else
	              	printf("\nRegistration cancelled successfully\n");
	              	}
	              break;
	              
	    case 3: display();
	    break;
	    case 4: exit(0);   
	    break;
	    default: printf("\nWrong choice!\n");       
	              
	                 
		          
	
	}
	
}

}
