#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//deklarasi file
FILE * fp;

//deklarasi typedef dan struct yang akan digunakan
typedef char isi[500];//string
typedef char input[20];
typedef struct{
	int nopegawai;
	isi nama;
	isi nohp;
	isi alamat;
}data_pegawai;//data buku

typedef struct{
	data_pegawai data[100];
}pegawai;//buku

//deklarasi prototype yang akan digunakan
void show_data(pegawai * pgw);
void search_data(pegawai * pgw);
void create_data(pegawai * pgw);
void delete_data(pegawai * pgw);
void update_data(pegawai * pgw);


int main(){
	//deklarasi variabel yang akan digunakan
	pegawai pgw;
	isi input;
	char user[10],pass[10];
	int pilihan;

	//membuat judul
	printf("\t\t===============================\n");
	printf("\t\t||        SELAMAT DATANG      ||\n");
	printf("\t\t||              DI            ||\n");
	printf("\t\t||     DATABASE PERUSAHAAN    ||\n");
	printf("\t\t===============================\n");

	//membuat perintah login
	printf("LOGIN DULU!!!\n");
	Login:
	printf("Username : ");
	gets(user);
	printf("Password : ");
	gets(pass);

	//mencocokkan nama user dan password
	if(strcmp(user,"admin")==0){
		if(strcmp(pass,"root")==0){
			printf("\nLogin Berhasil !!!\n");
		}else{
			printf("\nPassword Salah !!!\n");
			goto Login;
		}
	}else{
		printf("\nUsername dan Password Tidak Sesuai !!!\n");
		goto Login;
	}

	//membuat menu
	Menu:
	printf("\nMENU :\n");
	printf("1. Tampilkan Data Pegawai\n");
	printf("2. Cari Data Pegawai\n");
	printf("3. Tambah Data Pegawai\n");
	printf("4. Hapus Data Pegawai\n");
	printf("5. Ubah Data Pegawai  \n");
	printf("6. Keluar\n");
	printf("Masukkan Pilihan : ");
	scanf("%d", &pilihan);
	printf("\n");


	//menjalankan pilihan sesuai yang diinput user
	switch(pilihan){

	//pilihan untuk menampikan data
		case 1:
		show_data(&pgw);
		printf("nn\n");
		goto Menu;
 	
 	//pilihan untuk mencari data
		case 2:
		search_data(&pgw);
		goto Menu;

	//pilihan untuk menambah data
		case 3:
		create_data(&pgw);
		goto Menu;
		
	//pilihan untuk menghapus data
		case 4:
		show_data(&pgw);
		delete_data(&pgw);
		show_data(&pgw);
		goto Menu;
		
	//pilihan untuk mengubah data
		case 5:
		update_data(&pgw);
		goto Menu;
		
	//pilihan untuk keluar
		case 6:
		printf("\nExiting....\n");
		break;

		default :
		printf("\npilihan tidak ada\n");
		goto Menu;
	}
}

//fungsi untuk menampilkan data
void show_data(pegawai * pgw){
	//deklarasi variabel yang akan digunakan
	char buff[200];
	int c,i,n;

	//membuka file
	fp = fopen("data.txt","r");

	//loop untuk menampilkan data ke layar
	while((c=fgetc(fp)) != EOF){
		putchar(c);//menampilkan data kelayar
	}
	//menutup file
	fclose(fp);
}


//fungsi untuk mencari data
void search_data(pegawai * pgw){
	//deklarasi variabel yang digunakan
	int c, no;
	//membuka file
	 fp = fopen("data.txt", "r");

	 //memcetak perintah memaskkan no pegawai dan mengambilnya
	 printf("Masukkan no pegawai : ");
	 scanf("%d", &no);

	 //loop untuk menampilkan data ke layar
	 for(int i=0; i <= sizeof(fp); i++){
			if(((*pgw).data[i].nopegawai)== no ){
				printf("%s", &(*pgw).data[i].nopegawai);
				printf("%s", &(*pgw).data[i].nama);
				printf("%s", &(*pgw).data[i].nohp);
				printf("%s", &(*pgw).data[i].alamat);
				}
			}
	//menutup file
	fclose(fp);
}

