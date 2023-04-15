Bienvenue dans le projet d'étude sur les algorithmes de tri.
Application de visualisation et de génération de données CSV pour le Python en C++ et qui demande des librairies à installer. (Voir make download_lib)
(Vous pouvez avoir des problèmes avec make download_lib si votre version de linux n'est pas mis à jour)

Projet réalisé avec l'aide de :
Antoine https://github.com/aa2727
Guillaume https://github.com/P-Pix
Logan https://github.com/LoganVivien

-Le dossier Data contient la partie analyse des données du projet
-Le dossier App contient le code source de l'application de visualisation des algorithmes de tri.

# Comment je lance une visualisation ?

Allez dans le répertoire App et lancez la commande suivante :

`make init`
`make download_lib`  (cela va installer les dépendances de l'application si elles ne sont pas déjà installées sur votre machine)
`make all`
Si tout se passe bien vous pouvez à présent faire: 
`./Sorting_Algorithm HeapSort`

Cela va lancer l'application avec l'algorithme de tri HeapSort.

# Comment je regarde les résultats de l'analyse ?

Vous pouvez vous rendre dans le dossier Data et ouvrir les fichiers .pynb avec Jupyter Notebook.
Chaque algorithme possède son fichier d'analyse et le fichier ComparatifInterAlgo.ipynb en fait la synthèse.

