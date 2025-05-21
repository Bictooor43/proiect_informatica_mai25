#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

/// gurt: yo

struct elem{
    int info;
    int poz;
    elem *urm;
} *p, *prim, *ultim;

int n;

bool verifprim(int n){
    if( n < 2) return 0;
    if(n == 2) return 1;
    if(n % 2 == 0) return 0;
    for(int d = 3; d * d <= n ; d+=2)
        if(n %d == 0) return 0;
    return 1;
}

void citire_general(elem *&prim)
{
    std::cin >> n;

    prim = new elem;
    std::cin >> prim -> info;
    prim -> urm = NULL;
    ultim = prim;

    for(int i=2;i<=n;++i)
    {
        p = new elem;
        std::cin >> p -> info;
        p -> urm = NULL;
        ultim -> urm = p;
        ultim = p;
    }
}

void prelucrare_c6(elem *&prim)
{
    elem *p1,*prim1,*ultim1;
    bool okpar = 0;
    for(elem *p = prim ; p != NULL ;p = p -> urm)
    {
        if(p -> info % 2 == 0 && okpar == 0)
        {
            prim1 = new elem;
            prim1 -> info = p -> info;
            prim1 -> urm = NULL;
            ultim1 = prim1;
            okpar = 1;
        }
        else if(p -> info % 2 == 0 && okpar == 1)
        {
            p1 = new elem;
            p1 -> info = p -> info;
            p1 -> urm = NULL;
            ultim1 -> urm = p1;
            ultim1 = p1;
        }
    }
    for(elem *p = prim1 ; p != NULL ; p = p -> urm)
        std::cout << p -> info <<' ';
}

void prelucrare_p4b(elem *&prim){
    int nr = 0;
    for(elem *p = prim ; p != NULL ; p = p -> urm)
        if(verifprim(p -> info)) nr++;
    std::cout<<nr;
}

void prelucrare_p6(elem *&prim)
{
    bool verif=1;
    for(elem *p = prim ; p -> urm != NULL ; p=p ->urm)
        if(p -> info > p -> urm -> info) verif = 0;
    if(verif) std::cout<<"lista este ordonata crescator";
    else std::cout<<"lista nu este ordonata crescator";
}

void prelucrare_p8(elem *&prim){
    int s = 0;
    for(elem *p = prim ; p != NULL ; p = p -> urm)
        if(p->info%2==0) s+=p->info;
    std::cout<<s;
}

void prelucrare_s2(elem *&prim)
{
    int cnt=0;
    for(elem *p = prim; p != NULL ; p = p -> urm){
        cnt++, p -> poz = cnt;
        if(p -> poz == n-1)
        {
            elem *t = p -> urm;
            ultim = p;
            p -> urm = t -> urm;
            delete t;
        }
    }
    for(elem *p = prim ; p != NULL ; p = p ->urm)
        std::cout<< p -> info << ' ';
}

void prelucrare_s7(elem *&prim)
{
    int cnt=0;
    for(elem *p = prim ; p != NULL; p = p -> urm)
        cnt++, p ->poz = cnt;
    for(elem *p = prim -> urm; p != NULL ; p = p ->urm)
        if(p -> poz % 2 == 0)
        {
            elem *t = p ->urm;
            p -> urm = t -> urm;
            delete t; 
        }
    elem *t = prim;
    prim = prim -> urm;
    delete t;
    for(elem *p = prim ; p != NULL; p = p -> urm)
        std::cout << p -> info << ' ';
}

void prelucrare_s8(elem *&prim){
    int nr = 0;
    for(elem* p = prim; p!=NULL; p=p->urm)
        nr++;
    if(nr%2==0){
        elem* p = prim; int i=1;
        while(i<n/2-1){
            p=p->urm; i++;
        }
        elem* x = p->urm; elem* y = x->urm;
        p->urm = y->urm;
        x->urm = NULL; y->urm = NULL;
    }
    else{
        elem* p = prim; int i=1;
        while(i<n/2){
            p=p->urm; i++;
        }
        elem* x = p->urm;
        p->urm = x->urm;
        x->urm = NULL;
    }
    for(elem *p = prim ; p != NULL ; p = p -> urm)
        std::cout << p -> info <<' ';
}

