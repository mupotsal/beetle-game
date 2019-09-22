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
	void make_head() {
		head += 1;
	}

	// make leg
	void make_leg() {
		legs += 2;
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
		if (sum >= 11) {
			return true;
		}
		if (sum < 11) {
			return false;

		}
		/*		cout << "eyes = " << eyes << endl;
		cout << head << endl;
		cout << tail << endl;
		cout << body << endl;
		cout << feelers << endl;
		cout << legs << endl; 
		*/
	}

	int total() {
		int sum = legs + feelers + tail + head + body + eyes;
		return sum;

	}

	int sum_legs() {
		int sum = legs;
		return sum;
	}

	int sum_head() {
		int sum = head;
		return sum;
	}
	int sum_feelers() {
		int sum = feelers;
		return sum;
	}
	int sum_eyes() {
		int sum = eyes;
		return sum;
	}

	int sum_body() {
		int sum = body;
		return sum;
	}
	int sum_tail() {
		int sum = tail;
		return sum;
	}

	bool who_plays(bool value) {
		return value ;
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
bool comp_pvalue = true;
bool humanp_value = false;

int Computer_player() {
	cout << "we are her" << endl;
	Dice compdice(6);
	int croll = compdice.roll();

	if (croll == 1) {
		if (beetle_comp.sum_body() < 1) {
			beetle_comp.make_body();
			cout << " COmp added body" << endl;
			cout << beetle_comp.is_complete() << endl;
			cout << "COMP PARTS = "<<beetle_comp.total() << endl;
			comp_pvalue = beetle_comp.who_plays(true);
			humanp_value = beetle_user.who_plays(false);
		}
		else {
			cout << "Comp-Body already added" << endl;
			cout << "COMP PARTS = " << beetle_comp.total() << endl;
			comp_pvalue = beetle_comp.who_plays(false);
			humanp_value = beetle_user.who_plays(true);

		}
	}

	else if (croll == 2) {
		if (beetle_comp.sum_body() == 1) {
			 if (beetle_comp.sum_head() < 1) {
				 beetle_comp.make_head();
				 cout << " Comp added head" << endl;
				 cout << "COMP PARTS = " << beetle_comp.total() << endl;
				 comp_pvalue = beetle_comp.who_plays(true);
				 humanp_value = beetle_user.who_plays(false);
			 }
			 else {
				 cout << "The body has been added already" << endl;
				 cout << "COMP PARTS = " << beetle_comp.total() << endl;
				 comp_pvalue = beetle_comp.who_plays(false);
				 humanp_value = beetle_user.who_plays(true);
			 }
		}
		else {
			cout << "Conputer Got Head but Body is missing" << endl;
			cout << "COMP PARTS = " << beetle_comp.total() << endl;
			comp_pvalue = beetle_comp.who_plays(false);
			humanp_value = beetle_user.who_plays(true);

		}
	}

	else if (croll == 3) {
		if ((beetle_comp.sum_head() > 0) && (beetle_comp.sum_body() > 0)) {
			if (beetle_comp.sum_eyes() < 2) {
				beetle_comp.make_eye();
				cout << "comp added eye" << endl;
				cout << "COMP PARTS = " << beetle_comp.total() << endl;
				comp_pvalue = beetle_comp.who_plays(true);
				humanp_value = beetle_user.who_plays(false);
			}
			else {
				cout << "Comp-Eyes already added" << endl;
				cout << "COMP PARTS = " << beetle_comp.total() << endl;
				comp_pvalue = beetle_comp.who_plays(false);
				humanp_value = beetle_user.who_plays(true);
			}

		}
		else {
			cout << "Computer Got Eye but Body and or head is missing " << endl;
			cout << "COMP PARTS = " << beetle_comp.total() << endl;
			comp_pvalue = beetle_comp.who_plays(false);
				humanp_value = beetle_user.who_plays(true);
		}
	}

	 

	else if (croll == 4) {
		if ((beetle_comp.sum_body() > 0) && (beetle_comp.sum_head() > 0)) {
			if (beetle_comp.sum_feelers() < 2) {
				beetle_comp.make_feeler();
				cout << " comp added feeler" << endl;
				cout << "COMP PARTS = " << beetle_comp.total() << endl;
				comp_pvalue = beetle_comp.who_plays(true);
				humanp_value = beetle_user.who_plays(false);
			}
			else {
				cout << "Comp-Feelers already added" << endl;
				cout << "COMP PARTS = " << beetle_comp.total() << endl;
				comp_pvalue = beetle_comp.who_plays(false);
			}
		}
		else {
			cout << "Computer Got Feeler but Body and or head is missing " << endl;
			cout << "COMP PARTS = " << beetle_comp.total() << endl;
			comp_pvalue = beetle_comp.who_plays(false);
			humanp_value = beetle_user.who_plays(true);
		}

	}

	else if (croll == 5) {
		if (beetle_comp.sum_body() == 1) {
		    if (beetle_comp.sum_legs() < 6) {
				beetle_comp.make_leg();
				cout << " comp added leg " << endl;
				cout << "COMP PARTS = " << beetle_comp.total() << endl;
				comp_pvalue = beetle_comp.who_plays(true);
				humanp_value = beetle_user.who_plays(false);
		 	}
		    else {
				cout << "The is already added" << endl;
				cout << "COMP PARTS = " << beetle_comp.total() << endl;
				comp_pvalue = beetle_comp.who_plays(false);
				humanp_value = beetle_user.who_plays(true);
		 }
		}
		else {
			cout << "The Body is missing" << endl;
			cout << "COMP PARTS = " << beetle_comp.total() << endl;
			comp_pvalue = beetle_comp.who_plays(false);
			humanp_value = beetle_user.who_plays(true);

		}
		
	}

	else if (croll == 6) {
		if (beetle_comp.sum_body() > 0) {
			if (beetle_comp.sum_tail() < 1) {
				beetle_comp.make_tail();
				cout << " comp added tail" << endl;
				cout << "COMP PARTS = " << beetle_comp.total() << endl;
				comp_pvalue = beetle_comp.who_plays(true);
				humanp_value = beetle_user.who_plays(false);
			}
			else {
				cout << "Comp-tail already added" << endl;
				cout << "COMP PARTS = " << beetle_comp.total() << endl;
				comp_pvalue = beetle_comp.who_plays(false);
				humanp_value = beetle_user.who_plays(true);
			}
		}
		else {
			cout << "Computer Got tail but The Body is missing" << endl;
			cout << " COMP PARTS = " << beetle_comp.total() << endl;
			comp_pvalue = beetle_comp.who_plays(false);
			humanp_value = beetle_user.who_plays(true);
		}
		
	}

	else if (croll == 1) {
		return 0;
		cout << "added something" << endl;
	}

	cout << beetle_comp << endl;


}


int human_player() {

	Dice hdice(6);
	int croll = hdice.roll();
	

	if (croll == 1) {
		if (beetle_user.sum_body() < 1) {
			beetle_user.make_body();
			cout << " human added body" << endl;
			cout << beetle_user.is_complete() << endl;
			cout << "Total human Parts" << beetle_user.total() << endl;
			humanp_value = beetle_user.who_plays(true);
			comp_pvalue = beetle_comp.who_plays(false);
			return 0;
		}
		else {
			cout << "Human_Player Body already added" << endl;
			cout << "Total human Parts" << beetle_user.total() << endl;
			humanp_value = beetle_user.who_plays(false);
			comp_pvalue = beetle_comp.who_plays(true);
		}
	}


	else if (croll == 2) {
		if (beetle_user.sum_body() > 0) {
			if (beetle_user.sum_head() < 1) {
				beetle_user.make_head();
				cout << " human added head" << endl;
				cout << "Total human Parts" << beetle_user.total() << endl;
				humanp_value = beetle_user.who_plays(true);
				comp_pvalue = beetle_comp.who_plays(false);
			}
			else {
				cout << "Human_Player Head already added" << endl;
				cout << "Total human Parts" << beetle_user.total() << endl;
				humanp_value = beetle_user.who_plays(false);
				comp_pvalue = beetle_comp.who_plays(true);
			}
		}
		else {
			cout << "Human Got Head but The body is missing" << endl;
			cout << "Total human Parts" << beetle_user.total() << endl;
			humanp_value = beetle_user.who_plays(false);
			comp_pvalue = beetle_comp.who_plays(true);
		}
	}

	else if (croll == 3) {
		if ((beetle_user.sum_body() > 0) && (beetle_user.sum_head() > 0)) {
			if (beetle_user.sum_eyes() < 1) {
				beetle_user.make_eye();
				cout << " human added eye" << endl;
				cout << "Total human Parts" << beetle_user.total() << endl;
				humanp_value = beetle_user.who_plays(true);
				comp_pvalue = beetle_comp.who_plays(false);
			}
			else {
				cout << "Human_Player Eyes already added" << endl;
				cout << "Total human Parts" << beetle_user.total() << endl;
				humanp_value = beetle_user.who_plays(false);
				comp_pvalue = beetle_comp.who_plays(true);
			}
		}
		else {
			cout << "Human Got eyes butThe head or body is missing" << endl;
			cout << "Total human Parts" << beetle_user.total() << endl;
			humanp_value = beetle_user.who_plays(false);
			comp_pvalue = beetle_comp.who_plays(true);
		}
	}

	else if (croll == 4) {
		if ((beetle_user.sum_body() > 0) && (beetle_user.sum_head() > 0)) {
			if (beetle_user.sum_feelers() < 2) {
				beetle_user.make_feeler();
				cout << " human added feeler" << endl;
				cout << "Total human Parts" << beetle_user.total() << endl;
				humanp_value = beetle_user.who_plays(true);
				comp_pvalue = beetle_comp.who_plays(false);
			}
			else {
				cout << "Human_Player Feelers already added" << endl;
				cout << "Total human Parts" << beetle_user.total() << endl;
				humanp_value = beetle_user.who_plays(false);
				comp_pvalue = beetle_comp.who_plays(true);
			}
		}
		else {
			cout << "Human Got feelers butThe head or body is missing" << endl;
			cout << "Total human Parts" << beetle_user.total() << endl;
			humanp_value = beetle_user.who_plays(false);
			comp_pvalue = beetle_comp.who_plays(true);
		}
	}

	else if (croll == 5) {
		if (beetle_user.sum_body() > 0) {
			if (beetle_user.sum_legs() < 6) {
				beetle_user.make_leg();
				cout << " human added leg " << endl;
				cout << "Total human Parts" << beetle_user.total() << endl;
				humanp_value = beetle_user.who_plays(true);
				comp_pvalue = beetle_comp.who_plays(false);

			}
			else {
				cout << "Human_Player Legs already added" << endl;
				cout << "Total human Parts" << beetle_user.total() << endl;
				humanp_value = beetle_user.who_plays(false);
				comp_pvalue = beetle_comp.who_plays(true);
			}
		}
		else {
			cout << "Human Got legs butThe body is missing" << endl;
			cout << "Total human Parts" << beetle_user.total() << endl;
			humanp_value = beetle_user.who_plays(false);
			comp_pvalue = beetle_comp.who_plays(true);
		}

	}

	else if (croll == 6) {
		if (beetle_user.sum_body() > 0) {
			if (beetle_user.sum_tail() < 1) {
				beetle_user.make_tail();
				cout << " human added tail" << endl;
				cout << "Total human Parts" << beetle_user.total() << endl;
				humanp_value = beetle_user.who_plays(true);
				comp_pvalue = beetle_comp.who_plays(true);
			}
			else {
				cout << "Human_Player Tail already added" << endl;
				cout << "Total human Parts" << beetle_user.total() << endl;
				humanp_value = beetle_user.who_plays(true);
				comp_pvalue = beetle_comp.who_plays(false);
			}
		}
		else {
			cout << "Human Got tail but The body is missing" << endl;
			cout << "Total human Parts" << beetle_user.total() << endl;
			humanp_value = beetle_user.who_plays(false);
			comp_pvalue = beetle_comp.who_plays(true);
		}
	}




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
	while (beetle_comp.is_complete() == false && beetle_user.is_complete() == false) {
		while ((comp_pvalue == true) && (beetle_comp.is_complete() == false && beetle_user.is_complete() == false)) {
			Computer_player();
		}
		while ((humanp_value == true) && (beetle_comp.is_complete() == false && beetle_user.is_complete() == false)) {
			human_player();
		}
	}
	//cout << "The complete Beetle!\n" << endl;

	cout << beetle_user << endl;
	cout << beetle_comp << endl;

	//FIXME: Your codee


	cin >> readchar; //This is to keep screen open in some situations.
	return 0;
}