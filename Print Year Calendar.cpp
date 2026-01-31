#include<iostream>
#include<stdio.h>
using namespace std;
short ReadMonth()
{
short Month;
cout << "\nPlease enter a Month? ";
cin >> Month;
return Month;
}
short ReadYear()
{
short Year;
cout << "\nPlease enter a year? ";
cin >> Year;
return Year;
}
bool IsLeapYear(short Year)
{
    return(Year%4==0&&Year%100!=0)||(Year%400==0);

}
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

string MonthShortName(short MonthNumber)
{
string Months[12] = { "Jan", "Feb", "Mar",
"Apr", "May", "Jun",
"Jul", "Aug", "Sep",
"Oct", "Nov", "Dec"
};
return (Months[MonthNumber - 1]);
}
short NumberofDayInMonth(short Month , short Year)
{
    if(Month<1||Month>12)return 0;
    //{31,28,31,30,31,30,31,31,30,31,30,31}
    // 0  1  2  3  4  5  6  7  8  9  10 11//
    int ArrDaysInMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    return(Month==2)?(IsLeapYear(Year)?29:28) :ArrDaysInMonth[Month-1];
}
void PrintCalendar(short month, short Year)
{
    int i = 0;
    short DayOfWeekIndex = DayOfWeekOrder(1, month, Year); 
    short DaysInMonth = NumberofDayInMonth(month, Year); 

   
    printf("\n  _______________ %s _______________\n\n", MonthShortName(month).c_str());
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

 
    for (i = 0; i < DayOfWeekIndex; i++)
    {
        printf("     "); 
    }

    
    for (int j = 1; j <= DaysInMonth; j++)
    {
        printf("%5d", j);

        if (++i == 7) 
        {
            i = 0;
            printf("\n");
        }
    }

    printf("\n  _________________________________\n");
}
void PrintYearCalendar(int Year)
{
printf("\n _________________________________\n\n");
printf(" Calendar - %d\n", Year);
printf(" _________________________________\n");
for (int i = 1; i <= 12; i++)
{
PrintCalendar(i, Year);
}
return;
}

int main()
{

    short y =ReadYear();
    
    PrintYearCalendar(y);
return 0;
}