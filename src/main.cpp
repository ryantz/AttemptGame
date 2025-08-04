#include "../include/GameLoop.h"
#include "../include/Random.h"
#include "../include/Table.h"

int main() {
	
	DrawTable();

	GameLoop GameLoop;

	GameLoop.Start();

	return 0;
}
