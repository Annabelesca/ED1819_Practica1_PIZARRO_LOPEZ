<h1><p align="center">ED1819_Practica1_PIZARRO_LOPEZ</p></h1>
<h2><p align="center">Pràctica 1. Estructura de Dades</p></h1>

## 1. Introducció
Aquesta pràctica es basa en la recopilació de les diferents estructures de dades que hem anat implementant a les primeres sessions de laboratori. L’objectiu de la pràctica és crear una única llibreria i comprovar el correcte funcionament d’aquesta, per tant l’estructura de la que consta la pràctica serà la següent:

<p align="center">
  <img alt="Il·lustració 1.Estructura general de la pràctica" src="https://github.com/Annabelesca/ED1819_Practica1_PIZARRO_LOPEZ/blob/master/Ilustracions/Ilustracio1.png">
</p>


## 2. La Pila
La pila és una estructura de dades que consta d’una base on s’emmagatzemen els elements. Aquests es van afegint un sobre l’altre (és a dir, es van apilant). Només és pot accedir a l’últim element que ha sigut apilat, que rep el nom de Cim. Aquesta estructura és de tipus LIFO (Last In, First Out).
El tipus d’implementació que farem servir en aquesta pràctica és sobre vector i només emmagatzemem enters a la pila. La nostra estructura, a més, emmagatzemarà (com enters) el nombre màxim de elements que pot contenir i el nombre dels elements que es troben emmagatzemats (que a més, marcarà la posició del Cim). Per tant, la nostra estructura segueix aquest model:

<p align="center">
  <img alt="Il·lustració 2. Representació Pila sobre vector" src="https://github.com/Annabelesca/ED1819_Practica1_PIZARRO_LOPEZ/blob/master/Ilustracions/Ilustracio2.png">
</p>


### 2.1	Cost d’emmagatzemament: 
Suposem que un enter ocupa un espai de 4Bytes.
La nostra estructura consta de 2 enters: El que determina la posició del cim dins l’estructura i el que determina quants elements com a màxim pot contenir l’estructura -> 8Bytes.
A més, també conté un vector d’enters -> MaxElems * 4Bytes.

<p align="center"><b>Cost espaial Pila = 8 Bytes + (MaxElems* 4Bytes)</b></p>

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



## 3. La Cua
La cua és una estructura de dades que consta d’una base on s’emmagatzemen els elements. Aquests es van afegint un darrere l’altre, però només es pot treballar sobre el primer element que s’hagi afegit a l’estructura, per tant, estem parlant d’una estructura de tipus FIFO (First In, First Out) també coneguda com FCFS (First Come, First Served).

El tipus d’implementació que farem servir en aquesta pràctica és sobre vector circular. D’aquesta manera, i com veurem més endavant, evitem que la funció d’esborrat tingui un cost Θ(n) i que se’ns dispari quan hagi molts elements.  Només emmagatzemem enters a la pila. La nostra estructura, a més, emmagatzemarà (com enters) el nombre màxim de elements que pot contenir, el nombre dels elements que es troben emmagatzemats, la posició del primer element de l’estructura i la posició de l’últim. Per tant, la nostra estructura segueix aquest model:

<p align="center">
  <img alt="Il·lustració 3. Representació Cua Circular" src="https://github.com/Annabelesca/ED1819_Practica1_PIZARRO_LOPEZ/blob/master/Ilustracions/Ilustracio3.png">
</p>


### 3.1	Cost d’emmagatzemament: 
Suposem que un enter ocupa un espai de 4Bytes.
La nostra estructura consta de 4 enters: El que determina la posició del primer element dins l’estructura, el que determina la posició de l’últim element dins l’estructura, el que indica quants elements hi ha emmagatzemats i el que determina quants elements com a màxim pot contenir l’estructura -> 16 Bytes.
A més, també conté un vector d’enters -> MaxElems * 4Bytes.

