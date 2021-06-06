#include <stdio.h>
#include <conio.h> //MENGGUNAKAN GETCH()
#include <stdlib.h> //MENGGUNAKAN SYSTEM("CLS)
#define MAX 1000 //MAKSIMAL NOMOR ANTRIAN

int nomer[MAX];
int head=-1;
int tail=-1;


void AntrianMasuk(int no){
    if (tail == -1){
        head=tail=0;
    }else {
        tail++;
    }
    nomer[tail]=no;
}

void AntrianKeluar(){
    if(tail == -1){
    	printf("Antrian sudah kosong ! ");
        getch();
    }else {
    	int a = head;
        for(a=head; a<tail; a++){
            nomer[a]=nomer[a+1];
        }
        tail--;
        if(tail == -1){
            head = -1;
        }
    }
}

void Clear(){
     head=tail=-1;
}

void View(){
     if(tail == 1){
     	printf("Antrian kosong ! ");

     }else {
         system("cls");
         int a = head;
         for(a=head;a<=tail;a++){
         	printf("===============================\n");
        	printf("No Antri: %d\n", nomer[a]);
         }
     }
}

int main(){
    system("color 07");
    int choose, p=1, urut; //deklarasi untuk pilihan user dan nomer urut antrian
    do{
        system("cls");
        printf("===== PROGRAM ANTRIAN C ===== \n===============================\n1. Tambah Antrian            \n2. Panggil Antrian           \n3. Lihat daftar antrian      \n4. Hapus Antrian                    \n5. Exit                      \n===============================");
		printf("\npilihan : ");
		scanf("%d", &choose);
        if(choose == 1){
            if(tail == MAX-1) {
            	printf("Antrian sudah penuh, mohon tunggu beberapa saat lagi ");
            }
            else{
                urut=p;
                AntrianMasuk(urut);
                printf("---------------------------------\n");
                printf("|          NO. ANTRIAN          |\n");
                printf("|               %d               |\n", p);
                printf("---------------------------------\n");
                printf("|       Silahkan Mengantri      |\n");
                printf("|      Menunggu %d Antrian       |\n", tail);
                printf("---------------------------------\n");
                p++;
            }
        }
        else if(choose == 2){
        	printf("=================================\n");
        	printf("No. Antri : %d\n", nomer[head]);
        	printf("=================================\n");
            AntrianKeluar();
            printf("Silahkan Dipanggil");
        }
        else if(choose == 3){
            View();
        }
        else if(choose == 4){
            Clear();
            printf("Antrian dikosongkan ! ");
        }
        else if(choose == 5){
        }
        else{
        	printf("Masukan anda salah ! \n");
        }
        getch();
    }while(choose!=5);
}
