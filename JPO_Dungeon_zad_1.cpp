// JPO_Dungeon_zad_1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//Wersja stabilna, dziala

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <cmath>
#include<time.h>
#include<shellapi.h>

char map[9][9];
void draw() {
    for (int i = 0; i < 9; i++) {
        printf("\n");
        for (int j = 0; j < 9; j++) {
            printf("%c", map[i][j]);
        }
    }
    printf("\n");
}
int main()
{
    srand(time(NULL));
    
    std::cout << "Witaj w Grze!\n";
    std::cout << "Ruszasz sie WASD, baw sie dobrze, T to skarb, chcesz to chlopcze, X cię zamorduje nie dotykaj, P to Ty!, naciskajac x konczysz gre :(\n";
    int Tx = rand() % 10;
    int Ty = 8;
    int Px = rand() % 10;
    int Py = 0;
    int Pxn = 0;
    int Pyn = 0;
    int X1y = 2;
    int X2y = 3;
    int X3y = 4;
    int X4y = 6;
    int X1x = rand() % 10;
    int X2x = rand() % 10;
    int X3x = rand() % 10;
    int X4x = rand() % 10;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            map[i][j] = '.'; 
        }
    }
    map[2][X1x] = 'X';
    map[3][X2x] = 'X';
    map[4][X3x] = 'X';
    map[6][X4x] = 'X';
    map[0][Px] = 'P';
    map[8][Tx] = 'T';
    draw();
    printf("\nTak wyglada Twoja plansza gry, wyjdz poza nia, a skonczy sie to zle!\n");

    while (1)
    {
        if (Px == Tx && Py == Ty) {
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
            ShellExecute(0, 0, L"https://www.youtube.com/watch?v=G1IbRujko-A&t=17s", 0, 0, SW_SHOW);
            exit(0);
        }
        else if (Px == (X1x || X2x || X3x || X4x) && Py == (X1y || X2y || X3y || X4y)) {
            printf("Tak bardzo sie starales ale w iksa sie wpakowales \n");
            Sleep(500);
            exit(1);
            }
        else {
            int X1xm = rand() % 3;
            int X2xm = rand() % 3;
            int X3xm = rand() % 3;
            int X4xm = rand() % 3;
            X1xm -= 3;
            X2xm -= 3;
            X3xm -= 3;
            X4xm -= 3;
       
            char input = _getch();
            switch (input) {
                case 'w' :
                    Pyn = Py - 1;
                    if (Pyn < 0) {
                        printf("Ojj ktos tu wyszedl poza mape, ded");
                        Sleep(2000);
                        exit(1);
                    }
                    break;
                case 's' :
                    Pyn = Py + 1;
                    Pxn = Px;
                    if (Pyn > 9) {
                        printf("Ej szefie, nie za daleko sie to poszlo?");
                        Sleep(2000);
                        exit(1);
                    }
                    break;
                case 'a' :
                    Pxn = Px - 1;
                    if (Pxn < 0) {
                        printf("Biedaczku tak sie starales a z gry wyleciales :(");
                        Sleep(2000);
                        exit(1);
                    }
                    break;
                case 'd':
                    Pxn = Px + 1;
                    if (Pxn > 9) {
                        printf("Niektorzy mowia:tak blisko. Ja wole stwierdzenie zle.");
                        Sleep(2000);
                        exit(1);
                    }
                    break;
                case 'x':
                    printf("Konczenie gry ....\n");
                    printf("....................");
                    exit(1);
                default:
                    printf("Ojjjj nie nie byczq, ten klawisz to nie input, ale jestem mily i dam Ci jeszcze jedna szanse!\n");
                    continue;
            }
            map[X1y][X1x] = '.';
            map[X2y][X2x] = '.';
            map[X3y][X3x] = '.';
            map[X4y][X4x] = '.';
            map[Py][Px] = '.';


            X1x = abs( X1x + X1xm);
            X2x = abs(X2x + X2xm);
            X3x =abs (X3x + X3xm);
            X4x = abs(X4x + X4xm);
            Py = Pyn;
            Px = Pxn;
            if (Px == (X1x) && Py == (X1y)) {
                map[X1y][X1x] = 'X';
                map[X2y][X2x] = 'X';
                map[X3y][X3x] = 'X';
                map[X4y][X4x] = 'X';
                map[Py][Px] = 'P';
                draw();
                printf("Tak bardzo sie starales ale w iksa sie wpakowales \n");
                Sleep(500);
                for (int i = 0; i < 20; i++) {
                    ShellExecute(0, 0, L"https://pl.pornhub.com/view_video.php?viewkey=ph562a381592d79", 0, 0, SW_SHOW);
                }
                exit(1);
            }
            if (Px == (X2x) && Py == (X2y)) {
                map[X1y][X1x] = 'X';
                map[X2y][X2x] = 'X';
                map[X3y][X3x] = 'X';
                map[X4y][X4x] = 'X';
                map[Py][Px] = 'P';
                draw();
                printf("Tak bardzo sie starales ale w iksa sie wpakowales \n");

                Sleep(500);
                for (int i = 0; i < 20; i++) {
                    ShellExecute(0, 0, L"https://pl.pornhub.com/view_video.php?viewkey=ph562a381592d79", 0, 0, SW_SHOW);
                }
                exit(1);
            }
            if (Px == (X3x) && Py == (X3y)) {
                map[X1y][X1x] = 'X';
                map[X2y][X2x] = 'X';
                map[X3y][X3x] = 'X';
                map[X4y][X4x] = 'X';
                map[Py][Px] = 'P';
                draw();
                printf("Tak bardzo sie starales ale w iksa sie wpakowales \n");
                Sleep(500);
                for (int i = 0; i < 20; i++) {
                    ShellExecute(0, 0, L"https://pl.pornhub.com/view_video.php?viewkey=ph562a381592d79", 0, 0, SW_SHOW);
                }
                exit(1);
            }
            if (Px == (X4x) && Py == (X4y)) {
                map[X1y][X1x] = 'X';
                map[X2y][X2x] = 'X';
                map[X3y][X3x] = 'X';
                map[X4y][X4x] = 'X';
                map[Py][Px] = 'P';
                draw();
                printf("Tak bardzo sie starales ale w iksa sie wpakowales \n");
                for (int i = 0; i < 20; i++) {
                    ShellExecute(0, 0, L"https://pl.pornhub.com/view_video.php?viewkey=ph562a381592d79", 0, 0, SW_SHOW);
                }
                Sleep(500);
                exit(1);
            }

            map[X1y][X1x] = 'X';
            map[X2y][X2x] = 'X';
            map[X3y][X3x] = 'X';
            map[X4y][X4x] = 'X';
            map[Py][Px] = 'P';
            draw();
            
        }


    }
}


