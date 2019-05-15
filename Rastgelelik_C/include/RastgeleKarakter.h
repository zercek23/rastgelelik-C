#ifndef RASTGELEKARAKTER_H
#define RASTGELEKARAKTER_H

#include "Random.h"
#include "stdarg.h"
#include "Math.h"

struct RASTGELEKARAKTER{
	Random super;
	
	char (*RastgeleKarakterGetir)(struct RASTGELEKARAKTER*);
	char* (*RastgeleKarakterlerGetir)(struct RASTGELEKARAKTER*,int);
	char (*AraligaUygunKarakterGetir)(struct RASTGELEKARAKTER*,char,char);
	char* (*AraligaUygunKarakterlerGetir)(struct RASTGELEKARAKTER*,char,char,int);
	char (*BelirtilenKarakterGetir)(struct RASTGELEKARAKTER*,int,...);
	char* (*BelirtilenKarakterlerGetir)(struct RASTGELEKARAKTER*,int,int,...);
	char* (*CumleGetir)(struct RASTGELEKARAKTER*);
	void (*Yoket)(struct RASTGELEKARAKTER*);
};
typedef struct RASTGELEKARAKTER* RastgeleKarakter;

RastgeleKarakter RastgeleKarakterOlustur();
char rastKarakter(const RastgeleKarakter);
char* rastKarakterler(const RastgeleKarakter,int);
char rastKarakterAralik(const RastgeleKarakter,char,char);
char* rastKarakterlerAralik(const RastgeleKarakter,char,char,int);
char rastKarakterBelirtilen(const RastgeleKarakter,int,...);
char* rastKarakterlerBelirtilen(const RastgeleKarakter,int,int,...);
char* Cumle(const RastgeleKarakter);
void RastgeleKarakterYoket(RastgeleKarakter);

#endif