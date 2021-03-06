// car.cpp : Defines the entry point for the console application.
//

//  main.cpp
//  Week2DylanMaynardPart3Car
//  Created by Dylan Maynard on 1/29/18.
//  Copyright © 2018 Dylan Maynard. All rights reserved.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <cstdlib>
using namespace std;

#define LOW_BATTERY 20
#define LOW_GAS 3
#define FEET_PER_GAS_UNIT 50.00
#define FEET_PER_BATTERY_UNIT 15.00
#define MAX_GAS 10.00
#define MAX_CHARGE 100.00
#define INPUT 20

// CLASS CAR
class Car
{
public:  // Functions
	Car();
	void check_battery();
	void check_gas();
	double get_gas();
	double get_battery();
	void start_car();
	void turn_right();
	void turn_left();
	void go_straight();
	void shift_gear_forward();
	void shift_gear_backward();
	void park_car();
	void move_car(); // 1 unit of gas / 50 feet  1% batter / 100 feet
	void print_menu();
	void fill_up_gas();
	void new_battery();

private:  // Variables
	double battery_level;
	double amount_of_gas;
	int num_of_gears;
	bool car_in_motion = false;
	bool started = false;
	bool parked = true;
	bool right = false;
	bool left = false;
	bool straight = false;
	bool in_drive = false;
	bool in_reverse = false;
};

Car::Car() :amount_of_gas{ MAX_GAS }, battery_level{ MAX_CHARGE } {}

void Car::print_menu()  // Interactive menu to assist user
{
	cout << "------------------------------------------------" << endl;
	cout << "| Welcome to your Virtual Car help menu        |" << endl;
	cout << "| Here are the directions                      |" << endl;
	cout << "| Car starts with full tank of gas             |" << endl;
	cout << "| 10 units of gas #1 unit = 50 feet            |" << endl;
	cout << "| Enter \"h\" to see the help menu               |" << endl;
	cout << "| Enter \"start\" to start car                   |" << endl;
	cout << "| Enter \"check gas\" to check gas               |" << endl;
	cout << "| Enter \"check battery\" to check battery       |" << endl;
	cout << "| Enter \"fill gas\" to fill up gas              |" << endl;
	cout << "| Enter \"new battery\" to get a new battery     |" << endl;
	cout << "| Enter \"left\" to turn left                    |" << endl;
	cout << "| Enter \"right\" to turn right                  |" << endl;
	cout << "| Enter \"straight\" to go straight              |" << endl;
	cout << "| Enter \"shift forward\" to shift car forward   |" << endl;
	cout << "| Enter \"shift backward\" to shift car backward |" << endl;
	cout << "| Enter \"move\" to move car                     |" << endl;
	cout << "| Enter \"park\" to park car                     |" << endl;
	cout << "| Enter \":kill\" to kill program                |" << endl;
	cout << "------------------------------------------------" << endl;
}

void Car::check_gas() // Tells user current amount of gas
{
	cout << " Car currently has " << amount_of_gas << " units of gas" << endl;
	cout << " [";
	for (int i = 0; i < amount_of_gas; i++)
	{
		cout << "#";
	}
	for (int j = 0; j < 10 - amount_of_gas; j += 1) {
		cout << " ";
	}
	cout << "] " << endl;
	cout << " About " << amount_of_gas * FEET_PER_GAS_UNIT << " feet left of gas!\n " << endl;
}

void Car::check_battery() // Tells user current battery charge
{
	cout << " Car currently has " << battery_level << " % charge" << endl;
	cout << " [";
	for (int i = 0; i < battery_level; i += 10)
	{
		cout << "#";
	}
	for (int j = 0; j < 100 - battery_level; j += 10)
	{
		cout << " ";
	}
	cout << "] " << endl;
	cout << " About " << battery_level * FEET_PER_BATTERY_UNIT << " feet left of battery!\n " << endl;
}

double Car::get_gas()
{
	return amount_of_gas;
}

double Car::get_battery()
{
	return battery_level;
}

void Car::fill_up_gas()
{
	amount_of_gas = MAX_GAS;
	cout << " Gas filled up! " << endl;
	check_gas();
}

void Car::new_battery()
{
	battery_level = MAX_CHARGE;
	cout << " Battery fully charged! " << endl;
	check_battery();
}

