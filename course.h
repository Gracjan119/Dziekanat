#ifndef DZIEKANAT_COURSE_H
#define DZIEKANAT_COURSE_H
#include <iostream>
#include <vector>

class course {
    std::string nazwa;
    std::string prowadzacy_imie;
    std::string prowadzacy_nazwisko;
    int ile_zapisanych;
    int max_zapisanych;
    int ilosc_godzin; //ilosc godzin do wyliczenia pensum
    int typ_zajec; // 0-cwiczenia, 1-laboratorium, 2-wyklad, 3-projekt
    //std::vector<int> lista_uczestnikow;
public:
    std::vector<int> lista_uczestnikow;
    course(std::string nazwa,std::string prowadzacy_imie,std::string prowadzacy_nazwisko, int max_zapisanych,int ilosc_godzin,int typ_zajec); // konstruktor
    int ile_godzin();
    void WYSWIETL_DANE(); // wyswietla wszystkie dane};
    void aktualizacja_imie_nazwisko(std::string imie, std::string nazwisko); //aktualizuje imie i nazwisko na kursach po ich zmianie u prowadzącego
    void aktualizacja_ilosci_osob(); //aktualizacja ilosci osob zapisanych
    void pokaz_indeksy_zapisane(); //pokazuje indeksy zapisane na kurs
    void zapisz_student(int indeks); //dodaje indeks studenta do wektora
    void wypisz_student(int indeks); //usuwa indeks studenta z wektora
    bool czy_jest_zapisany(int indeks); //sprawdza czy student jest zapisany na kurs
};

#endif //DZIEKANAT_COURSE_H
