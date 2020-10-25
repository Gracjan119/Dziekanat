#include <iostream>
#include "student.h"

student::student(std::string imie,std::string nazwisko,int nr_albumu,std::string kierunek,int rok)
{
student::imie=imie;
student::nazwisko=move(nazwisko);
student::nr_albumu=nr_albumu;
student::kierunek=kierunek;
student::rok=rok;
}


void student::WYSWIETL_DANE()
{
    std::cout << "Imie = " << imie<<std::endl;
    std::cout << "Nazwisko = "  << nazwisko<<std::endl;
    std::cout << "Nr albumu = " << nr_albumu<<std::endl;
    std::cout << "Kierunek = " << kierunek<<std::endl;
    std::cout << "Rok: " << rok<<std::endl;
}

void student::ZMIEN_DANE()
{
    int wybor;
    for(;;)
    {
        std::cout<<"Witam w opcji zmiany informacji."<<std::endl;
        std::cout<<"------------------------"<<std::endl;
        std::cout<<"1.Imie"<<std::endl;
        std::cout<<"------------------------"<<std::endl;
        std::cout<<"2.Nazwisko"<<std::endl;
        std::cout<<"------------------------"<<std::endl;
        std::cout<<"3.Nr albumu"<<std::endl;
        std::cout<<"------------------------"<<std::endl;
        std::cout<<"4.Kierunek"<<std::endl;
        std::cout<<"------------------------"<<std::endl;
        std::cout<<"5.Rok"<<std::endl;
        std::cout<<"------------------------"<<std::endl;
        std::cout<<"6.Wyjscie"<<std::endl;
        std::cout<<"Wybierz opcje: "<<std::endl;
        std::cin>>wybor;

        switch( wybor )
        {
            case 1:
                std::cout<<"Imie = ";
                std::cin>>student::imie;
                break;

            case 2:
                std::cout<<"Nazwisko  = ";
                std::cin>>student::nazwisko;
                break;

            case 3:
                std::cout<<"Nr albumu = ";
                std::cin>>student::nr_albumu;
                break;
            case 4:
                std::cout<<"Kierunek = ";
                std::cin>>student::kierunek;
                break;
            case 5:
                std::cout<<"Rok = ";
                std::cin>>student::rok;
                break;

            default:
                ;
        }
        break;
    }
}

int student::indeks_student() {
    return student::nr_albumu;
}




