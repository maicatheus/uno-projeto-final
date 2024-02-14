# Trabalho Final: UNO

Esse projeto busca exercitar o uso das estruturas de dados da linguagem C estudadas ao longo do semestre na disciplina de Estruturas de Dados, através da implementação do jogo UNO em um programa de computador.

## Autores

- Lucas Oliveira
- Matheus Maica

## Descrição do jogo UNO

O jogo UNO consiste em um baralho de quatro cores (verde, amarelo, azul e vermelho), cada cor contendo cartas de valores que variam de 0 a 9 (as cores possuem um par de cartas de mesmo valor, com exceção do 0, que é um por cor). Além disso, cada cor também possui um par de cartas de "Pular", "Inverter" e "Compra Duas". Por fim, o baralho ainda possui dois tipos de cartas "coringa": as cartas "Muda Cor" e "Compra Quatro", sendo quatro cartas de cada tipo. Assim, o baralho de UNO totaliza 108 cartas.

O jogo deve ser jogado por maiores de 10 anos, e o número de participantes varia de 2 a 10 pessoas. Cada jogador recebe sete cartas do baralho, e, após a distrubuição, a carta do topo do baralho é posta na mesa, dando início ao jogo. A jogada é feita de três maneiras: cada jogador deve jogar uma carta de mesmo número (ou símbolo) que a do topo da pilha da mesa, de mesma cor mas número/símbolo diferente, ou uma idêntica (mesma cor e número/símbolo). Caso o jogador não tenha nenhnuma carta para jogar, deverá então comprar da pilha até que uma jogada seja possível. Caso a pilha de cartas para comprar acabe, a primeira carta da pilha é separada das demais do monte de descarte, que então é embaralhado e posto como a nova pilha de cartas para comprar.

Quando um jogador fica com apenas uma carta na mão, este deve gritar "Uno!". Caso contrário, um dos outros jogadores pode acusá-lo de não ter dito, e ele então deverá comprar cinco cartas do monte.

Vence a partida o jogador que conseguir ficar com a mão vazia. Quando isso acontece, os demais jogadores revelam as cartas da mão, e é feita uma contagem dos pontos para o vencedor da rodada.  Vence o jogo o jogador que somar 500 pontos (ou o que tiver mais pontos).

Critérios de pontuação:

- Cartas de 0 a 9 tem o valor da sua face;
- Pular, Inverter e Compra Duas somam 20 pontos cada;
- Muda Cor e Compra Quatro valem 50 pontos. 

## Descrição do projeto

### Estruturas

Para a implementação do jogo, foram utilizadas diferentes estruturas estudadas ao longo do semestre:

- Baralho e Descarte: para esses dois itens foram utilizados os conceitos de Pilha Encadeada, já que, para o Baralho, era necessário apenas retirar cartas do topo e, para o Descarte, apenas adicioná-las no topo;

- Lista de Jogadores: para criar a lista de jogadores (e por consequência a ordem das jogadas na rodada), foram usados conceitos de Listas Circulares, já que, para cada rodada, cada jogador deve jogar uma vez, até voltar para o jogador que iniciou a rodada, criando uma noção de ciclo. Além disso, quando as cartas de Inverter são jogadas, é necessário inverter a ordem dos jogadores, sem alterar a estrutura. Essa lista recebe elementos do tipo Jogador;

- Jogadores: cada jogador é representado por uma estrutura do tipo Jogador, que contém um vetor de caracteres "nome", uma estrutua Lista Encadeada que representa a mão do jogador, uma variável "int" que determina se o jogador disse Uno quando ficar com apenas uma carta na mão, e dois ponteiros do mesmo tipo, que indicam o próximo jogador e o anterior;

- Mão do jogador: a lista de cartas da mão de cada jogador é preenchida com estruturas do tipo NodoBaralho, que contém estruturas do tipo Carta, e uma variável "int" que armazena o número de cartas nessa lista;

- Cartas: cada carta é representada por uma estrutura Carta, que possui três informações: Cor, que armazena as quatro cores, ValoresCor, que armazena os números de 0 a 9, Pula, Inverter e Compra Duas, e Especiais, que armazena Muda Cor e Compra Quatro;

- Status da jogada: essa estrutura foi criada com o objetivo de "controlar a jogada" que um jogador faz. Possui quatro variáveis do tipo "int", jogadaPermitida, jogadaEspecial, jogadaSacana e gameOver, que analisam a jogada feita pelo jogador de acordo com a carta escolhida; e uma estrutura do tipo Carta.

### Funções

Além das funções aprendidas e desenvolvidas ao longo do semestre, nas aulas e em atividades práticas semanais, outras funções foram criadas para facilitar o funcionamento do programa, como funções para comprar cartas, jogar uma carta, validar a jogada feita, embaralhar o baralho, entre outras; e outras para facilitar o entendimento do programa, como funções para mostrar a carta da mesa, mostrar as cartas dos jogadores, para colocar cor das cartas na tela, entre outras, o que permite um entendimento melhor do que está acontecendo.

Como são muitas as funções para colocar nesse documento, é mais prático analisá-las no código, já que foram nomeadas com nomes autoexplicativos.
