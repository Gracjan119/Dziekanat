#ifndef DZIEKANAT_TEACHER_H
#define DZIEKANAT_TEACHER_H
#include <iostream>
#include "course.h"
#include <vector>
class teacher {
    friend class student;
    std::string imie;
    std::string nazwisko;
    std::string stopien_naukowy; // adiunkt/asystent-210h,profesor-180h,doktorant-90h
    int ilosc_godzin;
    int pensum;
public:
    std::vector<course> zajecia_teacher;
    teacher(std::string imie, std::string nazwisko, std::string stopien_naukowy); // konstruktor
    void WYSWIETL_DANE(); // wyswietla wszystkie dane
    void ZMIEN_DANE(); // pozwala zmienic dane
    int jakie_pensum(std::string stopien); // funkcja do ustalenia pensum na podstawie stopnia naukowego
    std::string imie_prowadzacego(); //zwraca imie prowadzacego
    std::string nazwisko_prowadzacego(); //zwraca nazwisko prowadzacego
    void aktualizacja_godzin(); //aktualizuje godziny po dodaniu kursu

};


#endif //DZIEKANAT_TEACHER_H
