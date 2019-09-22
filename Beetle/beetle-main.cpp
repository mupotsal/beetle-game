/**
Liberty Mupotsa
FIXME: Place your name(s) and a description of the lab here
See the requirements list in the Lab description for what to do
Beetle image, Getrandom, and Dice by Dr. Jan Pearce, Berea College

Milestone Requirements:
By 8 am on 9/16/19 Milestone 1: Pull repo and make at least one change and commit

By 8 am on 9/18/19 Milestone 2: Make sincere attempt to complete everything,
so you can come to class with questions.  However, it might not yet be working.

By 8 am on 9/20/19 Final Milestone: Lab is complete.


*/

#include <iostream>
#include <string>
#include <random> //needed for Getrandom
#include <chrono> 
using namespace std;

class Getrandom {
	/** Uses <random> and <chrono> from C++11 to return a random integer in range [1..size] */
public:
	Getrandom(int size) {
		auto seed = chrono::system_clock::now().time_since_epoch().count(); //gets a new seed for the randomness
		default_random_engine generator(seed);			//seeds our randomness
		uniform_int_distribution<int> intdist(1, size); //a distibution to make each in-range integer equally likely
		self_rand_int_ = intdist(generator);			//generates the randme number
	}
	int roll() {
		return self_rand_int_;
	}
private:
	int self_rand_int_;
};

class Dice {
	/** class that can be used to make dice.
	Dependent upon the Getrandom class above. */
public:
	Dice() {// default constructor assumes a 6-sided die.
		self_roll_count_ = 0;
		self_sides_ = 6;
	}
	Dice(int sides) {        // constructor for any size dice
		self_roll_count_ = 0;
		self_sides_ = sides;
	}
	int roll() {             // return the random roll of the die
		// postcondition: number of rolls updated, random 'die' roll returned

		Getrandom newrandom(self_sides_);
		self_roll_count_ = self_roll_count_ + 1;         // update # of times die rolled
		return(newrandom.roll());
	}
	int get_sides() const {   // how many sides this die has
		// postcondition: return # of sides of die
		return self_sides_;
	}
	int get_roll_count() const {   // # times this die rolled
		// postcondition: return # of times die has been rolled
		return self_roll_count_;
	}
private:
	int self_roll_count_;       // # times die rolled
	int self_sides_;           // # sides on die
}; //a semi colon must end every C++ class declaration.

class Beetle
{
public:
	// Default Constructor
	Beetle() {
		beetleName = "Beetle1";

	}

	Beetle(string Name_beetle) {
		beetleName = Name_beetle;
	}

	void setName(string name) {
		beetleName = name;
	}
	// make body
	void make_body() {
		body += 1;
		cout << "making body" << endl;
	}
	//  make head
	void make_head(){
		head += 1;
	}
	
	// make leg
	void make_leg() {
		legs += 1;
	}
	// make eye
	void make_eye() {
		eyes += 1;
	}


	// make feeler
	void make_feeler() {
		feelers += 1;
		string feelers[] = {
			 "      Y   Y      ",
		};
	}


	// make tail
	void make_tail() {
		tail += 1;
		string tail[] = { "       |:|       ",// tail
						  "       |:|       ",
						  "        v        " };

	}

	const int len_beetle = 11;
	string complete_beetle[11] = {
		"      Y   Y      ", //fillers
		"      \\\\_//      ", //
		"     .@   @.     ", // eyes
		"  v__/  -  \\__v  ", // body and 6 legs
		"v___|---.---|___v",
		" v__|   |   |__v ",
		"    \\   |   /    ",
		"     `. : .'     ",
		"       |:|       ",// tail
		"       |:|       ",
		"        v        "
	};

	//FIXME: Add all of your methods


	void show() const {
		//FIX ME -- this needs to done using << overloading
		// and it needs to show the partial Beetle.
		/*for (int i = 0; i < len_beetle; i++) {
			cout << complete_beetle[i] << endl;
		}
		return; */
	}
	bool is_complete() {

		int sum = legs + feelers + tail + head + body + eyes;
		if (sum == 6) {
			return true;
		}
		if (sum > 6){
			return false;
			
		}
		cout << "eyes = "<< eyes << endl ;
		cout << head<< endl;
		cout << tail << endl;
		cout << body<< endl;
		cout << feelers << endl;
		cout << legs << endl;
	}

	int total() {
		int sum = legs + feelers + tail + head + body + eyes;
		return sum;

	}

	int sum_legs() {
		int sum = legs;
	}

	int sum_head() {
		int sum = head;
	}
	int sum_feelers() {
		int sum = feelers;
	}
	int sum_eyes() {
		int sum = eyes;
	}

	int sum_body() {
		int sum = body;
		return sum;
	}
	int sum_tail() {
		int sum = tail;
	}
	// This is to find if beetle 1 or the other is complete

	friend ostream& operator << (ostream& stream, const Beetle& beetle);
private:
	string beetleName;
	int legs = 0;
	int head = 0;
	int tail = 0;
	int feelers = 0;
	int eyes = 0;
	int body = 0;

	//FIXME: declare all other member class and instance variables here

	/*Note: You need to draw your Beetle as each part is added.
	You may use your own ASCII art or you may use mine.
	Think about how to use the array elements in order to
	draw the Beetle as the game progresses */

	/* const int len_beetle = 11;
	 string complete_beetle[11] = {
		 "      Y   Y      ",
		 "      \\\\_//      ",
		 "     .@   @.     ",
		 "  v__/  -  \\__v  ",
		 "v___|---.---|___v",
		 " v__|   |   |__v ",
		 "    \\   |   /    ",
		 "     `. : .'     ",
		 "       |:|       ",
		 "       |:|       ",
		 "        v        "
	 };
	 */

}; //don't forget semi-colon!!

ostream& operator <<(ostream& stream, const Beetle& beetle) {
	beetle.show();
	stream << beetle.beetleName << "/" << beetle.beetleName;
	return stream;

}

Beetle beetle_comp;
Beetle beetle_user;

int Computer_player() {

	Dice compdice(6);
	int croll = compdice.roll();

	if (croll == 1) {
		if (beetle_comp.sum_body() < 1) {
			beetle_comp.make_body();
			cout << "added body" << endl;
			cout << beetle_comp.is_complete() << endl;
			cout << beetle_comp.total() << endl;
		}
	}

	else if (croll == 2) {
		beetle_comp.make_head();
		cout << "added head" << endl;
	}

	else if (croll == 3) {
		beetle_comp.make_eye();
		cout << "added eye" << endl;
	}

	else if (croll == 4) {
		beetle_comp.make_feeler();
		cout << "added feeler" << endl;
	}

	else if (croll == 5) {
	    beetle_comp.make_leg();
		cout << "added leg "<< endl;
	}

	else if (croll == 6) {
		beetle_comp.make_tail();
		cout << "added tail" << endl;
	}

	else if (croll == 1) {
		return 0;
		cout << "added something" << endl;
	}

	cout << beetle_comp << endl;


}

int human_player() {
	return 0;
}

bool comp_complete() {
	return false;
}

bool hum_complete() {
	return false;
}
int main() {

	char readchar;

	//FIXME: Your code


	bool hc = beetle_comp.is_complete();
	bool cc = beetle_user.is_complete();
	while (hc == false && cc == false) {
		Computer_player();
		//human_player();
	}
	cout << "The complete Beetle!\n" << endl;
	
	cout << beetle_user << endl;

	//FIXME: Your codee


	cin >> readchar; //This is to keep screen open in some situations.
	return 0;
}

