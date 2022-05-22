#include<stdio.h>
#include<math.h>

int faktoriyel(int h);
int gregory(float degerler[100],float sonuclar[100],int x,int iterasyon,float fark[100][100]);
float hesaplama(float degerler[100],float sonuclar[100],float fark[100][100],int x,int iterasyon,float deger,int h);
float carpma(int a,float deger,float degerler[100]);

int main(){
	
	int x;
	float degerler[100],sonuclar[100];
	int h;
	int i;
	float temp,x0;
	int count;
	int iterasyon=0;
	float deger;
	float fark[100][100]={0};
	
	
	printf("Gireceginiz x degerlerinin sayisini giriniz:");
	scanf("%d",&x);
	printf("X degerlerinin arasindaki esit araliklarin degerini tam sayi olarak giriniz:");
	scanf("%d",&h);
	printf("x degerlerinin baslangici olan degeri giriniz(x0):");
	scanf("%f",&x0);
	
	temp=x0;
	
	for(i=0;i<x;i++){
		degerler[i]=temp;
		temp+=h;
	}
	
	for(i=0;i<x;i++){
		printf("x'in %.2f degeri icin f(x):",degerler[i]);
		scanf("%f",&sonuclar[i]);
	}
	
	printf("Sonucunu hesaplatmak istediginiz kac sayi vardir:");
	scanf("%d",&count);
	
	
	iterasyon=gregory(degerler,sonuclar,x,iterasyon,fark);
	
	for(i=0;i<count;i++){
		printf("Degeri giriniz:");
		scanf("%f",&deger);
		
		printf("Sonuc: %9.3f",hesaplama( degerler, sonuclar, fark, x, iterasyon, deger,h));
		printf("\n\n");
	}
	
	
	
	return 0;
}


int faktoriyel(int h){
	
	int sonuc=1;
	while(h>1){
		sonuc=sonuc*h;
		h--;
	}
	return sonuc;
	
}

float carpma(int a,float deger,float degerler[100]){
	int i;
	float sonuc=1;
	for(i=0;i<a;i++){
		sonuc*=deger-degerler[i];
	}
	return sonuc;
}

int gregory(float degerler[100],float sonuclar[100],int x,int iterasyon,float fark[100][100]){
	
	int i,j;
	int flag=1;
	int temp=x;
	for(i=0;i<x;i++){

		fark[0][i]=sonuclar[i];
	}
	j=1;
	while(flag){
		
		for(i=1;i<x;i++){
			fark[j][i-1]=fark[j-1][i]-fark[j-1][i-1];
			if(fark[j][i-1]==0){
				flag=0;	
			}
		}
		iterasyon++;
		j++;
		x--;
	}
	
/*	for(i=0;i<iterasyon;i++){
		for(j=0;j<temp;j++){
			printf("%7.1f",fark[i][j]);
		}
		printf("\n");
	}*/
	return iterasyon;
	
}

float hesaplama(float degerler[100],float sonuclar[100],float fark[100][100],int x,int iterasyon,float deger,int h){
	
	float sonuc=0;
	int i;
	sonuc = sonuclar[0];
	for(i=1;i<iterasyon;i++){
		sonuc+=( carpma(i,deger,degerler)/pow(h,i) )*(fark[i][0]/faktoriyel(i) );
	}
	return sonuc;
}
