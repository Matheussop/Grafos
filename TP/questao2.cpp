#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
# define MAIOR __DBL_MAX__
    //Variaveis globais//
    double matrizadj[100][100];
    int componetes = 0;
    double distanciax[100];
    double distanciay[100];
    //-----------------//

class Grafo{
    public:
    //Variaveis da classe//
    int V; // numero de vertices do grafo 
    //-------------------//

    //Contrutores da classe//
    Grafo(){
        this->V = 1;
    }
    Grafo(int v);
    //--------------------//

    //Metodos da classe//
    void criarMatriz(int v); //criar a matriz 
    void mostrarMatriz(); //Printa a matriz na tela , apenas para debugar o codigo .
    void zerarMatriz(); //Coloca 0 em toda a matriz
    void InfMatriz();
    void menorDis();
    void calcularResp(double *x);
    //-----------------//
};

Grafo::Grafo(int v){
    this->V = v;
    criarMatriz(v);
}

void Grafo::zerarMatriz(){
    for(int i=0;i < V;i++){
        for(int j = 0;j < V;j++){
            matrizadj[i][j] = 0;
        }
    }
}

void Grafo::mostrarMatriz(){
    for(int i=0;i < V;i++){
        for(int j = 0;j < V;j++){
            cout << matrizadj[i][j] << " | " ;
        }
        cout << endl;
    }
}

void Grafo::criarMatriz(int v){
    double matrizadj[v][v];
    int visitados[V];
    int pi[V];
}

void conexao(int v1,int v2,double x){
    if(v1 != v2){
        matrizadj[v1][v2] = x;
        matrizadj[v2][v1] = x;
    }else {
        matrizadj[v1][v2] = MAIOR; // Caso o vertice que eu estou fizer ligação com ele msm , minha distancia sera infinita
    }
}

void iniciarVetor(double vetor[], int n){
       for(int i = 0;i < n ;i++){
        vetor[i] = 0; //Iniciar todos os elementos do meu vetor com 0
    } 
}

void pitagoras(double* distanciax,double* distaciay,int n){
    double x;
    int valor1 , valor2;
    for(int j = 0; j < n; j++){
        for(int i = 0;i < n ; i++){
            x = 0;
            valor1 = distanciax[i] - distanciax[j]; // A diferença do X1 e X0
            valor2 = distanciay[i] - distanciay[j]; // A diferença do Y1 e Y0
            x = sqrt((pow(valor1,2))+(pow(valor2,2))); // Elevar os dois valores ao quadrado e tirar a raiz do seu somatorio
            conexao(j,i,x); //Criar um aresta com o valor de x como distancia
        }
    }
}
/*------------------------
* O seguinte metodo ira conferir o melhor caminho de um vertice para o outro,
* e colocar em um vetor os valores da distancia.
* O vetor sera passado para outro metodo chamado calcularResp
**/
void Grafo::menorDis(){ 
    double chave[V-1] ;
    for(int i=0;i < V-1;i++){
        chave[i] = MAIOR;
    }
    int visitados[V] ;
    int i  = 0 ,j ,l = 0, x = 0;
    while(i != (V-1)){
        for(j = 0; j < V ; j++){
           if(matrizadj[l][j] < chave[i] && visitados[j] != 1){ 
               chave[i] = matrizadj[l][j];  //Colocar no vetor se o valor for menor que o corrente
               x = j;
            }
        }
        visitados[l] = 1; // Colocar ele como visitado
        l = x;  //Ir para o proximo vertice
        i++;
    }
    calcularResp(chave); //Chamar o vertice para calcular a soma total das distancias
}   
void Grafo::calcularResp(double *x){ //Calcula a distancia total
    double resp = 0.0;
    for(int i = 0; i < V ; i++){
      resp += x[i]; 
    }
    cout << fixed << setprecision(2) << resp/100 << endl << endl;
}
int main(){
    int repeticao = 0;
    double qVertices = 0;
    cin >> repeticao ;
    for(int j = 0 ; j < repeticao; j++){
        cin >> qVertices;
        Grafo  grafo(qVertices) ;
        for(int i = 0 ; i < qVertices ; i++){
            double d = 0;
            cin >> distanciax[i];
            cin >> distanciay[i];
        }
        pitagoras(distanciax,distanciay,qVertices);
        //grafo.mostrarMatriz();
        grafo.menorDis();
        grafo.zerarMatriz();
    }
    return 0;
}