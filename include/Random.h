#pragma once
#include <random>

/*
* Seeder: initial random number
* Engine: Uses seed number to generate endless supp of random numbers 
* Distributor: convert random numbers to range we want
* Use: Crit chance? Dodge chance?
*/
namespace Random {
	std::random_device Seeder;
	unsigned int seed{ Seeder() };
	std::mt19937 Engine{ seed };

	void PrintSeed() {
		std::cout << "Seed: " << seed << std::endl;
	}

	// to replicate randomness
	void Reseed(unsigned int PrevSeed) {
		seed = PrevSeed;
		Engine.seed(PrevSeed);
	}

	int Integer(int min, int max) {
		std::uniform_int_distribution get{ min, max };
		return get(Engine);
	}

	// if the random prob generated is less than specified, do smth (true)
	bool Bool(float Probability) {
		std::uniform_real_distribution get{ 0.0 , 1.0 };
		return Probability > get(Engine);
	}
}