#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void yazdir(float matrix[20][20],int boyut);
void gauss_elimination(float matrix[20][20],int boyut);
void kokleriBulma(float matrix[20][20],int boyut,float kok[20]);

int main(){
	
	float matrix[20][20],kok[20];
	int boyut;
	int i,j;
	
	for(i=0;i<20;i++){
		kok[i]=1;
	}
	
	printf("Kare matrisin boyutunu giriniz:");	
	scanf("%d",&boyut);
	
	for(i=0;i<boyut;i++){
		printf("%d. denklemin katsayilarini giriniz:\n",i+1);
		for(j=0;j<boyut+1;j++){
			if(j!=boyut){
				printf("%d. terimin katsayisi:",j+1);
				scanf("%f",&matrix[i][j]);
			}
			else{
				printf("Sonucun katsayisini giriniz:");
				scanf("%f",&matrix[i][j]);
			}
		}
	}
	
	yazdir(matrix,boyut);
	gauss_elimination(matrix, boyut);
	yazdir(matrix,boyut);
	kokleriBulma(matrix,boyut,kok);
	
	return 0;
}


void yazdir(float matrix[20][20],int boyut){
	
	int i,j;
	for(i=0;i<boyut;i++){
		for(j=0;j<boyut+1;j++){
			if(j!=boyut){
				if(j==boyut-1){
					printf("%f ",matrix[i][j]);
				}
				else{
					printf("%f + ",matrix[i][j]);
				}
				
			}
			else{
				printf("= %f",matrix[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n\n");
}


void gauss_elimination(float matrix[20][20],int boyut){
	
	int i,j,t,flag=0;
	float bolen1,bolen2;
	
	for(i=0;i<boyut;i++){
		flag=0;
		for(t=i;t<boyut;t++){
			bolen1=matrix[t][i];
			if(flag==0){
				for(j=0;j<boyut+1;j++){
					matrix[i][j]=matrix[i][j]/bolen1;
					flag=1;
				}	
			}
			else{
				for(j=0;j<boyut+1;j++){
					matrix[t][j]=matrix[t][j]/bolen1;
					matrix[t][j]=matrix[t][j]-matrix[i][j];
					matrix[t][j]=matrix[t][j]*bolen1;
				}
			}
			
		}
		
	}
	
}

void kokleriBulma(float matrix[20][20],int boyut,float kok[20]){
	
	int i,j,t;
	float toplam=0;
		
	for(i=boyut-1;i>=0;i--){
		toplam=0;
		for(j=boyut-1;j>i;j--){
			toplam+=kok[j]*matrix[i][j];
		}
		kok[j]=matrix[i][boyut]-toplam;
	}
	
	for(i=0;i<boyut;i++){
		printf("x%d:%f ",i+1,kok[i]);
	}
}
