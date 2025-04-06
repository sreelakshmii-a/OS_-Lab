#include<stdio.h>
#define size 100
struct process{
  int id,at,bt,ct,tat,wt,rt;
};
struct complete{
  int i,co;
};
int front=-1,rear=-1,q[size];

void enqueue(int item){
  if(rear==size-1){
    printf("Queue full");

  }
  else if(front==-1 && rear==-1){

    front =rear=0;
    q[rear]=item;
  }
  else{
    rear++;
    q[rear]=item;
  }
}

int dequeue(){
  int item;
  if(front==-1 && rear==-1){
    printf("queue empty");
  }
  else if(front==0 && rear==0){
    item =q[front];
    front =-1;
    rear=-1;

  }
  else{
    item=q[front];
    front++;
  }
  return item;
}

int isEmpty(){
  return(front==-1 || front>rear);
}



void main(){
  int n;
  printf("Enter the number of processes");
  scanf("%d",&n);
  struct process p[n], key;
  struct complete d[size];
  int quanta;
  printf("Enter the quanta");
  scanf("%d",&quanta);
 
  for (int i=0;i<n;i++){
    p[i].id=i;
        printf("enter the arrival time");
        scanf("%d",&p[i].at);
        printf("enter the burst time");
        scanf("%d",&p[i].bt);
        p[i].rt=p[i].bt;
    
  }
  for (int i=0;i<n;i++){
  key=p[i];
    int j=i-1;
    while(j>=0 && p[j].at>key.at){
      p[j+1]=p[j];
      j--;
    }
    p[j+1]=key;
  }
enqueue(p[0].id);
int i=0,k;
while(!isEmpty()){
  int c=dequeue();
  if(p[c].rt>quanta || p[c].rt==quanta){
    d[i].i=c;
    if(i==0){
      d[i].co=quanta;
    }
    else{
      d[i].co=d[i-1].co+quanta;
    }
    p[c].ct=d[i].co;
    p[c].rt=p[c].rt-quanta;
    
  }
  else{
    d[i].i=c;
    if(i==0){
      d[i].co=p[c].rt;
    }
    else{
      d[i].co=d[i-1].co+p[c].rt;
    }
    p[c].ct=d[i].co;
    p[c].rt=0;
  }

  for(int j=0;j<n;j++)
        {
            if(i==0 && p[j].at<=d[i].co && p[j].id!=c)
            {
                enqueue(p[j].id);
            }
            else
            {
                if(p[j].at>d[i-1].co && p[j].at<=d[i].co && p[j].id!=c)
                {
                    enqueue(p[j].id);
                }
            }
        }
        if(p[c].rt>0)
        {
            enqueue(p[c].id);
        }
       i++;
       k=i;
  
}

float avgwt=0.0,avgtat=0.0,att,awt,ni=0;
ni=n;
for(int i=0;i<n;i++){
  p[i].tat=p[i].ct-p[i].at;
  p[i].wt=p[i].tat-p[i].bt;
  avgtat=avgtat+p[i].tat;
  avgwt=avgwt+p[i].wt;
}



     



//Gant-Chart
if(p[0].at==0){
for(int i =0;i<k;i++){
  printf("+-----");
}
printf("+");
printf("\n|");
for(int i =0;i<k;i++){
  printf(" %d   |",d[i].i);
}
printf("\n");
for(int i =0;i<k;i++){
  printf("+-----");
}
printf("+\n");
printf("0");
for(int i =0;i<k;i++){
  printf("     %d",d[i].co);
}
}
else{
  for(int i =0;i<k+1;i++){
    printf("+-----");
  }
  printf("+");
  printf("\n");
  printf("|IDEAL|");
  for(int i =0;i<k;i++){
    printf(" P%d   |",d[i].i);
  }
  printf("\n");
  for(int i =0;i<k+1;i++){
    printf("+-----");
  }
  printf("+\n");
  printf("0    %d",p[0].at);
  for(int i =0;i<k;i++){
    printf("     %d",d[i].co);
  }
  
  
  
  
  
  
  
}
printf("\n");
printf("\nPID\tat\tbt\tct\ttat\twt\n");
for(int i=0;i<n;i++){
  printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
}

att=avgtat/ni;
awt=avgwt/ni;
printf("\naverage turn around time=%f\n",att);
printf("average waiting time=%f\n",awt);









}