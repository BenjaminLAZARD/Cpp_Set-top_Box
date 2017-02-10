# TP de C++ set-top box
**Address of the full content with _Version Control_ : https://github.com/BenjaminLAZARD/inf224**
A cette adresse il est possible de consulter le dépot GIT où j'ai réalisé mon travail, étape par étape.

Pour visualiser ce fichier stylisé, il suffit de l'ouvrir dans Atom et d'utiliser le raccourci `ctrl + maj + m`. Eclipse ou un navigateur internet le permettent également.

## Etape 4
+ Une méthode dont l'implémentation n'a pas de sens au niveau de la classe de base est dite abstraite.
On les déclare avec "=0" à la fin de la signature dans le header.
+ Le makefile n'a besoin que des fichiers .cpp employés. Le main appelle tous les headers nécessaires.
+ La classe de base devient abstraite (car l'une de ses méthodes est abstraite). Elle n'est donc plus instanciable.

## Etape 5
+ Le polymorphisme permet la recherche dynamique de méthodes virtuelles parentes. Ainsi une array de mediaobject
pour laquelle on appelle la fonction print, utilise le print spécifique à chaque sous-classe si possible.
+ Dans le cadre du C++, il faut connaître la longueur du tableau, et avoir des méthodes parentes virtuelles.
+ Les élements du tableau sont des pointeurs vers ces objets. Cela permet qu'une modification externe de l'un des objets se répercute
dans un accès à l'élément correspondant du tableau.
+ Java est similaire, mais les jongleries avec les pointeurs sont cachées. Les références sont comme les pointeurs.

## Etape 6
Pour assurer l'encapsulation des données et en particulier du tableau de durées de chapitres, il faut qu'un constructeur
n'utilise pas seulement l'adresse du tableau d'origine, mais qu'il en fasse une copie profonde. De même, un accès au tableau
nécessite une copie et non le seul passage de l'adresse. En effet, si ces conditions ne sont pas respectées, une opération sur
le tableau utilisé par le constructeur ou renvoyé par l'objet va modifier l'objet. Les getteurs son facilement réalisés en C ++ grâce aux objets de type `const type*`.

## Etape 7
+ Il est nécessaire d'effacer le tableau de chapitres dans Movie, car l'allocation n'est pas dans la pile comme
pour les autres attributs des autres classes. Seul le pointeur est détruit lors de la destruction de la classe, pas l'objet pointé.
+ La copie de Movie pose problème à cause du tableau d'entier matérialisé par un pointeur. Il faut dupliquer l'objet
correspondant lors de la copie avec la méthode operator= et le constructor copy.

## Etape 8
Les éléments du tableau ne sont que des références pour que des modifications sur les objets se répecercutent sur des consultations ultérieurs du tableau. Cela sert également à assurer le partage dynamique entre objets : si on modifie une photo, on doit pouvoir retrouver la photo modifiée dans les groupes auxquels appartient la photo.

## ETAPE 10
Pour éviter que les objets puissent être créés en dehors de la classe "bibliothèque" (library chez moi)... Il  y a plusieurs solutions...
+ Une première façon de faire est d'utiliser les classes multimedia comme des classes imbriquées dans la bibliothèque.
+ Une deuxième façon de faire serait de déclarer les constructeurs comme étant des méthodes privées... Mais c'et vraiment bizarre. On préfère donc la première solution bien que je ne l'ai pas mise en place ici.

## ETAPE 11
Il est nettement plus simple d'ajouter la fonction processRequest à la bibliothèque pour que celle-ci ait accès aux bonnes variables.

## ETAPE 12
Cette étape a été réalisée comme dans le cours, et une procédure de test a été construite. Cependant, le débuggage n'a pas été fait par manque detemps (problème avec un getline). Normalement, peu de choses sont à modifier pour que cela soit correct.

## ETAPE 13
Cette étape a été réalisée comme dans le cours, et une procédure de test a été construite. Cependant, le débuggage n'a pas été fait par manque de temps (problème avec la fonction getline). Normalement, peu de choses sont à modifier pour que cela soit correct.
Dans les 3 cas suggérés par l'énoncé, des erreurs ont été levées. Pour le cas d'une suppression intempestive, une solution sans levée d'erreur ayant déjà été construite, l'erreur n'a été rajoutée que pour montrer ma compréhension du principe.

___

## Java Swing ETAPE 1
Pas vraiment de commentaires... ça marche. Je n'ai plus beaucoup de temps car je pars au ski pendant les vacances et je n'aurai pas internet. Pour cette raison, je me suis contenté de faire en sorte de répondre aux attentes de l'énoncé de manière complète, mais sans contrainte de "style" ni "ergonomie".
J'ai oublié, je crois, de réaliser le bouton qui permet de quiter l'application. En fait il apparait dans le code, masi j'ai oublié de l'ajouter à un JPanel...

## Java Swing ETAPE 2
Je me suis aidé de ce [*tutoriel*](https://docs.oracle.com/javase/tutorial/uiswing/misc/action.html) pour comprendre comment implémenter les abstract actions.
On peut quiter l'application via le menu. Mais j'ai laissé trainé le bouton qui permet de quitter l'application inutilement dans le code.

## Java Swing ETAPE 3
Tout marche correctement. Essayez notamment d'utiliser la GUI java pour jouer l'image `landscape` et la video `whereiwent` (enfin là où je vais).
Je n'ai pas pris le temps de faire une fonction de mise en pause... Mais j'ai pris en compte une éventuelle déconnexion du serveur, et quelques autres cas d'erreur. Il est également possible d'effacer la "console" de la remote-control.


    En vous souhaitant une bonne journée,
    Bien cordialement,

    Benjamin LAZARD
