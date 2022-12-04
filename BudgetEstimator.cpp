#include<iostream>
#include<iomanip>
#include<fstream>
//#include<ofstream>
using namespace std;
//*****Holds our Savings goal & Holds our target month******
struct Target
{
	double goal; 
	int month; 
};
//**Holds the current amount of money we have right now***
struct Current
{
	double moneyAvalible; 
};
//**Holds our remainder***
struct Remainder
{
	double remainder; 
};
//**Holds all the important info we need***
struct Info 
{
	Current current;
	Target target;
	Remainder remainder; //Calculates remainder of what you already have
};

//******Prototypes*******
double getBudgetInfo( Info& );
int get_Months( Info& );
void calculateInfo( Info& );
void writeToFile( Info& );
bool doAgain( );

int main( )
{
	//**Do-while loop to repeat the program if desired**
	do {
		Info info;
		char again = 'y';
		//Title of Program*******
		cout << "--------------------------------" << endl;
		cout << "**** Savings Goal Estimator ****" << endl;
		cout << "--------------------------------" << endl;
		//call to protoypes*******
		getBudgetInfo( info );
		get_Months( info );
		calculateInfo( info );
		writeToFile( info );
	}while ( doAgain( ) );
	//*****End of program title****
	cout << endl << "\t\tThanks for using the Savings Goal Calculator today!" << endl;
	return 0;
}
//**Get the Target Savings**
double getBudgetInfo( Info& info )
{
	info.target.goal = 0; //**initilize to remove warnings.**
	info.current.moneyAvalible = 0; //**initilize to remove warnings.**
	//**Enter target savings goal.**
	cout << "Enter Target Savings Goal: $";
	while ( !(cin >> info.target.goal) || info.target.goal <= 0 )
	{
		cout << "No negative values, numbers, or special symbols allowed..." << endl;
		cout << "Re-Enter Target Goal: $";
		//cin >> info.target.goal;
		cin.clear( );
		cin.ignore( 123, '\n' );
	}
	//**Enter current money on hand**
	cout << "Enter amount of money you're willing to contribute to begin saving (Enter 0 if you wish to skip this): $";
	while( !(cin >>info.current.moneyAvalible) || info.current.moneyAvalible <= -1 )
	{
		cout << "No negative values, numbers, or special symbols allowed..." << endl;
		cout << "Re-Enter how much money you have now or (Enter 0 if you wish to skip this): $";
		cin.clear( );
		cin.ignore( 123, '\n' );
	}
	//**End the Program.**
	if ( info.current.moneyAvalible >= info.target.goal )
	{
		cout << endl << "\t\tUmmm...looks like you already reached your goal...guess you don't need me after all!" << endl <<endl;
		cout << "\t\tThanks for using the Savings Goal Calculator today!" << endl;
		exit( 0 );
	}
	//**Continue target savings goal.**
	if ( info.current.moneyAvalible == 0 ) 
	{
		info.remainder.remainder = info.target.goal;
		cout << "Let's continue your goal of: $" << info.remainder.remainder << endl;
		return info.remainder.remainder;
	}
	//**Update target savings goal & Display.**
	else if ( info.current.moneyAvalible != 0  &&  info.current.moneyAvalible >= 1 )
	{
		info.remainder.remainder = info.target.goal - info.current.moneyAvalible;
		cout << "Here is your updated goal: $" << info.remainder.remainder << endl;
		return info.remainder.remainder;
	}
}
//**Get the desired Months.**
int get_Months( Info& info )
{
	cout << "Enter in months how long you wish to reach your goal: ";
	while ( !(cin >> info.target.month) || info.target.month <= 0 )
	{
		cout << "No negative values, numbers, or special symbols allowed..." << endl;
		cout << "Re-Enter in months how long you wish to reach your goal: ";
		cin.clear( );
		cin.ignore( 123, '\n' );
	}
	cout << "You entered: " << info.target.month << " Months" << endl << endl;
	return info.target.month;
}
//**Calculate the data entered.**
void calculateInfo( Info& info )
{
	int month_Entered = info.target.month;
	double monthly_Contribution;
	const double week = 4.3452381;
	double week_Total;
	double weekly_Contribution;
	const double days = 30.4166667;
	double days_Total;
	double daily_Contribution;
	//**Calculations going on here**
	week_Total = info.target.month * week; // **Total weeks**
	days_Total = info.target.month * days; // **Total days**
	monthly_Contribution = info.remainder.remainder / info.target.month; // **Monthly tribute**
	weekly_Contribution = info.remainder.remainder / week_Total; // **Weekly tribute**
	daily_Contribution = info.remainder.remainder / days_Total; // **Daily tribute**
	//**Displaying the results**
	cout << "\t\t\t---------------------------------------" << endl;
	cout << "\t\t\tTo meet your goal of: $" << info.remainder.remainder << " In " << info.target.month << " Months." << endl;
	cout << "\t\t\t---------------------------------------" << endl;
	cout << "\t\t\tIt is suggested you contribute: $" << monthly_Contribution << " Monthly." << endl;
	cout << "\t\t\t\t\tOr...." << endl;
	cout << "\t\t\tIt is suggested you contribute: $" << weekly_Contribution << " Weekly." << endl;
	cout << "\t\t\t\t\tOr...." << endl;
	cout << "\t\t\tIt is suggested you contribute: $" << daily_Contribution << " Daily." << endl << endl;
}
//**Writing to a .txt file on NotePad**
void writeToFile( Info& info )
{
	// **Open the file and name it....**
	ofstream SavingsGoalReport;
	SavingsGoalReport.open("SavingsGoalReport.txt");
	int month_Entered = info.target.month;
	double starting_Balance = info.remainder.remainder;
	double monthly_Contribution;
	double week = 4.3452381;
	double week_Total;
	double weekly_Contribution;
	double days = 30.4166667;
	double days_Total;
	double daily_Contribution;
	//**Calculations going on here**
	week_Total = info.target.month * week; // **Total weeks**
	days_Total = info.target.month * days; // **Total days**
	monthly_Contribution = info.remainder.remainder / info.target.month; // **Monthly tribute**
	weekly_Contribution = info.remainder.remainder / week_Total; // **Weekly tribute**
	daily_Contribution = info.remainder.remainder / days_Total; // **Daily tribute**
	
	//**Displaying the results**
	SavingsGoalReport << "\t\t\t---------------------------------------" << endl;
	SavingsGoalReport << "\t\t\tTo meet your goal of: $" << info.remainder.remainder <<" In "<< info.target.month << " Months." << endl;
	SavingsGoalReport << "\t\t\t---------------------------------------" << endl;
	SavingsGoalReport << "\t\t\tIt is suggested you contribute: $" << monthly_Contribution << " Monthly." << endl;
	SavingsGoalReport << "\t\t\t\t\tOr...." << endl;
	SavingsGoalReport << "\t\t\tIt is suggested you contribute: $" << weekly_Contribution << " Weekly." << endl;
	SavingsGoalReport << "\t\t\t\t\tOr...." << endl;
	SavingsGoalReport << "\t\t\tIt is suggested you contribute: $" << daily_Contribution << " Daily." << endl << endl;
	//**Close the file**
	if (SavingsGoalReport.is_open())
	{
		SavingsGoalReport << "File opened successfully!" << endl;
	}
	else
	{
		SavingsGoalReport << "Oopsie, something went wrong." << endl;
	}
	SavingsGoalReport.close();
}
//**Asks the user choice to repeat again**
bool doAgain( )
{
	char again = 'y';
	cout << "\t\tWould you like to do this again? ( Y/N ):  ";
	cin >> again;
	while ( !(again == 'Y' || again == 'y' || again == 'N' || again == 'n') )
	{
		cout << "\t\tPlease try again ( Y/N ):  ";
		cin >> again;
	}
	if ( again == 'Y' || again == 'y' )
	{
		return true;
	}
	else
	{
		return false;
	}
}
