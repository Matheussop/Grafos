#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    char nome[100] = "";
    double ganha = 0, vendas=0;
    cin >> nome ; cin >> ganha ; cin >> vendas; 
    double bonus = (0.15*vendas);
    cout << fixed << setprecision(2) << "TOTAL = R$ "<< (ganha+bonus) << endl;
    return 0;
}