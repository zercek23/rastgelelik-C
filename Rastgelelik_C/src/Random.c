#include "Random.h"

Random RandomOlustur(){
	Random this;
	this =(Random)malloc(sizeof(struct RANDOM));	
	this->rastgeleSayi = 1;
	
	this->RastgeleSayi=&RandomSayi;
	this->Yoket=&RandomYoket;	
	return this;	
}

long RandomSayi(const Random this){
	//Süre alınır.
	long zaman = clock() + time(NULL);	
	//Alınan süreye rastgele matematiksel işlem uygulanır.
    this->rastgeleSayi = (zaman * 1103515245 + 12345 + this->rastgeleSayi); 
	//Sayı döndürülür.
    return this->rastgeleSayi;
}

void RandomYoket(Random this){
	if(this==NULL) return;
	free(this);	
}