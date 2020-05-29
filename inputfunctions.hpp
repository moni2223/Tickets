#include <iostream>
#include "Play.h"
#include"Ticket.hpp"
#include "Functions.hpp"
using namespace std;

//We have 5 halls!!!!!!!

Play* plays = new Play[1024];
Ticket* tickets = new Ticket[1024];

int playid = 0;
int hallid = 1;
int ticketid = 0;
void inputfunctions(char input[])
{
	if (isAddevent(input) == 1)
	{
		char* temp;
		temp = strtok(input, " ");//add
		int tempo = 0;
		struct tm playdate;
		while (temp != NULL)
		{
			tempo++;
			if (tempo == 2)
			{
				int day = takingday(temp);
				int month = takingmonth(temp);
				int year = takingyear(temp);
				playdate.tm_year = year;//setting year
				playdate.tm_mon = month;//setting month
				playdate.tm_mday = day;//setting day
				plays[playid].set_playdate(playdate);

			}
			if (tempo == 3)
			{
				int currenthall = atoi(temp);
				if (currenthall > 5)
				{
					cout << "There is not such hall" << endl;
					return;
				}
				for (int i = 0; i < playid; i++)
				{
					struct tm olddate = plays[i].get_playdate();
					if (olddate.tm_mon = playdate.tm_mon && olddate.tm_mday == playdate.tm_mday)
					{
						int hall = plays[i].get_playhallid();
						if (hall == currenthall)
						{
							cout << "There is play on this date" << endl;
							return;
						}

					}
				}

				plays[playid].set_playhallid(currenthall);
			}
			if (tempo == 4)
			{
				if (strlen(temp) < 2)
				{
					cout << "Invalid play name" << endl;
					return;
				}
				plays[playid].set_playname(temp);
			}
			temp = strtok(NULL, " ");

		}
		cout << "Added successfully" << endl;
		playid++;
		return;
	}
	if (isfreeseats(input) == 1)
	{
		char* temp;
		temp = strtok(input, " ");//freeseats
		int tempo = 0;
		struct tm newdate;
		while (temp != NULL)
		{
			tempo++;
			if (tempo == 2)
			{
				int day = takingday(temp);
				int month = takingmonth(temp);
				int year = takingyear(temp);
				newdate.tm_year = year;//setting year
				newdate.tm_mon = month;//setting month
				newdate.tm_mday = day;//setting day
			}
			if (tempo == 3)
			{
				for (int i = 0; i < playid; i++)
				{
					struct tm olddate = plays[i].get_playdate();
					if (compare2dates(olddate, newdate) == 1)
					{
						if (isequalarrays(plays[i].get_playname(), temp) == 1)
						{
							cout << "There are " << plays[i].get_freeplaces() << " places left." << endl;
							return;
						}
					}
				}
			}
			temp = strtok(NULL, " ");
		}
		cout << "No play found" << endl;
		return;
	}
	if (isbook(input) == 1)
	{
		char* temp;
		temp = strtok(input, " ");//book
		int tempo = 0;
		int samedate = 0;
		int sameplayid;
		int roww = 0;
		int placee = 0;
		int sameplacerow = 0;
		while (temp != NULL)
		{
			tempo++;
			if (tempo == 2)
			{
				roww = atoi(temp);
				tickets[ticketid].set_row(roww);
			}
			if (tempo == 3)
			{
				placee = atoi(temp);
				for (int i = 0; i < ticketid; i++)
				{
					if (tickets[i].get_row() == tickets[ticketid].get_row())
					{
						if (tickets[i].get_place() == placee)
						{
							sameplacerow = 1;
						}
					}

				}
				tickets[ticketid].set_place(placee);
			}
			if (tempo == 4)
			{
				struct tm newdate;

				int day = takingday(temp);
				int month = takingmonth(temp);
				int year = takingyear(temp);
				newdate.tm_year = year;//setting year
				newdate.tm_mon = month;//setting month
				newdate.tm_mday = day;//setting day
				for (int i = 0; i < playid; i++)
				{
					struct tm olddate = plays[i].get_playdate();
					if (compare2dates(olddate, newdate) == 1)
					{
						samedate = 1;
						sameplayid = i;
						tickets[ticketid].set_playdate(olddate);
					}
				}
				if (samedate == 0)
				{
					cout << "There is not any plays on this date" << endl;
					return;
				}
			}
			if (tempo == 5)
			{
				for (int i = 0; i < ticketid; i++)
				{
					if (tickets[i].get_row() == roww)
					{
						if (tickets[i].get_place() == placee)
						{
							if (isequalarrays(temp, tickets[i].get_playname()))
							{
								cout << "This place is booked" << endl;
								return;
							}
						}
					}
				}
				if (isequalarrays(plays[sameplayid].get_playname(), temp) == 1)
				{
					tickets[ticketid].set_playname(temp);
					tickets[ticketid].set_isBooked(1);
				}
				else
				{
					cout << "There is not such a play" << endl;
					return;
				}
			}
			if (tempo == 6)
			{
				tickets[ticketid].set_note(temp);
			}
			if (tempo > 6)
			{
				char* oldnote = tickets[ticketid].get_note();
				char* newnote = strcat(oldnote, " ");
				char* verynew = strcat(newnote, temp);
				tickets[ticketid].set_note(verynew);
			}
			temp = strtok(NULL, " ");
		}
		cout << "Booked successfully" << endl;
		ticketid++;
		int places = plays[sameplayid].get_freeplaces();
		places--;
		plays[sameplayid].set_freeplaces(places);
		return;
	}
	if (isunbook(input) == 1)
	{
		char* temp;
		temp = strtok(input, " ");//unbook
		int tempo = 0;
		int roww = 0;
		int placee = 0;
		int foundticketid;
		while (temp != NULL)
		{
			tempo++;
			if (tempo == 2)
				roww = atoi(temp);

			if (tempo == 3)
				placee = atoi(temp);

			if (tempo == 4)
			{
				int found = 0;
				int concequence = 0;
				for (int i = 0; i < playid; i++)
				{
					struct tm playdatee = plays[i].get_playdate();
					int day = takingday(temp);
					int month = takingmonth(temp);
					int year = takingyear(temp);
					if (playdatee.tm_year == year && playdatee.tm_mon == month && playdatee.tm_mday)
						found = 1;
				}
				if (found == 0)
				{
					cout << "There is no play on this date" << endl;
					return;
				}
				for (int j = 0; j < ticketid; j++)
				{
					if (roww == tickets[j].get_row())
					{
						if (placee = tickets[j].get_place())
						{
							if (found == 1)
							{
								concequence = 1;
								foundticketid = j;
							}
						}
					}
				}
				if (concequence == 0)
				{
					cout << "No such ticket found" << endl;
					return;
				}
			}
			if (tempo == 5)
			{
				if (isequalarrays(temp, tickets[foundticketid].get_playname()) == 0)
				{
					cout << "Ticket info is wrong" << endl;
					return;
				}
				else
				{
					tickets[foundticketid].set_isBooked(0);
					cout << "Unbooked successfully" << endl;
					return;
				}
			}
			temp = strtok(NULL, " ");
		}

	}
	if (isBuy(input) == 1)
	{
		char* temp;
		temp = strtok(input, " ");//buy
		int tempo = 0;
		int roww = 0;
		int placee = 0;
		int found = 0;
		int success = 0;
		int foundplayid = 8;
		struct tm playdatee;
		while (temp != NULL)
		{
			tempo++;
			if (tempo == 2)
				roww = atoi(temp);

			if (tempo == 3)
				placee = atoi(temp);

			if (tempo == 4)
			{
				int day = takingday(temp);
				int month = takingmonth(temp);
				int year = takingyear(temp);
				
				playdatee.tm_year = year;
				playdatee.tm_mon = month;
				playdatee.tm_mday = day;
				for (int j = 0; j < ticketid; j++)
				{
					if (compare2dates(playdatee, tickets[j].get_playdate()) == 1) 
					{
						found = 1;
					}
				}
				if (found == 0)
				{
					cout << "There is no such ticket" << endl;
					return;
				}
			}

			if (tempo == 5)
			{
				for (int k = 0; k < playid; k++)
				{
					if (isequalarrays(temp, plays[k].get_playname()) == 1) 
					{
						if (compare2dates(plays[k].get_playdate(), playdatee) == 1) 
							foundplayid = k;
					}
				}
				for (int i = 0; i < ticketid; i++)
				{
					if (roww == tickets[i].get_row())
					{
						if (placee = tickets[i].get_place())
						{
							if (found == 1)
							{
								if (isequalarrays(temp, tickets[i].get_playname()) == 1)
								{

									success = 1;
									tickets[i].set_isPaid(1);
									int uniquuecode = roww * 100 + placee;
									tickets[i].set_uniquecode(uniquuecode);
									break;
								}
							}
						}
					}
				}

			}
			temp = strtok(NULL, " ");
		}
		if (success == 0)
		{
			cout << "No ticket found" << endl;
			return;
		}
		cout << foundplayid << endl;
		int oldticks=plays[foundplayid].get_boughttickets();
		oldticks++;
		plays[foundplayid].set_boughttickets(oldticks);
		cout << "Ticket bought successfully" << endl;
		return;
	}
	if (isbookings(input) == 1) 
	{
		char* temp;
		temp = strtok(input, " ");//bookings
		int tempo = 0;
		struct tm newdate;
		int found=0;
		while (temp != NULL)
		{
			tempo++;
			if (tempo == 2) 
			{
				int day = takingday(temp);
				int month = takingmonth(temp);
				int year = takingyear(temp);
				newdate.tm_year = year;
				newdate.tm_mon = month;
				newdate.tm_mday = day;
				
			}
			if (tempo == 3) 
			{
				for (int i = 0; i < ticketid; i++)
				{
					if (compare2dates(newdate, tickets[i].get_playdate()) == 1)
					{
						if (isequalarrays(tickets[i].get_playname(), temp) == 1) 
						{
							tickets[i].showinfo();
						}
					}

				}
			}
			temp = strtok(NULL, " ");

			
		}
	}
	if (isCheck(input) == 1) 
	{
		char* temp;
		temp = strtok(input, " ");//check
		temp = strtok(NULL, " ");
		for (int i = 0; i < ticketid; i++)
		{
		   int uniqquecode = atoi(temp);
		  if(tickets[i].get_uniquecode()==uniqquecode)
		  {
			  tickets[i].showinfo();
			  return;
		  }
		}
		cout << "Ticket not found" << endl;
		return;
	}
	if (isReport(input) == 1) 
	{
		char* temp;
		char firstdate[11];
		char seconddate[11];
		temp = strtok(input, " ");//report
		int tempo = 0;
		int done = 0;

		while (temp != NULL)
		{
			tempo++;
			if (tempo == 2)
				strcpy(firstdate, temp);

			if (tempo == 3)
				strcpy(seconddate, temp);
			
			if (tempo == 4) 
			{
				int halll = atoi(temp);
				int fromdate[4];
				fromdate[0] = takingday(firstdate);
				fromdate[1] = takingmonth(firstdate);
				fromdate[2] = takingyear(firstdate);
				int todate[4];
				todate[0] = takingday(seconddate);
				todate[1] = takingmonth(seconddate);
				todate[2] = takingyear(seconddate);
				if (fromdate[2] == todate[2])
				{
					if (fromdate[1] == todate[1])
					{
						for (int j = 0; j < playid; j++)
						{
							struct tm playdatee = plays[j].get_playdate();
							if (fromdate[2] == playdatee.tm_year)
							{
								if (fromdate[1] == playdatee.tm_mon)
								{
									if (fromdate[0] <= playdatee.tm_mday && playdatee.tm_mday <= todate[0])
									{
										if (plays[j].get_playhallid() == halll)
										{
											plays[j].showinfo();
											done = 1;
										}
									}
								}
							}
						}
					}
				}
			}
			temp = strtok(NULL, " ");
		}
		if (done == 0) 
		{
			cout << "Nothing found" << endl;
			return;
		}
	}
}