<p align="center"><b>Cost espaial Cua = 16 Bytes + (MaxElems * 4 Bytes)</b></p> 

### 3.2	Funcions disponibles i costos temporals de l’estructura Pila: 
Totes les funcions següents es troben definides al header “cua.h”.


#### Crear_Cua  
```java
Cua Crear_Cua(int max_elem); 
```
Constructor de l’estructura Cua. La funció crea una estructura de dades de Tipus Cua i inicialitza les seves variables (nombre d’elements màxims, nombre d’elements emmagatzemats, creació del vector base i inicialització dels cursors que apuntaran al primer i a l’últim element de la cua).

**Paràmetres:**
-	max_elem: nombre màxim d’elements que podrà contenir l’estructura. 

**Retorna:** 
-	Estructura de tipus Cua amb les variables inicialitzades i sense cap element emmagatzemat.

**Anàlisi del cost:   Θ(1)** -> Crear_Cua és una funció que només fa assignacions, per tant el seu cost serà constant.

#### Cap_Cua  
```java
int Cap_Cua(Cua C); 
```
Mètode de consulta que retorna el primer element (cap) que ha sigut inserit a l’estructura.

**Paràmetres:**
-	C: Cua de la qual es vol consultar el cap.

**Retorna:** 
-	Enter amb el valor del cap o imprimeix per pantalla un error si l’estructura d’on es vol obtenir el cap és buida.

**Anàlisi del cost:   Θ(1)** -> Cap_Cua és una funció que retorna el contingut d’una posició del vector (el cap) del qual es coneix l’índex, per tant el seu cost serà constant.


#### Encuar_Cua  
```java
Cua Encuar_Cua(Cua C, int E); 
```
Mètode de modificació de l’estructura que insereix l’element que es passa per paràmetre dins l’estructura (al final). Com és una estructura circular la primera acció a realitzar és marcar quina és la posició inicial i la última quan l’estructura és buida. Posteriorment s’afegeix l’element a la posició marcada per aquests cursors (que apunten a la posició 0). Si no era buida, es mou el cursor que apunta a l’últim element i s’introdueix l’element a la posició especificada. Finalment, s’incrementa el nombre d’elements de l’estructura en una unitat. 

**Paràmetres:**
-	C: Cua a la qual es vol inserir un nou element.
-	E: Enter què es vol inserir a l’estructura

**Retorna:** 
-	Estructura de tipus Cua amb el nou element inserit o imprimeix per pantalla un error si l’estructura on es vol inserir un nou element és plena.
-	
**Anàlisi del cost:   Θ(1)** -> Encuar_Cua és una funció que fa una assignació i una suma, per tant el seu cost serà constant.

#### Desencuar_Cua  
```java
Cua Desencuar_Cua(Cua C); 
```
Mètode de modificació de l’estructura que elimina el primer element inserit a l’estructura. Per a fer-ho, es mou el cursor a la següent posició (tenint en compte que és una cua circular) i es decrementa el nombre d’elements. 

**Paràmetres:**
-	C: Cua de la qual es vol esborrar el cap.

**Retorna:** 
-	Estructura de tipus Cua amb un nou cap o imprimeix per pantalla un error si l’estructura d’on es vol esborrar l’element és buida.
-	
**Anàlisi del cost:   Θ(1)** -> Desencuar_Cua és una funció que fa una assignació i una resta, per tant el seu cost serà constant.

#### EsBuida_Cua  
```java
int EsBuida_Cua(Cua C); 
```
Mètode de consulta que comprova si l’estructura no conté cap element comparant el nombre d’elements emmagatzemats a l’estructura amb 0.

**Paràmetres:**
-	C: Cua la qual es vol comprovar si és buida.
	
**Retorna:** 
-	1 si l’estructura és buida, 0 altrament.
	
**Anàlisi del cost:   Θ(1)** -> EsBuida_Cua és una funció que fa una comparació, per tant el seu cost serà constant.

