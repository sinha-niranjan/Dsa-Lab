#include <bits/stdc++.h>
using namespace std;

bool operand(char);
bool higher(char, char);
void exp(string);

void exp(string s)
{
    stack<char> st;
    string result;
    s.push_back(')');
    st.push('(');
    int i = 0;
    while (!st.empty())
    {
        char ch = s[i];
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        {
            result.push_back(ch);
        }
        else if (operand(ch))
        {
            if (higher(ch, st.top()) || st.top() == '(' || st.top() == ')')
            {
                st.push(ch);
            }
            else if (ch == ')')
            {
                while (st.top() != '(')
                {
                    char temp = st.top();
                    st.pop();
                    result.push_back(temp);
                }
                st.pop();
            }
            else
            {

                while (!higher(ch, st.top()) && st.top() != '(' && st.top() != ')') 
                {
                    char temp = st.top();
                    st.pop();
                    result.push_back(temp);
                }
                st.push(ch);
            }
        }
         
        i++;
        for (auto j : result)
        {
            cout << j;
        }
        cout << endl;
    }

    for (auto i : result)
    {
        cout << i;
    }
    cout << endl;
}

bool operand(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '(' || ch == ')')
    {
        return true;
    }
    else
        return false;
}

bool higher(char ch, char top)
{
    if(ch == '(') return true;

    if (top == '^')
    {
        if (ch == '(')
            return true;
        return false;
    }
    else if (top == '*' || top == '/')
    {
        if (ch == '^' || ch == '(')
        {
            return true;
        }
        else
            return false;
    }
    else if (top == '+' || top == '-')
    {
        if (ch == '^' || ch == '*' || ch == '/' || ch == '(')
        {
            return true;
        }
        else
            return false;
    }
}

int main()
{

    string s = " a+(b*c-(d/e-f)*g)*h";
    exp(s);

    return 0;
}

// a+(b*c-(d/e-f)*g)*h