#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
# define MAIOR __DBL_MAX__
    //Variaveis globais//
    int matrizadj[10000][10000];
    int matrizR[10000][10000];
    int componetes = 0;
    int visitados[100000];
    int pi[100000];
    queue<int> fila;
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
    void conexao(int v1,int v2); //Criar uma conexao entre os dois vertices (aresta)
    void InfMatriz();
    void Clargura();//Metodo que chama o busca em largura em profundida
    void largura(int s); //Metodo de busca em largura
    void mostrarMatriz(); //Printa a matriz na tela , apenas para debugar o codigo .
    void zerarMatriz(); //Coloca 0 em toda a matriz
    void mostrarMatrizR();
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
            matrizR[i][j] = 0;
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

void Grafo::mostrarMatrizR(){
    for(int i=0;i < V;i++){
        for(int j = 0;j < V;j++){
            cout << matrizR[i][j] << " | " ;
        }
        cout << endl;
    }
}

void Grafo::criarMatriz(int v){
    int matrizadj[v][v];
    int matrizT[v][v];
    int visitados[V];
    int pi[V];
}

void Grafo::conexao(int v1,int v2){
    matrizadj[v1][v2] = 1;
}

void iniciarVetor(int vetor[], int n){
    for(int i = 0;i < n ;i++){
        vetor[i] = 0; //Iniciar todos os elementos do meu vetor com 0
    } 
}
/***************************************************
 * O metodo a seguir ira chamar o metodo de busca em largura
 *  passando todos os vertices do grafo
 */
void Grafo::Clargura(){
    for(int i=0; i < V;i++){ //for para percorrer todo o grafo
        largura(i); //chamada do metodo que realiza busca em largura
    }
}//fim do metodo Clargura
void Grafo::largura(int s){
    for(int i = 0;i < V ;i++){
        iniciarVetor(visitados,V); //inicializa o vetor de visitados com tudo 0
    }
    visitados[s] = 1; //marcar o vertice como cinza 
    fila.empty(); // criar a lista
    fila.push(s); // inserir na lista o vertice s 
    while(fila.size() != 0){
        int j ;
        j = fila.front(); // pega o primeiro valor da lista e coloca em j 
        fila.pop(); // remover o primeiro valor da lista
        for(int i = 0 ; i < V; i++){
            if(matrizadj[j][i] && visitados[i] == 0){ // verifica se  
                visitados[i] = 1; //marcar o vertice como cinza
                matrizR[s][i] = 1; // colocar na Matriz Resposta que o vertice "s" e o vertice "i" tem caminhos entre eles;
                matrizR[i][s] = 1;// colocar na Matriz Resposta que o vertice "i" e o vertice "s" tem caminhos entre eles; 
                fila.push(i); //inserir o vertice i na lista , (vertices adjacentes a j)
            }
        } 
        visitados[j] = 2; //marcar o vertice como preto
    }
}

/**************************************************************
 * O metodo resp ira conferir se na Matriz Resposta eu irei ter dois 
 * vertices que nao possuem um caminho entre se . 
 * 
 *************************************************************/
bool resp(int v){
    bool resp = true; 
    for(int i = 0; i < v ; i++){ 
        for(int j = 0; j < v ; j++){ 
            if(i != j && matrizR[i][j] == 0){ //em quanto não houver algum zero e não se a diagonal(pois a diagonal indica a distancia de um vertice para ele msm , ou seja 0)
                resp = false; //Caso encontre algum zero , o grafo nao é bolado
            }
        }
    }
    return resp;
}

int main(){
    int repeticao = 0, qVertices = 0,qArestas = 0;
        cin >> qVertices ; //ler a quantida de vertices
        cin >> qArestas ; //ler a quantida de arestas
        Grafo  grafo(qVertices) ; // criar um grafo com a quantidade de vertices desejados
        for(int j = 0 ; j < qArestas; j++){ // for para inserir as arestas no grafo
            int v1 = 0, v2 = 0;
            cin >> v1; cin >> v2;
            grafo.conexao(v1-1,v2-1);
        }
        grafo.Clargura(); //Chamar o vertice que fara a busca em largura no grafo.
        //grafo.mostrarMatriz();
        //grafo.mostrarMatrizR();
        printf("%sBolada\n", resp(qVertices) ? "" : "Nao ");
    return 0;
}