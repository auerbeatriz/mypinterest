# [Trabalho 2] My Pinterest | Beatriz Auer e Mateus Maioli

**Alunos**: Beatriz Auer Mariano e Mateus Maioli Giacomin<br>
**Disciplina**: Estrutura de Dados<br>
**Professor**: Thiago Meireles Paixão<br>
**Semestre**: 2023/1 - 3º período<br>

## Introdução

O objetivo do trabalho é desenvolver um projeto em C que faça a recuperação de imagens correlacionadas a uma imagem de entrada, baseada em seu conteúdo (*Content-based Image Retrieval*, CBIR). Para isso, utilizou-se a técnica histogramas para realizar a extração de descritores de cada imagem. A extração de conteúdo baseado em histograma consiste na representação da frequência que um determinado valor ocorre: nesse caso, a frequência que um valor de cor de pixel é repetido na matriz de pixels de uma imagem.<br>
Nesse trabalho, utilizou-se imagens no formato PGM em escala de cinza (valores de pixel de 0 a 255).

[!WARNING] Falar mais sobre o trabalho em si

**Conteúdos relacionados:** implementação de TADs e listas encadeadas.

## Base de dados

Foram selecionados 10 ambientes do Ifes Campus Serra para representar a nossa base de dados. Cada localidade possui 10 fotos.

[!WARNING] para cada nova localidade que não são as de origem do trabalho que for adicionada, é preciso criar as pastas correspondentes e adicionar as imagens PGM, pois o programa não faz isso sozinho.

As imagen estão armazenas dentro de `base/pgm/` e divididas por localidade. O diretório base possui, ainda, uma subpasta `histogram_extractor`. A pasta histogram_extractor possui um arquivo `index` que correlaciona o caminho de cada imagem de cada localidade ao seu respectivo descritor e várias outras subspastas, uma para cada localidade, que possuem os arquivos com os descritores das imagens, em si. Dentro de base há um arquivo `convert_to_pgm.py`, que foi adaptado do código dado pelo professor para converter as imagens de `base/img/` em pgm.


[!NOTE] a estrutura de pastas foi adaptada da documentação para melhor atender à nossa implementação (e também para ser melhor da gente entender).

![Estrutura do diretório base](doc/base.png)

## Estruturas

Todas as estruturas abaixo foram implementadas utilizando o conceito de TADs.

> TAD: Tipo Abstrato de Dados.<br>
Consiste na abstração de uma estrutura de dados que define um conjunto de operações permitidas em seus objetos, ocultando os detalhes de implementação e fornecendo uma interface clara para manipular e acessar os dados.<br>
As estruturas foram implementadas, portanto, utilizando um cabeçalho **.h** e implementação **.c**.

### List

Lista encadeada genérica. Nesse tipo de estrutura de dados, cada elemento de uma lista, chamado de **nó** possui um ponteiro de referência para o próximo nó da lista. Nesse caso, como a lista é genérica, o nó pode ser um ponteiro para qualquer tipo, como Locality, Image, char, int, etc.

### Locality

Estrutura que armazena todas as imagens de uma determinada localidade, em forma de uma lista encadeada. Possui dois atributos: name, nome da localidade, e images, que é a lista de imagens do local.

[!NOTE] As localidades selecionadas estão armazenadas em uma lista encadeada do tipo Locality. Cada Locality, por sua vez, tem sua própria lista encadeada como "atributo" que armazena as imagens do tipo Image.

### Image

Image: estrutura que armazena o conteudo das imagens PGM, como altura, largura, nível máximo de cinza e a matriz dos pixels da imagem. A matriz de pixels da imagem consiste em um vetor de vetores do tipo *unsigned char*.

## Fluxo
1. Inicializa as localidades do banco de dados, que são listadas no arquivo localities.txt. As localidades são carregadas par dentro da List localities.
2. Lê as imagens de cada localidade, armazena nas listas respectivas de cada localidade e extrai e armazena os descritores de cada imagem.