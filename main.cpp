#include <iostream>
#include <vector>
#include "student.h"
#include "teacher.h"
#include "course.h"
using namespace std;

void zapisz_student(vector<teacher>& baza_teacher,vector<student>& baza_student) {
    int student, prowadzacy,zmienna3;

    std::cout << "\n\nWyswietlenie bazy danych studentow:";
    for (unsigned int i = 0; i < baza_student.size(); i++) {
        cout << "\n\nPozycja nr " << i << endl;
        baza_student[i].student::WYSWIETL_DANE();
    }
    std::cout << "\n\nWybierz pozycje studenta ktorego chcesz dopisac na kurs: " << endl;
    std::cin >> student;

    std::cout << "\n\nWyswietlenie bazy danych prowadzacych:" << endl;
    for(unsigned int i=0; i<baza_teacher.size(); i++)
    {
        cout<<"\n\nPozycja nr "<<i<<endl;
        baza_teacher[i].teacher::WYSWIETL_DANE();
    }
    std::cout << "\n\nWybierz prowadzacego na ktorego kurs chcesz sie zapisac: " << endl;
    std::cin >> prowadzacy;

    std::cout << "\n\nWyswietlenie bazy danych kursow danego prowadzacego:";
    for (unsigned int k = 0; k < baza_teacher[prowadzacy].zajecia_teacher.size(); k++) {
        cout << "\n\nPozycja nr " << k << endl;
        baza_teacher[prowadzacy].zajecia_teacher[k].WYSWIETL_DANE();
    }
    std::cout << "\n\nWybierz pozycje kursu na ktory chcesz dopisac studenta: " << endl;
    std::cin >> zmienna3;
    baza_teacher[prowadzacy].zajecia_teacher[zmienna3].zapisz_student(baza_student[student].nr_albumu);
    //baza_teacher[prowadzacy].zajecia_teacher[zmienna3].pokaz_indeksy_zapisane(); //do sprawdzenia jakie sa osoby zapisane na kursie
}

void wypisz_student(vector<teacher>& baza_teacher,vector<student>& baza_student) {
    int student, prowadzacy,zmienna3;

    std::cout << "\n\nWyswietlenie bazy danych studentow:";
    for (unsigned int i = 0; i < baza_student.size(); i++) {
        cout << "\n\nPozycja nr " << i << endl;
        baza_student[i].student::WYSWIETL_DANE();
    }
    std::cout << "\n\nWybierz pozycje studenta ktorego chcesz wypisac z kursu: " << endl;
    std::cin >> student;

    std::cout << "\n\nWyswietlenie bazy danych prowadzacych:" << endl;
    for(unsigned int i=0; i<baza_teacher.size(); i++)
    {
        cout<<"\n\nPozycja nr "<<i<<endl;
        baza_teacher[i].teacher::WYSWIETL_DANE();
    }
    std::cout << "\n\nWybierz prowadzacego z ktorego kursu chcesz sie wypisac: " << endl;
    std::cin >> prowadzacy;

    std::cout << "\n\nWyswietlenie bazy danych kursow danego prowadzacego na ktorych student jest zapisany:";
    for (unsigned int k = 0; k < baza_teacher[prowadzacy].zajecia_teacher.size(); k++) {
            if(baza_teacher[prowadzacy].zajecia_teacher[k].czy_jest_zapisany(baza_student[student].nr_albumu)==true){
            cout << "\n\nPozycja nr " << k << endl;
            baza_teacher[prowadzacy].zajecia_teacher[k].WYSWIETL_DANE();
                }
    }

    std::cout << "\n\nWybierz pozycje kursu z ktorego chcesz wypisac studenta: " << endl;
    std::cin >> zmienna3;

    baza_teacher[prowadzacy].zajecia_teacher[zmienna3].wypisz_student(baza_student[student].nr_albumu);
    //baza_teacher[prowadzacy].zajecia_teacher[zmienna3].pokaz_indeksy_zapisane(); //do sprawdzenia jakie sa osoby zapisane na kursie
}




