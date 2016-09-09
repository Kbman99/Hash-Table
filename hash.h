#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>

class hash {
public:
	hash();
	
	int Hash(std::string key);

	void AddItem(std::string name, std::string drink);

	int NumberOfItemsInIndex(int index);

	void PrintTable();
	
	void PrintItemsAtIndex(int index);

	void FindDrink();

	void FindDrink(std::string name);

	void RemoveItem(std::string name);

private:
	static const int tableSize = 40;

	struct item{
		std::string name;
		std::string drink;
		item* next;
	};

	item* HashTable[tableSize];

};

#endif
