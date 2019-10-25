#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int c1 = 0, c2 = 0, q1 = 0, q2 =0; 
    double preco1 = 0, preco2 = 0;
    cin >> c1 ; cin >> q1 ; cin >> preco1; 
    cin >> c2 ; cin >> q2 ; cin >> preco2; 
    double total = ((q1 * preco1) + (q2 * preco2));
    cout << fixed << setprecision(2) << "VALOR A PAGAR: R$ "<< total << endl;
    return 0;
}