void Car::start_car()
{
	if (!started && amount_of_gas > 0 && battery_level > 0 && !car_in_motion && parked)
	{
		started = true;
		cout << " Car started! " << endl;
		while (1)
		{
			cout << " Would gear would you like to shift the car into? " << endl;
			cout << "(drive) or (reverse) > ";
			string gear;
			cin >> gear;
			if (gear == "drive")
			{
				shift_gear_forward();
				break;
			}
			else if (gear == "reverse")
			{
				shift_gear_backward();
				break;
			}
			else
			{
				cout << " \nEnter a valid input! " << endl;
			}
		}
		cin.get();
	}
	else if (started)
	{
		cout << " Car is already started!" << endl;
	}
	else if (amount_of_gas == 0)
	{
		cout << " Car is out of gas! " << endl;
	}
	else if (battery_level == 0)
	{
		cout << " Car battery is dead! " << endl;
	}
}

void Car::turn_left()
{
	if (started && in_drive && !parked)
	{
		left = true;
		right = false;
		straight = false;
		cout << " Car turned left! Enter move next to enter by how far! " << endl;
	}
	else if (!started)
	{
		cout << " Car is not started! " << endl;
	}
	else if (started && !in_drive)
	{
		cout << " Car is not in drive! " << endl;
	}
}

void Car::turn_right()
{
	if (started && in_drive && !parked)
	{
		right = true;
		left = false;
		straight = false;
		cout << " Car turned right! Enter move next to enter by how far! " << endl;
	}
	else if (!started)
	{
		cout << " Car is not started! " << endl;
	}
	else if (started && !in_drive)
	{
		cout << " Car is not in drive! " << endl;
	}
}

void Car::go_straight()
{
	if (started && in_drive && !parked)
	{
		straight = true;
		left = false;
		right = false;
		cout << " Car is going straight! Enter move next to enter by how far! " << endl;
	}
	else if (!started)
	{
		cout << " Car is not started!" << endl;
	}
	else if (started && !in_drive)
	{
		cout << " Car is not in drive!" << endl;
	}
}

void Car::shift_gear_forward()
{
	if (started && !in_drive)
	{
		cout << " Car shifted to drive! " << endl;
		in_drive = true;
		in_reverse = false;
		parked = false;
		straight = true;
		left = false;
		right = false;
	}
	else if (in_drive)
	{
		cout << " Car is already in drive! " << endl;
	}
	else if (!started)
	{
		cout << " Car is not been started yet! " << endl;
	}
}

void Car::shift_gear_backward()
{
	if (started && !in_reverse)
	{
		cout << " Car shifted to reverse!" << endl;
		in_reverse = true;
		in_drive = false;
		parked = false;
		straight = false;
		left = false;
		right = false;
	}
	else if (in_reverse)
	{
		cout << " Car is already in reverse! " << endl;
	}
	else if (!started)
	{
		cout << " Car is not been started yet! " << endl;
	}
}

void Car::move_car()
{
	if (started && amount_of_gas >= 0)
	{
		bool valid = false;
		int feet = 0;
		while (!valid)
		{
			valid = true;
			cout << " How much feet would you like to move by? > ";
			cin >> feet;
			if (cin.fail())
			{
				cin.clear(); //This corrects the stream.
				cin.ignore(); //This skips the left over stream data.
				cout << " Please enter an Integer only. " << endl;
				valid = false;
			}
		}
		if (feet > 0)
		{
			double minus_gas;
			double minus_battery;

			minus_gas = feet / FEET_PER_GAS_UNIT;
			minus_battery = feet / FEET_PER_BATTERY_UNIT;

			if (straight && amount_of_gas - minus_gas >= 0 && battery_level - minus_battery >= 0)
			{
				amount_of_gas -= minus_gas;
				battery_level -= minus_battery;
				cout << " Moving for " << feet << " feet! " << endl;
				if (amount_of_gas < LOW_GAS)
				{
					cout << " \n Running low on gas... Fill up soon! " << endl;
					check_gas();
				}
				if (battery_level < LOW_BATTERY)
				{
					cout << " \n Running low on charge... Get new battery soon! " << endl;
					check_battery();
				}
			}
			else if (left && amount_of_gas - minus_gas >= 0 && battery_level - minus_battery >= 0)
			{
				amount_of_gas -= minus_gas;
				battery_level -= minus_battery;
				cout << " Turning left for " << feet << " feet! " << endl;
				left = false;
				straight = true;
			}
			else if (right && amount_of_gas - minus_gas >= 0 && battery_level - minus_battery >= 0)
			{
				amount_of_gas -= minus_gas;
				battery_level -= minus_battery;
				cout << " Turning right for " << feet << " feet! " << endl;
				right = false;
				straight = true;
			}
			else if (in_reverse && amount_of_gas - minus_gas >= 0 && battery_level - minus_battery >= 0)
			{
				amount_of_gas -= minus_gas;
				battery_level -= minus_battery;
				cout << " Reversing for " << feet << " feet! " << endl;
			}
			else if (amount_of_gas - minus_gas <= 0)
			{
				cout << " Not enought gas! " << endl;
				cout << " Not gas! " << endl;
			}
			else if (battery_level - minus_battery <= 0)
			{
				cout << " Not enough charge! " << endl;
				cout << " check Battery! " << endl;
			}
			cin.get();
		}
		else if (feet <= 0)
		{
			cout << " Enter a positive integer only! " << endl;
			cin.get();
		}
	}
	else if (!started)
	{
		cout << " Car has not been started yet! " << endl;
	}
}

