#include <iostream>  
#include <string>

#include "../headers/passwordValidator.hpp"

User::User(string p) :password(p) {} 

bool passwordValidator::containsNumbers (string s){
    for(char c: s) {
         if (isdigit(c)) return true;
        }
        return false;
    }

    bool passwordValidator::containsUpperCaseLetter (string s){
    for(char c: s) {
         if (isupper(c)) return true;
        }
        return false;
    }

     bool passwordValidator::containsLowerCaseLetter (string s){
    for(char c: s) {
         if (islower(c)) return true;
        }
        return false;
    }

    bool hasValidPassword(User& user) {
        string p = user.password;
    if (p.length() >= 10 && containsNumbers(p) && containsUpperCaseLetter(p) && containsLowerCaseLetter(p)) {
        return true;
    }
    else return false;

    }

