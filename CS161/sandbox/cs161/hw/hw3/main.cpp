#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Adult {
private:	
	  const double RATE = 13.00;
	 const double SURCHARGE = 1.25;
	int _num;
public:
	Adult() {
		_num = 0;
	};

	~Adult() {};

	double cost() {
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

	~Child() {};

	double cost() {
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

	~Vehicle() {}

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

	double price() {
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

	double cost() {
		return (Vehicle::price() + Vehicle::fuel_surcharge());
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
		vehicle->set(0,0,0);
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

	double cost() {
		return (adult->cost() + child->cost() + vehicle->cost());
		
	}
};

int main() {

	Ticket *t = new Ticket();
	t->set("adult", 3);
	t->set("child", 1);
	t->set("vehicle", 1, 25, 8);
	cout << t->cost() << endl;


	system("pause");
	return 0;
}
