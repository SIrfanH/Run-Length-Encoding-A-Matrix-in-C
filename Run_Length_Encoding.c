#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i , j, dizi_boyut=0, counter=0, matris_satir, matris_sutun, dizi[100], tmp, yeni_matris[50][50]; float ratio;int matrix[50][50];
    // yeni_matris degiskenini sonradan compressed array'i matrise cevirmek icin tanimladim

    printf("Enter the Number of Rows and columns\n");
    scanf("%d %d",&matris_satir,&matris_sutun);         //matris eleman sayisi

    for(i=0; i<matris_satir; i++)
    {
        for(j=0; j<matris_sutun; j++)
        {
            printf("Matrix[%d][%d] Elemani giriniz:\t", i+1, j+1);      //kullanicidan matris elemani aliniyor
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("The Matrix is:\n");

    for(i=0; i<matris_satir; i++)
    {
        for(j=0; j<matris_sutun; j++)
        {
            printf("%d\t", matrix[i][j]);           //matris elemanlarini printliyor
        }
        printf("\n");
    }
    tmp=matrix[0][0];             // tmp degiskeni matris elemanlarini karsilastirmak icin

    for(i=0; i<matris_satir; i++)
    {
        for(j=0; j<matris_sutun; j++)
        {
            if(tmp != matrix[i][j])   //matrisin 2 ard arda gelen elemani degismeyene kadar while icine girmez ve counter degiskeni arttiririlir
            {
                dizi[dizi_boyut] = counter;  //while icine girerse demek ki matris elemani degismis, counter sayisi dizinin
                dizi[dizi_boyut+1] = tmp;    //elemanina ve tmp sayisi dizinin bir sonraki elemanina atanacak
                dizi_boyut = dizi_boyut+2;
                tmp = matrix[i][j];            //tmp yeni matris elemaninin degerini alacak
                counter=0;
            }
            counter++;
        }
    }
    dizi[dizi_boyut] = counter;

    dizi[dizi_boyut+1] = tmp;

    dizi_boyut = dizi_boyut+2;

    ratio = 1-((float) dizi_boyut/(matris_satir * matris_sutun));

    printf("\nThe Run-Length Encoded Array is:\n");
    for(i=0; i<dizi_boyut; i++)
    {
        printf("%d  ", dizi[i]);       // compressed diziyi printliyor
    }
    printf("\nCompression Ration is %.2f", ratio);

    dizi_boyut=0;         // baska degisken kullanmak istemedigim icin dizi_boyut degiskenini bundan sonra farkli bir islem icin kullandim

    for(i=0; i<matris_satir; i++)
    {
        for(j=0; j<matris_sutun; j++)
        {
            if(dizi[dizi_boyut] != 0)  // dizi[dizi_boyut] sifir olana kadar yeni_matrisin dizi[dizi_boyut] kadar elemanina dizi[dizi_boyut+1]'i atar
            {                       // yani eger dizi[dizi_boyut] uc ise ve dizi[dizi_boyut+1] 1 ise, yeni_matrisin 3 elemanina 1 atar
                yeni_matris[i][j] = dizi[dizi_boyut+1];
            }
            dizi[dizi_boyut]--;
            if(dizi[dizi_boyut] == 0)
            {
                dizi_boyut = dizi_boyut+2; //dizi[dizi_boyut] 0 oldugunda, counter indisi cift olan baska elemana gecer
            }
        }
    }
    printf("\nYeni matris:\n");
    for(i=0; i<matris_satir; i++)
    {
        for(j=0; j<matris_sutun; j++)
        {
            printf("%d\t", yeni_matris[i][j]);
        }
        printf("\n");
    }

    return 0;
}
