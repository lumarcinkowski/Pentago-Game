#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

void wypelnij(char tab[][10]);
void ruch(char tab[][10], char zeton);
void moment_ruchu(char tab[][10], char cwiartka, int nr_pola, char zeton);
void obrot(char tab[][10], char zeton);
void moment_obrotu(char tab[][10], int x, int y, int ilosc);
bool sprawdz(char tab[][10], char zeton);
bool sprawdz_poziom(char tab[][10], char zeton);
bool sprawdz_pion(char tab[][10], char zeton);
bool sprawdz_ukos(char tab[][10], char zeton);
void help();
void prosta_linia_gora();
void prosta_linia_dol();
void prosta_linia();
void informacja(string imie1, string imie2, char zeton1, char zeton2, int kolejka, string kogo_tura);
void wyswietl_wszystko(char tab[][10], string imie1, string imie2, char zeton1, char zeton2, int kolejka, string kogo_tura);
void wyswietl(char tab[][10]);
void glowne_menu(char plac[][10], int kolejka, string imie1, string imie2, char zeton1, char zeton2);
void gra_w_pentango(char plac[][10], int kolejka, string imie1, string imie2, char zeton1, char zeton2);
void kolko_i_krzyzyk(char tab[][10], int kolejka, string imie1, string imie2, char zeton1, char zeton2);
void przykladowa_plansza(char tab[][10], int kolejka, string imie1, string imie2, char zeton1, char zeton2);



int main()
{

    int kolejka = 1;
    char plac[10][10];
    char zeton1, zeton2;
    string imie1, imie2;
    do {
        cout << " Gracz 1! Podaj swoj nick: " << endl;
        getline(cin, imie1);
        cout << " Gracz 2! Podaj swoj nick: " << endl;
        getline(cin, imie2);
        if (imie1 == imie2) cout << "nick nie moze byc taki sam dla dwoch graczy" << endl;
    } while (imie1 == imie2);
    do {
        cout << imie1 << " wybierz swoj zeton" << endl;
        cin >> zeton1;
        cout << imie2 << " wybierz swoj zeton" << endl;
        cin >> zeton2;
        if (zeton1 == zeton2)cout << "Zetony nie moga byc takie same! Wybierz je jeszcze raz" << endl;
    } while (zeton1 == zeton2);

    system("cls");


    wypelnij(plac);
    glowne_menu(plac, kolejka, imie1, imie2, zeton1, zeton2);
    cout << "Koniec programu" << endl;
    char decyzja;
    do {
        cout << "Grasz dalej? " << endl;
        cout << "Jesli tak wpisz m " << endl;
        cout << "Jesli nie wpisz n" << endl;
        cin >> decyzja;

        switch (decyzja) {
        case 'm': {
            system("cls");
            wypelnij(plac);
            glowne_menu(plac, kolejka, imie1, imie2, zeton1, zeton2);
            break;
        }
        case 'n': {
            exit(0);
            break;
        }
        case 'p': {
            cout << "Witaj w pauzie" << endl;
            system("pause");
            break;
        }
        case 'h': {
            help();
            break;
        }
        default: {
            cout << "Niepoprawne dane " << endl;
            break;
        }
        }
    } while (decyzja != 'm');

    return 0;
}
void wypelnij(char tab[][10]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            tab[i][j] = '-';
        }
    }
}

