//Bismillahirrahmannirrahim.........
/*
	Saya Wiwi Juwita tidak melakukan kecurangan seperti yang telah dispesifikasikan pada matakuliah
	Algoritma dan Pemrograman 1 dalam mengerjakan Tugas Masa Depan Alpro 1( Kode Hitungan Detektif Alpro), 
	jika saya melakukan kecurangan maka Allah adalah saksi saya, 
	dan saya bersedia menerima hukuman-Nya. 
	Aamiin...
*/
#include "header.h"

int satu(int n, char string[100][100]){		//definisi nama fungsi yang dipakai dan variabel yang di lempar dari main
	//varibel yang digunakan sesuai kebutuhan
	int i,j;				//variabel iterasi dalam proses looping
	int n_angka=0;			//banyaknya karakter angka dalam string
	int angka[100];			//array untuk menampung semua karakter angka yang terdapat dalam string
	int minus=0;			//penanda kalau ada tanda '-'
	int plus=0;				//penanda kalau ada tanda '+'
	int kali=0;				//penanda kalau ada nilai 'x'
	int hasil=0;			//variabel penyimpan hasil dari operasi matematik dari angka-angka di dalam array angka atau angka-angka dalam string
	
	//PROSES OUTPUT
	//proses pencarian karakter angka kemudian karakter angka tersebut dimasukan ke dalam array
	for(i=0; i<n; i++){										//proses ini berputar sebanyak string yang diinput
		for(j=0; j<strlen(string[i]); j++){					//proses pengecekan karakter angka berputar sebanyak jumlah karakter yang ada pada string ke i
			if(string[i][j]>=48 && string[i][j]<=57){		//syarat bila ketemu karakter angka 0-9 (48=0 dan 57=9 ASCI)
				angka[n_angka] = string[i][j]-48;			//bila sesuai dengan syarat maka karakter tersebut di ubah menjadi tipe data integer dan disimopan di dalam array angka
				n_angka++;									//n_angka ini terus bertambah sesuai proses looping, dan ini menjadi banyaknya karakter angka yang ada di dalam array angka
			}
		}
		
		//proses pencarian simbol untuk pengoperasian matematik
		j=0;		//untuk iterasi
		while((j<strlen(string[i])) && (minus==0) && (plus==0) && (kali==0)){	//looping akan dilakukan bila j kurnag dari banyaknya karakter pada string ke i dan bila nilai variabel minus, plus, dan kali bernilai 0
			if(string[i][j]=='-'){				//syarat bila bertemu karakter '-' 
				minus=1;						//nilai minus menjadi 1
			}else if(string[i][j]=='+'){		//syarat bila bertemu karakter '+'
				plus=1;							//nilai plus menjadi 1
			}else if(string[i][j]=='x'){		//syarat bila ketemu karakter 'x'
				kali=1;							//nilai kali menjadi 1
			}else{								//bila tidak sesuai dengan syarat
				j++;							//proses looping terus berjalan atau nilai j bertambah
			}
		}
	}
	
	//proses penghitungan
		if(minus==1){							//syarat bila nilai minus=1
			hasil = angka[0];					//nilai hasil menjadi nilai array angka yang pertama
			for(i=1; i<n_angka; i++){			//proses looping sebanyak banyaknya angka di dalam array angka dan dimuali dari array angka ke-2 atau indeks ke-1
				hasil = hasil - angka[i];		//proses yang dilakukan nilai hasil terus di kurangi dengan angka-angka di dalam array angka
			}
		}else if(plus==1){						//syarat bila nilai plus=1
			for(i=0; i<n_angka; i++){			//proses looping sebanyak banyaknya angka di dalam array angka dan dimuali dari array angka pertama atau indeks ke-0
				hasil = hasil + angka[i];		//proses yang dilakukan nilai hasil terus ditambah dengan angka-angka di dalam array angka
			}
		}else if(kali==1){						//syarat bila nilai kali=1
			hasil = 1;							//nilai hasil menjadi 1
			for(i=0; i<n_angka; i++){			//proses looping sebanyak banyaknya angka di dalam array angka dan dimuali dari array angka pertama atau indeks ke-0
				hasil = hasil * angka[i];		//proses yang dilakukan nilai hasil terus dikali dengan angka-angka di dalam array angka
			}
		}

	return (hasil);	//nilai yang akan dilempar(nilai hasilm dilempar ke main)
}

