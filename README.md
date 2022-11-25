# PSPD-Lab01 

## Gerador de arquivo com palavras pseudo-aleatórias

Foi criado devido a necessidade do projeto um gerador de arquivo. Para executá-lo basta rodar o comando na raiz do projeto: 

```
  python generate_file.py
```
## RPC 

### 1 - Passo: Iniciar o portmapper
```
  rpcbind
```

### 2 - Passo: Compilar o programa na pasta do arquivo

executar na pasta que estão os arquivos c

```
 make
```

### 3 - Passo: Executar o programa (Servidor)

Em uma máquina rode o programa com o comando:
```
  ./rpc_server
```
com isso o programa irá funcionar como um servidor de rpc na máquina local.

### 4 - Passo: Executar o cliente

Em uma outra máquina que tenha acesso a mesma rede, rode o comando colocando as entradas de sua preferência:
```
  ./rpc_client <server_ip> <rota_arquivo_leitura>
```


## gRPC

Para executar o cluster de containers com gRPC será necessário apenas rodar o comando:

```
  docker-compose up
```