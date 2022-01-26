#ifndef SAYI_HPP
#define SAYI_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class Sayi {
private:
    int number_size; // sayilarin karakter sayisini tutan degisken.
    int length;
public:
    Sayi(); // kurucu metod
    string tumTextDondur(); // txt dosyasini dondurdugum metod
    int sayininBoyutu(); // txt dosyasindaki sayinin eleman adeti
    string kareleriSil(string); // txt dosyasindaki '#' karakterini sildigim metod
    string yuzlerBasamagiDegistir(string); // yuzler basamagindaki rakam 0 ise 1 yaptigim metod
    string* SayiyiUcerliAyir(string); // sayilari 3'erli ayirdigim metod
    int* SayiyiInteCevir(string*,int); // split, subst gibi string metodlarla sayiyi 3erli ayirdiktan sonra string dizimin elemanlarini int diziye kopyaladigim metod 
    // sayilari son haline getirip dondurdugum metolar
    int* ilkSayiyiBul(string);
    int* ikinciSayiyiBul(string);
    ~Sayi();
};

#endif