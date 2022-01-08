#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include"KNN.h"





int main() {
    int i, x, numLigne = 147, k = 12;
	float predict;
    
    FILE *file;
    file = fopen("Dataset.csv","r");
    if (file == NULL){
        printf("Error");
    }
    ligne *dataset = malloc(numLigne * sizeof (*dataset));
    searchData(file, dataset);

    ligne test_set;
    printf("--------------------------------------\n");
    printf("Donnez les valeurs pour tester svp : \n");
    printf("--------------------------------------\n\n");
    printf("Donnez la valeur du Pettalength : ");scanf("%d",&test_set.att.Pettalength);
    printf("Donnez la valeur du Petalwidth : ");scanf("%d",&test_set.att.Petalwidth);*/
    
    
    

    // 1.4,0.2,Iris-setosa
    // 4.7,1.4,Iris-versicolor
    // 5.3,1.9,Iris-virginica
    //Iris-setosa=1
    //Iris-versicolor=2
    //Iris-virginica=3

    
    test_set.att.Pettalength = 4.7;
    test_set.att.Petalwidth = 1.4;
    //test_set.Class = ;
    
    predict = KNN(dataset,test_set, k, numLigne);
	printf("Class est %f",predict);
    
    fclose(file);
    return 0;
}





