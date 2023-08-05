#include <bits/stdc++.h>
using namespace std;

const string g="A1B";

void PrintGrammar(){
    printf("The given grammar:\n");
    cout << "S --> " << g << "\n";
    cout << "A --> 0A|e\n";
    cout << "B --> 0B|1B|e\n";
}

int main()
{
    PrintGrammar();

    printf("\nEnter a string as input: ");
    string input, output;
    cin>>input;

    int first_one=-1;

    for(int i=0;i<input.size();i++){
        if(input[i]=='1'){
            first_one=i;
            break;
        }
    }

    // if there exists no 1
    // the string is never accepted
    if(first_one==-1){
        printf("The string is not accepted for this language,\n\n");
        return 0;
    }

    printf("The string is accepted for the given grammar.\n");
    printf("Below showing the left derivative of the string:\n\n");

    cout << " --> " << g << "\n";

    output="";

    // for the terminals before non-terminal 1
    for(int i=0;i<first_one;i++){
        output+='0';
        cout << " --> ";
        for(auto ele:output){
            cout << ele;
        }
        cout << g << "\n";
    }

    // now handle the epsilon of A
    cout << " --> ";
    for(auto ele:output){
        cout << ele ;
    }
    cout << "e1B" << "\n";

    for(int i=first_one;i<input.size();i++){
        output+=input[i];
        cout << " --> ";
        for(auto ele:output){
            cout << ele;
        }
        cout << "B\n";
    }

    // now handle the epsilon of A
    cout << " --> ";
    for(auto ele:output){
        cout << ele ;
    }
    cout << "e" << "\n";

    cout << " --> ";
    for(auto ele:output){
        cout << ele ;
    }
    printf("\n\n");
}
