// ex5.cpp -- stack for customer struct
#include <iostream>
#include "stack.h"

customer & input(customer & ctm);
int main()
{
    using namespace std;
    Stack st; // create an empty stack
    char ch;
    customer ctm;
    double total = 0.0;
    cout << "Please enter A to add a customer,\n"
         << "P to process a customer, or Q to quit.\n";
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
                cout << "Enter a customer to add:\n";
                input(ctm);
                if (st.isfull())
                    cout << "stack already full\n";
                else
                    st.push(ctm);
                break;
            case 'P':
            case 'p':
                if (st.isempty())
                    cout << "stack already empty\n";
                else
                {
                    st.pop(ctm);
                    total += ctm.payment;
                    cout << "Total paryment: " << total << "\n";
                }
                break;
        }
        cout << "PLease enter A to add a customer,\n"
             << "P to process a customer, or Q to quit.\n";

    }
    cout << "Bye\n";
    return 0;
}

customer & input(customer & ctm)
{
    std::cout << "Name: ";
    std::cin.getline(ctm.fullname, 35);
    std::cout << "Payment: ";
    std::cin >> ctm.payment;
    std::cin.clear();
    while(std::cin.get() != '\n') continue;
    return ctm;
}
