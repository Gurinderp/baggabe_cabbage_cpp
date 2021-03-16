#include <iomanip>
#include <iostream>

void input(std::string& first_name, std::string& last_name, 
    float& hours_worked, double& pay_rate);
void gross_processing(double& gross_pay, float hours_worked, double pay_rate);
void tax_processing(double& taxes, double gross_pay);
void net_processing(double& net_pay, double tax_amount, double gross_pay);
void output_header();
void output(std::string first_name, std::string last_name, float hours_worked, 
    double pay_rate, double gross_pay, double parking, double tax_amount, double net_pay);

int main()
{
    std::string first_name, last_name;
    float hours_worked;
    double pay_rate, gross_pay, tax_amount, net_pay;
    double parking = 7.50;

    input(first_name, last_name, hours_worked, pay_rate);
    gross_processing(gross_pay, hours_worked, pay_rate);
    tax_processing(tax_amount, gross_pay);
    net_processing(net_pay, tax_amount, gross_pay);
    output_header();
    output(first_name, last_name, hours_worked, pay_rate, gross_pay, parking);
}

void input(std::string& first_name, std::string& last_name, 
    float& hours_worked, double& pay_rate)
{
    std::cout << "Enter employee's first name: ";
    std::cin >> first_name;
    std::cout << "Enter employee's last name: ";
    std::cin >> last_name;
    std::cout << "Enter number of hours worked: ";
    std::cin >> hours_worked;
    std::cout << "Enter hourly pay rate: ";
    std::cin >> pay_rate;
}

void gross_processing(double& gross_pay, float hours_worked, double pay_rate)
{
    gross_pay = hours_worked * pay_rate;
}

void tax_processing(double& tax_amount, double gross_pay)
{
    tax_amount = gross_pay * 0.28;
}

void net_processing(double& net_pay, double tax_amount, double gross_pay)
{
    net_pay = gross_pay - tax_amount;
}

void output_header()
{
    std::cout << std::endl;
    std::cout << "12345678901234567890##21.00##321.00##4321.00##321.00##321.00##4321.00"
        << std::endl;
    std::cout << "                             Hourly  Gross                    Net    "
        << std::endl;
    std::cout << "Name                  Hours  Rate    Pay      Taxes   Deduct  Pay    "
        << std::endl;
    std::cout << "====================  =====  ======  =======  ======  ======  ======="
        << std::endl;
}

void output(std::string first_name, std::string last_name, float hours_worked, 
    double pay_rate, double gross_pay, double parking, double tax_amount, double net_pay)
{
    std::cout << first_name << ", " << last_name
        << std::setw(19) << hours_worked << "  "
        << std::setw(6) << pay_rate << "  "
        << std::setw(7) << gross_pay << "  "
        << std::setw(6) << parking << "  "
        << std::setw(6) << parking << "  "
        << std::setw(7) << parking;
}