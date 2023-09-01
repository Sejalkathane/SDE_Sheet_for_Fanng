// Given a number N. The task is to complete the function convertFive()
//  which replaces all zeros in the number with 5 and returns the number.
// Example:

// Input
// 2
// 1004
// 121

// Output
// 1554
// 121



#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=1004;

     // one way::::::::
    // string s=to_string(n);
    // replace(s.begin(),s.end(),'0','5');
    // int num=stoi(s);
    // cout<< num;

    
    // important condition
     //num+=pow(10,i)*dig;   //we place without reverse;
     //help to place number in order as they  like two time reverse


    //secondway:::::::::
    int num=0;
    int i=0;
    while(n)
    {
        int dig=n%10;
        if(dig==0)
        {
            dig=5;
        }
        num+=pow(10,i)*dig;
        i++;
        n=n/10;
    }
    cout<<num;

}