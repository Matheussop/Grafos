#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double  a = 0 , b = 0 , c = 0 , d = 0;
    cin >> a ; cin >> b ; cin >> c; cin >> d;
    int media = ((a*b) - (c*d));
    cout << fixed << setprecision(1) << "DIFERENCA = " << media << endl;
    return 0;
}