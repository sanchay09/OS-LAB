/*Write a C program to simulate the following non-pre-emptive CPU
scheduling algorithm to find turnaround time and waiting time.
🡪 SJF (Non-pre-emptive)*/

#include<stdio.h>
 int main()
{
    int Burst_time[20],process[20],Waiting_time[20],Turn_around_time[20],i,j,n,total=0,pos,temp;
    float avg_Waiting_time,avg_Turn_around_time;
    printf("Enter number of process:");
    scanf("%d",&n);

    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&Burst_time[i]);
        process[i]=i+1;
    }

   //sorting
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(Burst_time[j]<Burst_time[pos])
                pos=j;
        }

        temp=Burst_time[i];
        Burst_time[i]=Burst_time[pos];
        Burst_time[pos]=temp;

        temp=process[i];
        process[i]=process[pos];
        process[pos]=temp;
    }

    Waiting_time[0]=0;


    for(i=1;i<n;i++)
    {
        Waiting_time[i]=0;
        for(j=0;j<i;j++)
            Waiting_time[i]+=Burst_time[j];

        total+=Waiting_time[i];
    }

    avg_Waiting_time=(float)total/n;
    total=0;

    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        Turn_around_time[i]=Burst_time[i]+Waiting_time[i];
        total+=Turn_around_time[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",process[i],Burst_time[i],Waiting_time[i],Turn_around_time[i]);
    }

    avg_Turn_around_time=(float)total/n;
    printf("\n\nAverage Waiting Time=%f",avg_Waiting_time);
    printf("\nAverage Turnaround Time=%f\n",avg_Turn_around_time);
}