void ruch(char tab[][10], char zeton) {

    char cwiartka;
    cout << "Aby uzyskac pomoc w dowolnym miejscu wpisz h (help)" << endl;
    do {
        cout << "Podaj cwiartke  ";
        cin >> cwiartka;
        switch (cwiartka) {
        case 'c': {
            cout << "Podaj nowy zeton " << endl;

            char nowy_zeton;
            cin >> nowy_zeton;
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 6; j++) {
                    if (tab[i][j] == zeton) {
                        tab[i][j] = nowy_zeton;
                    }
                }
            }
            zeton = nowy_zeton;

            break;
        }
        case 'p': {
            cout << "Witaj w pauzie" << endl;
            system("pause");
            break;
        }
        case 'h': {
            help();
            break;
        }
        case 'q':
        case 'w':
        case 'a':
        case 's':break;
        default: cout << "Bledne dane" << endl; break;
        }
    } while ((cwiartka != 'q') && (cwiartka != 'w') && (cwiartka != 'a') && (cwiartka != 's'));


    char nr_pola;
    do {
        cout << "Podaj nr pola  ";
        cin >> nr_pola;
        switch (nr_pola) {
        case 'h': {
            help();
            break;
        }
        case 'c': {
            cout << "Podaj nowy zeton " << endl;

            char nowy_zeton;
            cin >> nowy_zeton;
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 6; j++) {
                    if (tab[i][j] == zeton) {
                        tab[i][j] = nowy_zeton;
                    }
                }
            }
            zeton = nowy_zeton;
            break;
        }
        case 'p': {
            cout << "Witaj w pauzie" << endl;
            system("pause");
            break;
        }
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':break;
        default: cout << "niepoprawne dane" << endl; break;

        }

    } while ((nr_pola != '1') && (nr_pola != '2') && (nr_pola != '3') && (nr_pola != '4') && (nr_pola != '5') && (nr_pola != '6') && (nr_pola != '7') && (nr_pola != '8') && (nr_pola != '9'));

    moment_ruchu(tab, cwiartka, nr_pola, zeton);

}


void moment_ruchu(char tab[][10], char cwiartka, int nr_pola, char zeton) {
    int a = 0, b = 0;

    if (cwiartka == 'q') a = 0, b = 0;
    if (cwiartka == 'w')a = 0, b = 3;
    if (cwiartka == 'a')a = 3, b = 0;
    if (cwiartka == 's')a = 3, b = 3;
    if (nr_pola == '1') {
        if (tab[2 + a][0 + b] == '-') {
            tab[2 + a][0 + b] = zeton;
        }
        else {
            cout << "Nie mozna postawic zetonu na zajete pole. Podaj je jeszcze raz" << endl;
            ruch(tab, zeton);
        }
    }
    if (nr_pola == '2') {
        if (tab[2 + a][1 + b] == '-') {
            tab[2 + a][1 + b] = zeton;
        }
        else {
            cout << "Nie mozna postawic zetonu na zajete pole. Podaj je jeszcze raz" << endl;
            ruch(tab, zeton);
        }
    }
    if (nr_pola == '3') {
        if (tab[2 + a][2 + b] == '-') {
            tab[2 + a][2 + b] = zeton;
        }
        else {
            cout << "Nie mozna postawic zetonu na zajete pole. Podaj je jeszcze raz" << endl;
            ruch(tab, zeton);
        }
    }
    if (nr_pola == '4') {
        if (tab[1 + a][0 + b] == '-') {
            tab[1 + a][0 + b] = zeton;
        }
        else {
            cout << "Nie mozna postawic zetonu na zajete pole. Podaj je jeszcze raz" << endl;
            ruch(tab, zeton);
        }
    }
    if (nr_pola == '5') {
        if (tab[1 + a][1 + b] == '-') {
            tab[1 + a][1 + b] = zeton;
        }
        else {
            cout << "Nie mozna postawic zetonu na zajete pole. Podaj je jeszcze raz" << endl;
            ruch(tab, zeton);
        }
    }
    if (nr_pola == '6') {
        if (tab[1 + a][2 + b] == '-') {
            tab[1 + a][2 + b] = zeton;
        }
        else {
            cout << "Nie mozna postawic zetonu na zajete pole. Podaj je jeszcze raz" << endl;
            ruch(tab, zeton);
        }
    }
    if (nr_pola == '7') {
        if (tab[0 + a][0 + b] == '-') {
            tab[0 + a][0 + b] = zeton;
        }
        else {
            cout << "Nie mozna postawic zetonu na zajete pole. Podaj je jeszcze raz" << endl;
            ruch(tab, zeton);
        }
    }
    if (nr_pola == '8') {
        if (tab[0 + a][1 + b] == '-') {
            tab[0 + a][1 + b] = zeton;
        }
        else {
            cout << "Nie mozna postawic zetonu na zajete pole. Podaj je jeszcze raz" << endl;
            ruch(tab, zeton);
        }
    }
    if (nr_pola == '9') {
        if (tab[0 + a][2 + b] == '-') {
            tab[0 + a][2 + b] = zeton;
        }
        else {
            cout << "Nie mozna postawic zetonu na zajete pole. Podaj je jeszcze raz" << endl;
            ruch(tab, zeton);
        }
    }
}


