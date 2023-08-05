#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int main()
{
    int Ninput,Nstate;
    cout<<"Enter the number of states"<<endl;
    cin>>Nstate;
    char Nfastate[Nstate];
    cout<<"Enter States\n";
    for(int i=0;i<Nstate;i++)
    {
        cin>>Nfastate[i];
    }


    cout<<"Enter the number of Inputs\n";
    cin>>Ninput;
    char Nfainput[Ninput];
    cout<<"Enter Inputes\n";
    for(int i=0;i<Ninput;i++)
    {
        cin>>Nfainput[i];
    }


    char NFAtable[Nstate][Ninput][100];
    cout<<"Enter The transition table for NFA\n";
    for(int i=0;i<Nstate;i++)
    {
        for(int j=0;j<Ninput;j++)
        {
            cin>>NFAtable[i][j];
        }
    }


    cout<<"Enter Initial state\n";
    char initial;
    cin>>initial;
    cout<<"Enter the final state\n";
    char final;
    cin>>final;

    //printing Transition table for NFA
    for(int i=0;i<Ninput;i++)
        cout<<"\t"<<Nfainput[i];
        cout<<"\n";
        cout<<"-----------------------------------------\n";

    for(int i=0;i<Nstate;i++)
    {
        if(initial==Nfastate[i])
            cout<<"->"<<Nfastate[i]<<"\t";
        else if(final==Nfastate[i])
            cout<<" *"<<Nfastate[i]<<"\t";
        else
           cout<<"  "<<Nfastate[i]<<"\t";
        for(int j=0;j<Ninput;j++)
        {
            cout<<NFAtable[i][j]<<"\t";
        }
        cout<<endl;
    }


    char Dfastate[100][100];
    Dfastate[0][0]=Nfastate[0];

    char DFAtable[20][Ninput][100];

     DFAtable[0][0]=NFAtable[0][0];
    DFAtable[0][1][0]=NFAtable[0][1];


    stack<string>stack;
    stack.push(DFAtable[0][0]);
    stack.push(DFAtable[0][1]);



    return 0;
}
/*
4
A B C D
2
0 1
A AB
PHI C
PHI D
D D
A
D

*/
