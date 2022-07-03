#include <iostream>
using namespace std;

#ifndef DOCUMENT_H
#define DOCUMENT_H

class Document {
public:
    int prioritate = 0;
    Document(int p) 
    {
        this->prioritate = p;
    }
    virtual void afiseazaDocument() = 0;
};
class DocumentCerere : public Document {
public:
    DocumentCerere(int p) :Document(p) {}
    void afiseazaDocument()
    {
        cout << "Afiseaza document tip cerere cu prioritatea " << this->prioritate << endl;
    }
};
class DocumentProcesVerbal : public Document {
public:
    DocumentProcesVerbal(int p) :Document(p) {}
    void afiseazaDocument()
    {
        cout << "Afiseaza document tip proces verbal cu prioritatea " << this->prioritate << endl;
    }
};

#endif