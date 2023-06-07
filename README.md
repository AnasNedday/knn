# KNN 
KNN : Définition
Avant de nous concentrer sur l’algorithme KNN, il est nécessaire de reprendre les bases.  Qu’est-ce qu’un algorithme d’apprentissage supervisé? 
En apprentissage supervisé, un algorithme reçoit un ensemble de données qui est étiqueté
avec des valeurs de sorties correspondantes sur lequel il va pouvoir s’entraîner et définir 
un modèle de prédiction. Cet algorithme pourra par la suite être utilisé sur de nouvelles données 
afin de prédire leurs valeurs de sorties correspondantes.

L’intuition derrière l’algorithme des K plus proches voisins est l’une des plus simples de tous les algorithmes de Machine Learning supervisé :

#### Étape 1 :  Sélectionnez le nombre K de voisins
#### Étape 2 :  Calculez la distance
  Du point non classifié aux autres points.
#### Étape 3 :  Prenez les K voisins les plus proches selon la distance calculée.
#### Étape 4 :  Parmi ces K voisins, comptez le nombre de points  appartenant à chaque catégorie.
#### Étape 5 : Attribuez le nouveau point à la catégorie la plus présente parmis ces K voisins.
#### Étape 6 : Notre modèle est prêt :
