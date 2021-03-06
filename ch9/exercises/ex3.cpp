// ex3.cpp -- new
#include <iostream>
#include <new>
#include <cstring>
struct chaff {
    char dross[20];
    int slag;
};
const int BUF = 512;
const int N = 2;
char buffer[BUF];

int main()
{
    using namespace std;
    chaff *carr1 = new chaff[N];
    chaff *carr2 = new (buffer) chaff[N];
    for (int i = 0; i < N; ++i) {
        strcpy(carr1[i].dross, "carr1");
        strcpy(carr2[i].dross, "carr2");
        carr1[i].slag = carr2[i].slag = i;
    }

    for (int i = 0; i < N; ++i) {
        cout << "The ith element in carr1 is: ";
        cout << carr1[i].dross << ", " << carr1[i].slag << endl;
    }

    for (int i = 0; i < N; ++i) {
        cout << "The ith element in carr2 is: ";
        cout << carr2[i].dross << ", " << carr2[i].slag << endl;
    }
    
    return 0;
}
