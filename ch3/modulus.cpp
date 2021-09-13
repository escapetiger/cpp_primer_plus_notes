// modulus.cpp -- uses % operator to convert lbs to stone
#include <iostream>
int main(void)
{
    using namespace std;
    const int Lbs_per_stn = 14;
    int lbs;

    std::cout << "Enter your weight in pounds: ";
    cin >> lbs;
    int stone = lbs / Lbs_per_stn;              // whole stone
    int pounds = lbs % Lbs_per_stn;       // remainder in pounds
    std::cout << lbs << " pounds are " << stone
              << " stone, " << pounds << " pound(s)." << std::endl;
    return 0;
}
