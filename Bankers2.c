#include<stdio.h>
#include<stdlib.h>

void needMat(int n,int m,int max[][m],int need[][m],int alloc[][m]){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      need[i][j]=0;
      need[i][j]=max[i][j]-alloc[i][j];
    }
  }
}

void bankers(int comp,int n,int m,int finish[],int need[][m],int avail[],int work[][m],int alloc[][m],int safe[],int max[][m]){
  
  while(comp<n){
    int f=0;
    for(int i=0;i<n;i++){
      int g=0;
      if(finish[i]==0){
        for(int j=0;j<m;j++){
          if(need[i][j]<=avail[j]){
            g++;
          }
          if(g==m){
            for(int k=0;k<m;k++){
              work[comp][k]=avail[k];
              avail[k]+=alloc[i][k];
            }
            finish[i]=1;
            f=1;
            safe[comp]=i+1;
            comp++;
          }
        }
      }
    }
    if(f!=1){
      break;
    }
  }



  printf("\n\talloc\tmax\tneed\tavail\n");
    for(int i=0;i<n;i++)
    {
        printf("P%d\t",i);
        for(int j=0;j<m;j++)
        {
            printf("%d ",alloc[i][j]);
        }
        printf("\t");
        for(int j=0;j<m;j++)
        {
            printf("%d ",max[i][j]);
        }
        printf("\t");
        for(int j=0;j<m;j++)
        {
            printf("%d ",need[i][j]);
        }
        printf("\t");
        for(int j=0;j<m;j++)
        {
            printf("%d ",work[i][j]);
        }
        printf("\n");
    }


    if(comp==n){
      printf("SAfe\n");
      for(int i=0;i<n;i++){
        printf("P%d=>",safe[i]);
      }
      printf("\n");
    }
    else{
      printf("Unsafe");
    }
}



void request(int m,int req[],int avail[],int need[][m],int alloc[][m],int v){
  int g=0;
  for(int i=0;i<m;i++){
    if(req[i]<=need[v][i]){
      if(req[i]<=avail[i]){
        g++;
      }
    }
  }

  if(g==m){
    printf("\nRequest is accepeted!\n");
    for(int i=0;i<m;i++){
      avail[i]-=req[i];
      alloc[v][i]+=req[i];
      need[v][i]-=req[i];
    }
  }
  else{
    printf("Request cannot be accepted");
  }
}


void main(){
  int n,m;
  printf("Enter the number of processes and resources");
  scanf("%d%d",&n,&m);
  int alloc[n][m],max[n][m],need[n][m],avail[m],work[n][m],finish[n],safe[n],total[m],req[m],comp=0,v=0;
  printf("Enter allocation matrix");
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
     scanf("%d",&alloc[i][j]);
    }
    finish[i]=0;
  }
  printf("Enter max matrix");
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
     scanf("%d",&max[i][j]);
    }
  }

  printf("Enter max resources");
  for(int i=0;i<m;i++){
    scanf("%d",&total[i]);
    avail[i]=0;
  }

  for(int i=0;i<m;i++)
  {
      for(int j=0;j<n;j++)
      {
          avail[i]+=alloc[j][i];
      }
      avail[i]=total[i]-avail[i];
  }
  for(int i=0;i<m;i++)
    {
        printf("\n%d\t",avail[i]);
    }

  needMat(n,m,max,need,alloc);
  int c;
  printf("1.Bankers\n2.Request\n");
  scanf("%d",&c);
  switch(c){
    case 1:bankers(comp,n,m,finish,need,avail,work,alloc,safe,max);
    break;
    case 2:request(m,req,avail,need,alloc,v);
    break;
    default:
      printf("Invalid");
  }
}