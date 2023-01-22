#include<iostream>
using namespace std;

class Patterns{
public:
    void makeSquare(string character, int number) {
        if(number <= 0) {
            printNotFeasible();
            return;
        }
        for(int row = 0 ; row < number ; row ++) {
            for(int column = 0 ; column < number ; column ++) {
                cout<<character<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n"<<"\n";
        return;
    }

    void makeEquilateralTriangle(string character, int base) {
        
        if(base <= 0) {
            printNotFeasible();
            return;
        }

        if(base < 3) {
            cout<<"Min base should be 3"<<"\n";
            return;
        }

        if(base%2 == 0) { 
            cout<<"with even numbers it will make a pleatue, try using odd numbers, but for now your pleatue is : \n \n";
        }


        for(int row = base/2 ; row < base ; row++) {
            for(int col = 0 ; col < base ; col ++) {
                if( row >= base/2 && row + col >= base-1 && col <= row){
                    cout<<character<<" ";
                }else {
                    cout<<"  ";
                }
            }
            cout<<"\n";
        }
        cout<<"\n"<<"\n";
        return;
    }

    void makeLeftSidedRightTriangle(string character, int base) {
        
        if(base <= 0) {
            printNotFeasible();
            return;
        }

        for(int row = 1 ; row <= base ; row ++) {
            for(int col = 1 ; col <= row ; col ++) {
                cout<<character<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n"<<"\n";
        return;
    }

    void makeRightSidedRightTriangle(string character, int base) {
        
        if(base <= 0) {
            printNotFeasible();
            return;
        }

        for(int row = 0 ; row < base ; row ++) {
            for(int col = 0 ; col < base ; col ++) {
                if(row + col >= base-1) {
                    cout<<character<<" ";
                }else {
                    cout<<"  ";
                }
            }
            cout<<"\n";
        }
        cout<<"\n"<<"\n";
        return;
    }



    void printNotFeasible() {
        cout<<"This is not feasible with the parameters you passed "<<"\n";
        return;
    }


};