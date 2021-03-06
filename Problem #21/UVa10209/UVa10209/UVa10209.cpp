// UVa10209.cpp : Darien Cortez : hastyhooligan

#include <iostream>
#include <cmath>
#include <iomanip>

#define PI acos(-1)//formula for PI

using namespace std;

int main()
{
    double a;//length of one side of outer square
    while (cin >> a)
    {
        double A = a * a;//area of outer square
        
		double striped = A *(1 - sqrt(3) + PI/3);//formula for the middle section
        double dotted = A * (2 * sqrt(3) - 4 + PI/3);//formula for the dotted section
        double checkered = A - striped - dotted;//subtract the outer area but the dotted and striped areas to find this
        
        cout << fixed << setprecision(3) << striped << " " << dotted << " " << checkered << endl;
    }
    
    return 0;
}