#include "tools.h"
using std::stack;
using std::vector;
tools::tools(){}
double tools::most(int num)
{
    double ans=1;
    for(int i=1;i<=num;i++)
        ans*=i;
    return ans;
}
int tools::getPriority(QChar ch)
{
    switch(ch.toLatin1()){
        case '+':return 1;
        case '-':return 1;
        case '/':return 2;
        case '*':return 2;
        case '^':return 3;
        case '!':return 3;
    }
    return 0;
}

vector<QString> tools::toCalable(QString equ)
{
    stack<QString> ans;
    stack<QString> temp;
    QString digit;
    for(auto ch:equ)
    {
        if(ch.isDigit())
        {
            digit.push_back(ch);
            continue;
        }
        else if(!digit.isEmpty())
        {
            ans.push(digit);
            digit.clear();
        }
        if(ch=='(')
            temp.push(ch);
        else if(ch==')')
        {
            if(temp.empty())
                return vector<QString>();
            while(temp.top()!='(')
            {
                ans.push(temp.top());
                temp.pop();
            }
            temp.pop();
        }
        else
        {
            if(temp.empty() || getPriority(ch)>getPriority(temp.top()[0]))
                temp.push(ch);
            else
            {
                while(!temp.empty() && getPriority(temp.top()[0])>=getPriority(ch))
                {
                    ans.push(temp.top());
                    temp.pop();
                }
                temp.push(ch);
            }
        }
    }
    if(!digit.isEmpty())
        ans.push(digit);
    while(!temp.empty())
    {
        ans.push(temp.top());
        temp.pop();
    }
    vector<QString> st(ans.size());
    for(int i=ans.size()-1;i>=0;i--)
    {
        st[i]=ans.top();
        ans.pop();
    }
    return st;
}


double tools::calculate(QString equ)
{
    bool is;
    double ans=0;
    auto cal=toCalable(equ);
    stack<double> st;
    for(auto ch:cal)
    {
        auto temp=ch.toDouble(&is);
        if(is)
        {
            st.push(temp);
        }
        else
        {
            CHECK;
            auto num1=st.top();
            st.pop();
            if(ch=='!')
            {
                st.push(most(num1));
                continue;
            }
            else
            {
                CHECK;
                auto num2=st.top();
                st.pop();
                if(ch=='+')
                    ans=num1+num2;
                else if(ch=='-')
                    ans=num2-num1;
                else if(ch=='*')
                    ans=num1*num2;
                else if(ch=='/')
                {
                    if(num2==0)
                        return INT_MAX;
                    ans=num2/num1;
                }
                else if(ch=='^')
                    ans=pow(num2,num1);
            }
            st.push(ans);
        }
    }
    return st.top();
}
