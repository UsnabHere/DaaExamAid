#include <stdio.h>
#include <stdlib.h>

int insertionSort(int a[], int n)
{
    int i, j, temp;
    int count = 1;

    for (i = 1; i < n; i++)
    {
        count++;
        temp = a[i];
        j = i - 1;

        while (j >= 0 && temp < a[j])
        {
            count++;
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = temp;
    }

    return count;
}

int main()
{
    int a[100], n, i, k;
    int best, worst;
    double average;
    long total;

    printf("Size\tBest\tAverage\tWorst\n");

    for (n = 20; n <= 80; n += 10)
    {
        for (i = 0; i < n; i++)
            a[i] = i + 1;

        best = insertionSort(a, n);

        for (i = 0; i < n; i++)
            a[i] = n - i;

        worst = insertionSort(a, n);

        total = 0;

        for (k = 0; k < 100; k++)
        {
            for (i = 0; i < n; i++)
                a[i] = i + 1;

            for (i = n - 1; i > 0; i--)
            {
                int r = rand() % (i + 1);
                int t = a[i];
                a[i] = a[r];
                a[r] = t;
            }

            total += insertionSort(a, n);
        }

        average = total / 100.0;

        printf("%d\t%d\t%.2f\t%d\n",
               n, best, average, worst);
    }

    return 0;
}

clc;
clear;
close all;

n = [20 30 40 50 60 70 80];

% Calculated values from C program
best_cal = [20 30 40 50 60 70 80];

avg_cal = [114.73 240.97 436.52 659.43 ...
    942.18 1270.05 1648.68];

worst_cal = [210 465 820 1275 1830 2485 3240];

% Theoretical values
best_theory = n;
avg_theory = n.^2;
worst_theory = n.^2;

% Best Case
subplot(3,1,1);
plot(n,best_theory,'b-o','LineWidth',2);
hold on;
plot(n,best_cal,'r--*','LineWidth',2);
title('Best Case: Theoretical vs Calculated');
xlabel('Input Size (n)');
ylabel('Count');
legend('Theoretical','Calculated');
grid on;

% Average Case
subplot(3,1,2);
plot(n,avg_theory,'b-o','LineWidth',2);
hold on;
plot(n,avg_cal,'r--*','LineWidth',2);
title('Average Case: Theoretical vs Calculated');
xlabel('Input Size (n)');
ylabel('Count');
legend('Theoretical','Calculated');
grid on;

% Worst Case
subplot(3,1,3);
plot(n,worst_theory,'b-o','LineWidth',2);
hold on;
plot(n,worst_cal,'r--*','LineWidth',2);
title('Worst Case: Theoretical vs Calculated');
xlabel('Input Size (n)');
ylabel('Count');
legend('Theoretical','Calculated');
grid on;
