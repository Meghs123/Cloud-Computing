//MEGHA SINGH 1928300
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int np;
    int Ttat=0,ct=0;
    int Twt=0;
    float Atat,Awt;
    printf("Enter no. of process= ");
    scanf("%d",&np);
    int e_time[np],p[np],at[np],temp,tat[np],wt[np];
    printf("Enter the arrival time of process:\n");
    for(int i=0;i<np;i++)
      {
        scanf("%d",&at[i]);
        p[i]=i+1;
      }
    printf("Enter the burst time of the processes:\n");
    for(int i=0;i<np;i++)
        scanf("%d",&e_time[i]);

    // sorting the data in ascending order of arrival time
    for(int i=0; i<np; i++)
    {
        for(int j=0; j<np; j++)
        {
            if(at[i]<at[j])
            {
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                temp=e_time[i];
                e_time[i]=e_time[j];
                e_time[j]=temp;
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    //for Total TAT and WT
    printf("P\tAT\tCPU Burst\tCT\tTAT\tWT\n");
    printf("-------------------------------\n");
    for(int i=0;i<np;i++)
    {
        ct+=e_time[i];
        tat[i]=ct-at[i];
        Ttat+=tat[i];
        wt[i]=tat[i]-e_time[i];
        Twt+=wt[i];
        printf("%d      \t%d\t%d \t\t%d \t%d  \t%d\n",p[i],at[i],e_time[i],ct,tat[i],wt[i]);
    }
    //for average tat and wt
    Atat=(float)Ttat/np;
    Awt=(float)Twt/np;
    printf("Total TAT=%d  Avg TAT=%lf",Ttat,Atat);
    printf("\n");
    printf("Total WT=%d   Avg WT=%lf\n",Twt,Awt);
}
