

#include "Islem.hpp"

Islem::Islem() {
    list = new Doublylinkedlist();
    list2 = new Doublylinkedlist();

    this->ilkSayi = NULL;
    this->ikinciSayi =  NULL;
}

void Islem::IslemleriYap() {
    // sayiyi bul dizinin her bir elemanini listeye at
    int* ilk_sayi = sayi->ilkSayiyiBul(sayi->tumTextDondur()); 
    list->arrayToList(ilk_sayi,(sayi->tumTextDondur().length()-1)/6);   
    // sayiyi bul dizinin her bir elemanini listeye at
    int* ikinci_sayi = sayi->ikinciSayiyiBul(sayi->tumTextDondur()); 
    list2->arrayToList(ikinci_sayi,(sayi->tumTextDondur().length()-1)/6);
    list->compareNodes(list,list2); // listeleri karsilastir.
    // listeleri yazdir.
    cout<<"Sayi 1 : ";
    list->print();
    cout<<"Sayi 2 : ";
    list2->print();
}
Islem::~Islem() {
    delete list;
    delete list2;
}