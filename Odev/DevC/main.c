#include <stdio.h>
#include <stdlib.h>

//"Teklif" adinda bir struct tan�mlar
typedef struct {
	
    int teklifveren_no;
    double teklif;
    
}Teklif;

//"teklifler" dizisinin verilerini "Teklif" structure'�nda tutmas� i�in pointer tan�mlar

Teklif* teklifler;


//En y�ksek teklifi bulmak i�in bir fonksiyon tan�mlar

double odemeyi_hesapla(Teklif* teklifler , int teklifveren_sayisi) {
    
	int i = 0;
    double odeme = 0.0;
	

//"teklifveren_sayisi" degiskeninin 0 olmas� halinde program� sonland�r�r

	if (teklifveren_sayisi == 0) {
       
        return 0;
    }
    
    
//En b�y�k teklifi bularak "odeme" de�i�kenine e�itler

    for (i ; i < teklifveren_sayisi; ++i) {
        if (teklifler[i].teklif > odeme) {
            odeme = teklifler[i].teklif;
        }
    }

    return odeme;
}


//Kazanan teklifi verenin numaras�n� bulan ve yazd�ran bir fonksiyon olu�turur.

void acikarttirma(Teklif* teklifler, int teklifveren_sayisi) {
    
//"teklifveren_sayisi"'n�n 0 olmas� halinde program� durdurur    
    
	if (teklifveren_sayisi == 0) {
        printf("Teklif veren kimse yok");
        return;
    }
    
    
//Yeni bir "odeme" degiskeni olusturarak fonksiyonu uygular ve e�itler
    
	double odeme = odemeyi_hesapla(teklifler, teklifveren_sayisi);
    int kazanan_no = 0;
    int i = 0;


//Kazanan teklifi verenin numaras�n� bulur ve yazd�r�r

    for (i ; i < teklifveren_sayisi; ++i) {
        if (teklifler[i].teklif == odeme) {

            kazanan_no += teklifler[i].teklifveren_no;

            printf("%d. Teklifi veren kisi kazandi\n" , kazanan_no);

        }
    }

    printf("\n");
    printf("Teklif ettigi miktar ise: %.2lf TL'idi", odeme);
}

int main() {

    int i = 0;
    int teklifveren_sayisi;


//De�i�kenleri kullan�c�dan ister

    printf("Teklif veren kac kisi var ? : ");
    scanf("%d", &teklifveren_sayisi);


//"malloc" fonksiyonu ile kullan�c�n�n girdi�i "teklifveren_sayisi" kadar haf�zada yer ayr�l�r

    Teklif* teklifler = (Teklif*)malloc(teklifveren_sayisi * sizeof(Teklif));
   
   
//NULL �eklinde bir pointer d�nd�rm�� ise program� durdurur
    
    if (teklifveren_sayisi == NULL) {
    	
        printf(stderr, "Hafiza ayrilamadi.");
        return 1;
    }


//"teklifveren_sayisi" de�i�keninin pozitif bir tamsay� oldu�unu kontrol eder

    if (teklifveren_sayisi <= 0) {
        printf("Gecersiz deger girdiniz.");
        return 1;
    }
    

//Teklif veren ki�ilerin tekliflerini al�r
    
    for (i ; i < teklifveren_sayisi; ++i) {
        teklifler[i].teklifveren_no = i + 1;

        printf("%d. Kisinin teklif ettigi miktari giriniz : ", teklifler[i].teklifveren_no);
        scanf("%lf", &teklifler[i].teklif);
    }

    
//"acikarttirma" fonksiyonunu �al��t�r�r
    
    acikarttirma(teklifler, teklifveren_sayisi);


//Program g�revini tamamlad���nda "free" fonksiyonu ile kullan�lm�� olan haf�zay� bo�alt�r

    free(teklifler);


    return 0;
}

