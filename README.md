#KISA SINAV 2

          NOT

2 tane kod üzerinde uğraştım. Odev/DevC klasöründeki kod çalışır durumda fakat verilen şemadakinden biraz farklı şekilde yapıldı.
"Hatalı Kod" klasöründeki kod ise şemadaki gibi yapıldı fakat sürekli hata aldım. nedenini hala çözemedim, ikisini de atmak istedim.



          TYPEDEF

"typedef" sözcüğü "type definition" (tip tanımlaması) sözcüklerinden gelir.
typedef ile var olan veri tiplerini yeni bir isme dönüştürmemize olanak sağlar.
"struct" ile kullanılabilir, kullanıldığında "struct <isim>" yazmak yerine sadece struct'a tanımladığımız ismi kullanmamız yeterli olur.

örnek : 

typedef struct {
    
   int teklifveren_no;
   double teklif;

}Teklif;

şeklinde "Teklif" isminde bir struct oluşturabiliriz.


          STRUCT

"Struct" sözcüğü ise "Structure" (yapı) sözcüğünün kısaltmasıdır.
struct, farklı veri tiplerindeki değişkenleri tek isim altında toplamamıza olanak sağlar.

örnek olarak :

struct <isim>{

   int sayi;
   char karakter;
   float sayi1;

};

şeklinde bir struct oluşturabiliriz.



          AÇIK ARTIRMA VE OYUN TEORİSİ İLİŞKİSİ


      AÇIK ARTTIRMA 

Farklı açık artırma türleri vardır, bunlardan bazıları : 


   English Auction(İngiliz müzayedesi) : 

Müzayedeci, satışa sunulan ürün için bir fiyat belirler. Teklif veren kişiler ise ortada tek kişi kalana kadar bu fiyatı arttırarak yeni teklifler verir.
En yüksek teklifi veren kişi ürünü satın alabilir.


   Dutch Auction(Açık eksiltme) : 

Müzayedeci, ortadaki ürün için üst sınır bir fiyat belirler. Bir kişi teklif verene kadar fiyatı düşürür. Teklif veren kişi ürünü satın alabilir.


   Vickrey auction :

Bu türde ise teklif veren kişiler birbirlerinin teklifini görmeden ortadaki ürün için bir fiyat belirler. En yüksek fiyatı veren kişi ürünü alır.
Fakat alırken ek yüksek 2. fiyatı veren kişinin belirlediği fiyattan alır.



      OYUN TEORİSİ

Oyun teorisi, rasyonel karar vericiler arasındaki stratejik etkileşimleri inceleyen geniş bir alandır. Oyuncular , stratejiler , kazançlar ve dengeler gibi bileşenleri vardır.



      OYUN TEORİSİ VE AÇIK ARTTIRMA İLİŞKİSİ

Açık artırmalar genellikle oyun teorisi kavramları kullanılarak analiz edilir çünkü açık artırmalara katılanlar stratejik karar vericilerdir.
Bir açık artırmada teklif verenler, en uygun teklif verme stratejilerini belirlemek için oyun teorik akıl yürütmeyi kullanabilirler.
Açık artırma formatları ve kuralları, istenen sonuçları elde etmek için oyun teorisi ilkeleri dikkate alınarak tasarlanmıştır.










