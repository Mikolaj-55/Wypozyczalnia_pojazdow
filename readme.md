# Opis wymagań biznesowych
## 1. Cel biznesowy
System wspiera działanie wypożyczalni pojazdów. Zezwala na obsługę klientów i zarządzanie flotą pojazdów.
## 2. Główni aktorzy
klient 	- może rezerwować, przeglądać pojazdy, kontrolować stan kar finansowych
pracownik	- może zarządzać rezerwacjami i pojazdami.
## 3. User case
```
1. Wyszukaj pojazd
Aktorzy: Klient/Pracownik obsługi
Opis: Użytkownik przeszukuje katalog pojazdów, aby sprawdzić jego dostępność. 
Powiązanie z User Story: Odpowiada pierwszej historii użytkownika (wyszukiwanie/przeglądanie).
```
```
2. Ustal metodę płatności
Aktor: Klient
Opis: Klient podaje metodę płatności, żeby mogła być zawarta w rezerwacji.
Powiązanie z opisem systemu: Wynika bezpośrednio z zasad działania rezerwacji.
```
```
3. Dodaj pojazd
Aktor: Pracownik obsługi
Opis: Pracownik obsługi dodaje do systemu nowy pojazd, podając jego markę, model, typ oraz numer VIN, co zwiększa liczbę pojazdów w wypożyczalni.
Powiązanie z User Story: Odpowiada szóstej historii użytkownika (zarządcza/administracyjna).
```
```
4. Usuń pojazd
Aktor: Pracownik obsługi
Opis: Pracownik obsługi usuwa z systemu pojazd, podając jego numer VIN lub ((())), co zmniejsza liczbę pojazdów w wypożyczalni.
Powiązanie z User Story: Odpowiada szóstej historii użytkownika (zarządcza/administracyjna).
```
```
5. Nalicz karę finansową
Aktor: Pracownik obsługi
Opis: Pracownik obsługi nakłada na klienta karę finansową za zwrot pojazdu w złym stanie, co zwiększa atrybut kary na jego koncie.
Powiązanie z User Story: Odpowiada piątej historii użytkownika (logika biznesowa).
```
```
6. Złóż rezerwację
Aktor: Klient
Opis: Dla każdego pojazdu: klient inicjuje proces wypożyczenia pojazdu. System rejestruje datę wypożyczenia, jego okres i metodę płatności, tworzy pozycję rezerwacji powiązaną z pojazdem i dodaje ją do listy wypożyczonych pojazdów. Następnie system przekazuje tę listę, metodę płatności, okres...
Powiązanie z User Story: Odpowiada drugiej historii użytkownika (tworzenie/transakcja).
```
```
7. Potwierdź rezerwację
Aktor: Pracownik obsługi
Opis: Pracownik obsługi potwierdza(lub nie) rezerwację. Jeśli nie potwierdzi, rezerwacja jest usuwana.
Powiązanie z opisem systemu: Wynika bezpośrednio z zasad działania rezerwacji.
```

# tasks dla vscode:
        "args": 
            "-fdiagnostics-color=always",
            "-g",
            "${workspaceFolder}/*.cpp", 
            "-o",
            "${fileDirname}\\${fileBasenameNoExtension}.exe"

# stworzenie main.exe
    g++ main.cpp date.cpp klient.cpp osoba.cpp platnosc.cpp pojazd.cpp pozycja_rezerwacji.cpp pracownik_obslugi.cpp rezerwacja.cpp system_rezerwacji.cpp -o main.exe
