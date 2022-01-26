
#include "Sayi.hpp"

Sayi::Sayi() {
    number_size = 0;
    length = 0;
}   
// txt dosyasini okudugum metod.
string Sayi::tumTextDondur() {
    ifstream dosyaOku;
    string tumText;
    // dosyayi actim.
    dosyaOku.open("doc/veri.txt");
    while(!dosyaOku.eof()) { // dosyanin sonuna gelene kadar oku.
        dosyaOku >> tumText; // dosyayi tumText string'ine attım.
    }
    dosyaOku.close();
    return tumText;
}
int Sayi::sayininBoyutu() {
    number_size = (tumTextDondur().length()-1)/2;
    return number_size;
}
// txt dosyasindaki '#' karakterini sildigim metod.
string Sayi::kareleriSil(string text) {
    char c='#';
    string result;
   for (int i = 0; i < text.size(); i++) // txt'nin sonuna kadar gidecek olan for dongusu. karakter karakter okuyacak.
   {
    // dosyadaki her bir elemani aliyorum.
    char currentChar = text[i]; 
    // '#' karakterini gordugunde string'e almayacak.bu sekilde '#' karakterinden kurtuldum.
    if (currentChar != c)
        result += currentChar;
   }
    return result;
}
// eger yuzler basamagi 0 ise 1'e cevirdigim metod.
string Sayi::yuzlerBasamagiDegistir(string text) {
    // yuzler basamagini kontrol ettigim icin i'yi 3'er arttırıyorum.
    for(int i = 0; i< text.length(); i=i+3) {
        if(text[i] == '0') 
            text[i] = '1';
    }
    return text;
}
// dosyadaki sayilari 3 basamaki hale ayirdigim metod.
string* Sayi::SayiyiUcerliAyir(string tumText) {
    string* text = new string[tumText.length()];
    int j = 0;
    for(int i = 0; i<=tumText.length(); i+=3) {
        // substring metodu ile diziyi 3'erli ayirip text dizisine attim.
        text[j] += tumText.substr(i, 3);
        // cout<<text[j]<<" ";
        j++;
    }
    return text;
}
// subst metodunu kullanmak icin diziyi string olarak tutmuştum. bu metodda ise string dizinin her bir elemanini int diziye kopyaliyorum.
int* Sayi::SayiyiInteCevir(string kopyalanacakDizi[],int size) {
    int* text = new int[size];
    int n;
    // cout<<endl;
    for(int i = 0; i<size; i++) {
        stringstream stream(kopyalanacakDizi[i]); // stringstream ile string dizinin elemanlarini tek tek gezdim.
        while(stream >> n) { // n degiskenine yazdirdim
            text[i] = n;  // daha sonra elemanlari int diziye attim. 
            // cout<<n+1<<" ";
        }
    }
    return text;
}
// sayilari son haline getirip dondurdum.
int* Sayi::ilkSayiyiBul(string tumText) {
    tumText = kareleriSil(tumTextDondur());
    tumText =yuzlerBasamagiDegistir(tumText.substr(0,tumText.length()/2)); // textin '#' karakterini sildikten sonra yuzler basamagini degistirip txt'yi subst metoduyla ikiye boldum
    string* test = SayiyiUcerliAyir(tumText); // sayiyi diziye atmak icin 3 basamakli sekilde ayirdim.
    return SayiyiInteCevir(test,tumText.length()/3); // int diziye cevirdigim sayiyi dondurdum.
    delete test; // cop olusmamasi icin
}
int* Sayi::ikinciSayiyiBul(string tumText) {
    tumText = kareleriSil(tumTextDondur()); // textin '#' karakterini sildikten sonra yuzler basamagini degistirip txt'yi subst metoduyla ikiye boldum
    tumText =yuzlerBasamagiDegistir(tumText.substr(tumText.length()/2,tumText.length())); // sayiyi diziye atmak icin 3 basamakli sekilde ayirdim.
    string* test = SayiyiUcerliAyir(tumText);  // int diziye cevirdigim sayiyi dondurdum.
    return SayiyiInteCevir(test,tumText.length());
    delete test; // cop olusmamasi icin
}
// yikici metod
Sayi::~Sayi() {
    
}
