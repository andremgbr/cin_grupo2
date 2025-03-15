# Projeto Mercado

Este projeto simula um sistema de carrinhos de compras simples de um mercado em linguagem C.

## Descrição

O programa permite que o usuário interaja com um carrinho de compras, realizando operações como:

* Inserir itens no carrinho.
* Visualizar o carrinho de compras.
* Limpar o carrinho de compras.
* Limpar um item do carrinho de compras.
* Sair do programa.

### Depedencias

FrameWork de test em C
```Bash
$ sudo apt-get install check
```

## Compilação e Execução

Para compilar e executar o programa, siga os passos abaixo:

1.  **Clone o repositório:**

    ```bash
    git clone https://github.com/andremgbr/cin_grupo2.git
    cd CIN_GRUPO2
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

## Uso

Ao executar o programa, você verá um menu com as seguintes opções:

```1.  Inserir item no carrinho.```: Comando o qual listara os intens disponíveis para adicionar ao carrinho, o usuário deverá
selecionar o intem desejado e depois a quantidade desejada.
  
```2.  Visualizar carrinho de compras.```: Comando o qual irá listar todos os intes que já estão no carrinho, o seu valor unitário
e a quantidade total por item e a quantidade total no carrinho.

```3.  Limpar carrinho de compras.```: Comando o qual irá retirar todos os intens do carrinho de compra, deixando o zerado.

```4.  Remover item do carrinho.```: Comando o qual permite zerar apenas um item no carrinho de compra.

```5.  Sair.```: Comando para sair da aplicação.

Siga as instruções exibidas no console para interagir com o programa.


## Docker

Aplicação disponível também no dockerhub fabiohennr/scm_cin_grupo2

No terminal (tendo o docker já instalado) executar o seguinte comando: 
```docker run -it --rm fabiohennr/scm_cin_grupo2:v2.1```
a partir disso, o programa já esta configurado e pronto para execução

