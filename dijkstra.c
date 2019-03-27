#include<stdio.h>

int INFINITY=9999; 
void dijkstra(int G[20][20],int n,int startnode)
{

    int cost[20][20],dist[20],prev[20];
    

    int visited[20],visitcount,mindist,nextnode;
 
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];

    for(int i=0;i<n;i++){
        dist[i]=cost[startnode][i];
        prev[i]=startnode;
        visited[i]=0;
    }

    dist[startnode]=0;
    visited[startnode]=1;
    visitcount=1;

    while(visitcount<n-1){

        mindist=INFINITY; 
        for(int i=0;i<n;i++)
            if(dist[i]<mindist&&!visited[i]){
      
                mindist=dist[i];
                nextnode=i;
            }

        visited[nextnode]=1;
        for(int i=0;i<n;i++)
            if(!visited[i])
                if(mindist+cost[nextnode][i]<dist[i]){
                    dist[i]=mindist+cost[nextnode][i];
                    prev[i]=nextnode;
                }

        visitcount++;
    }


    int i=0;
    while(i!=-1){
        printf("\nEnter node to travel to (-1 to exit): ");
        scanf("%d",&i);

        if(i >= n || i < 0) continue;

        printf("Shortest distance to node %d = %d",i,dist[i]);

        printf("\nPath=%d",i);
        int j=i;
        while(j!=startnode){
            j=prev[j];
            printf("<-%d",j);
        }
    }
}



int main()
{

 
    int G[20][20];
    int n,s;

    printf("Enter # of vertices (1-20): ");
    scanf("%d",&n);

    while(n > 20 || n < 0){
        printf("Reenter # of vertices (1-20): ");
        scanf("%d", &n);
    }

    printf("\nEnter the dists matrix (Note: assign 0 for self, assign 0 for no path):\n");
    for(int i=0;i<n;i++){
        printf("dists from node %d: ", i);
        for(int j=0;j<n;j++)
            scanf("%d",&G[i][j]);
    }

    printf("\nEnter the starting node: ");
    scanf("%d",&s);
    dijkstra(G,n,s); 

    return 0;
}


