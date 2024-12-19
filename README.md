# Projet Individuel Semestre 1 Prog&Algo
- [Projet Individuel Semestre 1 Prog\&Algo](#projet-individuel-semestre-1-progalgo)
  - [Indications](#indications)
  - [Projet d'origine](#projet-dorigine)
  - [Ajout d'un puissance 4 disposant d'un mode 2 joueurs](#ajout-dun-puissance-4-disposant-dun-mode-2-joueurs)
  - [Structure des fichiers](#structure-des-fichiers)
  - [Choix d'implémentation](#choix-dimplémentation)

## Indications

Programme créé et testé sous Windows 10 64bit

## Projet d'origine
Objectif: Créer un Morpion disposant d'un mode solo et d'un mode deux joueurs

Pour utiliser le projet d'origine, utilisez la fonction
```cpp
boot_menu();
```
(Si c'est la première fois que vous utilisez ces fichiers, il suffira de décommenter la ligne correspondante.)

Aucune difficulté particulière à signaler.

## Ajout d'un puissance 4 disposant d'un mode 2 joueurs
Pour pouvoir jouer au puissance 4, utilisez la fonction
```cpp
boot_menu_with_connect4();
```
(Si c'est la première fois que vous utilisez ces fichiers, il suffira de décommenter la ligne correspondante.)

Le jeu se joue comme si l'on avait le jeu de société devant soi.

Problème principal: Ne pas coder en dur toutes les combinaisons possibles.
Solution: coder en dur les combinaisons diagonales et faire des boucles pour les combinaisons verticales et horizontales.

## Structure des fichiers
Les fichiers Player(.cpp et .hpp) contiennent la définition d'un joueur, la fonction qui permet de créer un nouveau joueur ainsi qu'une fonction 
```cpp
detect_similarities(Player const & player_1, Player & player_2)
```
qui permet d'empêcher que deux joueurs aient le même nom et/ou le même symbole.

Les fichiers main(.cpp et .hpp) contiennent toutes les fonctions relatives au bon fonctionnement du jeu de morpion ainsi que les deux fonctions qui permettent de jouer uniquement au morpion et l'autre qui donne le choix entre le morpion et le puissance 4.

Les fichiers connect4(.cpp et .hpp) contiennent toutes les fonctions relatives au bon fonctionnement du jeu de puissance 4.

## Choix d'implémentation
Les deux jeux se jouent à l'aide du terminal.