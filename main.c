#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct hasta{

	char 	hastaAdi[50];
	char 	odaKayitTarih[11];
	char 	ilacAdi[50];
	
	int 	hastaNo;
	int 	odaNo;
	int 	ilacNo;
	int 	gunlukIlacAdet;
	int		hastaYas;
};



int main() {
	setlocale(LC_ALL,"Turkish");//T�rk�e karakter deste�i.
	
	int islem;
	bas:
	printf("(1) Ekle\n(2) Listele\n(3) Ara\n(4) Sil\n(5) G�ncelle\n(6) ��k��\n");
	hata:
	printf("\nYapmak istedi�iniz i�lemi giriniz: ");
	scanf("%d",&islem);
	
	switch (islem){
		case 1:  ekle();
				 break;
				 
		case 2:	 listele();
				 break;
				 
		case 3:	 ara();
				 break;
				 
		case 4:	 sil();
				 break;
				 
		case 5:	 guncelle();
				 break;
				 
		case 6:  return 0; 
				 break;
				 
		default: printf("B�yle bir i�lem bulunmamaktad�r.\n");	
				 goto hata;
		
	}
	printf("\n");
	goto bas;
}

void ekle(){
	//hasta bilgileri istenip hastane.txt dosyas� i�ine at
	
	struct hasta hastaekle;
	FILE *hasta_ekle = fopen ("hastane.txt","a");
	
	
	printf("Hastan�n numaras�n� giriniz: ");
	scanf("%d",&hastaekle.hastaNo);

	printf("Hastan�n ad� giriniz: ");
	scanf("%s",hastaekle.hastaAdi);
	
	printf("Hastan�n ya��n� giriniz: ");
	scanf("%d",&hastaekle.hastaYas);
	
	printf("Hastan�n oda numaras�n� giriniz: ");
	scanf("%d",&hastaekle.odaNo);
	
	printf("Hastan�n oda kay�t tarihini giriniz(gg.aa.yyyy): ");
	scanf("%s",hastaekle.odaKayitTarih);
	
	printf("�la� numaras� giriniz: ");
	scanf("%d",&hastaekle.ilacNo);
	
	printf("�la� ad�n� giriniz: ");
	scanf("%s",hastaekle.ilacAdi);
	
	printf("G�nl�k verilecek ila� adetini giriniz: ");
	scanf("%d",&hastaekle.gunlukIlacAdet);
	
	printf("\nHasta bilgisi eklendi.\n");
	
	fprintf(hasta_ekle,"%d 	%s 	%d 	%d 	%s 	%d 	%s 	%d\n",hastaekle.hastaNo ,hastaekle.hastaAdi ,hastaekle.hastaYas ,hastaekle.odaNo, hastaekle.odaKayitTarih ,hastaekle.ilacNo, hastaekle.ilacAdi,hastaekle.gunlukIlacAdet);
	fclose(hasta_ekle);
}

