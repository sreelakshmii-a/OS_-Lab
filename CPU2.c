#include<stdio.h>
#include<stdlib.h>
 struct process{
  int id,at,bt,tat,ct,wt;
 };

 void main(){
  float sumtat=0.0,sumwt=0.0;
  int n;
  printf("Enter the number of processes");
  scanf("%d",&n);

  struct process p[n],key;
  for(int i=0;i<n;i++){
    printf("Enter the arrival time and burst time of process%d",i);
    scanf("%d%d",&p[i].at,&p[i].bt);
    p[i].id=i;
    key=p[i];
    
  }
  for(int i = 1; i < n; i++) {
    key = p[i];
    int j = i - 1;
    while(j >= 0 && p[j].bt > key.bt) {
        p[j + 1] = p[j];
        j--;
    }
    p[j + 1] = key;
}

 


  p[0].ct=p[0].at+p[0].bt;
  for(int i=1;i<n;i++){
    p[i].ct = (p[i].at > p[i - 1].ct) ? p[i].at + p[i].bt : p[i - 1].ct + p[i].bt;  
  }

  for(int i=0;i<n;i++){
    p[i].tat=p[i].ct-p[i].at;
    p[i].wt=p[i].tat-p[i].bt;
    sumtat+=p[i].tat;
    sumwt+=p[i].wt;
  }
  float avgwt,avgtat;
  avgwt=sumwt/n;
  avgtat=sumtat/n;
  printf("Average Waiting Time:%f\n",avgwt);
  printf("Average Turn Around  Time:%f\n",avgtat);

//Table

printf("PID\tat\tbt\tct\ttat\twt\n");
for(int i=0;i<n;i++){
  printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
}

//Gant-Chart
if(p[0].at==0){
for(int i =0;i<n;i++){
  printf("+-----");
}
printf("+");
printf("\n|");
for(int i =0;i<n;i++){
  printf(" %d   |",p[i].id);
}
printf("\n");
for(int i =0;i<n;i++){
  printf("+-----");
}
printf("+\n");
printf("0");
for(int i =0;i<n;i++){
  printf("     %d",p[i].ct);
}
}
else{
  for(int i =0;i<n+1;i++){
    printf("+-----");
  }
  printf("+");
  printf("\n");
  printf("|IDEAL|");
  for(int i =0;i<n;i++){
    printf(" P%d   |",p[i].id);
  }
  printf("\n");
  for(int i =0;i<n+1;i++){
    printf("+-----");
  }
  printf("+\n");
  printf("0    %d",p[0].at);
  for(int i =0;i<n;i++){
    printf("     %d",p[i].ct);
  }
  
  
  
  
  
  
  
}







 }