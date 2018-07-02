//Lesson 3 excercise 2
//Sunny Lan
//2018-03-27

#include <iostream>
#include <ctime>
using namespace std;

int main(){
    srand(time(0));
    int nm=rand()%(1000-100)+100;
    cout << "Random number: "<<nm<<endl;
    int tot=0;
    int dig;
    for(dig=1;nm;dig++)
    {
        cout << "Digit "<<dig<<" is "<<nm%10<<endl;
        tot+=nm%10;
        nm/=10;
    }

    cout << "Sum of digits is "<<tot<<endl;
    cout << "Average of digits is "<<tot/(dig-1.0)<<endl;
}
