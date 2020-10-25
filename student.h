#ifndef DZIEKANAT_STUDENT_H
#define DZIEKANAT_STUDENT_H
#include <iostream>
#include "teacher.h"

class student {
    std::string imie;
    std::string nazwisko;
    int nr_albumu;
    std::string kierunek;
    int rok;
public:
    student(std::string imie, std::string nazwisko, int nr_albumu, std::string kierunek, int rok); // konstruktor
    void WYSWIETL_DANE(); // wyswietla wszystkie dane
    void ZMIEN_DANE(); // pozwala zmienic dane student
    int indeks_student(); //zwraca indeks studenta
    friend void zapisz_student(std::vector<teacher>& baza_teacher,std::vector<student>& baza_student);//zapisuje studenta na kurs/wyciaga nr albumu
    friend void wypisz_student(std::vector<teacher>& baza_teacher,std::vector<student>& baza_student); //wypisuje studenta
};


#endif //DZIEKANAT_STUDENT_H
