#include "Project2_ATM.h"


void main()
{

	account arrClients[200];
	string AccNumber;
	short Choice, AccIndex, allAccounts = 0;
	float AmountDep, AmountWid;
	do {
		system("cls");
		Displaytitle("banque royale");
		Displaytitle("guichet automatque bancaire");
		allAccounts = ReadFromTextfile(arrClients);
		AccIndex = ValidateAcc(arrClients, allAccounts);
		Displayaccname(AccIndex, arrClients);
		Nipverification(arrClients, AccIndex);
		Displaymenu();
		Choice = Readchoice(1, 3);
		switch (Choice)
		{
		case 1:
			AmountDep = ReadAmountDep(2, 20000);
			PerformdeDeposite(arrClients, AccIndex, allAccounts, AmountDep);
			break;
		case 2:
			AmountWid = ReadWithdrawal(20, 500);
			PerformWithdrawal(arrClients, AccIndex, allAccounts, AmountWid);
			break;
		case 3:
			Displayconsaltation(AccIndex, arrClients);
			break;

		}

		system("pause");
	} while (Choice == 1 || Choice == 2 || Choice == 3);
}