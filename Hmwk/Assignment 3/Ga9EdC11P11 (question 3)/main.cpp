/* 
 * File: main.cpp
 * Author: Matthew Madrigal
 * Created on October 21st 2025, 7:37 pm
 * Purpose: To display the difference between the budget and actual spent amount
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

// Structurers
struct Budget {
    float hous;     // Housing
    float util;     // Utilities
    float expe;     // Household Expenses
    float trans;    // Transportation
    float food;     // Food
    float medical;  // Medical
    float ins;      // Insurance
    float ent;      // Entertainment
    float cloth;    // Clothing
    float misc;     // Miscellaneious
};

//Function Prototypes
void printResults(const Budget &, const Budget &);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    Budget budget;
    Budget spent;
    
    //Initialize Variables
    // Set default budget
    budget.hous = 500;
    budget.util = 150;
    budget.expe = 65;
    budget.trans = 50;
    budget.food = 250;
    budget.medical = 30;
    budget.ins = 100;
    budget.ent = 150;
    budget.cloth = 75;
    budget.misc = 50;
    
    //Process or map Inputs to Outputs
    // Takes in info for all sections
    cout << "Enter housing cost for the month:$" << endl;
    cin >> spent.hous;
    cout << "Enter utilities cost for the month:$" << endl;
    cin >> spent.util;
    cout << "Enter household expenses cost for the month:$" << endl;
    cin >> spent.expe;
    cout << "Enter transportation cost for the month:$" << endl;
    cin >> spent.trans;
    cout << "Enter food cost for the month:$" << endl;
    cin >> spent.food;
    cout << "Enter medical cost for the month:$" << endl;
    cin >> spent.medical;
    cout << "Enter insurance cost for the month:$" << endl;
    cin >> spent.ins;
    cout << "Enter entertainment cost for the month:$" << endl;
    cin >> spent.ent;
    cout << "Enter clothing cost for the month:$" << endl;
    cin >> spent.cloth;
    cout << "Enter miscellaneous cost for the month:$" << endl;
    cin >> spent.misc;
    
    //Display Outputs
    printResults(budget, spent);

    //Exit stage right!
    return 0;
}

void printResults(const Budget &budget, const Budget &spent) {
    // Prints the evaluation for all the sections
    cout << "Housing " << ((budget.hous > spent.hous) ? "Under" : (budget.hous < spent.hous ? "Over" : "Even")) << endl;
    cout << "Utilities " << ((budget.util > spent.util) ? "Under" : (budget.util < spent.util ? "Over" : "Even")) << endl;
    cout << "Household Expenses " << ((budget.expe > spent.expe) ? "Under" : (budget.expe < spent.expe ? "Over" : "Even")) << endl;
    cout << "Transportation " << ((budget.trans > spent.trans) ? "Under" : (budget.trans < spent.trans ? "Over" : "Even")) << endl;
    cout << "Food " << ((budget.food > spent.food) ? "Under" : (budget.food < spent.food ? "Over" : "Even")) << endl;
    cout << "Medical " << ((budget.medical > spent.medical) ? "Under" : (budget.medical < spent.medical ? "Over" : "Even")) << endl;
    cout << "Insurance " << ((budget.ins > spent.ins) ? "Under" : (budget.ins < spent.ins ? "Over" : "Even")) << endl;
    cout << "Entertainment " << ((budget.ent > spent.ent) ? "Under" : (budget.ent < spent.ent ? "Over" : "Even")) << endl;
    cout << "Clothing " << ((budget.cloth > spent.cloth) ? "Under" : (budget.cloth < spent.cloth ? "Over" : "Even")) << endl;
    cout << "Miscellaneous " << ((budget.misc > spent.misc) ? "Under" : (budget.misc < spent.misc ? "Over" : "Even")) << endl;
    
    // Calculates total (difference between budget and spent)
    float total = (budget.hous - spent.hous) + (budget.util - spent.util) + (budget.expe - spent.expe) + (budget.trans - spent.trans)
    + (budget.food - spent.food) + (budget.medical - spent.medical) + (budget.ins - spent.ins) + (budget.ent - spent.ent)
    + (budget.cloth - spent.cloth) + (budget.misc - spent.misc);
    
    // Prints the correct text
    if(total < 0) {
        cout << "You were $" << setprecision(2) << fixed << total*-1 << " over budget";
    } else if(total > 0) {
        cout << "You were $" << setprecision(2) << fixed << total << " under budget";
    } else {
        cout << "You were even with the budget";
    }
    
}