#include<bits/stdc++.h>
int main()
{
    int table[5][5]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    for(int i=1;i<5;i++)
    {
        for(int j=0;j<i;j++)
        {
            printf("%d   ",table[i][j]);
        }
        printf("\n");
    }
}
