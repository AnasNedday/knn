#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "KNN.h"


void searchData(FILE* file, ligne *dataset){
    printf("Ana dkhelt l getline\n");

    int numLigne = 147 ;
    char * line = NULL;
    char * read = NULL;
    size_t len = 0;
    //size_t read;
    bool first = true;
    if(file == NULL) {
        printf("Erreur!");   
        exit(1);             
    }

int j = 0;
    while (((read = getline(&line, &len, file)) != -1) && j < numLigne) {
        int i = 0;
        float table[3];
        char *token;
        token = strtok(line,",");
        while( token != NULL ) {
            if (first == false){
                table[i] = atof(token);
                printf("%f\n",table[i]);
                i++;
            }
            token = strtok(NULL, ",");
            }
        if (first == false){
            dataset[j].att.Pettalength = table[0];
            dataset[j].att.Petalwidth = table[1];
            dataset[j].Class = (int)table[2];
            j++;
        }
        first = false;
    //printf("%f %f %d \n",dataset[j].att.Pettalength,dataset[j].att.Petalwidth,dataset[j].Class);

    }


    fclose(file);

}


void GetDistance(ligne *dataset, distanceEtClass *distEtclass, ligne test_set){
    int i = 0, numLigne = 147;

    for (i = 0; i < numLigne ; i++){
        distEtclass[i].distance = sqrt(
            pow(test_set.att.Pettalength - dataset[i].att.Pettalength,2) + 
            pow(test_set.att.Petalwidth - dataset[i].att.Petalwidth,2) 
        );//calcul de la distance euclidienne

        distEtclass[i].Class = (int) dataset[i].Class;
        distEtclass[i].line = i + 2;
    }

printf("rani khrejt mn getDistance\n");
}

void SortByDistance(distanceEtClass *distEtclass){
    int numLigne = 147;
    int i = 0, j;
    distanceEtClass temp;


    for (i = 0; i < numLigne; i++)
    {
        for (j = i + 1; j < (numLigne); j++)
        {
            if (distEtclass[i].distance > distEtclass[j].distance)
            {
                temp = distEtclass[i];
                distEtclass[i] = distEtclass[j];
                distEtclass[j] = temp;
            }
            
        }
    }
    printf("rani khrejt mn SortBydistance\n");
} 

float KNN(ligne *dataset, ligne test_set, int k, int numLigne){
    int x,j;
    float pourcentage;
    distanceEtClass *distanceEtClass = malloc(numLigne * sizeof (*distanceEtClass));
    
    GetDistance(dataset, distanceEtClass, test_set);
    SortByDistance(distanceEtClass);
    
    
    int allClass = 0;
    for (x = 0; x < k; x++){
        printf("distance : %f, Class: %d, line: %d \n",distanceEtClass[x].distance,distanceEtClass[x].Class, distanceEtClass[x].line);
        if (distanceEtClass[x].Class == 1 || distanceEtClass[x].Class == 2 ||distanceEtClass[x].Class == 3 ){
            allClass += distanceEtClass[x].Class;
        }
    }
    printf("%d \n",allClass);
    printf("K === %d : \n allClass == %d \n Pourcentage d'etre 1 est === %f \n",k, allClass, (float) allClass/k);
    printf("rani khrejt mn SortBydistance\n");
    return (float) allClass/k;
   
}




