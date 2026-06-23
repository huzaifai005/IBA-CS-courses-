#include<iostream>
#include<string>
#include<fstream>

class logger {
    public: 
    void log(std::string message) {
        std::cout << message << std::endl;
    }

    void log(std::string message, int level) {
        std::cout << "Level: " << level << " " <<  message << std::endl; 
    }

    void log(std::string message, std::string filename) {
         std::ofstream file;
        file.open(filename, std::ios::app);
        if (!file)
        std::cout << "No such file found";
        else {
        file << message;
        std::cout << "Data appended successfully\n";
        file.close();
    }
    }


};

int main () {
    logger l1;
    l1.log("Information message");

    l1.log("Critical error", 5);

    l1.log("something wentr wrong", "cats.txt");
}