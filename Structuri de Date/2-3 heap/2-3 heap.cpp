//din ce am inteles, un 2-3 heap este un heap format din 2-3 trees

#include <fstream>
#include <vector>
#include <cmath>

using namespace std;
//structura nod care reprezinta un nod dintr un arbore
struct Nod {
    Nod* parinte;
    Nod* copil;
    Nod* st;
    Nod* dr;
    Nod* partener;
    bool extra;
    int dim;
    long long cheie;
};
//functia pentru initializarea unui nod
void initNod(Nod* nod) {
    nod->parinte = nullptr;
    nod->copil = nullptr;
    nod->st = nullptr;
    nod->dr = nullptr;
    nod->partener = nullptr;
    nod->extra = false;
    nod->dim = 0;
    nod->cheie = 0;
}
//functia care adauga un copil nodului
void adaugaCopil(Nod* parinte, Nod* copil) {
    Nod* nst, * ndr;
    nst = parinte->copil;
    if (nst != nullptr) {
        ndr = nst->dr;
        copil->st = nst;
        copil->dr = ndr;
        ndr->st = copil;
        nst->dr = copil;
    }
    else {
        copil->st = copil->dr = copil;
    }
    parinte->copil = copil;
    copil->parinte = parinte;
}

void stergeCopil(Nod* parinte, Nod* copil) {
    Nod* nst=new Nod, * ndr=new Nod;
    initNod(nst);
    initNod(ndr);
    if (copil->dim) {
        parinte->st = copil->st;
        parinte->dr = copil->dr;
        nst->dr = parinte->dr;
        ndr->st = parinte->st;
    }
    else {
        parinte->copil = nullptr;
    }
}

void schimbaCopil(Nod* parinte, Nod* nod) {
    Nod* nst, * ndr = parinte->dr;
    if (ndr == parinte) {
        nod->dr = nod->st = nod;
    }
    else {
        nst = parinte->st;
        nst->dr = nod;
        ndr->st = nod;
        nod->st = nst;
        nod->dr = ndr;
    }
    nod->parinte = parinte->parinte;
    if (parinte->parinte->copil == parinte)
        parinte->parinte->copil = nod;
}

int mergeNoduri(Nod** a, Nod** b) {
    Nod* arb1, * arb1part, * arb2, * arb2part;
    if ((*a)->cheie >= (*b)->cheie) {
        arb1 = (*a);
        arb2 = (*b);
    }
    else {
        arb1 = (*b);
        arb2 = (*a);
    }
    int aux = 1;
    arb1part = arb1->partener;
    arb2part = arb2->partener;
    if (arb1part == nullptr) {
        if (arb2part != nullptr) {
            adaugaCopil(arb1, arb2);
            (arb1->dim)++;
            *a = nullptr;
            *b = arb1;
        }
        else {
            arb1->partener = arb2;
            arb2->partener = arb1;
            arb2->extra = true;
            *a = arb1;
            *b = nullptr;
        }
    }
    else
        if (arb2part == nullptr) {
            arb1->partener = nullptr;
            arb2->partener = arb1part;
            arb1part->partener = arb2;
            if (arb2->cheie > arb1part->cheie)
                adaugaCopil(arb1, arb2);
            else {
                arb1part->extra = false;
                arb2->extra = true;
                adaugaCopil(arb1, arb1part);
            }
            (arb1->dim)++;
            aux++;
            *a = nullptr;
            *b = arb1;
        }
        else {
            arb1->partener = nullptr;
            arb1part->partener = nullptr;
            arb1part->extra = false;
            arb1part->st = arb1part->dr = arb1part;
            arb1part->parinte = nullptr;
            adaugaCopil(arb1, arb2);
            (arb1->dim)++;
            *a = arb1part;
            *b = arb1;
        }
    return aux;
}

struct Heap {
    Nod** arbori;
    int nrArbori;
    int nrNoduri;
    int valoare;
};

void creareHeap(Heap *heap, int nrNoduri) {
    heap->nrNoduri = 0;
    heap->nrArbori = (int)(0.5+log(nrNoduri+1)/log(2.0));
    heap->arbori = new Nod * [heap->nrArbori];
    for (int i = 0; i < heap->nrArbori; i++)
        heap->arbori[i] = nullptr;
    heap->valoare = 0;
}

