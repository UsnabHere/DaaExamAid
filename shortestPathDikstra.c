
#include <stdio.h>
#define MAX 80
#define INF 999999

int g[MAX][MAX],d[MAX],vis[MAX],parent[MAX];
long work;

void dijkstra(int n,int src){
    int i,j,u;

    for(i=0;i<n;i++){
        d[i]=INF;
        vis[i]=0;
        parent[i]=-1;
    }
    d[src]=0;
    work=0;

    for(i=0;i<n;i++){
        u=-1;

        for(j=0;j<n;j++){
            if(j>0) work++;
            if(!vis[j] && (u==-1 || d[j]<d[u]))
                u=j;
        }

        if(u==-1 || d[u]==INF) break;
        vis[u]=1;

        for(j=0;j<n;j++){
            if(j==u) continue;
            work++;

            if(!vis[j] && g[u][j]>0 &&
               d[u]+g[u][j]<d[j]){
                d[j]=d[u]+g[u][j];
                parent[j]=u;
            }
        }
    }
}

void printPath(int v){
    if(parent[v]!=-1){
        printPath(parent[v]);
        printf(" -> ");
    }
    printf("%d",v);
}

int main(){
    int n,i,j;

    n=16;

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            g[i][j]=(i==j)?0:(i+j)%9+1;

    dijkstra(n,0);

    printf("Shortest paths from source node 0:\n");

    for(i=0;i<n;i++){
        printPath(i);
        printf("  Distance = %d\n",d[i]);
    }

    printf("\nSize Theoretical Calculated\n");

    for(n=20;n<=80;n+=10){
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                g[i][j]=(i==j)?0:(i+j)%9+1;

        dijkstra(n,0);

        printf("%d %d %ld\n",n,n*n,work);
    }

    return 0;
}

clc; clear; close all;

n = 20:10:80;

theoretical = n.^2;

calculated = [760 1740 3120 4900 7080 9660 12640];

T = table(n',theoretical',calculated', ...
    'VariableNames',{'InputSize','Theoretical','Calculated'});
disp(T);

figure;
plot(n,theoretical,'b-o','LineWidth',2);
hold on;
plot(n,calculated,'k-o','LineWidth',2);

title('Dijkstra Algorithm - Time Complexity Analysis');
xlabel('Input Size (n)');
ylabel('Number of Operations');
legend('Theoretical O(n^2)','Calculated', ...
    'Location','northwest');
grid on;
hold off;


  