void sil(){
	//kullan�c�dan hasta no istenicek ve hastane.txt dosyas�ndan kay�t silinecek
	FILE *hasta_sil = fopen ("hastane.txt","r");
	FILE *hasta_sil_yeni = fopen("hastane_yeni.txt","w+");
	struct hasta hastasil;
	int h_no,lck,i=0;
	while(!feof(hasta_sil)){
			fscanf(hasta_sil,"%d %s %d %d %s %d %s %d\n",&hastasil.hastaNo,hastasil.hastaAdi,&hastasil.hastaYas,&hastasil.odaNo,hastasil.odaKayitTarih,&hastasil.ilacNo,hastasil.ilacAdi,&hastasil.gunlukIlacAdet);
			i++;
	}
	
	if(hasta_sil==NULL||i<=1){
		printf("Silinecek bir bilgi bulunamamaktad�r veya en az 2 kay�t olmal�d�r.\n");
		fclose(hasta_sil);
		fclose(hasta_sil_yeni);
	}
	else{
		printf("\nKayd� silinecek hastan�n nosu: ");
		scanf("%d",&h_no);
		while(!feof(hasta_sil)){
			fscanf(hasta_sil,"%d %s %d %d %s %d %s %d\n",&hastasil.hastaNo,hastasil.hastaAdi,&hastasil.hastaYas,&hastasil.odaNo,hastasil.odaKayitTarih,&hastasil.ilacNo,hastasil.ilacAdi,&hastasil.gunlukIlacAdet);
			
		
			if(hastasil.hastaNo==h_no){
				printf("Hasta bilgisi silindi.\n");
				lck = 1;
			}
			else{
				fprintf(hasta_sil_yeni,"%d	 %s	 %d	 %d	 %s	 %d	 %s	 %d\n",hastasil.hastaNo,hastasil.hastaAdi,hastasil.hastaYas,hastasil.odaNo,hastasil.odaKayitTarih,hastasil.ilacNo,hastasil.ilacAdi,hastasil.gunlukIlacAdet);
			}
			i++;
		}
		printf("%d",i);
		if(lck!=1){
			printf("Bu hasta numaras�na ait veri bulunmamaktad�r.\n");
		}
		fclose(hasta_sil);
		fclose(hasta_sil_yeni);
		remove("hastane.txt");
		rename("hastane_yeni.txt","hastane.txt");
	}
}

void ara(){
	//kullan�c�dan hasta no istenecek ve hastane.txt ekrana getir
	FILE *hasta_ara = fopen ("hastane.txt","r");
	struct hasta hastaara;
	int h_no,lck;
	if(hasta_ara==NULL){
		printf("Aranacak veri bulunmamaktad�r.\n");
		pclose(hasta_ara);
	}
	else{
		printf("\nHasta numaras�n� giriniz: ");
		scanf("%d",&h_no);
		
		
		while(!feof(hasta_ara)){
			fscanf(hasta_ara,"%d	%s	%d	%d	%s	%d	%s	%d\n",&hastaara.hastaNo,hastaara.hastaAdi,&hastaara.hastaYas,&hastaara.odaNo,hastaara.odaKayitTarih,&hastaara.ilacNo,hastaara.ilacAdi,&hastaara.gunlukIlacAdet);
			
			if(hastaara.hastaNo==h_no){
				printf("\nHasta No	Hasta Ad�	Hasta Ya��	Oda Numaras�	Oda Kay�t Ta.	�la� No.	�la� Ad�	�la� Ad.\n");
				printf("\n--------------------------------------------------------------------------------------------------------\n");
				printf("%d	%s	%d	%d	%s	%d	%s	%d\n",hastaara.hastaNo,hastaara.hastaAdi,hastaara.hastaYas,hastaara.odaNo,hastaara.odaKayitTarih,hastaara.ilacNo,hastaara.ilacAdi,hastaara.gunlukIlacAdet);
				printf("\n--------------------------------------------------------------------------------------------------------\n");
				lck++;
			}
		}
		if(lck!=1){
			printf("Bu hasta numaras�na ait veri bulunmamaktad�r.\n");
		}
		fclose(hasta_ara);
	}
}

void listele(){
	//b�t�n kay�tlar� g�sterir
	struct hasta hastalistele;
	FILE *hasta_listele = fopen ("hastane.txt","r+");
	
	if(hasta_listele==NULL){
		printf("Herhangi bir hasta girdisi bulunamad� l�tfen ekleme yap�n�z.\n");
		fclose(hasta_listele);
	}
	else{
	
	printf("\nHasta No	Hasta Ad�	Hasta Ya��	Oda Numaras�	Oda Kay�t Ta.	�la� No.	�la� Ad�	�la� Ad.\n");
	printf("\n--------------------------------------------------------------------------------------------------------\n");
	
	while(!feof(hasta_listele)){
		fscanf(hasta_listele,"%d	%s	%d	%d	%s	%d	%s	%d\n",&hastalistele.hastaNo,hastalistele.hastaAdi,&hastalistele.hastaYas,&hastalistele.odaNo,hastalistele.odaKayitTarih,&hastalistele.ilacNo,hastalistele.ilacAdi,&hastalistele.gunlukIlacAdet);
		printf("%d	%s	%d	%d	%s	%d	%s	%d\n",hastalistele.hastaNo,hastalistele.hastaAdi,hastalistele.hastaYas,hastalistele.odaNo,hastalistele.odaKayitTarih,hastalistele.ilacNo,hastalistele.ilacAdi,hastalistele.gunlukIlacAdet);	
	}
	printf("--------------------------------------------------------------------------------------------------------\n");
	
	

	fclose(hasta_listele);
}
}


