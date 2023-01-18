// Elizabeth Roberts
// CS 273
// Final Project
#ifndef _PLANT_H_
#define _PLANT_H_

/* plant.h
The plant class is utilized by the garden class. Five classes inherit from
the plant class: carrot, turnip, cucumber, tomato, and lettuce. Each plant
has the variable age. Every inheriting class has the variables name and 
dayHarvest that are different for each of the five plant types.
*/

#include <iostream> 
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Plant {
    private: 
        // age of plant
        int age;
    protected:
        // name of plant
        string name;
        // // day the plant is ready to be harvested
        int dayHarvest;
    public:
        // constructor
        // sets age to 0
        // inherited classes also set appropriate name and dayHarvest
        Plant();

        // used by progressDay() in Garden, increases age by 1 day
        void ageUp();

        // return true if age > dayHarvest (variable per plant)
        bool harvestable();
        
        // return name of plant
        string getName ();

};

// Carrot object inherits from plant
class Carrot : public Plant {  
    public:
        Carrot(); // constructor: sets name and dayHarvest
};

// Turnip object inherits from plant
class Turnip : public Plant {
    public:
        Turnip(); // constructor: sets name and dayHarvest
};

// Cucumber object inherits from plant
class Cucumber : public Plant {
    public:
        Cucumber(); // constructor: sets name and dayHarvest
};

// Tomato object inherits from plant
class Tomato : public Plant {
    public:
        Tomato(); // constructor: sets name and dayHarvest
};

// Lettuce object inherits from plant
class Lettuce : public Plant {
    public:
        Lettuce(); // constructor: sets name and dayHarvest
};

#endif