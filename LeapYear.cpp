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
int main()
{
    if (IsLeapYear(ReadYear()))
    {
      cout<<"Leap Year ";
    }
    else{
          cout<<"Not Leap Year ";
    }
    
    
} 
