#include <iostream>
#define INFINITO 1000000
using namespace std;
/*
* Programa usando matriz de adjacencias
*/
int cc = 0; 
int pai[100];
class Grafo{
    private:
        int V; //numero de vertices
        int adj[100][100];
        //ponteiro para um vetor contendo as listas de adjacencias
    public:

        //construtor da class Grafos
        Grafo(int v){
            this->V = v;
            adj[v][v]; //matriz de adjacencias
        }

        //Metodo para adicionar uma aresta de um vertice "v1" a um vertice "v2" com um peso
        void addAresta(int v1, int v2 , int peso){
            adj[v1][v2] = peso;
            adj[v2][v1] = peso;
        }

        //Metodo para colocar um vertice no heap
        void montaHeap(int *Q){
            for(int i = 0; i < V ; i++){
                Q[i] = i;
            }
        }
    /*
    * Metodo que ira reistruturar o heap , (balanceamento do heap)
    */
    void reorganizar(int *Q, int n, int valores[]){
        int tmp = 0;
        int menorFilho = 0;
        for(int i=0;i<n/2;i++){ //for para andar no heap
            if((i*2)+1 == n || valores[Q[(i*2)+1]] <= valores[Q[(i*2)+2]]){
                menorFilho = (i*2)+1;
            }else{
                menorFilho = (i*2)+2;
            }
            if(valores[Q[i]] > valores[Q[menorFilho]]){
                tmp = Q[i];
                Q[i] = Q[menorFilho];
                Q[menorFilho] = tmp;
            }
        }// fim do for
    }// fim do meotod reorganizar

    /*
    *  Metodo para pegar o menor valor de um heap
    */
    int menorValor(int *Q, int n){ 
        int menor = Q[0];
        Q[0] = Q[n-1];
        return menor;
    }

    //Remove uma aresta da matriz de adjacencias
    void removerAresta(int v1 , int v2){
        adj[v1][v2] = 0;
        adj[v2][v1] = 0;
    }

    //Metodo para mostrar toda a matriz de adjacencias
    void mostrarMatriz(){
        for(int i=0;i < V;i++){
            for(int j = 0;j < V;j++){
                cout << adj[i][j] << " | " ;
            }
            cout << endl;
        }
    }

    //Algoritmo de Dijkstra 
    int dijkstra(int inicio, int destino){
        
        //vetor de distancias
        int dist[V];
        //vetor de visitados, para verificar se um vertice ja foi visitados
        int *Q = new int[V];
        //for para iniciar os vetores usados
        for (int i = 0; i < V ; i++){
            dist[i] = INFINITO;
            pai[i] = -1;
        }
        //Inserir o elemento no heap
        montaHeap(Q);

        int n = V;
        // iniciar o vetor de distancia .
    
        dist[inicio] = 0; //obs a distancia de um vertice para ele msm , é smp zero


        //Loop do algoritimo 
        for(int i = 0; i < V ; i++){
            int u = menorValor(Q,n); //pegando o vertice
            n--;
            for(int v = 0; v < V ; v++){
                if( dist[v]  > dist[u] + adj[u][v] && adj[u][v] != 0){ //
                    dist[v] = dist[u] +  adj[u][v];
                    pai[v] = u;
                }
            }
            //Reorniza o heap, colocando os valores de acordo com o "peso"
            reorganizar(Q,n,dist);
        }


     /*A proxima estrutura e para percorrer o melhor 
     caminho do heap removendo as arestas, 
     para que o proximo algoritimo ache outro melhor caminho*/   
    int i = V-1;    
    while(pai[i] != -1){
        removerAresta(i,pai[i]);
        i = pai[i];
    }
    if(i != 0){
        //Caso n seja possivel fazer o trajeto
        return -1;
    }
    return dist[destino];
    }//fim do metodo dijkstra
    
};

int main(){

    int qVertices = 0, qArestas = 0, v1 = 0 , v2 = 0, p = 0, i =1;
    while( cin >> qVertices){
        cin >> qArestas;
        Grafo grafo(qVertices);
        for(int i = 0; i < qArestas; i++){
            v1 = 0 ; v2 = 0;
            cin >> v1; cin >> v2; cin >> p;
            grafo.addAresta(v1-1,v2-1,p);
        }
        int grupo = 0 , assentos = 0; 

        cin >> grupo; cin >> assentos;
        int resp = 0;
        int pcaminho = 0;
        cout << "Instancia " << i << endl << endl;
        i++;
        while(grupo > 0 && pcaminho != -1){
            pcaminho = (grafo.dijkstra(0,(qVertices-1))  ); //Chamada do dijktra
            if(pcaminho != -1){
                if(grupo > assentos){ //O tamanho do grupo for maior que o espaco do onibus
                    resp += (pcaminho * assentos); // entao apenas mutiplicar a quantidade de passagens pelo o preco dela (tamanho do caminho minimo)
                }else {
                    resp += (pcaminho *grupo); // entao a quantidade de pessoas que sobrou vezes o o tamanho total do caminho minimo
                }
            }else{
                cout << "impossivel " << endl; //caso seja impossivel colocar todos os amigos nos voo 
                grupo = -1;
            }
        grupo -= assentos;
        }
        if(pcaminho != -1){
            cout << resp << endl; //a resp total  do caminho * preço (soma de todas as passgens)
        }
        cout << endl << endl << endl; //apenas para pular os espaco do verde
    }
    return 0;
}