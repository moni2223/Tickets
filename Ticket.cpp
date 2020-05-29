#pragma once
#include "Ticket.hpp"
#include <iostream>
#include <time.h>
using namespace std;

Ticket::Ticket(const char* playname,struct tm playdate, const int isBooked, const int isPaid, const int row, const int place, int ticketid,const char* note,int uniquecode) 
{
	set_playname(playname);
	set_playdate(playdate);
	set_isBooked(isBooked);
	set_isPaid(isPaid);
	set_row(row);
	set_place(place);
	set_ticketid(ticketid);
	set_note(note);
	set_uniquecode(uniquecode);
}
Ticket::Ticket() :Ticket("Unknown", {0}, 0, 0, 0, 0, 0, "Unknown",0)
{}
void Ticket::Free()
{
	isBooked = isPaid = row = place = ticketid =uniquecode= 0;
	delete[] playname;
	delete[] note;
}
Ticket::~Ticket()
{
	Free();
}

char* Ticket::get_playname() 
{
	return playname;
}
struct tm Ticket::get_playdate() 
{
	return playdate;
}
int Ticket::get_isBooked() 
{
	return isBooked;
}
int Ticket::get_isPaid()
{
	return isPaid;
}
int Ticket::get_row()
{
	return row;
}
int Ticket::get_place() 
{
	return place;
}
int Ticket::get_ticketid() 
{
	return ticketid;
}
char* Ticket::get_note()
{
	return note;
}
int Ticket::get_uniquecode()
{
	return uniquecode;
}

void Ticket::set_playname(const char* playname) 
{
	strcpy(this->playname, playname);
}
void Ticket::set_playdate(struct tm playdate)
{
	this->playdate = playdate;
}
void Ticket::set_isBooked(int isBooked) 
{
	this->isBooked = isBooked;
}
void Ticket::set_isPaid(int isPaid) 
{
	this->isPaid = isPaid;
}
void Ticket::set_row(int row) 
{
	this->row = row;
}
void Ticket::set_place(int place) 
{
	this->place = place;
}
void Ticket::set_ticketid(int ticketid) 
{
	this->ticketid = ticketid;
}
void Ticket::set_note(const char* note)
{
	strcpy(this->note, note);
}
void Ticket::set_uniquecode(int uniquecode)
{
	this->uniquecode=uniquecode;
}
void Ticket::showinfo() 
{
	cout << "---------------------------------------------------" << endl;
	cout << "The ticket is for the play: " << playname << endl;
	cout << "The ticket is for: " << playdate.tm_year<<"."<<playdate.tm_mon<<"."<<playdate.tm_mday << endl;
	cout << "The ticket is booked(0 or 1):  " << isBooked << endl;
	cout << "The ticket is paid(0 or 1):  " << isPaid << endl;
	cout << "The ticket is for row:  " << row << endl;
	cout << "The ticket is for place:  " << place << endl;
	cout << "The ticket's id is: " << ticketid << endl;
	cout<<  "The ticket's note is: "<<note<<endl;
	cout << "The ticket's uniquecode is: " << uniquecode << endl;
	cout << "---------------------------------------------------" << endl;
}