#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void yazdir(float katsayi[],int kuvvet);
void turevYazdir(float turevKatsayi[],int kuvvet);
float hesaplama(float katsayi[],int kuvvet,float a);
float turevhesaplama(float turevKatsayi[],int kuvvet,float a);
void newton_raphson(float a,float hata,float katsayi[],float turevKatsayi[],int kuvvet);
void turevKatsayiHesapla(float katSayi[], float turevKatsayi[], int kuvvet);

int main(){
	
	int i;
	int kuvvet;
	float a,toplam,hata,normal,turev;
	float katsayi[20],turevKatsayi[20];
	
	printf("Fonksiyonun en buyuk kuvvetini giriniz:");
	scanf("%d",&kuvvet);
	
	for(i=kuvvet;i>=0;i--){
		printf("x^%d katsayisini giriniz:",i);
		scanf("%f",&katsayi[i]);
	}
	
/*	for(i=kuvvet-1;i>=0;i--){
		printf("Turevin x^%d katsayisini giriniz:",i);
		scanf("%f",&turevKatsayi[i]);
	}*/
	
	turevKatsayiHesapla(katsayi, turevKatsayi, kuvvet);
	
	printf("Hata degerini giriniz:");
	scanf("%f",&hata);
	
	printf("Baslangic degeri giriniz:");
	scanf("%f",&a);
	
	yazdir(katsayi,kuvvet);
	turevYazdir(turevKatsayi,kuvvet);
	newton_raphson( a, hata, katsayi, turevKatsayi, kuvvet);
	

	return 0;
	
}

void turevKatsayiHesapla(float katSayi[], float turevKatsayi[], int kuvvet){
	int i;
	for(i=kuvvet; i>=1; i--){
		turevKatsayi[i-1] = katSayi[i]*i;
	}
}


void yazdir(float katsayi[],int kuvvet){
	int i,j;
	
		printf("\nFonksiyon: ");
	
		for(i=kuvvet;i>=0;i--){
			if(katsayi[i]!=0){
				
				if(i==0){
					printf("(%0.1f)",katsayi[i]);
				}
				else{
					printf("(%0.1fx^%d) + ",katsayi[i],i);
				}
			}
		}
}

void turevYazdir(float turevKatsayi[],int kuvvet){
		int i,j;
	
		printf("\nTurevli Fonksiyon: ");
	
		for(i=kuvvet-1;i>=0;i--){
			if(turevKatsayi[i]!=0){
				
				if(i==0){
					printf("(%0.1f)",turevKatsayi[i]);
				}
				else{
					printf("(%0.1fx^%d) + ",turevKatsayi[i],i);
				}
			}
		}
}


float hesaplama(float katsayi[],int kuvvet,float a){
	
	int i,j;
	float toplam,us=0;
	
	toplam=0.0;
	toplam+=katsayi[0];
	
	for(i=1;i<=kuvvet;i++){
		
		us = pow(a,i);
		toplam += us*katsayi[i];
	}	
	
	return toplam;
}

float turevhesaplama(float turevKatsayi[],int kuvvet,float a){
	int i,j;
	float toplam,us=0;
	
	toplam=0.0;
	toplam+=turevKatsayi[0];
	
	for(i=1;i<=kuvvet-1;i++){
		
		us = pow(a,i);
		toplam += us*turevKatsayi[i];
	}	
	
	return toplam;
}


void newton_raphson(float a,float hata,float katsayi[],float turevKatsayi[],int kuvvet){
	int i,j;
	i=1;
	float a1,a2;
	float temp;
	float kok;
		
		a1=a;
		a2=a1-(hesaplama(katsayi,kuvvet,a1)/turevhesaplama(turevKatsayi, kuvvet, a1));
		while( fabs(a2-a1) > hata ){
			printf("\n%d. iterasyon\n******************\n",i);
			printf("x1:%f x2:%f\n",a1,a2);
			a1=a2;
			a2=a1-(hesaplama(katsayi,kuvvet, a1)/turevhesaplama( turevKatsayi, kuvvet, a1));
			i++;
		}
		kok = a2;
		
		printf("\nYaklasik kok: ");
		printf("%f",kok);
		
}




