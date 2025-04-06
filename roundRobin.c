#include<stdio.h>
#define N 20
int front=-1,rear=-1,q[N];
struct process
{
    int at,bt,ct,wt,tt,id,rt;
};
struct complete
{
    int i,co;
};
void enqueue(int item)
{
    if(rear==N-1)
    {
        printf("queue overflow");
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        q[rear]=item;
    }
    else
    {
        rear++;
        q[rear]=item;
    }
}
int dequeue()
{
    int item;
    if(front==-1 && rear==-1)
    {
        printf("queue empty");
        return -1;
    }
    else if(front==rear)
    {
        item=q[front];
        front=-1;
        rear=-1;
    }
    else
    {
        item=q[front];
        front++;
    }
    return item;
}
int isempty()
{
    return(front==-1 || front>rear);
}
void main()
{
    struct complete d[N];
    int n,i,j,c,qa,k,l=0;
    float att=0.0,awt=0.0;
    printf("enter the number of processes\t");
    scanf("%d",&n);
    printf("enter the time slice\t");
    scanf("%d",&qa);
    struct process p[n],key;
    for(i=0;i<n;i++)
    {
        p[i].id=i;
        printf("enter the arrival time");
        scanf("%d",&p[i].at);
        printf("enter the burst time");
        scanf("%d",&p[i].bt);
        p[i].rt=p[i].bt;
    }
    for(i=1;i<n;i++)
    {
        key=p[i];
        j=i-1;
        while(j>=0 && p[j].at>key.at)
        {
            p[j+1]=p[j];
            j--;
        }
        p[j+1]=key;
        
    }




    
    enqueue(p[0].id);
    i=0;
    while(!isempty())
    {
        c=dequeue();
        if(p[c].rt>qa || p[c].rt==qa)
        {
            d[i].i=c;
            if(i==0){
            d[i].co=qa;
            }
            else{
                d[i].co=d[i-1].co+qa;
            }
            p[c].ct=d[i].co;
            p[c].rt=p[c].rt-qa;
        }
        else
        {
            d[i].i=c;
            if(i==0){
            d[i].co=p[c].rt;
            }
            else{
                d[i].co=p[c].rt+d[i-1].co;
            }
            p[c].ct=d[i].co;
            p[c].rt=0;
        }
        for(j=0;j<n;j++)
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









    if(p[0].at!=0)
    {
        for(i=0;i<=k;i++)
        {
        printf("+-----");
        if(i==k-1)
        {
            printf("+\n");
        }
        }
        printf("| IDLE");
         for(i=0;i<k;i++)
        {
        printf("| P%d  ",d[i].i);
        if(i==k-1)
        {
            printf("|");
        }
        }
        for(i=0;i<=k;i++)
        {
            printf("+-----");
            if(i==k)
            {
                printf("+\n");
            }
        }
    }
    else{
    for(i=0;i<k;i++)
    {
        printf("+-----");
        if(i==k-1)
        {
            printf("+\n");
        }
    }
    for(i=0;i<k;i++)
    {
        printf("| P%d  ",d[i].i);
        if(i==k-1)
        {
            printf("|\n");
        }
    }
    for(i=0;i<k;i++)
    {
        printf("+-----");
            if(i==k-1)
            {
                printf("+\n");
            }
    }
    }
    for(i=0;i<k;i++)
    {
        if(i==0)
        {
            printf("0    ");
        }
        printf("%d     ",d[i].co);
    }
    for(i=0;i<n;i++)
    {
        p[i].tt=p[i].ct-p[i].at;
        p[i].wt=p[i].tt-p[i].bt;
        att=att+p[i].tt;
        awt=awt+p[i].wt;
    }
    att=att/n;
    awt=awt/n;
    printf("\naverage turn around time=%f\n",att);
     printf("average waiting time=%f\n",awt);
     for(i=1;i<n;i++)
    {
        key=p[i];
        j=i-1;
        while(j>=0 && p[j].id>key.id)
        {
            p[j+1]=p[j];
            j--;
        }
        p[j+1]=key;
        
    }
    printf("PID  AT  BT  CT  TT  WT\n");
    for(i=0;i<n;i++)
    {
        printf("P%d   %d   %d   %d  %d  %d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt);
    }
}