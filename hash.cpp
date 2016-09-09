#include "hash.h"

hash::hash() {
	for (int i = 0; i < tableSize; i++) {
		HashTable[i] = new item;
		HashTable[i]->name = "empty";
		HashTable[i]->drink = "empty";
		HashTable[i]->next = NULL;
	}
}

int hash::Hash(std::string key) {
	int hash = 0;
	int index;

	for (int i = 0; i < key.length(); i++) {
		hash += (int)key[i] * 17;
	}

	index = hash % tableSize;

	return index;
}

//Remove an item from the hash table
void hash::RemoveItem(std::string name) {
	int index = Hash(name);

	item* delPtr;
	item* P1;
	item* P2;

	//Case 0 - buket is empty
	if (HashTable[index]->name == "empty" && HashTable[index]->drink == "empty") {
		std::cout << name << "was not found in the Hash Table" << std::endl;
	}

	//Case 1 - Only 1 item in bucket and has matching name
	else if (HashTable[index]->name == name && HashTable[index]->next == NULL) {
		HashTable[index]->name = "empty";
		HashTable[index]->drink = "empty";

		std::cout << name << " was removed from the Hash Table" << std::endl;
	}
	//Case 2 - Match is in first item but there are more than 1 item
	else if (HashTable[index]->name == name) {
		delPtr = HashTable[index];
		HashTable[index] = delPtr->next;
		delete delPtr;

		std::cout << name << " was removed from the Hash Table" << std::endl;
	}
	//Case 3 - Bucket has items but first is not a match
	else {
		P1 = HashTable[index]->next;
		P2 = HashTable[index];

		while(P1 != NULL && P1->name != name){
			P2 = P1;
			P1 = P1->next;
		}
		//Case 3.1 - No match
		if (P1 == NULL) {
			std::cout << name << " was not found in the Hash Table!" << std::endl;
		}
		//Case 3.2 - Match is found
		else {
			delPtr = P1;
			P1 = P1->next;
			P2->next = P1;

			delete delPtr;

			std::cout << name << " was removed from the Hash Table" << std::endl;
		}
	}
}

void hash::AddItem(std::string name, std::string drink) {
	int index = Hash(name);

	if (HashTable[index]->name == "empty") {
		HashTable[index]->name = name;
		HashTable[index]->drink = drink;
	}
	else {
		item* Ptr = HashTable[index];	//pointer to find last position in list
		item* n = new item;				//creates new item to store info in
		n->name = name;
		n->drink = drink;
		n->next = NULL;
		while (Ptr->next != NULL) {		//finds last index
			Ptr = Ptr->next;
		}
		Ptr->next = n;
	}
}

int hash::NumberOfItemsInIndex(int index) {
	item* Ptr = HashTable[index];
	int counter = 0;
	if (HashTable[index]->name == "empty") {
		return counter;
	}
	else {
		item* Ptr = HashTable[index];
		counter++;
		while (Ptr->next != NULL) {
			counter++;
			Ptr = Ptr->next;
		}
		return counter;
	}
}

void hash::PrintTable() {
	int number;
	for (int i = 0; i < tableSize; i++) {
		int bucket = 1;
		number = NumberOfItemsInIndex(i);
		std::cout << "------------------" << std::endl;
		std::cout << "index = " << i << std::endl;
		std::cout << "# of items = " << number << std::endl;
		std::cout << "bucket # = " << bucket << std::endl;
		std::cout << HashTable[i]->name << std::endl;
		std::cout << HashTable[i]->drink << std::endl;
		if (HashTable[i]->next != NULL) {					//prints data inside each index
			item* Ptr = HashTable[i]->next;
			while (Ptr) {
				bucket++;
				std::cout << "*************" << std::endl;
				std::cout << "bucket # = " << bucket << std::endl;
				std::cout << Ptr->name << std::endl;
				std::cout << Ptr->drink << std::endl;
				Ptr = Ptr->next;
			}

		}
		std::cout << "------------------" << std::endl;
	}
}

void hash::PrintItemsAtIndex(int index) {
	item* Ptr = HashTable[index];
}

//First overload with string argument
void hash::FindDrink(std::string name) {
	int index = Hash(name);
	bool foundName = false;
	std::string drink;

	item* Ptr = HashTable[index];
	while (Ptr != NULL) {
		if (Ptr->name == name) {
			foundName = true;
			drink = Ptr->drink;
		}
		Ptr = Ptr->next;
	}
	if (foundName) {
		std::cout << "***NAME FOUND***" << std::endl;
		std::cout << name << "'s Favorite drink = " << drink << std::endl;
	}
	else {
		std::cout << name << "'s info was not found in the Hash Table." << std::endl;
	}
}

//Second overload with no argument
void hash::FindDrink() {
	std::string name;
	std::cout << std::endl << "Please enter the name you wish to search for (case matters): " << std::endl;
	std::cin >> name;
	int index = Hash(name);
	bool foundName = false;
	std::string drink;

	item* Ptr = HashTable[index];
	while (Ptr != NULL) {
		if (Ptr->name == name) {
			foundName = true;
			drink = Ptr->drink;
		}
		Ptr = Ptr->next;
	}
	if (foundName) {
		std::cout << "***NAME FOUND***" << std::endl;
		std::cout << name << "'s Favorite drink = " << drink << std::endl;
	}
	else {
		char again;
		std::cout << name << "'s info was not found in the Hash Table." << std::endl;
		std::cout << "Would you like to search again? (Y/N): ";
		std::cin >> again;
		if (again == 'Y' || again == 'y') FindDrink();
		else return;
	}
}