#include <iostream>

void input(std::string& first_name, std::string& last_name, float& hours_worked, double& pay_rate);

int main()
{
    std::string first_name, last_name;
    float hours_worked;
    double pay_rate;

    input(first_name, last_name, hours_worked, pay_rate);
}

void input(std::string& first_name, std::string& last_name, float& hours_worked, double& pay_rate)
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