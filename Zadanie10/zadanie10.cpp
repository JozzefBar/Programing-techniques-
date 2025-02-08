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
#include <iomanip>
#include <cassert>
#include <list>
#include <map>
#include <queue>
#include <ranges>
#include <stack>
#include <set>
#include <deque>
#include <algorithm>
#include <limits>

using namespace std;

//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Upravte definiciu metody 'T::met()' tak, aby informovala, ze metoda nemeni stav objektu.

    Pre kontrolu odkomentujte riadok v testovacej funkcii. Odkomentovany riadok musi byt kompilovatelny.
*/

class T {
public:
    void met() const {}
};

void testUloha1() {
    cout << "----- 1. uloha (metoda nemeni stav objektu) ------------------------------------" << endl;
    const T o;
    o.met(); // odkomentujte
}

//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Upravte definiciiu konstruktora tak, aby bol konverznym konstruktorom.

    Zakomentovane riadky v testovacom kode musia byt kompilovatelne.
*/

class Number {
private:
    int number;
public:
    Number(int value) : number(value){
    }
    int getValue() const {
        return number;
    }
};

void fun(Number n) {
    cout << n.getValue() << endl;
}

void testUloha2() {
    cout << "----- 2. uloha (konverzny konstruktor) -----------------------------------------" << endl;

    Number a = 10; // ak existuje zodpovedajuci konverzny konstruktor, tak je tento riadok kompilovatelny
    cout << a.getValue() << endl;

    fun(20); // ak existuje zodpovedajuci konverzny konstruktor, tak je tento riadok kompilovatelny
}

//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Vytvorte triedu 'B', ktora je podtriedou triedy 'A'.
    Upravte definiciu metody 'A::met()' a definujte metodu 'B::met()' tak,
    aby bol testovaci kod po odkomentovani uspesne vykonany (aby bola vzdy volana spravna metoda).
*/

class A {
public:
    virtual char met() const{
        return 'a';
    }
};

class B : public A{
public:
    char met() const override {
        return 'b';
    }
};

void testUloha3() {
    cout << "----- 3. uloha (volanie spravnej metody) ---------------------------------------" << endl;

    A a;
    B b;

    A *pa  = &a;
    A *pab = &b;
    B* pb  = &b;

    assert(pa->met()  == 'a'); // volanie A::met()
    assert(pab->met() == 'b'); // volanie B::met()
    assert(pb->met()  == 'b'); // volanie B::met()
}

//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Upravte definicie destruktorov tried 'C' a 'D' tak, aby sa v testovacej funkcii zavolal spravny destruktor.
    Testovacia funkcia musi namiesto:
        C::~C()
    po uprave vypisat:
        D::~D()
        C::~C()
*/

class C {
public:
    virtual ~C() {
        cout << "C::~C()" << endl;
    }
};

class D : public C {
public:
    ~D() {
        cout << "D::~D()" << endl;
    }
};

void testUloha4() {
    cout << "----- 4. uloha (volanie spravneho destruktora) ---------------------------------" << endl;
    C *obj = new D;
    delete obj; // aby sa zavolal spravny detruktor
}

//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Vytvorte operator +=, ktory bude sluzit pre pripocitanie druheho komplexneho cisla ku prvemu.
    Operator definujte ako clena triedy.

    Pre kontrolu odkomentujte riadky v testovacom kode, kde je priklad pouzitia operatora.
*/

class Complex {
private:
    int real;
    int imaginary;
public:
    Complex(int realPart, int imaginaryPart)
    : real(realPart)
    , imaginary(imaginaryPart) {
    }
    int getRealPart() const {
        return real;
    }
    int getImaginaryPart() const {
        return imaginary;
    }
    Complex& operator += (const Complex& other){
        real += other.real;
        imaginary += other.imaginary;
        return *this;
    }
};

void testUloha5() {
    cout << "----- 5. uloha (operator +=) ---------------------------------------------------" << endl;

    Complex a(1,2);
    Complex b(10, 20);
    Complex c(100, 200);

    c += b += a;

    assert(a.getRealPart() == 1);
    assert(a.getImaginaryPart() == 2);
    assert(b.getRealPart() == 11);
    assert(b.getImaginaryPart() == 22);
    assert(c.getRealPart() == 111);
    assert(c.getImaginaryPart() == 222);
}

