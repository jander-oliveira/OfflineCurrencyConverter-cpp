# Conversor de Moedas (Offline Currency Converter)

> 🇧🇷 Versão em Português abaixo | 🇺🇸 English version below

- [English Version](#english-version)
- [Versão-em-português](#versão-em-português)

---

## 🇺🇸 English Version

### Offline Currency Converter

This is a simple currency converter written in C++ that allows conversion between BRL, USD, EUR, and JPY using fixed rates. The user selects the source currency, the target currency, and the amount to convert, and the program calculates the result based on predefined rates.

This project was developed as a personal practice, with occasional support from AI tools (such as ChatGPT) for reviewing, explaining, and structuring the code.

The objective of this project is strictly academic and intended for self-learning. I am currently exploring the C++ language and decided to begin with a basic version using fixed rates. In the future, I plan to implement real-time currency rate fetching using a public API and JSON to make the conversion more accurate.

### How to Compile

You can compile the project using g++ in your terminal:

```bash
g++ conversor.cpp -o conversor
./conversor
```

### Program Flow

1. Displays the list of supported currencies
2. Asks the user for the source currency
3. Asks the user for the destination currency
4. Asks for the amount to convert
5. Validates all inputs
6. Retrieves the fixed conversion rate for the selected currency pair
7. Calculates the result using: `value * rate`
8. Displays the result with the appropriate currency symbol and two decimal places

### Concepts Used

- Data types: `string`, `double`
- Loops: `while`
- Conditional structures: `if`, `else`, `for`
- Arrays: `string moedasValidas[]`
- Data structures: `std::map`, `std::pair`
- Input/output: `cin`, `cout`
- Number formatting: `setprecision`, `fixed`

### Next Steps

- [ ] Connect to a live exchange rate API (JSON)
- [ ] Add more currencies (e.g., GBP, ARS, BTC)
- [ ] Create a graphical user interface (GUI) or migrate to a web version

---

## 🇧🇷 Versão em Português

### Conversor de Moedas (versão offline)

Este é um conversor de moedas simples escrito em C++, que permite converter valores entre BRL, USD, EUR e JPY utilizando taxas fixas. O usuário escolhe a moeda de origem, a moeda de destino e o valor a ser convertido, e o programa calcula o resultado com base nas taxas pré-definidas.

Este projeto foi desenvolvido como prática pessoal, com auxílio pontual de ferramentas de IA (como o ChatGPT) para revisão, explicações e estruturação do código.

O objetivo deste projeto é exclusivamente acadêmico e voltado ao aprendizado individual, no qual estou explorando os fundamentos da linguagem C++. Por isso, optei por começar com uma versão simples baseada em taxas fixas. Futuramente, pretendo implementar o uso de APIs com JSON para buscar as taxas de conversão automaticamente da internet, tornando o sistema mais preciso e atualizado.

### Como Compilar

Você pode compilar com o compilador `g++` no terminal:

```bash
g++ conversor.cpp -o conversor
./conversor
```

### Funcionamento do Programa

1. Mostra as moedas disponíveis para conversão
2. Solicita que o usuário informe a moeda de origem
3. Solicita que o usuário informe a moeda de destino
4. Solicita o valor a ser convertido
5. Valida os dados informados
6. Busca a taxa de conversão fixa para o par de moedas
7. Realiza o cálculo: `valor * taxa`
8. Exibe o resultado com o símbolo da moeda e duas casas decimais

### Conceitos Usados

- Tipos de dados: `string`, `double`
- Laços de repetição: `while`
- Estruturas condicionais: `if`, `else`, `for`
- Vetores: `string moedasValidas[]`
- Estruturas associativas: `std::map`, `std::pair`
- Entrada e saída de dados: `cin`, `cout`
- Formatação numérica: `setprecision`, `fixed`

### Próximos Passos

- [ ] Conectar com API de câmbio para obter taxas em tempo real
- [ ] Adicionar suporte a mais moedas (ex: GBP, ARS, BTC)
- [ ] Criar interface gráfica com C++ ou migrar para versão web
