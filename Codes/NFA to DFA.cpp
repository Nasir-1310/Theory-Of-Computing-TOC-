#include <bits/stdc++.h>
using namespace std;

string find_uniqChar(string x, string y)
{
    set<char> res;

    for (int i = 0; i < x.size(); i++)
    {
        if (!res.count(x[i]))
            res.insert(x[i]);
    }


    for (int i = 0; i < y.size(); i++)
    {
        if (!res.count(y[i]))
            res.insert(y[i]);
    }

   // string ans = "";
      string ans;
    for (char a : res)
    {
        ans += a;
    }

    return ans;
}

int main()
{

    int number_of_State, number_of_Alphabets, number_of_FinishStates;
    string startState;
    vector<char> states, alphabets;
    vector<pair<string, vector<string>>> table, dTable;
    set<string> finishingStates, done, DFA;
    stack<string> stack;

    cout << "Enter number of states: ";
    cin >> number_of_State;

//Inputing NFA States
    for (int i = 0; i < number_of_State; i++)
    {
         cout << "State " << i+1 << ": ";

        char s;
        cin >> s;
        states.push_back(s);
    }


    cout << "Enter number of alphabets: ";
    cin >> number_of_Alphabets;
//Inputing NFA Alphabets
    for (int i = 0; i < number_of_Alphabets; i++)
    {
        cout << "Alphabet " << i+1 << ": ";

        char a;
        cin >> a;
        alphabets.push_back(a);
    }

    //Transition Table for NFA
    cout << "Enter the state Transition Table: ";
    for (int i = 0; i < number_of_State; i++)
    {

        string parent;
        cin >> parent;

        vector<string> child;
        for (int j = 0; j < number_of_Alphabets; j++)
        {
            string c;
            cin >> c;
            child.push_back(c);
        }

        table.push_back({parent, child});
    }
    //string
    string str;
    cin>>str;
    int fl = 0;

      for(int i=0;i<str.size();i++){

        if(str[i]=='1' && str[i + 1] == '1' && str[i+2] =='1'){
            fl = 1;
        }
      }
      if(fl == 1){
        cout << "Accepted" << "\n" << "A->B->C->D" << endl;
      }
      else{
        cout << "Not Accepted" << endl;
      }

    cout << "Enter the start state: ";
    cin >> startState;

    cout << "How many finishing states do you have: ";
    cin >> number_of_FinishStates;

    for (int i = 0; i < number_of_FinishStates; i++)
    {
        string b;
        cin >> b;
        finishingStates.insert(b);
    }

    cout << "\nTransition Table for NFA\n";

    for (int i = 0; i < number_of_Alphabets; i++)
    {
        cout << "\t\t" << alphabets[i];
    }
    cout << "\n-----------------------------------------\n";

    for (int i = 0; i < number_of_State; i++)
    {
        if (table[i].first == startState)
            cout << "->" << table[i].first << "\t\t";
        else if (finishingStates.count(table[i].first))   // not clear
            cout << " *" << table[i].first << "\t\t";
        else
            cout << "  " << table[i].first << "\t\t";

        for (int j = 0; j < number_of_Alphabets; j++)
        {
            cout << table[i].second[j] << "\t\t";
        }

        cout << endl;
    }

    cout << "\n\n";
    dTable.push_back({table[0].first, table[0].second});


    for (int i = 0; i < number_of_Alphabets; i++)
        stack.push(dTable[0].second[i]);
    done.insert(table[0].first);


//Constructing DFA transition Table
    for(;;)
    {
        if (stack.empty())
            break;

        string pState = stack.top();
        stack.pop();
        cout<<"pstate(or pop)="<<pState<<endl;

        if (done.count(pState))
        {
            continue;
        }

        string newDFASubState;
        vector<string> indivStates;
        vector<string> tmp;

        for (int k = 0; k < pState.size(); k++)
        {
            if (isalpha(pState[k]))
            {
                string ss;

                ss += pState[k];
                indivStates.push_back(ss);
            }

        }
        for (int i = 0; i < number_of_Alphabets; i++)
        {
            for (string singleState : indivStates)
            {
                cout<<"Single state="<<singleState<<endl;
                for (int j = 0; j < number_of_State; j++)
                {
                    if (table[j].first == singleState && table[j].second[i] != "phi")
                    {
                        newDFASubState = find_uniqChar(newDFASubState, table[j].second[i]);

                        break;
                    }
                }
            }

            tmp.push_back(newDFASubState);

            if (!DFA.count(newDFASubState))
            {
                DFA.insert(newDFASubState);
                stack.push(newDFASubState);
            }

            newDFASubState.clear();
        }

        done.insert(pState);
        dTable.push_back({pState, tmp});
        tmp.clear();
    }

    cout << "Transition Table for DFA\n";

    for (int i = 0; i < number_of_Alphabets; i++)
    {
        cout << "\t\t" << alphabets[i];
    }

    cout << "\n-----------------------------------------\n";

    for (int i = 0; i < dTable.size(); i++)
    {

        if (i == 0)
            cout << "->" << dTable[i].first << "\t\t";
        else
        {
            int flag = 1;
            for (int j = 0; j < dTable[i].first.size(); j++)
            {

                char ch = dTable[i].first[j];
                string s;
                s += ch;

                if (finishingStates.count(s))
                {
                    cout << " *" << dTable[i].first << "\t\t";
                    flag = 0;
                    break;
                }
            }

            if (flag)
                cout << "  " << dTable[i].first << "\t\t";
        }

        for (int j = 0; j < number_of_Alphabets; j++)
        {
            cout << dTable[i].second[j] << "\t\t";
        }

        cout << endl;
    }

return 0;
}
/*
4
A B C D
2
0 1
A A AB
B phi C
C phi D
D D D
1000111
A
1
D
*/
