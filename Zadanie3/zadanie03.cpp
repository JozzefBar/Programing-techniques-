/*
Meno a priezvisko:

POKYNY:
(1)  Implementujte funkcie tak, aby splnali popis pri ich deklaraciach.
(2)  Cela implementacia musi byt v tomto jednom subore.
(3)  Odovzdajte len tento zdrojovy subor (s vypracovanymi rieseniami).
(4)  Program musi byt kompilovatelny.
(5)  Globalne a staticke premenne su zakazane.
(6)  V ziadnom pripade nemente deklaracie funkcii, ktore mate za ulohu naprogramovat
     (nemente nazvy, navratove hodnoty, ani typ a pocet parametrov v zadanych funkciach).
     Nemente implementacie zadanych datovych typov, ani implementacie hotovych pomocnych funkcii
     (ak nie je v zadani ulohy uvedene inak).
(7)  V pripade potreby mozete kod doplnit o dalsie pomocne funkcie alebo datove typy.
(8)  Vase riesenie otestujte (vo funkcii 'main' a pomocou doplnenych pomocnych funkcii alebo datovych typov).
     Testovaci kod ale nebude hodnoteny.
(9)  Funkcia 'main' musi byt v zdrojovom kode posledna.
*/

#include <iostream>
#include <cstring>

#define ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0]))

using namespace std;

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Uzol zretazeneho zoznamu
struct Node {
    int data; // hodnota uzla
    Node* next; // smernik na dalsi uzol zoznamu
};

// Zretazeny zoznam
struct List {
    Node* first; // smernik na prvy uzol zoznamu
};

//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia usporiada pole 'data' od najvacsieho prvku po najmensi prvok.
    Pouzite algoritmus insertion sort.

    PARAMETRE:
        [in, out] data - pole, ktore funkcia usporiada
        [in] length    - pocet prvkov pola

    VSTUPNE PODMIENKY:
        'length' moze mat lubovolnu hodnotu
        'data' ukazuje na platne pole

    PRIKLADY:
        (1, 3, 2) -> (3, 2, 1)
        (1, 2, 2, 1) -> (2, 2, 1, 1)
        (1) -> (1)
        () -> ()
*/
void insertionSort(int *data, const size_t length) {
    for(size_t i = 1; i < length; i++){
        int tmp = data[i];
        size_t j = i;
        while(j > 0 && data[j - 1] < tmp){
            data[j] = data[j - 1];
            j--;
        }
        data[j] = tmp;
    }
}

//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia usporiada textove retazce v poli 'data' od najvacsieho prvku po najmensi (lexikograficky).
    Preusporiadajte smerniky v poli.
    Pouzite algoritmus insertion sort.

    PARAMETRE:
        [in, out] data - pole, ktore funkcia usporiada.
                Pole obsahuje smerniky na textove retazce.
                Kazdy textovy retazec je ukonceny '\0'.
                Posledny smernik ma hodnotu 'nullptr'. Podla toho urcite pocet prvkov pola (pocet textovych retazcov).

    VSTUPNE PODMIENKY:
        'data' obsahuje minimalne jeden smernik.
        Posledny smernik ma hodnotu 'nullptr'.

    PRIKLADY:
        ("Juraj", "Peter", "Andrej", nullptr) -> ("Peter", "Juraj", "Andrej", nullptr)
        ("Juraj", "Anabela", "Peter", "Andrej", nullptr) -> ("Peter", "Juraj", "Andrej", "Anabela", nullptr)
        ("Andrej", "Juraj", "Andrej", nullptr) -> ("Juraj", "Andrej", "Andrej", nullptr)
        ("Andrej", nullptr) -> ("Andrej", nullptr)
        (nullptr) -> (nullptr)

    POZNAMKY:
        Pri testovani mozete jednoducho pole vytvorit nasledovnym sposobom:
        const char *mena[] = {"Juraj", "Peter", "Andrej", nullptr};

        Na porovnanie obsahu textovych retazcov vyuzite prislusnu funkciu zo standardnej kniznice.
