#include <stdio.h>
#include <stdlib.h>

typedef struct {

    int teklifveren_sayisi;

}Artirma;


typedef struct {

    int teklifveren_sayisi;
    int teklifveren_no;
    double teklif;

}Teklif;

Teklif* teklifler;


double odemeyihesapla(Teklif* teklifler, int kazanan_no){

    int teklifveren_sayisi;
    double odeme = 0.0;
    int i = 0;

    for(i ; i < teklifveren_sayisi  ; i++){

        if(i != kazanan_no){

            odeme += teklifler[i].teklif;
        }

    }

    return odeme;

}

void acikarttirma(Teklif* teklifler){

    int i = 0;
    int teklifveren_sayisi;
    double enyuksek_teklif;
    int kazanan_no;

    for (i ; i < teklifveren_sayisi; ++i) {
        if (teklifler[i].teklif > enyuksek_teklif) {
            enyuksek_teklif = teklifler[i].teklif;
        }
    }

    for(i ; i < teklifveren_sayisi ; i++){

        if(teklifler[i].teklif == enyuksek_teklif){

            kazanan_no = i;

            printf("kazanan kisi = %d", i);




        }
    }

    odemeyihesapla(teklifler , kazanan_no);

    printf("\nodeme = %d" , enyuksek_teklif);



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

    acikarttirma(teklifler);


//Program g�revini tamamlad���nda "free" fonksiyonu ile kullan�lm�� olan haf�zay� bo�alt�r

    free(teklifler);




    return 0;
}

