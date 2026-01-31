



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
int GetDifferenceInDays(Date Date1, Date Date2, bool
IncludeEndDay = false)
{
int Days = 0;
while (IsDate1BeforeDate2(Date1, Date2))
{
Days++;
Date1 = IncreaseDateByOneDay(Date1);
}
return IncludeEndDay ? ++Days : Days;
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
short DayOfWeekOrder(Date Date)
{
return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}
string DayShortName(short DayOfWeekOrder)
{
string arrDayNames[] = {
"Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
return arrDayNames[DayOfWeekOrder];
}
short IsEndOfWeek(Date Date)
{
return DayOfWeekOrder(Date) == 6;
}
bool IsWeekEnd(Date Date)
{
//Weekends are Fri and Sat
short DayIndex = DayOfWeekOrder(Date);
return (DayIndex == 5 || DayIndex == 6);
}
bool IsBusinessDay(Date Date)
{

return !IsWeekEnd(Date);
}
short DaysUntilTheEndOfWeek(Date Date)
{
return 6 - DayOfWeekOrder(Date);
}
short DaysUntilTheEndOfMonth(Date Date1)
{
Date EndOfMontDate;
EndOfMontDate.Day = NumberOfDaysInAMonth(Date1.Month,
Date1.Year);
EndOfMontDate.Month = Date1.Month;
EndOfMontDate.Year = Date1.Year;
return GetDifferenceInDays(Date1, EndOfMontDate, true);
}
short DaysUntilTheEndOfYear(Date Date1)
{
Date EndOfYearDate;
EndOfYearDate.Day = 31;
EndOfYearDate.Month = 12;
EndOfYearDate.Year = Date1.Year;
return GetDifferenceInDays(Date1, EndOfYearDate, true);
}
short ReadDay()
{
short Day;
cout << "\nPlease enter a Day? ";
cin >> Day;
return Day;
}
short ReadMonth()
{
short Month;
cout << "Please enter a Month? ";
cin >> Month;
return Month;
}
short ReadYear()
{
short Year;
cout << "Please enter a Year? ";
cin >> Year;
return Year;
}
Date ReadFullDate()
{
Date Date;
Date.Day = ReadDay();
Date.Month = ReadMonth();
Date.Year = ReadYear();
return Date;
}
Date GetSystemDate()
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
Date Date1 = GetSystemDate();
cout << "\nToday is " << DayShortName(DayOfWeekOrder(Date1))
<< " , "
<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year <<
endl;
//---------------------
cout << "\nIs it End of Week?\n";
if (IsEndOfWeek(Date1))
cout << "Yes it is Saturday, it's of Week.";
else
cout << "No it's Not end of week.";
//---------------------
cout << "\n\nIs it Weekend?\n";
if (IsWeekEnd(Date1))
cout << "Yes it is a week end.";
else
cout << "No today is " <<
DayShortName(DayOfWeekOrder(Date1)) << ", Not a weekend.";
//---------------------
cout << "\n\nIs it Business Day?\n";
if (IsBusinessDay(Date1))
cout << "Yes it is a business day.";
else
cout << "No it is NOT a business day.";
//---------------------
cout << "\n\nDays until end of week : "
<< DaysUntilTheEndOfWeek(Date1) << " Day(s).";
//---------------------
cout << "\nDays until end of month : "
<< DaysUntilTheEndOfMonth(Date1) << " Day(s).";
//---------------------
cout << "\nDays until end of year : "
<< DaysUntilTheEndOfYear(Date1) << " Day(s).";
system("pause>0");
return 0;
}