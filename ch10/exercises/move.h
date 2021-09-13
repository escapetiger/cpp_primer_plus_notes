// move.h -- Move class
#ifndef MOVE_H
#define MOVE_H

class Move
{
private:
    double x;
    double y;

public:
    Move(double a = 0, double b = 0);       // sets x, y to a, b
    virtual ~Move();
    void showmove() const;                  // shows current x, y values
    Move add(const Move & m) const;         // adds x of m to x of invoking object to get new x
                                            //  adds y of m to y of invoking object to get new y, creates a new move object
                                            //  initialized to new x, y values and returns it
    void reset(double a = 0, double b = 0); // resets x, y to a, b
};

#endif /* MOVE_H */
