////13  
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
short ReadDays()
{
short Day;
cout << "\nPlease enter a Day? ";
cin >> Day;
return Day;
}
bool IsLeapYear(short Year)
{
    return(Year%4==0&&Year%100!=0)||(Year%400==0);

}
short NumberOfDaysInAMonth(short Month , short Year)
{
    if(Month<1||Month>12)return 0;
    //{31,28,31,30,31,30,31,31,30,31,30,31}
    // 0  1  2  3  4  5  6  7  8  9  10 11//
    int ArrDaysInMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    return(Month==2)?(IsLeapYear(Year)?29:28) :ArrDaysInMonth[Month-1];
}
short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month,
short Year)
{
short TotalDays = 0;
for (int i = 1; i <= Month - 1; i++)
{
TotalDays += NumberOfDaysInAMonth(i, Year);
}
TotalDays += Day;
return TotalDays;
}
struct Date
{
   
    short day =0;
    short Month=0;
    short Year=0;
};

Date GetDateFromOrderInYear(short DateOrderInYear , short Year)
{
    Date date;
    short monttdays =0;
    int    RemainingDays =DateOrderInYear;
    date.Year =Year;
    date.Month =1;
    while (true)
    {
        monttdays = NumberOfDaysInAMonth(date.Month ,date.Year);
       if (RemainingDays>monttdays)
       {
        RemainingDays-=monttdays;
        date.Month++;
       }
      else
      {
        date.day = RemainingDays;
        break;
      }
       
       
        
    }
    
return date;
}


int main()
{
    // short d =ReadDay();
    // short m =ReadMonth();
    short d =ReadDays();
    short y =ReadYear();

Date date = GetDateFromOrderInYear(d,y);
cout<<date.day<<endl;
cout<<date.Month<<endl;
cout<<date.Year<<endl;

}
