#include<stdio.h>
#include<math.h>

float kok(float matris[100][100],float degerler[100],int boyut,int n);
void seidel(float matris[100][100],float degerler[100],float eski[100],float fark[100],float hata,int boyut);
void tablo(float matris[100][100],float degerler[100],float eski[100],int boyut,int iterasyon);

int main(){
	
	float matris[100][100];
	float degerler[100];
	float eski[100];
	float fark[100];
	float hata;
	int boyut;
	int i,j;
	
	printf("Kare matrisin boyutunu giriniz:");
	scanf("%d",&boyut);
	printf("Sirayla baslangic degerlerini giriniz\n");
	for(i=0;i<boyut;i++){
		scanf("%f",&degerler[i]);
	}
	
	printf("Hata degerini giriniz:");
	scanf("%f",&hata);
	
	printf("Matrisin degerlerini kosegenlerdeki degerler maksimum olacak sekilde giriniz\n");
	for(i=0;i<boyut;i++){
		for(j=0;j<=boyut;j++){
			if(j!=boyut){
				printf("[%d][%d]:",i+1,j+1);
				scanf("%f",&matris[i][j]);
			}
			else{
				printf("Denklemin sonucunu giriniz:");
				scanf("%f",&matris[i][j]);
			}
		}
	}
	printf("\n");
	for(i=0;i<boyut;i++){
		for(j=0;j<=boyut;j++){
			if(j!=boyut){
				if(j==boyut-1){
					printf("(%3.1f)",matris[i][j]);
				}
				else{
					printf("(%3.1f) + ",matris[i][j]);
				}
				
			}
			else{
				printf(" = (%3.1f)",matris[i][j]);
			}
			
		}
		printf("\n");
	}
	
	seidel(matris,degerler,eski,fark,hata,boyut);
	
	return 0;
}




void seidel(float matris[100][100],float degerler[100],float eski[100],float fark[100],float hata,int boyut){
	
	int i,j;
	int flag=1;
	float deger;
	int iterasyon=1;
	
	printf("\n\n");
	printf("    Iterasyon	  x	      |delta x|   	  y	      |delta y|	          z	      |delta z|\n");
	printf("	%d	",iterasyon); 
	for(i=0;i<boyut;i++){
		printf("%5.3f		  - 	 	",degerler[i]);
	}
	printf("\n");
	
	while(flag){
		
		for(i=0;i<boyut;i++){
			eski[i]=degerler[i];
			
			degerler[i]=kok(matris,degerler,boyut,i);
		}
		
		tablo(matris,degerler,eski,boyut,iterasyon);
		
			
	
		flag=0;
		for(i=0;i<boyut;i++){
			deger=fabs(degerler[i]-eski[i]);
			if(deger>hata){
				flag=1;
			}
		}
		iterasyon++;
	}
	printf("\n");
	for(i=0;i<boyut;i++){
		printf("%d.kok: %6.3f   ",i+1,degerler[i]);
	}	
	
}



float kok(float matris[100][100],float degerler[100],int boyut,int n){
	
	int i,j;
	float sonuc=0;
	
	for(i=0;i<boyut;i++){
		if(i!=n){
			sonuc += matris[n][i]*degerler[i];
		}
	}
	return (matris[n][boyut]-sonuc)/matris[n][n];
	
	
}


void tablo(float matris[100][100],float degerler[100],float eski[100],int boyut,int iterasyon){
	
	int i;
	printf("	%d	",iterasyon+1);
	for(i=0;i<boyut;i++){
		printf("%5.3f		%5.3f		",degerler[i],fabs(degerler[i]-eski[i]) );
	}
	printf("\n");
	
}

