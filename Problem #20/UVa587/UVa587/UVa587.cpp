// UVa587.cpp : Darien Cortez : hastyhooligan

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	string line, direction;
	int cnt = 1, steps;//counter for map # and the amount of steps
	const double diagnol = sqrt(2.0) / 2;//diagnol value
	
	cin >> line;
	while (line != "END")
	{
		double x = 0.0, y = 0.0;//x, y coordinates

		//*******************************************************************
		//the following code gets rid of the period and switches commas
		//to spaces to allow the stream to read each instruction separately
		//*******************************************************************
		line = line.erase(line.size() - 1);
		replace(line.begin(), line.end(), ',', ' ');
		stringstream ss(line);

		//updates x and y coordinates based on instruction
		while (ss >> steps >> direction)
		{
			if (direction == "N")
				y += steps;

			else if (direction == "NE")
			{
				x += diagnol * steps;
				y += diagnol * steps;
			}
			
			else if (direction == "E")
				x += steps;

			else if (direction == "SE")
			{
				x += diagnol * steps;
				y -= diagnol * steps;
			}

			else if (direction == "S")
				y -= steps;
				
			else if (direction == "SW")
			{
				x -= diagnol * steps;
				y -= diagnol * steps;
			}

			else if (direction == "W")
				x -= steps;

			else if (direction == "NW")
			{
				x -= diagnol * steps;
				y += diagnol * steps;
			}
		}

		double d = sqrt((x*x) + (y*y));//distance to the treasure

		cout << fixed << setprecision(3) << "Map #" << cnt << "\nThe treasure is located at (" << x << "," << y
			<< ").\nThe distance to the treasure is " << d << ".\n\n";

		cnt++;
		cin >> line;
	}

   return 0;
}