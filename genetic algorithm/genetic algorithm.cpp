// genetic algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
#include "Header.h"
#include <random>
#include <vector>
#include <algorithm>

std::vector<bool> crossover(const std::vector<bool>& parent1, const std::vector<bool>& parent2, int crossover_point)
{
    std::vector<bool> offspring(parent1);

    for (int i = crossover_point; i < parent1.size(); i++)
    {
        offspring[i] = parent2[i];
    }

    return offspring;
}


int main()
{
    //create random Solutions
    std::random_device device;
    std::uniform_int_distribution<int> unif(0, 1);
    std::vector<Solution> solutions;

    const int NUM = 5;
    
    for (int i = 0; i < NUM; i++)
    {
        std::vector<bool> backpack;
        for (int j = 0; j < ITEMS_CNT; j++)
        {
            backpack.push_back(unif(device));
        }
        solutions.push_back(Solution(backpack));
     
    }
    int gen = 0;
   while (gen < 100)
   {
        gen++;
    std::sort(solutions.begin(), solutions.end(), [](const auto& lhs, const auto& rhs) { return lhs.value > rhs.value; });
  
    //take top solutions
   const int SAMPLE_SIZE = 2;
   std::vector<Solution> sample;
   std::copy(solutions.begin(), 
       solutions.begin() + SAMPLE_SIZE,
       std::back_inserter(sample)
   );
   solutions.clear();
   
   //mutate by %
   std::uniform_int_distribution<int> m(0, 100);
   for (auto& s : sample) {
       for (int i = 0; i < ITEMS_CNT; i++)
       {
           if (m(device) <= 1)
           {
               s.backpack[i] = true ? false : true;
           }
       }
   }

   //segz
   std::uniform_int_distribution<int> cross(0, SAMPLE_SIZE - 1);
   std::uniform_int_distribution<int> rate(0, ITEMS_CNT-1);
   
   for (int i = 0; i < NUM; i++)
   {
       std::vector<bool>& mother = sample[cross(device)].backpack;
       std::vector<bool>& father = sample[cross(device)].backpack;

       

       solutions.push_back(Solution(crossover(mother, father, rate(device))));
   }
 
  

   solutions[0].print();
   std::cout << gen << std::endl;
   }
   
   
}
