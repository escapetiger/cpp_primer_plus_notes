// ex3.cpp -- strfun
#include <iostream>
using namespace std;
struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};
void Show(box bx);
float GetVolume(box *bptr);

int main()
{
    box bx1;
    cout << "Let's make a box!\n";
    cout << "Enter the name of maker: ";
    cin.getline(bx1.maker, 40);
    cout << "Enter the height of your box: ";
    cin >> bx1.height;
    cout << "Enter the weight of your box: ";
    cin >> bx1.width;
    cout << "Enter the length of your box: ";
    cin >> bx1.length;

    Show(bx1);
    cout << "The volume of your box: " << GetVolume(&bx1) << endl;

    return 0;
}

void Show(box bx)
{
    cout << bx.maker << " made a "
         << bx.length << "x" << bx.width << "x" << bx.height
         << " box!" << endl;
}

float GetVolume(box *bptr)
{
    return bptr->length * bptr->width * bptr->height;
}
