#include<bits/stdc++.h>
using namespace std;
#define max 100
#define a 1
#define ab 2
#define abc 3
#define abcd 4
#define ad 5
#define abd 6



int main()
{
    char str[max];
    string path[max];
    int f = a;
    int head = -1;

    printf("Enter your string : ");
    scanf("%s",str);

    for(int i = 0 ; str[i] != '\0' ; i++)
    {
        switch(f)
        {
        case a :
            if(str[i] == '0')
            {
                f = a;
                cout<<"(a,0)-->a"<<endl;
                head++;
                path[head] = "a";
            }
            else if(str[i] == '1')
            {
                f = ab;
                cout<<"(a,1)->>ab"<<endl;
                head++;
                path[head] = "ab";
            }
            break;
        case ab :
            if(str[i] == '0')
            {
                f = a;
                head++;
                cout<<"(ab,0)->>a"<<endl;
                path[head] = "a";
            }
            else if(str[i] == '1')
            {
                f = abc;
                head++;
                cout<<"(ab,1)->>abc"<<endl;
                path[head] = "abc";
            }
            break;
        case abc :
            if(str[i] == '0')
            {
                f = a;
                cout<<"(abc,0)->>a"endl;
                head++;
                path[head] = "a";
            }
            else if(str[i] == '1')
            {
                f = abcd;
                head++;
                cout<<"(abc,1)->>abcd"<<endl;
                path[head] = "abcd";
            }
            break;
        case abcd :
            if(str[i] == '0')
            {
                f = ad;
                head++;
                cout<<"(abc,0)->>ad"<<endl;
                path[head] = "ad";
            }
            else if(str[i] == '1')
            {
                f = abcd;
                head++;
                cout<<"(abc,1)->>abcd";
                path[head] = "abcd";
            }
            break;
        case ad :
            if(str[i] == '0')
            {
                f = ad;
                head++;
                cout<<"(ad,0)->>ad"<<endl;
                path[head] = "ad";
            }
            else if(str[i] == '1')
            {
                f = abd;
                head++;
                cout<<"(ad,1)->>abd"<<endl;
                path[head] = "abd";
            }
            break;
        case abd :
            if(str[i] == '0')
            {
                f = ad;
                head++;
                cout<<"(abd,ad)->>ad"<<endl;
                path[head] = "ad";
            }
            else if(str[i] == '1')
            {
                f = abcd;
                head++;
                cout<<"(abd,1)->>abcd";
                path[head] = "abcd";
            }
            break;

        }
    }

    if(f == abcd||   f == abd || f == ad)
    {
        printf("\n\nYour string is accepted!\n\n");
        printf("path : ");
        for(int j = 0 ; j <=head ; j++) cout << path[j] << " ";
        printf("\n");
    }
    else printf("\n\nYour String is not accepted!\n");

    return 0;
}
