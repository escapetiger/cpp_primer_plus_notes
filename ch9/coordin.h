// coordin.h -- structure templates and function prototypes
// struture template
#ifndef COORDIN_H_
#define COORDIN_H_
struct polar
{
    double distance; // distance from origin
    double angle; // diesction from orgin
};

struct rect {
    double x; // horizontal distance from origin
    double y; // vertical distance from origin
};

// prototypes
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

#endif /* ifndef COORDIN_H_ */
