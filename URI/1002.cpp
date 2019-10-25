#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){
    double  x = 0 , y = 3.14159;
    cin >> x ; 
    double media = pow(x,2);
    cout << fixed << setprecision(4) << "A=" << y*media << endl;
    //printf("A=%.4f",y*media);   
    return 0;
}