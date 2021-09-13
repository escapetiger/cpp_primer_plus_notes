/******************************************************************************
* File:             tv.h
*
* Author:           Joey Tsai  
* Created:          09/05/21 
* Description:      Tv and Remote classes
*****************************************************************************/


#ifndef TV_H
#define TV_H

#include <iostream>
class Remote;
class Tv
{
private:
    int state;      // on or off
    int volume;     // assumed to be digitized
    int maxchannel; // maximum number of channels
    int channel;    // current channel setting
    int mode;       // broadcast or cable
    int input;      // TV or DVD
   

public:
    friend class Remote;
    enum {Off, On};
    enum {MinVal, MaxVal = 20};
    enum {Antenna, Cable};
    enum {TV, DVD};

    Tv(int s = Off, int mc = 125) : state(s), volume(5), maxchannel(mc), channel(2),
                                    mode(Cable), input(TV) {};
    void onoff() {state = (state == On) ? Off : On;};
    bool ison() const {return state == On;};
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode() {mode = (mode == Antenna) ? Cable : Antenna;};
    void set_input() {input = (input == TV) ? DVD : TV;};
    void settings() const; // display all settings
    void set_remote_status(Remote & r);
    virtual ~Tv();
};

class Remote
{
private:
    int mode; // controls TV or DVD
    int status; // controls REG or COM
public:
    friend class Tv;
    enum {REG, INT};
    Remote (int m = Tv::TV, int s = REG) : mode(m), status(s) {};
    bool volup(Tv & t) {return t.volup();};
    bool voldown(Tv & t) {return t.voldown();};
    void onoff(Tv & t) {t.onoff();};
    void chanup(Tv & t) {t.chanup();};
    void chandown(Tv & t) {t.chandown();};
    void set_chan(Tv & t, int c) {t.channel = c;};
    void set_mode(Tv & t) {t.set_mode();};
    void set_input(Tv & t) {t.set_input();};
    void show_status() 
    {std::cout << "Remote Status: " << ((status == REG) ? "regular" : "interactive") << std::endl;};
    virtual ~Remote ();

};
#endif /* TV_H */
