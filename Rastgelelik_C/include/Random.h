#ifndef RANDOM_H
#define RANDOM_H

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

struct RANDOM{
	long rastgeleSayi;
	long (*RastgeleSayi)(struct RANDOM*);
	void (*Yoket)(struct RANDOM*);
};

typedef struct RANDOM* Random;

Random RandomOlustur();
long RandomSayi(const Random);
void RandomYoket(Random);

#endif