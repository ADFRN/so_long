so_long (macOS - Intel - Azerty)
================================

Petit jeu 2D réalisé avec MiniLibX (projet 42). Le joueur doit récupérer toutes les collectes puis atteindre la sortie sans traverser les murs.

Installation
------------

- Prérequis: `cc`, `make`, MiniLibX déjà inclus dans le dépôt.
- Cloner le projet puis, à la racine, lancer `make` pour construire l'exécutable `so_long`.

Lancer le jeu
-------------

- Construire: `make`
- Exécuter: `./so_long maps/map_1765289120.ber` (ou toute carte `.ber` valide).
- Nettoyer les binaires: `make clean` ; tout nettoyer: `make fclean`.

Contrôles
----------

- Déplacements: `Z`/`Q`/`S`/`D`.
- Quitter: `Esc` ou fermer la fenêtre.

Cartes
------

- Les cartes sont des fichiers `.ber` dans `maps/`.
- Chaque carte doit être rectangulaire et entourée de murs, contenir au moins une sortie `E`, un joueur `P` et un collectible `C`.

Ressources utiles
-----------------

- MiniLibX macOS et incluse dans  `minilibx/`.
- Pour regénérer une map : `./maps/generate.sh`.
