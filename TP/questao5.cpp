#include <iostream>
using namespace std;

    //Variaveis globais//
    int matrizadj[10000][10000]; //Alocando a matriz com tamanho 100 100
    int componetes = 0;      
    int visitados[10000]; //Vetor usado para ver qual vertice ja foi
    int vCor[10000];
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
    bool dfs(int v);//Faz dfs apartir de um vertiice
    void dfsvisit(int v); // Olhar os vizinhos de v
    void mostrarMatriz(); //Printa a matriz na tela , apenas para debugar o codigo .
    void zerarMatriz(); //Coloca 0 em toda a matriz
    void colocaCor(int j , int cor);
    bool inserirNovasArestas(int qArestas);
    //-----------------//
};

Grafo::Grafo(int v){
    this->V = v;
    vCor[V];
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
    int matrizadj[v][v];
    int visitados[V];

}
void Grafo::colocaCor(int v,int cor){
    vCor[v] = cor;
}
void Grafo::conexao(int v1,int v2){
    matrizadj[v1][v2] = 1;
    matrizadj[v2][v1] = 1;
}
void iniciarVetor(int vetor[], int n){
       for(int i = 0;i < n ;i++){
        vetor[i] = 0; 
    } 
}
bool Grafo::dfs(int v){
    bool resp = false;
    iniciarVetor(visitados,V);
    componetes = 0;
    for(int i  = 0 ; i < V ; i++){
        if(visitados[i] == 0){
            dfsvisit(i);
            componetes = componetes + 1;
        }
    }
    if(componetes == 1){
        resp = true;
    }
    return resp;
}

void Grafo::dfsvisit(int v){
    visitados[v] = 1; // 1 representa a cor cinza
    for(int i = 0; i < V ; i++){
        if(matrizadj[v][i] && visitados[i] == 0 ){
            dfsvisit(i);
        }
    }
    visitados[v] = 2; // 2 representa a cor preta
}

bool Grafo::inserirNovasArestas(int qArestas){
    bool resp = false;
    for(int i = 0; i < V ; i++){
        for(int j = 0; j < V;j++){
            if(vCor[i] != vCor[j] && matrizadj[i][j] != 1){ //confere se as cores sao iguais e se ja existe aresta entre os dois vertices
                qArestas--;
                conexao(i,j); // caso seja possivel fazer a ligacao entre as arestas
                if(qArestas == 0){ // ja inseriu todas as arestas p , n ah mais oq inserir sair da repeticao
                    i = j = V;
                }
            }
        }
    }
    if(qArestas == 0){ //caso todas as arestas fossem inseridas corretamente
        resp = true; 
    }
    return resp;
}

int main(){
    int qCasos = 0; 
    cin >> qCasos;

    for(int i = 0;i < qCasos ; i++){

        int qVertices = 0, qArestas = 0, qCores = 0, qInserir = 0;
        cin >> qVertices; cin >> qArestas; cin >> qInserir; cin >> qCores;
        Grafo grafo(qVertices);
        for(int j = 0; j < qVertices ; j++){
            int cor = 0; 
            cin >> cor;
            grafo.colocaCor(j,cor); //grava a cor de cada vertice em um vetor
        }
        for(int j = 0; j < qArestas ; j++){
            int v1 = 0 , v2 = 0;
            cin >> v1; cin >> v2;
            grafo.conexao((v1-1),(v2-1)); //inseri as arestas no grafo
        }
        bool resp = false;

        resp = grafo.inserirNovasArestas(qInserir); //verifica se é possivel inserir as p arestas no grafo
        if(resp){
            resp = grafo.dfs(0); //chamando busca em profundidade para verificar se o grafo é conexo 
        }

        grafo.zerarMatriz(); //Zerando a matriz para o proximo grafo
        printf("%s\n", resp ? "Y" : "N"); //Imprimindo se é possivel ou n 
    }

    return 0;
}
