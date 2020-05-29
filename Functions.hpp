#include <iostream>
using namespace std;

char addevent[] = "addevent";
char freeseats[] = "freeseats";
char book[] = "book";
char unbook[] = "unbook";
char buyy[] = "Buy";
char bookings[] = "Bookings";
char check[] = "check";
char report[] = "report";

bool isequalarrays(char* temp, char* temp1)
{
	int len = strlen(temp);
	int len1 = strlen(temp1);
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (temp[i] == temp1[i])count++;
		else break;
	}
	if (count == len)return 1;
	else return 0;
}
int takingday(char* temp)
{
	int day = 0;
	int num1;
	int num2;
	char* dayaschar = new char[4];
	for (int i = 0; i < strlen(temp); i++)
	{
		if (temp[i] == '.')
		{
			for (int j = 0; j < i; j++)
			{
				dayaschar[j] = temp[j];
			}
		}
	}
	day = atoi(dayaschar);
	return day;
}
int takingmonth(char* temp)
{
	int month = 0;
	int num1;
	int num2;
	for (int i = 3; i < strlen(temp); i++)
	{
		if (temp[i] == '.')
		{
			num1 = temp[i - 2] - '0';
			num2 = temp[i - 1] - '0';
			month = num1 * 10 + num2;
		}
	}
	return month;

}
int takingyear(char* temp)
{
	int year = 0;
	if (temp[6] == '.')
	{

		int num2 = temp[7] - '0';
		int num3 = temp[8] - '0';
		int num4 = temp[9] - '0';
		int num5 = temp[10] - '0';
		year = num2 * 1000 + num3 * 100 + num4 * 10 + num5;
		return year;
	}
	int num1 = temp[6] - '0';
	int num2 = temp[7] - '0';
	int num3 = temp[8] - '0';
	int num4 = temp[9] - '0';
	year = num1 * 1000 + num2 * 100 + num3 * 10 + num4;
	return year;
}
bool compare2dates(struct tm firstexpdate, struct tm secondexpdate)
{
	int firstexpyear = firstexpdate.tm_year;
	int firstexpmonth = firstexpdate.tm_mon;
	int firstexpday = firstexpdate.tm_mday;
	int secondexpyear = secondexpdate.tm_year;
	int secondexpmonth = secondexpdate.tm_mon;
	int secondexpday = secondexpdate.tm_mday;
	if (firstexpyear <= secondexpyear)
	{
		if (firstexpmonth <= secondexpmonth)
		{
			if (firstexpday <= secondexpday)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}


bool isAddevent(char input[])
{
	int len = 0;
	int temp = 0;
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] == ' ')
		{
			for (int j = 0; j < i; j++)
			{
				if (input[j] == addevent[j])
					len++;

				else break;
			}
		}
		if (len == strlen(addevent))
		{
			return 1;
			break;
		}
	}
	return 0;
}
bool isfreeseats(char input[])
{
	int len = 0;
	int temp = 0;
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] == ' ')
		{
			for (int j = 0; j < i; j++)
			{
				if (input[j] == freeseats[j])
					len++;

				else break;
			}
		}
		if (len == strlen(freeseats))
		{
			return 1;
			break;
		}
	}
	return 0;
}
bool isbook(char input[]) 
{
	int len = 0;
	int temp = 0;
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] == ' ')
		{
			for (int j = 0; j < i; j++)
			{
				if (input[j] == book[j])
					len++;

				else break;
			}
		}
		if (len == strlen(book))
		{
			return 1;
			break;
		}
	}
	return 0;
}
bool isunbook(char input[])
{

	int len = 0;
	int temp = 0;
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] == ' ')
		{
			for (int j = 0; j < i; j++)
			{
				if (input[j] == unbook[j])
					len++;

				else break;
			}
		}
		if (len == strlen(unbook))
		{
			return 1;
			break;
		}
	}
	return 0;
}
bool isBuy(char input[])
{
	int len = 0;
	int temp = 0;
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] == ' ')
		{
			for (int j = 0; j < i; j++)
			{
				if (input[j] == buyy[j])
					len++;

				else break;
			}
		}
		if (len == strlen(buyy))
		{
			return 1;
			break;
		}
	}
	return 0;
}
bool isbookings(char input[])
{
	int len = 0;
	int temp = 0;
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] == ' ')
		{
			for (int j = 0; j < i; j++)
			{
				if (input[j] == bookings[j])
					len++;

				else break;
			}
		}
		if (len == strlen(bookings))
		{
			return 1;
			break;
		}
	}
	return 0;
}
bool isCheck(char input[]) 
{
	int len = 0;
	int temp = 0;
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] == ' ')
		{
			for (int j = 0; j < i; j++)
			{
				if (input[j] == check[j])
					len++;

				else break;
			}
		}
		if (len == strlen(check))
		{
			return 1;
			break;
		}
	}
	return 0;

}
bool isReport(char input[])
{
	int len = 0;
	int temp = 0;
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] == ' ')
		{
			for (int j = 0; j < i; j++)
			{
				if (input[j] == report[j])
					len++;

				else break;
			}
		}
		if (len == strlen(report))
		{
			return 1;
			break;
		}
	}
	return 0;

}