#include <iomanip>
#include <iostream>

#define PARKING  7.50
#define TAX_RATE 0.28
#define MIN_PAY 7.25
#define MAX_PAY 44.99
#define MIN_HOURS 20
#define MAX_HOURS 60
#define MAX_REGULAR 40
#define OVERTIME_RATE 1.5


void input(std::string& first_name, std::string& last_name, 
    float& hours_worked, float& pay_rate);
void overtimeHours(float hours_worked, float& normal_hours, 
    float& overtime_hours);
void gross_processing(float& gross_pay, float normal_hours, 
    float overtime_hours, float pay_rate);
void tax_processing(float& tax_amount, float gross_pay);
void net_processing(float& net_pay, float tax_amount, float gross_pay);
void joinName(std::string first_name, std::string last_name, 
    std::string& full_name);
void output_header();
void output(std::string full_name, float normal_hours, 
    float overtime_hours, float pay_rate, float gross_pay, float tax_amount,
    float net_pay, std::string& process_another);

int main()
{

    std::string first_name, last_name, full_name, process_another;
    float hours_worked, normal_hours, overtime_hours,
        pay_rate, gross_pay, tax_amount, net_pay;
    do {
    input(first_name, last_name, hours_worked, pay_rate);
    overtimeHours(hours_worked, normal_hours, overtime_hours);
    gross_processing(gross_pay, normal_hours, overtime_hours, pay_rate);
    tax_processing(tax_amount, gross_pay);
    net_processing(net_pay, tax_amount, gross_pay);
    joinName(first_name, last_name, full_name);
    output_header();
    output(full_name, normal_hours, overtime_hours, pay_rate, 
        gross_pay, tax_amount, net_pay, process_another);
    } while ((process_another == "y") || (process_another == "Y"));
}

void input(std::string& first_name, std::string& last_name, 
    float& hours_worked, float& pay_rate)
{
    std::cout << "Enter employee's first name: ";
    std::cin >> first_name;
    std::cout << "Enter employee's last name: ";
    std::cin >> last_name;

    do
    {
        std::cout << "Enter number of hours worked: ";
        std::cin >> hours_worked;
        if ((hours_worked < MIN_HOURS) || (hours_worked > MAX_HOURS)) 
        {
            std::cout << "Error: Invalid Entry" << std::endl;
        }
    } while ((hours_worked < MIN_HOURS) || (hours_worked > MAX_HOURS));

    do 
    {
        std::cout << "Enter hourly pay rate: ";
        std::cin >> pay_rate;
        if ((pay_rate < MIN_PAY) || (pay_rate > MAX_PAY))
        {
            std::cout << "Error: Invalid Entry" << std::endl;
        }
    } while ((pay_rate < MIN_PAY) || (pay_rate > MAX_PAY));
}

void overtimeHours(float hours_worked, float& normal_hours,
    float& overtime_hours)
{
    overtime_hours = 0;
    normal_hours = hours_worked;
    if (hours_worked > MAX_REGULAR)
    {
        overtime_hours = hours_worked - MAX_REGULAR;
        normal_hours = MAX_REGULAR;
    };
}

void gross_processing(float& gross_pay, float normal_hours, 
    float overtime_hours, float pay_rate)
{
    gross_pay = (normal_hours * pay_rate) + (overtime_hours * (pay_rate * OVERTIME_RATE));
}

void tax_processing(float& tax_amount, float gross_pay)
{
    tax_amount = gross_pay * TAX_RATE;
}

void net_processing(float& net_pay, float tax_amount, float gross_pay)
{
    net_pay = gross_pay - tax_amount - PARKING;
}

void joinName(std::string first_name, std::string last_name, 
    std::string& full_name)
{
    full_name = last_name + ", " + first_name;
}

void output_header()
{
    std::cout << std::endl;
    std::cout << "                      Reg    Ovt    Hourly  Gross                    Net  "
        << std::endl;
    std::cout << "Name                  Hours  Hours  Rate    Pay      Taxes   Deduct  Pay  "
        << std::endl;
    std::cout << "====================  =====  =====  ======  =======  ======  ======  ======="
        << std::endl;
}


void output(std::string full_name, float normal_hours,
    float overtime_hours, float pay_rate, float gross_pay, float tax_amount, 
    float net_pay, std::string& process_another)
{
    std::cout << std::setw(20) << full_name << "  "
        << std::setw(5) << std::setprecision(2) << std::fixed 
        << normal_hours << "  "
        << std::setw(5) << std::setprecision(2) << std::fixed 
        << overtime_hours << "  "
        << std::setw(6) << std::setprecision(2) << std::fixed 
        << pay_rate << "  "
        << std::setw(7) << std::setprecision(2) << std::fixed 
        << gross_pay << "  "
        << std::setw(6) << std::setprecision(2) << std::fixed 
        << tax_amount << "  "
        << std::setw(6) << std::setprecision(2) << std::fixed 
        << PARKING << "  "
        << std::setw(7) << std::setprecision(2) << std::fixed 
        << net_pay
        << "\nProcess another employee (Y/N)?";
    std::cin >> process_another;
}