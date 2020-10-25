#include <iostream>
#include "teacher.h"
teacher::teacher(std::string imie, std::string nazwisko, std::string stopien_naukowy)
{
teacher::imie = imie;
teacher::nazwisko = nazwisko;
teacher::stopien_naukowy = stopien_naukowy;
teacher::ilosc_godzin = 0;
teacher::pensum = jakie_pensum(stopien_naukowy);
}
void teacher::WYSWIETL_DANE()
{
    std::cout << "Imie = " <<teacher::imie<<std::endl;
    std::cout << "Nazwisko = "  <<teacher::nazwisko<<std::endl;
    std::cout << "Stopien naukowy = " <<teacher::stopien_naukowy<<std::endl;
    std::cout << "Aktualna ilosc godzin = " <<teacher::ilosc_godzin<<std::endl;
    std::cout << "Pensum= " <<teacher::pensum<<std::endl;
}

int teacher::jakie_pensum(std::string stopien) // funkcja do ustalenia pensum na podstawie stopnia naukowego
{
    if(stopien=="adiunkt"||stopien=="Adiunkt")
        return 210;
    if(stopien=="asystent"||stopien=="Asystent")
        return 210;
    if(stopien=="profesor"||stopien=="Profesor")
        return 180;
    if(stopien=="doktorant"||stopien=="Doktorant")
        return 90;
    return 0;
}

void teacher::ZMIEN_DANE()
{
    int wybor;
    while(true)
    {
        std::cout<<"Witam w opcji zmiany informacji."<<std::endl;
        std::cout<<"------------------------"<<std::endl;
        std::cout<<"1.Imie"<<std::endl;
        std::cout<<"------------------------"<<std::endl;
        std::cout<<"2.Nazwisko"<<std::endl;
        std::cout<<"------------------------"<<std::endl;
        std::cout<<"3.Stopien naukowy"<<std::endl;
        std::cout<<"------------------------"<<std::endl;
        std::cout<<"4.Bez zmian"<<std::endl;
        std::cout<<"------------------------"<<std::endl;
        std::cout<<"Wybierz opcje: "<<std::endl;
        std::cin>>wybor;

        switch( wybor )
        {
            case 1:
                std::cout<<"Imie = ";
                std::cin>>teacher::imie;
                break;

            case 2:
                std::cout<<"nazwisko  = ";
                std::cin>>teacher::nazwisko;
                break;

            case 3:
                std::cout<<"Stopien naukowy = ";
                std::cin>>teacher::stopien_naukowy;
                teacher::pensum = jakie_pensum(stopien_naukowy);
                break;
            case 4:
                std::cout<<"Bez zmian"<<std::endl;
                break;
        }
        break;
    }
}

std::string teacher::imie_prowadzacego() {
    return teacher::imie;
}

std::string teacher::nazwisko_prowadzacego() {
    return teacher::nazwisko;
}


void teacher::aktualizacja_godzin() {
int godziny=0;
for(int i=0; i<zajecia_teacher.size(); i++)
{
godziny=godziny+zajecia_teacher[i].course::course::ile_godzin();
}
    teacher::ilosc_godzin=godziny;
}