void obrot(char tab[][10], char zeton) {

    char cwiartka, strona;
    int ilosc_obrotow = 0;

    do {
        cout << "Podaj cwiartke ktora chcesz obrocic  ";
        cin >> cwiartka;
        switch (cwiartka) {
        case 'c': {
            cout << "Podaj nowy zeton " << endl;
            char nowy_zeton;
            cin >> nowy_zeton;
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 6; j++) {
                    if (tab[i][j] == zeton) {
                        tab[i][j] = nowy_zeton;
                    }
                }
            }
            zeton = nowy_zeton;
            break;
        }
        case 'p': {
            cout << "Witaj w pauzie" << endl;
            system("pause");
            break;
        }
        case 'h': {
            help();
            break;
        }
        case 'q':
        case 'w':
        case 'a':
        case 's':break;
        default: cout << "Bledne dane" << endl; break;
        }
    } while ((cwiartka != 'q') && (cwiartka != 'w') && (cwiartka != 'a') && (cwiartka != 's'));

    do {
        cout << "Podaj w ktora strone o 90 stopni obrocic wybrana cwiartke " << endl;
        cin >> strona;
        switch (strona) {
        case 'c': {
            cout << "Podaj nowy zeton " << endl;
            char nowy_zeton;
            cin >> nowy_zeton;
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 6; j++) {
                    if (tab[i][j] == zeton) {
                        tab[i][j] = nowy_zeton;
                    }
                }
            }
            zeton = nowy_zeton;
            break;
        }
        case 'p': {
            cout << "Witaj w pauzie" << endl;
            system("pause");
            break;
        }
        case 'h': {
            help();
            break;
        }
        case 'z':
        case 'x':break;
        default: cout << "Bledne dane" << endl; break;
        }

    } while ((strona != 'z') && (strona != 'x'));


    if (strona == 'z') {
        ilosc_obrotow = 1;
    }
    else if (strona == 'x') {
        ilosc_obrotow = 3;
    }
    if (cwiartka == 'q') {
        int x = 0, y = 0;
        moment_obrotu(tab, x, y, ilosc_obrotow);
    }
    if (cwiartka == 'w') {
        int x = 0, y = 3;
        moment_obrotu(tab, x, y, ilosc_obrotow);
    }
    if (cwiartka == 'a') {
        int x = 3, y = 0;
        moment_obrotu(tab, x, y, ilosc_obrotow);
    }
    if (cwiartka == 's') {
        int x = 3, y = 3;
        moment_obrotu(tab, x, y, ilosc_obrotow);
    }
}
void moment_obrotu(char tab[][10], int x, int y, int ilosc) {

    int i = 0;
    char buff = '-';

    for (i = 0; i < ilosc; i++) {

        buff = tab[x + 2][y];
        tab[x + 2][y] = tab[x + 2][y + 2];
        tab[x + 2][y + 2] = tab[x][y + 2];
        tab[x][y + 2] = tab[x][y];
        tab[x][y] = buff;

        buff = tab[x + 2][y + 1];
        tab[x + 2][y + 1] = tab[x + 1][y + 2];
        tab[x + 1][y + 2] = tab[x][y + 1];
        tab[x][y + 1] = tab[x + 1][y];
        tab[x + 1][y] = buff;
    }


}
bool sprawdz(char tab[][10], char zeton) {
    sprawdz_pion(tab, zeton);
    sprawdz_poziom(tab, zeton);
    sprawdz_ukos(tab, zeton);
    if (sprawdz_pion(tab, zeton) == true || sprawdz_poziom(tab, zeton) == true || sprawdz_ukos(tab, zeton) == true) {
        cout << "Wygrywa zeton " << zeton << endl;
        return true;

    }
    else {
        return false;
    }
}
bool sprawdz_poziom(char tab[][10], char zeton) {

    int ile_poziom = 0;
    for (int i = 0; i < 6; i++) {
        if (tab[i][0] == zeton) {
            for (int j = 0; j < 5; j++) {
                if (tab[i][j] == zeton) {
                    ile_poziom++;
                }
            }
        }
        if (tab[i][0] != zeton) {
            for (int j = 1; j < 6; j++) {
                if (tab[i][j] == zeton) {
                    ile_poziom++;
                }
            }
        }
        if (ile_poziom == 5) {
            return true;
        }
        ile_poziom = 0;
    }
    return false;
}

