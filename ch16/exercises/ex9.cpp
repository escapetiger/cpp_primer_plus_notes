/******************************************************************************
* File:             ex9.cpp
*
* Author:           Joey Tsai  
* Created:          09/07/21 
* Description:      sort in linked list and vector
*****************************************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <algorithm>

const int SIZE = 1000000;
int main(void)
{
    using std::vector;
    using std::list;
    using std::cout;
    using std::endl;
    srand(time(0));
    vector<int> vi0(SIZE);
    for (int i = 0; i < SIZE; ++i) {
        vi0.push_back(rand() % SIZE);
    }
    vector<int> vi(vi0);
    list<int> li(vi0.begin(), vi0.end());

    clock_t start = clock();
    sort(vi.begin(), vi.end());
    clock_t end = clock();
    cout << "sort in vector: ";
    cout << (double) (end - start) / CLOCKS_PER_SEC << " s" << endl;
    
    start = clock();
    li.sort();
    end = clock();
    cout << "sort in list: ";
    cout << (double) (end - start) / CLOCKS_PER_SEC << " s" << endl;

    copy(vi0.begin(), vi0.end(), li.begin());
    start = clock();
    copy(li.begin(), li.end(), vi.begin());
    sort(vi.begin(), vi.end());
    copy(vi.begin(), vi.end(), li.begin());
    end = clock();
    cout << "copy, sort and copy: ";
    cout << (double) (end - start) / CLOCKS_PER_SEC << " s" << endl;
    return 0;
}
