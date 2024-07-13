# Laborator pentru elevii de liceu la FMI UniBuc 2024

## Sortări

Dorim să observăm practic ce înseamnă diferite clase de complexitate.

Etape:
- afișarea unui tablou unidimensional (vector)
- generarea de numere aleatoare
- cronometrarea timpului de execuție
- alocare dinamică
- sortare prin interschimbare în $O(n^2)$
- sortare rapidă cu funcția predefinită `qsort` în $O(n*log(n))$

După ce avem cele două implementări cu timpii de execuție, desenăm datele pe un grafic.

## Backtracking

Aplicăm tehnica de programare Backtracking pentru a rezolva probleme specifice.

Arătăm o structură generală care poate fi aplicată pe orice fel de problemă, apoi particularizăm rezolvarea din motive de eficiență.

Ca problemă concretă, dorim să rezolvăm un puzzle de Jigsaw Sudoku (sau nonomino). Condițiile sunt:
- unicitate pe linii
- unicitate pe coloane
- unicitate pe zone

Etape:
- citirea datelor din fișier
- afișarea datelor citite
- completarea unui singur element
- completarea (fără condiții) a tuturor elementelor (un fel de forță brută)
- aplicarea constrângerii de unicitate pe linii
- aplicarea constrângerii de unicitate pe coloane
- aplicarea constrângerii de unicitate pe zone
- optimizarea soluției

Pentru afișare cu text colorat în mod portabil, am folosit [rlutil](https://github.com/tapio/rlutil).
