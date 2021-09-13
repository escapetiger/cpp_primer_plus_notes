// plorg.h -- Plorg class
#ifndef PLORG_H
#define PLORG_H

class Plorg
{
private:
    char name_[19];
    int CI_;

public:
    Plorg();
    Plorg(const char * name, int CI = 50);
    virtual ~Plorg();
    void show();
    void reset(int CI);
};

#endif /* PLORG_H */
