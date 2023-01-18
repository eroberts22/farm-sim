// Elizabeth Roberts
// CS 273
// Final Project

/* 
Main function runs the simulation of a vegetable garden
utilizing the Garden class and its functions.
*/

#include "garden.h"
#include "plant.h"

// Function Headers //////////////////////////
// prompt user for action choice
// returns an integer 1-10 that represents choice
int action_choice();

// calls appropriate function based on user choice
void function_call(int choice, Garden &VegetableGarden);

// runs the simulation in a while loop until user chooses to exit
void Simulation (Garden &VegetableGarden);
//////////////////////////////////////////////

int action_choice() {
    int choice = 0;
    do {
        cout << "\nChoose an Action: " 
                << "\n1. Purchase Vegetables"
                << "\n2. Water Garden"
                << "\n3. Progress Day"
                << "\n4. Harvest Vegetables"
                << "\n5. Show Garden"
                << "\n6. Show Storage"
                << "\n7. Sell Items"
                << "\n8. See Last Sold Item"
                << "\n9. Show Stats"
                << "\n10. Exit Simulation"
                << endl << endl;
        cin >> choice;
        if (choice >=1 && choice <= 10) {
            break;
        } else {
            cout << "Invalid choice!" << endl;
            cin.clear();
            cin.ignore(999,'\n');
        }
    } while (true);
    return choice;
}

void function_call(int choice, Garden &VegetableGarden) {
    if (choice == 1) {VegetableGarden.purchasePlant(); system("pause");}
    if (choice == 2) {VegetableGarden.water(); system("pause");}
    if (choice == 3) {VegetableGarden.progressDay(); system("pause");}
    if (choice == 4) {VegetableGarden.harvest(); system("pause");}
    if (choice == 5) {VegetableGarden.showGarden(); system("pause");}
    if (choice == 6) {VegetableGarden.showStorage(); system("pause");}
    if (choice == 7) {VegetableGarden.sellItems(); system("pause");}
    if (choice == 8) {VegetableGarden.lastSold(); system("pause");}
    if (choice == 9) {VegetableGarden.stats(); system("pause");}
}

void Simulation (Garden &VegetableGarden) {
    // output starting information 
    VegetableGarden.start();

    // runs the simulation until exited
    while (true) {
        
        int choice = action_choice();
        // exit simulation
        if (choice == 10) 
            break;

        function_call(choice, VegetableGarden);
    }
    // output of final stats
    VegetableGarden.stats();
}

int main () {
    // creates Garden
    Garden VegetableGarden; 

    // runs simulation
    Simulation(VegetableGarden);

    system("pause");
    return 0;
}