void Car::park_car() // parks car and changes logic of variables accordingly
{
	if (started && !parked) // checks if car is started or already parked
	{
		started = false;
		parked = true;
		car_in_motion = false;
		in_reverse = false;
		in_drive = false;
		cout << " Car has been stopped and is now parked" << endl;
	}
	else if (parked)
	{
		cout << " Car is already Parked! " << endl;
	}
}

enum moves // enumeration to use switch satement for user input for strings
{
	h,
	start,
	check_gas,
	check_battery,
	fill_gas,
	new_battery,
	turn_left,
	turn_right,
	straight,
	shift_forward,
	shift_backward,
	move_car,
	park,
	kill
};

void clear_screen() // clears screen after every input
{
	cout << string(100, '\n');
}

int main(int argc, const char * argv[]) {
	cout << " Dylan Maynard \t 1/29/18 \n" << endl;

	char answer[INPUT];

	// map string and enumeration to use switch statement for user input for strings
	map<string, moves> map_moves{ { "h", h },{ "start",start },{ "check gas",check_gas },{ "check battery", check_battery },{ "fill gas",fill_gas },{ "new battery",new_battery },{ "left",turn_left },{ "right",turn_right },{ "straight",straight },{ "shift forward",shift_forward },{ "shift backward",shift_backward },{ "move",move_car },{ "park",park },{ ":kill",kill } };

	Car car;
	car.print_menu();
	cout << "";
	do
	{
		if (car.get_gas() <= 0)
		{
			cout << " Car ran out of gas! " << endl;
			return(0);
		}
		if (car.get_battery() <= 0)
		{
			cout << " Car ran out of baterry! " << endl;
			return(0);
		}
		cout << "Enter a move > ";
		cin.getline(answer, INPUT);
		switch (map_moves[answer]) {
		case h:
			clear_screen();
			car.print_menu();
			break;

		case start:
			clear_screen();
			car.print_menu();
			car.start_car();
			break;

		case check_gas:
			clear_screen();
			car.print_menu();
			car.check_gas();
			break;

		case check_battery:
			clear_screen();
			car.print_menu();
			car.check_battery();
			break;

		case fill_gas:
			clear_screen();
			car.print_menu();
			car.fill_up_gas();
			break;

		case new_battery:
			clear_screen();
			car.print_menu();
			car.new_battery();
			break;

		case turn_left:
			clear_screen();
			car.print_menu();
			car.turn_left();
			break;

		case turn_right:
			clear_screen();
			car.print_menu();
			car.turn_right();
			break;

		case straight:
			clear_screen();
			car.print_menu();
			car.go_straight();
			break;

		case shift_forward:
			clear_screen();
			car.print_menu();
			car.shift_gear_forward();
			break;

		case shift_backward:
			clear_screen();
			car.print_menu();
			car.shift_gear_backward();
			break;

		case move_car:
			clear_screen();
			car.print_menu();
			car.move_car();
			break;

		case park:
			clear_screen();
			car.print_menu();
			car.park_car();
			break;

		case kill:
			cout << " Detected program end command... " << endl;
			return(0);

		default:
			return(0);
			break;
		}
	} while (1);
	return (0);
}
