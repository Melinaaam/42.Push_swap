# Push_Swap
_Parce que Swap_push, c’est moins naturel_

> **Objectif :** Trier une liste de nombres entiers avec un minimum d'opérations, en utilisant deux piles représentées par des listes chaînées.

---

## Introduction

Le projet **Push Swap** consiste à trier une liste d'entiers en utilisant exclusivement un ensemble d’opérations prédéfinies sur deux piles (A et B).  
Chaque pile est représentée ici par une liste chaînée (type `t_pslist`).  
L’enjeu est de **minimiser le nombre d’opérations** (`sa`, `sb`, `pa`, `pb`, `ra`, `rb`, etc.) et de gérer efficacement la mémoire ainsi que les cas d’erreurs.

---

## 1. Récupérer les arguments

### 1.1 Lancement du programme

Le programme peut être appelé de deux manières :

1. **Avec plusieurs arguments séparés** :

   ```bash
   ./push_swap 6 10 7 3 4
   ```

   Dans ce cas, chaque argument représente un nombre à trier.

2. **Avec un seul argument et des valeurs entre guillemets** :

   ```bash
   ./push_swap "6 10 7 3 4"
   ```

   Ici, il faut **split** la chaîne de caractères reçue afin d'obtenir un tableau de nombres séparés.

### 1.2 Gestion des arguments

- Le premier paramètre dans `argv[0]` est toujours le nom de l'exécutable.  
- Les paramètres suivants (`argv[1]`, `argv[2]`, etc.) sont soit les nombres à trier, soit la chaîne unique à découper.  
- Si l’on procède à un **split** (dans le cas de l’argument unique), il faudra gérer la **libération** de ce tableau après usage.

---

## 2. Vérifications et création de la pile A

Une fois les arguments collectés (qu’il s’agisse de plusieurs arguments ou d’un seul argument splitté), on exécute les vérifications suivantes :

1. **Est-ce un nombre valide ?**  
   - La fonction `is_numeric()` peut aider à s’assurer qu’il s’agit bien de chiffres (avec gestion éventuelle du signe `+` ou `-`).
2. **Conversion en type `long`** via `ft_atol()` pour vérifier les débordements.  
   - On compare ensuite la valeur convertie à `INT_MIN` et `INT_MAX`.
3. **Vérifier qu’il n’existe pas de doublon** dans la liste (fonction `is_double()`).  
4. **En cas de problème** :  
   - Libérer la liste chaînée (pile A) déjà créée.  
   - Libérer le tableau issu du `split` si nécessaire.  
   - Afficher un message d’erreur et **stopper** le programme.

Si tout est correct, on **crée la liste chaînée** représentant la pile A (avec `new_node()`) en insérant un maillon pour chaque entier.

---

## 3. Algorithme de tri

Le tri se déroule essentiellement sur la pile A, avec l’aide de la pile B comme espace temporaire.

### 3.1 Cas simples : 2 ou 3 valeurs

- **2 valeurs** : un simple échange (`ft_sa()`) suffit.  
- **3 valeurs** : on repère le plus grand élément et on effectue quelques rotations ou swaps pour les mettre dans l’ordre (par exemple avec la fonction `sort_three()`).

### 3.2 Cas généraux (+ de 3 valeurs)

1. **Partition (pile A vers B)**  
   - On calcule une médiane (ex. via `find_mediane()`) puis on **pousse** dans B (`ft_pb()`) tous les éléments en-dessous (ou au-dessus) de cette médiane pour un premier tri grossier.  
   - On répète jusqu’à ce qu’il reste **3 éléments** dans A, et on applique ensuite le tri pour 3.

2. **Récupération des éléments de B dans A**  
   - Chaque élément de B a une cible dans A (`find_closer()` + `cost_calcul()` pour déterminer où insérer).  
   - On détermine le **coût** de déplacement (nombre de rotations `ra` / `rra` + `rb` / `rrb`).  
   - On identifie l’**élément le moins cher** et on l’insère dans A au-dessus de sa cible.

3. **Finalisation**  
   - Vérifier que l’élément le plus petit se trouve en **tête** de A.  
   - Si ce n’est pas le cas, on effectue des rotations ou reverse rotations pour le remonter en haut de la liste.

Les fonctions comme `partition_a()`, `sort_a_and_b()`, `move_to_a()`, etc., gèrent ces étapes.

---

## 4. Contrôles et outils de vérification

### 4.1 Visualisation

Un outil ([push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer.git)) permet de générer des listes de grande taille et de **visualiser** l’exécution. Pour l’installer :

```bash
git clone https://github.com/o-reo/push_swap_visualizer.git
cd push_swap_visualizer
mkdir build
cd build
cmake ..
make
./bin/visualizer
```

On peut ensuite **observer** le comportement de `push_swap`.

---

## Conclusion

Le **Push Swap** est un excellent exercice pour travailler :

- La **gestion de piles** (listes chaînées, insertion, suppression).  
- Les **opérations** (`sa`, `pa`, `ra`, etc.).  
- La **stratégie algorithmique** (calcul de médianes, évaluation du coût de déplacement).  
- La **mémoire** (valgrind, funcheck, etc.).  

**Bon courage pour votre implémentation et bonne programmation !**

