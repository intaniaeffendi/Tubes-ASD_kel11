#include <iostream>
#include "mobil.h"
#include <windows.h>

using namespace std;


adr_pelanggan alokasi_pelanggan (infotype_pelanggan x) //alokasi parent / entitas 1
{
    adr_pelanggan Q;
    Q = new elm_pelanggan;
    info(Q) = x;
    next(Q) = NULL;
    prev(Q) = NULL;
    first_history(Q) = NULL;
    last_history(Q) = NULL;
    return Q;
} //1103130301

adr_car alokasi_car (infotype_car x) //alokasi entitas 2
{
    adr_car Q;
    Q = new elm_car;
    info(Q) = x;
    next(Q) = NULL;
    prev(Q) = NULL;
    return Q;
} //1103130301

adr_history alokasi_history (infotype_history x) //alokasi child
{
    adr_history Q;
    Q = new elm_history;
    info(Q) = x;
    next(Q) = NULL;
    car(Q) = NULL;
    return Q;
} //1103130301

adr_terbanyak1 alokasi_terbanyak1 (infotype_terbanyak1 x) //alokasi list report
{
    adr_terbanyak1 Q;
    Q = new elm_terbanyak1;
    info(Q) = x;
    next(Q) = NULL;
    prev(Q) = NULL;
    return Q;
} //1103130301

bool isEmpty_pelanggan (list_pelanggan L) //cek list pelanggan
{
    if ((first(L) == NULL) && (last(L) == NULL) )
        return true;
    else
        return false;
} //1103130301

bool isEmpty_car (list_car L) //cek list mobil
{
    if ((first(L) == NULL) && (last(L) == NULL) )
        return true;
    else
        return false;
} //1103130301

bool isInteger(int x) //validasi integer
{
    if ( !cin )
    {
        cin.clear();
        cin.ignore();
        return false;
    }
    else
    return true;
} //1103130301

void menu () //1103130301
{
    cout << endl;
    cout << "================================Penyewaan mobil================================" << endl;
    cout << "Menu:" <<endl;
    cout << "1.   Insert data pelanggan" << endl; //V
    cout << "2.   Insert data mobil" << endl; //V
    cout << "3.   Insert data penyewaan" << endl; //V
    cout << "4.   Delete data pelanggan" << endl; //V
    cout << "5.   Delete data mobil" << endl; //V
    cout << "6.   Delete data penyewaan" << endl; //V
    cout << "7.   Update data pelanggan" << endl; //V
    cout << "8.   View data pelanggan" << endl; //V
    cout << "9.   View data mobil" << endl; //V
    cout << "10.  Cari data pelanggan" << endl; //V
    cout << "11.  Report " << endl; //V
    cout << "12.  View mobil yg di sewa pelanggan" << endl; //V
    cout << "13.  View pelanggan yang menyewa sebuah mobil" << endl; //V
    cout << "0.   Selesai" << endl;
    cout << endl;
}

void createList_pelanggan (list_pelanggan &L) //buat list pelanggan
{
    first(L) = NULL;
    last(L) = NULL;
} //1103130301

void createList_car (list_car &L) //buat list mobil
{
    first(L) = NULL;
    last(L) = NULL;
} //1103130301

void createList_terbanyak1 (list_terbanyak1 &L) //buat list report
{
    first(L) = NULL;
    last(L) = NULL;
} //1103130301

void insert_pelanggan (list_pelanggan &L, adr_pelanggan Q) //insert pelanggan (insert teruurut ascending)
{
    adr_pelanggan P;
    P = first(L);
    if ( !isEmpty_pelanggan(L) )
    {
        if ( info(P).id_pelanggan > info(Q).id_pelanggan )
        {
            next(Q) = P;
            prev(P) = Q;
            first(L) = Q;
        }

        else if ( info(P).id_pelanggan < info(Q).id_pelanggan )
        {
            if ( next(P) == NULL )
            {
                next(P) = Q;
                prev(Q) = P;
                next(Q) = NULL;
                last(L) = Q;
            }

            else
            {
                while ( (next(P) != NULL) && (info(P).id_pelanggan < info(Q).id_pelanggan) )
                {
                    P = next(P);
                }
                    if ( (next(P) == NULL) && (info(P).id_pelanggan < info(Q).id_pelanggan) )
                    {
                        next(P) = Q;
                        prev(Q) = P;
                        last(L) = Q;
                    }

                    else if ( info(P).id_pelanggan == info(Q).id_pelanggan )
                    {
                        cout << "id sudah ada";
                    }

                    else
                    {
                        prev(Q) = prev(P);
                        next(prev(P)) = Q;
                        prev(P) = Q;
                        next(Q) = P;
                    }
            }
        }

        else
        {
            cout << "Data dengan id tersebut sudah ada";
        }
    }

    else
    {
        next(Q) = NULL;
        prev(Q) = NULL;
        first(L) = Q;
        last(L) = Q;
    }
} //1301164552

