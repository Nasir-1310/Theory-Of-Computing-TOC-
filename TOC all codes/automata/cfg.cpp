#include <iostream>
using namespace std;
string taken_input, maching;
string grammer[3]={"E+E","E*E","(E)"};
int main_len;

int string_length_calculate(string input)
{
    int i;
    for(i=0;input[i]!='\0';i++);
    return i;
}
bool check_grammer(int start)
{
    int dis=0;
    for(int i=0;i<3;i++)
    {
        if((taken_input[start]==grammer[i][0])&&(taken_input[start+1]==grammer[i][1])&&(taken_input[start+2]==grammer[i][2]))
        {
            dis=1;
            break;
        }
    }
    if(dis==1) return true;
    else
        return false;

}

void short_string(int start)
{
    taken_input[start]='E';
    for(int i=start; i<(main_len-3);i++)
    {
        taken_input[i+1]=taken_input[i+3];
    }
    main_len = main_len -3;
}


int main()
{
    int i,j;
    cout<<"Enter Input: ";
    cin>>taken_input;
    main_len = string_length_calculate(taken_input);

    //int taken_input_len= calc_string_len(taken_input);

    for(i=0;i<main_len;i++)
    {
        if((taken_input[i]=='0')||(taken_input[i]=='1'))
        taken_input[i]='E';
    }

    //cout<<taken_input;

    for(i=0;i<(string_length_calculate(taken_input)-1);i++)
    {
        if(check_grammer(i))
        {
            short_string(i);
            i=0;
        }
        if(main_len<2)
        {
            break;
        }


    }
    if((main_len==1)||(main_len==0))
    cout<<"String accept the grammer";
    else
    cout<<"String doesn't accept the grammer";

    return 0;
}

//0+(1+(0+1)+1)
//0*(1+(0*1))+1
