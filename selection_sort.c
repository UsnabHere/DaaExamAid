
#include <stdio.h>

int sort(int a[], int n) {
    int i,j,m,t,c=0;
    for(i=0;i<n-1;i++) {
        m=i;
        for(j=i+1;j<n;j++) {
            c++;
            if(a[j]<a[m]) m=j;
        }
        t=a[i]; a[i]=a[m]; a[m]=t;
    }
    return c;
}

int main() {
    int a[80],n,i,b,w,avg;
    printf("Size Best Average Worst\n");

    for(n=20;n<=80;n+=10) {
        for(i=0;i<n;i++) a[i]=i;
        b=sort(a,n);

        for(i=0;i<n;i++) a[i]=n-i;
        w=sort(a,n);

        for(i=0;i<n;i++) a[i]=(i*37)%n;
        avg=sort(a,n);

        printf("%d %d %d %d\n",n,b,avg,w);
    }
    return 0;
}

clc; clear; close all;

n = [20 30 40 50 60 70 80];

% Calculated values from C program
best_cal = [190 435 780 1225 1770 2415 3160];
avg_cal = [190 435 780 1225 1770 2415 3160];
worst_cal = [190 435 780 1225 1770 2415 3160];

% Theoretical values
best_theory = n.^2;
avg_theory = n.^2;
worst_theory = n.^2;

% Plot graphs
T = {best_theory, avg_theory, worst_theory};
C = {best_cal, avg_cal, worst_cal};
names = {'Best','Average','Worst'};

for i = 1:3
    subplot(3,1,i);
    plot(n,T{i},'b-o',n,C{i},'r--*','LineWidth',2);
    title([names{i} ' Case: Theoretical vs Calculated']);
    xlabel('Input Size (n)');
    ylabel('Count');
    legend('Theoretical','Calculated');
    grid on;
end