//-------------------------------------------------------------------------------------------------
// 6. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Vytvorte operator <<, ktory zapise hodnotu objektu triedy 'Complex' (z predchadzajuceho prikladu)
    do textoveho prudu dat.
    Poznamka: Operator musi byt definovany ako globalny.

    Pre kontrolu odkomentujte riadky v testovacom kode.
*/

ostream& operator<<(ostream& os, const Complex& c) {
    os << c.getRealPart();
    if (c.getImaginaryPart() >= 0) {
        os << "+" << c.getImaginaryPart() << "i";
    } else {
        os << c.getImaginaryPart() << "i";
    }
    return os;
}


void testUloha6() {
    cout << "----- 6. uloha (operator << ) --------------------------------------------------" << endl;

    Complex a( 1, 2);
    Complex b(-3,-4);
    cout << "a = " << a << ", b = " << b << endl;

    ostringstream stream;
    stream << a << " " << b;
    assert(stream.str() == "1+2i -3-4i");
}

//=================================================================================================
// STROM - definicia pre dalsie ulohy
//=================================================================================================

// Uzol stromu
struct Node {
    char value; // hodnota uzla
    list<Node*> children; // zoznam nasledovnikov

    explicit Node(char value) : value(value) {}
};

// Strom
struct Tree {
    Node * root; // koren stromu

    explicit Tree(Node *root = nullptr) : root(root) {}
};

//-------------------------------------------------------------------------------------------------
// 7. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati zoznam vsetkych hodnot uzlov v strome 'tree', ktorych hodnotou je velke pismeno.
    Pouzite algoritmus hladania DO HLBKY.
    Pouzite iterativnu implementaciu.
    Doporucenie: pre identifikaciu velkych pismen pouzite funkciu 'std::isupper'

    VSTUPNA HODNOTA:
        [in] tree - prehladavany strom

    NAVRATOVA HODNOTA:
        zoznam velkych pismen, ktore su hodnotami uzlov v strome 'tree'

    VYSTUPNA PODMIENKA:
        Poradie vo vystupnom zozname musi zodpovedat postupnosti prehladavania algoritmom DO HLBKY.

    PRIKLAD:
        na obrazku
*/

list<char> depthFirstSearchUpperCases(const Tree *tree) {
    list<char> new_list;

    if (tree == nullptr || tree->root == nullptr) {
        return new_list;
    }

    stack<Node*> s;
    s.push(tree->root);

    while(!s.empty()){
        Node* current = s.top();
        s.pop();

        if (isupper(current->value)) {
            new_list.push_back(current->value);
        }

        for (auto &it : current->children) {
            s.push(it);
        }
    }
    return new_list;
}

//-------------------------------------------------------------------------------------------------
// 8. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati zoznam vsetkych hodnot uzlov v strome 'tree', ktorych hodnotou je velke pismeno.
    Pouzite algoritmus hladania DO SIRKY.
    Pouzite iterativnu implementaciu.
    Doporucenie: pre identifikaciu velkych pismen pouzite funkciu 'std::isupper'

    VSTUPNA HODNOTA:
        [in] tree - prehladavany strom

    NAVRATOVA HODNOTA:
        zoznam velkych pismen, ktore su hodnotami uzlov v strome 'tree'

    VYSTUPNA PODMIENKA:
        Poradie vo vystupnom zozname musi zodpovedat postupnosti prehladavania algoritmom DO SIRKY.

    PRIKLAD:
        na obrazku
*/

list<char> breadthFirstSearchUpperCases(const Tree *tree) {
    list<char> new_list;

    if (tree == nullptr || tree->root == nullptr) {
        return new_list;
    }

    queue<Node*> q;
    q.push(tree->root);

    while(!q.empty()){
        Node* current = q.front();
        q.pop();

        if (isupper(current->value)) {
            new_list.push_back(current->value);
        }

        for (auto &it : current->children) {
            q.push(it);
        }
    }

    return new_list;
}

