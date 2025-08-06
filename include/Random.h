#pragma once
#include <iostream>
#include <random>

/*
* Seeder: initial random number
* Engine: Uses seed number to generate endless supp of random numbers 
* Distributor: convert random numbers to range we want
* Use: Crit chance? Dodge chance?
*/
namespace Random {

    void PrintSeed();

    void Reseed(unsigned int PrevSeed);

    int Integer(int min, int max);

    // if the random prob generated is less than specified, do smth (true)
    bool Bool(float Probability);
}

