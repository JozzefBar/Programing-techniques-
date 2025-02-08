/*
Meno a priezvisko: Jozef Barčák

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

using namespace std;

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Reprezentacia uzla zretazeneho zoznamu
struct Node {
    int data; // hodnota uzla
    Node* next; // adresa nasledujuceho uzla zoznamu
};

// Reprezentacia zretazeneho zoznamu
struct List {
    Node* first; // adresa prveho uzla zoznamu
};

// Uspesnost vykonania funkcie
enum class Result {
    SUCCESS, // funkcia vykonana uspesne
    FAILURE  // chyba pri vykonavani funkcie
};

//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia prida novy uzol s hodnotou 'val' na zaciatok zoznamu 'list'.

    PARAMETRE:
        [in] list - vstupny zretazeny zoznam
        [in] val - hodnota uzla pridaneho na zaciatok zoznamu

    PRIKLADY:
        list=() a val=0 ... zoznam po vykonani funkcie ... (0)
        list=(-3) a val=1 ... zoznam po vykonani funkcie ... (1,-3)
        list=(6,6,5,8) a val=10 ... zoznam po vykonani funkcie ... (10,6,6,5,8)
*/

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

void prependNode(List* list, const int val) {
    Node *tmp = createNode(val);
    tmp->next = list->first;
    list->first = tmp;
}

//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia prida novy uzol s hodnotou 'val' na koniec zoznamu 'list'.

    PARAMETRE:
        [in] list - vstupny zretazeny zoznam
        [in] val - hodnota uzla pridaneho na koniec zoznamu

    PRIKLADY:
        list=() a val=7 ... zoznam po vykonani funkcie ... (7)
        list=(0) a val=1 ... zoznam po vykonani funkcie ... (0,1)
        list=(1,2,3,4,5) a val=6 ... zoznam po vykonani funkcie ... (1,2,3,4,5,6)
*/

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
// 3. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori novy zretazeny zoznam a vyplni ho vsetkymi cislami (v zachovanom poradi),
    ktore sa nachadzaju vo vstupnom poli 'data', ktore ma dlzku 'n'.

    PARAMETRE:
        [in] data - vstupne pole cisiel
        [in] n - dlzka vstupneho pola

    NAVRATOVA HODNOTA:
        Vytvoreny zretazeny zoznam obsahujuci vsetky hodnoty zo vstupneho pola 'data' (v zachovanom poradi).
        V pripade prazdneho pola (dlzka 0), funkcia vrati prazdny zoznam (prazdny zoznam je taky, kde smernik 'first'
        ukazuje na 'nullptr').

    PRIKLADY:
        data=(1) a n=1 ... vrati zoznam ... (1)
        data=(7,6,41,2) a n=4 ... vrati zoznam ... (7,6,41,2)
        data=(3,2,1) a n=0 ... vrati zoznam ... ()
*/

void clearList(List *list) {
    while (list->first) {
        Node *tmp = list->first->next;
        delete list->first;
        list->first = tmp;
    }
}
// Funkcia na vymazanie celeho zoznamu
void destroyList(List **list) {
    clearList(*list);
    delete (*list);
    (*list) = nullptr;
}

List* createListFromArray(const int* data, const size_t n) {
    List* list = new List;
    list->first = nullptr;
    for(size_t i = 0; i < n; i++){
        appendNode(list, data[i]);
    }
    return list;
}

//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori novy symetricky zretazeny zoznam (vid priklady) podla parametra 'val'.
    Symetricky zoznam ma tvar 0,1,2,...val...2,1,0.

    PARAMETRE:
        [in] val - hodnota uzla podla, ktoreho sa vytvori novy symetricky zretazeny zoznam (uzol v strede zoznamu).

    NAVRATOVA HODNOTA:
        Vytvoreny zretazeny zoznam obsahujuci prvky v takom poradi, aby bol symetricky.
        V pripade 'val'<0, funkcia vrati 'nullptr'.

    PRIKLADY:
        val=-31 ... vrati ... nullptr
        val=0 ... vrati zoznam ... (0)
        val=1 ... vrati zoznam ... (0,1,0)
        val=2 ... vrati zoznam ... (0,1,2,1,0)
        val=3 ... vrati zoznam ... (0,1,2,3,2,1,0)
        val=4 ... vrati zoznam ... (0,1,2,3,4,3,2,1,0)
        val=6 ... vrati zoznam ... (0,1,2,3,4,5,6,5,4,3,2,1,0)
*/

List* createSymmetricList(const int val) {
    if(val < 0)
        return nullptr;

    List* list = new List;
    list->first = nullptr;

    appendNode(list, val);
    for(int i = val - 1; i >= 0; i--){
        prependNode(list, i);
        appendNode(list, i);
    }
    return list;
}

