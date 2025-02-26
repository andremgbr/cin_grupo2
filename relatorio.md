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


#### Sujestões Professor

show cart
remover itens do carrinho
efetivar venda (Limpa o carrinho e mexe nas quantidades)
desistir da compra - libera o carrinho mas nao meche nas quantidades
fechamento do caixa - registrando as venda e listar as veendas do  dia 
incrementar outras funcionalidades
gerar relatorio e arquivo txt de fechamento do caixa
