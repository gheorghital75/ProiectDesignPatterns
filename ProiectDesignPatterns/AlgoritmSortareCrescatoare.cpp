#include <vector>
#include "Document.cpp"

class AlgoritmSortareCrescatoare
{
    void schimba(Document*& x, Document*& y)
    {
        Document* tmp = x;
        x = y;
        y = tmp;
    }
    bool comparare(Document*& a, Document*& b)
    {
        if (a->prioritate > b->prioritate)
            return true;
        else
            return false;
    }
public:
    void sorteaza(std::vector<Document*>* arr) {
        bool suntToateSchimbate = true;
        int x = 0;
        while (suntToateSchimbate)
        {
            suntToateSchimbate = false;
            x++;
            for (int i = 0; i < (*arr).size() - x; i++)
            {
                if (comparare((*arr)[i], (*arr)[i+1]))
                {
                    schimba((*arr)[i], (*arr)[i+1]);
                    suntToateSchimbate = true;
                }
            }
        }
    }
};