void prelucrare_m7(elem *&prim)
{
    int cnt=0,aux;
    for(elem *p = prim ; p != NULL; p = p -> urm)
    {
        cnt++, p -> poz = cnt;
        if(p -> poz == n) aux = p -> info;
    }
    for(elem *p = prim ; p != NULL; p = p -> urm)
        if(p -> poz == n-1)
        {
            elem *t = p -> urm;
            p -> urm = t -> urm;
            delete t;
        }
    elem *t1 = new elem;
    t1 -> info = aux;
    t1 -> urm = prim;
    prim = t1;

    for(elem *p = prim ; p != NULL; p = p -> urm)
        std::cout << p -> info << ' ';
}

void prelucrare_m8(elem *&prim)
{
    elem *pi=prim, *pj=prim; 
    while (pi != NULL)
    {
        pj = pi -> urm;
        while ( pj != NULL)
        {
            if (pi -> info > pj -> info) std::swap(pi -> info, pj -> info);
            pj = pj -> urm;
        }
    pi = pi -> urm;
}

    for(elem *p = prim ; p != NULL ; p = p ->urm)
        std::cout<< p -> info << ' ';
}

void prelucrare_m12(elem *&prim)
{
    elem *prim1, *prim2, *ultim1, *ultim2, *p1;
    bool okpar=false,okimp=false;

    for(elem *p = prim ; p != NULL ;p = p -> urm) ///parcurgem lista pt a identifica elementele pare si a le pune in lista noua
    {
        if(p -> info % 2 == 0 && okpar == 0)
        {
            prim1 = new elem;
            prim1 -> info = p -> info;
            prim1 -> urm = NULL;
            ultim1 = prim1;
            okpar = 1;
        }
        else if(p -> info % 2 == 0 && okpar == 1)
        {
            p1 = new elem;
            p1 -> info = p -> info;
            p1 -> urm = NULL;
            ultim1 -> urm = p1;
            ultim1 = p1;
        }
    }
    for(elem *p = prim1 ; p != NULL ; p = p -> urm) ///parcurgem lista pt a identifica elementele imppare si a le pune in lista noua
        std::cout << p -> info <<' ';
    
    std::cout << '\n';

    for(elem *p = prim ; p != NULL ;p = p -> urm)
    {
        if(p -> info % 2 != 0 && okimp == 0)
        {
            prim2 = new elem;
            prim2 -> info = p -> info;
            prim2 -> urm = NULL;
            ultim2 = prim2;
            okimp = 1;
        }
        else if(p -> info % 2 != 0 && okimp == 1)
        {
            p1 = new elem;
            p1 -> info = p -> info;
            p1 -> urm = NULL;
            ultim2 -> urm = p1;
            ultim2 = p1;
        }
    }
    for(elem *p = prim2 ; p != NULL ; p = p -> urm)
        std::cout << p -> info <<' ';

}

class Menu  {

private:

    bool shouldStop;
    std::string userInput;

public:

    Menu() {
        citire_general(prim);
        shouldStop = 0;
    }

    void printMenu() {
        system("cls");
        std::cout << "-------------------\n [TIPUL DE CITIRE]\n-------------------\n\n";
        std::cout << "1. Parcurgerea listelor liniare\n";
        std::cout << "2. Stergeri in liste liniare\n";
        std::cout << "3. Modificarea listelor liniare\n";
        std::cout << "4. Crearea listelor liniare\n";
        std::cout << "\n---------------------------\n [CUM FORMATATI COMENZILE]\n---------------------------\n";
        std::cout << "Pasul 1: Alegeti tipul de operatie pe care doriti sa il efectuati: Parcurgere, Stergere sau Modificare.\n";
        std::cout << "Pasul 2: Dupa ce submeniul a fost deschis, alegeti in ce maniera doriti sa se efectueze operatia. Veti tasta\n        exclusiv numarul de ordine al modalitatii dorite.\n";
        std::cout << "Pasul 3: Pentru a va intoarce la meniul principal, tastati: back .\n";
        std::cout << "\n** Daca doriti sa parasiti consola, tastati in orice moment: exit . **\n";
    }

