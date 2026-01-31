



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
bool IsDate1BeforeDate2(Date Date1, Date Date2)
{
// return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
// Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
// Date2.Month ? Date1.Day < Date2.Day : false)) : false);
//or
if(Date1.Year!=Date2.Year)return Date1.Year<Date2.Year;
if(Date1.Month!=Date2.Month)return Date1.Month<Date2.Month;
return Date1.Day<Date2.Day;
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

void SwapDates(Date& Date1, Date& Date2)
{
Date TempDate;
TempDate.Year = Date1.Year;
TempDate.Month = Date1.Month;
TempDate.Day = Date1.Day;
Date1.Year = Date2.Year;
Date1.Month = Date2.Month;
Date1.Day = Date2.Day;
Date2.Year = TempDate.Year;
Date2.Month = TempDate.Month;
Date2.Day = TempDate.Day;
}
int GetDifferenceInDays(Date Date1, Date Date2, bool
IncludeEndDay = false)
{
int Days = 0;
short SawpFlagValue = 1;
if (!IsDate1BeforeDate2(Date1, Date2))
{
//Swap Dates
SwapDates(Date1, Date2);
SawpFlagValue = -1;
}
while (IsDate1BeforeDate2(Date1, Date2))
{
Days++;
Date1 = IncreaseDateByOneDay(Date1);
}
return IncludeEndDay ? ++Days * SawpFlagValue : Days *
SawpFlagValue;
}