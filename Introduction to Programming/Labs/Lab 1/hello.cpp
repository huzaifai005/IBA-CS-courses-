#include <iostream>
#include <string>

int main()
{
	std::string name;
	std::cin >> name;
	
	int age;
	std::cin >> age;
	
	std::cout << "Hello "<< name <<", you are " << age <<" years old";
}