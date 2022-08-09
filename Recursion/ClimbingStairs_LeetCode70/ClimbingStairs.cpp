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

 int climbStairs2(int n) {
        int prev = 1;
        int present = 1;
        int next = 0;
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        
        for(int stair = 2; stair <= n ; stair++){
            next = prev+present;
            prev = present;
            present=next;
        }
        return next;
    }

int main(){

    int n;
    cout<<"Number of stairs? ";
    cin >> n;

    int number_of_ways2 = climbStairs2(n);
    cout << "number of ways to climb stairs effective: " << number_of_ways2;
    
    cout<<endl;
    
    int number_of_ways = climbStairs(n);
    cout << "number of ways to climb stairs: " << number_of_ways<<endl;

    return 0;
}