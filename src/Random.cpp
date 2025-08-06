#include "../include/Random.h"

/*
* Seeder: initial random number
* Engine: Uses seed number to generate endless supp of random numbers 
* Distributor: convert random numbers to range we want
* Use: Crit chance? Dodge chance?
*/

std::random_device Seeder;
unsigned int seed{ Seeder() };
std::mt19937 Engine{ seed };


void Random::PrintSeed() {
	std::cout << "Seed: " << seed << std::endl;
}

// to replicate randomness
void Random::Reseed(unsigned int PrevSeed) {
	seed = PrevSeed;
	Engine.seed(PrevSeed);
}

int Random::Integer(int min, int max) {
	std::uniform_int_distribution get{ min, max };
	return get(Engine);
}

// if the random prob generated is less than specified, do smth (true)
bool Random::Bool(float Probability) {
	std::uniform_real_distribution get{ 0.0 , 1.0 };
	return Probability > get(Engine);
}

