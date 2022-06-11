// write include statements
#include "hwexpressions.h"
#include <iomanip>
#include <iostream>
// write namespace using statement for cout
using std::cin;
using std::cout;
using std::endl;
using std::right;
using std::setw;

int main()
{
    double meal_amount, tip_rate, tip_amount, tax_amount, total;

    // Get info from the user
    cout << "Enter the cost of your meal: ";
    cin >> meal_amount;
    tax_amount = get_sales_tax_amount(meal_amount);
    cout << "Enter tip rate, in percent: ";
    cin >> tip_rate;
    tip_amount = get_tip_amount(meal_amount, tip_rate);
    total = meal_amount + tip_amount + tax_amount;

    // formatting
    cout << std::fixed << std::showpoint << std::setprecision(2) << right;

    // Display receipt
    cout << "\nYour receipt: " << endl;
    cout << "Meal amount: " << setw(5) << "$" << setw(6) << meal_amount << endl;
    cout << "Sales Tax:   " << setw(5) << "$" << setw(6) << tax_amount << endl;
    cout << "Tip Amount:  " << setw(5) << "$" << setw(6) << tip_amount << endl;
    cout << "Total:       " << setw(5) << "$" << setw(6) << total << endl;

    return 0;
}
