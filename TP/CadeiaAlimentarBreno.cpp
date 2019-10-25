#include <iostream>
using namespace std;
void printMatriz(int** matriz, int n){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }
}
int** criarMatriz(int** matriz, int n, int relacoes){
    int x,y;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            matriz[i][j] = 0;
        }
    }
    for(int i = 0;i<relacoes;i++){
        cin >> x;
        cin >> y;
        matriz[(x-1)][(y-1)] = 1;
    }
    return matriz;
}
int* verificaLigacao(int** matriz, int n, int* arrayCor,int i){
    for(int j =0;j<n;j++){
       // cout<<"I: " << i << " J: "<< j << "\n";
        if(matriz[i][j] == 1){
            if(arrayCor[j] != 0){
                arrayCor[i] = 2;
            }
            else{
                arrayCor[i] = 1;
                arrayCor = verificaLigacao(matriz,n,arrayCor,j);
            }
        }
    }
    return arrayCor;   
}
bool ehBolada(int** matriz, int n){
    int* arrayCor = new int[n];
    for(int i = 0;i<n;i++){
        arrayCor[i] = 0;
    }
    bool Bolada = false;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(matriz[i][j] == 1){
                if(arrayCor[i] == 1){
                    arrayCor[i] = 2;
                    arrayCor = verificaLigacao(matriz,n,arrayCor,j);
                }
                else{
                    arrayCor[i] = 1;
                    arrayCor = verificaLigacao(matriz,n,arrayCor,j);
                }
            }
        }
    }
    int cont = 0;
    int cont2 = 0;
    for(int i = 0;i <n;i++){
        if(arrayCor[i] == 2){
            cont++;
        }
    }
    if(cont >= n-2){
        Bolada = true;
    }
    else{
        Bolada = false;
    }
    return Bolada;
}

int main(){
    int n; 
    int relacoes;
    cin >> n;
    cin >> relacoes;
    bool bolada;
    int** matriz = new int*[n];
    for(int l = 0;l<n;l++){
        matriz[l] = new int[n];
    }
    matriz = criarMatriz(matriz,n,relacoes);
    bolada = ehBolada(matriz,n);
    //printMatriz(matriz,n);
    if(bolada){
        cout << "Bolada" << endl;
    }
    else{
        cout << "Nao Bolada" << endl;
    }
    return 0;
}