void insert_car (list_car &L, adr_car Q) //insert mobil (insert first)
{
    adr_car P;
    P = first(L);

    if (!isEmpty_car(L))
    {
        next(Q) = P;
        prev(P) = Q;
        first(L) = Q;
    }

    else
    {
        first(L) = Q;
        last(L) = Q;
    }
} //1301164552

void insert_history (list_pelanggan &L, list_car L2, infotype_history x, int id_car, int id) //insert history (insert last)
{
    adr_pelanggan P;
    P = first(L);
    adr_car R;
    R = first(L2);
    adr_history Q;
    Q = alokasi_history(x);
    bool found;
    found = false;

    while ( P != NULL )
    {
        if ( info(P).id_pelanggan == id )
        {
            while ( ( info(R).id_car != id_car ) && ( next(R) != NULL ) )
            {
                R = next(R);
            }
            if ( info(R).id_car == id_car )
            {
                car(Q) = R;
            }
            if ( first_history(P) == NULL )
            {
                first_history(P) = Q;
                last_history(P) = Q;
            }
            else
            {
                next(last_history(P)) = Q;
                last_history(P) = Q;
            }
            found = true;
        }
        P = next(P);
    }
    if ( ( found == false ) && ( next(P) == NULL ) )
    {
        cout << "data pelanggan tidak ada";
    }
} //1301164552

void delete_pelanggan (list_pelanggan &L, int id) //1301164552
{
    adr_pelanggan P,Q,R;
    P = first(L);

    if ( !isEmpty_pelanggan(L) )
    {
        while ( ( info(P).id_pelanggan != id ) && ( next(P) != NULL ) )
        {
            P = next(P);
        }
        if ( info(P).id_pelanggan == id )
        {
            if ( ( prev(P) != NULL ) && ( next(P) != NULL ) )
            {
                Q = prev(P); R = next(P);
                next(Q) = R;
                prev(R) = Q;
                next(P) = NULL;
                prev(P) = NULL;
            }
            else if ( ( prev(P) == NULL ) && ( next(P) == NULL ) )
            {
                first(L) = NULL;
                last(L) = NULL;
            }
            else if ( prev(P) == NULL )
            {
                first(L) = next(P);
                prev(next(P)) = NULL;
                next(P) = NULL;
            }
            else if ( next(P) == NULL )
            {
                last(L) = prev(P);
                next(prev(P)) = NULL;
                prev(P) = NULL;
            }
            cout << endl;
            cout << "proses delete data pelanggan selesai";
        }
        else
        {
            cout << endl;
            cout << "data tidak ada atau sudah di hapus";
        }
    }
    else
    {
        cout << endl;
        cout << "list kosong";
    }
}

void delete_car (list_car &L, int id) //1301164552
{
    adr_car P,Q,R;
    P = first(L);

    if ( !isEmpty_car(L) )
    {
        while ( ( info(P).id_car != id ) && ( next(P) != NULL ) )
        {
            P = next(P);
        }
        if ( info(P).id_car == id )
        {
            if ( ( prev(P) != NULL ) && ( next(P) != NULL ) )
            {
                Q = prev(P); R = next(P);
                next(Q) = R;
                prev(R) = Q;
                next(P) = NULL;
                prev(P) = NULL;
            }
            else if ( ( prev(P) == NULL ) && ( next(P) == NULL ) )
            {
                first(L) = NULL;
                last(L) = NULL;
            }
            else if ( prev(P) == NULL )
            {
                first(L) = next(P);
                prev(next(P)) = NULL;
                next(P) = NULL;
            }
            else if ( next(P) == NULL )
            {
                last(L) = prev(P);
                next(prev(P)) = NULL;
                prev(P) = NULL;
            }
            cout << endl;
            cout << "proses delete data mobil selsai";
        }
        else
        {
            cout << endl;
            cout << "data tidak ada atau sudah di hapus";
        }
    }
    else
    {
        cout << endl;
        cout << "list kosong";
    }
}