//fungsi untuk menambah data
void create_data(pegawai * pgw){
	//deklarasi file untuk digunakan
	char lanjut;
	int masuk;

	//membuka file
	fp = fopen("data.txt","r+");

	//mengambil data yang ingin dimasukkan
	printf("Berapa data yang ingin anda masukkan ? : ");
	scanf("%d",&masuk);

	//loop untuk mengambil data
	for(int i=(sizeof(fp)+1); i<=(masuk+sizeof(fp)); i++){
		//mengambil no pegawai dan memasukkan kedalam file
	printf("Masukkan Kode Pegawai : ");
	scanf("%s",&(*pgw).data[i].nopegawai);
	fprintf(fp, "%s, ", &(*pgw).data[i].nopegawai);

	//mengambil nama pegawai dan memasukkan kedalam file
	printf("Masukkan Nama Pegawai : ");
	scanf("%s",&(*pgw).data[i].nama);
	fprintf(fp, "%s, ", &(*pgw).data[i].nama);

	//mengambil no hp dan memasukkan kedalam file
	printf("Masukkan No.Hp pegawai : ");
	scanf("%s",&(*pgw).data[i].nohp);
	fprintf(fp, "%s, ", &(*pgw).data[i].nohp);

	//mengambil alamat dan memasukkan kedalam file
	printf("Masukkan Alamat Pegawai : ");
	scanf("%s",&(*pgw).data[i].alamat);
	fprintf(fp, "%s\n", &(*pgw).data[i].alamat);

	//menanyakan kepada user apakah ingin melanjutkan input
	lanjut:
	printf("lanjut ? (y/n) : ");
	getchar();scanf("%c",&lanjut);

	if(i < masuk+sizeof(fp)){
	if(lanjut=='y'){
		continue;
	}else if(lanjut=='n'){
		break;
	}else{
		printf("masukkan anda salah\n ");
		goto lanjut;
	}
}
	}
	//tutup file
	fclose(fp);
}

//fungsi untuk menghapus data
void delete_data(pegawai * pgw){
	//deklarasi variabel yang ingin digunakan
	int n,status,c;
	char p;
	//membuka file
	fp = fopen("data.txt","r+");

	printf("\n\nMasukkan No. pegawai :");
	scanf("%d", n);//mengambil no pegawai

	printf("Yakin ingin menghapus ? (y/n) : ");
	scanf("%c", &p);
	if(p=='y'|| p=='Y'){
		for(int i=0; i <= sizeof(fp); i++){
			//menghilangkan data
			if(((*pgw).data[i].nopegawai)== n ){
				(*pgw).data[i].nopegawai == ' ';
			}
		}
	}

}

//fungsi untuk mengupdate data
void update_data(pegawai * pgw){
	//deklarasi variabel yang ingin digunakan
	int n,a;
	char b[20],c[20],d[20];
	char p;

	//membuka file
	fp = fopen("data.txt","r+");

	printf("Masukkan No. pegawai");
	scanf("%d", n);//mengambil no pegawai

	//mengubah no pegawai
	printf("Apakah ingin mengubah no. pegawai ? (y/n) : ");
	scanf("%c", &p);
	if(p=='y'|| p=='Y'){
		printf("Masukkan no pegawai : ");
		scanf("%d",&a);
			for(int i=0; i <= sizeof(fp); i++){
				//mengupdate record 
				if(((*pgw).data[i].nopegawai)== n ){
					(*pgw).data[i].nopegawai= a;
					printf("\nBERHASIL !!!\n");
				}
			}
	}

	//mengubah nama pegawai
	printf("Apakah ingin mengubah nama pegawai ? (y/n) : ");
	scanf("%c", &p);
	if(p=='y' || p=='Y'){
		printf("Masukkan nama pegawai : ");
		scanf("%s",&b);
			for(int i=0; i <= sizeof(fp); i++){
				if(((*pgw).data[i].nopegawai)== n ){
					//mengupdate record
					strcpy((*pgw).data[i].nama, b) ;
					printf("\nBERHASIL !!!\n");
				}
			}
	}

	//mengubah no. hp pegawai
	printf("Apakah ingin mengubah no. Hp pegawai ? (y/n) : ");
	scanf("%c", &p);
	if(p=='y'|| p=='Y'){
		printf("Masukkan no. Hp pegawai : ");
		scanf("%s",&c);
		for(int i=0; i <= sizeof(fp); i++){
				if(((*pgw).data[i].nopegawai)== n ){
					//mengupdate record
					strcpy((*pgw).data[i].nohp, c);
					printf("\nBERHASIL !!!\n");
				}
			}
	}

	//mengubah alamat pegawai
	printf("Apakah ingin mengubah alamat pegawai ? (y/n) : ");
	scanf("%c", &p);
	if(p=='y'|| p=='Y'){
		printf("Masukkan alamat pegawai : ");
		scanf("%s",&d);
		for(int i=0; i <= sizeof(fp); i++){
				if(((*pgw).data[i].nopegawai)== n ){
					//mengupdate record
					strcpy((*pgw).data[i].alamat, d);
					printf("\nBERHASIL !!!\n");
				}
			}
	}

}
