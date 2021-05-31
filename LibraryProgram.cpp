#include <iostream> // cin dan cout
#include <string.h> // untuk strcpy() dan strcmp()
#include <windows.h> // untuk gotoxy()
#include <stdlib.h> // untuk system()
using namespace std;

char daftar[5][50] = {"Logika Matematika", "Aljabar Linear", "Algoritma", "C++", "Machine Learning"};
int pilih,x,i,j;

void peminjaman();
void pengembalian();
void dafbuk();
void inbuk();
void menu();
void keluar();

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void menu()
{
	system("cls");
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "          PROGRAM PERPUSTAKAAN          " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "MENU UTAMA: " << endl;
	cout << " 1. Peminjaman " << endl;
	cout << " 2. Pengembalian " << endl;
	cout << " 3. Daftar Buku " << endl;
	cout << " 4. Input Buku " << endl;
	cout << " 5. Keluar" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << " Pilihan Anda = "; cin >> pilih;
	switch (pilih)
	{	case 1 : peminjaman(); break;
		case 2 : pengembalian(); break;
		case 3 : dafbuk(); break;
		case 4 : inbuk(); break;
		case 5 : keluar(); break;
		default : "   ";
	}	
}

void tanya()
{
	char pil;
	cout << endl;
	cout << " Kembali Ke Menu Utama? [y/t] " ; cin >> pil;
	if (pil=='Y' || pil=='y')
 	{ menu(); }
	else if (pil=='T' || pil=='t')
 	{ keluar(); }
 	else
	 cout << " Pilihan Tidak Valid" << endl;
}

void keluar()
{
	system("cls");
	cout << endl;
	cout << "________________________________________________" << endl;
	cout << "|          Terimakasih Atas Kujungannya         |" << endl;
	cout << "|               Sampai Jumpa Lagi               |" << endl;
	cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
	cout << "|           BUKU ADALAH JENDELA DUNIA           |" << endl;
	cout << "|_______________________________________________|" << endl;
}

void peminjaman()
{
	system ("cls");
	char nama[5][50],temp[40];
	int tanggal[5], jum,tgl[5],kode[5],j;
	cout << "      Peminjaman Pada Bulan Januari      " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << " Banyak Peminjam (maks 3) = "; cin >> jum;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	for (i=0; i < jum; i++)
	{ 
	cout<<" Nama " << i+1  << ": "; cin >> nama[i];
	cout <<" Tanggal Peminjaman (1-31): "; cin>>tanggal[i];
	cout << " Kode Buku (1-5) : "; cin >> kode[i];
	cout <<	"===============================" << endl;
	if ((tanggal[i]<0) || (tanggal[i]>31))
		{
		cout<<" Input tanggal salah"<<endl;
		}
	else
		{
 		if (tanggal[i]<25)
		 tgl[i]=tanggal[i]+7;
 		if (tanggal[i]>=25)
		 tgl[i]=(tanggal[i]+7)-31;
		}
	}
	cout << "____________________________________________________" << endl;
	cout << endl;
	gotoxy(2,17); cout << " Nama ";
    gotoxy(9,17); cout <<" | " ;
    gotoxy(13,17); cout << "      Buku     ";
    gotoxy(30,17); cout <<" | " ;
    gotoxy(33,17); cout << "Pinjam";
    gotoxy(39,17); cout <<" | " ;
    gotoxy(43,17); cout << "Kembali";
    gotoxy(51,17); cout <<" | " ;
    cout << endl;
    cout << "==========|====================|========|===========|" << endl;
	for (x=0;x<jum;x++)
 	{
	 gotoxy(2,19+x); cout << nama[x] ;
	 gotoxy(9,19+x); cout <<" | " ;
	 switch(kode[x])
		{
		case 1 : gotoxy(12,19+x); cout << daftar[0]; break;
		case 2 : gotoxy(12,19+x); cout << daftar[1]; break;
		case 3 : gotoxy(12,19+x); cout << daftar[2]; break;
		case 4 : gotoxy(12,19+x); cout << daftar[3]; break;
		case 5 : gotoxy(12,19+x); cout << daftar[4]; break;
		default : cout << "Kode Tidak Valid";
		}
 	 gotoxy(30,19+x); cout <<" | " ;
 	 gotoxy(35,19+x); cout << tanggal[x];
     gotoxy(39,19+x); cout <<" | " ;
     gotoxy(46,19+x); cout << tgl[x];
     gotoxy(51,19+x); cout <<" | " ;
     cout << endl;
 	}
	tanya();
}

