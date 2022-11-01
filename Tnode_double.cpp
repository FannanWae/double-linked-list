#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y)
{
    HANDLE hConsoleOutput;
    COORD dwCursorPosition;
    dwCursorPosition.X = x;
    dwCursorPosition.Y = y;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}

struct TNode
{
    int NilaiX;
    int NilaiY;
    string target;
    TNode *next;
    TNode *prev;
};

TNode *head, *tail;

void init()
{
    head = NULL;
    tail = NULL;
}

int isEmpty()
{
    if (tail == NULL)
        return 1;
    else
        return 0;
}

void insertDepan(int databaru1, int databaru2, string target)
{
    TNode *baru;
    baru = new TNode;
    baru->NilaiX = databaru1;
    baru->NilaiY = databaru2;
    baru->target = target;
    baru->next = NULL;
    baru->prev = NULL;
    if (isEmpty() == 1)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->prev = NULL;
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
    gotoxy(30, 15);
    cout << "Data masuk";
    getch();
}

void insertBelakang(int databaru1, int databaru2, string target)
{
    TNode *baru, *bantu;
    baru = new TNode;
    baru->NilaiX = databaru1;
    baru->NilaiY = databaru2;
    baru->target = target;
    baru->next = NULL;
    baru->prev = NULL;
    if (isEmpty() == 1)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
    gotoxy(30, 15);
    cout << "Data masuk";
    getch();
}

void insertAfter(int databaru1, int databaru2, string target)
{
    TNode *baru, *bantu;
    int ke1;
    baru = new TNode;
    baru->NilaiX = databaru1;
    baru->NilaiY = databaru2;
    baru->target = target;
    baru->next = NULL;
    if (isEmpty() == 1)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        gotoxy(30, 15);
        cout << "Insert Setelah Nilai X = ";
        cin >> ke1;
        bantu = head;
        do
        {
            if (ke1 == tail->NilaiX)
            {
                tail->next = baru;
                baru->prev = tail;
                tail = baru;
                break;
            }
            else if (ke1 == bantu->NilaiX)
            {
                baru->next = bantu->next;
                baru->prev = bantu;
                bantu->next->prev = baru;
                bantu->next = baru;
            }
            bantu = bantu->next;
        } while (bantu != NULL);
    }
    gotoxy(30, 15);
    cout << "                           ";
    gotoxy(30, 15);
    cout << "Data masuk";
    getch();
}

void insertBefore(int databaru1, int databaru2, string target)
{
    TNode *baru, *bantu;
    int ke1;
    baru = new TNode;
    baru->NilaiX = databaru1;
    baru->NilaiY = databaru2;
    baru->target = target;
    baru->next = NULL;
    if (isEmpty() == 1)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        gotoxy(30, 15);
        cout << "Insert Sebelum Nilai X = ";
        cin >> ke1;
        bantu = head;
        do
        {
            if (ke1 == bantu->next->NilaiX)
            {
                baru->next = bantu->next;
                baru->prev = bantu;
                bantu->next->prev = baru;
                bantu->next = baru;
                break;
            }
            bantu = bantu->next;
        } while (bantu != NULL);
    }
    gotoxy(30, 15);
    cout << "                           ";
    gotoxy(30, 15);
    cout << "Data masuk";
    getch();
}

