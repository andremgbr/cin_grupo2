### Depedencias

FrameWork de test em C
```Bash
$ sudo apt-get install check
```

### GitFlow - Estratégia de branching

#### Branching
O repositório será divido em 2 branches principais.
- Main: código versionado para realeases.
- Dev: código em fase de desenvolvimento.

Para alguma nova criação de funcionalidade deverá ser criada uma nova branch a partir do Dev com prefixo feature/ no nome, Ex: feature/funcionalidade, o que faŕa o merge para a branch Dev..\
Para alguma correção de bug presente em produção, deve-se criar uma nova branch a partir do Main com prefixo hotfix/ no nome, Ex: hotfix/funcionalidade, o que deve ser feito merge na main e na dev posteriormente.\
Para release, será escolhido um commit estável na branch DEV e será feito o merge para main.

Mais info no:
https://www.alura.com.br/artigos/git-flow-o-que-e-como-quando-utilizar?srsltid=AfmBOopstJCwgYAND855bTLVjTVd3yjaH041YOyjroKgL8kMGGM7xBRb

#### Commit e Tags

Adotar alguma convenção de commit (ex.: feat: ..., fix: ..., docs: ...) e versionar com tags (v1.0, v1.1, etc.) na medida que o projeto for evoluindo.\

### Procedimento de build e CI/CD

#### Build
A metodolia de build utilizada foi o programa make. Basta estar com o terminal na pasta raiz do projeto e executar o seguintes
comandos:

```make``` para buildar a aplicação\
```make run``` para executar a aplicação\
```make test``` para executar os teste unitários\

#### GitActions

Foi criada uma GitActions para CI/CD, nele está configurada uma ação que, a cada merge para a branch DEV e para a branch MAIN, é
realizada o ```make``` para verificar se o códigos é compilado corretamente e também realiza o ```make test``` verificando se todos os testes
unitários.

### Estrutura e política de testes

#### Estrutura
O projeto foi definido que tenha a seguinte árvore:
```
.
|-- bin
|   `-- mercado
|-- inc
|   `-- mercado.h
|-- obj
|   |-- mercado.o
|   `-- run.o
|-- src
|   |-- mercado.c
|   `-- run.c
|-- test
|   |-- bin
|   |   `-- teste
|   |-- obj
|   |   |-- check_chart.o
|   |   `-- mercado.o
|   |-- check_chart.c
|   `-- Makefile
|-- Makefile
|-- README.md
`-- relatorio.md
```

* `inc/mercado.h`: Contém a definição da estrutura `Product` e os protótipos das funções.
* `src/mercado.c`: Implementa as funções de manipulação do carrinho de compras.
* `src/run.c`: Contém a função `main` e a lógica principal do programa.
* `bin/`: Diretório para os executáveis.
* `obj/`: Diretório para os arquivos objeto.
* `test/`: Diretório que contem a execução e os arquivos do teste unitário. 
* `Makefile`: Arquivo para compilação do projeto.
* `README.md`: Este arquivo com a descrição do projeto.


#### Politica de testes
Cada Desenvolvedor fica responsável por testar o seu desenvolvimento de aplicação e se necessário, criar um test unitário  da nova aplicação dentro do
./test/check_cart e toda o pullRequest deve ser verificado e testado por um outro desenvolvedor. Além disso, o próŕio GitAction também executará o teste a cada PR e Push na branch DEV e na branch MAIN.

### Forma de versionamento adotada
Depois de determinado conjuntos de novas features e bugs, é estabilizado um commit na branch DEV e feito um merge para a main,
gerando então uma TAG daquele commit, posteriormente é gerado um realise no GitHub, citando as alterações e adições, e também
disponibilizando os executáveis, além do link da imagem do dockerFile. 

### Lições Aprendidas

#### André Roetger
* Achei muito interessante o gerenciamento de tarefas disponível no Projects do GitHub. Além disso, o próprio gerenciamento de issues oferece diversas funcionalidades úteis para o desenvolvimento do projeto.
* Eu desconhecia a ferramenta Actions do GitHub e achei extremamente interessante aprender a utilizá-la. Fiquei impressionado com o quão poderosa ela é, especialmente para o controle de testes, automação de processos e envio de notificações por e-mail para os responsáveis.
* Um dos desafios enfrentados pelo time foi a falta de um líder responsável por definir o escopo do projeto e designar as tarefas entre os membros.
* Tivemos que realizar algumas reuniões para alinhar decisões importantes. Apesar de a seção de issues permitir comentários, sentimos falta de um ambiente de chat instantâneo para facilitar a comunicação em tempo real.

#### Dennis Paulino Irineu

#### Fábio Marques Henrique

#### Terence Myren Kutzner
Para mim foi o primeiro contato que tive com o Git/Github - tive um pouco de dificuldade para me familiarizar com os comandos e padrões para criar branch e commits. Com o passar do projeto, fui me familiarizando e cometendo menos erros ao fazer commits, reviews, criação de branch. 
Uma outra dificuldade que senti no inicio foi fazer correções de nomes de branch por erros de digitação (acredito que pela pouca familiaridade com a ferramenta). No geral pode-se destacar algumas: 
- A importância de seguir um padrão de nomenclatura para branches e commits, o que facilita a organização e entendimento do histórico do projeto. Nesse questito, como todos estavam aprendendo é possível ver claramente a diferença dos commits do inicio do projeto para o fim dele. 
- Além disso, percebi o quanto os commits pequenos e frequentes ajudam na rastreabilidade das mudanças e tornam o processo de revisão mais facil.
- Além disso, importante ter comunicação clara com o time, especialmente ao lidar com conflitos de merge. Nesse quesitos as reuniões realizadas com os integrantes ajudou bastante.