#### EsPlena_Cua  
```java
int EsPlena_Cua(Cua C); 
```
Mètode de consulta que comprova si l’estructura conté el nombre màxim d’elements comparant el nombre d’elements emmagatzemats a l’estructura amb el nombre màxim d’elements que es poden emmagatzemar.

**Paràmetres:**
-	C: Cua la qual es vol comprovar si és plena.
	
**Retorna:** 
-	1 si l’estructura és plena, 0 altrament.
	
**Anàlisi del cost:   Θ(1)** -> EsPlena_Cua és una funció que fa una comparació, per tant el seu cost serà constant.

#### Destruir_Cua  
```java
void Destruir_Cua(Cua C); 
```

Mètode que allibera l’espai reservat per el vector que conté els enters

**Paràmetres:**
-	C: Cua de la qual es vol alliberar l’espai.

**Anàlisi del cost:   Θ(1)** -> Es crida una funció de la llibreria stdlib.h anomenada free() que el que fa és desassignar una regió de memòria de la qual es coneix la direcció, per tant té un cost constant.

#### missatgeError_Cua   
```java
void missatgeError_Cua(int i);
```

Mètode que s’encarrega d’imprimir per pantalla els errors que es produeixen en les diferents funcions de l’estructura en funció de l’índex que se li passa per paràmetre.  

**Paràmetres:**
-	i: Enter que representa el tipus d’error que s’ha produït. Si i=0, es printejarà un error de cua buida. Si i=1, es printejarà un error de cua plena. 

**Anàlisi del cost:   Θ(1)** -> Només es fa un switch i es printeja, per tant, el cost és constant.


## 4. La Llista
La cua és una estructura de dades on es pot afegir elements a qualsevol posició. El tipus d’implementació que farem servir en aquesta pràctica és amb gestió dinàmica. 

La nostra llista es correspondrà a un punter que farà referència al primer element de la llista i a l’element anterior al punt d’interès. Això és degut a què, com els elements només tenen un encadenament cap endavant, quan volguéssim introduir un element davant del punt d’interès no tindríem cap manera d’enllaçar aquest nou amb els elements que precedeixen el PDI. És per això que no es referencia el PDI, sinó l’anterior a aquest. 

Què passa si aquest PDI apunta al primer element de la llista? L’anterior no estaria apuntant a cap element de la llista. Per solucionar aquest inconvenient, es crea l’element fantasma, que és un element que es situa a l’inici de la llista i que no tindrà valor. Només estarà perquè l’anterior al PDI pugui apuntar dins la llista. 

La nostra llista no serà d’enters, sinó que serà d’un registre anomenat “Node”. El node contindrà un enter, que serà la informació que ens interessarà emmagatzemar i un encadenament que serà un punter al següent node. La llista com a estructura contindrà un punter al primer element de la llista (a l’element fantasma) i un altre punter al anterior al PDI. La representació d’aquesta estructura seria la següent: 

<p align="center">
  <img alt="Il·lustració 4. Representació Llista amb PDI i element fantasma" src="https://github.com/Annabelesca/ED1819_Practica1_PIZARRO_LOPEZ/blob/master/Ilustracions/Ilustracio4.png">
</p>


### 4.1	Cost d’emmagatzemament: 
Suposem que un enter ocupa un espai de 4Bytes i un punter ocupa un espai de 4Bytes també.
Dividim l’estructura en dos parts:

- Node: Consta d’un enter i un punter al següent node -> 8Bytes.
- Llista: Consta de dos punters -> 8Bytes.

<p align="center"><b>Cost espaial Llista = 8 Bytes + (MaxElems * mida(Node))= 8 Bytes + (MaxElems*8Bytes)</b></p> 

### 4.2	Funcions disponibles i costos temporals de l’estructura Pila: 
Totes les funcions següents es troben definides al header “llista.h”.

