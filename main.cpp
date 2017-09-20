#include "Payroll.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	stringstream	employeeOneStream, employeeTwoStream, employeeThreeStream;
	string			name;
	int				menuChoice, hours, overtimeHours, regularHours;
	double			rate, overtimeRate, regularPay, overtimePay = 0, grossPay,
		salary, ficaSSN, ficaMED, fedIncomeTax, netPay;
	const double	OTMULTIPLIER = 1.5,
		FITTAXRATE = .15,
		SSTAXRATE = .062,
		MEDICARETAXRATE = .0145;
	bool			isHourlyEmployee, overtime;
	enum { hourlyEmployee = 1, salaryEmployee = 2 };

	cout << "Payroll Calculation Program." << endl;

	for (int i = 0; i < 3; i++)
	{
		// initialize variables to 0
		hours = 0, overtimeHours = 0, rate = 0, overtimeRate = 0, regularPay = 0, overtimePay = 0, grossPay = 0, salary = 0;

		cout << "Employee name: ";
		cin >> name;

		cout << "Press 1 - hourly" << endl;
		cout << "Press 2 - salary" << endl;
		cin >> menuChoice;

		menuChoice = validateMenuChoice(menuChoice);

		switch (menuChoice)
		{
		case hourlyEmployee:
			isHourlyEmployee = true;

			cout << "Enter hours worked: ";
			cin >> hours;

			hours = validateHours(hours);

			cout << "Enter hourly pay rate: ";
			cin >> rate;

			rate = validateRate(rate);

			overtime = getOvertimeStatus(hours);

			if (overtime)
			{
				overtimeHours = getOvertimeHours(hours);
				regularHours = getRegularHours(hours, overtimeHours);
				regularPay = regularHours * rate;
				overtimeRate = rate * OTMULTIPLIER;
				overtimePay = overtimeHours * overtimeRate;
				grossPay = regularPay + overtimePay;
			}
			else
			{
				regularPay = grossPay = hours * rate;
			}
			break;

		case salaryEmployee:
			isHourlyEmployee = false;
			overtime = false;

			cout << "Enter gross salary: ";
			cin >> salary;

			salary = validateSalary(salary);
			grossPay = regularPay = salary / 26;
			break;

		default: cout << "bad input";
		}
		//end switch

		fedIncomeTax = getfIT(grossPay, FITTAXRATE);
		ficaSSN = getficasSSN(grossPay, SSTAXRATE);
		ficaMED = getficaMED(grossPay, MEDICARETAXRATE);
		netPay = getNetPay(grossPay, fedIncomeTax, ficaSSN, ficaMED);

		if (i == 0)
		{
			employeeOneStream = getStream(isHourlyEmployee, name, hours, overtimeHours, rate, overtimeRate, regularPay,
				overtimePay, grossPay, ficaSSN, ficaMED, fedIncomeTax, netPay);
		}
		if (i == 1)
		{
			employeeTwoStream = getStream(isHourlyEmployee, name, hours, overtimeHours, rate, overtimeRate, regularPay,
				overtimePay, grossPay, ficaSSN, ficaMED, fedIncomeTax, netPay);
		}
		if (i == 2)
		{
			employeeThreeStream = getStream(isHourlyEmployee, name, hours, overtimeHours, rate, overtimeRate, regularPay,
				overtimePay, grossPay, ficaSSN, ficaMED, fedIncomeTax, netPay);
		}

	}
	// end of employee loop

	printPayroll();

	cout << employeeOneStream.str();
	cout << employeeTwoStream.str();
	cout << employeeThreeStream.str();

	system("pause");
	return 0;
}
