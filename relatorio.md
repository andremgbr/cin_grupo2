### Depedencias
```Bash
$ sudo apt-get install check
```

```make```: para buildar a aplicação
```make run```: para executar a aplicação
```make test```: para executar os teste unitários

### GitFlow 

O repositório será divido em 2 branches principais. 
- Main: código versionado para realeases.
- Dev: código em fase de desenvolvimento.

Para alguma nova criação de funcionalidade deverá ser criada uma nova branch a partir do Dev com prefixo feature/ no nome, Ex: feature/funcionalidade, o que faŕa o merge para a branch Dev..
Para alguma correção de bug presente em produção, deve-se criar uma nova branch a partir do Main com prefixo hotfix/ no nome, Ex: hotfix/funcionalidade, o que deve ser feito merge na main e na dev posteriormente.
Para release, é criado uma nova branch a partir do dev com prefixo release com o número da versão, Ex release/1.0.0, e desse branch faz apenas as correções das features/bugs que estão presente nessa branc e assim feito merge para Main e também Dev.

Mais info no:
https://www.alura.com.br/artigos/git-flow-o-que-e-como-quando-utilizar?srsltid=AfmBOopstJCwgYAND855bTLVjTVd3yjaH041YOyjroKgL8kMGGM7xBRb

### Commit

Adotar alguma convenção de commit (ex.: feat: ..., fix: ..., docs: ...) e versionar com tags (v1.0.0, v1.1.0, etc.) na medida que o projeto for evoluindo.

###
#### André Roetger
* Achei muito interessante o gerenciamento de tarefas disponível no Projects do GitHub. Além disso, o próprio gerenciamento de issues oferece diversas funcionalidades úteis para o desenvolvimento do projeto.
* Eu desconhecia a ferramenta Actions do GitHub e achei extremamente interessante aprender a utilizá-la. Fiquei impressionado com o quão poderosa ela é, especialmente para o controle de testes, automação de processos e envio de notificações por e-mail para os responsáveis.
* Um dos desafios enfrentados pelo time foi a falta de um líder responsável por definir o escopo do projeto e designar as tarefas entre os membros.
* Tivemos que realizar algumas reuniões para alinhar decisões importantes. Apesar de a seção de issues permitir comentários, sentimos falta de um ambiente de chat instantâneo para facilitar a comunicação em tempo real.
