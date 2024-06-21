# CATS VS. BOXES

## Descriere
Acest joc este inspirat din jocul Plants vs. Zombies. Nu exista o modalitate de a castiga, scopul este de a obtine un scor cat mai mare.
Dupa putin timp tot jocul va deveni un haos in care v-a trebui sa colectezi resurse, sa pui jos pisici luptatoare si sa fii atent la cutiile buclucase.

## Pisicile
Sunt 3 tipuri de pisici pe care le poti folosi pentru a-ti apara domiciliul de cutiile malefice :
- Pisica Pistolara (nume misterios)
- Pisica Cersetoare (Armando)
- Pisica Mare si Grasa (Gordo)

Într-o zi obișnuită, într-un cartier liniștit, locuia o pisica. Era o felină aparte, cu o blană moale și cu o privire fulgerătoare. Ce o făcea diferită era că avea un pistol ciudat - un mic aparat care trăgea gheme de ață.

Stăpânul ei, un băiat pe nume Ion Ionut Ionel, nu știa despre abilitățile neobișnuite ale pisicii sale, dar într-o zi, când un grup de cutii de carton malefice au început să se apropie de casa lor, pisica pistolara și-a scos arma și s-a pregătit să apere teritoriul.

Pentru a face față acestei amenințări, pisica pistolara nu e singură. În echipa ei se numărau prietenii săi: Armando, o pisică cersetoare care făcea rost de Whiskas pentru a le da energie pisicilor din cartier, și Gordo, o pisică mare și grăsuță care putea ține ocupate cutiile malefice mai mult timp. În cazuri extreme și nefericite, Gordo era pregătită să se sacrifice pentru binele tuturor.

Cu un fel de îndemânare deosebită pentru o pisică, pistolara trăgea gheme de ață precise, lovindu-le pe cutii ca pe niște tintele mobile. Cu fiecare gheme trasă, o cutie malefică cădea.

## Important!
Aveți voie cu cod generat de modele de limbaj la care nu ați contribuit semnificativ doar în folder-ul `generated`.
Codul generat pus "ca să fie"/pe care nu îl înțelegeți se punctează doar pentru puncte bonus, doar în contextul
în care oferă funcționalități ajutătoare și doar dacă are sens.

O cerință nu se consideră îndeplinită dacă este realizată doar ca o serie de apeluri proxy către cod generat.

### Cerințe modele de limbaj la nivel de semestru
- [ ] minim o funcționalitate majoritar doar cu LLM
- [ ] minim 2-3 funcționalități ~50% voi, ~50% LLM-ul
- [ ] minim 2-3 funcționalități suficient de complicate pe care un LLM nu le poate implementa

### Tema 0

- [ ] Nume proiect (poate fi schimbat ulterior)
- [ ] Scurtă descriere a temei alese, ce v-ați propus să implementați

## Tema 1

#### Cerințe
- [ ] definirea a minim **3-4 clase** folosind compunere cu clasele definite de voi
- [ ] constructori de inițializare
- [ ] pentru o aceeași (singură) clasă: constructor de copiere, `operator=` de copiere, destructor
<!-- - [ ] pentru o altă clasă: constructor de mutare, `operator=` de mutare, destructor -->
<!-- - [ ] pentru o altă clasă: toate cele 5 funcții membru speciale -->
- [ ] `operator<<` pentru toate clasele pentru afișare (std::ostream)
- [ ] cât mai multe `const` (unde este cazul)
- [ ] implementarea a minim 3 funcții membru publice pentru funcționalități specifice temei alese, dintre care cel puțin 1-2 funcții mai complexe
  - nu doar citiri/afișări sau adăugat/șters elemente într-un/dintr-un vector
- [ ] scenariu de utilizare a claselor definite:
  - crearea de obiecte și apelarea tuturor funcțiilor membru publice în main
  - vor fi adăugate în fișierul `tastatura.txt` DOAR exemple de date de intrare de la tastatură (dacă există); dacă aveți nevoie de date din fișiere, creați alte fișiere separat
- [ ] tag de `git`: de exemplu `v0.1`
- [ ] serviciu de integrare continuă (CI); exemplu: GitHub Actions

## Tema 2

#### Cerințe
- [x] separarea codului din clase în `.h` (sau `.hpp`) și `.cpp`
- [ ] moșteniri:
  - [x] minim o clasă de bază și **3 clase derivate**
  - [x] ierarhia trebuie să fie cu bază proprie, nu derivată dintr-o clasă predefinită
  - [x] clasă cu atribut de tip pointer la o clasă de bază cu derivate
  - [x] funcții virtuale (pure) apelate prin pointeri de bază din clasa care conține atributul de tip pointer de bază
    - minim o funcție virtuală va fi **specifică temei** (e.g. nu simple citiri/afișări)
    - constructori virtuali (clone): sunt necesari, dar nu se consideră funcții specifice temei
  - [x] apelarea constructorului din clasa de bază din constructori din derivate
  - [x] smart pointers (recomandat, opțional)
  - [x] `dynamic_cast`/`std::dynamic_pointer_cast` pentru downcast cu sens
- [ ] suprascris cc/op= pentru copieri/atribuiri corecte, copy and swap
- [x] excepții
  - [x] ierarhie proprie cu baza `std::exception` sau derivată din `std::exception`; minim **3** clase pentru erori specifice
  - [x] utilizare cu sens: de exemplu, `throw` în constructor (sau funcție care întoarce un obiect), `try`/`catch` în `main`
- [x] funcții și atribute `static`
- [x] STL
- [x] cât mai multe `const`
- [ ] la sfârșit: commit separat cu adăugarea unei noi clase derivate fără a modifica restul codului, **pe lângă cele 3 derivate deja adăugate**
  - noua derivată nu poate fi una existentă care a fost ștearsă și adăugată din nou
- [x] tag de `git`: de exemplu `v0.2`

## Tema 3

#### Cerințe
- [ ] 2 șabloane de proiectare (design patterns)
- [ ] o clasă șablon cu sens; minim **2 instanțieri**
  - [ ] preferabil și o funcție șablon (template) cu sens; minim 2 instanțieri
<!-- - [ ] o specializare pe funcție/clasă șablon -->
- [ ] tag de `git`: de exemplu `v0.3` sau `v1.0`

## Resurse

- whiskas : https://catdogshop.cl/producto/whiskas-adulto-pollo-1-kg/
- projectile : https://clipart-library.com/clipart/583502.htm
- fragile box : https://box-printing.co.uk/fragile-boxes
- normal box : https://www.amazon.ca/Boxes-Fast-BF121236-Cardboard-Corrugated/dp/B077BSG1VN
- heavy box : https://www.gostore.co.uk/product/boxes-packaging/large-packing-box/
- wall cat : https://www.pinterest.com.mx/pin/344877283950240286/
- shooter cat : https://www.amazon.com/Kalashnikat-Funny-Sticker-Decal-Bumper/dp/B08NG1B41Q
- generator cat : https://www.youtube.com/channel/UC49eIaJNhhBrvEjPDBJQUCA

Font : https://fontsforyou.com/en/fonts/66398-yoster.font


- [SFML](https://github.com/SFML/SFML/tree/2.6.1) (Zlib)
- adăugați trimiteri către resursele externe care v-au ajutat sau pe care le-ați folosit
