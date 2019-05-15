#include "RastgeleKarakter.h"


RastgeleKarakter RastgeleKarakterOlustur(){
	RastgeleKarakter this;
	this=(RastgeleKarakter)malloc(sizeof(struct RASTGELEKARAKTER));
	this->super=RandomOlustur();
	
	this->RastgeleKarakterGetir = &rastKarakter;
	this->RastgeleKarakterlerGetir=&rastKarakterler;
	this->AraligaUygunKarakterGetir = &rastKarakterAralik;
	this->AraligaUygunKarakterlerGetir=&rastKarakterlerAralik;
	this->BelirtilenKarakterGetir=&rastKarakterBelirtilen;
	this->BelirtilenKarakterlerGetir=&rastKarakterlerBelirtilen;
	this->CumleGetir=&Cumle;
	this->Yoket=&RastgeleKarakterYoket;
	return this;
}
char rastKarakter(const RastgeleKarakter this){
	char donecekKarakter;
	int rastgeleSayi;
	do{ 
        //Verilen aralığa göre rastgele bir sayıyı değişkene atar.
		rastgeleSayi = (int)(this->super->RastgeleSayi(this->super) % 123);
    }while(!((rastgeleSayi <= 90 && rastgeleSayi >=65) || (rastgeleSayi<=122 && rastgeleSayi >= 97)));
	//rastgeleSayi char cinsinde değişkene atanır ve bu değişken döner.
    donecekKarakter = (char)rastgeleSayi;
	return donecekKarakter;
}
char* rastKarakterler(const RastgeleKarakter this,int adet){
	//donecekKarakterler'e tek tek rastgele karakterler atanır.
	char* donecekKarakterler = (char*)malloc(sizeof(char)*adet);
	for(int i = 0; i<adet; i++)
		donecekKarakterler[i] = this->RastgeleKarakterGetir(this);
	return donecekKarakterler;
}
char rastKarakterAralik(const RastgeleKarakter this,char a,char b){
	//Verilen char aralıkları int değişkenlere atanır. Kontroller ile dönecek karaktere sürekli rastgele karakterler atanır.
	char donecekKarakter;
	int ilk = a;
    int son = b;
        
    if (!((ilk == son+1) || (ilk+1 == son) || (ilk == son))) {
        do{
			donecekKarakter = this->RastgeleKarakterGetir(this);
		}while(!((donecekKarakter <= b && donecekKarakter >=a) || (donecekKarakter >= b && donecekKarakter <= a)));
    }
	//Aralıkta karakter geldiği zaman bu karakter döner.
	return donecekKarakter;
}
char* rastKarakterlerAralik(const RastgeleKarakter this,char a,char b,int adet){
	//Verilen char aralıkları int değişkenlere atanır. Kontroller ile dönecek karakterlere sürekli rastgele karakterler atanır.
	char* donecekKarakterler = (char*)malloc(sizeof(char)*adet);
	int ilk = a;
    int son = b;
	if (fabs(ilk-son) > adet) {
        for (int i = 0; i < adet; i++) {
            donecekKarakterler[i] = this->AraligaUygunKarakterGetir(this,a,b);
        }
    }
	//Aralıkta karakterler geldiği zaman bu karakterler döner.
	return donecekKarakterler;
}

char rastKarakterBelirtilen(const RastgeleKarakter this,int parametreAdedi,...){
	//Girilen parametreAdedi değişkeni ve parametlere göre alınan karakterler içerisinden rastgele karakter seçilir.
	char* kontrolKarakterler = (char*)malloc(sizeof(char)*parametreAdedi);	
	va_list valist;
	va_start(valist, parametreAdedi);
	
	for(int i=0; i<parametreAdedi; i++){
		kontrolKarakterler[i] = (char)va_arg(valist,int);
	}
	va_end(valist);	
	
	int rastgeleSayi;
	
	do{
		rastgeleSayi = (int)(this->super->RastgeleSayi(this->super) % 123);
	}while(!(rastgeleSayi < parametreAdedi && rastgeleSayi > 0));
	//Seçilen karakter döner.
	return kontrolKarakterler[rastgeleSayi];
}

char* rastKarakterlerBelirtilen(const RastgeleKarakter this,int adet,int parametreAdedi,...){
	//Girilen parametreAdedi değişkeni ve parametlere göre alınan karakterler içerisinden parametre kısmında verilen adete göre rastgele karakterler seçilir.
	char* kontrolKarakterler = (char*)malloc(sizeof(char)*parametreAdedi);
	char* donecekKarakterler = (char*)malloc(sizeof(char)*adet);	
	va_list valist;
	va_start(valist, parametreAdedi);
	
	for(int i=0; i<parametreAdedi; i++){
		kontrolKarakterler[i] = (char)va_arg(valist,int);
	}
	va_end(valist);	
	
	int rastgeleSayi;
	
	for(int i=0; i<adet; i++){
		do{
			rastgeleSayi = (int)(this->super->RastgeleSayi(this->super) % 123);
		}while(!(rastgeleSayi < parametreAdedi && rastgeleSayi > 0));
		
		donecekKarakterler[i] = kontrolKarakterler[rastgeleSayi];
	}
	free(kontrolKarakterler);
	//Seçilen karakterler döner.
	return donecekKarakterler;
}

char* Cumle(const RastgeleKarakter this){
	//bosluk ve kelime sayısı rastgele bir sayı belirlendikten sonra cümle yapısı oluşturulur.
	int bosluk;
	int adet;
	int sayac = 0;
	do{
		bosluk = (int)(this->super->RastgeleSayi(this->super) % 123);
	}while(!(bosluk < 9 && bosluk > 1));
	char* cumle = (char*)malloc(sizeof(char)*200);
	
	for (int i = 0; i < bosluk; i++) {
        do{
            adet = (int)(this->super->RastgeleSayi(this->super) % 123);
        }while(!(adet < 9 && adet > 1));
		
        for (int j = 0; j < adet; j++) {                              
            cumle[sayac++] = this->RastgeleKarakterGetir(this);
        }
		cumle[sayac++] = ' ';
    }
	return cumle;
}
void RastgeleKarakterYoket(RastgeleKarakter this){
	if(this==NULL) return;
	this->super->Yoket(this->super);
	free(this);
}