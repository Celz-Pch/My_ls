# 📁 my_ls

## 📄 Description

`my_ls` est une réimplémentation du programme Unix `ls` en C.  
Le but est de reproduire le comportement du `ls` système (au moins en partie), en respectant les options demandées dans le sujet du projet Epitech.

Le programme doit afficher le contenu d’un répertoire selon les options données, en respectant le format de sortie standard.

---

## ⚙️ Fonctionnalités

Ton programme doit gérer au minimum les options suivantes :

| Option | Description |
|---------|--------------|
| `-l` | Affiche le contenu en format long (droits, liens, propriétaire, groupe, taille, date, nom). |
| `-R` | Affiche récursivement le contenu des sous-répertoires. |
| `-a` | Affiche tous les fichiers, y compris ceux commençant par `.`. |
| `-r` | Inverse l’ordre d’affichage. |
| `-t` | Trie les fichiers par date de modification (les plus récents d’abord). |

Les options peuvent être combinées, comme dans la commande réelle :

```bash
./my_ls -lRa