void caridata()
{
    TNode *bantu;
    if (head != NULL)
    {
        int ke1;
        string target;
        gotoxy(30, 14);
        cout << "Cari Nilai X berapa = ";
        cin >> ke1;
        gotoxy(30, 15);
        cout << "Cari String Target apa = ";
        cin >> target;
        bantu = head;
        do
        {
            if (ke1 == bantu->NilaiX && target == bantu->target)
            {
                gotoxy(50, 1);
                cout << "====================================\n";
                gotoxy(50, 2);
                cout << "|  NILAI X  |  NILAI Y  |  TARGET  |\n";
                gotoxy(50, 3);
                cout << "====================================\n";
                gotoxy(50, 4);
                cout << "|";
                gotoxy(53, 4);
                cout << bantu->NilaiX;
                gotoxy(62, 4);
                cout << "|";
                gotoxy(65, 4);
                cout << bantu->NilaiY;
                gotoxy(74, 4);
                cout << "|";
                gotoxy(77, 4);
                cout << bantu->target;
                gotoxy(85, 4);
                cout << "|";
                gotoxy(50, 5);
                cout << "====================================";
                break;
            }
            else
            {
                bantu = bantu->next;
            }

        } while (bantu != NULL);
    }
    else
    {
        gotoxy(30, 15);
        cout << "Kosong";
    }
    getch();
}

void tampil()
{
    TNode *bantu;
    if (head != NULL)
    {
        bantu = tail;
        gotoxy(50, 1);
        cout << "====================================\n";
        gotoxy(50, 2);
        cout << "|  NILAI X  |  NILAI Y  |  TARGET  |\n";
        gotoxy(50, 3);
        cout << "====================================\n";
        int y = 4;
        while (bantu != NULL)
        {
            gotoxy(50, y);
            cout << "|";
            gotoxy(53, y);
            cout << bantu->NilaiX;
            gotoxy(62, y);
            cout << "|";
            gotoxy(65, y);
            cout << bantu->NilaiY;
            gotoxy(74, y);
            cout << "|";
            gotoxy(77, y);
            cout << bantu->target;
            gotoxy(85, y);
            cout << "|";
            bantu = bantu->prev;
            y++;
        }
        gotoxy(50, y++);
        cout << "====================================";
    }
    else
    {
        gotoxy(30, 15);
        cout << "Kosong";
    }
    getch();
}