//=================================================================================================
// GRAF - definicia pre dalsie ulohy
//=================================================================================================
// Graf reprezentuje cestnu siet medzi obcami na planete.
// Uzol grafu reprezentuje obec.
// Hrana grafu reprezentuje "priame" cestne spojenie z jednej obce do druhej.
// Graf je orientovany - Hrana grafu reprezentuje moznost jazdy len jednym smerom.
//   Preto je moznost "priamej" jazdy medzi obcami oboma smermy reprezentovana dvoma hranami grafu.
// Graf je ohodnoteny - Mapa cestnej siete eviduje dlzky "priamych" cestnych spojeni medzi obcami.
// Obce nemusia byt prepojene cestnou sietou, napriklad ak sa nachadzaju na roznych pevninach.

// Forward deklaracie su potrebne, pretoze:
//  - definicie 'City' a 'RoadTo' su cyklicky zavisle:
//      - v definicii 'City' je pouzite 'RoadTo'
//      - a v definicii 'RoadTo' je pouzite 'City'
//  - definicie 'City' a 'SearchData' su cyklicky zavisle:
//      - v definicii 'City' je pouzite 'SearchData'
//      - a v definicii 'SearchData' je pouzite 'City'
struct RoadTo;
struct City;

// Udaje pouzite v algoritmoch hladania
struct SearchData {
    // Mozete si doplnit dalsie atributy a metody, ktore pouzijete v algoritmoch hladania
    bool discovered;
    unsigned distance;
    const City *previous;
    bool foundShortestPath;

    void clear() { // nastavi na implicitne hodnoty (tuto metodu mozete upravit (ale nie jej deklaracnu cast - nedoplnajte parametre))
        discovered = false;
        distance = numeric_limits<unsigned>::max();
        previous = nullptr;
        foundShortestPath = false;
    }
};

// Obec (uzol grafu)
struct City {
    string name; // nazov obce
    list<RoadTo> roads; // zoznam "priamych" jednosmernych cestnych spojeni do dalsich obci (zoznam vystupnych hran z tohto uzla grafu)

    SearchData searchData; // udaje pouzite v algoritmoch hladania

    // Mozete doplnit dalsi konstruktor alebo metody, ale tento konstruktor nemente
    explicit City(string name) : name(move(name)) {
        searchData.clear();
    };
};

// Jednosmerne "priame" cestne spojenie do dalsej obce (orientovana, ohodnotena hrana grafu)
struct RoadTo {
    City *city; // obec, do ktorej je toto "priame" cestne spojenie
    unsigned length; // dlzka tohto "priameho" spojenia

    // Mozete doplnit dalsi konstruktor alebo metody, ale tento konstruktor nemente
    RoadTo(City *city, unsigned length)
    : city(city)
    , length(length) {
    }
};

// Cestna mapa planety (orientovany, ohodnoteny graf)
struct Planet {
    list<City> cities; // zoznam obci na planete (zoznam vrcholov grafu)

    void clearSearchData() { // inicializuje atributy pouzite v algoritme hladania
        for(City &c : cities) {
            c.searchData.clear();
        }
    }
};

// Vyminka v pripade neexistencie obce so zadanym nazvom
class CityNotExistsException : exception {
    string cityName; // nazov obce
public:
    explicit CityNotExistsException(string name)
    : cityName(move(name)) {
    }
    const char * what() const noexcept override { // vrati nazov neexistujucej obce
        return cityName.c_str();
    }
};

//-------------------------------------------------------------------------------------------------
// 9. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati zoznam nazvov vsetkych obci na planete 'planet',
    ktore su z obce s nazvom 'startCity' dosiahnutelne pomocou cestnej siete.
    Pouzite algoritmus hladania DO SIRKY.

    VSTUPNA HODNOTA:
        [in] planet - cestna siet na planete
        [in] startCity - nazov obce

    NAVRATOVA HODNOTA:
        zoznam nazvov vsetkych obci, dosiahnutelnych z obce 'startCity'

    VYNIMKA:
        CityNotExistsException - ak na planete 'planet' neexistuje obec s nazvom 'startCity'.
        Metoda 'CityNotExistsException::what()' vrati nazov neexistujucej obce (hodnota 'startCity').

    VYSTUPNE PODMIENKY:
        Vystupny zoznam obsahuje aj 'startCity'.
        Poradie vo vystupnom zozname musi zodpovedat postupnosti prehladavania algoritmom DO SIRKY.

    PRIKLAD:
        na obrazku

    POZNAMKA:
        Ak v implementacii pouziteje 'City::searchData',
        tak bude pravdepodobne potrebne na zaciatku zavolat 'planet->clearSearchData()',
        aj aby bolo osetrene viacnasobne volanie algoritmu s tym istym objektom 'planet'.
