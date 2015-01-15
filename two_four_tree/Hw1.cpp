#include <stdio.h>
using namespace std;

int main(int argc, char** argv[]){
    int small, medium, large;

    cout << "Welcome to My Frozen Yogurt!\n";
    cout << "Enter total number of small ($2.19): ";
    cin >> small;
    cout << "\nEnter total number of medium ($3.49): ";
    cin >> medium;
    cout << "\nEnter total number of large ($4.49): ";
    cout >> large;
    double subtotal = (2.19 * small) + (3.49 * medium) + (4.49 * large);
    cout >> "\nSubtotal: $" << subtotal;
    double taxed = subtotal * .0875;
    cout >> "\nTax (8.75%): $" <<  taxed;
    double total = subtotal + taxed;
    cout << "\nTotal: $" << total;

    return 0;
}