void delete_history (list_pelanggan &L, int id, int id_history) //1301164552
{
    adr_pelanggan P;
    P = first(L);
    adr_history Q,R;

    if ( !isEmpty_pelanggan(L) )
    {
        while ( ( info(P).id_pelanggan != id ) && ( next(P) != NULL ) )
        {
            P = next(P);
        }
        if ( info(P).id_pelanggan == id )
        {
            if ( first_history(P) != NULL )
            {
                Q = first_history(P);
                while ( ( info(Q).id_history != id_history ) && ( next(Q) != NULL ) )
                {
                    R = Q;
                    Q = next(Q);
                }
                if ( info(Q).id_history == id_history )
                {
                    if ( first_history(P) == Q )
                    {
                        first_history(P) = next(Q);
                        next(Q) = NULL;
                    }
                    else if ( next(Q) == NULL )
                    {
                        last_history(P) = R;
                    }
                    else
                    {
                        next(R) = next(Q);
                        next(Q) = NULL;
                    }
                }
                cout << endl;
                cout << "proses delete data penyewaan selesai";
            }
            else
            {
                cout << endl;
                cout << "data penyewaan kosong";
            }
        }
        else
        {
            cout << endl;
            cout << "data pelanggan tidak ditemukan";
        }
    }
    else
    {
        cout << endl;
        cout << "list kosong";
    }
}

void update (list_pelanggan &L, adr_pelanggan Q) //1301164552
{
    adr_pelanggan P;
    P = first(L);

    if ( !isEmpty_pelanggan(L) )
    {
        while ( ( info(P).id_pelanggan != info(Q).id_pelanggan ) && ( P != NULL ) )
        {
            P = next(P);
        }
        if ( info(P).id_pelanggan == info(Q).id_pelanggan )
        {
            info(P) = info(Q);
        }
        else
        {
            cout << "data tidak ditemukan";
        }
    }
    else
    {
        cout << "list kosong";
    }
}


void view_pelanggan (list_pelanggan L) //1301164552
{
    adr_pelanggan P;
    P = first(L);
    if ( P != NULL )
    {
        cout << "==Data pelanggan yang sudah di input==";
        cout << endl;
        cout << endl;
        while ( next(P) != NULL )
        {
            cout << "Nama   :";
            cout << info(P).nama; cout << endl;
            cout << "Id     :";
            cout << info(P).id_pelanggan; cout << endl;
            cout << "No. Hp :";
            cout << info(P).hp; cout << endl;
            cout << endl;
            P = next(P);
        }
        cout << "Nama   :";
        cout << info(P).nama; cout << endl;
        cout << "Id     :";
        cout << info(P).id_pelanggan; cout << endl;
        cout << "No. Hp :";
        cout << info(P).hp; cout << endl;
        cout << endl;
    }
    else
    {
        cout << "list kosong";
    }
}

void view_car (list_car L) //1103130301
{
    adr_car P;
    P = first(L);
    infotype_car x;

    if ( !isEmpty_car(L) )
    {
        cout << "==Data mobil yang sudah di input==";
        cout << endl;
        cout << endl;
        while ( next(P) != NULL )
        {
            cout << "Merek mobil    : ";
            cout << info(P).merek; cout << endl;
            cout << "Tahun produksi : ";
            cout << info(P).tahun; cout << endl;
            cout << "Id mobil       : ";
            cout << info(P).id_car; cout << endl;
            cout << endl;
            P = next(P);
        }
        cout << "Merek mobil    : ";
        cout << info(P).merek; cout << endl;
        cout << "Tahun produksi : ";
        cout << info(P).tahun; cout << endl;
        cout << "Id mobil       : ";
        cout << info(P).id_car; cout << endl;
        cout << endl;
    }
    else
    {
        cout << "list kosong";
    }
}

void view_mobilpelanggan (list_pelanggan L) //1103130301
{//clear
    adr_pelanggan P;
    adr_history Q;
    adr_car R;
    P = first(L);

    if ( !isEmpty_pelanggan(L) )
    {
        cout << "==Data pelanggan dan mobil yang di sewa==";
        cout << endl; cout << endl;
        while ( P != NULL )
        {
            if ( first_history(P) != NULL )
            {
                cout << endl;
                cout << "Data pelanggan : " << endl;
                cout << "Nama : "; cout << info(P).nama << endl;
                cout << "Id   : "; cout << info(P).id_pelanggan << endl;
                cout << "No.Hp: "; cout << info(P).hp << endl;
                cout << endl;
                cout << "Mobil yang di sewa : " << endl; cout << endl;
                Q = first_history(P);

                while ( Q != NULL )
                {
                    R = car(Q);
                    cout << "Merek    : "; cout << info(R).merek << endl;
                    cout << "Id mobil : "; cout << info(R).id_car << endl;
                    cout << endl;
                    Q = next(Q);

                }
            }
            else
            {
                cout << endl;
                cout << "Data pelanggan : " << endl;
                cout << "Nama : "; cout << info(P).nama << endl;
                cout << "Id   : "; cout << info(P).id_pelanggan << endl;
                cout << "No.Hp: "; cout << info(P).hp << endl;
                cout << endl;
                cout << "Mobil yang di sewa belum ada ";
                cout << endl; cout << endl;
            }
            cout << "========================================";
            cout << endl; cout << endl;
            P = next(P);
        }
    }
    else
    {
        cout << "list pelanggan kosong";
        cout << endl;
    }
}

