// structur.cpp -- a simple structure
#include <iostream>
struct inflatable
{
    char name[20];
    float volume;
    double price;
};

int main(void)
{
    using namespace std;
    inflatable guest =
    {
        "Glorious Gloria",                                // name value
        2.88,                                             // volumn value
        30.99                                             // price value
    };                                                    // guest is a structure variable of type inflatable
                                                          // It's initialized to the indicated values
    inflatable pal =
    {
        "Audacious Arthur",
        4.12,
        33.99
    };                                                    // pal is a second variable of type inflatable
                                                          // NOTE: some implementations require using static inflatable guest =

    cout << "Expand your guest list with " << guest.name;
    cout << " and " << pal.name << "!\n";
    cout << "You have both for $";
    cout << guest.price + pal.price << ".\n";

    return 0;
}
