#include<stdio.h>
#include<stdlib.h>
#define maxsize 100

void display(int f[],int frames){
  
  for(int i=0;i<frames;i++){
    if(f[i]!=-1){
      printf("%d\t",f[i]);
    }
    else{
      printf("-\t");
    }
  }

}


void FIFO(int pages[],int n,int frames){
  int index=0,fault,hit;
  int f[maxsize];
  for(int i=0;i<frames;i++){
    f[i]=-1;
 
   }
  for(int i=0;i<n;i++){
    int found =0;
    for(int j=0;j<frames;j++){
       if(f[j]!=pages[i]){
        found =1;
       }
    }
    if(found ==0){
      f[index]=pages[i];
      index=(index+1)%frames;
      fault++;
      display(f,frames);
      printf("Fault occured");
    }
    else{
      display(f,frames);
      printf("Hit occured");

    }
  }



}

void main(){
  int n;
  printf("Enter the number of pages");
  scanf("%d",&n);
  int pages[maxsize];
  printf("Enter the pages");
  for(int i=0;i<n;i++){
    scanf("%d",&pages[i]);
  }
  int frames;
  printf("Enter the number of frames");
  scanf("%d",frames);
  FIFO(pages,n,frames);
}