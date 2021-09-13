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
    CandyBar *candies = new CandyBar[csize];
    candies[0] = {"Mocha Munch", 2.3, 350};
    candies[1] = {"Betty Chen", 5.6, 600};
    candies[2] = {"Jenny Cai", 4.5, 800};

    for (int i = 0; i < csize; ++i) {
        cout << "Brand: " << candies[i].brand << "\n";
        cout << "Weight: " << candies[i].weight << "\n";
        cout << "Calorie: " << candies[i].calorie << "\n";
        cout << endl;
    }
    
    return 0;
}
