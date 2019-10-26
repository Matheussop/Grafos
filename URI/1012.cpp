#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){

    double a = 0 , b = 0 , c = 0 , aTriangulo = 0 , aCirculo = 0, aTrapezio = 0, aQuadrado = 0, aRetangulo = 0, pi = 3.14159; 
    cin >> a; cin >> b ; cin >> c;
    aTriangulo = (a*c)/2; 
    aCirculo =  (pi *(pow(c,2.0)));
    aTrapezio = ((a+b)*c)/2;
    aQuadrado = b*b;
    aRetangulo = a*b;
    
    cout << fixed << setprecision(3) << "TRIANGULO: "<< aTriangulo << endl;
    cout << "CIRCULO: " << aCirculo << endl;
    cout << "TRAPEZIO: " << aTrapezio << endl;
    cout << "QUADRADO: " << aQuadrado << endl;
    cout << "RETANGULO: " << aRetangulo << endl;

}