#include <string>
#include <iostream>
#include <stdlib.h>
#include <istream>
#include <vector>
#include <thread>

using namespace std;

char mychar;
string mystring;



class Item {

public:
	string itemName;

	inline string printItems() const
	{
		return this->itemName;
	};

private:

};



class Inventory {

public:

	Inventory();
	//~Inventory();
	
	int numOfItems;
	//Item **itemArray;
	vector <Item> *itemVector;

	void addItem(const Item &item);

	void removeItem(int index);

	inline void printItems() const {
	
		for (int i = 0; i < this-> numOfItems; i++)
		{
			//cout << this->itemArray[i]->printItems() << endl;
			cout << this.itemVector[i]->printItems() << endl;
		}
	}

};

//inventory constructor
Inventory::Inventory()
{

	this->numOfItems = 0;
	this->itemArray = new Item*[10];
}

void Inventory::addItem(const Item & item)
{
	
	//this->itemArray[this->numOfItems++] = new Item(item);
	this->itemVector[this->numOfItems++] = new Item(item);
}

void Inventory::removeItem(int index)
{
	itemVector->erase(index);
}


class PlayerCharacter {

public:

	//functions

	void printName() const;
	void initialize(const string name);

	inline const string& getName() const { return this->characterName; }
	inline const double& getXpos() const { return this->xpos; }
	inline const double& getYpos() const { return this->ypos; }

	//modifiers



private:
	string characterName;
	double xpos;
	double ypos;

};

void PlayerCharacter::printName() const
{
	cout << this->characterName;
}

void PlayerCharacter::initialize(const string name)
{
	this->characterName = name;
}

int main() {

	Item item;
	item.itemName = "cat";

	Inventory inventory;

	inventory.addItem(Item());

	inventory.addItem(item);

	inventory.printItems();

	cout << "add your name: ";
	cin >> mystring;

	PlayerCharacter playerCharacter;

	playerCharacter.initialize(mystring);

	playerCharacter.printName();
	while (mystring != "q")
	{



		cout << " what would you like to do : add OR erase (a / e)  ? ";
		cin >> mystring;
		if (mystring == "a") {
			item.itemName = mystring;
			inventory.addItem(item);
			inventory.printItems();
		}
		else
		{
			int v;
			cout << " what number item  ? ";
			cin >> v;
			inventory.removeItem(v);
			cout << "you now have";
			inventory.printItems();

		}

	return 0;

};