#### Crear_Llista 
```java
Llista Crear_Llista(); 
```
Constructor de l’estructura Llista. La funció crea una estructura de dades de Tipus Llista i inicialitza les seves variables creant un punter i s’assegura que hagi suficient espai per crear la llista. Un cop creada, fa que els punters primer i anterior referenciïn aquest node. Per finalitzar, fa que l’encadenament d’aquest node apunti a NULL.

**Retorna:** 
- Estructura de tipus Llista amb l’element fantasma.
- 
**Anàlisi del cost:   Θ(1)** -> Crear_Llista és una funció que només fa assignacions, per tant el seu cost serà constant.


#### Inserir_Llista   
```java
Llista Inserir_Llista(Llista L, int E); 
```
Mètode de modificació de l’estructura que insereix l’element passat per paràmetre davant del PDI. Per fer això, s’intenta crear el nou node. Al qual se li assigna el enter que s’ha passat per paràmetre i es fa que aquest apunti al PDI. Com el que es té a la llista és la referència al node anterior, s’utilitza aquesta referència per obtenir el PDI i poder fer que el nou node pugui apuntar-lo. Desprès es canvia l’encadenament de l’anterior i passa a apuntar el nou node. Finalment fem que anterior apunti al nou node creat. 

**Paràmetres:**
- L: Llista a la qual es vol inserir l’element.
- E: Enter que es vol inserir a la llista.
	
**Retorna:** 
- Estructura de tipus Llista amb el nou element i amb anterior apuntant al nou node o un error si no s’ha pogut crear el node corresponent.	

**Anàlisi del cost:   Θ(1)** -> Inserir_Llista és una funció que només fa assignacions, per tant el seu cost serà constant.

<p align="center">
  <img alt="Il·lustració 5. Representació de la funció inserir" src="https://github.com/Annabelesca/ED1819_Practica1_PIZARRO_LOPEZ/blob/master/Ilustracions/Ilustracio5.png">
</p>

#### Esborrar_Llista   
```java
Llista Esborrar_Llista(Llista L); 
```
Mètode de modificació de l’estructura que esborra l’element referenciat pel PDI i mou el PDI a la següent posició. Per aconseguir-ho el que es fa és obtenir la referència al PDI a partir de l’encadenament de l’anterior i fer que l’encadenament del anterior sigui l’encadenament del PDI. Per finalitzar, alliberem l’espai del node del PDI.  

**Paràmetres:**
- L: Llista de la qual es vol esborrar l’element.
	
**Retorna:** 
- Estructura de tipus Llista sense aquest node i amb un nou PDI (el següent element) o error si la llista era buida o el PDI es troba a la dreta del tot.

**Anàlisi del cost:   Θ(1)** -> Esborrar_Llista és una funció que només fa assignacions, per tant el seu cost serà constant.

<p align="center">
  <img alt="Il·lustració 6. Representació de la funció esborrar" src="https://github.com/Annabelesca/ED1819_Practica1_PIZARRO_LOPEZ/blob/master/Ilustracions/Ilustracio6.png">
</p>


#### Actual_Llista   
```java
int Actual_Llista(Llista L); 
```
Mètode de consulta que retorna l’element referenciat pel PDI. 

**Paràmetres:**
- L: Llista de la qual es vol obtenir l’element referenciat pel PDI.
	
**Retorna:** 
- Enter amb el valor del node PDI o error si PDI es troba a la dreta.

**Anàlisi del cost:   Θ(1)** -> Actual_Llista és una funció que només fa assignacions, per tant el seu cost serà constant.

#### EsBuida_Llista    
```java
int EsBuida_Llista(Llista L); 
```
Mètode de consulta que comprova si l’estructura és buida comprovant si l’encadenament del primer element (l’element fantasma) és una referència a NULL. 

**Paràmetres:**
- L: Llista la qual es vol comprovar si és buida.
	
**Retorna:** 
- 1 si l’estructura és buida, 0 altrament.

