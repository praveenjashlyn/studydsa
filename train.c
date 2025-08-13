#include <stdio.h>

//queue

struct customers{
    int ticketsleft;
    char name[50];
}queue[50];

int front,rear,size=10;

void initialise(){
    front=rear=-1;
}

void enqueue(){
    if(front==-1 && rear==-1){
        front=rear=0;
        printf("Enter Name and tickets count");
        scanf(" %[^\n]%d",queue[rear].name,&queue[rear].ticketsleft);
        printf("Successfully added...");
        
    }
    else if((rear+1)%size==front){
        printf("Queue is full");


    }
    else{
        rear=(rear+1)%size;
        queu
    }
}



void main(){

    
    



}

