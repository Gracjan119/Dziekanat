#include <iostream>
#include "course.h"

course::course(std::string nazwa, std::string prowadzacy_imie, std::string prowadzacy_nazwisko, int max_zapisanych,int ilosc_godzin, int typ_zajec) {
    course::nazwa=nazwa;
    course::prowadzacy_imie=prowadzacy_imie;
    course::prowadzacy_nazwisko=prowadzacy_nazwisko;
    course::ile_zapisanych=0;
    course::max_zapisanych=max_zapisanych;
    course::ilosc_godzin=ilosc_godzin;
    course::typ_zajec=typ_zajec;
}

int course::ile_godzin() {
    return course::ilosc_godzin;
}

void course::WYSWIETL_DANE() {
    std::cout << "Nazwa = " << course::nazwa<<std::endl;
    std::cout << "Imie = " << course::prowadzacy_imie<<std::endl;
    std::cout << "Nazwisko = "  <<course::prowadzacy_nazwisko<<std::endl;
    std::cout << "Obecna ilosc zajetych miejsc = " << course::ile_zapisanych<<std::endl;
    std::cout << "Maksymalna ilosc miejsc = " << course::max_zapisanych<<std::endl;
    std::cout << "Ilosc godzin: " << course::ilosc_godzin<<std::endl;
    std::cout << "Typ zajec = ";
    switch(course::typ_zajec) // 0-cwiczenia, 1-laboratorium, 2-wyklad, 3-projekt
    {
        case 0:
            std::cout << "cwiczenia" << std::endl;
            break;
        case 1:
            std::cout << "laboratorium" << std::endl;
            break;
        case 2:
            std::cout << "wyklad" << std::endl;
            break;
        case 3:
            std::cout << "projekt" << std::endl;
            break;
    }

}

void course::aktualizacja_imie_nazwisko(std::string imie, std::string nazwisko) {
    course::prowadzacy_imie=imie;
    course::prowadzacy_nazwisko=nazwisko;
}

void course::aktualizacja_ilosci_osob() {
    course::ile_zapisanych=course::lista_uczestnikow.size();

}

void course::zapisz_student(int indeks) {
    if(course::ile_zapisanych<course::max_zapisanych){
        lista_uczestnikow.push_back(indeks);
        std::cout<<"Zapis udany, ";
        course::aktualizacja_ilosci_osob();
        std::cout<<"Stan osob aktualizowany";
    } else std::cout<<"Nie ma miejsca kursie";
}

void course::wypisz_student(int indeks) {
    for(unsigned int i=0; i<lista_uczestnikow.size(); i++)
    {
       if(lista_uczestnikow[i]==indeks)
       {
           lista_uczestnikow.erase(lista_uczestnikow.begin()+i);
           course::aktualizacja_ilosci_osob();
       }
       else
               std::cout<<"blad przy przeszukiwaniu kursu";
    }
}

void course::pokaz_indeksy_zapisane() {
for(int i=0;i<lista_uczestnikow.size();i++)
    std::cout<<i<<":"<<lista_uczestnikow[i]<<" ";
}

bool course::czy_jest_zapisany(int indeks) {
    for(int i=0;i<lista_uczestnikow.size();i++)
        if(lista_uczestnikow[i]==indeks){
            return true;
        }
    return false;
}




