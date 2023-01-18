// Elizabeth Roberts
// CS 273
// Final Project
#include "plant.h"

Plant::Plant() {
    age = 0;
}

void Plant::ageUp() {
    age++;   
}

bool Plant::harvestable() {
    if (age >= dayHarvest) {
        return true;
    }
    return false;
}

string Plant::getName() { return name; }

//Classes that inherit from Plant
Carrot::Carrot() {
    name = "Carrot";
    dayHarvest = 4;
}

Turnip::Turnip() {
    name = "Turnip";
    dayHarvest = 6;
}

Cucumber::Cucumber() {
    name = "Cucumber";
    dayHarvest = 7;
}

Tomato::Tomato() {
    name = "Tomato";
    dayHarvest = 5;
}

Lettuce::Lettuce() {
    name = "Lettuce";
    dayHarvest = 3;
}