bool sprawdz_pion(char tab[][10], char zeton) {

    int ile_poziom = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            if (tab[0][i] == zeton) {
                if (tab[j][i] == zeton) {
                    ile_poziom++;
                }
            }
            if (tab[0][i] != zeton) {
                if (tab[j + 1][i] == zeton) {
                    ile_poziom++;
                }
            }
            if (ile_poziom == 5) {
                return true;
            }
        }
        ile_poziom = 0;
    }
    return false;
}



bool sprawdz_ukos(char tab[][10], char zeton) {

    int j, ile_poziom = 0;
    //sprawdzenie pierwszej przekatnej zaczynajacej sie od skrajnie lewego gornego rogu
    for (int i = 0; i < 5; i++) {
        if (tab[0][0] == zeton) {
            if (tab[i][i] == zeton) {
                ile_poziom++;
            }
        }
        if (tab[0][0] != zeton) {
            if (tab[i + 1][i + 1] == zeton) {
                ile_poziom++;
            }
        }
    }
    if (ile_poziom == 5) {
        return true;
    }
    ile_poziom = 0;
    //sprawdzenie drugiej przekatnej zaczynajacej sie od skrajnie prawego gornego rogu
    for (int i = 0, j = 5; i < 5 && j>0; i++, j--) {
        if (tab[0][5] == zeton) {
            if (tab[i][j] == zeton) {
                ile_poziom++;
            }
        }
        if (tab[0][5] != zeton) {
            if (tab[i + 1][j - 1] == zeton) {
                ile_poziom++;
            }
        }

    }
    if (ile_poziom == 5) {

        return true;
    }
    return false;
}

void przykladowa_plansza(char tab[][10], int kolejka, string imie1, string imie2, char zeton1, char zeton2) {

    system("cls");
    tab[0][1] = zeton2; tab[1][2] = zeton2; tab[1][4] = zeton2; tab[4][0] = zeton2; tab[4][4] = zeton2; tab[5][1] = zeton2; tab[5][4] = zeton2; tab[5][5] = zeton2;
    tab[0][4] = zeton1; tab[1][0] = zeton1; tab[1][1] = zeton1; tab[1][3] = zeton1; tab[2][1] = zeton1; tab[3][0] = zeton1; tab[3][1] = zeton1; tab[4][2] = zeton1;
    system("cls");
    while (sprawdz(tab, zeton1) == 0 && sprawdz(tab, zeton2) == 0) {
        wyswietl_wszystko(tab, imie1, imie2, zeton1, zeton2, kolejka, imie1);
        ruch(tab, zeton1);
        system("cls");
        wyswietl_wszystko(tab, imie1, imie2, zeton1, zeton2, kolejka, imie1);
        obrot(tab, zeton1);
        system("cls");
        wyswietl_wszystko(tab, imie1, imie2, zeton1, zeton2, kolejka, imie1);
        sprawdz(tab, zeton1);
        system("cls");
        //gracz 2
        if (sprawdz(tab, zeton1) == 0) {
            wyswietl_wszystko(tab, imie1, imie2, zeton1, zeton2, kolejka, imie2);
            ruch(tab, zeton2);
            system("cls");
            wyswietl_wszystko(tab, imie1, imie2, zeton1, zeton2, kolejka, imie2);
            obrot(tab, zeton2);
            system("cls");
            wyswietl_wszystko(tab, imie1, imie2, zeton1, zeton2, kolejka, imie2);
            sprawdz(tab, zeton2);
            system("cls");
            kolejka++;
        }
    }

}
void kolko_i_krzyzyk(char tab[][10], int kolejka, string imie1, string imie2, char zeton1, char zeton2) {
    system("cls");

    while (sprawdz(tab, zeton1) == 0 && sprawdz(tab, zeton2) == 0) {
        wyswietl_wszystko(tab, imie1, imie2, zeton1, zeton2, kolejka, imie1);
        ruch(tab, zeton1);
        system("cls");
        wyswietl_wszystko(tab, imie1, imie2, zeton1, zeton2, kolejka, imie1);
        sprawdz(tab, zeton1);
        system("cls");
        //gracz 2
        if (sprawdz(tab, zeton1) == 0) {
            wyswietl_wszystko(tab, imie1, imie2, zeton1, zeton2, kolejka, imie2);
            ruch(tab, zeton2);
            system("cls");
            wyswietl_wszystko(tab, imie1, imie2, zeton1, zeton2, kolejka, imie2);
            sprawdz(tab, zeton2);
            system("cls");
            kolejka++;
        }

    }
}


