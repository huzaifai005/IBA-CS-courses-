#include<iostream>
#include<vector>
double percent_even(std::vector<int> v) {
    double count = 0;
    for(int i = 0; i < size(v); i++){
        if(v[i]%2==0) {
            count = count + 1;
        }
    }
    double per = (count / size(v))*100;
    return per;
}
int main() {
    std::vector<int> v1 = {6, 2, 9, 11, 3};
    std::vector<int> v2 = {6, 2, 9, 11, 4};
    std::vector<int> v3 = {1, 3, 5, 7, 9};
    std::cout << "Percentage of even numbers in the array is: " << percent_even(v3);

}