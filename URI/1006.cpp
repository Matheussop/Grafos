#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double  a = 0 , b = 0 , c = 0 ;
    cin >> a ; cin >> b ; cin >> c;
    double media = (((a*2)+(b*3)+(c*5))/10);
    cout << fixed << setprecision(1) << "MEDIA = " << media << endl;
    return 0;
}