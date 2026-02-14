# Les Structures de Données en Langage C

Ce dépôt est dédié à la mise en œuvre et à l'étude des structures de données fondamentales à l'aide du langage de programmation C. 

En informatique, une structure de données est une organisation logique des données permettant de faciliter leur manipulation et leur traitement. Elle constitue la mise en œuvre concrète d'un Type Abstrait de Données (TAD), faisant le pont entre la théorie algorithmique et la réalité matérielle.

---

## Classification des Structures de Données

Les structures de données sont classées ici selon leur topologie et la nature des relations entre leurs éléments.

### 1. Structures de Données Linéaires
Dans ces structures, les éléments sont organisés de manière séquentielle. Chaque élément (hormis les extrémités) possède un prédécesseur et un successeur unique.

* **Tableaux (Statiques et Dynamiques) :** Accès direct par indice, occupation d'un bloc contigu en mémoire.
* **Listes Chaînées :** Allocation dynamique par nœuds reliés par des pointeurs.
    * *Simplement chaînées* : navigation unidirectionnelle.
    * *Doublement chaînées* : navigation bidirectionnelle.
    * *Circulaires* : le dernier élément boucle sur le premier.
* **Piles (Stack) :** Gestion de type LIFO (Last-In, First-Out).
* **Files (Queue) :** Gestion de type FIFO (First-In, First-Out).

[Image of linear data structures: array, linked list, stack, and queue]

### 2. Structures de Données Non-Linéaires
Ces structures sont utilisées pour modéliser des relations plus complexes qu'une simple séquence. On les divise en trois grandes familles :

#### A. Structures Arborescentes (Hiérarchiques)
Modélisent une relation de type "Un-vers-Plusieurs". Elles sont acycliques et possèdent une racine unique.
* Arbres Binaires de Recherche (ABR).
* Arbres équilibrés (AVL, Arbres Rouge-Noir).
* Tas (Heaps) pour les files de priorité.

[Image of binary search tree and AVL tree structures]

#### B. Structures en Réseaux (Graphes)
Modélisent des relations de type "Plusieurs-vers-Plusieurs". Contrairement aux arbres, les graphes peuvent contenir des cycles et n'ont pas de hiérarchie imposée.
* Représentations par matrices d'adjacence ou listes d'adjacence.
* Algorithmes de parcours (BFS, DFS) et de recherche de chemins.

[Image of graph data structure representing a network]

#### C. Structures Associatives
Basées sur une relation Clé-Valeur. Elles visent à optimiser le temps d'accès aux données indépendamment de la taille du vecteur.
* Tables de hachage.
* Gestion des collisions par chaînage ou adressage ouvert.

---

## Pourquoi le langage C ?

C est un langage de programmation impératif, statique de moyen niveau et à typage fort. Il est le choix de référence pour l'étude des structures de données pour plusieurs raisons fondamentales :

### Maîtrise de la Gestion Mémoire
C offre au développeur une marge de contrôle importante sur la machine. L'absence de ramasse-miettes (Garbage Collector) impose une gestion manuelle de l'allocation et de la libération de la mémoire via `malloc()` et `free()`. Cette approche est cruciale pour comprendre l'occupation spatiale réelle des structures.

### Manipulation des Pointeurs
L'utilisation directe des adresses mémoire permet de construire des structures complexes (comme les listes chaînées ou les arbres) en manipulant les liens entre les nœuds. Cela permet une optimisation fine des algorithmes et une compréhension profonde de la topologie des données.