void view_pelangganmobil (list_pelanggan L, list_car L2) //1301164552
{
    adr_pelanggan P;
    adr_car Q,S;
    adr_history R,T;
    Q = first(L2);
    infotype_history x;
    infotype_pelanggan y;

    while ( Q != NULL )
        {
            cout << "==Data mobil=="; cout << endl;
            cout << "Merek mobil    : "; cout << info(Q).merek; cout << endl;
            cout << "Tahun produksi : "; cout << info(Q).tahun; cout << endl;
            cout << "Id mobil       : "; cout << info(Q).id_car; cout << endl;
            cout << endl;
            cout << "Penyewa mobil ini : "<<endl;
            P = first(L);
            while ( P != NULL )
            {
                int idx = 0, z = 0;
                string tmp[20];
                R = first_history(P);

                if ( R != NULL )
                {
                    do
                    {
                        T = R;
                        S = car(T);
                        if ( info(S).id_car == info(Q).id_car )
                        {
                            tmp[idx] = info(P).nama;
                            idx = idx+1;
                        }

                        if (next(R) != NULL) {
                            R = next(R);
                        }
                    } while ( next(R) != NULL );

                        while ( z < idx )
                        {
                            cout << " : ";
                            cout << tmp[z];
                            cout << endl;
                            z = z+1;
                        }
                }
                else
                {
                    cout << "belum ada";
                    cout << endl;
                }
                P = next(P);
            }
            Q = next(Q);
        }

}

void cari (list_pelanggan L, int x) //1103130301
{
    adr_pelanggan P;
    P = first(L);

    if ( !isEmpty_pelanggan(L) )
    {
        while ( ( info(P).id_pelanggan != x ) && ( next(P) != NULL ) )
        {
            P = next(P);
        }
        cout << "Hasil pencarian : ";
        if ( info(P).id_pelanggan == x )
        {
            cout << "data ditemukan" << endl; cout << endl;
            cout << "Nama   : ";
            cout << info(P).nama << endl;
            cout << "Id     : ";
            cout << info(P).id_pelanggan << endl;
            cout << "No. Hp : ";
            cout << info(P).hp << endl;
        }
        else
        {
            cout << "data tidak ditemukan" << endl; cout << endl;
        }
    }
    else
    {
        cout << "list kosong" << endl;
    }
}

void report (list_pelanggan L, list_terbanyak1 &L2) //1301164552
{
    int mx,tmp,tmp2;
    infotype_terbanyak1 x;
    adr_pelanggan P,R;
    adr_history Q;
    adr_terbanyak1 S,T;
    P = first(L);
    T = first(L2);
    mx,tmp2 = 0;
    tmp = 1;

    if ( !isEmpty_pelanggan(L))
    {
        while ( P != NULL )
        {
            if ( first_history(P) != NULL )
            {
                Q = first_history(P);
                while ( next(Q) != NULL)
                {
                    Q = next(Q);
                    tmp = tmp+1;
                }
                S = alokasi_terbanyak1(x);
                info(S).jumlah = tmp;
                info(S).id_pelanggan = info(P).id_pelanggan;
                info(S).nama = info(P).nama;

                if ( first(L2) == NULL )
                {
                    first(L2) = S;
                    last(L2) = S;
                }
                else
                {
                    T = first(L2);
                    if ( info(T).jumlah < info(S).jumlah )
                    {
                        prev(T) = S;
                        next(S) = T;
                        first(L2) = S;
                    }
                    else if ( info(T).jumlah == info(S).jumlah )
                    {
                        prev(T) = S;
                        next(S) = T;
                        first(L2) = S;
                        tmp2 = tmp2+1;
                    }
                    else
                    {
                        T = last(L2);
                        prev(S) = T;
                        next(T) = S;
                    }
                }
            }
            else
            {
                cout << "belum ada penyewaan mobil" << endl;
            }
            P = next(P);
        }
        T = first(L2);
        if ( tmp2 != 0 )
        {
            int i; i = 1;
            while ( i <= tmp2 )
            {
                cout << "Id pelanggan              : ";
                cout << info(T).id_pelanggan << endl;
                cout << "Nama                      : ";
                cout << info(T).nama << endl;
                cout << "Jumlah mobil yang di sewa : ";
                cout << info(T).jumlah << endl;
                cout << endl;
                i = i+1;
                T = next(T);
            }
        }
        else
        {
            cout << "Id pelanggan              : ";
            cout << info(T).id_pelanggan << endl;
            cout << "Nama                      : ";
            cout << info(T).nama << endl;
            cout << "Jumlah mobil yang di sewa : ";
            cout << info(T).jumlah << endl;
            cout << endl;
        }
    }
    else
    {
        cout << "list kosong"; cout << endl;
    }
}
