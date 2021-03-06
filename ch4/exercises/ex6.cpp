#include <iostream>
#include <string>
using namespace std;
struct CandyBar
{
    string brand;
    double weight;
    int calorie;
};
int main(void)
{
    const int csize = 3;
    CandyBar candies[csize] = {
        {"Mocha Munch", 2.3, 350},
        {"Betty Chen", 5.6, 600},
        {"Jenny Cai", 4.5, 800}
    };

    for (int i = 0; i < csize; ++i) {
        cout << "Brand: " << candies[i].brand << "\n";
        cout << "Weight: " << candies[i].weight << "\n";
        cout << "Calorie: " << candies[i].calorie << "\n";
        cout << endl;
    }
    
    return 0;
}
