#ifndef _PAYROLL_H
#define _PAYROLL_H
#include <string> //needed for (parameter data type: string) for printPayroll
using namespace std;

int validateMenuChoice(int menuChoice);
bool getOvertimeStatus(int hours);
int validateHours(int hours);
double validateRate(double rate);
int getOvertimeHours(int hours);
int getRegularHours(int hours, int overtimeHours);
double validateSalary(double salary);

double getfIT(double gross, double FITTAXRATE);
double getficasSSN(double grossPay, double SSTAXRATE);
double getficaMED(double grossPay, double MEDICARETAXRATE);
double getNetPay(double grossPay, double fedIncomeTax, double ficaSSN, double ficaMED);

void printPayroll(bool isHourlyEmployee[], string name[], int hours[], int overtimeHours[],
	double rate[], double overtimeRate[], double regularPay[],
	double overtimePay[], double grossPay[], double ficaSSN[], double ficaMED[], double fedIncomeTax[], double netPay[]);

#endif // PAYROLL_H_INCLUDED


