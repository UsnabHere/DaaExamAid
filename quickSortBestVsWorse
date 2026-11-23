
#include <stdio.h>

int count;

void build(int a[],int start,int n){
    if(n==0) return;

    int left=(n-1)/2;

    build(a,start,left);
    build(a,start+left+1,n-left-1);
    a[start+n-1]=start+left+1;
}

int partition(int a[],int l,int r){
    int pivot=a[r],i=l-1,t,j;

    for(j=l;j<r;j++){
        count++;
        if(a[j]<pivot){
            i++;
            t=a[i]; a[i]=a[j]; a[j]=t;
        }
    }

    t=a[i+1]; a[i+1]=a[r]; a[r]=t;
    return i+1;
}

void quick(int a[],int l,int r){
    if(l<r){
        int p=partition(a,l,r);
        quick(a,l,p-1);
        quick(a,p+1,r);
    }
}

int main(){
    int a[80],n,i,best,worst;

    printf("Size Best Worst\n");

    for(n=20;n<=80;n+=10){

        build(a,0,n);
        count=0;
        quick(a,0,n-1);
        best=count;

        for(i=0;i<n;i++)
            a[i]=i+1;

        count=0;
        quick(a,0,n-1);
        worst=count;

        printf("%d %d %d\n",n,best,worst);
    }

    return 0;
}


clc; clear; close all;

n = 20:10:80;

% Theoretical complexity
best_theory = n.*log2(n);
worst_theory = n.^2;

% Calculated values from C output
best_calc = [84 127 201 279 353 436 507];
worst_calc = [190 435 780 1225 1770 2415 3160];

% Display comparison table
T = table(n',best_theory',best_calc', ...
    worst_theory',worst_calc', ...
    'VariableNames',{'Size','BestTheory','BestCalculated', ...
    'WorstTheory','WorstCalculated'});
disp(T);

% Best Case Graph
figure;
plot(n,best_theory,'b-o','LineWidth',2);
hold on;
plot(n,best_calc,'k-o','LineWidth',2);
title('Quick Sort - Best Case');
xlabel('Input Size (n)');
ylabel('Number of Comparisons');
legend('Theoretical O(n log n)','Calculated');
grid on;
hold off;

% Worst Case Graph
figure;
plot(n,worst_theory,'b-o','LineWidth',2);
hold on;
plot(n,worst_calc,'k-o','LineWidth',2);
title('Quick Sort - Worst Case');
xlabel('Input Size (n)');
ylabel('Number of Comparisons');
legend('Theoretical O(n^2)','Calculated');
grid on;
hold off;

