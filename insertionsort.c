#include <stdio.h>

void main(){
    int arr[]={1,3,5,4,2};
    int n=5;
    for(int i=1;i<n;i++){
        int j=i-1;
        int key=arr[i];
        while(j>=0 && arr[j]<key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;


    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
