## Purpose

The overall purpose of this project is to simulate a vegetable garden where a user can buy and sell their vegetables to gain an overall profit.  

## Requirements 

__List of Files__

    Headers:
        garden.h
        plant.h
    Source:
        garden.cpp
        main.cpp
        plant.cpp

__Headers Outlined__

garden.h

    private:
        // containers hold pointers to Plant objects
        vector<list<Plant*>> garden; // container representing garden
        deque<Plant*> storage; // container representing storage
        stack<Plant*> soldItems; // container representing the items sold

        map<int, string> vegLookup // name lookup for vegetables
        map<int, int> costLookup // purchase cost lookup for vegetables
        map<string, int> valueLookup // sell value lookup for vegetables

        int money; // amount of money the user currently has
        int daysElapsed; // counter for number of days elapsed
        int waterLevel; // current water level of the garden

        // statistics that display in stats()
        int carrot_sold;
        int turnip_sold;
        int cucumber_sold;
        int tomato_sold;
        int lettuce_sold;
        int amount_spent;
        int amount_earned;

        // functions that are utilized by purchasePlant()
        // adds plant to correct position in garden container
        void addPlantsFunction(int,int); 
        // returns true if there are sufficient funds for purchase
        bool purchasable(int, int); 

        // helper function for showStorage
        int countVegetable(string);

        // constant variables
        static const int WATER_LIMIT; // limit for watering garden

    public:
        Garden(); // constructor, set garden size to 5
            // money to $300
            // daysElapsed to 0
            // waterlevel to 5
        void start(); // short intro to simulation
        void water(); // water the garden, increase water level to 1
        void progressDay(); // go to next day
            // ages up every plant by 1
            // decreases water level by 1
        void harvest(); // harvests vegetables if they are ready
            // transfers plants from garden container to storage container
        void showGarden (); // output the garden
        void showStorage(); // output storage
        void purchasePlant(); // purchase plants
            // utilizes addPlantsFunction() and purchasable()
        void sellItems(); // sells all items in storage
            // transfers plants from storage container to soldItems container
        void lastSold(); // shows last item sold
        void stats(); // output of stats, number of plants sold and profits 

plant.h

    private: 
        int age; // age of plant
    protected:
        string name; // name of plant
        int dayHarvest; // day the plant is ready to be harvested
    public:
        Plant(); // constructor, sets age to 0
            // inherited classes also set appropriate name and dayHarvest
        void ageUp(); // increase age by 1
        bool harvestable(); // if the age > dayHarvest
        string getName (); // return name of plant

* Plant.h also has five classes that inherit from the Plant class
  * Carrot
  * Turnip
  * Cucumber
  * Tomato
  * Lettuce
    
## Overview of Simulation
This project simulates a vegetable garden. Its main function is to purchase, grow, harvest, and sell plants. It runs indefinetely until the user chooses to exit the simulation.   

__Main Game Elements__

Below are the ten actions the user can pick from. The first nine all continue the game, and the last one exits the simulation.

1. Purchase Vegetables - choice of five different vegetables to purchase
2. Water Garden - increases the water level of the garden
3. Progress Day - increases the age of the plants by one, decreases water level by one
4. Harvest Vegetables - harvest vegetables if they are ready for harvest
5. Show Garden - outputs the garden in a visually friendly form
6. Show Storage - outputs the storage in a visually friendly form
7. Sell Items - sells all items in storage
8. See Last Sold Item - shows the last item sold
9. Show Stats - outputs the game stats
10. Exit Simulation - exits the simulation 


## Analysis

This project overall helped with understanding applications of how data structures can be used in simulations and games. I found that doing more functionalizing in the classes and main.cpp was incredibly helpful to visualizing and understanding how the containers and simulation elements were interacting with one another. Properly organizing my classes was challenging. If I were to redo the implementation, I may have created a main "game" class that could hold separate classes of "garden", "storage", and "shop", instead of just holding three containers in the main garden class. This simulation gives a user the ability to gain profits for buying and selling vegetables. The only hazard to the garden I implemented was when the garden is not kept watered, a plant can die. To make this simulation more realistic and interactive, I would have added more "hazards" such as storms, animals or even a damaged garden fence that the user has to keep repaired to keep animals out. Overall, this simulation was able to give a good base for a more complex farming simulation and helped in my understanding of using data containers.

## Detailed Manual for Project Use

This project is a simulation of a vegetable garden where a user can purchase and grow five different types of vegetables. Each plant type has a different purchase price. The user can input any number greater than 0 and less than 50 for the number of plants they wish to purchase. Once purchased, the vegetables are planted in the garden in a specific row depending on the type. One must be sure to keep the garden watered, because if it gets too dry, there is a chance one of the plants will die. Whenever a day progresses, the water level decreases by 1 and the age of every plant in the garden increases by 1. A plant becomes harvestable once it reaches a specific set age (which is different for every plant). When a user chooses to harvest from the garden, they can pick one type of plant to harvest. If they are not harvestable, then nothing will happen. If they are harvestable, then they will be removed from the garden and put into storage. The user is able to see the garden and storage at any time. To make money to buy more plants, the user must sell their items. Selling plants removes every item from storage and gives the user money for every vegetable. Each different vegetable has a different sale price, but selling any vegetable will give the user a profit. The user is able to see the last item that has been sold. The user can see their stats at any time. The stats function shows the number of each type of vegetable sold, the days elapsed, money spent, money earned, and total profits. When a user is done with the simulation, they can choose to exit and their final stats will be displayed.

## Works Cited

[1] Iterating and removing from list   
* https://stackoverflow.com/questions/16269696/erasing-while-iterating-an-stdlist    
  
CS 273 Lectures:  
* Inheritance and Composition  
* Linked List pt.1 and pt.2  
* Stacks  
* Deque  

Link to Presentation: https://lizroberts2000.wixsite.com/garden-simulation 