#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE * fp;

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

void show_data(pegawai * pgw);
void search_data(pegawai * pgw);
void create_data(pegawai * pgw);
void delete_data(pegawai * pgw);
void update_data(pegawai * pgw);

int main(){
	pegawai pgw;
	isi input;
	char user[10],pass[10];
	int pilihan;

	printf("\t\t===============================\n");
	printf("\t\t||        SELAMAT DATANG      ||\n");
	printf("\t\t||              DI            ||\n");
	printf("\t\t||     DATABASE PERUSAHAAN    ||\n");
	printf("\t\t===============================\n");

	
	printf("LOGIN DULU!!!\n");
	Login:
	printf("Username : ");
	gets(user);
	printf("Password : ");
	gets(pass);

	if(strcmp(user,"admin")==0){
		if(strcmp(pass,"root")==0){
			printf("\nLogin Berhasil !!!\n");
		}else{
			printf("Password Salah !!!\n");
			goto Login;
		}
	}else{
		printf("Username dan Password Tidak Sesuai !!!\n");
		goto Login;
	}
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


	
	switch(pilihan){

		case 1:
		show_data(&pgw);
		printf("nn\n");
		goto Menu;
 
		case 2:
		search_data(&pgw);
		goto Menu;

		case 3:
		create_data(&pgw);
		goto Menu;
		
		case 4:
		show_data(&pgw);
		delete_data(&pgw);
		show_data(&pgw);
		goto Menu;
		
		case 5:
		update_data(&pgw);
		goto Menu;
		
		case 6:
		printf("\nExiting....\n");
		break;

		default :
		printf("\npilihan tidak ada\n");
		goto Menu;
	}
}

void show_data(pegawai * pgw){
	char buff[200];
	int c,i,n;


	fp = fopen("data.txt","r");

	while((c=fgetc(fp)) != EOF){
		putchar(c);
	}
	fclose(fp);
}



void search_data(pegawai * pgw){
	pegawai p;
	int c,k;
	 fp = fopen("data.txt", "r");

	printf("Masukkan no Pegawai : ");
	scanf("%d", &k);

	while((c=fgetc(fp)) != EOF){
		if(c == k){
			putchar(c);
		}
	}

	fclose(fp);
}

void create_data(pegawai * pgw){//fungsi untuk menambah data
	char lanjut;
	int masuk;
	fp = fopen("data.txt","r+");
	printf("%d\n",sizeof(fp) );

	printf("Berapa data yang ingin anda masukkan ? : ");
	scanf("%d",&masuk);

	for(int i=(sizeof(fp)+1); i<=(masuk+sizeof(fp)); i++){
	printf("Masukkan Kode Pegawai : ");
	scanf("%s",&(*pgw).data[i].nopegawai);
	fprintf(fp, "%s, ", &(*pgw).data[i].nopegawai);

	printf("Masukkan Nama Pegawai : ");
	scanf("%s",&(*pgw).data[i].nama);
	fprintf(fp, "%s, ", &(*pgw).data[i].nama);

	printf("Masukkan No.Hp pegawai : ");
	scanf("%s",&(*pgw).data[i].nohp);
	fprintf(fp, "%s, ", &(*pgw).data[i].nohp);

	printf("Masukkan Alamat Pegawai : ");
	scanf("%s",&(*pgw).data[i].alamat);
	fprintf(fp, "%s\n", &(*pgw).data[i].alamat);

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
	fclose(fp);
}


void delete_data(pegawai * pgw){
	int n;
	char p;
	pegawai delete;

	printf("Masukkan No. pegawai");
	scanf("%d", n);

	printf("Yakin ingin menghapus ? (y/n) : ");
	scanf("%c", &p);
	if(p=='y'|| p=='Y'){
		//delete
	}

	

}

void update_data(pegawai * pgw){
	int n,a;
	input b,c,d;
	char p;

	pegawai update;

	printf("Masukkan No. pegawai");
	scanf("%d", n);

	printf("Apakah ingin mengubah no. pegawai ? (y/n) : ");
	scanf("%c", &p);
	if(p=='y'|| p=='Y'){
		printf("Masukkan no pegawai : ");
		scanf("%d",&a);
	}

	printf("Apakah ingin mengubah nama pegawai ? (y/n) : ");
	scanf("%c", &p);
	if(p=='y' || p=='Y'){
		printf("Masukkan nama pegawai : ");
		scanf("%s",&b);
	}

	printf("Apakah ingin mengubah no. Hp pegawai ? (y/n) : ");
	scanf("%c", &p);
	if(p=='y'|| p=='Y'){
		printf("Masukkan no. Hp pegawai : ");
		scanf("%s",&c);
	}

	printf("Apakah ingin mengubah alamat pegawai ? (y/n) : ");
	scanf("%c", &p);
	if(p=='y'|| p=='Y'){
		printf("Masukkan alamat pegawai : ");
		scanf("%s",&d);
	}


}
