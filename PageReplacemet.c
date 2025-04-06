#include<stdio.h>
#include<stdlib.h>
#define maxsize 100



void display(int f[],int frames){
  printf("Frames:");
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
  int fault=0,hit=0;
  int index=0;
  int f[maxsize];
  for(int i=0;i<frames;i++){
   f[i]=-1;

  }
  for(int i=0;i<n;i++){
    int found=0;
    for(int j=0;j<frames;j++){
      if(f[j]==pages[i]){
          found=1;
      }
    }
    if(found==0){
      f[index]=pages[i];
      index=(index+1)%frames;
      fault++;
      display(f,frames);
      printf("\t Page Fault %d \n",pages[i]);
    }
    else{
      display(f,frames);
      hit++;
      printf("\t Page hit %d \n",pages[i]);
    }

  }

  printf("\nFaults:%d\n",fault);
  float fa=0.0;
  float hi=0.0;
  float ni=0.0;
  ni = n;
  fa=fault;
  hi=hit;
  float avg1,avg2;
  avg1=fa/ni;
  avg2=hi/ni;
  printf("\nFault Ratio:%f\n",avg1);
  printf("\nHit Ratio:%f\n",avg2);
}

void LRU(int pages[],int n,int frames){
  int f[frames],time[frames];
  int hit=0,fault=0,clock=0;

  for(int i=0;i<frames;i++){
    f[i]=-1;
    time[i]=-1;
  }
  for(int i=0;i<n;i++){
    int found=0,lrindex=0;  
        for(int j=0;j<frames;j++){
      if(f[j]==pages[i]){
        found=1;
        time[j]=clock++;
        break;
      }
    }
    if(found==0){
      int min=99999;
      for(int j=0;j<frames;j++){
        if(time[j]<min){
          min=time[j];
          lrindex=j;
        }
      }
      f[lrindex]=pages[i];
      time[lrindex]=clock++;
      fault++;
      display(f,frames);
      printf("Fault occured %d\n",pages[i]);
    }
    else{
      display(f,frames);
      hit++;
      printf("Hit occured %d\n",pages[i]);
    }
  }
  float H,F,N,aH,aF;
  H=hit;
  F=fault;
  N=n;
  aH=H/N;
  aF=F/N;
  printf("Hit Ratio:%f",aH);
  printf("Fault Ratio:%f",aF);
}




void LFU(int pages[],int n,int frames){
  int f[frames],time[frames],freq[frames];
  int hit=0,fault=0;

  for(int i=0;i<frames;i++){
    f[i]=-1;
    freq[i]=0;
  }
  for(int i=0;i<n;i++){
    int found=-1,lfindex=0;
    for(int j=0;j<frames;j++){
      if(f[j]==pages[i]){
        found=j;
        freq[j]++;
        break;
      }
    }
    if(found==-1){
      int min=99999;
      for(int j=0;j<frames;j++){
        time[j]++;

        if(freq[j]<min && f[j]!=-1){
          min=freq[j];
          lfindex=j;
        }
        else{
          lfindex=j;
          break;
        }
      }
      int v,most=0;
      v=freq[lfindex];
      for(int j=0;j<frames;j++){
        if(time[j]>=most){
          most =time[j];
          lfindex=j;
        }
      }
    
    
      f[lfindex]=pages[i];
      time[lfindex]=0;
      freq[lfindex]=1;
      fault++;
      display(f,frames);
      printf("Fault occured %d\n",pages[i]);
    }
    else{
      for(int j=0;j<frames;j++){
        time[j]++;
      }
      display(f,frames);
      hit++;
      printf("Hit occured %d\n",pages[i]);
    }
  }
  float H,F,N,aH,aF;
  H=hit;
  F=fault;
  N=n;
  aH=H/N;
  aF=F/N;
  printf("Hit Ratio:%f",aH);
  printf("Fault Ratio:%f",aF);
}






void main(){
  int n,frames;
  int pages[maxsize];
  printf("Enter the number of pages");
  scanf("%d",&n);
  printf("Enter the pages");
  for(int i=0;i<n;i++){
    scanf("%d",&pages[i]);
  }
  printf("Enter the number of frames");
  scanf("%d",&frames);
  
  LFU(pages,n,frames);

}