**Anàlisi del cost:   Θ(1)** -> EsBuida_Llista és una funció que només fa una comparació, per tant, el seu cost serà constant.

#### Principi_Llista    
```java
Llista Principi_Llista(Llista L); 
```
Mètode per moure el PDI a l’inici de la llista. Iguala el punter a l’anterior a la referència del primer.

**Paràmetres:**
- L: Llista de la qual es vol moure el PDI a l’inici.
	
**Retorna:** 
- Estructura de tipus Llista amb el PDI apuntant al primer element.

**Anàlisi del cost:   Θ(1)** -> Principi_Llista és una funció que només fa una assignació, per tant, el seu cost serà constant.

#### Seguent_Llista    
```java
Llista Seguent_Llista(Llista L); 
```
Mètode per moure el PDI una posició a la dreta. El que es fa és que l’anterior apunti al seu encadenament.

**Paràmetres:**
- L: Llista de la qual es vol moure el PDI.
	
**Retorna:** 
- Estructura de tipus Llista amb el PDI apuntant al següent element o error si el PDI es troba a la dreta del tot.

**Anàlisi del cost:   Θ(1)** -> Seguent_Llista és una funció que només fa una assignació, per tant, el seu cost serà constant.

#### EsFinal_Llista    
```java
int EsFinal_Llista(Llista L); 
```
Mètode per comprovar si el PDI es troba a la dreta del tot comprovant si l’encadenament del node anterior és igual a Null.

**Paràmetres:**
- L: Llista de la qual es vol comprovar si el PDI es troba a la dreta del tot.
	
**Retorna:** 
- 1 si PDI es troba a la dreta del tot, 0 altrament.

**Anàlisi del cost:   Θ(1)** -> EsFinal_Llista és una funció que només fa una assignació, per tant, el seu cost serà constant.

#### Fusiona_Llista    
```java
Llista Fusiona_Llista(Llista L1, Llista2); 
```
Mètode per concatenar dues llistes. El que es fa és buscar l’últim node de la primera llista i concatenar-lo amb el primer node de la segona llista, tenint en compte que cal evitar concatenar-lo amb l’element fantasma de la segona llista. 

**Paràmetres:**
- L: Llista de la qual es vol comprovar si el PDI es troba a la dreta del tot.
	
**Retorna:** 
- Estructura de tipus llista que conté els elements de les dues llistes concatenades. El PDI de la qual pertanyerà a la primera llista.

**Anàlisi del cost:   Θ(n)** -> Fusiona_Llista és una funció que ha de recórrer tots els nodes de la primera llista fins trobar l’últim, que acabarà concatenant-se amb el primer element de la segona llista.

#### Print_Llista    
```java
void Print_Llista(Llista L); 
```

Mètode per printejar per pantalla el contingut de la llista que s’ha passat per referència sense modificar el seu PDI. Mostrarà els elements separats per el camp ‘->’

**Paràmetres:**
- L: Llista que es vol printejar.

**Anàlisi del cost:   Θ(n)** -> Print_Llista és una funció que ha de recórrer tots els nodes de la llista fins trobar l’últim i anar printejant el valor dels nodes.


### 4.3	Discussió costos lineals de les funcions Fusiona i Print:
Aquestes dues funcions, a diferència de la resta, tenen un cost temporal lineal que va lligat a la quantitat d’elements que formen part de l’estructura. En alguns casos, si el nombre d’elements és molt gran, aquest cost podria arribar a ser prohibitiu. En el cas de la funció de printejar aquest cost no es pot evitar de cap manera ja que s’ha de recórrer si o si l’estructura. En canvi, a la funció de fusionar llista es podria evitar si afegíssim un nou punter a l’estructura que referenciés l’últim element. A canvi de 4Bytes, obtindríem un cost constant a l’hora de fusionar les dues llistes ja que només faria falta una assignació. Aquesta millora seria més significativa entre més elements contingués l’estructura. 