*/

list<string> breadthFirstSearchReachable(Planet * planet, const string & startCity) {
    auto it = find_if(planet->cities.begin(), planet->cities.end(),
                      [&startCity](const City &city) { return city.name == startCity; });
    if(it == planet->cities.end()) throw CityNotExistsException(startCity);

    planet->clearSearchData();
    queue<City*> q;
    list<string> reachableCities;

    City* start = &(*it);
    start->searchData.discovered = true;
    q.push(start);
    reachableCities.push_back(start->name);

    while(!q.empty()) {
        City *current = q.front();
        q.pop();

        for (const RoadTo &road: current->roads) {
            City *neighbor = road.city;
            if (!neighbor->searchData.discovered) {
                neighbor->searchData.discovered = true;
                q.push(neighbor);
                reachableCities.push_back(neighbor->name);
            }
        }
    }

    return reachableCities;
}

//-------------------------------------------------------------------------------------------------
// 10. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia najte dlzky najkratsich ciest z obce 'startCity' do vsetkych dosiahnutelnych obci.
    Pouzite Dijkstrov algoritmus.

    VSTUPNE HODNOTY:
        [in] planet - cestna siet na planete
        [in] startCity - nazov obce

    NAVRATOVA HODNOTA:
        Pre kazdu obec dosiahnutelnu zo 'startCity' (na planete 'planet') obsahuje dlzku najkratsej cesty zo 'startCity'.

    VYNIMKA:
        CityNotExistsException - ak na planete 'planet' neexistuje obec s nazvom 'startCity'.
        Metoda 'CityNotExistsException::what()' vrati nazov neexistujucej obce (hodnota 'startCity').

    VYSTUPNA PODMIENKA:
        Navratova hodnota obsahuje nazvy len tych miest, ktore su dosiahnutelne zo 'startCity'.
        Navratova hodnota obsahuje aj vzdialenost do 'startCity' (nula).

    PRIKLAD:
        na obrazku

    POZNAMKA:
        Ak v implementacii pouziteje 'City::searchData',
        tak bude pravdepodobne potrebne na zaciatku zavolat 'planet->clearSearchData()',
        aj aby bolo osetrene viacnasobne volanie algoritmu s tym istym objektom 'planet'.
*/

