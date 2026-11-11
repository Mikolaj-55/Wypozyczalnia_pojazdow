# tasks dla vscode:
        "args": 
            "-fdiagnostics-color=always",
            "-g",
            "${workspaceFolder}/*.cpp", 
            "-o",
            "${fileDirname}\\${fileBasenameNoExtension}.exe"

# stworzenie main.exe
    g++ main.cpp date.cpp klient.cpp osoba.cpp platnosc.cpp pojazd.cpp pozycja_rezerwacji.cpp pracownik_obslugi.cpp rezerwacja.cpp system_rezerwacji.cpp -o main.exe