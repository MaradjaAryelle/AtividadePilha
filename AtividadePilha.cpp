#include <iostream>

using namespace std;

struct Cidade{
	int populacao;
	string nome;	
};

struct ElementoPilha{
	Cidade cidade;
	ElementoPilha *next;
};

void exibirLista(ElementoPilha *topo){
    ElementoPilha *p = topo;
    cout << "\n[ ";
    while(p != NULL) {
        cout << p->cidade.nome << " ";
        p = p->next;
    }
    cout << "]";
}

void empilhar(ElementoPilha *&topo, string nome, int populacao){
	ElementoPilha *elemento = new ElementoPilha;
	elemento -> cidade.nome = nome;
	elemento -> cidade.populacao = populacao;
	elemento -> next = topo;
	
	topo = elemento;
}

int acharMeio (ElementoPilha *&topo){
	int tamanho = 0;

	ElementoPilha *aux = new ElementoPilha;
	aux = topo;
	
	while (aux != NULL){
		aux = aux -> next;
		tamanho++; 
	}
	int meio = (tamanho-1)/2;
	return meio;
}

void removerMeio(ElementoPilha *&topo, int meio) {
    ElementoPilha* temporario = topo;
    ElementoPilha* anterior = NULL;
    
    for (int i = 0; i <= meio; i++) {
    	anterior = temporario;
        temporario = temporario -> next;
        }
    anterior->next = temporario->next;
    delete temporario;
    }

int main(int argc, char** argv) {
	int meio;
	ElementoPilha *topo = NULL;
	
	empilhar(topo, "Sousa", 60000);
	empilhar(topo, "Cajazeiras", 50000);
	empilhar(topo, "Pombal", 40000);
	empilhar(topo, "Patos", 120000);
	empilhar(topo, "Campina", 250000);
	
	meio = acharMeio(topo);
	cout << meio << endl;

	removerMeio(topo, meio);
	exibirLista(topo);


	return 0;
}
