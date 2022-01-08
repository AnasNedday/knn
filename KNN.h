#ifndef _KNN
  #define _KNN

  typedef struct{
    float Pettalength,Petalwidth;
  
     }attribut;

 typedef struct{
     attribut att;
    int Class;
     }ligne;

typedef struct {
        float distance;
        int Class;
        int line;
    }distanceEtClass;


 void searchData(FILE *file, ligne *dataset);
 void GetDistance(ligne *dataset, distanceEtClass *distEtclass, ligne test_set);
 void SortByDistance(distanceEtClass *distEtclass);
 float KNN(ligne *dataset, ligne test_set, int k, int numLigne);


#endif

    

