#include <iostream>
#include <string>

#include "hash.h"

int main() {
	hash Hashy;


	Hashy.AddItem("Kyle", "Coffee");
	Hashy.AddItem("Kim", "Water");
	Hashy.AddItem("Brad", "Honest Tea");
	Hashy.AddItem("Dave", "Espresso");
	Hashy.AddItem("Logan", "Red Bull");
	Hashy.AddItem("Andrew", "Monster");
	Hashy.AddItem("Chris", "Sweet Tea");
	Hashy.AddItem("Nick", "Energy Drinks");
	Hashy.AddItem("Elisha", "Water");
	Hashy.AddItem("Alexa", "Mocha");
	Hashy.AddItem("Bianca", "Tea");
	Hashy.AddItem("Brandon", "Water");

	Hashy.PrintTable();

	Hashy.FindDrink();


	return 0;
}