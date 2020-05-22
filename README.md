# m2cdsi-sadmd
Metaheuristique pour la résolution du problème du sac à dos multidimensionnel avec contraintes de demande


## Pour le bon fonctionnement du git 

Quelques rappels :

- Avant toute modification du code, ou pour télécharger la dernière version, on tape dans son terminal **git pull**

- Pour ajouter un ou des fichiers modifiés, on utilise **git add [nom_fichier]**. Pour tout ajouter, on peut utiliser "git add \*" . 
- Pour faire une demande de commit et dire ce que l'on à fait : **git commit -m 'Le commentaire sur ce que vous avez ajouté' **. Le commit et le commentaire sont **obligatoires**
- Enfin, pour uploader votre code après avoir fait tout ça : **git push**


Pour l'instant je ne pense pas que ça soit nescessaire de se compliquer la vie avec des branches, mais du coup, il ne faut jamais **uploader du code sans se concerter**, sous peine d'avoir des conflits.

## Fonctionnement actuel du code

La classe Data permet d'initialiser un objet contenant toutes les données du fichier correspondant dont on se servira par la suite.

Pour tester le code, on le clone, on se met dans le dossier, on tape **make**, puis *./output*.

