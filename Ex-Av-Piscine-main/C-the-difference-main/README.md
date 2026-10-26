# C, the difference

Série de quatre exercices en C pour consolider les bases de la formation 42 : manipulation de chaînes, structures, parsing d'arguments, arithmétique entière et allocation mémoire. Chaque exercice s'accompagne d'une petite mise en situation historique (ou presque).

| Ex. | Programme | Thème | Notions travaillées |
|-----|-----------|-------|---------------------|
| [`ex00`](ex00/) | `ft_paragraph` | *Hot off the press* — Mayence, 1450 | Structures, header, découpage de texte |
| [`ex01`](ex01/) | `ft_calc` | *Your very first own calculator* — Rouen, 1642 | Parsing d'arguments, gestion d'erreurs, multi-fichiers, overflow (bonus) |
| [`ex02`](ex02/) | `ft_acki` | *Veni, vidi, converti* — Rome, 44 av. J.-C. | `/` et `%`, conversion en chiffres romains sans table |
| [`ex03`](ex03/) | `bazinga` | *One malloc to rule them all* — Pasadena | `malloc` unique, grille 2D dans un tableau 1D, macros |

---

## Règles communes

- Code en **C**, conforme à la **Norme** (vérifié avec `norminette`).
- Compilation avec `cc -Wall -Wextra -Werror` : si ça ne compile pas, c'est 0.
- Aucun crash toléré (segfault, bus error, double free…).
- **Pas de variables globales.**
- Seules les fonctions externes listées dans chaque sujet sont autorisées. Toute sortie passe par `write` (`printf`, `putchar`, etc. sont interdits).
- Pas de Makefile requis : chaque programme est compilé avec la commande indiquée dans son sujet.
- Les messages d'erreur partent sur la **sortie d'erreur**, suivis d'un retour à la ligne, et le programme renvoie `1`.

> **À propos de l'IA** — ces exercices sont là pour que tu galères un peu. Raisonne d'abord, papier et crayon en main, échange avec tes pairs, et sois capable d'expliquer chaque ligne que tu rends. Un exercice résolu par une IA est un exercice que tu n'as pas résolu.

---

## ex00 — `ft_paragraph`

Mettre en page un texte en lignes et paragraphes de taille fixe, comme un apprenti typographe chez Gutenberg.

```bash
cc -Wall -Wextra -Werror ft_paragraph.c
./a.out "<texte>"
```

- **Fichiers :** `ft_paragraph.c`, `ft_paragraph.h`
- **Fonction autorisée :** `write`
- Les réglages vivent dans une structure `t_config` (`p_nbr`, `p_len`, `l_len`) déclarée dans le header, et toute la mise en page se fait dans `ft_make_paragraph(char *input, t_config *config)`.
- Les valeurs de configuration n'apparaissent qu'**une seule fois** dans le code, à l'initialisation de la structure : elles seront modifiées en évaluation.
- Texte trop long → `Rest: …` ; texte trop court → messages `Not enough paragraphs.`, `Missing line in paragraph.`, `Missing char in line.` (sur la sortie standard, retour `0`).

## ex01 — `ft_calc`

Une calculatrice en ligne de commande qui calcule ou compare deux entiers, dans la lignée de la Pascaline.

```bash
cc -Wall -Wextra -Werror *.c
./a.out <int> <signe> <int>
```

- **Fichiers :** `ft_calc.c` + autant de `.c` / `.h` que nécessaire (la Norme limite à 5 fonctions par fichier).
- **Fonction autorisée :** `write`
- **Opérateurs :** `+` `-` `*` `/` (division entière) → résultat ; `==` `!=` `<` `>` → `true` / `false`.
- Les arguments sont vérifiés de gauche à droite, seule la première erreur est affichée. Division par zéro gérée.
- **Bonus :** détection des dépassements d'`int` (arguments et résultat).

> 💡 Pense à protéger les signes dans ton shell : `./a.out 6 '*' 7`.

## ex02 — `ft_acki`

Convertir un nombre décimal (1 à 3999) en chiffres romains… sans aucune table de conversion.

```bash
cc -Wall -Wextra -Werror ft_acki.c
./a.out <nombre>
```

- **Fichier :** `ft_acki.c`
- **Fonction autorisée :** `write`
- **Interdit :** tout tableau, chaîne ou structure stockant des symboles romains ou leurs valeurs. Le résultat doit être **calculé**, pas recherché. Seuls les littéraux `'I'`, `'V'`, `'X'`… sont autorisés.
- Zéros initiaux acceptés (`0042` → `XLII`) ; les très grands nombres doivent produire l'erreur de plage, pas un crash.

## ex03 — `bazinga`

Construire une grille 2D avec **un seul `malloc`** et afficher un mot centré dedans.

```bash
cc -Wall -Wextra -Werror bazinga.c
./a.out <largeur> <hauteur>
```

- **Fichiers :** `bazinga.c`, `bazinga.h`
- **Fonctions autorisées :** `malloc`, `free`, `write`
- **Interdit :** plus d'un appel à `malloc`, `calloc` / `realloc`, tableaux statiques, VLA et `char **`. La grille est une seule ligne de mémoire, indexée par `grid[y * width + x]`.
- Le mot et le caractère de remplissage sont définis par les macros `BAZINGA` et `FILLER` dans le header, et le programme doit fonctionner avec n'importe quelles autres valeurs.
- Toute la mémoire doit être libérée : aucune fuite tolérée.

---

## Structure attendue

```
.
├── ex00/
│   ├── ft_paragraph.c
│   └── ft_paragraph.h
├── ex01/
│   ├── ft_calc.c
│   └── … (autres .c / .h)
├── ex02/
│   └── ft_acki.c
└── ex03/
    ├── bazinga.c
    └── bazinga.h
```

## Tester

Les sujets utilisent `cat -e` pour rendre visibles les fins de ligne (`$`) :

```bash
./a.out 21 + 21 | cat -e     # 42$
./a.out 42 / 0; echo $?      # Error: division by zero.  puis 1
```

Pense aux cas limites : chaîne vide, zéro, nombres négatifs ou énormes, mauvais nombre d'arguments, grilles minuscules… Tes évaluateurs les testeront, c'est certain.

## Évaluation

Correction par les pairs. Pendant l'évaluation, une **petite modification** peut être demandée pour vérifier que tu comprends ton code, par exemple :

- **ex00** : changer les valeurs de la structure ou y ajouter un champ ;
- **ex01** : ajouter un opérateur (`%`, `<=`, `>=`) ;
- **ex02** : afficher en minuscules ou détailler la conversion (`1987 = M + CM + LXXX + VII`) ;
- **ex03** : changer les macros (`BAZINGA` → `"42"`, `FILLER` → `'#'`).
