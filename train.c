#include <stdio.h>


//queue

struct customers{
    int ticketsleft;
    char name[50];
}queue[50];

int front,rear,size=10,count=0,i;

void initialise(){
    front=rear=-1;
}

void enqueue(){
    if(front==-1 && rear==-1){
        front=rear=0;
        printf("Enter Name and tickets count");
        scanf(" %[^\n]%d",queue[rear].name,&queue[rear].ticketsleft);
        printf("Successfully added...");
        count++;
        
    }
    else if((rear+1)%size==front){
        printf("Queue is full");


    }
    else{
        rear=(rear+1)%size;
        printf("Enter Name and tickets count");
        scanf(" %[^\n]%d",queue[rear].name,&queue[rear].ticketsleft);
        printf("Successfully added...");
        count++;
    }
}
void dequeue(){
    if(front==-1 && rear==-1){
        printf("dequeue not possible");
    }
    else if(front==rear){
        printf("Dequeued person %s ",queue[front].name);
        front=rear=-1;
        count--;
    }
    else{
        printf("Dequeued person %s ",queue[front].name);
        front=(front+1)%size;
        count--;

    }
}
int serve(){
    if(queue[front].ticketsleft!=0){
        (queue[front].ticketsleft)--;
            if((queue[front].ticketsleft)==0){
                dequeue();
                return 0;
            }
    
        rear=(rear+1)%size;
        queue[rear]=queue[front];
    
        front=(front+1)%size;
        return 1;
    }
    
    else{
        dequeue();
    }

}


void main(){

    initialise();
    int choice=1;
    while(choice){
        printf("What dou you want to do :\n 1.book tickets \n 2. serve ticket \n 3.Current customer served \n 4.Customers Waiting. \n 5.customers list with forms \n");
        scanf(" %d",&choice);
        switch(choice){
            case 1: 
                enqueue();
                break;
            case 2:
                serve();
                break;
            case 3: 
                printf("%s || %d \n",queue[rear].name,queue[rear].ticketsleft);
                break;
            case 4:
                printf("Customers waiting : %d \n",count);
                break;
            case 5:
            
                for(i=front;i!=rear;i=(i+1)%size)
                {   printf("name : %s || forms left :%d \n",queue[i].name,queue[i].ticketsleft);
                }
                printf("name : %s || forms left :%d \n",queue[i].name,queue[i].ticketsleft);
        }
            

    }
}