map<string, unsigned> dijkstra(Planet * planet, const string & startCity) {
    auto it = find_if(planet->cities.begin(), planet->cities.end(),
                      [&startCity](const City &city) { return city.name == startCity; });
    if(it == planet->cities.end()) throw CityNotExistsException(startCity);

    map<string, unsigned> distanceMap;
    planet->clearSearchData();

    City* start = &(*it);
    queue<City*> q;
    start->searchData.discovered = true;
    start->searchData.distance = 0;
    distanceMap[start->name] = 0;

    q.push(start);

    while(!q.empty()) {
        City* currentCity = q.front();
        q.pop();

        for (const RoadTo &road : currentCity->roads) {
            City* neighbor = road.city;

            unsigned newDistance = currentCity->searchData.distance + road.length;

            if (!neighbor->searchData.discovered || newDistance < neighbor->searchData.distance) {
                neighbor->searchData.distance = newDistance;
                neighbor->searchData.discovered = true;

                distanceMap[neighbor->name] = newDistance;
                q.push(neighbor);
            }
        }
    }

    return distanceMap;
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

// tu mozete doplnit pomocne funkcie a struktury

void testUloha9() {
    Planet planet;
    // Create cities
    planet.cities.emplace_back("London");
    planet.cities.emplace_back("Wisdon");
    planet.cities.emplace_back("Melon");
    planet.cities.emplace_back("Tilon");
    planet.cities.emplace_back("Lion");
    planet.cities.emplace_back("Billon");
    planet.cities.emplace_back("Turbilon");
    planet.cities.emplace_back("Nylon");
    planet.cities.emplace_back("Guildon");
    planet.cities.emplace_back("Gaučon");
    planet.cities.emplace_back("Tigron");
    planet.cities.emplace_back("Etalon");

    // Find cities for connections
    City *london = nullptr, *wisdon = nullptr, *melon = nullptr, *tilon = nullptr,
            *lion = nullptr, *billon = nullptr, *turbilon = nullptr, *nylon = nullptr,
            *guildon = nullptr, *gaucon = nullptr, *tigron = nullptr, *etalon = nullptr;

    for (City &city : planet.cities) {
        if (city.name == "London") london = &city;
        else if (city.name == "Wisdon") wisdon = &city;
        else if (city.name == "Melon") melon = &city;
        else if (city.name == "Tilon") tilon = &city;
        else if (city.name == "Lion") lion = &city;
        else if (city.name == "Billon") billon = &city;
        else if (city.name == "Turbilon") turbilon = &city;
        else if (city.name == "Nylon") nylon = &city;
        else if (city.name == "Guildon") guildon = &city;
        else if (city.name == "Gaučon") gaucon = &city;
        else if (city.name == "Tigron") tigron = &city;
        else if (city.name == "Etalon") etalon = &city;
    }

    // Connect cities (add roads)
    london->roads.emplace_back(wisdon, 0);
    london->roads.emplace_back(melon, 0);

    wisdon->roads.emplace_back(tilon, 0);
    wisdon->roads.emplace_back(lion, 0);

    melon->roads.emplace_back(lion, 0);
    melon->roads.emplace_back(billon, 0);

    tilon->roads.emplace_back(turbilon, 0);

    lion->roads.emplace_back(nylon, 0);

    nylon->roads.emplace_back(wisdon, 0);

    guildon->roads.emplace_back(gaucon, 0);
    guildon->roads.emplace_back(nylon, 0);

    etalon->roads.emplace_back(tigron, 0);

    turbilon->roads.emplace_back(melon, 0);

    list<string> output = breadthFirstSearchReachable(&planet, "London");
    cout << "{ ";
    for (auto &it : output) {
        cout << it << ", ";
    }
    cout << "}\n";
}

void testUloha10() {
    Planet planet;
    // Create cities
    planet.cities.emplace_back("London");
    planet.cities.emplace_back("Haron");
    planet.cities.emplace_back("Pecelon");
    planet.cities.emplace_back("Ballon");
    planet.cities.emplace_back("Nicudon");
    planet.cities.emplace_back("Etalon");
    planet.cities.emplace_back("Tigron");

    // Find cities for connections
    City *london = nullptr, *haron = nullptr, *pecelon = nullptr, *ballon = nullptr,
            *nicudon = nullptr, *etalon = nullptr, *tigron = nullptr;

    for (City &city : planet.cities) {
        if (city.name == "London") london = &city;
        else if (city.name == "Haron") haron = &city;
        else if (city.name == "Pecelon") pecelon = &city;
        else if (city.name == "Ballon") ballon = &city;
        else if (city.name == "Nicudon") nicudon = &city;
        else if (city.name == "Etalon") etalon = &city;
        else if (city.name == "Tigron") tigron = &city;
    }

    // Connect cities (add roads)
    london->roads.emplace_back(haron, 10);
    london->roads.emplace_back(pecelon, 40);
    london->roads.emplace_back(nicudon, 100);

    haron->roads.emplace_back(pecelon, 20);

    pecelon->roads.emplace_back(nicudon, 50);
    pecelon->roads.emplace_back(ballon, 10);

    ballon->roads.emplace_back(nicudon, 50);
    ballon->roads.emplace_back(haron, 15);

    etalon->roads.emplace_back(tigron, 10);

    map<string, unsigned> output = dijkstra(&planet, "London");
    cout << "{ ";
    for (auto &it : output) {
        cout << it.first << ": " << it.second << ", ";
    }
    cout << "}\n";
}

int main() {
    testUloha1();
    testUloha2();
    testUloha3();
    testUloha4();
    testUloha5();
    testUloha6();

    // tu mozete doplnit testovaci kod

    testUloha9();
    testUloha10();

    return 0;
}