int main()
{
    vector <student> baza_student;
    vector <teacher> baza_teacher;

    // dane testowe
    baza_teacher.push_back(teacher("Amadeusz", "Szybki", "adiunkt"));
    baza_teacher.push_back(teacher("Elzbieta", "Powolna", "adiunkt"));
    baza_teacher.push_back(teacher("Pawel", "Bum", "profesor"));
    baza_teacher.push_back(teacher("Stanislaw", "Ziemski", "doktorant"));
    baza_teacher.push_back(teacher("Bartosz", "Wodny", "profesor"));

    baza_student.push_back(student("Gracjan","Mak",213769,"cbe",1));
    baza_student.push_back(student("Maciej","Sielecki",692137,"cbe",1));
    baza_student.push_back(student("Hubert","Kowalski",253555,"cbe",1));
    baza_student.push_back(student("Adam","Soltysiaczny",876921,"cbe",1));
    baza_student.push_back(student("Mateusz","Pastuch",123094,"tel",3));

    baza_teacher[0].teacher::zajecia_teacher.push_back(course("Telekomunikacja",baza_teacher[0].teacher::imie_prowadzacego(),baza_teacher[0].teacher::nazwisko_prowadzacego(),210,30,2));
    baza_teacher[0].teacher::zajecia_teacher.push_back(course("Telekomunikacja 2",baza_teacher[0].teacher::imie_prowadzacego(),baza_teacher[0].teacher::nazwisko_prowadzacego(),210,30,2));
    baza_teacher[2].teacher::zajecia_teacher.push_back(course("Analiza",baza_teacher[2].teacher::imie_prowadzacego(),baza_teacher[2].teacher::nazwisko_prowadzacego(),30,60,0));
    baza_teacher[1].teacher::zajecia_teacher.push_back(course("Teoria systemow",baza_teacher[1].teacher::imie_prowadzacego(),baza_teacher[1].teacher::nazwisko_prowadzacego(),60,80,1));
    baza_teacher[0].teacher::aktualizacja_godzin();
    baza_teacher[1].teacher::aktualizacja_godzin();
    baza_teacher[2].teacher::aktualizacja_godzin();
    baza_teacher[3].teacher::aktualizacja_godzin();
    baza_teacher[4].teacher::aktualizacja_godzin();

    baza_teacher[0].zajecia_teacher[0].zapisz_student(253555);
    baza_teacher[0].zajecia_teacher[0].zapisz_student(876921);
    baza_teacher[0].zajecia_teacher[0].wypisz_student(253555);
    baza_teacher[2].zajecia_teacher[0].zapisz_student(253555);

    while(true)
    {
        cout<<endl;
        cout<<"Witam w programie dziekanat."<<endl;
        cout<<"------------------------"<<endl;
        cout<<"1.Wyswietl baze danych studentow"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"2.Wyswietl baze danych zajec"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"3.Wyswietl baze danych pracownikow"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"4.Dodaj zajecia do prowadzacego"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"5.Usun zajecia od prowadzacego"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"6.Zmien rekord z bazy danych pracownikow"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"7.Zmien rekord z bazy danych studentow"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"8.Zmien rekord z bazy danych zajec"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"9.Zapisz studenta na zajecia"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"10.Wypisz studenta z zajec"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"11.Sprawdz na jakie zajecia jest zapisany student"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"12.Wyjdz"<<endl;
        cout<<"------------------------"<<endl;



        int zmienna;
        cout<<"Wybierz akcje: ";
        cin>>zmienna;
        int zmienna2;
        string nazwa;
        int max_zapisanych;
        int ilosc_godzin;
        int typ_zajec;

        switch( zmienna )
        {
            case 1:
                cout<<"\n\nWyswietlenie bazy danych studentow:";
                for(unsigned int i=0; i<baza_student.size(); i++)
                {
                    cout<<"\n\nPozycja nr "<<i<<endl;
                    baza_student[i].student::WYSWIETL_DANE();
                }
                break;
            case 2:
                cout<<"\n\nWyswietlenie bazy danych zajec:"<<endl;
                for(unsigned int i=0; i<baza_teacher.size(); i++)
                {
                    for(unsigned int j=0; j<baza_teacher[i].teacher::zajecia_teacher.size(); j++) {
                        baza_teacher[i].teacher::zajecia_teacher[j].course::WYSWIETL_DANE();
                        cout<<endl;
                    }
                }
                break;
            case 3:
                cout<<"\n\nWyswietlenie bazy danych pracownikow:";
                for(unsigned int i=0; i<baza_teacher.size(); i++)
                {
                    cout<<"\n\nPozycja nr "<<i<<endl;
                    baza_teacher[i].teacher::WYSWIETL_DANE();
                }
                break;
            case 4:
                cout<<"\n\nWyswietlenie bazy danych pracownikow:";
                for(unsigned int i=0; i<baza_teacher.size(); i++)
                {
                    cout<<"\n\nPozycja nr "<<i<<endl;
                    baza_teacher[i].teacher::WYSWIETL_DANE();
                }
                cout<<"\n\nWybierz pozycje pracownika do ktorego chcesz dodac kurs: ";
                cin>>zmienna;
                cout<<"\n\nNazwa: ";
                cin>>nazwa;
                cout<<"\n\nMaksymalna ilosc miejsc: ";
                cin>>max_zapisanych;
                cout<<"\n\nIlosc godzin: ";
                cin>>ilosc_godzin;
                cout<<"\n\nTyp zajec(0-cwiczenia, 1-laboratorium, 2-wyklad, 3-projekt): ";
                cin>>typ_zajec; //do zabezpieczenia
                baza_teacher[zmienna].teacher::zajecia_teacher.push_back(course(nazwa,baza_teacher[zmienna].teacher::imie_prowadzacego(),
                        baza_teacher[zmienna].teacher::nazwisko_prowadzacego(),max_zapisanych,ilosc_godzin,typ_zajec));

                baza_teacher[zmienna].teacher::aktualizacja_godzin();
                break;
            case 5: //do dodania usuwanie kursow od studentow
                cout<<"\n\nWyswietlenie bazy danych pracownikow:";
                for(unsigned int i=0; i<baza_teacher.size(); i++)
                {
                    cout<<"\n\nPozycja nr "<<i<<endl;
                    baza_teacher[i].teacher::WYSWIETL_DANE();
                }
                cout<<"\n\nWybierz pozycje pracownika od ktorego chcesz usunac kurs: ";
                cin>>zmienna;
                for(unsigned int j=0; j<baza_teacher[zmienna].zajecia_teacher.size(); j++)
                {
                    cout<<"\n\nPozycja nr "<<j<<endl;
                    baza_teacher[zmienna].zajecia_teacher[j].WYSWIETL_DANE();
                }
                cout<<"\n\nWybierz pozycje kursu ktory chcesz usunac: ";
                cin>>zmienna2;


                baza_teacher[zmienna].zajecia_teacher.erase(baza_teacher[zmienna].zajecia_teacher.begin()+zmienna2);
                baza_teacher[zmienna].teacher::aktualizacja_godzin();
                break;

            case 6:
                cout<<"\n\nWyswietlenie bazy danych pracownikow:";
                for(unsigned int i=0; i<baza_teacher.size(); i++)
                {
                    cout<<"\n\nPozycja nr "<<i<<endl;
                    baza_teacher[i].teacher::WYSWIETL_DANE();
                }
                cout<<"\n\nWybierz pozycje pracownika ktorego chcesz edytowac: "<<endl;
                cin>>zmienna; //zmienna
                baza_teacher[zmienna].teacher::ZMIEN_DANE();

                for(unsigned int j=0; j<baza_teacher[zmienna].zajecia_teacher.size(); j++)
                {
                    baza_teacher[zmienna].zajecia_teacher[j].aktualizacja_imie_nazwisko(baza_teacher[zmienna].imie_prowadzacego(),baza_teacher[zmienna].nazwisko_prowadzacego());
                }
                break;
            case 7:
                cout<<"\n\nWyswietlenie bazy danych studentow:";
                for(unsigned int i=0; i<baza_student.size(); i++)
                {
                    cout<<"\n\nPozycja nr "<<i<<endl;
                    baza_student[i].student::WYSWIETL_DANE();
                }
                cout<<"\n\nWybierz pozycje studenta ktorego chcesz edytowac: "<<endl;
                cin>>zmienna; //zmienna
                baza_student[zmienna].student::ZMIEN_DANE();
                break;
            case 8:
                cout<<"\n\nWyswietlenie bazy danych studentow:";
                for(unsigned int i=0; i<baza_student.size(); i++)
                {
                    cout<<"\n\nPozycja nr "<<i<<endl;
                    baza_student[i].student::WYSWIETL_DANE();
                }
                cout<<"\n\nWybierz pozycje studenta ktorego chcesz edytowac: "<<endl;
                cin>>zmienna; //zmienna
                baza_student[zmienna].student::ZMIEN_DANE();
                break;

            case 9: //zapis na zajecia
                zapisz_student(baza_teacher , baza_student);
                break;

            case 10: //wypis z zajec
                wypisz_student(baza_teacher , baza_student);
                break;

            case 11: //sprawdza na co zapisany jest student
                cout<<"\n\nWyswietlenie bazy danych studentow:";
                for(unsigned int i=0; i<baza_student.size(); i++)
                {
                    cout<<"\n\nPozycja nr "<<i<<endl;
                    baza_student[i].student::WYSWIETL_DANE();
                }
                cout<<"\n\nWybierz pozycje studenta ktorego kursy chcesz zobaczyc: "<<endl;
                cin>>zmienna; //zmienna

                cout<<"\n\nWyswietlenie bazy danych zajec:"<<endl;
                for(unsigned int i=0; i<baza_teacher.size(); i++)
                {
                    for(unsigned int j=0; j<baza_teacher[i].teacher::zajecia_teacher.size(); j++) {
                        if(baza_teacher[i].zajecia_teacher[j].czy_jest_zapisany(baza_student[zmienna].indeks_student())==true) {
                            baza_teacher[i].teacher::zajecia_teacher[j].course::WYSWIETL_DANE();
                            cout << endl;
                        }
                    }
                }

                break;

            case 12:
                return 0;
                break;
        }
    }
    return 0;
}