void guncelle(){
	//kullan�c�dan hasta no istenecek hasta bilgisi bulunup g�ncellenecek ekranda g�sterilecek
	FILE *hasta_guncelle = fopen ("hastane.txt","r");
	FILE *hasta_guncelle_yeni = fopen("hastane_yeni.txt","w+");
	struct hasta hastaguncelle;
	int h_no;
	
	if(hasta_guncelle==NULL){
		printf("G�ncellenecek veri bulunamad�.\n");
		fclose(hasta_guncelle);
		fclose(hasta_guncelle_yeni);
	}
	else{
		
		printf("\nG�ncellenecek hastan�n nosu: ");
		scanf("%d",&h_no);
		while(!feof(hasta_guncelle)){
			fscanf(hasta_guncelle,"%d	%s	%d	%d	%s	%d	%s	%d\n",&hastaguncelle.hastaNo,hastaguncelle.hastaAdi,&hastaguncelle.hastaYas,&hastaguncelle.odaNo,hastaguncelle.odaKayitTarih,&hastaguncelle.ilacNo,hastaguncelle.ilacAdi,&hastaguncelle.gunlukIlacAdet);
			
			if(h_no==hastaguncelle.hastaNo){
				printf("Hastan�n ad� giriniz: ");
				scanf("%s",hastaguncelle.hastaAdi);
		
				printf("Hastan�n ya��n� giriniz: ");
				scanf("%d",&hastaguncelle.hastaYas);
		
				printf("Hastan�n oda numaras�n� giriniz: ");
				scanf("%d",&hastaguncelle.odaNo);
		
				printf("Hastan�n oda kay�t tarihini giriniz(gg.aa.yyyy): ");
				scanf("%s",hastaguncelle.odaKayitTarih);
		
				printf("�la� numaras� giriniz: ");
				scanf("%d",&hastaguncelle.ilacNo);
		
				printf("�la� ad�n� giriniz: ");
				scanf("%s",hastaguncelle.ilacAdi);
		
				printf("G�nl�k verilecek ila� adetini giriniz: ");
				scanf("%d",&hastaguncelle.gunlukIlacAdet);
				
				printf("G�ncelleme ba�ar�l�.\n");
				
				fprintf(hasta_guncelle_yeni,"%d 	%s 	%d 	%d 	%s 	%d 	%s 	%d\n",hastaguncelle.hastaNo ,hastaguncelle.hastaAdi ,hastaguncelle.hastaYas ,hastaguncelle.odaNo, hastaguncelle.odaKayitTarih ,hastaguncelle.ilacNo, hastaguncelle.ilacAdi,hastaguncelle.gunlukIlacAdet);
	
			}
			else{
				fprintf(hasta_guncelle_yeni,"%d		%s		%d		%d		%s		%d		%s		%d\n",hastaguncelle.hastaNo,hastaguncelle.hastaAdi,hastaguncelle.hastaYas,hastaguncelle.odaNo,hastaguncelle.odaKayitTarih,hastaguncelle.ilacNo,hastaguncelle.ilacAdi,hastaguncelle.gunlukIlacAdet);
			}	
		}
	
		fclose(hasta_guncelle);
		fclose(hasta_guncelle_yeni);
		remove("hastane.txt");
		rename("hastane_yeni.txt","hastane.txt");
	}
}


