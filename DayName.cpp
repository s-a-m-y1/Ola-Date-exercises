#include<iostream>
#include<string>
using namespace std;
short DayOfWeekOrder(short Day, short Month, short Year)
{
short a, y, m;
a = (14 - Month) / 12;
y = Year - a;
m = Month + (12 * a) - 2;
// Gregorian:
//0:sun, 1:Mon, 2:Tue...etc
return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m)
/ 12)) % 7;
}
string DayShortName(short DayOfWeekOrder)
{
string arrDayNames[] = {
"Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
return arrDayNames[DayOfWeekOrder];
}

int main()
{
   cout<< DayShortName(DayOfWeekOrder(1,2,2022))<<endl;
    return 0;
}