//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia odstrani (aj spravne uvolni pamat) zo vstupneho zoznamu 'list' prvy uzol.

    PARAMETRE:
        [in,out] list - zretazeny zoznam, z ktoreho funkcia odstrani uzol

    NAVRATOVA HODNOTA:
        Result::SUCCESS, ak bol prvy uzol vymazany
        Result::FAILURE, ak nebol prvy uzol vymazany (vstupny zoznam bol prazdny)

    PRIKLADY:
        list=() ... funkcia vrati Result::FAILURE
        list=(5) ... zoznam po vykonani funkcie ... () a vrati Result::SUCCESS
        list=(10,10,10) ... zoznam po vykonani funkcie ... (10,10) a vrati Result::SUCCESS
        list=(3,2,1) ... zoznam po vykonani funkcie ... (2,1) a vrati Result::SUCCESS
*/

Result removeFirstNode(List* list) {
    if(list->first == nullptr) return Result::FAILURE;

    Node *tmp = list->first;
    list->first = tmp->next;

    delete tmp;
    return Result::SUCCESS;
}

//-------------------------------------------------------------------------------------------------
// 6. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia najde prvy uzol zretazeneho zoznamu 'list', ktory obsahuje hodnotu 'val'.

    PARAMETRE:
        [in] list - vstupny zretazeny zoznam
        [in] val - hodnota uzla, ktory sa hlada

    NAVRATOVA HODNOTA:
        Funkcia vrati prvy uzol, ktory obsahuje hodnotu 'val'.
        Ak sa taky uzol v zozname nenachadza alebo je vstupny zoznam prazdny, vtedy funkcia vrati 'nullptr'.

    PRIKLADY:
        list=(), val=10 ... funkcia vrati 'nullptr'
        list=(2), val=3 ... funkcia vrati 'nullptr'
        list=(1,2,3,4,5,6), val=-1 ... funkcia vrati 'nullptr'
        list=(1), val=1 ... funkcia vrati uzol s hodnotou 1
        list=(5,9,18), val=9 ... funkcia vrati uzol s hodnotou 9
*/

Node* findNodeInList(List* list, const int val) {
    Node* tmp = list->first;
    while(tmp){
        if(tmp->data == val) return tmp;
        else
            tmp = tmp->next;
    }
    return nullptr;
}

//-------------------------------------------------------------------------------------------------
// 7. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia zisti, ci su dva vstupne zoznamy 'list1' a 'list2' rovnake (t.j. rovnako dlhe a obsahujuce
    rovnake hodnoty uzlov v rovnakom poradi).

    PARAMETRE:
        [in] list1 - prvy zretazeny zoznam
        [in] list2 - druhy zretazeny zoznam

    NAVRATOVA HODNOTA:
        'true' - ak su vstupne zoznamy rovnake
        'false' - ak vstupne zoznamy nie su rovnake

    PRIKLADY:
        list1=(1)
        list2=()
        Funkcia vrati 'false'.

        list1=()
        list2=(5,3)
        Funkcia vrati 'false'.

        list1=()
        list2=()
        Funkcia vrati 'true'.

        list1=(1)
        list2=(1)
        Funkcia vrati 'true'.

        list1=(4,-9,2)
        list2=(4,-9,2)
        Funkcia vrati 'true'.

        list1=(3,2,1)
        list2=(1,2,3)
        Funkcia vrati 'false'.

        list1=(2)
        list2=(7,4,5)
        Funkcia vrati 'false'.

        list1=(7,4)
        list2=(7,4,5)
        Funkcia vrati 'false'.
*/

bool areListsEqual(List* list1, List* list2) {
    Node* tmp1 = list1->first;
    Node* tmp2 = list2->first;

    while(tmp1 != nullptr || tmp2 != nullptr){
        if(tmp1 == nullptr || tmp2 == nullptr || tmp1->data != tmp2->data) return false;
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }

    return true;
}

//-------------------------------------------------------------------------------------------------
// 8. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori novy zretazeny zoznam prekopirovanim vsetkych hodnot uzlov vstupneho zoznamu 'list' v obratenom
    poradi.

    PARAMETRE:
        [in] list - vstupny zretazeny zoznam

    NAVRATOVA HODNOTA:
        Zretazeny oznam, ktory vznikne prekopirovanim hodnot uzlov vstupneho zoznamu 'list' v obratenom poradi.

    PRIKLADY:
        list=() ... funkcia vrati ... () t.j. prazdny zoznam
        list=(1) ... funkcia vrati ... (1)
        list=(5,6) ... funkcia vrati ... (6,5)
        list=(8,14,2,3) ... funkcia vrati ... (3,2,14,8)
*/

List* copyListReverse(List* list) {
    List* newlist = new List;
    newlist->first = nullptr;
    Node* tmp = list->first;
    while(tmp){
        prependNode(newlist, tmp->data);
        tmp = tmp->next;
    }

    return newlist;
}

