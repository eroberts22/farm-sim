// Elizabeth Roberts
// CS 273
// Final Project
#ifndef _GARDEN_H_
#define _GARDEN_H_

// SOURCES:
// iterating and removing from list
//      https://stackoverflow.com/questions/16269696/erasing-while-iterating-an-stdlist
// Lectures:
//      Inheritance and Composition
//      Linked List pt.1 and pt.2
//      Stacks
//      Deque

/* garden.h
The garden class handles three major containers:
    garden: vector of lists of plant pointers
    storage: deque of plant pointers
    soldItems: stack of plant pointers
This class also has several variables used in the direct 
simulation as counters (daysElapsed and waterLevel) as 
well as the money variable, which holds the amount of money
the user can spend. There are constant variables for prices
and the water limit. The user can purchase plants, water plants,
harvest plants, and sell plants.
*/

#include "plant.h" 
#include <vector>
#include <list>
#include <stack>
#include <deque>
#include <ctime>
#include <algorithm>
#include <map>

using std::vector;
using std::list;
using std::stack;
using std::deque;
using std::map;

class Garden {
    private:
        // containers hold pointers to Plant objects
        vector<list<Plant*>> garden;  // container representing garden
        deque<Plant*> storage; // container representing storage
        stack<Plant*> soldItems; // container representing the items sold
        
        // name lookup for vegetables
        map<int, string> vegLookup {
            {1, "Carrot"},
            {2, "Turnip"},
            {3, "Cucumber"},
            {4, "Tomato"},
            {5, "Lettuce"}
        };

        // purchase cost lookup for vegetables
        map<int, int> costLookup {
            {1, 15},
            {2, 30},
            {3, 20},
            {4, 25},
            {5, 10}
        };
        
        // sell value lookup for vegetables
        map<string, int> valueLookup {
            {"Carrot", 18},
            {"Turnip", 35},
            {"Cucumber", 22},
            {"Tomato", 28},
            {"Lettuce", 12}
        };

        int money; // amount of money the user currently has
        int daysElapsed; // counter for number of days elapsed
        int waterLevel; // current water level of the garden

        // stats that display, shown in stats() 
        int carrot_sold;
        int turnip_sold;
        int cucumber_sold;
        int tomato_sold;
        int lettuce_sold;
        int amount_spent;
        int amount_earned;

        // functions that are utilized by purchasePlant()
        void addPlantsFunction(int,int); // adds plant to correct position in garden container
        bool purchasable(int, int); // returns true if there are sufficient funds for purchase

        // helper function for showStorage
        int countVegetable(string);

        // Constant Variables
        static const int WATER_LIMIT; // limit for watering garden

    public:
    // Garden elements
        // constructor, set garden size to 5
        // money to $300
        // daysElapsed to 0
        // waterlevel to 5
        Garden(); 
        
        // short intro to simulation
        void start(); 

        // water the garden, increase water level to 1
        void water(); 
        
        // go to next day
        // ages up every plant by 1
        // decreases water level by 1
        void progressDay();

        // harvests vegetables if they are ready
        // transfers plants from garden container: vector of lists of plant pointers
        // to storage container: deque of plant pointers
        void harvest(); 

        void showGarden (); // output the garden
        void showStorage(); // output storage
        
    // Shop elements
        // purchase plants
        // pushed to garden container: vector of lists of plant pointers
        // utilizes addPlantsFunction() and purchasable()
        void purchasePlant();

        // removes all items in storage: deque of plant pointers
        // moves all plants to soldItems: stack of plant pointers
        // increases the money depending on what's sold
        void sellItems();

        // shows last item sold
        void lastSold();

        // output of stats, number of plants sold and profits 
        void stats();
};

#endif