
#include<iostream>
using namespace std;
struct Date
{
   
    short Day =0;
    short Month=0;
    short Year=0;
};
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
short ReadDays()
{
short Day;
cout << "\nPlease enter a Day? ";
cin >> Day;
return Day;
}
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

Date IncreaseDateByOneDay(Date Date)
{
if (IsLastDayInMonth(Date))
{
if (IsLastMonthInYear(Date.Month))
{
Date.Month = 1;
Date.Day = 1;
Date.Year++;
}
else
{
Date.Day = 1;
Date.Month++;
}
}
else
{
Date.Day++;
}
return Date;
}


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

Date IncreaseDateByOneDay(Date Date)
{
if (IsLastDayInMonth(Date))
{
if (IsLastMonthInYear(Date.Month))
{
Date.Month = 1;
Date.Day = 1;
Date.Year++;
}
else
{
Date.Day = 1;
Date.Month++;
}
}
else
{
Date.Day++;
}
return Date;
}
Date ReadDate()
{
    Date date;
    date.Day =ReadDays();
    date.Month = ReadMonth();
    date.Year =ReadYear();

}
Date GetsystemDate()
{
Date Date;
time_t t = time(0);
tm* now = localtime(&t);
Date.Year = now->tm_year + 1900;
Date.Month = now->tm_mon + 1;
Date.Day = now->tm_mday;
return Date;

}


int main()
{
    
}