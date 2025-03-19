# Documentation - my_ls

## Introduction
`my_ls` est une implémentation personnalisée de la commande `ls` en C. Cette commande permet d'afficher le contenu d'un répertoire avec diverses options influençant l'affichage.

## Compilation

Utilisez le `Makefile` fourni pour compiler le programme :
```
make
```
Cela générera un exécutable nommé `my_ls`.

Pour nettoyer les fichiers objets et l'exécutable :
```
make clean
make fclean
```
Pour recompiler entièrement :
```
make re
```

## Utilisation

La syntaxe de `my_ls` est la suivante :
```
./my_ls [OPTIONS] [CHEMIN...]
```
Si aucun chemin n'est fourni, `my_ls` liste le contenu du répertoire courant.

## Options supportées

- `-l` : Affiche les détails des fichiers (permissions, taille, date de modification, etc.).
- `-R` : Liste récursivement les sous-répertoires.
- `-r` : Trie les fichiers en ordre inverse.
- `-d` : Affiche les informations des répertoires sans lister leur contenu.
- `-t` : Trie par date de modification.
- `-a` : Affiche tous les fichiers, y compris ceux commençant par `.`.
- `-A` : Comme `-a`, mais exclut `.` et `..`.
- `-L` : Suit les liens symboliques.

## Exemples d'utilisation

- Lister les fichiers du répertoire courant :
  ```
  ./my_ls
  ```
- Lister les fichiers avec détails :
  ```
  ./my_ls -l
  ```
- Lister tous les fichiers, y compris les fichiers cachés :
  ```
  ./my_ls -a
  ```
- Lister les fichiers triés par date de modification :
  ```
  ./my_ls -t
  ```
- Lister récursivement tous les fichiers et dossiers :
  ```
  ./my_ls -R
  ```
- Afficher les informations d'un répertoire sans lister son contenu :
  ```
  ./my_ls -d dossier/
  ```

## Fonctionnalités avancées

- `my_ls` utilise `opendir()`, `readdir()`, et `stat()` pour lire les fichiers et répertoires.
- Les options peuvent être combinées, par exemple :
  ```
  ./my_ls -l -a -t
  ```

## Erreurs possibles

- **"Permission denied"** : Vous n'avez pas les droits pour accéder à un répertoire.
- **"No such file or directory"** : Le fichier ou répertoire demandé n'existe pas.
- **"Invalid option"** : Une option non reconnue a été fournie.

## Run avec le Dockerfile

```
docker run -it --rm my_ls_image /bin/bash
```
## Conclusion

`my_ls` est une alternative à `ls` permettant d'explorer les fichiers et répertoires avec des options variées. Pour toute question ou amélioration, consultez le code source et les commentaires dans les fichiers `*.c` et `*.h`.

---
