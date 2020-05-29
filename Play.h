#pragma once
#include <time.h>
class Play
{
    char playname[1024];
    struct tm playdate;
    int playhallid;
    int freeplaces = 100;
    int boughttickets = 0;
    void Free();
public:
    Play(const char* playname, struct tm playdate, const int playhallid,int freeplaces,int boughttickets);
    Play();
    ~Play();

    char* get_playname();
    struct tm get_playdate();
    int get_playhallid();
    int get_freeplaces();
    int get_boughttickets();

    void set_playname(const char* playname);
    void set_playdate(struct tm playdate);
    void set_playhallid(const int playhallid);  
    void set_freeplaces(int freeplaces);
    void set_boughttickets(int boughttickets);
    void showinfo();
};

