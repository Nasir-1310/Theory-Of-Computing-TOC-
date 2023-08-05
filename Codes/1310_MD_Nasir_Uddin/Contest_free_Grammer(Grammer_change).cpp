#include<bits/stdc++.h>
using namespace std;
int main()
{

    string S,A,B;
    S="S -->0AB0";
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
    int length=s.length();

   if(s[0]!='0' || s[length-1]!='0' || length<2)
    printf("The String is not Accepted\n");
    else
    {

        printf("String is Accepted\n");

        printf("\nThe Leftmost Derivations of the String is :\n--------------------------------------------\n");
        printf("S--->>0AB0\n");

        for(int i=1; i<s.length(); i++)
        {
            if(s[i]=='0' && one==0)
            {
                cout<<" --->>";
                for(int j=0; j<=i; j++)
                    cout<<s[j];
                // if(s[i+1]==NULL)
                printf("AB0\n");

                if(s[i+1]=='1')
                {
                    cout<<" --->>";
                    for(int j=0; j<=i; j++)
                        cout<<s[j];
                    cout<<"eB0";
                    cout<<"\n --->>";
                    for(int j=0; j<=i; j++)
                        cout<<s[j];
                    cout<<"B0"<<endl;
                    one++;

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
                    printf("B0\n");

                }
                else
                {

                    cout<<" --->>";
                    for(int j=0; j<=i; j++)
                        cout<<s[j];
                    cout<<"B0\n";

                    cout<<" --->>";
                    for(int j=0; j<=i; j++)
                        cout<<s[j];
                    cout<<"e0\n --->>";

                    for(int j=0; j<=i; j++)
                        cout<<s[j];
                    cout<<"0\n";

                }
            }

        }

    }
    return 0;
}

