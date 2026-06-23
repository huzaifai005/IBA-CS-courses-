    //Huzaifa Iqbal 31563
#include <iostream>
#include <cmath>
int main () {
    int n;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
    int j;
    int k;
    int l;
    int m;
    int o;
    int p;
    int q;
    int r;
    std::cout << "Enter a number: ";
    std::cin >> n;
    if (n<-999999||n>999999) {
        std::cout << "Invalid input";
    }
    else {
     if (n<0) {
        std::cout << "negative";
        n = -1 * n;
    }
    b = n/10000;
    c = b%10;
    d = n/1000;
    if (d<20&&d>=10||d<120&&d>=110||d<220&&d>=210||d<320&&d>=
    310||d<420&&d>=410||d<520&&d>=510||d<620&&d>=610||d<720&&d>=710||d<820&&d>=810||d<920&&d>=910) {
    e = d%20;
    }
    f = d%10;
    g = n/100;
    h = g%10;
    i = n/10;
    j = i%10;
    m = n%100;
    k = n%10;
    l = n/100;
    o = n/10;
    p = o%10;
    q = n%10;
    r = n%100;
    if (n==0) {
        std::cout << "zero";
    }
    if (n>999) {
    if (n/100000==1||2||3||4||5||6||7||8||9) {
        int a;
        a = n/100000;
        switch (a) {
            case 1:
            std::cout << " one hundred";
            break;
            case 2:
            std::cout << " two hundred";
            break;
            case 3:
            std::cout << " three hundred";
            break;
            case 4:
            std::cout << " four hundred";
            break;
            case 5:
            std::cout << " five hundred";
            break;
            case 6:
            std::cout << " six hundred";
            break;
            case 7:
            std::cout << " seven hundred";
            break;
            case 8:
            std::cout << " eight hundred";
            break;
            case 9:
            std::cout << " nine hundred";
            break;
        }
    }
    
            switch (c) {
            case 2:
            std::cout << " twenty";
            break;
            case 3:
            std::cout << " thirty";
            break;
            case 4:
            std::cout << " forty";
            break;
            case 5:
            std::cout << " fifty";
            break;
            case 6:
            std::cout << " sixty";
            break;
            case 7:
            std::cout << " seventy";
            break;
            case 8:
            std::cout << " eighty";
            break;
            case 9:
            std::cout << " ninety";
            break;
        }
        if (d<20&&d>=10||d<120&&d>=110||d<220&&d>=210||d<320&&d>=
310||d<420&&d>=410||d<520&&d>=510||d<620&&d>=610||d<720&&d>=710||d<820&&d>=810||d<920&&d>=910) {
            switch (e) {
            case 10:
            std::cout << " ten";
            break;
            case 11:
            std::cout << " eleven";
            break;
            case 12:
            std::cout << " twelve";
            break;
            case 13:
            std::cout << " thirteen";
            break;
            case 14:
            std::cout << " fourteen";
            break;
            case 15:
            std::cout << " fifteen";
            break;
            case 16:
            std::cout << " sixteen";
            break;
            case 17:
            std::cout << " seventeen";
            break;
            case 18:
            std::cout << " eighteen";
            break;
            case 19:
            std::cout << " nineteen";
            break;
            
        }
}
        else {
            switch (f) {
            case 1:
            std::cout << " one";
            break;
            case 2:
            std::cout << " two";
            break;
            case 3:
            std::cout << " three";
            break;
            case 4:
            std::cout << " four";
            break;
            case 5:
            std::cout << " five";
            break;
            case 6:
            std::cout << " six";
            break;
            case 7:
            std::cout << " seven";
            break;
            case 8:
            std::cout << " eight";
            break;
            case 9:
            std::cout << " nine";
            break;
        }
        }
    std::cout << " thousand";
         switch (h) {
            case 1:
            std::cout << " one hundred";
            break;
            case 2:
            std::cout << " two hundred";
            break;
            case 3:
            std::cout << " three hundred";
            break;
            case 4:
            std::cout << " four hundred";
            break;
            case 5:
            std::cout << " five hundred";
            break;
            case 6:
            std::cout << " six hundred";
            break;
            case 7:
            std::cout << " seven hundred";
            break;
            case 8:
            std::cout << " eight hundred";
            break;
            case 9:
            std::cout << " nine hundred";
            break;
         }
        switch (j) {
            case 2:
            std::cout << " twenty";
            break;
            case 3:
            std::cout << " thirty";
            break;
            case 4:
            std::cout << " forty";
            break;
            case 5:
            std::cout << " fifty";
            break;
            case 6:
            std::cout << " sixty";
            break;
            case 7:
            std::cout << " seventy";
            break;
            case 8:
            std::cout << " eighty";
            break;
            case 9:
            std::cout << " ninety";
            break;
           }
           if (m<10||m>19) {
          switch (k) {
            case 1:
            std::cout << " one";
            break;
            case 2:
            std::cout << " two";
            break;
            case 3:
            std::cout << " three";
            break;
            case 4:
            std::cout << " four";
            break;
            case 5:
            std::cout << " five";
            break;
            case 6:
            std::cout << " six";
            break;
            case 7:
            std::cout << " seven";
            break;
            case 8:
            std::cout << " eight";
            break;
            case 9:
            std::cout << " nine";
            break;
        }
         }
             else if (m==10||11||12||13||14||15||16||17||18||19) {
             switch (m) {
            case 10:
            std::cout << " ten";
            break;
            case 11:
            std::cout << " eleven";
            break;
            case 12:
            std::cout << " twelve";
            break;
            case 13:
            std::cout << " thirteen";
            break;
            case 14:
            std::cout << " fourteen";
            break;
            case 15:
            std::cout << " fifteen";
            break;
            case 16:
            std::cout << " sixteen";
            break;
            case 17:
            std::cout << " seventeen";
            break;
            case 18:
            std::cout << " eighteen";
            break;
            case 19:
            std::cout << " nineteen";
            break;
        }
             }
        }
        else if (n<1000) {
            switch (l) {
                case 1:
            std::cout << " one hundred";
            break;
            case 2:
            std::cout << " two hundred";
            break;
            case 3:
            std::cout << " three hundred";
            break;
            case 4:
            std::cout << " four hundred";
            break;
            case 5:
            std::cout << " five hundred";
            break;
            case 6:
            std::cout << " six hundred";
            break;
            case 7:
            std::cout << " seven hundred";
            break;
            case 8:
            std::cout << " eight hundred";
            break;
            case 9:
            std::cout << " nine hundred";
            break;
            }
            switch (p) {
                case 2:
            std::cout << " twenty";
            break;
            case 3:
            std::cout << " thirty";
            break;
            case 4:
            std::cout << " forty";
            break;
            case 5:
            std::cout << " fifty";
            break;
            case 6:
            std::cout << " sixty";
            break;
            case 7:
            std::cout << " seventy";
            break;
            case 8:
            std::cout << " eighty";
            break;
            case 9:
            std::cout << " ninety";
            break;
            }
            if (r<10||r>19) {
          switch (q) {
            case 1:
            std::cout << " one";
            break;
            case 2:
            std::cout << " two";
            break;
            case 3:
            std::cout << " three";
            break;
            case 4:
            std::cout << " four";
            break;
            case 5:
            std::cout << " five";
            break;
            case 6:
            std::cout << " six";
            break;
            case 7:
            std::cout << " seven";
            break;
            case 8:
            std::cout << " eight";
            break;
            case 9:
            std::cout << " nine";
            break;
        }
         }
             else if (r==10||11||12||13||14||15||16||17||18||19) {
             switch (r) {
            case 10:
            std::cout << " ten";
            break;
            case 11:
            std::cout << " eleven";
            break;
            case 12:
            std::cout << " twelve";
            break;
            case 13:
            std::cout << " thirteen";
            break;
            case 14:
            std::cout << " fourteen";
            break;
            case 15:
            std::cout << " fifteen";
            break;
            case 16:
            std::cout << " sixteen";
            break;
            case 17:
            std::cout << " seventeen";
            break;
            case 18:
            std::cout << " eighteen";
            break;
            case 19:
            std::cout << " nineteen";
            break;
        }
             }
            
        }
          
    }   
            }
    
             