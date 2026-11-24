
#include <stdio.h>

struct Item {
    double w,p;
} a[80],b[80];

int count;

void merge(int l,int m,int r){
    int i=l,j=m+1,k=l;

    while(i<=m && j<=r){
        count++;
        if(a[i].p/a[i].w >= a[j].p/a[j].w)
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }

    while(i<=m) b[k++]=a[i++];
    while(j<=r) b[k++]=a[j++];

    for(i=l;i<=r;i++) a[i]=b[i];
}

void sort(int l,int r){
    if(l>=r) return;
    int m=(l+r)/2;
    sort(l,m);
    sort(m+1,r);
    merge(l,m,r);
}

double knapsack(int n,double W){
    double profit=0;
    int i;

    count=0;
    sort(0,n-1);

    for(i=0;i<n && W>0;i++){
        count++;

        if(a[i].w<=W){
            profit+=a[i].p;
            W-=a[i].w;
        }
        else{
            profit+=a[i].p*W/a[i].w;
            W=0;
        }
    }
    return profit;
}

int main(){
    int n,i;
    double W;

    printf("Enter number of items: ");
    scanf("%d",&n);
    if(n<1 || n>80) return 0;

    printf("Enter weight and profit:\n");
    for(i=0;i<n;i++){
        scanf("%lf%lf",&a[i].w,&a[i].p);
        if(a[i].w<=0 || a[i].p<0) return 0;
    }

    printf("Enter capacity: ");
    scanf("%lf",&W);
    if(W<0) return 0;

    printf("Maximum Profit = %.2f\n",knapsack(n,W));

    printf("\nSize Calculated\n");

    for(n=20;n<=80;n+=10){
        for(i=0;i<n;i++){
            a[i].w=i%10+1;
            a[i].p=(i*17)%97+1;
        }

        knapsack(n,1000);
        printf("%d %d\n",n,count);
    }

    return 0;
}

clc; clear; close all;

n = 20:10:80;

% Theoretical O(n log n), scaled for comparison
theory = 6*n.*log2(n);

% Actual calculated values from C
calculated = [82 144 198 270 335 410 475];

T = table(n',theory',calculated', ...
    'VariableNames',{'InputSize','Theoretical','Calculated'});
disp(T);

figure;
plot(n,theory,'b-o','LineWidth',2);
hold on;
plot(n,calculated,'k-o','LineWidth',2);

title('Fractional Knapsack - Complexity Analysis');
xlabel('Number of Items (n)');
ylabel('Number of Operations');
legend('Theoretical O(n log n)','Calculated', ...
       'Location','northwest');
grid on;
hold off;

       

    
       


