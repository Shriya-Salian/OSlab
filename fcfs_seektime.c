#include<stdio.h>
#include<stdlib.h>
int main()
{
    int RQ[100],i,n,TotalHeadMoment=0,initial;
    printf("Enter the request sequence:\n");
    scanf("%d",RQ[i]);
    for(i=0;i<n;i++)
    scanf("%d",&RQ[i]);
    printf("Enter the initial head position:\n");
    scanf("%d",initial);
    printf("Sequence of requesr access:\n");
    for(i=0;i<n;i++)
    {
        printf("%d",RQ[i]);
        TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
        initial=RQ[i];
    }
    printf("\nTotal head movement is %d :",TotalHeadMoment);
    return 0;
}