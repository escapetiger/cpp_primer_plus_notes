/******************************************************************************
* File:             ex10.cpp
*
* Author:           Joey Tsai
* Created:          09/07/21
* Description:
*****************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>


struct Review
{
    std::string title;
    int rating;
    double price;
};

bool operator<(std::shared_ptr<Review> r1, std::shared_ptr<Review> r2);
bool worseThan(std::shared_ptr<Review> r1, std::shared_ptr<Review> r2);
bool better(std::shared_ptr<Review> r1, std::shared_ptr<Review> r2);
bool cheaper(std::shared_ptr<Review> r1, std::shared_ptr<Review> r2);
bool moreExpensive(std::shared_ptr<Review> r1, std::shared_ptr<Review> r2);
bool FillReview(std::shared_ptr<Review> rr);
void ShowReview(std::shared_ptr<Review> rr);

int main(void)
{
    using std::cout;
    using std::endl;
    using std::vector;
    using std::shared_ptr;
    using std::string;
    using std::cin;

    vector<shared_ptr<Review>> books;
    shared_ptr<Review> temp(new Review);
    while (FillReview(temp))
    {
        books.push_back(temp);
        temp = shared_ptr<Review> (new Review);
    }
    int num = books.size();
    if (num > 0)
    {
        char show_mode;
        cout << "Select a show mode.\n"
             << "a) origin                      b) sorted by title\n"
             << "c) sorted by rating(ascending) d) sorted by rating(descending)\n"
             << "e) sorted by price(ascending)  f) sorted by price(descending)\n"
             << "q) quit" << endl;
        while (cin >> show_mode && show_mode != 'q')
        {
            switch (show_mode)
            {
            case 'a':
                cout << "Thank you. You entered the following:\n"
                     << "Rating\tBook\tPrice\n";
                for_each(books.begin(), books.end(), ShowReview);
                break;
            case 'b':
                sort(books.begin(), books.end());
                cout << "Sorted by title:\nRating\tBook\tPrice\n";
                for_each(books.begin(), books.end(), ShowReview);
                break;
            case 'c':
                sort(books.begin(), books.end(), worseThan);
                cout << "Sorted by rating(ascending):\nRating\tBook\tPrice\n";
                for_each(books.begin(), books.end(), ShowReview);
                break;
            case 'd':
                sort(books.begin(), books.end(), better);
                cout << "Sorted by rating(descending):\nRating\tBook\tPrice\n";
                for_each(books.begin(), books.end(), ShowReview);
                break;
            case 'e':
                sort(books.begin(), books.end(), moreExpensive);
                cout << "Sorted by price(ascending):\nRating\tBook\tPrice\n";
                for_each(books.begin(), books.end(), ShowReview);
                break;
            case 'f':
                sort(books.begin(), books.end(), cheaper);
                cout << "Sorted by rating(descending):\nRating\tBook\tPrice\n";
                for_each(books.begin(), books.end(), ShowReview);
                break;
            }
            cout << "Select a show mode.\n"
                 << "a) origin                      b) sorted by title\n"
                 << "c) sorted by rating(ascending) d) sorted by rating(descending)\n"
                 << "e) sorted by price(ascending)  f) sorted by price(descending)\n"
                 << "q) quit" << endl;
        }
    }
    else
        cout << "Nothing entered, nothing gained.\n";
    cout << "Bye.\n";

    return 0;
}

bool FillReview(std::shared_ptr<Review> rr)
{
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin, rr->title);
    if (rr->title == "quit")
        return false;
    std::cout << "Enter book rating: ";
    std::cin >> rr->rating;
    std::cout << "Enter book price: $";
    std::cin >> rr->price;
    if (!std::cin)
        return false;
    // get rid of rest of input line
    while (std::cin.get() != '\n')
        continue;
    return true;
}

void ShowReview(const std::shared_ptr<Review> rr)
{
    std::cout << rr->rating << "\t" << rr->title << "\t$" << rr->price << std::endl;
}


bool operator<(std::shared_ptr<Review> r1, std::shared_ptr<Review> r2)
{
    if (r1->title < r2->title)
        return true;
    else if (r1->title == r2->title && r1->rating < r2->rating)
        return true;
    else
        return false;
}

bool worseThan(std::shared_ptr<Review> r1, std::shared_ptr<Review> r2)
{
    if (r1->rating < r2->rating)
        return true;
    else
        return false;
}

bool better(std::shared_ptr<Review> r1, std::shared_ptr<Review> r2)
{
    if (r1->rating > r2->rating)
        return true;
    else
        return false;
}

bool cheaper(std::shared_ptr<Review> r1, std::shared_ptr<Review> r2)
{
    if (r1->price < r2->price)
        return true;
    else
        return false;
}

bool moreExpensive(std::shared_ptr<Review> r1, std::shared_ptr<Review> r2)
{
    if (r1->price > r2->price)
        return true;
    else
        return false;
}
