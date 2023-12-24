#include <stdio.h>
#include <stdlib.h>

//"Teklif" adinda bir struct tanýmlar
typedef struct {
	
    int teklifveren_no;
    double teklif;
    
}Teklif;

//"teklifler" dizisinin verilerini "Teklif" structure'ýnda tutmasý için pointer tanýmlar

Teklif* teklifler;


//En yüksek teklifi bulmak için bir fonksiyon tanýmlar

double odemeyi_hesapla(Teklif* teklifler , int teklifveren_sayisi) {
    
	int i = 0;
    double odeme = 0.0;
	

//"teklifveren_sayisi" degiskeninin 0 olmasý halinde programý sonlandýrýr

	if (teklifveren_sayisi == 0) {
       
        return 0;
    }
    
    
//En büyük teklifi bularak "odeme" deðiþkenine eþitler

    for (i ; i < teklifveren_sayisi; ++i) {
        if (teklifler[i].teklif > odeme) {
            odeme = teklifler[i].teklif;
        }
    }

    return odeme;
}


//Kazanan teklifi verenin numarasýný bulan ve yazdýran bir fonksiyon oluþturur.

void acikarttirma(Teklif* teklifler, int teklifveren_sayisi) {
    
//"teklifveren_sayisi"'nýn 0 olmasý halinde programý durdurur    
    
	if (teklifveren_sayisi == 0) {
        printf("Teklif veren kimse yok");
        return;
    }
    
    
//Yeni bir "odeme" degiskeni olusturarak fonksiyonu uygular ve eþitler
    
	double odeme = odemeyi_hesapla(teklifler, teklifveren_sayisi);
    int kazanan_no = 0;
    int i = 0;


//Kazanan teklifi verenin numarasýný bulur ve yazdýrýr

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


//Deðiþkenleri kullanýcýdan ister

    printf("Teklif veren kac kisi var ? : ");
    scanf("%d", &teklifveren_sayisi);


//"malloc" fonksiyonu ile kullanýcýnýn girdiði "teklifveren_sayisi" kadar hafýzada yer ayrýlýr

    Teklif* teklifler = (Teklif*)malloc(teklifveren_sayisi * sizeof(Teklif));
   
   
//NULL þeklinde bir pointer döndürmüþ ise programý durdurur
    
    if (teklifveren_sayisi == NULL) {
    	
        printf(stderr, "Hafiza ayrilamadi.");
        return 1;
    }


//"teklifveren_sayisi" deðiþkeninin pozitif bir tamsayý olduðunu kontrol eder

    if (teklifveren_sayisi <= 0) {
        printf("Gecersiz deger girdiniz.");
        return 1;
    }
    

//Teklif veren kiþilerin tekliflerini alýr
    
    for (i ; i < teklifveren_sayisi; ++i) {
        teklifler[i].teklifveren_no = i + 1;

        printf("%d. Kisinin teklif ettigi miktari giriniz : ", teklifler[i].teklifveren_no);
        scanf("%lf", &teklifler[i].teklif);
    }

    
//"acikarttirma" fonksiyonunu çalýþtýrýr
    
    acikarttirma(teklifler, teklifveren_sayisi);


//Program görevini tamamladýðýnda "free" fonksiyonu ile kullanýlmýþ olan hafýzayý boþaltýr

    free(teklifler);


    return 0;
}

