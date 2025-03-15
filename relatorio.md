### Depedencias

$ sudo apt-get install check

```make``` para buildar a aplicação\
```make run``` para executar a aplicação\
```make test``` para executar os teste unitários\

### GitFlow - Estratégia de branching

#### Branching
O repositório será divido em 2 branches principais.
- Main: código versionado para realeases.
- Dev: código em fase de desenvolvimento.

Para alguma nova criação de funcionalidade deverá ser criada uma nova branch a partir do Dev com prefixo feature/ no nome, Ex: feature/funcionalidade, o que faŕa o merge para a branch Dev..\
Para alguma correção de bug presente em produção, deve-se criar uma nova branch a partir do Main com prefixo hotfix/ no nome, Ex: hotfix/funcionalidade, o que deve ser feito merge na main e na dev posteriormente.\
Para release, é criado uma nova branch a partir do dev com prefixo release com o número da versão, Ex release/1.0.0, e desse branch faz apenas as correções das features/bugs que estão presente nessa branc e assim feito merge para Main e também Dev.

Mais info no:
https://www.alura.com.br/artigos/git-flow-o-que-e-como-quando-utilizar?srsltid=AfmBOopstJCwgYAND855bTLVjTVd3yjaH041YOyjroKgL8kMGGM7xBRb

#### Commit

Adotar alguma convenção de commit (ex.: feat: ..., fix: ..., docs: ...) e versionar com tags (v1.0.0, v1.1.0, etc.) na medida que o projeto for evoluindo.

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
./test/check_cart e toda o pullRequest deve ser verificado e testado por um outro desenvolvedor.

### Forma de versionamento adotada
Depois de determinado conjuntos de novas features e bugs, é estabilizado um commit na branch DEV e feito um merge para a main,
gerando então uma TAG daquele commit, posteriormente é gerado um realise no GitHub, citando as alterações e adições, e também
disponibilizando os executáveis, além do link da imagem do dockerFile. 

### Sujestões Professor

Link Projeto SCM: \
https://gist.github.com/leopoldomt/4d1bdb8e489b47a897b8bf6d0346c31f 

show cart\
remover itens do carrinho\
efetivar venda (Limpa o carrinho e mexe nas quantidades)\
desistir da compra - libera o carrinho mas nao meche nas quantidades\
fechamento do caixa - registrando as venda e listar as veendas do  dia \
incrementar outras funcionalidades\
gerar relatorio e arquivo txt de fechamento do caixa


### Lições Aprendidas

#### André Roetger
* Achei muito interessante o gerenciamento de tarefas disponível no Projects do GitHub. Além disso, o próprio gerenciamento de issues oferece diversas funcionalidades úteis para o desenvolvimento do projeto.
* Eu desconhecia a ferramenta Actions do GitHub e achei extremamente interessante aprender a utilizá-la. Fiquei impressionado com o quão poderosa ela é, especialmente para o controle de testes, automação de processos e envio de notificações por e-mail para os responsáveis.
* Um dos desafios enfrentados pelo time foi a falta de um líder responsável por definir o escopo do projeto e designar as tarefas entre os membros.
* Tivemos que realizar algumas reuniões para alinhar decisões importantes. Apesar de a seção de issues permitir comentários, sentimos falta de um ambiente de chat instantâneo para facilitar a comunicação em tempo real.

#### Dennis Paulino Irineu

#### Fábio Marques Henrique

#### Terence Myren Kutzner
