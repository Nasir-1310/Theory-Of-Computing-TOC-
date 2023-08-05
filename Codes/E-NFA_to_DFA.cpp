#include <bits/stdc++.h>
//#include <ctype.h>
using namespace std;

string add_all_unique_character(string existing, string new_string)
{
    set<char> sum;

    for (int i = 0; i < existing.size(); i++)
    {
        if (!sum.count(existing[i]))
            sum.insert(existing[i]);
    }

    for (int i = 0; i < new_string.size(); i++)
    {
        if (!sum.count(new_string[i]))
           sum.insert(new_string[i]);
    }

    string ans;
    for (char c : sum)
    {
        ans+= c;
    }

    return ans;
}

int main()
{

     // freopen("ENFA2.txt", "r", stdin);


    int nState, nAlphabets, nFinishStates;
    string startState;
    vector<char> states, alphabets;
    vector<pair<string, vector<string>>> table, Final_DFA;


    vector<pair<string, string>> dTable, eClosure;
    set<string> finishingStates, Finished, DFA;
    stack<string> track;

    cin >> nState;

    for (int i = 0; i < nState; i++)
    {
        char s;
        cin >> s;
        states.push_back(s);
        cout<<endl;
    }
    cin >> nAlphabets;

    alphabets.push_back('e');
    for (int i = 0; i < nAlphabets; i++)
    {
        char a;
        cin >> a;
        alphabets.push_back(a);
        cout<<endl;
    }

    nAlphabets += 2;
    for (int i = 0; i < nState; i++)
    {

        string state;
        cin >>state;

        vector<string>input;
        string eChild;
        eChild += state;

        for (int j = 0; j < nAlphabets - 1; j++)
        {
            string c;
            cin >> c;
            input.push_back(c);

            if (j == 0 and c != "phi")
                eChild += c;
        }

        table.push_back({state,input});
        eClosure.push_back({state, eChild});
    }
    cin >> startState;
    cin >> nFinishStates;

    for (int i = 0; i < nFinishStates; i++)
    {
        string b;
        cin >> b;
        finishingStates.insert(b);
    }

    cout << "\nTransition Table for E-NFA\n";
    for (int i = 0; i < nAlphabets - 1; i++) // -1 for epsilon col
    {
        cout << "\t\t" << alphabets[i];
    }

    cout << "\t\t"<< "e-closure";
    cout << "\n------------------------------------------------------------------------\n";

    // table info
    for (int i = 0; i < nState; i++)
    {
        if (table[i].first == startState)
            cout << "->" << table[i].first << "\t\t";
        else if (finishingStates.count(table[i].first))
            cout << " *" << table[i].first << "\t\t";
        else
            cout << "  " << table[i].first << "\t\t";

        for (int j = 0; j < nAlphabets; j++)
        {


            if (j == nAlphabets - 1)
            {
                cout << eClosure[i].second;
            }
            else
            {
                cout << table[i].second[j] << "\t\t";
            }
        }

        cout << endl;
    }

    cout << "\n\n";
// Constructing E-NFA to Final_DFA

    dTable.push_back({table[0].first, eClosure[0].second});

    track.push(dTable[0].second);

    while (1)
    {
        if (track.empty())
            break;

        string p_th_state = track.top();
        track.pop();

        if (Finished.count(p_th_state) or p_th_state == "Z")
        {
            continue;
        }

        string newDFASubState;
        vector<string> indivStates;
        vector<string> tmp;

        // extract states from the clutter
        for (int k = 0; k < p_th_state.size(); k++)
        {
            if (isalpha(p_th_state[k]))
            {
                string p;

                p += p_th_state[k];
                indivStates.push_back(p);
            }

        }



        // now find corresponding sub states of each singly identified states
        for (int i = 1; i < nAlphabets - 1; i++)
        {
            // in each turn I have to calculate for a single alphabet...
            for (string singleState : indivStates)
            {
                for (int j = 0; j < nState; j++)
                {
                    if (table[j].first == singleState)
                    {
                        string toFind = table[j].second[i];

                        for (int c = 0; c < toFind.size(); c++)
                        {
                            //each state a multiple character takle aita check korar jonno for loop with k
                            for (int k = 0; k < nState; k++)
                            {
                                string unique ;
                                unique = toFind[c];

                                if (table[k].first  == unique)
                                {
                                        newDFASubState =add_all_unique_character(newDFASubState, eClosure[k].second);

                                    break;
                                }
                            }
                        }


                    }
                }

            }

            if(newDFASubState.size() ==0) newDFASubState = "Z";
            tmp.push_back(newDFASubState);

            if (!DFA.count(newDFASubState))
            {
                DFA.insert(newDFASubState);
                track.push(newDFASubState);
            }
            newDFASubState.clear();

        }

        Finished.insert(p_th_state);
        Final_DFA.push_back({p_th_state, tmp});

        tmp.clear();

    }

   printf("---------------------------------FINAL DFA----------------------------------\n");

    cout << "\nTransition Table for DFA\n";
    for (int i = 1; i < nAlphabets-1; i++)
    {
        cout << "\t\t" << alphabets[i];
    }

    cout << "\n-----------------------------------------------\n";


    for (int i = 0; i < Final_DFA.size(); i++)
    {

        if (i == 0)
            cout << "->" << Final_DFA[i].first << "\t\t";
        else
        {
            int flag = 1;
            // to find finishing state is it match or not
            for (int j = 0; j < Final_DFA[i].first.size(); j++)
            {

                char ch = Final_DFA[i].first[j];
                string s;
                s += ch;

                if (finishingStates.count(s))
                {
                    cout << " *" << Final_DFA[i].first << "\t\t";
                    flag = 0;
                    break;
                }
            }

            if (flag)
                cout << Final_DFA[i].first << "\t\t";
        }

        for (int j = 0; j < nAlphabets - 2; j++)
        {
            cout << Final_DFA[i].second[j] << "\t\t";
        }

        cout << endl;
    }
}

/*
3
A B C
2
a b
A B C phi
B phi A phi
C phi B BC
A
1
C

*/
