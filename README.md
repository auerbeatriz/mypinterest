# [Trabalho 2] My Pinterest

**Alunos**: Beatriz Auer Mariano e Mateus Maioli Giacomin

**Disciplina**: Estrutura de Dados

**Professor**: Thiago Meireles Paixão

**Semestre**: 2023/1 - 3º período

## Introdução

O objetivo do trabalho é desenvolver um projeto em C que faça a recuperação de imagens correlacionadas a uma imagem de entrada, baseada em seu conteúdo (*Content-based Image Retrieval*, CBIR).

**Conteúdos relacionados:** implementação de TADs e listas encadeadas.

## Base de dados

## Estruturas
List: lista duplamente encadeada, conforme conceitos estudados em sala de aula (listar os conceitos aqui!!, com imagens e tudo o mais)

Locality: estrutura que armazena todas as imagens de uma determinada localidade, em forma de uma lista duplamente encadeada. Possui dois atributos: name, nome da localidade, e images, que é a lista de imagens do local

Image: estrutura que armazena o conteudo das imagens PGM, como altura, largura, nível máximo de cinza e a matriz dos pixels da imagem.

## Fluxo
1. Inicializa as localidades do banco de dados, que são listadas no arquivo localities.txt
2. 