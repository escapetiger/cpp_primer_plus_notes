// ex2.cpp -- CandyBar
#include <iostream>
#include <string>
using namespace std;
struct CandyBar
{
    string maker;
    double weight;
    int calorie;
};

void Set(CandyBar &cdb, string mk = "Millennium Munch", double wt = 2.85, int cl = 350);
void Show(const CandyBar &cdb);

int main()
{
    CandyBar cdb;
    Set(cdb);
    Show(cdb);

    return 0;
}

void Set(CandyBar &cdb, string mk, double wt, int cl)
{
    cdb.maker = mk;
    cdb.weight = wt;
    cdb.calorie = cl;
}

void Show(const CandyBar &cdb)
{
    cout << "Maker: " << cdb.maker << endl;
    cout << "Weight: " << cdb.weight << endl;
    cout << "Calorie: " << cdb.calorie << endl;

}
