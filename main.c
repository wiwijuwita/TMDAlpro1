//Bismillahirrahmannirrahim.........
/*
	Saya Wiwi Juwita tidak melakukan kecurangan seperti yang telah dispesifikasikan pada matakuliah
	Algoritma dan Pemrograman 1 dalam mengerjakan Tugas Masa Depan Alpro 1( Kode Hitungan Detektif Alpro), 
	jika saya melakukan kecurangan maka Allah adalah saksi saya, 
	dan saya bersedia menerima hukuman-Nya. 
	Aamiin...
*/
#include"header.h"
int main(){
	//varibel yang digunakan
	int n;		//untuk banyaknya masukan string
	int m;		//untuk varibel ketebalan
	int i;		//varibel sesuai kebutuhan
	
	scanf("%d",&n);		//inputan untuk banyaknya string
	
	char string[n][100];	//varibel string
	//proses inputan string
	for(i=0; i<n; i++){
		scanf("%s", &string[i]);
	}
	
	scanf("%d",&m);		//input ketebalan tampilan
	int hasil = satu(n,string);	//memanggil fungsi
	printf("%d\n",hasil);
	
	//pemanggilan prosedur
	pola(hasil,m);
	return 0;
}
