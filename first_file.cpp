#include <iostream>
#include<string>
#include<iomanip>
#include<fstream>


using namespace std;

//AAssigment #2
//Angel Briceno 

int main()
{
	//////// Housekeeping
	string guestName,roomString;
	char roomType;
	int noDays, noGuest=0;
	double roomCharge = 0.0, averageRate, totalCharge = 0.0;
	ofstream fout("chargeAngel.dat");
	const double DAILYPOOL = 80.0, DAILYGARDEN = 100.0, DAILYLAKE = 125.0;
	fout << fixed;
	fout << setprecision(2);


	//////// Input
	cout << "Welcome to Angel's Resort Hotel! " << endl 
		<< "to sign in we need the following info: " << endl << endl;

	cout << "- To sign in, please enter the guest name: " << endl;
	getline(cin, guestName);
	
			//////// Processing
	fout << setw(42)<< right << "Angel Resort Hotel Room Charge" << endl;
	fout << setw(16) << left << "Guest Name:"
		<< setw(15) << "Room Type:"
		<< setw(7) << right << "#Days:"
		<< setw(15) << "Room Charge:"
		<< endl<< endl;

	while (!cin.eof()) {
		cout << "- Please enter the number of days want to stay: " << endl;
		cin >> noDays;
		while (noDays < 0 || cin.fail())
		{
			cin.clear();
			cin.ignore(80, '\n');
			cout << "ups, just possitive numbers please, re-enter: " << endl;
			cin >> noDays;
		}

		cout << "- Please enter the type of room you are looking for." << endl
			<< "'g' - Garden View, 'p' - Pool view, or 'l' - Lake view. (g/p/l): " << endl;
		cin >> roomType;
		while (roomType != 'g' && roomType != 'p' && roomType != 'l')
		{
		
			cout << "wrong code, please re enter (g/p/l): " << endl;
			cin >> roomType;
		}

		if (roomType == 'p')
			roomString = "Pool View";
		else if (roomType == 'g')
			roomString = "Garden View";
		else
			roomString = "Lake view";
		
		if (roomType == 'p')
			roomCharge = DAILYPOOL * noDays;
		else if (roomType == 'g')
			roomCharge = DAILYGARDEN * noDays;
		else
			roomCharge = DAILYLAKE * noDays;

		fout << setw(16) << left << guestName
			<< setw(15) << roomString
			<< setw(7) << right << noDays
			<< setw(15) << roomCharge
			<< endl;

		cout << "- enter Ctrl Z to finish or enter next guest name: " << endl;
		cin.ignore(80, '\n');
		getline(cin, guestName);
		
		noGuest++;
		totalCharge += roomCharge;	
	}

	averageRate = totalCharge / noGuest;
	
	//////// Output
	fout << endl;
	fout << setw(10) << left << "Average Room Charge"
		<< setw(34)<< right << averageRate << endl;

	if (!fout.is_open())
	{
		cout << "chargeAngel.dat did not open:( " << endl;
		system("pause");
		exit(-1);
	}	
	system("type chargeAngel.dat");
	system("pause");
}
/*******************************************************
This Assignment was pretty challenging, I enjoyed 
finishing it and be able to solve the problems.
-I found difficult find how to divide the info in 
the HIPO format.
-Getting the average was kind of hard too beacuse
of the info in the loop is lost after the 
loop finishes.
-Find a way to show the output the way it suppose to was 
the hardest, I solved it with your help and the algorithm.
In general, this was very interesting
to solve I spent a lot of time to solve it.

********************************************************/
/*******************************************************
Welcome to Angel's Resort Hotel!
to sign in we need the following info :

-To sign in, please enter the guest name :
B.Angel
- Please enter the number of days want to stay :
4
- Please enter the type of room you are looking for.
'g' - Garden View, 'p' - Pool view, or 'l' - Lake view. (g / p / l) :
	g
	- enter Ctrl Z to finish or enter next guest name :
G.Paola
- Please enter the number of days want to stay :
3
- Please enter the type of room you are looking for.
'g' - Garden View, 'p' - Pool view, or 'l' - Lake view. (g / p / l) :
	p
	- enter Ctrl Z to finish or enter next guest name :
B.Carlos
- Please enter the number of days want to stay :
p
ups, just possitive numbers please, re - enter :
	7
	- Please enter the type of room you are looking for.
	'g' - Garden View, 'p' - Pool view, or 'l' - Lake view. (g / p / l) :
	l
	- enter Ctrl Z to finish or enter next guest name :
^ Z
Angel Resort Hotel Room Charge
Guest Name : Room Type : #Days : Room Charge :

B.Angel        Garden View          4         400.00
G.Paola        Pool View            3         240.00
B.Carlos       Lake view            7         875.00

Average Room Charge                            505.00
Press any key to continue . . .

**********************************************************/