    void startParcurgere() {
        system("cls");
        std::cout << "--------------\n [PARCURGERE]\n--------------\n";

        std::cout << "4.b. Determinati numarul de numere prime\n";
        std::cout << "6. Verificati daca in lista numerele sunt ordonate crescator\n";
        std::cout << "8.a. Calculati suma numerelor de rang par\n";

        std::cout << "\nTastati comanda dorita: ";
        std::cin >> userInput;

        if (userInput == "exit")
            exit(0);
        else if (userInput == "4b" || userInput == "4.b" || userInput == "4.b.") {
            system("cls");
            prelucrare_p4b(prim);
            std::cout << "\nTastati comanda dorita: ";
            std::cin >> userInput;
        }
        else if(userInput == "6"){
            system("cls");
            prelucrare_p6(prim);
            std::cout << "\nTastati comanda dorita: ";
            std::cin >> userInput;            
        }
        else if(userInput == "8a" || userInput == "8.a" || userInput == "8.a."){
            system("cls");
            prelucrare_p6(prim);
            std::cout << "\nTastati comanda dorita: ";
            std::cin >> userInput;
        }
        return ;
    }

    void startStergere() {
        system("cls");
        std::cout << "------------\n [STERGERE]\n------------\n";

        std::cout<<"2. Stergeti ultimul element\n";
        std::cout<<"7. Stergeti elementele de rang impar\n";
        std::cout<<"8. Stergeti elementele/elementul din mijloc\n";

        std::cout << "\nTastati comanda dorita: ";
        std::cin >> userInput;

        if (userInput == "exit")
            exit(0);
        else if (userInput == "2") {
            system("cls");
            prelucrare_s2(prim);
            std::cout << "\nTastati comanda dorita: ";
            std::cin >> userInput;
        }
        else if (userInput == "7"){
            system("cls");
            prelucrare_s7(prim);
            std::cout << "\nTastati comanda dorita: ";
            std::cin >> userInput;            
        }
        else if (userInput == "8"){
            system("cls");
            prelucrare_s8(prim);
            std::cout << "\nTastati comanda dorita: ";
            std::cin >> userInput;
        }
        return ;
    }

    void startModificare() {
        system("cls");
        std::cout << "--------------\n [MODIFICARE]\n--------------\n";

        std::cout<<"7.Mutati ultimul element la inceput\n";
        std::cout<<"8.Ordonati crescator lista (selectia minimului, bubble sort)\n";
        std::cout<<"12.Rupeti o lista in doua liste (valori pare/impare)\n";

        std::cout << "\nTastati comanda dorita: ";
        std::cin >> userInput;

        if (userInput == "exit")
            exit(0);
        else if (userInput == "7") {
            system("cls");
            prelucrare_m7(prim);
            std::cout << "\nTastati comanda dorita: ";
            std::cin >> userInput;
        }
        else if (userInput == "8"){
            system("cls");
            prelucrare_m8(prim);
            std::cout << "\nTastati comanda dorita: ";
            std::cin >> userInput;            
        }
        else if (userInput == "12"){
            system("cls");
            prelucrare_m12(prim);
            std::cout << "\nTastati comanda dorita: ";
            std::cin >> userInput;
        }
        return ;
    }

    void startCreare() {
        system("cls");
        std::cout << "--------------\n [CREARE]\n--------------\n";

        std::cout<<"6. Sa creeze o lista care sa contina numere pare dintr-o lista creata anterior";

        std::cout<<"\nTastati comanda dorita: ";
        std::cin >> userInput;

        if (userInput == "exit")
            exit(0);
        else if(userInput == "6") {
            system("cls");
            prelucrare_c6(prim);
            std::cout << "\nTastati comanda dorita: ";
            std::cin >> userInput;
        }
        return ;
    }
    void processInput() {
        if (userInput == "exit") {
            shouldStop = 1;
            exit(0);
        }
        else if (userInput == "Parcurgere" || userInput == "parcurgere") {
            startParcurgere();
            return ;
        }
        else if (userInput == "Stergere" || userInput == "stergere") {
            startStergere();
            return ;
        }
        else if (userInput == "Modificare" || userInput == "modificare") {
            startModificare();
            return ;
        }
        else if(userInput == "Creare" || userInput == "modificare") {
            startCreare();
            return ;
        }
        return ;
    }

    void start() {
        printMenu();
        for (; ! shouldStop; ) {
            std::cout << "\nTastati comanda dorita: ";
            std::cin >> userInput;
            processInput();
            printMenu();
        }
        return ;
    }

};
int main() {
    Menu menu;
    menu.start();
    return 0;
}