void gra_w_pentango(char plac[][10], int kolejka, string imie1, string imie2, char zeton1, char zeton2) {
    system("cls");
    while (sprawdz(plac, zeton1) == 0 && sprawdz(plac, zeton2) == 0) {
        cout << "Gra " << imie1 << " Znak " << zeton1 << endl;
        wyswietl_wszystko(plac, imie1, imie2, zeton1, zeton2, kolejka, imie1);
        ruch(plac, zeton1);
        system("cls");
        wyswietl_wszystko(plac, imie1, imie2, zeton1, zeton2, kolejka, imie1);
        obrot(plac, zeton1);
        system("cls");
        wyswietl_wszystko(plac, imie1, imie2, zeton1, zeton2, kolejka, imie1);
        sprawdz(plac, zeton1);
        system("cls");
        //gracz 2
        if (sprawdz(plac, zeton1) == 0) {
            cout << "Gra " << imie2 << endl;
            wyswietl_wszystko(plac, imie1, imie2, zeton1, zeton2, kolejka, imie2);
            ruch(plac, zeton2);
            system("cls");
            wyswietl_wszystko(plac, imie1, imie2, zeton1, zeton2, kolejka, imie2);
            obrot(plac, zeton2);
            system("cls");
            wyswietl_wszystko(plac, imie1, imie2, zeton1, zeton2, kolejka, imie2);
            sprawdz(plac, zeton2);
            system("cls");
            kolejka++;
        }
    }
}

void glowne_menu(char plac[][10], int kolejka, string imie1, string imie2, char zeton1, char zeton2) {
    char wybor;
    //wypelnij(plac);
    cout << "Sekcja obslugi programu" << endl;
    cout << "0.Plansza przykladowa" << endl;
    cout << "1. Kolko i krzyzyk" << endl;
    cout << "2.Zasady gry" << endl;
    cout << "3. Gra w Pentango" << endl;
    do {
        cout << "Podaj swoj wybor";
        cin >> wybor;

        switch (wybor) {
        case '0': {
            przykladowa_plansza(plac, kolejka, imie1, imie2, zeton1, zeton2);
            break;
        }
        case '1': {
            kolko_i_krzyzyk(plac, kolejka, imie1, imie2, zeton1, zeton2);
            break;
        }
        case '2': {
            help();
            break;
        }


        case '3': {
            gra_w_pentango(plac, kolejka, imie1, imie2, zeton1, zeton2);
            break;
        }
        default: {
            cout << "Wpisz wybor jeszcze raz" << endl;
        }
        }
    } while ((wybor != '0') && (wybor != '1') && (wybor != '2') && (wybor != '3'));

}


