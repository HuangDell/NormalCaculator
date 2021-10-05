#ifndef TOOLS_H
#define TOOLS_H
#define CHECK \
if(st.empty())\
    return INT_MAX;
#include <QString>
#include <stack>
#include <vector>
#include <QDebug>
#include <cmath>


class tools
{
public:
    tools();
    static double calculate(QString equ);
    static int getPriority(QChar ch);
    static std::vector<QString> toCalable(QString equ);
    static double most(int num);
};

#endif // TOOLS_H