void combina(Heap* heap, Nod* nod) {
    Nod* urm=new Nod, * arb1=new Nod, * arb2=new Nod;
    initNod(urm);
    initNod(arb1);
    initNod(arb2);
    int aux;
    arb1 = nod;
    arb2 = nullptr;
    do {
        if (arb1 != nullptr) {
            urm = arb1->dr;
            arb1->dr = arb1->st = arb1;
            arb1->parinte = nullptr;
        }
        else {
            arb1 = arb2;
            arb2 = nullptr;
        }
        if (arb2 != nullptr)
            mergeNoduri(&arb1, &arb2);
        if (arb1 != nullptr) {
            aux = arb1->dim;
            if (heap->arbori[aux] != nullptr) {
                mergeNoduri(&(heap->arbori[aux]), &arb1);
                if (heap->arbori[aux] == nullptr)
                    heap->valoare -= (1 << aux);
                arb2 = arb1;
            }
            else {
                heap->arbori[aux] = arb1;
                heap->valoare += (1 << aux);
            }
        }
        arb1 = urm;
    } while (arb1 || arb2);
}

//functia de inserare a unui nou nod in heap
void inserare(Heap* heap, int cheie) {
    Nod* nod = new Nod;
    initNod(nod);
    nod->cheie = cheie;
    combina(heap, nod);
    (heap->nrNoduri)++;
}

// in fisierul cu indicatii se cerea minimul, dar problema cere maximul, asa ca am facut functii pentru maxim:

Nod* maxim(Heap* heap) {
    Nod* max=new Nod, * urm=new Nod;
    initNod(max);
    initNod(urm);
    long long cheie1, cheie2;
    int valoare, p;
    valoare = heap->valoare;
    p = -1;
    while (valoare) {
        valoare = valoare >> 1;
        p++;
    }
    max = heap->arbori[p];
    cheie1 = max->cheie;
    while (p > 0) {
        p--;
        urm = heap->arbori[p];
        if (urm != nullptr) {
            cheie2 = urm->cheie;
            if (cheie2 > cheie1) {
                cheie1 = cheie2;
                max = urm;
            }
        }
    }
    return max;
}

long long extractMaxim(Heap* heap) {
    Nod* copil, * urm, * partener, * max = maxim(heap);
    int dim = max->dim;
    partener = max->partener;
    if (partener != nullptr) {
        partener->partener = nullptr;
        partener->extra = false;
        partener->parinte = nullptr;
        partener->st = partener->dr = partener;
        heap->arbori[dim] = partener;
    }
    else {
        heap->arbori[dim] = nullptr;
        heap->valoare -= (1 << dim);
    }
    (heap->nrNoduri)--;
    copil = max->copil;
    if (copil != nullptr) {
        urm = copil->dr;
        urm->st = copil->dr = nullptr;
        combina(heap, urm);
    }
    return max->cheie;
}

void heapify(Heap* heap1, Heap* heap2) {
    for (int i = 0; i < heap2->nrArbori; i++) {
        if (heap2->arbori[i] != nullptr) {
            heap2->arbori[i]->dr = heap2->arbori[i]->st = nullptr;
            combina(heap1, heap2->arbori[i]);
            heap2->arbori[i] = nullptr;
        }
    }
    heap1->nrNoduri += heap2->nrNoduri;
    heap2->nrNoduri = 0;
}

void stergereHeap(Heap* heap) {
    delete[] heap->arbori;
}

int main()
{
    ifstream fin("mergeheap.in");
    ofstream fout("mergeheap.out");

    int n, q;

    fin >> n >> q;
    Heap** heapuri = new Heap*[n+1];

    for (int i = 1; i <= n; i++) {
        heapuri[i] = new Heap;
        creareHeap(heapuri[i], 300000);
    }

    for (int i = 0; i < q; i++) {
        int op, m;
        fin >> op;
        switch (op) {
        case 1:
            long long x;
            fin >> m >> x;
            inserare(heapuri[m], x);
            break;
        case 2:
            fin >> m;
            fout << extractMaxim(heapuri[m]) << "\n";
            break;
        case 3:
            int a, b;
            fin >> a>> b;
            heapify(heapuri[a], heapuri[b]);
            heapuri[b] = new Heap;
            creareHeap(heapuri[b], 300000);

        }
    }

    for (int i = 1; i <= n; i++) {
        stergereHeap(heapuri[i]);
    }


    fin.close();
    fout.close();
    return 0;
}