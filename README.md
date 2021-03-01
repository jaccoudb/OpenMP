# OpenMP
Diretório destinado aos códigos de estudo de programação paralela em C++

Os exemplos que estão sendo mostrados nesse diretório são parte de um estudo para aplicações de paralelização de códigos futuros. Aqui são apresentados algumas ferramentas da biblioteca OpenMP.

* main_0.cpp
> Imprime _Thread_ e o _id_ da thread na tela para cada core.
* main_1.cpp
> Gera dois vetores A e B, sendo B resultado de uma operação através dos componentes do vetor A.
* main_2.cpp
> Imprime _Thread_ e o _id_ da thread na tela para cada core, utilizando condicional da biblioteca OpenMP e diretrizes _num_threads_, _private_ e _shared_.
* main_3.cpp
> Altera valores dentro da região paralela, que podem ou não ser alterados dentro dessas regiões.
* main_4.cpp
> Imprime valores de Máximo e Mínimo, utilizando regiões paralelas.
* main_5.cpp
> Imprime média dos elementos dos vetores, além dos múltiplos de 3, utilizando regiões paralelas.
* main_6.cpp
> Imprime média aritmética dos elementos de duas matrizes, avaliando se da matriz A é maior, menor ou igual que da matriz B, utilizando cópias locais "reduzidas" pela diretiva reduction.
