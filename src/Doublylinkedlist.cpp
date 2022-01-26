

#include "Doublylinkedlist.hpp"

//constructor
Doublylinkedlist::Doublylinkedlist() {
    head = NULL;
    tail = NULL;
}
// liste bos mu dolu mu kontrolu yapan metod
bool Doublylinkedlist::IsEmpty() {
    return size == 0;
}
// listenin sonuna eleman ekleyen metod
void Doublylinkedlist::push(int newElement) {
    Node* newNode = new Node(); // bos dugum
    newNode->data = newElement; // bos dugumun data'si parametre olarak gelen eleman olacak
    if(head == NULL) // listede eleman yok demektir.
        head = newNode; // listenin basina dugumu ekle
    else { // liste bos degilse
    Node* temp = head; // temp'i listenin basindan baslat
    while(temp->next != NULL) // listenin sonuna kadar git. cunku sona eleman ekliyorum
        temp = temp->next; // temp'i bir ilerlet
    temp->next = newNode;
    newNode->prev = temp;
    tail = temp->next; // listenin sonunu isaret eden tail
    }
}
// listeyi yazdirdigim metod.
void Doublylinkedlist::print() {
    Node* p = head; // p pointer'ini listenin en basina aldim
    while(p != NULL) { // p = NULL olana kadar listeyi gez ve liste elemanlarini yazdir.
        cout<<p->data;
        p = p->next;
    }
    cout<<endl;
}
// listeyi ters cevirdigim metod.
Node* Doublylinkedlist::reverseList() {
    Node* cur = head;
    if(cur->next == NULL) return head; // listede tek eleman var demektir.
    while(cur->next != NULL) // listenin basindan baslayan pointer'i listenin sonuna kadar ilerlet
        cur = cur->next;
        // next-prev'i degistir ve bir ilerlet
    head=cur;
    cur->next=cur->prev;
    cur->prev = NULL;
    cur = cur->next;
    // geriye dogru git
    while(cur->prev != NULL) {
        Node* tmp = cur->next;  // uzerinde oldugum dugumu ilerisini gosterecek pointer
        // dugumlerin yerini degistir.
        cur->next = cur->prev;
        cur->prev = tmp;
        cur = cur->next;
    }
    cur->prev = cur->next;
    cur->next = NULL;
    return head;
}
// int dizimin her bir elemanini listeye atiyorum. n = eleman sayisi
void Doublylinkedlist::arrayToList(int* array, int n) {
    for(int i = 0; i<n; i++) {
        push(array[i]);
        size++;
    }
}
// dugumleri degistirme metodu
void Doublylinkedlist::swapNodes(Node* first, Node* second) {
    // degistirilecek dugumler listenin sonundaysa bu kontrole girecek.
    if(first->next == NULL && second->next == NULL) { // eleman->next->prev'i olmaz. cunku son elemanin next'i NULL olacak. 
        // dugumleri tek tek degistirdim.
        first->prev->next = second;
        second->prev->next = first;
        Node* gecici = first->prev; // gerisini kaybetmemek icin bir pointer'in orayi göstermesini sagladim.
        first->prev = second->prev;
        second->prev = gecici;
    }
    // degistirilecek elemanlar listenin basindaysa.
    else if(first->prev == NULL && second->prev == NULL) { // yapamadim
        // cout<<"degistirilecek elemanlar basta..."<<endl;
    }
    // degistirilecek elemanlar listenin ortasindaysa
    else {
        // dugumleri tek tek degistirdim.
        first->prev->next = second;
        second->next->prev = first;
        first->next->prev = second;
        // olusturdugum gecici dugumleri ile degistirmek istedigim dugumun ilerisini ve gerisini kaybetmemis oldum.
        Node* gecici = first->next;
        first->next = second->next;
        second->next = gecici;

        second->prev->next = first;
        Node* gecici2 = first->prev;
        first->prev = second->prev;
        second->prev = gecici2;
    }
}
// dugumleri esit, kucuk yada buyuk olma durumlarina gore karsilastirdigim metod
void Doublylinkedlist::compareNodes(Doublylinkedlist* firstList,Doublylinkedlist* SecondList) {
    int kac_kere = 0; // dongunun kac kez dondugunu tutmak icin olusturdugum degisken
    // listelerin head'lerini gosterecek pointerlar tanimladim
    Node* temp1 = firstList->head;
    Node* temp2 = SecondList->head;
    while(temp1 != NULL && temp2 != NULL)  { // listenin elemanlarini tek tek gezecek dongu
        kac_kere++;
        if(temp1->data > temp2->data) { // ilk listedeki dugumun data'si daha buyukse
            firstList->reverseList(); // ilk listeyi ters cevir
            while(temp1->prev != NULL) { // listeyi ters cevirdigimde temp listenin sonunu isaret ettigi icin temp'i listenin basina aliyorum
                temp1 = temp1->prev;
            }
        }
        else if(temp1->data < temp2->data) { // ikinci listedeki dugumun data'si daha buyukse
            swapNodes(temp1,temp2); // dugumleri degistir.
            // dugumlerin yeri degistikten sonra dugumleri isaret eden temp1 ve temp2 degiskenleri birbirlerinin listesini gosteriyor. tekrar kendi listelerini gostermeleri icin gecici bir pointer yardimiyla gosterdikleri yerleri degistiriyorum.
            Node* gecici = temp1;
            temp1=temp2;
            temp2=gecici;
        }
        else if(temp1->data == temp2->data) { // dugumlerin data'lari birbirine esitse
            SecondList->reverseList(); // ikincilisteyi ters cevir.
            while(temp2->prev != NULL) { // listeyi ters cevirdigimde temp listenin sonunu isaret ettigi icin temp'i listenin basina aliyorum
                temp2 = temp2->prev; // listenin basina gelene kadar temp'i geriye al
            }
        }
        // dongu her dondugunde temp'leri bir ilerlet.
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
}
// sondan eleman silme metodu
void Doublylinkedlist::pop_back() {
  if(head != NULL) {
    // head null degilse next'ine git
    // head null ise head'i serbest birak
    if(head->next == NULL) {
      head = NULL;
    } 
    else {
        Node* temp = head;
        while(temp->next->next != NULL)
            temp = temp->next;

        // son dugumu null'a getir ve serbest birak.
        Node* lastNode = temp->next;
        temp->next = NULL;
        delete lastNode; 
    }
  }
  size--;
}
Doublylinkedlist::~Doublylinkedlist() {
    // cop kalmamasi icin liste bos olana kadar listedeki elemanlari siliyorum.
    while(IsEmpty())
        pop_back();
        // en son olarak da head ve tail'i iade ediyorum.
    delete head;
}