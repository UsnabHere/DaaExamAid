
#include <stdio.h>
#define INF 999999

int u[6400],v[6400],w[6400],d[80],count;

int bellman(int V,int E,int s){
    int i,j,change;

    for(i=0;i<V;i++) d[i]=INF;
    d[s]=0; count=0;

    for(i=1;i<V;i++){
        change=0;
        for(j=0;j<E;j++){
            count++;
            if(d[u[j]]!=INF &&
               d[u[j]]+w[j]<d[v[j]]){
                d[v[j]]=d[u[j]]+w[j];
                change=1;
            }
        }
        if(!change) break;
    }

    for(j=0;j<E;j++)
        if(d[u[j]]!=INF &&
           d[u[j]]+w[j]<d[v[j]])
            return 0;

    return 1;
}

int main(){
    int V,E,s,i,j;

    printf("Enter vertices and edges: ");
    scanf("%d%d",&V,&E);

    printf("Enter edges (source destination weight):\n");
    for(i=0;i<E;i++)
        scanf("%d%d%d",&u[i],&v[i],&w[i]);

    printf("Enter source: ");
    scanf("%d",&s);

    if(!bellman(V,E,s))
        printf("Negative cycle detected\n");
    else{
        printf("\nNode Distance\n");
        for(i=0;i<V;i++)
            if(d[i]==INF) printf("%d INF\n",i);
            else printf("%d %d\n",i,d[i]);
    }

    printf("\nSize Theoretical Calculated\n");

    for(V=20;V<=80;V+=10){
        E=0;
        for(i=0;i<V;i++)
            for(j=i+1;j<V;j++){
                u[E]=i;
                v[E]=j;
                w[E]=(j==i+1)?-1:2;
                E++;
            }

        bellman(V,E,0);
        printf("%d %d %d\n",V,(V-1)*E,count);
    }

    return 0;
}


clc; clear; close all;

V = 20:10:80;
E = V.*(V-1)/2;

theory = (V-1).*E;
calculated = [380 870 1560 2450 3540 4830 6320];

plot(V,theory,'b-o','LineWidth',2);
hold on;
plot(V,calculated,'k-o','LineWidth',2);

xlabel('Input Size (Vertices)');
ylabel('Number of Operations');
title('Bellman-Ford Complexity Analysis');
legend('Theoretical O(VE)','Calculated Edge Checks');
grid on;
hold off;

