
#include<iostream>
using namespace std;
struct Date
{
   
    short Day =0;
    short Month=0;
    short Year=0;
};
bool isLeapYear(short Year)
{
return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short NumberOfDaysInAMonth(short Month, short Year)
{
if (Month < 1 || Month>12)
return 0;
int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) :
days[Month - 1];
}
bool IsLastDayInMonth(Date Date)
{
return (Date.Day == NumberOfDaysInAMonth(Date.Month,
Date.Year));
}
bool IsLastMonthInYear(short Month)
{
return (Month == 12);
}
int main()
{
    return 0;
}