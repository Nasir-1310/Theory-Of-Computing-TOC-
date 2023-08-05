#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
int main()
{

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    double initial=60,final=200;
    for(int i=0;i<=180;i++)
    {
        double x=i;
        double y=50*sin((3.1415/180)*x)+100;
        line(initial,final,x+initial,y+final);
        initial=x+initial;
        final=y+final;

    }

     getch();
    closegraph();

}
