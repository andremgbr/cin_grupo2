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
Para alguma correção de bug presente em produção, deve-se criar uma nova branch a partir do Main com prefixo hotfix/ ou fix/ no nome, Ex: hotfix/funcionalidade, o que deve ser feito merge na main e na dev posteriormente.\
Para release, será escolhido um commit estável na branch DEV e será feito o merge para main.

#### Commit e Tags

Para realização de commits foi utilizada a seguinte estrutura de prefixos para os cometários do commit:
- Feat: indica uma featura adicionada;
- Fix: indica a correção de um Bug;
- Doc: Indica tudo que é ligado a documentação

Vale destacar que devido a inexperiência de trabalho com projeto no github, houveram algumas vezes falhas a adesão desse padrão. Entretando, buscou-se ao máximo fazer com que essas normas fossem seguidas


Depois de determinado conjuntos de novas features e bugs, é estabilizado um commit na branch DEV e feito um merge para a main, gerando então uma TAG daquele commit, posteriormente é gerado um realise no GitHub, citando as alterações e adições, e também disponibilizando os executáveis, além do link da imagem do dockerFile. Para as Tags foi utilizado o seuinte padrão para identificar posteriormente as releases:

- Sempre que o programa adicionava alguma Feature nova utilizava se o padrão X.0 (Ex.: V1.0, 2.0)
- Sempre que o programa corrigia algum bug em uma release ja existente utilizava se o padrão 1.X (Ex.: V1.1, V1.2)

### Procedimento de build e CI/CD

#### Build
A metodolia de build utilizada foi o programa make. Basta estar com o terminal na pasta raiz do projeto e executar o seguintes
comandos:

```make``` para buildar a aplicação\
```make run``` para executar a aplicação\
```make test``` para executar os teste unitários\

#### GitActions

Foi criada uma GitActions para CI/CD, nele está configurada uma ação que, a cada merge para a branch DEV e para a branch MAIN, é realizada o ```make``` para verificar se o códigos é compilado corretamente e também realiza o ```make test``` verificando se todos os testes unitários.

### Estrutura e política de testes

Forma implementados testes unitários para o programa. Cada desenvolvedor ficou responsável por testar sua própria implementação e, se necessário, criar testes adicionais dentro do diretório ./test/check_cart. Além disso, todo pull request passa por uma revisão e testes realizados por outro desenvolvedor. O GitHub Actions, como menccionado anteriomente, também executa automaticamente os testes a cada Pull Request e push nas branches DEV e MAIN.

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
Para o programa foram cirados os testes unitários.Cada Desenvolvedor fica responsável por testar o seu desenvolvimento de aplicação e se necessário, criar um test unitário  da nova aplicação dentro do
./test/check_cart e toda o pullRequest deve ser verificado e testado por um outro desenvolvedor. Além disso, o próŕio GitAction também executará o teste a cada PR e Push na branch DEV e na branch MAIN.

#### Gerenciamento de Projeto

O gerenciamento de atividades foi feita pelo próprio GitHub project.

Nele as atividades se davam a partir da criação de issues. Nessas issues eram apresentados:

- Sugestões de Melhorias
- Correções de Bugs

 Essas issues recebiam labels (enhancement, bug, documentation), eram associadas a um projetos e designado a um responsável. Geralmente, o próprio criador da issue atribuia esses elementos. Aqui vale destacar que devido no início do projeto o time não possio tanta familiaridade com esses elementos, entretanto isso foi aperfeiçoado ao decorrer do projeto. Dessa forma nas issues finais o time ja estava entendendo como atribuir essas issues e identificá-las. No contexto do nosso projeto, seguimos um fluxo típico para o tratamento de bugs, que pode ser descrito da seguinte forma:

- Identificação e Relato: Quando um bug é encontrado, ele é documentado como uma issue, detalhando o problema identificado.
- Atribuição da Correção: Após a criação da issue atribuia-se a issue a algum integrante. No nosso caso, quem abrisse a issue ja atribuia a um responsável.
- Correção: A pessoa designada trabalha na correção, aplicando um fix no código.
- Testes: Após a correção, são feitos testes para garantir que a solução funciona corretamente e não gera novos problemas.
- Lançamento: A correção fix é incluída na seguinte release do projeto.

