# TP de C++ set-top box
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
___