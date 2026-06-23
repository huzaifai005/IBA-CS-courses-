#include <iostream> 

int main()
{
	
int farenheit;
std::cout << "Enter temperature in farenheit: ";
std::cin >> farenheit;

int celcius;
celcius = (farenheit - 32.0) * 5.0/9.0;
std::cout << "temperature in celcius is: ";
std::cout << celcius;
}