# Notes

- N'utiliser l'héritage publique que si la classe IS-A la classe parent. Aussi, n'utiliser que l'héritage publique afin d'être réutilisée.
- Compiler firewall idiom est probablement la meilleure idée pour implémenter l'héritage privé.
- Mettre `const` partout, sauf dans le retour de méthode, car c'est optimisé sans le `const`.
- Faire ultra attention aux exceptions. Favoriser le swap et les copies temporaires et préférablement passer par copie les arguments, lorsque possible et utile. Utiliser le copy-and-swap idiom pour les classes.
- Placement new crée un objet dans un espace mémoire déjà alloué avec l'opérateur new global.
- Le destructeur doit absolument être `noexcept`!
- Déclarer les constructeurs comme `explicit` afin d'éviter les conversions et les appels implicites non voulus.
- L'argument-dependent lookup - Koenig lookup - permet de chercher des fonctions dans plus de scopes. Juste le fait de référencer un type en argument active l'ADL.