void inbuk()
{
	int no;
	char judul[5][50],temp[40];
	system ("cls");
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << " Jumlah Buku Yang Anda Masukan (maks 5): "; cin >> no;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	for (i=0; i < no; i++)
		{
			cout << "Buku Ke-" << i+1 << endl;
			cout << " Judul Buku = "; cin >> judul[i];
		}
 		gotoxy(1,14); cout << "Kode";
    	gotoxy(6,14); cout <<" | " ;
    	gotoxy(10,14); cout << "      Judul      ";
    	gotoxy(29,14); cout <<" | " ;
    	cout << endl;
    	cout << "=======|======================|" << endl;
    	for ( x=1; x<no; x++)
			for ( j=x; j>0; j--)
				if ( strcmp ( judul[j], judul[j-1]) < 0)
				{
	 			strcpy(temp,judul[j]);
	 			strcpy(judul[j], judul[j-1]);
	 			strcpy(judul[j-1], temp );
	 			}
		for (x=0;x < no;x++)
 		{
			gotoxy(3,16+x); cout<< x+1;
			gotoxy(6,16+x); cout <<" | " ;
			gotoxy(10,16+x); cout << judul[x];
 		    gotoxy(29,16+x); cout <<" | " ;
 		}
 	cout << endl;
 	tanya();
}

void dafbuk()
{
 	system("cls");
	cout << "          Daftar Buku          " << endl;
	cout << "_______________________________" << endl;
	gotoxy(2,2); cout << "Kode";
    gotoxy(7,2); cout <<" | " ;
    gotoxy(11,2); cout << "      Judul     ";
    gotoxy(29,2); cout <<" | " ;
    cout << endl;
    cout << "========|=====================|" << endl;
	for (x=0;x<5;x++)
 	{
	 gotoxy(3,4+x); cout << x+1 ;
	 gotoxy(7,4+x); cout <<" | " ;
	 gotoxy(11,4+x); cout << daftar[x];
 	 gotoxy(29,4+x); cout <<" | " ;
 	}	
 	cout << endl;
	tanya();
}

void pengembalian()
{
	system ("cls");
	char nama[50];
	int tanggal,tgl,kode,bayar,kembali;
	cout << "             Pengembalian Pada Bulan Januari             " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout<<" Nama " << ": "; cin >> nama;
	cout <<" Tanggal Peminjaman (1-31): "; cin>>tanggal;
	cout << " Kode Buku (1-5) : "; cin >> kode;
	cout << " Lama Meminjam : "; cin >> kembali;
	if ((tanggal<0) || (tanggal>31))
		{
		cout<<" Input tanggal salah"<<endl;
		}
	else
	{
 		if (tanggal<25)
		{
		 tgl=tanggal+7;
		 if (kembali > 7)
		 bayar = (kembali-7) * 2000; 
		}
 		if (tanggal>=25)
		{
		 tgl=(tanggal+7)-31;
		 if (kembali > 7)
		 bayar = (kembali-7) * 2000; 
		}
	}
	cout << "=========================================================" << endl;
	cout << " " << nama;
	 switch(kode)
		{
		case 1 : cout << " meminjam buku " << daftar[0]; break;
		case 2 : cout << " meminjam buku " << daftar[1]; break;
		case 3 : cout << " meminjam buku " << daftar[2]; break;
		case 4 : cout << " meminjam buku " << daftar[3]; break;
		case 5 : cout << " meminjam buku " << daftar[4]; break;
		default : cout << "Kode Tidak Tersedia";
		}
	cout << endl;
 	cout << " Meminjam pada tanggal " << tanggal << endl;
    cout << " Batas mengembalikan tanggal " << tgl<< endl;
    cout << " Meminjam Selama " << kembali << " hari"<< endl;
    cout << " Mendapat Denda Sebesar " << bayar << endl;
    tanya();
}

int main ()
{
	menu();
	cin.get();
}