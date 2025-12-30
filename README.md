# Gestion d'un Hôpital Intelligent

## Description
Application console développée en langage C pour optimiser la gestion des flux patients au sein d'un service hospitalier. Le programme implémente un système de **triage médical** : les patients sont organisés dynamiquement selon leur niveau d'urgence grâce à des algorithmes de structures de données.

Le projet inclut également la conception complète du système (Diagrammes de cas d'utilisation, de classes et de séquence) modélisée avec StarUML.

## Fonctionnalités Implémentées
* **Gestion des Admissions (Triage) :** Ajout de patients avec un niveau d'urgence (1 à 5). L'algorithme insère automatiquement le patient à la bonne position dans la file d'attente pour prioriser les cas critiques.
* **Suivi Médical (Historique) :** Chaque patient possède un dossier médical évolutif contenant l'historique des consultations (Date, Médecin, Soins).
* **Mise à Jour des Dossiers :** Ajout de nouvelles consultations dans l'historique d'un patient existant.
* **Recherche et Consultation :** Recherche rapide d'un patient par son identifiant unique (ID) pour consulter ses antécédents et son historique complet.
* **Affichage Global :** Visualisation de la liste des patients triée par ordre de priorité.

## Architecture Technique
* **Langage :** C Standard.
* **Structures de Données :**
  * **File de Priorité :** Utilisée pour la liste principale des patients, ordonnée selon l'urgence.
  * **Listes Chaînées :** Gestion dynamique de la mémoire.
  * **Piles (LIFO) :** Gestion de l'historique des consultations.

## Conception (UML)
Le projet comprend une modélisation UML détaillée (fichier .mdj) incluant :
* **Diagramme de Cas d'Utilisation :** Identification des acteurs (Patient, Médecin, Secrétaire, Administrateur).
* **Diagramme de Classes :** Structure des entités (Patient, DossierMédical, Médecin, Utilisateur).
* **Diagrammes de Séquence et d'Activité :** Modélisation des flux de connexion et de gestion des dossiers.

## Installation
1. Cloner le dépôt.
2. Compiler le fichier source `Gestion d’un hôpital intelligent.c`.
3. Lancer l'exécutable généré.

## Auteurs
Projet réalisé Hiba Karam en collaboration avec Tarek Souibri - Élèves Ingénieurs @ EMSI.
