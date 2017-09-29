#include "Payroll.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	string		name[3];
	int		menuChoice;
	int		hours[3];
	int		overtimeHours[3];
	int		regularHours[3];
	double		rate[3];
	double		overtimeRate[3];
	double		regularPay[3];
	double		overtimePay[3];
	double		grossPay[3];
	double		salary;
	double		ficaSSN[3];
	double		ficaMED[3];
	double		fedIncomeTax[3];
	double		netPay[3];
	const double	OTMULTIPLIER = 1.5;
	const double	FITTAXRATE = .15;
	const double	SSTAXRATE = .062;
	const double	MEDICARETAXRATE = .0145;
	bool		isHourlyEmployee[3];
	bool		overtime;
	
	cout << "Payroll Calculation Program." << endl;

	for (int i = 0; i < 3; i++)
	{

		hours[0] = 0;
		regularHours[i] = 0;
		overtimeHours[i] = 0;
		overtimeRate[i] = 0;
		rate[i] = 0;
		regularPay[i] = 0;
		overtimePay[i] = 0;
		grossPay[i] = 0;
		salary = 0;
		enum { hourlyEmployee = 1, salaryEmployee = 2 };

		cout << "Employee name: ";
		cin >> name[i];

		cout << "Press 1(hourly) 2(Salary): " << endl;
		cin >> menuChoice;

		menuChoice = validateMenuChoice(menuChoice);
		
		switch (menuChoice)
		{
		case hourlyEmployee:
			isHourlyEmployee[i] = true;
			overtime = false;

			cout << "Enter hours worked: ";
			cin >> hours[i];

			hours[i] = validateHours(hours[i]);

			cout << "Enter hourly pay rate: ";
			cin >> rate[i];

			rate[i] = validateRate(rate[i]);

			overtime = getOvertimeStatus(hours[i]);


			if (overtime)
			{
				overtimeHours[i] = getOvertimeHours(hours[i]);
				regularHours[i] = getRegularHours(hours[i], overtimeHours[i]);
				regularPay[i] = regularHours[i] * rate[i];
				overtimeRate[i] = rate[i] * OTMULTIPLIER;
				overtimePay[i] = overtimeHours[i] * overtimeRate[i];
				grossPay[i] = regularPay[i] + overtimePay[i];
			}
			else
			{
				overtime = false;
				regularPay[i] = grossPay[i] = hours[i] * rate[i];
			}
			break;

		case salaryEmployee:
			isHourlyEmployee[i] = false;
			overtime = false;

			cout << "Enter gross salary: ";
			cin >> salary;

			salary = validateSalary(salary);
			regularPay[i] = grossPay[i] = salary / 26;
			break;

		default: cout << "bad input";
		}
		//end switch

		fedIncomeTax[i] = getfIT(grossPay[i], FITTAXRATE);
		ficaSSN[i] = getficasSSN(grossPay[i], SSTAXRATE);
		ficaMED[i] = getficaMED(grossPay[i], MEDICARETAXRATE);
		netPay[i] = getNetPay(grossPay[i], fedIncomeTax[i], ficaSSN[i], ficaMED[i]);

	}
	// end of employee loop


	printPayroll(isHourlyEmployee, name, hours, overtimeHours,
		rate, overtimeRate, regularPay, overtimePay, grossPay, ficaSSN, ficaMED, fedIncomeTax, netPay);

	system("pause");
	return 0;
}
