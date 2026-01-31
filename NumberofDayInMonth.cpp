#include<iostream>
using namespace std;
short ReadYear()
{
    short Year;
    cout<<"Year : ";
    cin>>Year;
    return Year;
}
short ReadMonth()
{
    short month;
    cout<<"Month : ";
    cin>>month;
    return month;
}
bool IsLeapYear(short Year)
{
    return(Year%4==0&&Year%100!=0)||(Year%400==0);

}
short NumberofDayInMonth(short Month , short Year)
{
    if(Month<1||Month>12)return 0;
    //{31,28,31,30,31,30,31,31,30,31,30,31}
    // 0  1  2  3  4  5  6  7  8  9  10 11//
    int ArrDaysInMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    return(Month==2)?(IsLeapYear(Year)?29:28) :ArrDaysInMonth[Month-1];
}
int main()
{
    short y =ReadYear();
    short m =ReadMonth();
    cout<<"Days = "<<NumberofDayInMonth(m, y );
    

    return 0;
}