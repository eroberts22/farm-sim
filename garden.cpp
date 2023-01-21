// Elizabeth Roberts
// CS 273
// Final Project
#include "garden.h"

Garden::Garden() {
    garden.resize(5); 
    money = 300;
    daysElapsed = 0; 
    waterLevel = 5;

    // stat counters
    carrot_sold = 0;
    turnip_sold = 0;
    cucumber_sold = 0;
    tomato_sold = 0;
    lettuce_sold = 0;
    amount_spent = 0;
    amount_earned = 0;
} 

// constant variables
const int Garden::WATER_LIMIT = 10;

void Garden::start() {
    cout << "---------------------------------\n";
    cout << "--- Vegetable Farm Simulation ---\n";
    cout << "---------------------------------\n";
    cout << "You will have the choice to purchase five\n"
        << "different types of plants:\n"
        << "1. Carrots\n"
        << "2. Turnips\n"
        << "3. Cucumbers\n"
        << "4. Tomatoes\n"
        << "5. Lettuce\n\n";
    cout << "Every vegetable has a set purchase price and\n"
        << "set sale price that allows a profit when sold.\n\n";
    system("pause");
    cout << "\nStarting Stats: "
        << "\nStarting on day: " << daysElapsed
        << "\nStarting funds: $" << money
        << "\nGarden water level: " << waterLevel
        << endl; 
    cout << "For each day progressed, the plants age and the\n"
        << "garden's water level decreases.\n\n";
    system("pause");
}

void Garden::water() {
    if (waterLevel >= WATER_LIMIT) {
        cout << "Should not exceed water limit!\n\n";
        return;
    }
    cout << "Garden watered, ";
    waterLevel++;
    cout << "Current water level: " << waterLevel << endl;
    cout << endl;
}

void Garden::progressDay() {
    // increases number of days
    daysElapsed++;

    // ages up the plants in the garden
    list<Plant*>::iterator iter;
    for (int i = 0; i < garden.size(); i++) {
        for (iter = garden.at(i).begin(); iter != garden.at(i).end(); iter++) {
            (*iter)->ageUp(); 
        }
    }

    cout << "Day Progressed\n";
    // if water level is zero, chance of a plant dying (100% happens if all rows have plants)
    if (waterLevel == 0) {
        srand(time(NULL));
        int random = rand() % garden.size();
        // source: [1]
        list<Plant*>::iterator it; 
        if (!garden.at(random).empty() && (garden.at(random).size() > 1)) {
            it = garden.at(random).begin();
            cout << "A " << (*it)->getName() << " died from lack of water!" << endl;
            it = garden.at(random).erase(it);
        }
    }
    // decrease water level
    if (waterLevel != 0) {
        waterLevel--;
    }
    if (waterLevel < 3) {
        cout << "Water level is low!" << endl;
    }
    // output daily stats
    cout << "Current water level: " << waterLevel << endl;
    cout << "Days elapsed: " << daysElapsed << endl;
    cout << "Money: $" << money << endl << endl; 
}

void Garden::harvest() {
    int choice;
    // choice of plant to harvest
    do { 
        cout << "What type of plant would you like to harvest?\n"
            << "1. Carrot   (needs 4 days to mature)\n" 
            << "2. Turnip   (needs 6 days to mature)\n" 
            << "3. Cucumber (needs 7 days to mature)\n" 
            << "4. Tomato   (needs 5 days to mature)\n" 
            << "5. Lettuce  (needs 3 days to mature)\n";
        cin >> choice;
        if ( choice >= 1 && choice <= 5) {
            break;
        } else {
            cout << "Invalid choice!" << endl;
            cin.clear();
            cin.ignore(999,'\n');
        }
    } while (true);
    // if the row is empty
    if (garden.at(choice-1).empty()) {
        cout << "No plants to harvest!" << endl;
        return;
    } 

    // removes plants from garden and moves to storage
    bool harvested = false;
    int count = 0;
    list<Plant*>::iterator iter;
    for (iter = garden.at(choice-1).begin(); iter != garden.at(choice-1).end(); iter++) {
        // checks if the plants are harvetable
        if ((*iter)->harvestable()) { 
            harvested = true;
            count++;
            storage.push_back((*iter));
            iter = garden.at(choice-1).erase(iter); 
            --iter;
        }
    }

    //  if nothing was harvested
    if (harvested == false) {
        cout << "Plants were not ready to be harvested.\n\n";
    } else { // output number harvested
        cout << "Harvested plants placed in storage.\n";
        cout << "Number harvested: " << count << "\n\n";
    }
}

