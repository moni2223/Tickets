#include "Play.h"
#include <iostream>
using namespace std;

Play::Play(const char* playname, struct tm playdate, const int playhallid,int freeplaces,int boughttickets) 
{
	set_playname(playname);
	set_playdate(playdate);
	set_playhallid(playhallid);
	set_freeplaces(freeplaces);
	set_boughttickets(boughttickets);
}
Play::Play() : Play("Unknown", { 0 }, 0,100,0) {};

void Play::Free()
{
	playhallid = freeplaces = boughttickets =0;
	delete[] playname;
}
Play::~Play()
{
	Free();
}

char* Play::get_playname()
{
	return playname;
}
struct tm Play::get_playdate() 
{
	return playdate;
}
int Play::get_playhallid() 
{
	return playhallid;
}
int Play::get_freeplaces()
{
	return freeplaces;
}
int Play::get_boughttickets()
{
	return boughttickets;
}

void Play::set_playname(const char* playname) 
{
	strcpy(this->playname, playname);
}
void Play::set_playdate(struct tm playdate) 
{
	this->playdate = playdate;
}
void Play::set_playhallid(const int playhallid) 
{
	this->playhallid = playhallid;
}
void Play::set_freeplaces(int freeplaces)
{
	this->freeplaces = freeplaces;
}
void Play::set_boughttickets(int boughttickets) 
{
	this->boughttickets = boughttickets;
}
void Play::showinfo() 
{
	cout << "Play's name is: "<< playname << endl;
	cout << "Play's date is: " << playdate.tm_year <<"."<< playdate.tm_mon <<"."<< playdate.tm_mday << endl;
	cout << "Play's hall is: " << playhallid << endl;
	cout << "Play's free places count is: " <<freeplaces<< endl;
	cout << "Play's bought tickets are: " << boughttickets << endl;
}
