#ifndef ISLEM_HPP
#define ISLEM_HPP
#include "Sayi.hpp"
#include "Doublylinkedlist.hpp"

class Islem {
private:
    Sayi *sayi;
    int* ilkSayi;
    int* ikinciSayi;
    Doublylinkedlist *list;
    Doublylinkedlist *list2;
public:
    Islem();
    void IslemleriYap();
    ~Islem();
};

#endif