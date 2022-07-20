#include "expressions.h"

// example
int add_numbers(int num1, int num2)
{
    return num1 + num2;
}

// write function code here

/* Returns the total tax on the purchased meal */
double get_sales_tax_amount(double meal_amount)
{
    const double tax_rate = 0.0675; // 6.75%

    return meal_amount * tax_rate;
}

/* Returns the tip for the meal */
double get_tip_amount(double meal_amount, double tip_rate)
{
    return meal_amount * tip_rate / 100;
}