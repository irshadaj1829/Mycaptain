#include<bits/stdc++.h>
using namespace std;
 
class Time
{
    private:
        int seconds;
        int h,m,s;
    public:
        void getTime(void);
        void convertIntoSeconds(void);
        void displayTime(void);
};
 
void Time::getTime(void)
{
    cout << "Enter time: "<<'\n';
    
    cout << "Hours : ";
	cin >> h;
	
    cout << "Minutes : ";          
	cin >> m;
	
    cout << "Seconds : ";          
	cin >> s;
}
 
void Time::convertIntoSeconds(void)
{
    seconds = h*3600 + m*60 + s;
}
 
void Time::displayTime(void)
{
    cout << "The time is = " << setw(2) << setfill('0') << h << ":"
                             << setw(2) << setfill('0') << m << ":"
                             << setw(2) << setfill('0') << s << endl;
    cout << "Time in total seconds: " << seconds;
}
 
int main()
{
	Time T;
     
    T.getTime();
    T.convertIntoSeconds();
    T.displayTime();
}
