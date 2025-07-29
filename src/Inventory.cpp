#include <iostream>
#include <vector>

#include "../include/Inventory.h"

Inventory::Inventory() {
	InventoryVec& RefmInventory = mInventory;
	mInventory.reserve(6);
	std::cout << "Inventory created:\n Capacity: "
		<< mInventory.size() << "/"
		<< mInventory.capacity() << std::endl;
}

InventoryVec Inventory::GetInventory() {
	return mInventory;
}

