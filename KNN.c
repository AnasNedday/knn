#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "KNN.h"


void searchData(FILE* file, ligne *dataset){

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
    while (((read = getline(&line, &len, file)) != -1) && j < numLigne) { //to read line by line from the file
        int i = 0;
        float table[3];
        char *token;
        token = strtok(line,",");// to devide string by commas(,)
        while( token != NULL ) {
            if (first == false){
                table[i] = atof(token); //to convert char to float
                printf("%f\n",table[i]);
                i++;
            }
            token = strtok(NULL, ",");
            }
        if (first == false){
            // add lines from file to dataset
            dataset[j].att.Pettalength = table[0];
            dataset[j].att.Petalwidth = table[1];
            dataset[j].Class = (int)table[2];
            j++;
        }
        first = false;
    printf("%f %f %d \n",dataset[j].att.Pettalength,dataset[j].att.Petalwidth,dataset[j].Class);

    }


    fclose(file);

}


void GetDistance(ligne *dataset, distanceEtClass *distEtclass, ligne test_set){
    int i = 0, numLigne = 147;

    for (i = 0; i < numLigne ; i++){
        distEtclass[i].distance = sqrt(
            pow(test_set.att.Pettalength - dataset[i].att.Pettalength,2) + 
            pow(test_set.att.Petalwidth - dataset[i].att.Petalwidth,2) 
        );//calcul of euclidien distance

        distEtclass[i].Class = (int) dataset[i].Class;
        distEtclass[i].line = i + 2;//which line in dataset
    }

}

void SortByDistance(distanceEtClass *distEtclass){ //tri 
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
} 

void KNN(ligne *dataset, ligne test_set, int k, int numLigne){//global fonction like fonction main 
    int x,j;
    distanceEtClass *distanceEtClass = malloc(numLigne * sizeof (*distanceEtClass));
    
    GetDistance(dataset, distanceEtClass, test_set);
    SortByDistance(distanceEtClass);
    
    
    int classtrois = 0, classun=0, classdeux =0;
    printf(" ");
    for (x = 0; x < k; x++){
        printf("--------| Distance : %.3f | Class: %d | line: %3d | --------\n ",distanceEtClass[x].distance,distanceEtClass[x].Class, distanceEtClass[x].line);
        if (distanceEtClass[x].Class == 1 ){
            classun +=1;
        }
        if (distanceEtClass[x].Class == 2){
            classdeux += 1;
        }
        if (distanceEtClass[x].Class == 3){
            classtrois += 1;
        }
    }
    if (classun > classdeux && classun > classtrois){
        printf("---------------FLOWER De type iris-setosa (1)---------------\n");
    }
    else if (classdeux > classun && classdeux > classtrois){
        printf("---------------FLOWER De type iris versicolor(2)---------------\n");

    }
     else {printf("---------------FLOWER De type iris-virginica (3)---------------\n");}
    
   
}




