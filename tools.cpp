#include "tools.h"
using std::stack;
using std::pair;
using std::vector;
tools::tools(){}
double tools::most(int num)//jiu's
{
    double ans=1;
    for(int i=1;i<=num;i++)
        ans*=i;
    return ans;
}
int tools::getPriority(QChar ch)//定义符号的优先级
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

vector<QString> tools::toCalable(QString equ)//将表达式转化为逆波兰表达式
{
    stack<QString> ans;
    stack<QString> temp;
    QString digit;
    for(auto ch:equ)
    {
        if(ch.isDigit()||ch=='.')//添加小数计算
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


std::pair<double,std::vector<QString>> tools::calculate(QString equ)//计算逆波兰表达式
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
                return std::make_pair(INT_MAX,std::vector<QString>());
                    ans=num2/num1;
                }
                else if(ch=='^')
                    ans=pow(num2,num1);
            }
            st.push(ans);
        }
    }
    return std::make_pair(st.top(),cal);
}
