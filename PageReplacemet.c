#include<stdio.h>
#include<stdlib.h>


void FIFO(int pages[],int n,int f){
  int fault=0;
  int index=0;
  int frames[f];
  for(int i=0;i<f;i++){
   frames[i]=-1;

  }
  for(int i=0;i<n;i++){
    int found=0;
    for(int j=0;j<f;j++){
      if(frames[j]==pages[i]){
          found++;
      }
    }
    if(!found){
      frames[index]=pages[i];
      index=(index++)%f;
      fault++;
    }

  }

  printf()
}