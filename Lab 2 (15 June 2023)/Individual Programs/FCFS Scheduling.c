/*Write a C program to simulate the following non-pre-emptive CPU
scheduling algorithm to find turnaround time and waiting time.
🡪FCFS*/

#include<stdio.h>
int main()
{
    int n, i, j, Burst_time[10], Waiting_time[10], Turn_around_time[10];
    float avg_Turn_around_time=0, avg_Waiting_time=0;

    printf("Please enter the total number of processes:");
    scanf("%d",&n);

    printf("\nEnter The Process Burst Time\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&Burst_time[i]);
    }
    Waiting_time[0]=0;

    for(i=1;i<n;i++)
    {
        Waiting_time[i]=0;
        for(j=0;j<i;j++)
            Waiting_time[i]+=Burst_time[j];
    }

    printf("\nProcess\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time");

    for(i=0;i<n;i++)
    {
        Turn_around_time[i]=Burst_time[i]+Waiting_time[i];
        avg_Waiting_time+=Waiting_time[i];
        avg_Turn_around_time+=Turn_around_time[i];
        printf("\nP[%d]\t\t%d\t\t\t%d\t\t\t\t%d",i+1,Burst_time[i],Waiting_time[i],Turn_around_time[i]);
    }

    avg_Waiting_time =(float)(avg_Waiting_time)/(float)i;
    avg_Turn_around_time=(float)(avg_Turn_around_time)/(float)i;
    printf("\nAverage Waiting Time:%.2f",avg_Waiting_time);
    printf("\nAverage Turnaround Time:%.2f",avg_Turn_around_time);

    return 0;
}

