/*************************************************************************************
Name: Alex Narayan
Date: 4/11/2016
Assignment: Homework #3
Description: Total finder for a Ferry system
Source: Found help at cplusplus.com and stackoverflow
Other: Used classes even though you probably wanted us to use arrays and what not
I know how to use arrays but I was just itching to learn more about classes
granted how they were used here was likely full of rookie mistakes
*************************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//make the classes static since I am just using them as fancy data structures?
class Adult {
private:
	const double RATE = 13.00;
	const double SURCHARGE = 1.25;
	int _num;
public:
	Adult() {
		_num = 0;
	};

	~Adult() {
	};//is the destructor not supposed to be public?

	double total() {
		return (Adult::subtotal() + Adult::surchage());
	}

	double subtotal() {
		return (_num * RATE);
	}

	double surchage() {
		return (_num * SURCHARGE);
	}

	void set(int num) {
		_num = num;
	}

};

class Child {
private:
	const double RATE = 6.50;
	const double SURCHARGE = 1.25;
	int _num;

public:
	Child() {
		_num = 0;
	};

	~Child() {
	};

	double total() {
		return (Child::subtotal() + Child::surchage());
	}

	double subtotal() {
		return (_num * RATE);
	}

	double surchage() {
		return (_num * SURCHARGE);
	}

	void set(int num) {
		_num = num;
	}

};

class Vehicle {
private:
	const double NON_OVERSIZED_RATE = 43.00;
	const double NON_OVERSIZED_FUEL_SURCHAGE = 4.15;
	const double NON_OVERSIZED_ADDEDLENGTH_RATE = 2.15;

	const double OVERSIZED_RATE = 69.00;
	const double OVERSIZED_FUEL_SURCHAGE = 10.40;
	const double OVERSIZED_ADDEDLENGTH_RATE = 3.45;

	const double MAX_LENGTH = 20;
	const double NON_OVERSIZED_MAX_HEIGHT = 7;

	double _num;
	double _length;
	double _height;

public:
	Vehicle() {
		_num = 0;
		_length = 0;
		_height = 0;
	}

	~Vehicle() {
	}

	Vehicle(double num, double length, double height) {
		_num = num;
		_length = length;
		_height = height;
	}

	void set(double num, double length, double height) {
		_num = num;
		_length = length;
		_height = height;
	}

	double subtotal() {
		if (_height <= NON_OVERSIZED_MAX_HEIGHT && _length <= MAX_LENGTH) {
			return (NON_OVERSIZED_RATE * _num);
		}
		else if (_height <= NON_OVERSIZED_MAX_HEIGHT && _length > MAX_LENGTH) {
			return (
				(NON_OVERSIZED_RATE * _num)
				+ ((_length - MAX_LENGTH) * _num * NON_OVERSIZED_ADDEDLENGTH_RATE)
				);
		}
		else if (_height > NON_OVERSIZED_MAX_HEIGHT && _length <= MAX_LENGTH) {
			return (OVERSIZED_RATE * _num);
		}
		else if (_height > NON_OVERSIZED_MAX_HEIGHT && _length > MAX_LENGTH) {
			return (
				(OVERSIZED_RATE * _num)
				+ ((_length - MAX_LENGTH) * _num * OVERSIZED_ADDEDLENGTH_RATE)
				);
		}
	}
	//simplify
	double fuel_surcharge() {
		if (_height <= NON_OVERSIZED_MAX_HEIGHT && _length <= MAX_LENGTH) {
			return (NON_OVERSIZED_FUEL_SURCHAGE * _num);
		}
		else if (_height <= NON_OVERSIZED_MAX_HEIGHT && _length > MAX_LENGTH) {
			return (
				(NON_OVERSIZED_FUEL_SURCHAGE * _num)
				);
		}
		else if (_height > NON_OVERSIZED_MAX_HEIGHT && _length <= MAX_LENGTH) {
			return (OVERSIZED_FUEL_SURCHAGE * _num);
		}
		else if (_height > NON_OVERSIZED_MAX_HEIGHT && _length > MAX_LENGTH) {
			return (
				(OVERSIZED_FUEL_SURCHAGE * _num));
		}
	}

	double total() {
		return (Vehicle::subtotal() + Vehicle::fuel_surcharge());
	}

};

class Ticket {
private:
	Adult *adult = new Adult();
	Child *child = new Child();
	Vehicle *vehicle = new Vehicle();

public:
	Ticket() {
		adult->set(0);
		child->set(0);
		vehicle->set(0, 0, 0);
	};

	Ticket(int numAdults, int numChildren) {
		adult->set(numAdults);
		child->set(numChildren);
	}
	~Ticket() {};

	void set(string item, int value) {
		if (item == "adult") {
			adult->set(value);
		}
		else if (item == "child") {
			child->set(value);
		}
		else {
			;//throw an exception?
		}
	}

	void set(string item, int num, int length, int height) {
		if (item == "vehicle") {
			vehicle->set(num, length, height);
		}
	}

	double subtotal() {
		return (adult->subtotal() + child->subtotal() + vehicle->subtotal());
	}

	double fuel_surcharge() {
		return (adult->surchage() + child->surchage() + vehicle->fuel_surcharge());
	}

	double total() {
		return (adult->total() + child->total() + vehicle->total());
	}
};

int main() {

	string greeting,
		ask_adults,
		ask_children,
		ask_vehicle,
		ask_vehicle_length,
		ask_vehicle_height;

	int num_adults;
	int num_children;
	char vehicle;
	int vehicle_length;
	char vehicle_over_seven_feet;

	greeting = "Welcome to Alex Narayan's Fare Calculator";
	ask_adults = "How many adults (age 12 or over) are in your party? ";
	ask_children = "How many children (age 5 to 11) are in your party? ";
	ask_vehicle = "Are you driving a vehicle onto the ferry? (y/n): ";
	ask_vehicle_length = "What is the length of the vehicle in feet? ";
	ask_vehicle_height = "Is the vehicle over 7 feet high? (y/n) ";

	cout << greeting << endl;
	cout << ask_adults;
	cin >> num_adults;
	cout << ask_children;
	cin >> num_children;
	cout << ask_vehicle;
	cin >> vehicle;
	
	Ticket *ticket = new Ticket();
	ticket->set("adult", num_adults);
	ticket->set("child", num_children);

	if (vehicle == 'y' || vehicle == 'Y') {
		cout << ask_vehicle_length;
		cin >> vehicle_length;
		cout << ask_vehicle_height;
		cin >> vehicle_over_seven_feet;

		if (vehicle_over_seven_feet == 'y' || vehicle_over_seven_feet == 'Y') {
			ticket->set("vehicle", 1, vehicle_length, 8);
		}
		else {
			ticket->set("vehicle", 1, vehicle_length, 6); 
		}

	}
	else if (vehicle == 'n' || vehicle == 'N') {
		//without vehicle
		ticket->set("vehicle", 0, 19, 6);
	}
	else {
		//throw an exception?
		//todo: learn those
		;
	}
	
	//branching done finally output the results to the user	
	cout << "Your fare is $" << setprecision(2) << fixed << ticket->subtotal() << " plus a fuel surcharge of $" << ticket->fuel_surcharge() << endl;
	cout << setprecision(2) << fixed << "The total amount payable is $" << ticket->total() << endl;
		
	std::system("pause");
	return 0;

}




















