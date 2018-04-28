#include <iostream>
#include "mobil.h"
#include <windows.h>
using namespace std;

int main() //1103130301
{
    int a,c;
    list_pelanggan L1;
    list_car L2;
    list_terbanyak1 L3;
    createList_pelanggan(L1);
    createList_car(L2);
    createList_terbanyak1(L3);
    menu();
    cout << "pilih : "; cin >> c;
    while ( !isInteger(c) )
    {
                cout << "Format salah, masukan lagi : "; cin >> c;
    }
    a = c;

    do
    {
        if ( a == 1 )
        {
            system("cls");
            infotype_pelanggan x;
            adr_pelanggan P;
            cout << "==Input Data Pelanggan==" << endl;
            cout << "Id Pelanggan : ";
            cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Format salah, masukan lagi : ";
                cin >> c;
            }
            x.id_pelanggan = c;
            cout << "Nama         : ";
            cin >> x.nama;
            cout << "No. Hp       : ";
            cin >> x.hp;
            cout << endl;
            P = alokasi_pelanggan(x);
            insert_pelanggan(L1,P);
            system("cls");
            cout << "Data pelanggan pengan nama ";
            cout << info(P).nama;
            cout << " berhasil di input";
            cout << endl;
            menu();
            cout << "pilih menu : ";
            cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Format salah, masukan lagi : ";
                cin >> c;
            }
            a = c;
        }
        else if ( a == 2 )
        {
            system("cls");
            infotype_car x;
            adr_car P;
            cout << "==Input Data Mobil==" << endl;
            cout << "Id Mobil       : ";
            cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Format salah, masukan lagi : "; cin >> c;
            }
            x.id_car = c;
            cout << "Merek Mobil    : ";
            cin >> x.merek;
            cout << "Tahun Produksi : ";
            cin >> x.tahun;
            P = alokasi_car(x);
            insert_car(L2,P);
            system("cls");
            cout << "Data mobil dengan merek ";
            cout << x.merek;
            cout << " berhasil di input";
            cout << endl;
            menu();
            cout << "pilih menu : ";
            cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Format salah, masukan lagi : "; cin >> c;
            }
            a = c;
        }
        else if ( a == 3 )
        {
            system("cls");
            infotype_history x;
            int id_car, z;
            cout << "==Masukan Data Penyewaan==" << endl;
            cout << "Id Penyewa     : ";
            cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Format salah, masukan lagi : "; cin >> c;
            }
            z = c;
            cout << "Id Sewa        : ";
            cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Format salah, masukan lagi : "; cin >> c;
            }
            x.id_history = c;
            cout << "Id Mobil       : ";
            cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Format salah, masukan lagi : "; cin >> c;
            }
            id_car = c;
            cout << "Tanggal Sewa   : "; cin >> x.date;
            cout << "Lama Penyewaan : "; cin >> x.lama;
            insert_history(L1,L2,x,id_car,z);
            system("cls");
            cout << "Data penyewaan penyewaan dengan id sewa : "; cout << x.id_history; cout << " berhasil di input";
            cout << endl;
            menu();
            cout << "pilih menu : "; cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Format salah, masukan lagi : "; cin >> c;
            }
            a = c;
        }
        else if ( a == 4 )
        {
            system("cls");
            int id;
            cout << "==Delete Data Pelanggan==" << endl;
            cout << "Masukan id dari pelanggan yang ingin di hapus : "; cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Format salah, masukan lagi : "; cin >> c;
            }
            id = c;
            delete_pelanggan(L1,id);
            cout << endl;
            menu();
            cout << "pilih menu : "; cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Format salah, masukan lagi : "; cin >> c;
            }
            a = c;
        }
        else if ( a == 5 )
        {
            system("cls");
            int id;
            cout << "==Delete Data Mobil==" << endl;
            cout << "Masukan id dari mobil yg ingin di hapus : "; cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Format salah, masukan lagi : "; cin >> c;
            }
            id = c;
            delete_car(L2,id);
            cout << endl;
            menu();
            cout << "pilih menu : "; cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Format salah, masukan lagi : "; cin >> c;
            }
            a = c;
        }
        else if ( a == 6 )
        {
            system("cls");
            int id, id_history;
            cout << "==Delete Data Penyewaan==" << endl;
            cout << "Masukan id pelanggan                 : "; cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Format salah, masukan lagi : "; cin >> c;
            }
            id = c;
            cout << "Masukan id history yg ingin di hapus : "; cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Format salah, masukan lagi : "; cin >> c;
            }
            id_history = c;
            delete_history(L1,id,id_history);
            cout << endl;
            menu();
            cout << "pilih menu : "; cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Format salah, masukan lagi : "; cin >> c;
            }
            a = c;
        }
        else if ( a == 7 )
        {
            system("cls");
            infotype_pelanggan x; adr_pelanggan Q;
            cout << "==Update Data Pelanggan==" << endl;
            cout << "Id Pelanggan : "; cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Format salah, masukan lagi : "; cin >> c;
            }
            x.id_pelanggan = c;
            cout << "=Masukan Data Baru=" << endl;
            cout << "Nama   : "; cin >> x.nama;
            cout << "No. Hp : "; cin >> x.hp;
            Q = alokasi_pelanggan(x);
            update(L1,Q);
            system("cls");
            cout << "Proses Update Selesai";
            cout << endl;
            menu();
            cout << "pilih menu : "; cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Format salah, masukan lagi : "; cin >> c;
            }
            a = c;
        }
        else if ( a == 8 )
        {
            system("cls");
            view_pelanggan(L1);
            menu();
            cout << "pilih menu : "; cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Format salah, masukan lagi : "; cin >> c;
            }
            a = c;
        }
        else if ( a == 9 )
        {
            system("cls");
            view_car(L2);
            menu();
            cout << "pilih menu : "; cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Format salah, masukan lagi : "; cin >> c;
            }
            a = c;
        }
        else if ( a == 10 )
        {
            system("cls");
            cout << "==Mencari Data Pelanggan=="; cout << endl;
            int x; cout << "masukan id: ";
            cin >> x;
            cout << endl;
            cari(L1,x);
            cout << endl;
            cout << "Proses pencarian selesai"; cout << endl;
            menu();
            cout << "pilih menu : "; cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Format salah, masukan lagi : "; cin >> c;
            }
            a = c;
        }
        else if ( a == 11 )
        {
            system("cls");
            cout << "==Pelanggan yang paling sering menyewa mobil==" << endl;
            cout << endl;
            report(L1,L3);
            menu();
            cout << "pilih menu : "; cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Format salah, masukan lagi : "; cin >> c;
            }
            a = c;
        }
        else if ( a == 12 )
        {
            system("cls");
            view_mobilpelanggan(L1);
            menu();
            cout << endl;
            cout << "pilih menu : "; cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Format salah, masukan lagi : "; cin >> c;
            }
            a = c;
        }
        else if ( a == 13 )
        {
            system("cls");
            view_pelangganmobil(L1,L2);
            menu();
            cout << endl;
            cout << "pilih menu : "; cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Format salah, masukan lagi : "; cin >> c;
            }
            a = c;
        }
        else
        {
            cout << "inputan menu salah, input lagi : ";
            cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Format salah, masukan lagi : "; cin >> c;
            }
            a = c;
        }
    }
    while ( a != 0);
}
