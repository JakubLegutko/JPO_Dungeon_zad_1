#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <cmath>
#include<time.h>
#include<vector>

#define MAP_ROWS 9
#define MAP_COLS 9
int Py = 0;
int Pxn = 0;
int Pyn = 0;
const int X1y = 2;
const int X2y = 3;
const int X3y = 4;
const int X4y = 6;
const int Ty = 8;
int Tx;
int Px;
int X1x;
int X2x;
int X3x;
int X4x;
int X1xm;
int X2xm;
int X3xm;
int X4xm;
using std::vector;



vector<vector<char>> map;

void map_init() {
    for (int i = 0; i < MAP_COLS; i++) {
        for (int j = 0; j < MAP_ROWS; j++) {
            map.resize(MAP_ROWS, vector<char>(MAP_COLS, '.'));
        }
    }
}
void draw_no_clear() {
    for (int i = 0; i < MAP_COLS; i++) {
        printf("\n");
        for (int j = 0; j < MAP_ROWS; j++) {
            printf("%c", map[i][j]);
        }
    }
    printf("\n");
}
void draw() {
    system("cls");
    for (int i = 0; i < MAP_COLS; i++) {
        printf("\n");
        for (int j = 0; j < MAP_ROWS; j++) {
            printf("%c", map[i][j]);
        }
    }
    printf("\n");
}
void prep_map() {
    map[X1y][X1x] = 'X';
    map[X2y][X2x] = 'X';
    map[X3y][X3x] = 'X';
    map[X4y][X4x] = 'X';
    map[Py][Px] = 'P';
    map[Ty][Tx] = 'T';
}
void randomize_game() {
    Tx = rand() % 10;
    Px = rand() % 10;
    X1x = rand() % 10;
    X2x = rand() % 10;
    X3x = rand() % 10;
    X4x = rand() % 10;
}
void win_sequence() {
    printf("Kongratulejszyn, wygrales wlasnie Gre!\n");
    Sleep(1000);
    printf("....\n");
    Sleep(2000);
    printf("........\n");
    Sleep(500);
    printf("Co, czekasz na nagrode?\n");
    Sleep(400);
    printf("Nie slyszales? Kryzys jest!\n");
    Sleep(2000);
    printf("Ehh, no dobra, cos tam sie znajdzie...");
    Sleep(1000);
    printf("https://www.youtube.com/watch?v=G1IbRujko-A&t=17s");
    printf("\n");
    Sleep(300);
    printf("Milej pracy!!!");
    Sleep(5000);
    map.clear();
    exit(0);
}
void lose_sequence() {
    prep_map();
    draw();
    printf("Tak bardzo sie starales ale w iksa sie wpakowales \n");
    Sleep(2000);
    map.clear();
    exit(0);
}
void refresh_map() {
    map[X1y][X1x] = '.';
    map[X2y][X2x] = '.';
    map[X3y][X3x] = '.';
    map[X4y][X4x] = '.';
    map[Py][Px] = '.';


    X1x = abs(X1x + X1xm);
    X2x = abs(X2x + X2xm);
    X3x = abs(X3x + X3xm);
    X4x = abs(X4x + X4xm);
    Py = Pyn;
    Px = Pxn;
}
void randomize_X() {
    X1xm = rand() % 3;
    X2xm = rand() % 3;
    X3xm = rand() % 3;
    X4xm = rand() % 3;
    X1xm -= 3;
    X2xm -= 3;
    X3xm -= 3;
    X4xm -= 3;
}
int move(char input) {
    switch (input) {
    case 'w':
        Pyn = Py - 1;
        if (Pyn < 0) {
            printf("Ojj ktos tu wyszedl poza mape, ded");
            Sleep(2000);
            map.clear();
            exit(0);
        }
        return 1;
    case 's':
        Pyn = Py + 1;
        Pxn = Px;
        if (Pyn > 8) {
            printf("Ej szefie, nie za daleko sie to poszlo?");
            Sleep(2000);
            map.clear();
            exit(0);
        }
        return 1;
    case 'a':
        Pxn = Px - 1;
        if (Pxn < 0) {
            printf("Biedaczku tak sie starales a z gry wyleciales :(");
            Sleep(2000);
            map.clear();
            exit(0);
        }
        return 1;
    case 'd':
        Pxn = Px + 1;
        if (Pxn > 9) {
            printf("Niektorzy mowia:tak blisko. Ja wole stwierdzenie zle.");
            Sleep(2000);
            map.clear();
            exit(0);
        }
        return 1;
    case 'x':
        printf("Konczenie gry ....\n");
        printf("....................");
        Sleep(1000);
        map.clear();
        exit(0);
    default:
        printf("Ojjjj nie nie byczq, ten klawisz to nie input, ale jestem mily i dam Ci jeszcze jedna szanse!\n");
        return 3;
    }
}
int check_fail() {
    if (Px == (X1x) && Py == (X1y))
        return 1;
    if (Px == (X2x) && Py == (X2y))
        return 1;
    if (Px == (X3x) && Py == (X3y))
        return 1;
    if (Px == (X4x) && Py == (X4y))
        return 1;
    return 0;
}

int main()
{
    srand(time(0));
    
    std::cout << "Witaj w Grze!\n";
    std::cout << "Ruszasz sie WASD, baw sie dobrze, T to skarb, chcesz to chlopcze, X cię zamorduje nie dotykaj, P to Ty!, naciskajac x konczysz gre :(\n";
    randomize_game();
    map_init();
    prep_map();
    draw_no_clear();
    printf("\nTak wyglada Twoja plansza gry, wyjdz poza nia, a skonczy sie to zle!\n");

    while (1)
    {
        if (Px == Tx && Py == Ty) {
            win_sequence();
        }
        else {
            randomize_X();
       
            char input = _getch();
            switch (move(input)) {
            case 1: break;
            case 3: continue;
            }

            refresh_map();
            if (check_fail()) {
                lose_sequence();
            }
            prep_map();
            draw();
            
        }


    }
}