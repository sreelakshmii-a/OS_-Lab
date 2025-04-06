#include<stdio.h>

void needmatrix(int m,int n,int alloc[][m],int max[][m],int need[n][m])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            need[i][j]=0;
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
}

void bankers(int n,int m,int finish[],int safe[],int alloc[n][m],int need[n][m],int avail[m],int work[][m],int max[][m],int comp)
{

    while(comp<n)
    {
        int f=0;
        for(int i=0;i<n;i++)
        {
            int g=0;
            if(finish[i]==0)
            {
                for(int j=0;j<m;j++)
                {
                    if(need[i][j]<=avail[j])
                    {
                        g++;
                    }
                    if(g==m)
                    {
                        for(int k=0;k<m;k++)
                        {
                            work[comp][k]=avail[k];
                            avail[k]+=alloc[i][k];
                        }
                        safe[comp]=i+1;
                        f=1;
                        finish[i]=1;
                        comp++;

                    }
                }
            }
        }
        if(f!=1)
        {
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
    if(comp==n)
    {
        printf("\nSAFE SEQUENCE\n");
        int i;
        for(i=0;i<n-1;i++)
        {
            printf("P%d->",safe[i]);
        }
        printf("P%d",safe[i]);
    }
    else
    {
        printf("\nUNSAFE");
    }
}

void request(int n,int m,int avail[m],int req[],int v,int alloc[n][m],int need[n][m])
{
    int g=0;
    for(int i=0;i<m;i++)
    {
        if(req[i]<=need[v][i])
        {
            if(req[i]<=avail[i])
            {
                g++;
            }
        }

    }
    if(g==m)
    {
        for(int i=0;i<m;i++)
        {
            avail[i]-=req[i];
            alloc[v][i]+=req[i];
            need[v][i]-=req[i];
        }
    }
    else
    {
        printf("request can be accepted");
    }
}

void main()
{
    int n,m;
    printf("enter the number resorses and process");
    scanf("%d%d",&m,&n);
    int alloc[n][m],max[n][m],work[n][m],avail[m],finish[n],safe[n],need[n][m],total[m],req[m],v=0,comp=0;
    printf("enter each memory allocated for each process\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
        finish[i]=0;
    }
    printf("enter max memory allocated for each process\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("enter total of each process\n");
    for(int i=0;i<m;i++)
    {   
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
    needmatrix(m,n,alloc,max,need);
    int c;
    printf("1.bankers\n2.request and bankers\n");
    scanf("%d",&c);
    switch (c)
    {
    case 1:
            bankers(n,m,finish,safe,alloc,need,avail,work,max,comp);
            break;
    
    case 2:
            printf("enter the process number");
            scanf("%d",&v);
            printf("enter req need");
            for(int i=0;i<m;i++)
            {
                scanf("%d",&req[i]);
            }
            request(n,m,avail,req,v,alloc,need);
            bankers(n,m,finish,safe,alloc,need,avail,work,max,comp);
            break;
    }
    
}