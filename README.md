# Projeto Mercado

Este projeto simula um sistema de compras de um mercado simples em linguagem C.

## Descrição

O programa permite que o usuário interaja com um carrinho de compras, realizando operações como:

* Inserir itens no carrinho.
* Visualizar o carrinho de compras.
* Limpar o carrinho de compras.
* Sair do programa.

## Estrutura do Projeto

```shell
CIN_GRUPO2/
  ├── bin/
  ├── inc/
  │   └── mercado.h
  ├── obj/
  ├── src/
  │   ├── mercado.c
  │   └── run.c
  ├── Makefile
  └── README.md
```

* `inc/mercado.h`: Contém a definição da estrutura `Product` e os protótipos das funções.
* `src/mercado.c`: Implementa as funções de manipulação do carrinho de compras.
* `src/run.c`: Contém a função `main` e a lógica principal do programa.
* `bin/`: Diretório para os executáveis.
* `obj/`: Diretório para os arquivos objeto.
* `Makefile`: Arquivo para compilação do projeto.
* `README.md`: Este arquivo com a descrição do projeto.

## Compilação e Execução

Para compilar e executar o programa, siga os passos abaixo:

1.  **Clone o repositório:**

    ```bash
    git clone https://github.com/andremgbr/cin_grupo2.git
    cd mercado
    ```

2.  **Compilar o programa:**

    ```bash
    make
    ```

    Este comando irá compilar os arquivos `.c` e gerar o executável `mercado` no diretório `bin/`.

3.  **Executar o programa:**

    ```bash
    make run
    ```

    ou

    ```bash
    bin/mercado
    ```

4.  **Executar os testes:**

    ```bash
    make test
    ```

    Este comando irá compilar e executar os testes presentes no diretório `test/`.

5.  **Limpar os arquivos compilados:**

    ```bash
    make clean
    ```

    Este comando irá remover os arquivos executáveis e objetos gerados durante a compilação.

## Makefile

O `Makefile` utiliza as seguintes variáveis:

* `CC`: Compilador C (gcc).
* `CFLAGS`: Flags de compilação (Wall, Wextra).
* `TARGET`: Nome do executável (mercado).
* `BINFOLDER`: Diretório para os executáveis (bin/).
* `OBJFOLDER`: Diretório para os arquivos objeto (obj/).
* `SRCFOLDER`: Diretório dos arquivos fonte (src/).
* `INCLUD`: diretório dos arquivos de cabeçalho (inc/)
* `SRCFILES`: Lista de arquivos fonte.

## Uso

Ao executar o programa, você verá um menu com as seguintes opções:

1.  Inserir item no carrinho.
2.  Visualizar carrinho de compras.
3.  Limpar carrinho de compras.
4.  Sair.

Siga as instruções exibidas no console para interagir com o programa.

## Atualizações

Esse readme é apenas um esboço inicial para o projeto e será ajustado conforme o andamento do desenvollvimento da versão final do projeto.