No caso específico do nosso projeto foram deixados alguns bugs intencionais para exercitar essa questão.
 
### Reflexões e Lições Aprendidas

#### André Roetger
* Achei muito interessante o gerenciamento de tarefas disponível no Projects do GitHub. Além disso, o próprio gerenciamento de issues oferece diversas funcionalidades úteis para o desenvolvimento do projeto.
* Eu desconhecia a ferramenta Actions do GitHub e achei extremamente interessante aprender a utilizá-la. Fiquei impressionado com o quão poderosa ela é, especialmente para o controle de testes, automação de processos e envio de notificações por e-mail para os responsáveis.
* Um dos desafios enfrentados pelo time foi a falta de um líder responsável por definir o escopo do projeto e designar as tarefas entre os membros.
* Tivemos que realizar algumas reuniões para alinhar decisões importantes. Apesar de a seção de issues permitir comentários, sentimos falta de um ambiente de chat instantâneo para facilitar a comunicação em tempo real.

#### Dennis Paulino Irineu
* De fato o Github mostou-se ser indispensável para a realização de projetos (sejam eles grandes ou pequenos), já que ele dispões de tantas funcionalidades auxiliadoras. A possibilidade de exergar o história de commits e até a possibilidade de fazer um rollback são apenas alguns dessa facilidade que o git trás ao desenvolvedor. 
* A questão de pedir uma review de outro programador é muito benéfico, já que é um olhar de fora olhando seu código, além de diminuir a possibilidade de você acabar fazendo um merge numa branch errada, erro esse que pode ser um impesílio.
* A criação de branchs para cada tipo de tasks ajuda muito e permite com que mais pessoas possam contribuir com o programa.
* Um grande desafio foi enfrentar erros de merge, parte essa onde eu carecia de conhecimento.

#### Fábio Marques Henrique
* A realização de um projeto na prática é uma excelente forma de fixar a teoria aprendida em aula. A questão fundamental do versionamento se tornou, na minha cabeça, essencial para uma boa identificação dos itens de configuração, seu controle, permitindo auditoria e geração de relatórios. Mesmo para pequenos projetos (os quais eu desenvolvia sozinho) não me vejo trabalhando sem o auxilio de  uma ferramenta de controle de versão, como fazia antes e se mostra quase que obrigatório em um contexto de trabalho em equipe.
* Com as noções de build engeneering + environment configuration podemos verificar como se torna muito mais simples atualizações e testes usando ferramentas como o Make e Docker que em conjunto com as "actions" do GitHub que facilitam muito automação de rotinas desses testes.
* Outro ponto de extrema importância foi a realização de release management para rastreamento de versões e possibilidade de rollback caso haja necessidade.
Como todo projeto pode ser melhorado entramos no ciclo de melhoria continua e percebemos a importância de sempre manter um padrão no desenvolvimento do projeto, mantendo reuniões periódicas e decidindo próximos passos deixando sempre versões que podem ser facilmente apuradas e coletas para adaptações e/ou melhorias.

#### Terence Myren Kutzner
Para mim foi o primeiro contato que tive com o Git/Github - tive um pouco de dificuldade para me familiarizar com os comandos e padrões para criar branch e commits. Com o passar do projeto, fui me familiarizando e cometendo menos erros ao fazer commits, reviews, criação de branch.  Uma outra dificuldade que senti no inicio foi fazer correções de nomes de branch por erros de digitação (acredito que pela pouca familiaridade com a ferramenta). No geral pode-se destacar algumas lições aprendidas: 
- A importância de seguir um padrão de nomenclatura para branches e commits, o que facilita a organização e entendimento do histórico do projeto. Nesse questito, como todos estavam aprendendo é possível ver claramente a diferença dos commits do inicio do projeto para o fim dele. 
- Além disso, percebi o quanto os commits pequenos e frequentes ajudam na rastreabilidade das mudanças e tornam o processo de revisão mais facil.
- Além disso, importante ter comunicação clara com o time, especialmente ao lidar com conflitos de merge. Nesse quesitos as reuniões realizadas com os integrantes ajudou bastante.


