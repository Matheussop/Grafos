#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int number = 0, horas;
    double ganha = 0;
    cin >> number ; cin >> horas ; cin >> ganha; 
    double salario = horas*ganha;
    cout << fixed << setprecision(2) << "NUMBER = "<< number << endl << "SALARY = U$ " << salario << endl;
    return 0;
}