*/
void insertionSort(const char *data[]) {
    int n = 0;
    while(data[n] != nullptr) n++;

    for(size_t i = 1; i < n; i++){
        const char* key = data[i];
        size_t j = i;

        while (j > 0 && strcmp(data[j - 1], key) < 0) {
            data[j] = data[j - 1];
            j--;
        }
        data[j] = key;
    }
}

//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia usporiada zretazeny zoznam 'list' od najvacsieho prvku po najmensi.
    Preusporiadajte uzly v zozname (nekopirujte hodnoty v uzloch).
    Pouzite algoritmus insertion sort.

    PARAMETRE:
        [in, out] list - zretazeny zoznam, ktory funkcia usporiada

    VSTUPNE PODMIENKY:
        'list' obsahuje lubovolny pocet uzlov (moze byt prazdny)
        'list' nie je 'nullptr'

    PRIKLADY:
        vstup: 2->1->3,        vystup: 3->2->1
        vstup: 1->2->2->1,     vystup: 2->2->1->1
        vstup: prazdny zoznam, vystup: prazdny zoznam
*/

Node* Sortedlist(Node* sorted, Node* newnode){
    if(sorted == nullptr || sorted->data <= newnode->data){
        newnode->next = sorted;
        return newnode;
    }
    else{
        Node* current = sorted;
        while(current->next != nullptr && current->next->data > newnode->data){
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
        return sorted;
    }
}

void insertionSort(List * list) {
    Node* sorted = nullptr;
    Node* current = list->first;

    while(current != nullptr){
        Node* next = current->next;
        sorted = Sortedlist(sorted, current);
        current = next;
    }

    list->first = sorted;
}

void printList(const List* list){
    Node* tmp = list->first;
    while(tmp){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
}

Node* createNode(const int data){
    Node* tmp = new Node;
    tmp->data = data;
    tmp->next = nullptr;
    return tmp;
}

void appendNode(List* list, const int val) {
    Node* tmp = createNode(val);
    if(list->first){
        Node* tmp2 = list->first;
        while(tmp2->next)
            tmp2 = tmp2->next;
        tmp2->next = tmp;
    }
    else list->first = tmp;
}

//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vykona algoritmus merge (cast algoritmu merge sort), ktory ma linearnu vypoctovu zlozitost.
    Kombinuje dve susedne, usporiadane casti v poli 'input', do jednej usporiadanej casti v poli 'output'.
    Usporiadanie je od najvacsieho prvku po najmensi prvok!

    PARAMETRE:
        [out] output - vystupne pole, ktoreho cast output[low]...output[high-1] bude po vykonani funkcie usporiadana
        [in]  input  - vstupne pole, ktoreho casti input[low]...input[middle-1] a input[middle]...input[high-1]
                         musia byt pri volani funkcie usporiadane od najvacsieho prvku po najmensi
        [in]  low    - index 1. prvku lavej usporiadanej casti pola 'input'
        [in]  middle - index 1. prvku pravej usporiadanej casti pola 'input'
        [in]  high   - index za poslednym prvkom pravej usporiadanej casti pola 'input'

    VYSTUPNE PODMIENKY:
        Obsah 'input' je nezmeneny.
        output[low] ... output[high-1] obsahuje usporiadane prvky z input[low] ... input[high-1].
        Prvky s indexami mensimi ako 'low' sa nemenia (ani v jednom poli).
        Prvky s indexami vacsimi alebo rovnymi ako 'high' sa nemenia (ani v jednom poli).

    PRIKLAD:
        low: 4
        middle: 8
        hight: 12
        input:                         (10, 10, 10, 10,  7,  5,  2,  0,  8,  4,  2,  1, 10, 10, 10, 10)
        output pred vykonanim funkcie: (20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20)
        output po vykonani funkcie:    (20, 20, 20, 20,  8,  7,  5,  4,  2,  2,  1,  0, 20, 20, 20, 20)
*/
void mergeNeighbours(int *output, const int *input, const size_t low, const size_t middle, const size_t high) {
    size_t i = low;
    size_t j = middle;
    size_t curr = low;

    while(i < middle && j < high){
        if(input[i] >= input[j]){
            output[curr] = input[i];
            i++;
        }
        else{
            output[curr] = input[j];
            j++;
        }
        curr++;
    }
    while (i < middle) {
        output[curr] = input[i];
        ++ i;
        ++ curr;
    }
    while (j < high) {
        output[curr] = input[j];
        ++ j;
        ++ curr;
    }
}

void println(const char *label, const int *data, size_t length) {
    std::cout << label << ": ";
    for (size_t i = 0; i < length; ++ i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia usporiada prvky v poli 'data' od najvacsieho prvku po najmensi.
    Pouzite algoritmus merge sort.
    Vytvorte jedno pomocne pole. Pre alokaciu a dealokaciu pomocneho pola pouzite new[] a delete[].

    PARAMETRE:
        [in, out] data - pole, ktore funkcia usporiada
        [in] length    - pocet prvkov pola

    VSTUPNE PODMIENKY:
        'data' ukazuje na platne pole

    PRIKLADY:
        (1, 3, 2) -> (3, 2, 1)
        (1, 2, 2, 1) -> (2, 2, 1, 1)
        (1) -> (1)
        () -> ()

    POZNAMKA:
        Ak pouzijete pristup top-down, tak
        - v tejto funkcii zabezpecte vytvorenie a kopirovanie dat do pomocneho pola,
        - vytvorte a zavolajte rekurzivnu funkciu, v ktorej implementujete hlavnu cast algoritmu merge sort.
*/
void mergeSortRecursive(int *data1, int *data2, size_t low, size_t high) {
    if (low + 1 < high) {
        size_t middle = (low + high) / 2;
        mergeSortRecursive(data2, data1, low, middle);
        mergeSortRecursive(data2, data1, middle, high);
        mergeNeighbours(data1, data2, low, middle, high);
    }
}

void mergeSort(int *data, const size_t length) {
    int *temp = new int[length];
    memcpy(temp, data, length * sizeof(int));
    mergeSortRecursive(data, temp, 0, length);
    delete[] temp;
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

// tu mozete doplnit pomocne funkcie a struktury

int main() {
    //1. úloha
    /*
    int list[4] = {2, 1, 9, 8};
    insertionSort(list, ARRAY_SIZE(list));
    cout << "Úsporiadaný list: ";
    for(int i : list){
         cout << i << " ";
    }
    */

    /*
    //2. úloha
    const char *mena[] = {"Juraj", "Anabela", "Peter", "Andrej", nullptr};
    insertionSort(mena);
    cout << "Úsporiadaný list: ";
    for(auto & i : mena){
        cout << i << " ";
    }
    */

    //3. úloha

    List list{};
    appendNode(&list, 4);
    appendNode(&list, 14);
    appendNode(&list, -4);
    appendNode(&list, 7);
    appendNode(&list, 11);

    insertionSort(&list);
    printList((&list));

    //4. úloha
    /*
    int input[]  = {10, 10, 10, 10,  7,  5,  2,  0,  8,  4,  2,  1, 10, 10, 10, 10};
    int output[] = { 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20};
    mergeNeighbours(output, input, 4, 8, 12);
    println("input ", input, ARRAY_SIZE(input));
    println("output", output, ARRAY_SIZE(output));
    */
    //5. úloha
    /*
    int d1[] = {4,2,1,3,5,6};
    mergeSort(d1, ARRAY_SIZE(d1));
    println("d1", d1, ARRAY_SIZE(d1));
    */
    return 0;
}
