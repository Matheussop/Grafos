#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){
    double r = 0, pi = 3.14159;
    cin >> r;
    cout << fixed << setprecision(3) << "VOLUME = " <<((4.0/3)* pi *pow(r,3)) << endl;
}