void Garden::showGarden() {
    cout << "Current Garden:" << endl;
    for (int i = 0; i < garden.size(); i++) {
        cout << vegLookup.find(i+1)->second << endl;
        list<Plant*>::iterator iter = garden.at(i).begin();
        for (iter = garden.at(i).begin(); iter != garden.at(i).end(); iter++) {
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
}

void Garden::showStorage() {
    cout << "Current Storage:" << endl;
    cout << "Carrots : " << countVegetable("Carrot") << endl;
    cout << "Turnips : " << countVegetable("Turnip") << endl;
    cout << "Cucumber: " << countVegetable("Cucumber") << endl;
    cout << "Tomato  : " << countVegetable("Tomato") << endl;
    cout << "Lettuce : " << countVegetable("Lettuce") << endl; 
    cout << endl;
}

int Garden::countVegetable(string vegetable) {
    return count_if(storage.begin(), storage.end(), [vegetable](Plant* p) {return p->getName() == vegetable;});
}

void Garden::addPlantsFunction (int choice, int amount) {
    // push back the appropriate amount of plant into appropriate row
    switch (choice) {
        case 1:
            for (int i = 0; i < amount; i++) {
                garden.at(choice-1).push_back(new Carrot()); 
            }
            break;
        case 2:
            for (int i = 0; i < amount; i++) {
                garden.at(choice-1).push_back(new Turnip()); 
            }
            break;
        case 3:
            for (int i = 0; i < amount; i++) {
                garden.at(choice-1).push_back(new Cucumber()); 
            }
            break;
        case 4:
            for (int i = 0; i < amount; i++) {
                garden.at(choice-1).push_back(new Tomato()); 
            }
            break;
        default:
            for (int i = 0; i < amount; i++) {
                garden.at(choice-1).push_back(new Lettuce()); 
            }
            break;
    }
    string plural = amount > 1 ? "s" : "";
    cout << "Successfully purchased " << amount << " " << vegLookup.find(choice)->second << plural << endl;
    cout << "Remaining funds: $" << money << "\n\n";
}

bool Garden::purchasable(int choice, int amount) {
    // calculating cost based on the choice of plant and amount
    int cost = costLookup.find(choice)->second * amount;
    
    // if it costs too much, cannot purchase
    if (cost > money) {
        cout << "Unable to purchase, insufficient funds!\n";
        return false;
    }
    // subtracts the cost from money
    money = money - cost;
    amount_spent = amount_spent + cost; // counter for amount spent
    return true;
}

void Garden::purchasePlant() {
    int choice, amount;
    // input choice of type of plant to purchase
    cout << "Money: $" << money << endl;
    do { 
        cout << "What type of plant would you like to purchase?\n"
            << "1. Carrot -   $15\n" 
            << "2. Turnip -   $30\n" 
            << "3. Cucumber - $20\n" 
            << "4. Tomato -   $25\n" 
            << "5. Lettuce -  $10\n";
        cin >> choice;
        if ( choice >= 1 && choice <= 5) {
            break;
        } else {
            cout << "Invalid choice!" << endl;
            cin.clear();
            cin.ignore(999,'\n');
        }
    } while (true);

    // input amount of plants to purchase
    do {
        cout << "How many? " << endl;
        cin >> amount; 
        if (amount > 0 && amount <= 50) {
            break;
        } else {
            cout << "Invalid amount!" << endl;
            cin.clear();
            cin.ignore(999,'\n');
        }
    } while (true); 

    // if the transaction is approved (cost doesn't exceed money)
    if (purchasable(choice, amount)) {
        addPlantsFunction(choice,amount); // add plants to garden container
    }
}

void Garden::sellItems() {
    // if there are no items to sell
    if (storage.empty()) {
        cout << "No items to sell!\n\n";
        return;
    }
    cout << "Selling items\n";
    int counter = 0;
    // while the storage is not empty,
    // for the appropriate plant type, increase money by appropriote ammount
    // adds to counters of number of vegetables sold and amount_earned
    while (!storage.empty()) {
        string vegName = storage.front()->getName();
        int vegValue = valueLookup.find(vegName)->second;
      
        money += vegValue;
        amount_earned += vegValue;
        
        if (vegName == "Carrot") carrot_sold++;
        if (vegName == "Turnip") turnip_sold++;
        if (vegName == "Cucumber") cucumber_sold++;
        if (vegName == "Tomato") tomato_sold++;
        if (vegName == "Lettuce") lettuce_sold++;
        counter++;
        
        // pushes front item from storage to sold items
        soldItems.push(storage.front());
        // removes front of storage
        storage.pop_front(); 
    }
    int total = carrot_sold + turnip_sold + cucumber_sold + tomato_sold + lettuce_sold;
    cout << "Items sold: " << counter << endl;
    cout << "Total items sold: " << total << endl;
    cout << "Current funds: $" << money << "\n\n";
}

void Garden::lastSold() {
    if (soldItems.empty()) {
        cout << "Nothing has been sold." << endl;
        return;
    }
    cout << "Last Sold Item: " << soldItems.top()->getName() << endl << endl;
}

void Garden::stats() {
    int total = carrot_sold + turnip_sold + cucumber_sold + tomato_sold + lettuce_sold;
    int profit = amount_earned - amount_spent;
    cout << "Current Stats: "
        << "\nCarrots Sold   : " << carrot_sold
        << "\nTurnips Sold   : " << turnip_sold
        << "\nCucumbers Sold : " << cucumber_sold
        << "\nTomatoes Sold  : " << tomato_sold
        << "\nLettuce Sold   : " << lettuce_sold
        << "\nTotal Sold     : " << total
        << "\nDays Elapsed   : " << daysElapsed
        << "\nCurrent Money  : $" << money
        << "\nMoney Spent    : $" << amount_spent
        << "\nMoney Earned   : $" << amount_earned
        << "\nTotal Profit   : $" << profit
        << endl;
}
