#pragma once
#include <iostream>
#include <vector>

using InventoryVec = std::vector<int>;

class Inventory {
public:
	Inventory();
	InventoryVec GetInventory();

private:
	InventoryVec mInventory;
};