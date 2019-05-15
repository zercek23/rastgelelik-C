#include "RastgeleKarakter.h"

int main(){
	
    RastgeleKarakter m=RastgeleKarakterOlustur();
	printf("Rastgele Karakter:\n");
	for(int i=0;i<100;i++){
		printf("%c  ",m->RastgeleKarakterGetir(m));
	}
	
	printf("\n\nRastgele 3 Karakter:\n");
	for(int i=0;i<100;i++){
		printf("%s ",m->RastgeleKarakterlerGetir(m,3));
	}
	
	printf("\n\nVerilen iki karakter (a,f):\n");
	for(int i=0;i<100;i++){
		printf("%c ",m->AraligaUygunKarakterGetir(m,'a','f'));
	}
	
	printf("\n\nVerilen iki karakter (a,f,3): \n");
	for(int i=0;i<100;i++){
		printf("%s ",m->AraligaUygunKarakterlerGetir(m,'a','f',3));
	}
	
	printf("\n\nBelirtilen Karakterler (g,y,u,c,n,e):\n");
	for(int i=0;i<100;i++){
		printf("%c ",m->BelirtilenKarakterGetir(m,6,'g','y','c','n','e','u'));
	}
	
	printf("\n\nBelirtilen Karakterler adfsga(g,y,u,c,n,e):\n");
	for(int i=0;i<100;i++){
		printf("%s ",m->BelirtilenKarakterlerGetir(m,3,6,'g','y','c','n','e','u'));
	}
	
	printf("\n\nRastgele Cumle: %s",m->CumleGetir(m));
	printf("\nRastgele Cumle: %s",m->CumleGetir(m));
	
	m->Yoket(m);
	
	return 0;
}