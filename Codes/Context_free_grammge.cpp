#include<bits/stdc++.h>
using namespace std;
int main()
{

    string S,A,B;
    S="S -->A1B";
    A="A -->0A|e";
    B="B -->0B|1B|e";

    printf("Given grammar is :\n");
    cout<<"        "<<S<<endl;
    cout<<"        "<<A<<endl;
    cout<<"        "<<B<<endl;

    /* printf("                    S -->A1B\n");
     printf("                    A -->0A|e\n");
     printf("                    B -->0B|1B|e\n");
    */

    printf("Enter a String  :  ");
    string s;
    int count=0,one=0,zero=0;
    cin>>s;
    cout<<"\nGiven String:"<<s<<endl;

    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='0')
            zero++;
    }

    if(zero==s.length())
        printf("\nThe String is not Accepted\n");
    // zero=0;
    else
    {

        printf("String is Accepted\n");

        printf("\nThe Leftmost Derivations of the String is :\n--------------------------------------------\n");
        printf("S--->>A1B\n");

        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='0' && one==0)
            {
                cout<<" --->>";
                for(int j=0; j<=i; j++)
                    cout<<s[j];
                // if(s[i+1]==NULL)
                printf("A1B\n");

                if(s[i+1]=='1')
                {
                    cout<<" --->>";
                    for(int j=0; j<=i; j++)
                        cout<<s[j];
                    cout<<"e1B";
                    cout<<"\n --->>";
                    for(int j=0; j<=i; j++)
                        cout<<s[j];
                    cout<<"1B"<<endl;

                }
            }
            else if(s[i]=='1' && one==0 )
            {
                one++;
                if(i==0 && s[i]=='1')
                {
                    cout<<" --->>e1B"<<endl;
                    //cout<<" --->>1B"<<endl;
                }

                if(s[i+1]!=NULL)
                {
                    cout<<" --->>";
                    for(int j=0; j<=i; j++)
                        cout<<s[j];
                    cout<<"B\n";
                }
                else
                {
                    cout<<" --->>";
                    for(int j=0; j<=i; j++)
                        cout<<s[j];
                    cout<<"e";
                    cout<<"\n --->>";
                    for(int j=0; j<=i; j++)
                        cout<<s[j];
                    cout<<endl;
                }

            }
            else if(s[i]=='0' || s[i]=='1')
            {
                if(s[i+1]!=NULL)
                {
                    cout<<" --->>";
                    for(int j=0; j<=i; j++)
                        cout<<s[j];
                    //if(s[i+1]!=NULL)
                    printf("B\n");

                }
                else
                {

                    cout<<" --->>";
                    for(int j=0; j<=i; j++)
                        cout<<s[j];
                    cout<<"B\n";

                    cout<<" --->>";
                    for(int j=0; j<=i; j++)
                        cout<<s[j];
                    cout<<"e\n --->>";

                    for(int j=0; j<=i; j++)
                        cout<<s[j];
                    cout<<"\n";

                }
            }

        }

    }
    return 0;
}
