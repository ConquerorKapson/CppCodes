#include<iostream>
#include"Patterns.h"
using namespace std;

int main() {
    Patterns patterns;
    patterns.makeSquare("*", 1);
    patterns.makeEquilateralTriangle("A", 6);
    patterns.makeLeftSidedRightTriangle("B", 1);
    patterns.makeRightSidedRightTriangle("C", 1);
    return 0;
}