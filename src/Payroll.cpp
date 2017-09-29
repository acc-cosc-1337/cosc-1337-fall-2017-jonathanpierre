#include "Payroll.h"
#include <math.h>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int validateMenuChoice(int menuChoice)
{
	while (menuChoice < 1 || menuChoice > 2)
	{
		cout << "Re-enter: ";
		cin >> menuChoice;
	}
	return menuChoice;
}

bool getOvertimeStatus(int hours)
{
	bool overtimeStatus;

	if (hours > 40)
		overtimeStatus = true;
	else
		overtimeStatus = false;
	return overtimeStatus;
}

int validateHours(int h)
{
	while (h <= 0 || h >= 60)
	{
		cout << "Re-enter: ";
		cin >> h;
	}
	return h;
}

double validateRate(double r)
{
	while (r <= 0 || r >= 50)
	{
		cout << "Re-enter: ";
		cin >> r;
	}
	return r;
}

double validateSalary(double sal)
{
	while (sal < 20000 || sal > 100000)
	{
		cout << "Re-enter: ";
		cin >> sal;
	}
	return sal;
}

int getOvertimeHours(int hours)
{
	return hours - 40;
}

int getRegularHours(int hours, int overtimeHours)
{
	return (hours - overtimeHours);
}

double getfIT(double gross, double FITTAXRATE)
{
	return gross * FITTAXRATE;
}

double getficasSSN(double grossPay, double SSTAXRATE)
{
	return grossPay * SSTAXRATE;
}

double getficaMED(double grossPay, double MEDICARETAXRATE)
{
	return grossPay * MEDICARETAXRATE;
}

double getNetPay(double grossPay, double fedIncomeTax, double ficaSSN, double ficaMED)
{
	return grossPay - fedIncomeTax - ficaSSN - ficaMED;
}

void printPayroll(bool isHourlyEmployee[], string name[], int hours[], int overtimeHours[],
	double rate[], double overtimeRate[], double regularPay[],
	double overtimePay[], double grossPay[], double ficaSSN[], double ficaMED[], double fedIncomeTax[], double netPay[])
{

	cout << fixed << setprecision(2)
		<< left << setw(10) << "Name"
		<< setw(7) << "Hours"
		<< setw(9) << "OT Hours"
		<< setw(7) << "Rate"
		<< setw(9) << "OT Rate"
		<< setw(12) << "Regular Pay"
		<< setw(9) << "OT Pay"
		<< setw(10) << "Gross Pay"
		<< setw(10) << "FICASSN"
		<< setw(10) << "FICA Med"
		<< setw(8) << "FIT"
		<< setw(9) << "Net Pay" << endl;

	for (int e = 0; e < 3; e++)
	{
		cout << setw(10) << name[e];

		(isHourlyEmployee[e]) ? cout << setw(7) << hours[e] : cout << setw(7) << " ";
		(isHourlyEmployee[e]) ? cout << setw(9) << overtimeHours[e] : cout << setw(9) << " ";
		(isHourlyEmployee[e]) ? cout << setw(7) << rate[e] : cout << setw(7) << " ";
		(isHourlyEmployee[e]) ? cout << setw(9) << overtimeRate[e] : cout << setw(9) << " ";
		cout << setw(12) << regularPay[e];
		(isHourlyEmployee[e]) ? cout << setw(9) << overtimePay[e] : cout << setw(9) << " ";

		cout << setw(10) << grossPay[e]
			<< setw(10) << ficaSSN[e]
			<< setw(10) << ficaMED[e]
			<< setw(8) << fedIncomeTax[e]
			<< setw(9) << netPay[e]
			<< endl;
	}
}
