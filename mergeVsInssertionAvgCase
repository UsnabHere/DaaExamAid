
#include <stdio.h>
#include <stdlib.h>

int insertion(int a[], int n) {
    int i,j,t,c=0;
    for(i=1;i<n;i++) {
        t=a[i]; j=i-1;
        while(j>=0) {
            c++;
            if(a[j]<=t) break;
            a[j+1]=a[j--];
        }
        a[j+1]=t;
    }
    return c;
}

int merge(int a[],int l,int r) {
    if(l>=r) return 0;
    int m=(l+r)/2,i=l,j=m+1,k=l,c=0,b[80];
    c+=merge(a,l,m)+merge(a,m+1,r);
    while(i<=m && j<=r) {
        c++;
        b[k++]=(a[i]<=a[j])?a[i++]:a[j++];
    }
    while(i<=m) b[k++]=a[i++];
    while(j<=r) b[k++]=a[j++];
    for(i=l;i<=r;i++) a[i]=b[i];
    return c;
}

int main() {
    int a[80],b[80],n,i,k,t;
    double x,y;
    printf("Size Insertion Merge\n");
    for(n=20;n<=80;n+=10) {
        x=y=0;
        for(k=0;k<100;k++) {
            for(i=0;i<n;i++) a[i]=i;
            for(i=n-1;i>0;i--) {
                int r=rand()%(i+1);
                t=a[i]; a[i]=a[r]; a[r]=t;
            }
            for(i=0;i<n;i++) b[i]=a[i];
            x+=insertion(a,n);
            y+=merge(b,0,n-1);
        }
        printf("%d %.2f %.2f\n",n,x/100,y/100);
    }
    return 0;
}


clc; clear; close all;

n = 20:10:80;

% Replace with your actual C output
merge = [65 110 165 220 280 340 405];
insertion = [110 240 430 660 940 1270 1650];

plot(n,merge,'b-o',n,insertion,'r-o','LineWidth',2);

title('Average Case: Merge Sort vs Insertion Sort');
xlabel('Input Size (n)');
ylabel('Number of Comparisons');
legend('Merge Sort','Insertion Sort');
grid on;
