/*This program is a demonstratio of gant chart for fcfs and it works in such a way that
the process with id P1,P2,P3,P4 will duplicate the same id in the 
gant chart as per their burst time and arrival time and it's completion time can be calculated
by finding the index at which it last appeared in the entire array*/
#include <stdio.h>
void main() {
    int n = 5;
    int at[5] = {0, 1, 2, 3, 6};
    int bt[5] = {2, 6, 4, 9, 12};
    int pling[100];   
    int ct[5];           
    int time = 0;
    for (int i = 0; i < n; i++) {
        while (time < at[i]) {
            pling[time] = -1;  
            
            time++;
        }
        for (int j = 0; j < bt[i]; j++) {
            pling[time] = i;
            time++;
        }
        ct[i] = time;
    }
printf("Gantt Chart:\n");
    for (int i = 0; i < time; i++) {
        if (pling[i] == -1) {
            printf("| Idle ");
        } else {
            printf("| P%d ", pling[i] + 1);
        }
    }
    for (int i = 0; i < n; i++) {
        printf("\nP%d Completion Time = %d\n", i, ct[i]);
    }}
