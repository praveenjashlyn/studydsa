#include <stdio.h>
#include <string.h>

struct teachers{
	char name[50];
	char book[50];
	int pages;


}queue[50],teacher[50],tempname;
int front =-1,rear=-1;
char searchbook[50];




void enqueue(struct teachers teacher){
	if(front==-1 && rear==-1){
		front++;rear++;
		queue[rear]=teacher;

	}
    else if(rear==10){
        printf("Queue is full...");
    }
    else{
        queue[++rear]=teacher;
    }


}


void main(){
	int n,sum,i,current;
    
	//READ EVERYTHNG..
	
	printf("no. of teachers : ");
	scanf("%d",&n);





	for(int i=0;i<n;i++)
	{	printf("\nTeacher %d \n Enter name, book and pages\n",i+1);
		scanf(" %[^\n]",teacher[i].name);
		scanf(" %[^\n]",teacher[i].book);
		scanf(" %d",&teacher[i].pages);
        enqueue(teacher[i]);	
	}


    for(int i=0;i<n;i++){
        printf("pages are %d \n",queue[i].pages);
    }


	printf(" 1.current time : \n 2.waiting time \n 3.Teacher who waited most  \n 4.Exit \n");
	int choice,time;
    scanf("%d",&choice);

    while(choice==1 || choice==2 ||choice==3){

    
        switch(choice){
            case 1:
                printf("Enter current time : ");
                scanf("%d",&time);
                int calctime=0;
                int i=0;
                while(calctime<time)
                {
                    calctime=calctime+(queue[i].pages*2);
                    i++;
                }
                printf("name is %s \n",queue[i-1].name);
                break;


            case 2:
                printf("Enter book name : ");
                char searchbook[50];
                scanf(" %[^\n]",searchbook);
                i=0;
                int waittime=0;
                
                while(i<n && strcasecmp(searchbook,queue[i].book) )
                {   
                    waittime=waittime+ queue[i].pages*2;
                    i++;
                }
                if(i==n){
                    printf("Book not found..");

                }
                else{
                    printf("Waiting time for book %s is %d seconds..",queue[i].book,waittime);
                }
                break;
            
                
            case 3:
                printf("Waited most is %s \n",queue[rear].name);
                break;
            
            default:
                printf("Thankyou\n");
            

        }
        printf(" 1.current time : \n 2.waiting time \n 3.Teacher who waited most  \n 4.Exit \n");
	    scanf("%d",&choice);

        
    }
	
	
}
