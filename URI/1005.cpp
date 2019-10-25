#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double  x = 0 , y = 0;
    cin >> x ; cin >> y;
    double media = (((x*3.5)+(y*7.5))/11);
    cout << fixed << setprecision(5) << "MEDIA = " << media << endl;
    return 0;
}