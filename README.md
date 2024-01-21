# brtime - Manipulação de Datas e Horas no Fuso Horário do Brasil

A biblioteca **brtime** é projetada para fornecer funcionalidades simples de manipulação de datas e horas no fuso horário do Brasil na linguagem Pawn.

## Como Usar

### 1. Inclusao da Biblioteca

Antes de usar as funções de data e hora, certifique-se de incluir a biblioteca no seu gamemode ou filterscript:

```pawn
#include <a_samp>
#include <brtime>
```

### 2. Obtendo a Data Atual

Para obter a data atual no fuso horário do Brasil, utilize a função `BR_GetDate`:

```pawn
new year, month, day;
BR_GetDate(year, month, day);

// Agora, 'year', 'month' e 'day' contêm a data atual no fuso horário do Brasil.
```

### 3. Obtendo a Hora Atual

Para obter a hora atual no fuso horário do Brasil, utilize a função `BR_GetTime`:

```pawn
new hour, minute, second;
BR_GetTime(hour, minute, second);

// Agora, 'hour', 'minute' e 'second' contêm a hora atual no fuso horário do Brasil.
```

## Como Funciona

A biblioteca utiliza o SQLite integrado ao SA:MP para realizar consultas SQL que retornam a data e hora ajustadas para o fuso horário do Brasil. As funções `BR_GetDate` e `BR_GetTime` utilizam essas consultas para fornecer os valores desejados.

## Licença

Este projeto é licenciado sob a [Licença Apache, Versão 2.0](http://www.apache.org/licenses/LICENSE-2.0).
```
Este README.md fornece uma breve introdução à biblioteca brtime, explica como usá-la e oferece informações sobre seu funcionamento e licença. Certifique-se de ajustar conforme necessário para atender às necessidades específicas do seu projeto.
```