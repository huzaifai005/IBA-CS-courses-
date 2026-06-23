#include<iostream>
#include<vector>
int average(const std::vector<int>& a, int start, int end) {
    int sum = 0;
    int ave;
    for(int i = start; i <= end; i++) {
        sum = sum + a[i];
    } 
    ave = sum/(end-start+1);
    return ave;
    }

int halfaverage(const std::vector<int> a) {
    int mid = a.size()/2;
    int firsthalfaverage = average(a, 0, mid-1);
    int secondhalfaverage = average (a, mid-1,a.size()-1);
    int finalaverage = std::max (firsthalfaverage, secondhalfaverage);
    return finalaverage;
}

int main() {
    const std::vector<int> v1 = {4, 4, 4, 2, 2, 2};
    const std::vector<int> v2 = {3, 4, 5, 1, 2, 3};
    std::cout << halfaverage(v1);
}