void hapusDepan()
{

    TNode *hapus;
    int x;
    int y;
    string t;
    if (isEmpty() == 0)
    {
        if (head != tail)
        {
            hapus = head;
            x = head->NilaiX;
            y = head->NilaiY;
            t = head->target;
            head->next->prev = NULL;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
        gotoxy(30, 15);
        cout << x << " " << y << " " << t << " Terhapus";
    }
    else
    {
        gotoxy(30, 15);
        cout << "Kosong";
    }
    getch();
}

void hapusBelakang()
{
    TNode *bantu, *hapus;
    int x;
    int y;
    string t;
    if (head == NULL)
    {
        gotoxy(30, 15);
        cout << "Kosong" << endl;
    }
    else
    {
        if (head != tail)
        {
            hapus = tail;
            x = tail->NilaiX;
            y = tail->NilaiY;
            t = tail->target;
            tail = tail->prev;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
        gotoxy(30, 15);
        cout << x << " " << y << " " << t << " Terhapus";
    }
    getch();
}

void hapusTengah()
{
    TNode *hapus, *bantu;
    int ke1;
    int x;
    int y;
    string t;
    if (isEmpty() == 0)
    {
        if (head != tail)
        {
            bantu = head;
            gotoxy(30, 15);
            cout << "Cari Nilai X berapa = ";
            cin >> ke1;
            do
            {
                if (ke1 == bantu->next->NilaiX)
                {
                    hapus = bantu->next;
                    x = bantu->next->NilaiX;
                    y = bantu->next->NilaiY;
                    t = bantu->next->target;
                    bantu->next->next->prev = bantu;
                    bantu->next = bantu->next->next;
                    delete hapus;
                    break;
                }
                else
                    bantu = bantu->next;

            } while (bantu != NULL);
        }
        else
        {
            head = tail = NULL;
        }
        gotoxy(30, 15);
        cout << x << " " << y << " " << t << " Terhapus";
    }
    else
    {
        gotoxy(30, 15);
        cout << "Kosong";
    }
    getch();
}

void clear()
{
    TNode *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = NULL;
    gotoxy(30, 15);
    printf("clear");
    getch();
}

int main()
{
    int pil, databaru1, databaru2;
    string target;
    do
    {
        cout << endl;
        cout << " ============================" << endl;
        cout << " =   PROGRAM LINKED LIST    =" << endl;
        cout << " ============================" << endl;
        cout << " = 1. Insert Depan          =" << endl;
        cout << " = 2. Insert Belakang       =" << endl;
        cout << " = 3. Insert After          =" << endl;
        cout << " = 4. Insert Before         =" << endl;
        cout << " = 5. Hapus depan           =" << endl;
        cout << " = 6. Hapus Belakang        =" << endl;
        cout << " = 7. Hapus Tengah          =" << endl;
        cout << " = 8. Cari Data             =" << endl;
        cout << " = 9. Tampil Data           =" << endl;
        cout << " = 10. Clear                =" << endl;
        cout << " = 11. Exit                 =" << endl;
        cout << " ============================" << endl;
        gotoxy(29, 15);
        cout << " Masukan Pilihan : ";
        cin >> pil;
        gotoxy(29, 15);
        cout << "                          ";
        switch (pil)
        {
        case 1:
        {
            gotoxy(30, 13);
            cout << "Masukan Nilai X = ";
            cin >> databaru1;
            gotoxy(30, 14);
            cout << "Masukan Nilai Y = ";
            cin >> databaru2;
            gotoxy(30, 15);
            cout << "Masukan String Target = ";
            cin >> target;
            gotoxy(30, 13);
            cout << "                                     ";
            gotoxy(30, 14);
            cout << "                                     ";
            gotoxy(30, 15);
            cout << "                                     ";
            insertDepan(databaru1, databaru2, target);
            break;
        }
        case 2:
        {
            gotoxy(30, 13);
            cout << "Masukan Nilai X = ";
            cin >> databaru1;
            gotoxy(30, 14);
            cout << "Masukan Nilai Y = ";
            cin >> databaru2;
            gotoxy(30, 15);
            cout << "Masukan String Target = ";
            cin >> target;
            gotoxy(30, 13);
            cout << "                                     ";
            gotoxy(30, 14);
            cout << "                                     ";
            gotoxy(30, 15);
            cout << "                                     ";
            insertBelakang(databaru1, databaru2, target);
            break;
        }
        case 3:
        {
            gotoxy(30, 13);
            cout << "Masukan Nilai X = ";
            cin >> databaru1;
            gotoxy(30, 14);
            cout << "Masukan Nilai Y = ";
            cin >> databaru2;
            gotoxy(30, 15);
            cout << "Masukan String Target = ";
            cin >> target;
            gotoxy(30, 13);
            cout << "                                     ";
            gotoxy(30, 14);
            cout << "                                     ";
            gotoxy(30, 15);
            cout << "                                     ";
            insertAfter(databaru1, databaru2, target);
            break;
        }
        case 4:
        {
            gotoxy(30, 13);
            cout << "Masukan Nilai X = ";
            cin >> databaru1;
            gotoxy(30, 14);
            cout << "Masukan Nilai Y = ";
            cin >> databaru2;
            gotoxy(30, 15);
            cout << "Masukan String Target = ";
            cin >> target;
            gotoxy(30, 13);
            cout << "                                     ";
            gotoxy(30, 14);
            cout << "                                     ";
            gotoxy(30, 15);
            cout << "                                     ";
            insertBefore(databaru1, databaru2, target);
            break;
        }
        case 5:
        {
            hapusDepan();
            break;
        }
        case 6:
        {
            hapusBelakang();
            break;
        }
        case 7:

        {
            hapusTengah();
            break;
        }
        case 8:

        {
            caridata();
            break;
        }
        case 9:

        {
            tampil();
            break;
        }
        case 10:
        {
            clear();
            break;
        }
        case 11:
        {
            return 0;
            break;
        }
        default:
        {
            cout << "\n Maaf, Pilihan yang anda pilih tidak tersedia!";
        }
        }
        system("cls");
    } while (pil != 11);
    return 0;
}