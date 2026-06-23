#include <iostream>
int main (){
    int x, y;
    std::cin >> x >> y;

    if (x==1||x==3||x==5||x==7||x==8||x==10||x==12) {
        std::cout << "31 days";
    }
    else if (x==4||x==6||x==9||x==11) {
        std::cout << "30 days";
    }
    else if (x==2) {
        if(y%4==0){
            std::cout << "29 days";
        }
        else {
            std::cout << "28 days";
        }
    }
}
