#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
#include "date.hpp"
#include "osoba.hpp"
#include "klient.hpp"
#include "pracownik_obslugi.hpp"
#include "platnosc.hpp"
#include "pojazd.hpp"
#include "pozycja_rezerwacji.hpp"
#include "rezerwacja.hpp"
#include "system_rezerwacji.hpp"

using namespace std;

bool wczytaj_dane(SystemRezerwacji& SR, const string& nazwa_pliku){
    ifstream plik(nazwa_pliku);
    if(!plik.is_open()){
            cout<<"Nie udalo sie otworzyc pliku z danymi";
            return false;
    }
    string klasa;
    while(plik>>klasa){
        if(klasa=="Pojazd"){
            string marka, model, typ, numer_vin;
            bool dostepnosc;
            plik>>marka>>model>>typ>>numer_vin>>dostepnosc;
            SR.dodajPojazd(Pojazd(marka,model,typ,numer_vin,dostepnosc));
        }
        if(klasa=="Pracownik_obslugi"){
            string imie, nazwisko;
            int id, dzien, miesiac, rok;
            double pensja;
            plik>>imie>>nazwisko>>id>>dzien>>miesiac>>rok>>pensja;
            SR.dodajPracownika(PracownikObslugi(imie,nazwisko,id,Date(dzien,miesiac,rok),pensja));
        }
        if(klasa=="Klient"){
            string imie, nazwisko;
            int id, liczba_rezerwacji;
            double kary;
            plik>>imie>>nazwisko>>id>>kary>>liczba_rezerwacji;
            Klient k(imie,nazwisko,id,{},kary);
            for(int i=0;i<liczba_rezerwacji;i++){
                int id_rezerwacji, dzien1, miesiac1, rok1, dzien2, miesiac2, rok2, liczba_pozycji;
                string metoda;
                double koszt;
                bool potwierdzenie;
                plik>>id_rezerwacji>>dzien1>>miesiac1>>rok1>>dzien2>>miesiac2>>rok2>>metoda>>koszt>>potwierdzenie>>liczba_pozycji;
                Rezerwacja r(id_rezerwacji,Date(dzien1,miesiac1,rok1),Date(dzien2,miesiac2,rok2),{},Platnosc(metoda,koszt),potwierdzenie);
                for(int j=0;j<liczba_pozycji;j++){
                    string marka, model, typ, numer_vin;
                    bool dostepnosc;
                    plik>>marka>>model>>typ>>numer_vin>>dostepnosc;
                    Pojazd p=Pojazd(marka,model,typ,numer_vin,dostepnosc);
                    SR.dodajPojazd(p);
                    //metoda na dodanie pozycji rezerwacji do listy klasy Rezerwacja PozycjaRezerwacji(p);
                }
                SR.dodajRezerwacje(r);
                k.dodajRezerwacje(r);
            }
            SR.dodajKlienta(k);
        }
    }
    plik.close();
    return true;
}

int main()
{

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    SystemRezerwacji SR=SystemRezerwacji();
    SR.setStawka_dniowa(60);
    if(!wczytaj_dane(SR, "dane.txt")){return 1;}
    SR.menu();


    /*
    //TEST PRINT�W
    Date dd =Date(1,4,77);
    Date dy =Date(1,5,77);
    Platnosc pl=Platnosc("gotowka",10.67);
    Pojazd pp=Pojazd("Volksvagen","Passat","Samochod","jakis_VIN",true);
    PozycjaRezerwacji pr =PozycjaRezerwacji(pp);
    Pojazd pp2=Pojazd("Volksvagen","Passat","Samochod","jakis_VIN",false);
    PozycjaRezerwacji pr2 =PozycjaRezerwacji(pp2);
    vector <PozycjaRezerwacji> vpr={pr,pr2};
    Rezerwacja rr=Rezerwacja(1,dd,dy,vpr,pl,true);
    pl.print();
    cout<<endl<<endl;
    pp.print();
    cout<<endl<<endl;
    dd.print();
    cout<<endl<<endl;
    rr.print();
    cout<<endl;
    */

    return 0;
}
