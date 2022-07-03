#include <iostream>
#include <vector>
#include "Document.cpp"
#include "AlgoritmSortareCrescatoare.cpp"

using namespace std;


class Client {
public:
    Client()
    {

    }

    ~Client()
    {
        if (pointerDocument) {
            delete[] pointerDocument;
            pointerDocument = NULL;
        }
    }

    Document* creazaDocument(int tip,int p) { 
        if (tip == 1)
            pointerDocument = new DocumentCerere(p);
        else if (tip == 2)
            pointerDocument = new DocumentProcesVerbal(p);
        else
            pointerDocument = NULL;
        return pointerDocument; 
    }

private:
    Document* pointerDocument;
};

// Driver program
int main()
{
    Client* pClient = new Client();
    Document* d1 = pClient->creazaDocument(1, 10);
    Document* d2 = pClient->creazaDocument(1, 20);
    Document* d3 = pClient->creazaDocument(2, 30);
    Document* d4 = pClient->creazaDocument(1, 5);

    // o referinta catre un vector de referinte catre documente 
    vector<Document*>* documente = new vector<Document*>();
    documente->push_back(d1);
    documente->push_back(d2);
    documente->push_back(d3);
    documente->push_back(d4);

    // se afiseaza mesajul pentru fiecare document
    for (std::vector<Document*>::iterator it = documente->begin(); it != documente->end(); it++) {
        ((Document*)*it)->afiseazaDocument();
    }

    AlgoritmSortareCrescatoare* asc = new AlgoritmSortareCrescatoare();
    asc->sorteaza(documente);

    cout << endl << "Elementele vectorului sortate: " << endl;

    // se afiseaza mesajul pentru fiecare document
    for (std::vector<Document*>::iterator it = documente->begin(); it != documente->end(); it++) {
        ((Document*)*it)->afiseazaDocument();
    }

    return 0;
}