#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

void rma(char x[][10]);
void rms(char y[][10]);
void menu(void);
void bilgi(void);
void tekrar(void);
void cikis(void);

main(){
	
	srand(time(NULL));
	char mayintarlasi[10][10];
	int scm,scm2;	
	while(scm2!=3){
	//Genel menü
	menu();
	scanf("%d",&scm2);
	switch(scm2){
	//oyunun oynanışı hakkında bilgi 
	case 1:
	system("CLS");
	bilgi();
	break;
	//oyun 
	case 2:	
	do{	
	system("CLS");
	rma(mayintarlasi);
	rms(mayintarlasi);
	tekrar();
	scanf("%d",&scm);
	system("CLS");
}while(scm==1);
	break;
	//oyundan çıkış
	case 3:
		cikis();
		break;
	//menüden yanlış bir seçenek girilmesi durumnda verilen uyarı mesajı	
	default :
	system("CLS");
	printf("!!yanlis secenek lutfen tekrar deneyiniz!!\n\n");
	break;	
}

}
}
//menüyü yazdıran fonksiyon
void menu(void){
		printf("1-Nasil Oynanir?\n2-Oyuna Basla\n3-Oyunu Sonlandir\n\nYapmak istediginiz Secenegi Giriniz: ");
}
//oyunun nasıl oynandığını yazdıran fonksiyon
void bilgi(void){
	
printf("Oyunun amaci mayinlara basmadan tum tarlayi temizlemektir.X ve Y kordinati girilerek kareler acilir.Acmak istediginiz karenin kordinatini (1,2) gibi giriniz.Burada 1 X kordinatini 2 de Y kordinatini temsil etmektedir.Eger mayinsiz bir kare actiysaniz o karenin bulundugu yerde karenin 1 birimlik cevresinde bulunan mayin sayisi yazar. \t\t\t\t ");
}
// tekrar oynayıp oyanamak istemediğini yazdıran fonksiyon
void tekrar(void){
	
		printf("\ntekrar oynamak icin 1 e menuye donmek icin herhangi bir sayiya basabilirsiniz: ");
}

// çıkmak için bilgi mesajı yazdıran fonksiyon
void cikis(void){
	
	printf("\n\n*** CIKMAK ICIN HERHANGI BIR TUSA BASINIZ ***");
}

//rastgele mayın atama işlevini gerçekleştiren fonksiyon.
void rma(char x[][10]){
	
	int rst,rst2;
	int sasayac=0,susayac=0;
	
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
		x[i][j]='?';
		
	for(int i=0;i<15;i++){
		
		rst=rand()%10;
		rst2=rand()%10;
		
		//sütun ve satırlardaki mayın sayısını hesaplıyor.
		for(int j=0;j<10;j++){
			
			if(x[rst][j]=='*')
			sasayac++;
			
			if(x[j][rst2]=='*')
			susayac++;	
		}
		
		//iki mayın yan yana, çapraz köşegenlerde olmayacak, bir satır ve sütünde aynı anda en fazla 3 mayın olacak şartını kontrol ediyor.
		if(x[rst][rst2]=='*' || x[rst-1][rst2-1]=='*' || x[rst-1][rst2+1]=='*' || x[rst][rst2-1]=='*' || x[rst][rst2+1]=='*' || x[rst+1][rst2-1]=='*' || x[rst+1][rst2+1]=='*' || sasayac>=3 || susayac>=3 )
		i--;
	
		else if(x[rst][rst2]!='*')
		x[rst][rst2]='*';
		
		sasayac=0;
		susayac=0;	
	}	
		
		
	}
	
	void rms(char y[][10]){
		
		char bostarla[10][10];
		int mayinsizsecimsay=0,etrafindakimayinsay=0,krdnt,krdnt2;
		char etraftakimayinsatiri[5];
		
	//ekranda ilk gözükecek olan mayinsiz tarlayı oluşturuyor bu iki for döngüsü
		for(int i=0;i<10;i++)
		    for(int j=0;j<10;j++)
				bostarla[i][j]='?';
			
		for(int i=0;i<10;i++){
			
			for(int j=0;j<10;j++)
				
				printf("%c ",bostarla[i][j]);
				
			printf("\n");
		}	
		
	while(mayinsizsecimsay!=85){
		
		printf("\n\nAcmak istediginiz karenin kordinatini giriniz=");
		scanf("%d,%d",&krdnt,&krdnt2);
		krdnt-=1;
		krdnt2-=1;
		system("CLS");
	//buradaki if ler eğer kullanıcı mayin seçmediyse etrafındaki mayin sayısının kontrolünü yapıyor
	if(y[krdnt][krdnt2]=='?'){
		
		if(y[krdnt-1][krdnt2-1]=='*' && krdnt!=0 && krdnt2!=0)
		etrafindakimayinsay++;
		
		if(y[krdnt-1][krdnt2]=='*' && krdnt!=0)
		etrafindakimayinsay++;
		
		if(y[krdnt-1][krdnt2+1]=='*' && krdnt!=0 && krdnt2!=9)
		etrafindakimayinsay++;
		
		if(y[krdnt][krdnt2-1]=='*' && krdnt2!=0)
		etrafindakimayinsay++;
	
		if(y[krdnt][krdnt2+1]=='*' && krdnt2!=9)
		etrafindakimayinsay++;
		
		if(y[krdnt+1][krdnt2-1]=='*' &&krdnt!=9 && krdnt2!=0)
		etrafindakimayinsay++;
	
		if(y[krdnt+1][krdnt2]=='*' &&krdnt!=9)
		etrafindakimayinsay++;
			
		if(y[krdnt+1][krdnt2+1]=='*' &&krdnt!=9 && krdnt2!=9)
		etrafindakimayinsay++;
		//itoa fonksiyonu ile char bir diziye int formatında bir değer atmış olduk.Bu değer seçilen karenin etrafındaki mayın sayısıdır.
		itoa(etrafindakimayinsay,etraftakimayinsatiri,10);
		bostarla[krdnt][krdnt2]=etraftakimayinsatiri[0];
		
		mayinsizsecimsay++;
		//seçilen karenin etrafındaki mayın sayısını yazdırıyor
			for(int i=0;i<10;i++){
			
			for(int j=0;j<10;j++)			
				printf("%c ",bostarla[i][j]);
				
			printf("\n");
	}
		
		etrafindakimayinsay=0;
	
	}	
	//mayın seçilmesi durmunda mayınları tüm mayınları gösterip ve ardından kaybettiniz mesajı yazdırıyor.	
	else if(y[krdnt][krdnt2]=='*'){
		
			for(int i=0;i<10;i++)
		    {
	            for(int j=0;j<10;j++)
	                printf("%c ",y[i][j]);
	            printf("\n");    
	        }
	        
	  printf("kaybettiniz!");
	  
	break;
		
	}	
	//eğer oyun başarıyla tamamlanmışsa kazandınız mesajı yazdırıyor
	if(mayinsizsecimsay==85)	
	printf("kazandiniz!");
		
		
	}
		
			
		
	}

	
