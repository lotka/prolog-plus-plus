#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>

using namespace std;
// split a string at n, returning everything before the nth character
// and leaving everything including and after the nth character
string cropString(string &input_string, int n);
// split a string at the first occurence of the delimiter, functions
// as the above function after that
string cropString(string &input_string, char delimiter);
// count the occurences of c
int countChar(string s, char c);
// count te occurences of c upto a delimiter
int countChar(string s, char c, char delimiter);

class Atom;
class PredicateReference;
class Predicate;

// typically an argument of a function
class Atom
{
public:
	Atom(string n);
	string name;
	// if this is true then the atom is capitalised
	// and can unify with anything
	bool free_variable;
	// if this is true then atom is the underscore
	bool is_under_score;
	// list of possibilties
	vector<Atom *> possibilties;

	// print the name of the atom
	friend ostream &operator<<(ostream &out, Atom &c)     //output
	{
	        cout << c.name;
	}

	// check two atoms are equal
	bool operator == (Atom &b)
	{
		if(b.free_variable or free_variable)
		{
			return true;
		}
		if(this->name == b.name)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// check two atoms are not equal
	bool operator != (Atom &b)
	{
		if(b.free_variable or free_variable)
		{
			return false;
		}
		if(this->name != b.name)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool unifyWith(Atom * a)
	{
		if(a->free_variable)
		{
			if(not free_variable)
			{
				a->possibilties.push_back(this);
			}
			else
			{
				cout << "not sure what to do here" << endl;
			}
			return true;
		}
		else if(*a == *this)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

class PredicateRef
{
public:
	string name;
	PredicateRef(string input, vector<Predicate *> &predicates);
	vector<Atom *> args;
	int airty;
	friend ostream &operator<<(ostream &out, PredicateRef &c)
	{
	        cout << c.name;
	}
};

class Predicate
{
public:
	Predicate(string input, vector<Predicate *> &predicates);
	bool unifyWith(PredicateRef * ref);
	string name;
	int airty;
	vector<Atom *> args;
	vector<PredicateRef *> conditions;

	#define AND 1
	#define OR 	2
	#define IMPLIES 3
	#define END 4
	vector<int> connectives;
	Predicate * next;

};