//-------------------------------------------------------------------------------------------------
// 9. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vyhlada predchodcu zadaneho uzla 'node' vo vstupnom zretazenom zozname 'list'.

    VSTUPNA PODMIENKA:
        Uzol 'node' je vzdy existujucim uzlom vstupneho zoznamu 'list'.

    PARAMETRE:
        [in] list - vstupny zretazeny zoznam
        [in] node - uzol zretazeneho zoznamu 'list', ktoreho predchodcu hladame

    NAVRATOVA HODNOTA:
        Uzol, ktory je predchodcom uzla 'node' v zozname 'list'.
        V pripade hladania predchodcu prveho uzla zoznamu, funkcia vrati 'nullptr'.

    PRIKLADY:
        list=(4)
        node=4
        Funkcia vrati 'nullptr'.

        list=(1,2,3,4,5)
        node=1
        Funkcia vrati 'nullptr'.

        list=(-2,-3,56,4,41)
        node=-3
        Funkcia vrati uzol s hodnotou -2.

        list=(10,54,69,82,6)
        node=6
        Funkcia vrati uzol s hodnotou 82.
*/

Node* findPreviousNode(List* list, Node* node) {
    Node* tmp = list->first;
    while(tmp){
        if(tmp->next == nullptr || node->data == list->first->data) return nullptr;
        Node* tmp2 = tmp->next;
        if(node->data == tmp2->data) return tmp;
        tmp = tmp2;
    }
    return nullptr;
}

//-------------------------------------------------------------------------------------------------
// 10. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia zduplikuje vsetky uzly vstupneho zoznamu 'list', ktore obsahuju kladnu hodnotu.

    PARAMETRE:
        [in,out] list - vstupny zretazeny zoznam

    PRIKLADY:
        list=() ... po vykonani funkcie ... ()
        list=(3) ... po vykonani funkcie ... (3,3)
        list=(-1,1) ... po vykonani funkcie ... (-1,1,1)
        list=(-8,-9,-13) ... po vykonani funkcie ... (-8,-9,-13)
        list=(1,0,-2,3,-4) ... po vykonani funkcie ... (1,1,0,-2,3,3,-4)
*/

void duplicatePositiveNodes(List* list) {
    Node* tmp = list->first;
    while(tmp){
        if(tmp->data > 0){
            Node* newNode = createNode(tmp->data);
            newNode->next = tmp->next;
            tmp->next = newNode;
            tmp = newNode->next;
        }
        else
            tmp = tmp->next;
    }
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

// tu mozete doplnit pomocne funkcie a struktury pre testovanie

int main() {
    //uloha 1
    /*
    List list{};
    prependNode(&list, 4);
    prependNode(&list, 2);
    prependNode(&list, 5);
    printList((&list));
    */

    //uloha 2
    /*
    List list{};
    appendNode(&list, 4);
    appendNode(&list, 14);
    appendNode(&list, -4);
    printList((&list));
    */

    //uloha 3
    /*
    int data[4] = {4, 5, 6, 7};

    List* list = createListFromArray(data, sizeof(data)/sizeof(data[0]));
    printList(list);
    destroyList(&list);
    */

    //uloha 4
    /*
    List* list = createSymmetricList(4);
    if(list != nullptr) {
        printList(list);
        destroyList(&list);
    }
    */

    //uloha 5
    /*
    List* list = new List;
    list->first = nullptr;
    appendNode(list, -4);
    removeFirstNode(list);
    if(list != nullptr) {
        printList(list);
        destroyList(&list);
    }
    */

    //uloha 6
    /*
    List list{};
    appendNode(&list, 4);
    appendNode(&list, 14);
    appendNode(&list, -4);


    Node* foundNode = findNodeInList(&list, -4);
    if (foundNode) {
        std::cout << "Uzol s hodnotou " << foundNode->data << " bol nájdený." << std::endl;
    } else {
        std::cout << "Uzol s danou hodnotou nebol nájdený." << std::endl;
    }
    */

    //uloha 7

    List list{};
    List list2{};
    appendNode(&list2, 5);

    if (areListsEqual(&list, &list2))
        cout << "Sú symetrické" << endl;
    else
        cout << "Nie sú symetrické" << endl;

    //uloha 8
    /*
    List list{};
    appendNode(&list, 4);
    appendNode(&list, 14);
    appendNode(&list, -4);
    appendNode(&list, 7);
    appendNode(&list, 21);

    List* newlist = copyListReverse(&list);
    printList(newlist);

    if(newlist != nullptr) {
        destroyList(&newlist);
    }
    */

    //uloha 9
    /*
    List list{};
    appendNode(&list, 4);
    appendNode(&list, 8);
    appendNode(&list, 5);
    appendNode(&list, 15);
    appendNode(&list, -4);
    appendNode(&list, 48);
    appendNode(&list, 2);
    appendNode(&list, 54);

    Node* node = list.first->next->next;
    Node* previousNode = findPreviousNode(&list, node);

    if(previousNode)
        cout << "Je tam taký node: " << previousNode->data <<endl;
    else
        cout << "Nie je tam taký node" << endl;
    */

    //uloha 10
    /*
    List list{};
    appendNode(&list, 4);
    appendNode(&list, 14);
    appendNode(&list, -4);
    appendNode(&list, 7);
    appendNode(&list, 21);

    duplicatePositiveNodes(&list);
    printList(&list);
    */
    
    return 0;
}
