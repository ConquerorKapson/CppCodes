#include <iostream>
using namespace std;

int climbStairs(int n){
    if(n == 0){
        return 1;
    }

    if(n < 0){
        return 0;
    }

    return climbStairs(n-1)+climbStairs(n-2);    
}

int main(){

    int n;
    cout<<"Number of stairs? ";
    cin >> n;

    int number_of_ways = climbStairs(n);
    cout << "number of ways to climb stairs: " << number_of_ways;

    return 0;
}