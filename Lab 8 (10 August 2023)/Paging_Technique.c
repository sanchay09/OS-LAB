#include<stdio.h>
#define MAX 50

int main()
{
    int page[MAX],i,n,f,ps,off,pno;
    int choice=0;

    printf("Enter the number of pages in memory: ");
    scanf("%d",&n);

    printf("\nEnter Page size: ");
    scanf("%d",&ps);

    printf("\nEnter number of frames: ");
    scanf("%d",&f);
    for(i=0;i<n;i++)
        page[i]=-1;

    printf("\nEnter the Page Table\n");

    printf("(Enter frame no as -1 if that page is not present in any frame)\n\n");

    printf("\nPage No\t\tFrame No\n-------\t\t-------");
    for(i=0;i<n;i++)
    {
        printf("\n\n%d\t\t",i);
        scanf("%d",&page[i]);
    }

    do
    {
        printf("\n\nEnter the logical address(i.e,page no & offset):");
        scanf("%d%d",&pno,&off);

        if(page[pno]==-1)
            printf("\n\nThe required page is not available in any of frames");
        else
            printf("\nPhysical address(i.e,frame no & offset):%d,%d",page[pno],off);

        printf("\n\nDo you want to continue(1/0)?:");
        scanf("%d",&choice);
    }while(choice==1);

    return 1;
}
