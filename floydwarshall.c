
#include <stdio.h>
#define MAX 100

int main() {
    int sizes[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int count = 8;

    FILE *file = fopen("floyd_results.csv", "w");

    fprintf(file, "V,theoretical,calculated\n");
    printf("V\tTheoretical\tCalculated\n");

    for (int s = 0; s < count; s++) {
        int V = sizes[s];
        int graph[MAX][MAX];

        long long iterations = 0;
        long long comparisons = 0;
        long long additions = 0;
        long long updates = 0;

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                graph[i][j] = (i == j) ? 0 : 
                              (i * 7 + j * 3) % 20 + 1;
            }
        }

        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    iterations++;

                    int candidate = graph[i][k] + graph[k][j];
                    additions++;
                    comparisons++;

                    if (candidate < graph[i][j]) {
                        graph[i][j] = candidate;
                        updates++;
                    }
                }
            }
        }

        long long calculated = iterations +
                                comparisons + additions + updates;

        long long theoretical = 4LL * V * V * V;

        printf("%d\t%lld\t\t%lld\n",
               V, theoretical, calculated);

        fprintf(file, "%d,%lld,%lld\n",
                V, theoretical, calculated);
    }

    fclose(file);
    return 0;
}



clc; clear; close all;

n = 10:10:80;

theoretical = 4*n.^3;

calculated = [3034 24180 81412 192740 ...
              376162 649680 1031292 1539000];

disp('Size   Theoretical   Calculated');
disp([n' theoretical' calculated']);

plot(n,theoretical,'b-o','LineWidth',2);
hold on;
plot(n,calculated,'r--s','LineWidth',2);

xlabel('Number of Vertices (n)');
ylabel('Number of Operations');
title('Floyd-Warshall Algorithm - Complexity Analysis');
legend('Theoretical O(n^3)','Calculated');
grid on;
