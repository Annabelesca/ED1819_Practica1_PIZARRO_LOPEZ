<h1><p align="center">ED1819_Practica1_PIZARRO_LOPEZ</p></h1>
<h2><p align="center">Pràctica 1. Estructura de Dades</p></h1>

## 1. Introducció
Aquesta pràctica es basa en la recopilació de les diferents estructures de dades que hem anat implementant a les primeres sessions de laboratori. L’objectiu de la pràctica és crear una única llibreria i comprovar el correcte funcionament d’aquesta, per tant l’estructura de la que consta la pràctica serà la següent:

![Il·lustració 1. Estructura general de la pràctica](https://github.com/Annabelesca/DS_A2_Bosca_Pizarro/blob/master/Ilustraciones/Master.png)

## 2. La Pila
La pila és una estructura de dades que consta d’una base on s’emmagatzemen els elements. Aquests es van afegint un sobre l’altre (és a dir, es van apilant). Només és pot accedir a l’últim element que ha sigut apilat, que rep el nom de Cim. Aquesta estructura és de tipus LIFO (Last In, First Out).
El tipus d’implementació que farem servir en aquesta pràctica és sobre vector i només emmagatzemem enters a la pila. La nostra estructura, a més, emmagatzemarà (com enters) el nombre màxim de elements que pot contenir i el nombre dels elements que es troben emmagatzemats (que a més, marcarà la posició del Cim). Per tant, la nostra estructura segueix aquest model:

![Il·lustració 2. Representació Pila sobre vector](https://github.com/Annabelesca/DS_A2_Bosca_Pizarro/blob/master/Ilustraciones/Master.png)

### 2.1	Cost d’emmagatzemament: 
Suposem que un enter ocupa un espai de 4Bytes.
La nostra estructura consta de 2 enters: El que determina la posició del cim dins l’estructura i el que determina quants elements com a màxim pot contenir l’estructura -> 8Bytes.
A més, també conté un vector d’enters -> MaxElems * 4Bytes.
<p align="center">Cost espaial Pila = 8 Bytes + (MaxElems* 4Bytes)</p> 

### 2.2	Funcions disponibles i costos temporals de l’estructura Pila: 
Totes les funcions següents es troben definides al header “pila.h”.

#### Crear_Pila
```java
Pila Crear_Pila(int max_elem); 
```
Constructor de l’estructura Pila. La funció crea una estructura de dades de tipus Pila i inicialitza les seves variables (nombre d’elements màxims, nombre d’elements emmagatzemats i creació del vector base).

**Paràmetres:**
-	max_elem: nombre màxim d’elements que podrà contenir l’estructura. 

**Retorna:** 
-	Estructura de tipus Pila amb les variables inicialitzades i sense cap element emmagatzemat. 

**Anàlisi del cost:   Θ(1)** -> Crear_Pila és una funció que només fa assignacions, per tant el seu cost serà constant. 


#### Cim_Pila
```java
int Cim_Pila(Pila P); 
```
Mètode de consulta que retorna l’últim element que ha sigut inserit a l’estructura.

**Paràmetres:**
-	P: Pila de la qual es vol consultar el cim.

**Retorna:** 
-	Enter amb el valor del cim o imprimeix per pantalla un error si l’estructura d’on es vol obtenir el cim és buida.

**Anàlisi del cost:   Θ(1)** -> Cim_Pila és una funció que retorna el contingut d’una posició del vector (el cim) del qual es coneix l’índex, per tant el seu cost serà constant.  


#### Apilar_Pila
```java
Pila Apilar_Pila(Pila P, int E);
```
Mètode de modificació de l’estructura que insereix l’element que es passa per paràmetre dins l’estructura. Un cop introduït el nou element, s’incrementa el nombre d’elements emmagatzemats en una unitat.

**Paràmetres:**
-	P: Pila a la qual es vol inserir un nou element.
-	E: Enter que es vol inserir a l’estructura.

**Retorna:** 
-	Estructura de tipus Pila amb el nou element inserit (aquest nou element passa a ser el cim de la Pila) o imprimeix per pantalla un error si l’estructura on es vol inserir un nou element és plena.

**Anàlisi del cost:   Θ(1)** -> Apilar_Pila és una funció que fa una assignació i una suma, per tant el seu cost serà constant.


#### Desapilar_Pila
```java
Pila Desapilar_Pila(Pila P);
```
Mètode de modificació de la estructura que esborra l’element que es troba al cim, decrementant el nombre total d’elements emmagatzemats a la pila i modificant el cursor a cim. 

**Paràmetres:**
-	P: Pila de la qual es vol esborrar el cim.

**Retorna:** 
-	Estructura de tipus Pila o imprimeix per pantalla un error si l’estructura d’on es vol desapilar és buida.

**Anàlisi del cost:   Θ(1)** -> Desapilar_Pila és una funció decrementa un índex, per tant el seu cost serà constant.



#### EsBuida_Pila
```java
int EsBuida_Pila(Pila P);
```
Mètode de consulta que comprova si l’estructura no conté cap element comparant el nombre d’elements emmagatzemats a l’estructura amb 0.

**Paràmetres:**
-	P: Pila la qual es vol comprovar si es buida.

**Retorna:** 
-	1 si l’estructura és buida, 0 altrament.

**Anàlisi del cost:   Θ(1)** -> EsBuida_Pila és una funció que fa una comparació, per tant el seu cost serà constant.


#### EsPlena_Pila
```java
int EsPlena_Pila(Pila P);
```
Mètode de consulta que comprova si l’estructura conté el nombre màxim d’elements comparant el nombre d’elements emmagatzemats a l’estructura amb el nombre màxim d’elements que es poden emmagatzemar.

**Paràmetres:**
-	P: Pila la qual es vol comprovar si es plena.

**Retorna:** 
-	1 si l’estructura és plena, 0 altrament.

**Anàlisi del cost:   Θ(1)** -> EsPlena_Pila és una funció que fa una comparació, per tant el seu cost serà constant.


#### Destruir_Pila
```java
void Destruir_Pila(Pila P);
```
Mètode que allibera l’espai reservat pel vector que conté els enters.

**Paràmetres:**
-	P: Pila de la que es vol alliberar l’espai.

**Anàlisi del cost:   Θ(1)** -> Es crida una funció de la llibreria stdlib.h anomenada free() que el que fa és desassignar una regió de memòria de la qual es coneix la direcció, per tant té un cost constant.


#### missatgeError_Pila
```java
void missatgeError_Pila(int i);
```
Mètode que s’encarrega d’imprimir per pantalla els errors que es produeixen en les diferents funcions de l’estructura en funció de l’índex que se li passa per paràmetre.  

**Paràmetres:**
-	i: Enter que representa el tipus d’error que s’ha produït. Si i=0, es printejarà un error de pila buida. Si i=1, es printejarà un error de pila plena. 

**Anàlisi del cost:   Θ(1)** -> Només es fa un switch i es printeja, per tant, el cost és constant.
