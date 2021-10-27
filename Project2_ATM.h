#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct account {
	string accnumber;
	string name;
	string nip;
	float balance=0;
};

void Displaytitle(string anytitle)
{
	short len = anytitle.length();
	for (short i = 0; i < len; i++)
	{
		anytitle[i] = toupper(anytitle[i]);

	}
	cout << "\t\t\t" << anytitle << endl;
	cout << "\t\t\t";
	for (short i = 0; i < len; i++)
	{
		cout << "-";
	}
	cout << "\n\n";
}

void DisplaySubtitle(string anytitle)
{
	short len = anytitle.length();
	for (short i = 0; i < len; i++)
	{
		anytitle[i] = toupper(anytitle[i]);

	}
	cout << "\t\t" << anytitle << endl;
	cout << "\t\t";
	for (short i = 0; i < len; i++)
	{
		cout << "-";
	}
	cout << "\n\n";
}

short ReadFromTextfile(account tabclients[])
{
	fstream myfile;
	short i = 0;
	myfile.open("atm.txt",ios::in);

	while (!myfile.eof())
	{	
		
		getline(myfile,tabclients[i].accnumber);
		getline(myfile, tabclients[i].name);
		getline(myfile, tabclients[i].nip);
		myfile>>tabclients[i].balance;
		myfile.ignore();
		i++;
		
	}
	
	
	/*for (short j = 0; j < i; j++)
	{
		cout << tabclients[j].accnumber << endl;
		cout << tabclients[j].name << endl;
		cout << tabclients[j].nip << endl;
		cout << tabclients[j].balance << endl;
	}*/

	myfile.close();

	return i;
}




string ReadcusAccnum()
{
	
	string accnumber;
	
	do {
		cout << "Enter your account number: ";
		cin >> accnumber;
		short len;
		len = accnumber.length();
		for (short a = 0; a < len; a++)
		{
			accnumber[a] = toupper(accnumber[a]);
		}
	} while (accnumber == "");

	return accnumber;
}

string Readcusnip()
{

	string nip;

	do {

		cout << "Enter your nip: ";
		cin >> nip;

	} while (nip == "");
	

	return nip;
}




short ValidateAcc(account tabclients[],short allaccounts)
{
	string acnum, nip;
	short accindex=0, loop = 0;

	do {
		acnum = ReadcusAccnum();
		

		for (short i = 0; i <allaccounts; i++)
		{
			if (tabclients[i].accnumber==acnum)
			{
				
				accindex = i;
				loop++;
				
	
			}
			else
			{
				(loop == 0);
			}
			

		}
	} while (loop==0);
	
	return accindex;
	
}

void Displayaccname(short accindext, account tabclients[])
{
	cout << "Welcome " << tabclients[accindext].name << endl;
}

void Nipverification(account tabclients[],short accindex)
{
	string nip;
	short loop = 0;
	do {
		nip = Readcusnip();
		
			if (tabclients[accindex].nip == nip)
			{
				
				loop++;
			}
			else
			{
				(loop == 0);
			}
		
			
	}while (loop == 0);
	
}

	
void Displaymenu()
{
	cout << "\t1-Deposit\n\t2-Withdrawal\n\t3-Consultation\n";

}

short Readchoice(short min,short max)
{
	short choice;
	do {
		cout << "Enter you choice (" << min << "-" << max << "): ";
		cin >> choice;
	} while (choice < min || choice > max);


	return choice;
}

float ReadAmountDep(short min, int max)
{
	float amount;
	do {
		cout << "Enter amout to deposit (betwen $" << min << "-$" << max << "): ";
		cin >> amount;
	} while (amount<min || amount>max);
	return amount;
}
void Savefile(account tabclients[],short allaccounts)
{
	fstream myfile;
	myfile.open("atm.txt", ios::out);
	for (short i = 0; i < allaccounts - 1; i++)
	{
		myfile << tabclients[i].accnumber << endl;
		myfile << tabclients[i].name<<endl;
		myfile << tabclients[i].nip << endl;
		myfile << tabclients[i].balance<<endl;

	}

	myfile << tabclients[allaccounts - 1].accnumber << endl;
	myfile << tabclients[allaccounts - 1].name << endl;
	myfile << tabclients[allaccounts - 1].nip << endl;
	myfile << tabclients[allaccounts - 1].balance;

	myfile.close();

}
void Display()
{
	cout << "*==========\tTranscation completed with success\t==========*\n";
}

void PerformdeDeposite(account tabclients[], short accindex, short allaccounts,float amountdp)
{
	
	tabclients[accindex].balance = tabclients[accindex].balance + amountdp;
	
	Savefile(tabclients, allaccounts);
	Display();

}

float ReadWithdrawal(short min,int max)
{
	float amountwd;
	do {

		cout << "Enter amount to withdraw (between $" << min << "-$" << max << "): ";
		cin >> amountwd;
		
	} while (amountwd<min || amountwd>max);
	return amountwd;
}

void PerformWithdrawal(account tabclients[], short accindex, short allaccounts, float amountwd)
{

	tabclients[accindex].balance = tabclients[accindex].balance - amountwd;

	Savefile(tabclients, allaccounts);
	Display();

}

void Displayconsaltation(short accindex, account tabclients[])
{
	cout << "\tThe summary of account" << endl;
	cout << left << setw(20) << "Number: " << setw(10) << tabclients[accindex].accnumber << endl;
	cout << left << setw(20) << "Client: " << setw(10) << tabclients[accindex].name << endl;
	cout << left << setw(20) << "Nip: " << setw(10) << tabclients[accindex].nip << endl;
	cout << left << setw(20) << "Balance: " << setw(10) << "$"<<tabclients[accindex].balance << endl;

	cout << "\nThanks for using our services." << endl;


	
}
