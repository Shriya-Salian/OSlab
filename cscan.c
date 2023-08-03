//check

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int RQ[100],i,j,n,TotalHeadMoment=0,initial,size,move;
    printf("Enter the number of Requests:\n");
    scanf("%d",&n);
    printf("Enter the request sequence:\n");
    for(i=0;i<n;i++)
     scanf("%d",&RQ[i]);
    printf("Enter initial head position:\n");
    scanf("%d",&initial);
    printf("Enter the total disk size:");
    scanf("%d",&size);
    printf("Enter the head movement direction for high 1 and for low 0:\n");
    scanf("%d",&move);
    //logic for C-Scandisk scheduling
    //logic for sort the request array//
    for(i=0;i<n;i++)
    {
       for(j=0;j<n-i;j++)
       {
        if (RQ[j]>RQ[j+1])
        {
            int temp;
            temp=RQ[j];
            RQ[j]=RQ[j+1];
            RQ[j+1]=temp;
        }
       }
    }
    int index;
    for(i=0;i<n;i++)
    {
        if(initial<RQ[i])
        {
            index=i;
            break;
        }
    }
    if (move==1)
    {
        printf("Sequence of the request access:\n");
        for (i=index;i<n;i++)
        {
            printf("%d\t",RQ[i]);
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
        }
        TotalHeadMoment=TotalHeadMoment+abs(size-RQ[i-1]-1);
        TotalHeadMoment=TotalHeadMoment+abs(size-1-0);
        initial=0;
            for (i=0;i<index;i++)
            {
                printf("%d",RQ[i]);
                TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
                initial=RQ[i];
            }
    }
        else
        {
            printf("Sequence request access :\n");
            for(i=index-1;i>=0;i--)
            {
                printf("%d\t",RQ[i]);
                TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
                initial=RQ[i];
            }
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i+1]-0);
            TotalHeadMoment=TotalHeadMoment+abs(size-1-0);
            initial=size-1;
            for(i=n-1;i>=index;i--)
            {
              printf("%d",RQ[i]);
                TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial); 
                initial=RQ[i]; 
            }
        }
        printf("\nTotal head movement is %d",TotalHeadMoment);
        return 0;
}
/*
Output: 
Enter the number of Requests:
7
Enter the request sequence:

82 170 43 140 24 160 190
Enter initial head position:
50
Enter the total disk size:200
Enter the head movement direction for high 1 and for low 0:
1
Sequence of the request access:
82      140     160     170     02443
Total head movement is 391*/