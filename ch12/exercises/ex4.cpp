/******************************************************************************
* File:             ex4.cpp
*
* Author:           Joey Tsai  
* Created:          08/30/21 
* Description:      application of Stack class
*****************************************************************************/

#include <iostream>
#include <cctype>
#include "stack.h"

int main(void)
{
    using namespace std;
    Stack st; // create an empty stack
    char ch;
    unsigned long po;
    cout << "Please enter A to add a purchase order,\n"
         << "P to process a PO, or Q to quit.\n";
    while (cin >> ch && toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;
        if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        }
        switch (ch)
        {
            case 'A':
            case 'a':
                cout << "Enter a PO number to add: ";
                cin >> po;
                if (st.isfull())
                    cout << "stack already full\n";
                else
                    st.push(po);
                break;
            case 'P':
            case 'p':
                if (st.isempty())
                    cout << "stack already empty\n";
                else
                {
                    st.pop(po);
                    cout << "PO #" << po << " popped\n";
                }
                break;
        }
        cout << "PLease enter A to add a purchase order,\n"
             << "P to process a PO, or Q to quit.\n";

    }
    cout << "Bye\n";
    Stack st1 = st;
    Stack st2;
    st2 = st1;
    cout << "st1 contructed by copy constructor:\n";
    Item it;
    while(!st1.isempty()){
        st1.pop(it);
        cout << it << " ";
    }
    cout << endl;
    cout << "st2 valued by = ooperator:\n";
    while(!st2.isempty()){
        st2.pop(it);
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
