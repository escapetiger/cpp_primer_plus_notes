// strctfun.cpp
#include <iostream>
#include <cmath>
using namespace std;
struct polar
{
    double distance; // distance from origin
    double angle; // direction from origin
};
struct rect
{
    double x; // horizontal distance from origin
    double y; // vertical distance from origin
};

// prototypes
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

int main()
{
    rect rplace;
    polar pplace;

    cout << "Enter the x and y value: ";
    while (cin >> rplace.x >> rplace.y) {
        pplace = rect_to_polar(rplace);
        show_polar(pplace);
        cout << "Next two number (q to quit): ";
    }
    cout << "Done.\n";
    
    return 0;
} 

polar rect_to_polar(rect xypos)
{
    polar ans;

    ans.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
    ans.angle = atan2(xypos.y, xypos.x);
    return ans; // return a polar structure
}

void show_polar(polar dapos)
{
    const double Rad_to_deg = 57.29577951;
    cout << "distance = " << dapos.distance;
    cout << ", angle = " << dapos.angle * Rad_to_deg;
    cout << " degrees\n";
}