//proses pola
void pola(int hasil, int m){
	int array[100];		// array penampung nilai dari hasil
	int i,j,a,z;		//variabel itersi
	int n_array =0;		//nilai banyaknya elemen array yang ditampung 
	int x=0;			//penanda kalau hasilnya negatif
	int y;				/* y berfungsi kaya variabel x, maksudnya kalau misalnya nilai hasilnya negatif maka y = 1, 
						tapi terlebih dahulu y = 0 kan, apabila y=0 dan x=1 maka lanjut ke pola negatif selanjutnya y = 1 kan supaya tidak ngulang ke pola negatif lagi*/
	int batas;			//batas untuk angka 1, 4, 7
	
	//apabila hasilnya negatif
	if(hasil < 0){
		hasil = hasil * -1;	//hasil dikali -1 supaya positif, karena nilai hasil akan dipisah-pisahkan menjadi angka yang berdiri sendiri
		x = 1;	//untuk penendda kalau hasil itu negatif, jadi kalau hasilnya negatif x ini akan bernilai 1
	}
	for(i=0; i<m; i++){ //untuk print enter sebanyak keteblan 
		printf("\n");
	}
	if(hasil==0){		/*apabila nilainya 0,
						maka langsung ngeprint pola angka 0*/
		/*print ketebalan untuk baris 1*/
		for(i=0; i<m; i++)	{		//for ini untuk ngeprint sesuai ketebalan ke bawah
			for(a=0; a<m; a++){		//for ini untuk ngeprint spasi sesuai ketebalan ke samping
				printf(" ");
			}
			for(a=0; a<m; a++){		//for ini untuk ngeprint nol sesuai ketebalan ke samping
				printf("0");
			}
			printf("\n");			//enter untuk menandai pola baris pertama selesai
		}
		/*print ketebalan untuk baris 2*/
		for(i=0; i<m; i++){			//for ini untuk ngeprint sesuai ketebalan ke bawah
			for(a=0; a<m; a++){		//for ini untuk ngeprint nol sesuai ketebalan ke samping
				printf("0");
			}
			for(a=0; a<m; a++){		//for ini untuk ngeprint spasi sesuai ketebalan ke samping
				printf(" ");
			}
			for(a=0; a<m; a++){		//for ini untuk ngeprint nol sesuai ketebalan ke samping
				printf("0");
			}
			printf("\n");			//enter untuk menandai pola baris ke-2 selesai
		}
		/*untuk baris 3 karena kosong maka langsung print enter*/
		printf("\n");
		/*print ketebalan untuk baris 4*/
		for(i=0; i<m; i++){			//for ini untuk ngeprint sesuai ketebalan ke bawah
			for(a=0; a<m; a++){		//for ini untuk ngeprint nol sesuai ketebalan ke samping
				printf("0");
			}
			for(a=0; a<m; a++){		//for ini untuk ngeprint spasi sesuai ketebalan ke samping
				printf(" ");
			}
			for(a=0; a<m; a++){		//for ini untuk ngeprint nol sesuai ketebalan ke samping
				printf("0");
			}
			printf("\n");			//enter untuk menandai pola baris ke-4 selesai
		}
		/*print ketebalan untuk baris 5*/
		for(i=0; i<m; i++){			//for ini untuk ngeprint sesuai ketebalan ke bawah
			for(a=0; a<m; a++){		//for ini untuk ngeprint spasi sesuai ketebalan ke samping
				printf(" ");
			}
			for(a=0; a<m; a++){		//for ini untuk ngeprint nol sesuai ketebalan ke samping
				printf("0");
			}
			printf("\n");			//enter untuk menandai pola baris ke-5 selesai
		}
	}else{		//nah ini kalau nilai hasilnya bukan 0
		//memisahkan angka dari hasil menjadi angka yang berdiri sendiri, kemudian ditampung di dalam array
		/*prosesenya melakukan looping ketika hasil!=0 dan berhenti ketika hasil = 0*/
		while(hasil!=0){
			a = (hasil / 10) * 10;			//pertama hasil dibag 10 kemudian dikalikan 10 dan nilai operasinya di tampung di variabel a.
			array[n_array] = hasil - a;		//kemudian hasil yang awal di kurangi nilai a, dan di simpen di sebuah array dengan indeks n_array, n_array ini sebagai penanda berapa banyak angka yang di tampung di array
			hasil = hasil / 10;				//kemudian si hasil yang awal di bagi 10 lagi, nah apabila hasilnya masih belum 0 maka balik lagi ke proses loooping
			n_array++;						//n_array sebagai penanda banyaknya angka yang di masukan terus bertambah sebanyak proses looping
		}
		//pola sesuai angka
		//---------------------------------------------------------------baris ke-1-------------------------------------------------------------------------------
		//membuat batasan untuk angka 1 dan 4, karena untuk angka tersebut baris awalnya kosong
		z=0;										//z ini untuk variabel iterasi
		batas = 0;									//batas ini batasan pola
		while(z<n_array){							//proses ini akan melalukan looping sebanyak z kurang dari n_array atau banyaknya angka di dalam array
			if((array[z]==1 || array[z]==4)){		/*apabila dalam array bertemu angka 1 dan 4 maka, si batas itu nilainya variabel z + 1*/
				batas = z + 1;
				if(batas==n_array){					//nah apabila nilai batas sama dengan nilai n_array maka nilai batas menjadi sama dengan nilai z
					batas = z;
				}
			}else{
				z = n_array;						//selain angka 1 atau 4 maka nilai z sama dengan nilai n_array
			}
			z++;									//z terus bertambah sesuai banyaknya proses pengulangan
		}
		//selanjutnya masuk ke pola baris ke-1
		for(i=0; i<m; i++){						//for ini untuk ngeprint sesuai ketebalan ke bawah
			y=0;								//penanda untuk pola negatif
			for(j=n_array-1; j>=batas; j--){	//pemilihan angka
			//---------------------------------------------pola negatif baris ke-1-------------------------------------------------	
				if(x==1 && y==0){			//syarat untuk negatif
					if(batas==n_array-1 && (array[n_array-1]==1 || array[n_array-1]==4)){		//syarat bila batas =n-array-1 dan berlaku hanya untuk angka 1 dan angka 4
						y=1;				//maka nilai y menjadi satu ini tanda kalau negatif					
					}else{			//bila tidak sesuai syarat
						for(a=0; a<m; a++){		//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){		//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){		//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){		//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						y=1;	//bila sudah ketemu negatif maka y=1, fungsinya supaya tidak masuk lagi ke pola negatif ketika pengulangan
					}
				}
				
				//-----------------------------------print pola angka 0 bares ke-1-----------------------------------------------------
				if(array[j]==0){				//syarat ketumu angka 0
					for(a=0; a<m; a++){			//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){			//for ini untuk ngeprint nol sesuai ketebalan ke samping
						printf("0");
					}
					if(j!=batas){				//apabila indeks arraynya bukan indeks terakhir
						for(a=0; a<m; a++){		//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){		//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else{						//tapi abaila indeksinya terakhir maka langsung print enter
						printf("\n");
					}
				//--------------------------------------print pola angka 1 baris ke 1-----------------------------------------------------
				}else if(array[j]==1){						//syrat bila kemu angka 1
					if(j!=n_array-1 && j!=batas){			//apabila indeksnya berada di tengah
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else if(j==batas){						//apabila indeksnya berada di akhir atau angkanya berdiri sendiri
							printf("\n");
					}else if(j==n_array-1 && j!=batas){		//apabila indeksnya berada diawal dan bukan diakhir
						if(x==1){							//apabila hasilnya negatif 
							for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping	
								printf(" ");
							}
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}
				//---------------------------print pola angka 2 baris ke-1--------------------------------------------------------------------
				}else if(array[j]==2){					//sray ketemu angka 2
					for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
						printf("0");
					}
					if(j!=batas){						//apibal indeksnya bukan terakhir maka print sesuai ke tebalan
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else{		//apabila indeksnya terakhir maka langsung print enter
						printf("\n");
					}
				//--------------------------------print pola angka 3 baris ke-1-------------------------------------------------------
				}else if(array[j]==3){						//srayt ketemu angka 3
					if(j!=n_array-1 && j!=batas){			//apabila indeksnya berada di tengah
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else if(j==n_array-1 && j==batas){		//bila indeksnya diawal dan diakhir
						if(x==1){							//apabila ada negatif
							for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
								printf(" ");
							}
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						printf("\n");						//print enter
					}else if(j==n_array-1 && j!=batas){		//apbila indeksnya diiawal dan bukan diakhir
						if(x==1){							//bila ada negatif
							for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
								printf(" ");
							}
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else if(j!=n_array-1 && j==batas){		//apbila indeksnya bukan di awal dan di akhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						printf("\n");						//print enter
					}
				//--------------------------------------------print pola angka 4 baris ke-1------------------------------------------------------
				}else if(array[j]==4){						//srat ketemu angka 4
					if(j!=n_array-1 && j!=batas){			//bila indeksnya bukan di awal dan bukan diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else if(j==batas){						//apabila indeksnya di awal dan diakhir atau indeks=0
							printf("\n");
					}else if(j==n_array-1 && j!=batas){		//bila indeksnya diawal dan di akhir 
						for(a=0; a<m; a++){
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}
				//-------------------------------------print pola angka 5 baris ke-1---------------------------------------------------------
				}else if(array[j]==5){						//syarat bila ketemua angka 5
					for(a=0; a<m; a++){						//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){						//for ini untuk ngeprint 0 sesuai ketebalan ke samping
						printf("0");
					}
					if(j!=batas){							//apabila indeksnya 0 
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else{									//apbila indeksnya 0 atau berada di akhir langsung print enter
						printf("\n");
					}
				//-----------------------------------print pola angka 6 baris ke-1-----------------------------------------------------
				}else if(array[j]==6){						//syarat ketemu angka 6
					for(a=0; a<m; a++){						//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){						//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf("0");
					}
					if(j!=batas){							//bila indeksnya bukan terakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else{									//bila indeksnya terakhir, langsung print enter
						printf("\n");
					}
				//-----------------------------------print pola angka 7 baris ke-1-----------------------------------------------------
				}else if(array[j]==7){						//syarat ketemu angka 7
					for(a=0; a<m; a++){						//for ini untuk ngeprint 0 sesuai ketebalan ke samping
						printf("0");
					}
					for(a=0; a<m; a++){						//for ini untuk ngeprint 0 sesuai ketebalan ke samping
						printf("0");
					}
					if(j!=batas){							//bila indeksnya bukan terakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else{									//bila indeksnya di akhir
						printf("\n");						//langsung print enter
					}
				//-----------------------------------print pola angka 8 baris ke-1-----------------------------------------------------
				}else if(array[j]==8){					//syarat bila angka 8
					for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
						printf("0");
					}
					if(j!=batas){						//bila indeks bukan diakhir
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else{								//bila indeks diakhir 
						printf("\n");					//lanhsung print enter
					}
				//-----------------------------------print pola angka 9 baris ke-1-----------------------------------------------------
				}else if(array[j]==9){					//bila ketemu angka 9 
					for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf("0");
					}
					if(j!=batas){						//bila indeksnya bukan diakhir
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else{								//bila indeksnya diakhir
						printf("\n");					//langsung print enter
					}
				}
			}
		}
		//---------------------------------------------------------------------baris ke-2----------------------------------------------------------------
		for(i=0; i<m; i++){					//for ini untuk ngeprint sesuai ketebalan ke bawah
			y=0;							//y=0, agar masuk ke proses pola negatif
			for(j=n_array-1; j>=0; j--){	//pemilihan angka pada array
				//-----------------------------------print ola negatif baris ke-2--------------------------------------------------------------------------
				if(x==1 && y==0){			//syarat untuk negatif
					for(a=0; a<m; a++){		//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){		//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){		//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){		//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
				}
				y=1;						//y menjadi 1 karena bertemu negatif
				//-----------------------------------print pola angka 0 baris ke-2-----------------------------------------------------
				if(array[j]==0){					//syarat ketemu angka 0
					for(a=0; a<m; a++){				//for ini untuk ngeprint 0 sesuai ketebalan ke samping
						printf("0");
					}
					for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf("0");
					}
					if(j!=0){						//bila indeksnya bukan di akhir
						for(a=0; a<m; a++){			//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else{							//bila indeksnya di akhir
						printf("\n");				//langsung print 0
					}
				//-----------------------------------print pola angka 1 baris ke-2-----------------------------------------------------
				}else if(array[j]==1){						//syarat ketemu anggka 1
					if(j!=n_array-1 && j!=0){				//bila indeksnya berada bukan di awal dan bukan diakhir (ditengah) 
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else if(j==n_array-1 && j!=0){			//bila indeksnya berada di awal dan bukan diakhir
						if(x==1){							//bila ada negatif
							for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
								printf(" ");
							}
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else if(j!=n_array-1 && j==0){			//bila indeks bukan berada di awal dan berada diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						printf("\n");						//print enter
					}else if(j==n_array-1 && j==0){			//bila indeksnya berada diawal dan berada di akhir
						if(x==1){							//bila ada negatif
							for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
								printf(" ");
							}
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf("0");
						}
						printf("\n");						//print enter
					}
				//-----------------------------------print pola angka 2 baris ke-2-----------------------------------------------------
				}else if(array[j]==2){						//syarat ketemu angka 2
					for(a=0; a<m; a++){						//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){						//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){						//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
					if(j!=0){								//bila indeksnya bukan diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else{									//bila indeks berada diakhir
						printf("\n");						//langsung print enter
					}
				//-----------------------------------print pola angka 3 baris ke-2-----------------------------------------------------
				}else if(array[j]==3){						//syarat bertemu angka 3
					if(j!=n_array-1 && j!=0){				//bila indeksnya bukan diawal dan bukan diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else if(j==n_array-1 && j==0){			//bila indeksnya diawal dan diakhir
						if(x==1){							//bila ada negatif
							for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
								printf(" ");
							}
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						printf("\n");						//print enter
					}else if(j==n_array-1 && j!=0){			//bila indeksny diawal dan bukan diakhir
						if(x==1){							//bila ada negatif
							for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
								printf(" ");
							}
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else if(j!=n_array-1 && j==0){			//bila indeksnya bukan diawal dan berada diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						printf("\n");						//print enter
					}
				//-----------------------------------print pola angka 4 baris ke-2-----------------------------------------------------
				}else if(array[j]==4){						//syarat ketemu angka 4
					if(j==n_array-1 && j==0){				//bila indeksnya diawal dan diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						printf("\n");						//print enter
					}else if(j==n_array-1 && j!=0){			//bila indeksnya diawal dan bukan diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else if(j!=n_array-1 && j==0){			//bila indeksnya bukan diawal dan berada diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						printf("\n");						//print spasi
					}else if(j!=n_array-1 && j!=0){			//bila indeksnya bukan diawal dan bukan diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}
				//-----------------------------------print pola angka 5 baris ke-2-----------------------------------------------------
				}else if(array[j]==5){						//syarat ketemu angka 5
					if(j==n_array-1 && j==0){				//bila indeksnya diawal dan di akhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						printf("\n");						//print spasi
					}else if(j!=n_array-1 && j!=0){			//bila indeksnya bukan diawal dan bukna diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else if(j==n_array-1 && j!=0){			//bila indeksnya diawal dan bukan diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else if(j!=n_array-1 && j==0){			//bila indeksnya bukan diawal dan berada diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						printf("\n");						//print spasi
					}
				//-----------------------------------print pola angka 6 baris ke-2-----------------------------------------------------
				}else if(array[j]==6){						//syarat bila ketemu angka 6
					if(j==n_array-1 && j==0){				//bila indeksnya diawla dan diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						printf("\n");						//print spasi
					}else if(j!=n_array-1 && j!=0){			//bila indeksnya bukan diawal dan bukan diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else if(j==n_array-1 && j!=0){			//bila indeksnya diawal dan bukan diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else if(j!=n_array-1 && j==0){			//bila indeksnya bukan diawal dan berada diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						printf("\n");						//print enter
					}
				//-----------------------------------print pola angka 7 baris ke-2-----------------------------------------------------
				}else if(array[j]==7){						//syarat ketemu angka 7
					for(a=0; a<m; a++){						//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){						//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){						//for ini untuk ngeprint 0 sesuai ketebalan ke samping
						printf("0");
					}
					if(j!=0){								//bila indeksnya bukan berada di akhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else{									//bila indeksnya berada diakhir
						printf("\n");						//langsung printf enter
					}
				//-----------------------------------print pola angka 8 baris ke-2-----------------------------------------------------
				}else if(array[j]==8){						//syarat ketemu angka 8
					if(j==n_array-1 && j==0){				//bila indeksnya diawal dan diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						printf("\n");						//print enter
					}else if(j==n_array-1 && j!=0){			//bila indeks diawal dan bukan diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else if(j!=n_array-1 && j==0){			//bila indeksnya bukan diawal dan berada diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf("0");
						}
						printf("\n");						//print enter
					}else if(j!=n_array-1 && j!=0){			//bila indeksnya bukan diawal dan bukan diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}
				//-----------------------------------print pola angka 9 baris ke-2-----------------------------------------------------
				}else if(array[j]==9){						//syarat ketemu angka 9
					if(j==n_array-1 && j==0){				//bila indeksnya diawal dan diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						printf("\n");						//print enter
					}else if(j==n_array-1 && j!=0){			//bila indeksnya diawal dan diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else if(j!=n_array-1 && j==0){			//bila indeksnya bukan diawal dan berada diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");	
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						printf("\n");						//print enter
					}else if(j!=n_array-1 && j!=0){			//bila indeksnya bukan diawal dan bukan diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}
				}
			}
		}
		//-------------------------------------------------------------------------baris ke-3------------------------------------------------------------
		//memberi batas untuk angka 0,1,7 karena di baris ke-3 angka tersebut polanya kosong
		z=0;			//iterasi pada pengulangan
		batas = 0;		//untuk memberi batasan 
		while(z<n_array){		//prosesnya diulang selama z kurang dari n_array
			if((array[z]==0 || array[z]==1 || array[z]==7) ){		//syarat bila ketemu angka 0, 1, dan 7
				batas = z + 1;				//nilai batas menjadi nilai z ditambah 1
				if(batas==n_array){			//syarat bila nilai batas sama dengan n_Array
					batas = z;				//nilai batas menjadi sama dengan nilai z
				}
			}else{		//bila bukan angka 0, 1, dan 7
				z = n_array;				//nilai z menjadi sama dengan n_array
			}
			z++;				//nilai z terus bertambah sesuai pengulangan
		}
		for(i=0; i<m; i++){		//print pola sesuai ketebalan kebawah
			y=0;				//nilai y direset kembali menjadi 0, agar masuk ke pola negatif
			for(j=n_array-1; j>=batas; j--){				//pemilihan angka
				//-----------------------polla negatif baris ke-3----------------------------------------------------------------------------------------------------
				if(x==1 && y==0){						//syarat untuk negatif
					for(a=0; a<m; a++){					////for ini untuk ngeprint 0 sesuai ketebalan ke samping
						printf("0");
					}
					for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
						printf("0");
					}
					for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
						printf("0");
					}
					if(batas==n_array-1 && (array[n_array-1]==1 || array[n_array-1]==7)){		//bila batas = n_array angka pertama 1, atau 7
						y=1;							//y menjadi 1, supaya tidak balik ke proses pola negatif
					}else{								//bila bukan sesuai dengan syarat
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						y=1;							//y menjadi 1, supaya tidak balik ke proses pola negatif
					}
				}
				////-----------------------------------print pola angka 0 baris ke-3-----------------------------------------------------
				if(array[j]==0){									//syarat ketemu angka 0
					if(j==batas){									//bila indeksnya berada diakhir atau diawal
						printf("\n");								//print enter
					}else if(j!=n_array-1 && j!=batas){				//bila indeksnya bukan diawal dan bukan diakhir
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping		
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}
				//-----------------------------------print pola angka 1 baris ke-3-----------------------------------------------------
				}else if(array[j]==1){								//syarat ketemua nagka 1
					if(j!=n_array-1 && j!=batas){					//bila indeksnya bukan diawal dan bukan diakhir
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else if(j==batas){								//bila indeksnya berada diakhir dan diawal 
							printf("\n");							//lngsung print spasi
					}else if(j==n_array-1 && j!=batas){				//bila indeksnya diawla dan bukan diakhir
						if(x==1){									//bila ada negatif
							for(a=0; a<m; a++){						//for ini untuk ngeprint spasi sesuai ketebalan ke samping
								printf(" ");
							}
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}
				//-----------------------------------print pola angka 2 baris ke-3-----------------------------------------------------
				}else if(array[j]==2){								//bila ketemu angka 2
					for(a=0; a<m; a++){								//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");						
					}
					for(a=0; a<m; a++){								//for ini untuk ngeprint 0 sesuai ketebalan ke samping
						printf("0");
					}
					if(j!=batas){									//bila indeksnya bukan di akhir
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");					
						}
					}else{											//bila indeksnya diakhir
						printf("\n");								//lngasung print enter
					}
				//-----------------------------------print pola angka 3 baris ke-3-----------------------------------------------------
				}else if(array[j]==3){								//syarat ketemu angka 3
					if(j!=n_array-1 && j!=batas){					//bila indeksnya bukan diawal dan bukan diakhir
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else if(j==n_array-1 && j==batas){				//bila indeksnya diawal dan diakhir
						if(x==1){									//bila ada negatif
							for(a=0; a<m; a++){						//for ini untuk ngeprint spasi sesuai ketebalan ke samping
								printf(" ");
							}
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						printf("\n");								//print enter
					}else if(j==n_array-1 && j!=batas){				//bila indeksnya diawal dan bukan diakhir
						if(x==1){									//bila ada negatif
							for(a=0; a<m; a++){						//for ini untuk ngeprint spasi sesuai ketebalan ke samping
								printf(" ");
							}
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else if(j!=n_array-1 && j==batas){				//bila indeksnya bukan  diawal dan bukan diakhir dan berada diakhir
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						printf("\n");								//print enter
					}
				//-----------------------------------print pola angka 4 baris ke-3-----------------------------------------------------
				}else if(array[j]==4){								//syarat bila ketemu angka 4
					for(a=0; a<m; a++){								//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){								//for ini untuk ngeprint 0 sesuai ketebalan ke samping
						printf("0");
					}
					if(j!=batas){									//bila indeksnya bukan diakhir
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else{											//bila indeksnya di akhir
						printf("\n");								//langsung print enter
					}
				//-----------------------------------print pola angka 5 baris ke-3-----------------------------------------------------
				}else if(array[j]==5){								//syarat ketemu angka 5
					if(j!=n_array-1 && j!=batas){					//bila indeksnya bukan diawal dan bukan diakhir
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else if(j==n_array-1 && j==batas){				//bila indeksnya diawal dan diakhir
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						printf("\n");								//print enter
					}else if(j!=n_array-1 && j==batas){				//bila indeksnya bukan diawla dan berada diakhir
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");		
						}		
						for(a=0; a<m; a++){							//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						printf("\n");								//print enter
					}else if(j==n_array-1 && j!=batas){				//bila indeksnya diawla dan bukan diakhir
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}
				//-----------------------------------print pola angka 6 baris ke-3-----------------------------------------------------
				}else if(array[j]==6){								//syarat ketemu angka 6
					if(j!=n_array-1 && j!=batas){					//bila indeksnya bukan diawla dan bukan diakhir
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else if(j==n_array-1 && j==batas){				//bila indeksnya diawal dan diakhir
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						printf("\n");								//print enter
					}else if(j!=n_array-1 && j==batas){				//bila indeksnya bukan diawla dan berada diakhir
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");		
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						printf("\n");								//print enter
					}else if(j==n_array-1 && j!=batas){				//bila indeksnya diawal dan bukan diakhir 
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}
				//-----------------------------------print pola angka 7 baris ke-3-----------------------------------------------------
				}else if(array[j]==7){								//syarat bila ketemu angka 7
					if(j!=n_array-1 && j!=batas){					//bila indeksnya bukan diawal dan bukan diakhir
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else if(j==batas){								//bila indeksnya diakhir dan diawal
							printf("\n");							//langsung print enter
					}else if(j==n_array-1 && j!=batas){				//bila indeksnya diawal dan bukan diakhir
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}
				//-----------------------------------print pola angka 8 baris ke-3-----------------------------------------------------
				}else if(array[j]==8){								//syarat ketemu angka 8
					if(j!=n_array-1 && j!=batas){					//bila indeksnya bukan diawal dan bukan diakhir
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else if(j==n_array-1 && j==batas){				//bila indeksnya diawal dan diakhir
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						printf("\n");								//print enter
					}else if(j!=n_array-1 && j==batas){				//bila indeksnya bukan diawal dan berada diakhir
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						printf("\n");								//print enter
					}else if(j==n_array-1 && j!=batas){				//bila indeksnya diawal dan buka diakhir
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");		
						}
					}
				//-----------------------------------print pola angka 9 baris ke-3-----------------------------------------------------
				}else if(array[j]==9){								//syarat angka ketemu angka 9
					if(j!=n_array-1 && j!=batas){					//bila indeks bukan diawal dan bukan daikhir
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else if(j==n_array-1 && j==batas){				//bila indeks diawal dan diakhir
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						printf("\n");								//print enter
					}else if(j!=n_array-1 && j==batas){				//bila indeksnya bukan diawal dan berada diakhir
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						printf("\n");								//print enter
					}else if(j==n_array-1 && j!=batas){				//bila indeksnya diawal dan bukan diakhir
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){							//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}
				}
			}
		}
		//--------------------------------------------------------baaris ke 4-----------------------------------
		for(i=0; i<m; i++){						//print pola sesuai ketebalan ke bawah
			y=0;	//direset kembali menjadi 0
			for(j=n_array-1; j>=0; j--){		//proses pemilihan 0
				//-------------------------------print negatif baris ke 4-----------------------------------------------------------------------------------------------
				if(x==1 && y==0){				//syarat negatif
					for(a=0; a<m; a++){			//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){			//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){			//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){			//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
				}
				y=1;							//bila sudah nemu negatif maka y=1, supaya tiadak kembali ke proses pola negatif
				//-----------------------------------print pola angka 0 baris ke-4-----------------------------------------------------
				if(array[j]==0){				//syarat kemu angka 0
					for(a=0; a<m; a++){			//for ini untuk ngeprint 0 sesuai ketebalan ke samping
						printf("0");
					}
					for(a=0; a<m; a++){			//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){			//for ini untuk ngeprint 0 sesuai ketebalan ke samping
						printf("0");
					}
					if(j!=0){					//bila indeksnya bukan diakhir
						for(a=0; a<m; a++){		//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else{						//bila indeksnya diakhir
						printf("\n");			//langsung print enter
					}
				//-----------------------------------print pola angka 1 baris ke-4-----------------------------------------------------
				}else if(array[j]==1){					//syarat ketemu angka 1
					if(j!=n_array-1 && j!=0){			//bila indeksnya bukan diawal dan bukan diakhir
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){				//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else if(j==n_array-1 && j!=0){		//bila indeksnya diawal dan bukan diakhir
						if(x==1){						//bila ada negatif
							for(a=0; a<m; a++){			//for ini untuk ngeprint spasi sesuai ketebalan ke samping
								printf(" ");
							}
						}
						for(a=0; a<m; a++){				//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else if(j!=n_array-1 && j==0){		//bila indeksnya bukan diawal dan berada diakhir
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");				
						}
						for(a=0; a<m; a++){				//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						printf("\n");					//print enter
					}else if(j==n_array-1 && j==0){		//bila indeksnya diawal dan diakhir
						if(x==1){						//bila ada negatif
							for(a=0; a<m; a++){			//for ini untuk ngeprint spasi sesuai ketebalan ke samping
								printf(" ");
							}
						}
						for(a=0; a<m; a++){				//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						printf("\n");					//print enter
					}
				//-----------------------------------print pola angka 2 baris ke-4-----------------------------------------------------
				}else if(array[j]==2){					//bila ketemua angka 2
					for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
						printf("0");
					}
					if(j!=0){							//bila indeksnya bukan diakhir
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else{								//bila indeksnya diakhir
						printf("\n");					//langsung print enter
					}
				//-----------------------------------print pola angka 3 baris ke-4-----------------------------------------------------
				}else if(array[j]==3){					//bila ketemu angka 3
					if(j!=n_array-1 && j!=0){			//bila indeksnya bukan diawal dan buka diakhir
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){				//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else if(j==n_array-1 && j==0){		//bila indeksnya diawal dan diakhir
						if(x==1){						//bila ada negatif
							for(a=0; a<m; a++){			//for ini untuk ngeprint spasi sesuai ketebalan ke samping
								printf(" ");
							}
						}
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){				//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						printf("\n");					//print enter
					}else if(j==n_array-1 && j!=0){		//bila indeksnya diawal dan bukan diakhir
						if(x==1){						//bila ada negatif
							for(a=0; a<m; a++){			//for ini untuk ngeprint spasi sesuai ketebalan ke samping
								printf(" ");
							}
						}
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){				//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else if(j!=n_array-1 && j==0){		//bila indeksnya bukan diawal dan berada diakhir
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){				//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						printf("\n");					//print enter
					}
				//-----------------------------------print pola angka 4 baris ke-4-----------------------------------------------------
				}else if(array[j]==4){					//syarat ketemua angka 4
					for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
						printf("0");
					}
					if(j!=0){							//bila indeksnya bukan diakhir	
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else{								//bila indeksnya diakhir
						printf("\n");					//langsung print enter
					}
				//-----------------------------------print pola angka 5 baris ke-4-----------------------------------------------------
				}else if(array[j]==5){					//syarat ketemu angka 5
					for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
						printf("0");
					}
					if(j!=0){							//bila indeksnya bukan diakhir
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else{								//bila indeksnya diakhir
						printf("\n");					//langsung print enter
					}
				//-----------------------------------print pola angka 6 baris ke-4-----------------------------------------------------
				}else if(array[j]==6){					//bila ketemu angka 6
					for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
						printf("0");
					}
					for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
						printf("0");
					}
					if(j!=0){							//bila indeksnya bukan diakhir 
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else{								//bila indeksnya diakhir
						printf("\n");					//langsung print enter
					}
				//-----------------------------------print pola angka 7 baris ke-4-----------------------------------------------------
				}else if(array[j]==7){					///bila ketemu angka 7
					for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");					
					}
					for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
						printf("0");
					}
					if(j!=0){							//bila indeksnya bukan diakhir
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else{								//bila indeksnya di akhir
						printf("\n");					//langsung print enter
					}
				//-----------------------------------print pola angka 8 baris ke-4-----------------------------------------------------
				}else if(array[j]==8){					//bila ketemu angka 8
					for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
						printf("0");
					}
					for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
						printf("0");
					}
					if(j!=0){							//bila indeksnya bukan diakhir
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else{								//bila indeksnya diakhir
						printf("\n");					//langsung print enter
					}
				//-----------------------------------print pola angka 9 baris ke-4-----------------------------------------------------
				}else if(array[j]==9){					//syarat ketemu angka 9
					for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
						printf("0");
					}
					if(j!=0){							//bila indeksnya bukan diakhir
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else{								//bila indeksnya diakhir
						printf("\n");					//langsung print enter
					}
				}
			}
		}
		//-------------------------------------------------baaris ke 5-------------------------------------------------------
		//peberian batas untuk angka 1 dan 7 kareana angka tersebut di baris ke 5 polanya kosong
		z=0;			//iterasi
		batas = 0;		//untuk batasan
		while(z<n_array){			//prosesnya diulang selama z kurang dari n_array	
			if((array[z]==1 || array[z]==7) ){			//syarat bila ketemu angka 1 dan 7
				batas = z + 1;							//nilai batas menjadi nilai z ditambah 1
				if(batas==n_array){						//bila batas sama dengan nilai n_array
					batas = z;							//batas sama dengan z
				}
			}else{										//bila bukan angka 1 atau 7
				z = n_array;							//nilai z menjadi sama denagnnilai n_Array
			}
			z++;										//nilai z terus bertambah sesuai pengulangan
		}
		for(i=0; i<m; i++){								//print pola sesuai ketebalan kebawah
			y=0;										//y direset kemballi kjadi 0
			for(j=n_array-1; j>=batas; j--){			//pemilihan angka
				//----------------------------------------------------------------pola negatif baris ke 5--------------------------------------------------------------------------------
				if(x==1 && y==0){						//syarat negatif
					if(batas==n_array-1 && (array[n_array-1]==1 || array[n_array-1]==7)){		//bila batas=n_array-1 dan angka awalnya 1 dan 7
						y=1;							//ymenjadi satu karena ada negatif
					}else{								//bial tidak sesuai persyaratan 
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping		
							printf(" ");
						}
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						y=1;							//y=1 karena ada negatif, dan supaya tidak balik lagi ke pola negatif
					}
				}
				//-----------------------------------print pola angka 0 baris ke-5-----------------------------------------------------
				if(array[j]==0){						//syarat ketemu angka 0
					for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
						printf("0");
					}
					if(j!=batas){						//bila indeksnya bukan diakhir 
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else{								//bila indeksny diakhir
						printf("\n");					//langsung print enter
					}
				//-----------------------------------print pola angka 1 baris ke-5-----------------------------------------------------
				}else if(array[j]==1){					//bila ketemu angka 1
					if(j!=n_array-1 && j!=batas){		//bila indeksnya bukan diawal dan bukan diakhir
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else if(j==batas){					//bila indeksnya diakhir dan diakhir
							printf("\n");				//langsung print enter
					}else if(j==n_array-1 && j!=batas){		//bila indeksnya diawal dan bukan diakhir
						if(x==1){							//bila ada negatif
							for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
								printf(" ");
							}
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}
				//-----------------------------------print pola angka 2 baris ke-5-----------------------------------------------------
				}else if(array[j]==2){						//syarat ketemu angka 2
					for(a=0; a<m; a++){						//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){						//for ini untuk ngeprint 0 sesuai ketebalan ke samping
						printf("0");
					}
					if(j!=batas){							//bila indeksnya bukan diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else{									//bila indeksnya diakhir
						printf("\n");						//langsung print enter
					}
				//-----------------------------------print pola angka 3 baris ke-5-----------------------------------------------------
				}else if(array[j]==3){						//syarat ketemu angka 3
					if(j!=n_array-1 && j!=batas){			//bila indeksnya bukan diawal dan bukan diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}	
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}	
					}else if(j==n_array-1 && j==batas){		//bila indeksnya diawal dan diakhir
						if(x==1){							//bila ada negatif
							for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
								printf(" ");
							}
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						printf("\n");						//print enter
					}else if(j==n_array-1 && j!=batas){		//bila indeksnya diawal dan bukan diakhir
						if(x==1){							//bila ada negatif
							for(a=0; a<m; a++){				//for ini untuk ngeprint spasi sesuai ketebalan ke samping
								printf(" ");
							}
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else if(j!=n_array-1 && j==batas){		//bila indeksnya bukan diawal dan berada diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint 0 sesuai ketebalan ke samping
							printf("0");
						}
						printf("\n");						//print enter
					}
				//-----------------------------------print pola angka 4 baris ke-5-----------------------------------------------------
				}else if(array[j]==4){						//syarat ketemu angka 4
					for(a=0; a<m; a++){						//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){						//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){						//for ini untuk ngeprint 0 sesuai ketebalan ke samping
						printf("0");
					}
					if(j!=batas){							//bila indeksnya bukan diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else{									//bila indeksnya iakhir
						printf("\n");						//langsung print enter
					}
				//-----------------------------------print pola angka 5 baris ke-5-----------------------------------------------------
				}else if(array[j]==5){						//syarat ketemua ngka 5
					for(a=0; a<m; a++){						//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){						//for ini untuk ngeprint 0 sesuai ketebalan ke samping
						printf("0");
					}
					if(j!=batas){							//bila indeksnya bukan diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else{									//bila indeksnya diakhir
						printf("\n");						//langsung print spasi
					}
				//-----------------------------------print pola angka 6 baris ke-5-----------------------------------------------------
				}else if(array[j]==6){						//syarat ketemu angka 6
					for(a=0; a<m; a++){						//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){						//for ini untuk ngeprint 0 sesuai ketebalan ke samping
						printf("0");
					}
					if(j!=batas){							//bila indeksnya bukan diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else{									//bila indeksnya di akhir
						printf("\n");						//langsung print spasi
					}
				//-----------------------------------print pola angka 7 baris ke-5-----------------------------------------------------
				}else if(array[j]==7){						//syarat ketemu angka 7
					if(j!=n_array-1 && j!=batas){			//bila indeksnya bukan diawal dan bukan diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");		
						}	
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else if(j==batas){						//bila indeksnya diawal dan diakhir
							printf("\n");					//langsung print enter
					}else if(j==n_array-1 && j!=batas){		//bila indeksnya diawal dan bukan diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}
				//-----------------------------------print pola angka 8 baris ke-5-----------------------------------------------------
				}else if(array[j]==8){						//syarat ketemu angka 8
					for(a=0; a<m; a++){						//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){						//for ini untuk ngeprint 0 sesuai ketebalan ke samping
						printf("0");
					}
					if(j!=batas){							//bil indeksnya bukan diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else{									//bila indeksnya diakhir
						printf("\n");						//langsung print enter
					}
				//-----------------------------------print pola angka 9 baris ke-5-----------------------------------------------------
				}else if(array[j]==9){						//syarat ketemu angka angka 9
					for(a=0; a<m; a++){						//for ini untuk ngeprint spasi sesuai ketebalan ke samping
						printf(" ");
					}
					for(a=0; a<m; a++){						//for ini untuk ngeprint 0 sesuai ketebalan ke samping
						printf("0");
					}
					if(j!=batas){							//bila indeksnya bukan diakhir
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
						for(a=0; a<m; a++){					//for ini untuk ngeprint spasi sesuai ketebalan ke samping
							printf(" ");
						}
					}else{									//bila indeksnya diakhri
						printf("\n");						//langsung print eneter
					}
				}
			}
		}
	}
}
//alhammdulillah.........................................................................
