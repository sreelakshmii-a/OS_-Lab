#include <stdio.h>
#include <stdbool.h>

void main() {
    int n,m,i,j,k,f=0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int allocation[n][m], max[n][m], need[n][m], available[m],work[n][m],finish[n],safe[n],c=0;
    
    

    // Input Allocation Matrix
    printf("\nEnter Allocation Matrix (%d x %d):\n", n,m);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);

    // Input Maximum Matrix
    printf("\nEnter Maximum Matrix (%d x %d):\n", n,m);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    // Input Available Resources
    printf("\nEnter Available Resources (%d values):\n", m);
    for (i = 0; i < m; i++)
        scanf("%d", &available[i]);

    // Calculate Need Matrix
    for (i = 0; i < n; i++) {
        finish[i] = 0;
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
            need[i][j]=0;
            
        }
    }
    for (i = 0; i < n; i++){
        finish[i]=0;
    }
   
    // Banker's Algorithm
    
    while (c < n) {
      
        int f=0;
        for (i = 0; i < n; i++) {
            int g=0;
            if (finish[i]==0) {
               
                for (j = 0; j < m; j++) {
                    if (need[i][j] <= available[j]) {
                        g++;
                    }
                }
                if(g==m){
                  for (k = 0; k< m; k++){
                        
                        work[c][k]=available[k];
                        available[k]+=allocation[i][k];
                        
                        
                  }
                  safe[c++]=i;
                  f=1;
                  finish[i]=1;
                  c++;
                  
                }
              }
            
            
            }
         break;   
    }
    

   


    
    printf("\nPID\tAllocation\tMax\tNeed\tAvailable\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t", i);
        for (j = 0; j < m; j++)
            printf("%d ", allocation[i][j]);
        printf("\t\t");

        for (j = 0; j < m; j++)
            printf("%d ", max[i][j]);
        printf("\t");

        for (j = 0; j < m; j++)
            printf("%d ", need[i][j]);
        printf("\t");
        for (j = 0; j < m; j++)
            printf("%d ", work[i][j]);

        printf("\n");
    }

    
    if(c==n){
        printf("\nSystem is in a safe state.\nSafe sequence is: ");
        for (i = 0; i < n; i++)
            printf("P%d ", safe[i]);
        printf("\n");
        }
        else{
          printf("System not safe");
        }

    
}