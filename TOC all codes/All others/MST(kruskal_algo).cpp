#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s="A1B";
    cout<<"input grammer:";
    string s1,main1="",main2="";
    cin>>s1;
    int first_one=0,next_one=0,f=0;
    //00101

    set<char>v;
    for(int i=0;i<s1.size();i++)
    {
        v.insert(s1[i]);
    }
    if(v.size()==1&&v.find('0')!=v.end())cout<<"NOT ACCEPTED"<<endl;
    else
    {
     cout<<"ACCEPTED"<<endl;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]=='1')
        {
            first_one=i;
            break;
        }

    }
    next_one=first_one+1;
    //cout<<first_one<<endl;
    cout<<"--> A1B"<<endl;
    if(s1[0]=='1') cout<<"--> e1B"<<endl;
   // cout<<s[0]<<endl;
    for(int i=0;i<first_one;i++)
    {
        main1+="0";
        main2="B";

        cout<<"--> "+main1+"A"+"1"+main2<<" ";
        cout<<endl;

        if(first_one==0){
        cout<<"--> "+main1+"e1"+main2<<" ";
        cout<<endl;
        cout<<"--> "+main1+"1"+main2<<" ";
        cout<<endl;
        }
    }
   //cout<<"main2: "<<main2<<endl;
  main2="";
   for(int i=next_one;i<s1.size();i++)
   {

      if(s1[i]=='0')
      {
          main2+="0";
      }
      else if(s1[i]=='1')
      {
          main2+="1";
      }
      cout<<"--> "+main1+"1"+main2+"B"<<" ";
      // cout<<endl;
      if(i==s1.size()-1)
      {
          cout<<endl;
        cout<<"--> "+main1+"1"+main2+"e"<<" ";
        cout<<endl;
        cout<<"--> "+main1+"1"+main2+" ";
        cout<<endl;
      }
      cout<<endl;
   }
    }

}


