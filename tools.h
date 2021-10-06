#ifndef TOOLS_H
#define TOOLS_H
#define CHECK \
if(st.empty())\
    return std::make_pair(INT_MAX,std::vector<QString>());
#include <QString>
#include <stack>
#include <vector>
#include <QDebug>
#include <cmath>
#include <utility>


class tools
{
public:
    tools();
    static std::pair<double,std::vector<QString>> calculate(QString equ);
    static int getPriority(QChar ch);
    static std::vector<QString> toCalable(QString equ);
    static double most(int num);
};

#endif // TOOLS_H
