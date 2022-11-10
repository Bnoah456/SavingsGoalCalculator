//this is a Budget Calculator
//you will enter your target money goal, how much money you currently have, 
// target date (month,day,year) you want to reach the goal by
//Enter current date (month , day, year)
//started on 11/7/2022

#include<iostream>
#include<iomanip>
using namespace std;

struct Target
{
	double goal;
	int month;
};

struct Current
{
	double moneyAvalible;
	double interestRate;
};
struct Remainder
{
	double remainder;
};
struct TimeToGoal
{
	int months;
};
struct Info //get all the important info we need
{
	Current current;
	Target target;
	Remainder remainder; //calculate remainder of what you already have
};


double getBudgetInfo(Info&);
int get_Months(Info& m);
void calculateInfo(Info& );


int main()
{
	Info info;
	cout << "Budget Goal Estimator" << endl << endl;
	getBudgetInfo(info);
	get_Months(info);
	calculateInfo(info);
	return 0;
}

double getBudgetInfo(Info& i)
{
	cout << "Enter Target Goal: $"; //get the money goal
	cin >> i.target.goal;

	cout << "Enter how much money you have now (Enter -1 if you wish to skip this): $";
	cin >> i.current.moneyAvalible;

	i.remainder.remainder = i.target.goal - i.current.moneyAvalible;
	cout << "Here is our remainder: $" << i.remainder.remainder << endl;

	return i.remainder.remainder;
}

int get_Months(Info& m)
{
	cout << "Enter in months how long you wish to reach your goal: ";
	cin >> m.target.month;
	cout << "You entered: " << m.target.month << " Months" << endl;

	return m.target.month;
}
void calculateInfo(Info& remainder)
{
	int month_Entered = remainder.target.month;
	double starting_Balance = remainder.remainder.remainder;
	double monthly_Contribution;
	double week = 4.3452381;
	double week_Total;
	double weekly_Contribution;
	double days = 30.4166667;
	double days_Total;
	double daily_Contribution;

	int count = 0; //our month counter
	//to get the budget info in months (monthly contribution goal)

	monthly_Contribution = remainder.remainder.remainder / remainder.target.month;
	week_Total = remainder.target.month * week;
	days_Total = remainder.target.month * days;
	weekly_Contribution = remainder.remainder.remainder / week_Total;
	daily_Contribution = remainder.remainder.remainder / days_Total;

	cout << "Weeks: " << week_Total << endl;
	cout << "Days: " << days_Total << endl;

	cout << "So in " << remainder.target.month << " Months you need to save: $" << monthly_Contribution << " Per month to reach your goal." << endl;
	cout << "$" << weekly_Contribution << " Weekly." << endl;
	cout << "$" << daily_Contribution << " Daily." << endl;
	
}

