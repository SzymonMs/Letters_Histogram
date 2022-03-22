#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_CTYPE, "Polish"); //Polskie znaki w konsoli
    char str[1000]; //Tablica znaków do przechowywania s³ów
    int i,j; //Zmienne steruj¹ce do pêtli
    int toChar[128]; //Tablica do przechowywania liczby wyst¹pienia liter
    int count=0; // Liczba liter
    printf("Podaj wyra¿enie\n");
    gets(str); //Odebranie wyra¿enia z konsoli
    //WYPE£NIENIE TABLICY ZERAMI
    for(j=0;j<128;++j)
	{
   		toChar[j]=0;
    }
    //ZLICZANIE ZNAKÓW
    for(i=0; str[i] != EOF; i++)
	{
    	for(j=0;j<128;++j)
		{
        	if(str[i]==j)
        	{
            	toChar[j]=toChar[j]+1;
        	}
        }
    }
    printf("\n");
    // Horizontal histogram
   printf("#### HISTOGRAM CZÊSTOŒCI WYSTÊPOWANIA LITER- POZIOMY ####");
   printf("\n");
   for(j=65;j<123;++j) // only letters
   {
   		if(toChar[j]!=0)
   		{
	
		   printf("%d  %c  ",toChar[j],j);
   			for(i=0;i<toChar[j];++i)
   			{
   				printf("-");
			}
			printf("\n");
			count++;
		}
   }
   int *tab = malloc(sizeof(int)*count);
   printf("\n\n");
   // Vertical histogram
   printf("#### HISTOGRAM CZÊSTOŒCI WYSTÊPOWANIA LITER- PIONOWY ####");
   printf("\n\n");
   int MAX=0;
   for(i=65;i<123;++i)
   {
   		if(toChar[i]>MAX)
   		{
   			MAX=toChar[i];	
		}
   }
   int ster=MAX;
   int toChar2[128];
   for(i=0;i<128;++i)
   {
   		toChar2[i]=toChar[i];
   }
   
   for(i=0;i<ster;++i) //ster bo szerokosc histogramu taka ile liter mamy
   {
   		for(j=65;j<123;++j) //przejscie po tablicy liter bo kazda trzeba sprawdzic czy tam trzeba narysowac -
   		{
   			if(toChar[j]!=0)
			{			   
   				if(toChar[j]==MAX)
   				{
					printf("- ");
					toChar[j]=toChar[j]-1; //zmniejszenie toChar zeby potem znowu bylo MAX
				}
				else
					printf("  ");
			}
		}
		MAX=MAX-1;
		printf("\n");
   }
   for(i=65;i<123;++i)
   {
   		if(toChar2[i]!=0)
   			printf("%c ",i);
   }
   
   
    return 0;
}
