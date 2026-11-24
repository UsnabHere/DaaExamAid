
#include <stdio.h>

int n,capacity;
int weight[100],profit[100];
int maxProfit=0;
int current[100],best[100];

void knapsack(int i,int currentWeight,int currentProfit) {
    if(i==n) {
        if(currentProfit>maxProfit) {
            maxProfit=currentProfit;

            for(int j=0; j<n; j++)
                best[j]=current[j];
        }
        return;
    }

    if(currentWeight+weight[i]<=capacity) {
        current[i]=1;
        knapsack(i+1,currentWeight+weight[i],
                 currentProfit+profit[i]);
    }

    current[i]=0;
    knapsack(i+1,currentWeight,currentProfit);
}

int main() {
    printf("Enter number of items: ");
    scanf("%d",&n);

    printf("Enter knapsack capacity: ");
    scanf("%d",&capacity);

    printf("Enter weights of items: ");
    for(int i=0; i<n; i++)
        scanf("%d",&weight[i]);

    printf("Enter profits of items: ");
    for(int i=0; i<n; i++)
        scanf("%d",&profit[i]);

    knapsack(0,0,0);

    printf("\nMaximum Profit = %d\n",maxProfit);

    printf("Selected Items: ");
    for(int i=0; i<n; i++)
        if(best[i])
            printf("item %d ",i+1);

    printf("\nSolution: ");
    for(int i=0; i<n; i++)
        printf("%d",best[i]);

    printf("\n");

    return 0;
}
Enter number of items: 4
Enter knapsack capacity: 7
Enter weights of items: 1 3 4 5
Enter profits of items: 1 4 5 7

Maximum Profit = 9
Selected Items: item 2 item 3
Solution: 0110

#include <stdio.h>

int main() {
    int n[]={5,8,10,12,14,16,18,20};

    printf("Size\tOperations\n");

    for(int i=0;i<8;i++)
        printf("%d\t%lld\n",n[i],1LL<<n[i]);

    return 0;
}

clc; clear; close all;

n = [5 8 10 12 14 16 18 20];

operations = 2.^n;

disp('Size    Operations');
disp([n' operations']);

plot(n,operations,'b-o','LineWidth',2);

xlabel('Number of Items (n)');
ylabel('Number of Operations');
title('0-1 Knapsack - Complexity Analysis');
legend('Theoretical O(2^n)');
grid on;
