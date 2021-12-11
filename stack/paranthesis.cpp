#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool balancedParanthesis(string s)
{
    stack<char> st;
    for(int i = 0;i <s.length();i++)
    {
        if(s[i] == '(')
        {
            st.push(s[i]);
            //cout << "runned : \n";
        }
        else if(s[i] == ')')
        {
            if(st.empty()) 
                return false;
            else
                st.pop();
        }
    }
    return (st.empty()) ? true : false;
}
int main()
{
    string s = "(((a+b)*(c-d)))";
    int ans = balancedParanthesis(s);
    cout << ans << endl;
    return 0;
}