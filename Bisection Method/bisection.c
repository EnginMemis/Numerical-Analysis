#include<stdio.h>
#include<math.h>

float hesaplama(float katsayi[],int kuvvet,float a1);
void yazdir(float katsayi[],int kuvvet);
void bisection(float a1,float a2,float hata,float katsayi[],int kuvvet);

int main(){
	
	int i;
	int kuvvet;
	float a1,a2,toplam,hata;
	float katsayi[20];
	
	printf("Fonksiyonun en buyuk kuvvetini giriniz:");
	scanf("%d",&kuvvet);
	
	for(i=kuvvet;i>=0;i--){
		printf("x^%d katsayisini giriniz:",i);
		scanf("%f",&katsayi[i]);
	}
	
	printf("Hata degerini giriniz:");
	scanf("%f",&hata);
	
	printf("Aralik degerlerini giriniz:");
	scanf("%f,%f",&a1,&a2);
	yazdir(katsayi,kuvvet);
	bisection(a1,a2,hata,katsayi, kuvvet);

	return 0;
	
}
float hesaplama(float katsayi[],int kuvvet,float a1){
	
	int i,j;
	float toplam,us=0;
	
	toplam=0.0;
	toplam+=katsayi[0];
	
	for(i=1;i<=kuvvet;i++){
		
		us = pow(a1,i);
		toplam += us*katsayi[i];
	}	
	
	return toplam;
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

void bisection(float a1,float a2,float hata,float katsayi[],int kuvvet){
	int i,j;
	i=1;
	float temp;
	float kok;
	
	if(hesaplama(katsayi, kuvvet, a2) * hesaplama(katsayi,kuvvet,a1)<0){
		while( (a2-a1)/pow(2,i) > hata ){
		
			temp = (a1+a2)/2;
			
			if( hesaplama(katsayi, kuvvet, temp) * hesaplama(katsayi,kuvvet,a1)<=0){
				a2=temp;
				printf("\n%d. iterasyon\n******************",i);
				printf("\nx1:%f x2:%f\n",a1,a2);
			}	
			else if( hesaplama(katsayi, kuvvet, temp) * hesaplama( katsayi, kuvvet, a2) <0){
				a1=temp;
				printf("\n%d. iterasyon\n******************",i);
				printf("\nx1:%f x2:%f\n",a1,a2);
			}
			i++;
		}
		kok = (a1+a2)/2;
		
		printf("\nYaklasik kok: ");
		printf("%f",kok);
	}
	else if(hesaplama(katsayi, kuvvet, a2)==0 && hesaplama(katsayi,kuvvet,a1)==0){
		printf("\nKok:%f\n",a2);
		printf("Kok:%f",a1);
	}
	else if( hesaplama(katsayi,kuvvet,a1)==0){
		printf("\nKok:%f",a1);
	}
	else if(hesaplama(katsayi,kuvvet,a2)==0){
		printf("\nKok:%f\n",a2);
	}
	else{
		printf("\nGirdiginiz aralikta kok bulunmamaktadir.");
	}

	
}