void prosta_linia_gora() {
    cout << setw(3) << (char)218 << (char)196 << (char)196 << (char)196 << (char)194 << (char)196 << (char)196 << (char)196 << (char)194 << (char)196 << (char)196 << (char)196 << (char)191;
}
void prosta_linia() {
    cout << setw(3) << (char)195 << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << (char)197 << (char)196 << (char)196 << (char)196 << (char)180;

}
void prosta_linia_dol() {
    cout << setw(3) << (char)192 << (char)196 << (char)196 << (char)196 << (char)193 << (char)196 << (char)196 << (char)196 << (char)193 << (char)196 << (char)196 << (char)196 << (char)217;
}
void informacja(string imie1, string imie2, char zeton1, char zeton2, int kolejka, string kogo_tura) {
    int tura{ 1 };
    int g{ 1 };
    cout << "Kolejka nr " << kolejka << endl;
    cout << imie1 << "  " << "gra zetonem " << zeton1 << endl;
    cout << imie2 << "  " << "gra zetonem " << zeton2 << endl;
    cout << "Tura gracza " << kogo_tura << endl;
    prosta_linia_gora(); prosta_linia_gora();
    cout << endl;

}
void wyswietl(char tab[][10])
{


    for (int i = 0; i < 3; i++) {
        cout << " " << " " << (char)179;

        for (int j = 0; j < 6; j++) {
            if (j >= 0 && j < 3) {
                cout << setw(2) << tab[i][j] << setw(2) << (char)179;
            }
            if (j > 3 && j <= 5) {
                cout << setw(2) << tab[i][j] << setw(2) << (char)179;
            }
            if (j == 3) {
                cout << "  " << (char)179 << setw(2) << tab[i][j] << setw(2) << (char)179;
            }
        }

        cout << endl;
        if (i != 2) {
            prosta_linia();
            prosta_linia();
            cout << endl;
        }
        else {
            prosta_linia_dol();
            prosta_linia_dol();
            cout << endl;
        }


    }


    prosta_linia_gora();
    prosta_linia_gora();
    cout << endl;
    for (int i = 3; i < 6; i++) {
        cout << " " << " " << (char)179;;
        for (int j = 0; j < 6; j++) {
            if (j >= 0 && j < 3 || j>3 && j < 6) {
                cout << setw(2) << tab[i][j] << setw(2) << (char)179;
            }

            if (j == 3)cout << "  " << (char)179 << setw(2) << tab[i][j] << setw(2) << (char)179;
        }

        cout << endl;
        if (i != 5) {
            prosta_linia();
            prosta_linia();
            cout << endl;
        }
        else {
            prosta_linia_dol();
            prosta_linia_dol();
            cout << endl;
        }

    }
}
void wyswietl_wszystko(char tab[][10], string imie1, string imie2, char zeton1, char zeton2, int kolejka, string kogo_tura) {
    informacja(imie1, imie2, zeton1, zeton2, kolejka, kogo_tura);
    wyswietl(tab);

}

void help() {
    cout << "q,w,a,s to wybor czesci planszy odpowiednio: lewej gornej, prawej gornej, lewej dolnej, prawej dolnej" << endl;
    cout << "1..9 to wybor pola na czesci planszy jak na klawiaturze numerycznej tj. 1 to dolne lewe pole" << endl;
    cout << "z,x to obrot odpowiednio: zgodnie z ruchem wskazowek zegara, odwrotnie do ruchu wskazowek" << endl;
    cout << "p to pauza, u to undo, o to wczytanie predefiniowanej planszy" << endl;
    cout << "m to wejscie do opcji" << endl;
    cout << "h to wejscie do opisu programu" << endl;
    cout << "c to zmiana zetonu" << endl;
    cout << "Ruch to najpierw wybor czesci planszy i pola (np. q5), a nastepnie wybor czesci planszy i obrotu(np. az). Wyjscie z opcji p, m, h dowolnie wybrana komenda." << endl;

}
