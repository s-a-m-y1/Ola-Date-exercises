#include<iostream>
using namespace std;
short ReadYear()
{
    short Year;
    cout<<"Year : ";
    cin>>Year;
    return Year;
}
bool IsLeapYear(short Year)
{
    return(Year%4==0&&Year%100!=0)||(Year%400==0);

}
short NumberOfDaysInAYear(short Year)
{
return IsLeapYear(Year) ? 366 : 365;
}
short NumberOfHoursInAYear(short Year)
{
return NumberOfDaysInAYear(Year) * 24;
}
int NumberOfMinutesInAYear(short Year)
{
return NumberOfHoursInAYear(Year) * 60;
}
int NumberOfSecondsInAYear(short Year)
{
return NumberOfMinutesInAYear(Year) * 60;
}
int main()
{
    
    short Year =ReadYear();
  cout<<"NumberOfDaysInAYear = "<<NumberOfDaysInAYear(Year)<<endl;
    cout<<"NumberOfHoursInAYear = "<<NumberOfHoursInAYear(Year)<<endl;
      cout<<"NumberOfMinutesInAYear = "<<NumberOfMinutesInAYear(Year)<<endl;
        cout<<"NumberOfSecondsInAYear = "<<NumberOfSecondsInAYear(Year)<<endl;

} 
