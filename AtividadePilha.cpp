#include <iostream>

using namespace std;

struct Cidade{
	int populacao;
	string nome;	
};

struct ElementoPilha{
	Cidade cidade;
	ElementoPilha *next;
	char caractere;
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
    
void desempilhar(ElementoPilha *&topo, ElementoPilha *&temp) {
    if (topo == NULL) {
        return;
    }

    temp = topo;
    topo = topo->next;

    desempilhar(topo, temp->next);

    if (topo != NULL) {
        ElementoPilha *tempTopo = topo;
        while (tempTopo->next) {
            tempTopo = tempTopo->next;
        }
        tempTopo->next = temp;
        temp->next = NULL;
    } else {
        topo = temp;
    }
}

void reverterPilha(ElementoPilha *&topo) {
    ElementoPilha *temp = NULL;
    desempilhar(topo, temp);
}

void empilharPalavra(ElementoPilha*& topo, char c){
    ElementoPilha* novoElemento = new ElementoPilha;
    novoElemento->caractere = c;
    novoElemento->next = topo;
    topo = novoElemento;
}

char desempilharPalavra(ElementoPilha*& topo){
    if(topo == NULL) return '\0';
    char c = topo->caractere;
    ElementoPilha* temp = topo;
    topo = topo->next;
    delete temp;
    return c;
}

string reverterString(string palavra) {
    ElementoPilha* topo = NULL;
    
    for(char c : palavra) {
        empilharPalavra(topo, c);
    }
    
    string revertida = "";
    char c;
    while((c = desempilharPalavra(topo)) != '\0') {
        revertida += c;
    }
    return revertida;
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
	
	cout << "A lista inicial eh:";
	exibirLista(topo);
	
	removerMeio(topo, meio);
	cout << "\n\nO elemento do meio foi removido e a nova lista eh:";
	exibirLista(topo);

	reverterPilha(topo);
	cout << "\n\nA lista foi revertida para:";
	exibirLista(topo);

	string palavra;
	cout << "\n\nDigite uma palavra:";
	cin >> palavra;
	
	string revertida =  reverterString(palavra);
	cout << "Palavra revertida: " << revertida << endl;
	
	return 0;
}
