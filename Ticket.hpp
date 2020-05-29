#pragma once
#include <time.h>
class Ticket
{
	char playname[1024];
	struct tm playdate;
	int isBooked;
	int isPaid;
	int row;
	int place;
	int ticketid;
	char note[1024];
	int uniquecode;
	void Free();

public:
	Ticket(const char* playname,struct tm playdate, const int isBooked, const int isPaid, const int row, const int place,int ticketid,const char* note,int uniquecode);
	Ticket();
	~Ticket();

	char* get_playname();
	struct tm get_playdate();
	int get_isBooked();
	int get_isPaid();
	int get_row();
	int get_place();
	int get_ticketid();
	char* get_note();
	int get_uniquecode();

	void set_playname(const char* playname);
	void set_playdate(struct tm playdate);
	void set_isBooked(int isBooked);
	void set_isPaid(int isPaid);
	void set_row(int row);
	void set_place(int place);
	void set_ticketid(int ticketid);
	void set_note(const char* note);
	void set_uniquecode(int uniquecode);
	void showinfo();
};

