# Algorithmes de Tri 

Ce dépôt regroupe les implémentations et les explications théoriques des principaux algorithmes de tri. Le but est de comprendre le fonctionnement interne de chaque méthode, de la manipulation de la mémoire aux stratégies d'optimisation.

---

## Synthèse des Performances

| Algorithme | Meilleur Cas | Moyenne | Pire Cas | Stabilité |
| :--- | :--- | :--- | :--- | :--- |
| **Tri à Bulles** | $O(n)$ | $O(n^2)$ | $O(n^2)$ | Oui |
| **Tri par Insertion** | $O(n)$ | $O(n^2)$ | $O(n^2)$ | Oui |
| **Tri par Sélection** | $O(n^2)$ | $O(n^2)$ | $O(n^2)$ | Non |
| **Tri par Fusion** | $O(n \log n)$ | $O(n \log n)$ | $O(n \log n)$ | Oui |
| **Tri Rapide** | $O(n \log n)$ | $O(n \log n)$ | $O(n^2)$ | Non |

---

## Algorithmes Élémentaires

###  Tri à Bulles (Bubble Sort)
Le tri à bulles parcourt le tableau et compare les éléments consécutifs. Si deux éléments ne sont pas dans l'ordre, ils sont permutés. À chaque passage, la plus grande valeur "remonte" à sa position définitive.
* **Optimisation :** On utilise un drapeau (booléen) pour interrompre l'algorithme si aucun échange n'a eu lieu durant un parcours complet, signifiant que le tableau est déjà trié.

###  Tri par Insertion (Insertion Sort)
C'est l'algorithme le plus efficace pour les petits tableaux ou les données presque triées. On prend chaque élément un par un et on le fait "remonter" dans la partie déjà triée du tableau jusqu'à rencontrer un élément plus petit.

###  Tri par Sélection (Selection Sort)
Il s'agit d'un algorithme glouton. Sur un tableau de $n$ éléments, on cherche le plus petit élément pour l'échanger avec celui à l'indice 0, puis on cherche le second plus petit pour l'indice 1, et ainsi de suite.

---

## Algorithmes Avancés (Divide & Conquer)

###  Tri par Fusion (Merge Sort)
Souvent utilisé pour les listes chaînées, il repose sur le principe **Diviser pour régner** :
1.  **Division :** Le tableau est divisé récursivement en deux moitiés jusqu'à obtenir des sous-tableaux d'un seul élément.
2.  **Fusion :** Les éléments sont ensuite remontés et fusionnés dans l'ordre pour reconstruire le vecteur final.

[Image of merge sort algorithm diagram]

###  Tri Rapide (Quick Sort)
Le tri rapide utilise un **pivot** pour partitionner le tableau. Les éléments inférieurs au pivot vont à gauche, les supérieurs à droite.

**Stratégies de choix du pivot :**
* **Premier/Dernier élément :** Simple, mais risque de tomber sur la complexité pire cas ($O(n^2)$) si le tableau est déjà trié.
* **Élément aléatoire :** Diminue fortement le risque de pire cas.
* **Médiane de trois :** Consiste à prendre la médiane entre le premier, le dernier et l'élément du milieu. C'est la méthode la plus robuste pour garantir une complexité quasi-linéaire ($O(n \log n)$).

**Mécanisme de Partitionnement (Lomuto) :**
On "gare" le pivot à la fin du tableau. Un indice d'exploration parcourt le vecteur et échange les éléments inférieurs au pivot avec un indice "marqueur" qui définit la frontière des zones. À la fin, le pivot est replacé à sa position définitive entre les deux zones.

