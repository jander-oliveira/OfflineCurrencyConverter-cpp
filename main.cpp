// Conversor de moedas (BRL, USD, EUR, JPY)
// Versão offline com taxas fixas (etapas iniciais)

#include <iostream>     // Para entrada e saída padrão (cin, cout)
#include <string>       // Para manipular strings
#include <iomanip>      // Para formatar a saída com casas decimais
#include <map>          // (Opcional) Para associar pares de moedas a taxas
#include <utility>      // (Opcional) Para usar std::pair

// ------------------------------
// Função que mostra as moedas suportadas
// ------------------------------
void mostrarMoedas() {
    std::cout << "Moedas disponíveis para conversão:\n";
    std::cout << "________________________________\n";
    std::cout << "USD - Dólar Americano\n";
    std::cout << "BRL - Real Brasileiro\n";
    std::cout << "EUR - Euro\n";
    std::cout << "JPY - Iene Japonês\n";
    std::cout << "________________________________\n";
}

// ------------------------------
// Função que lê uma moeda de origem ou destino
// Valida a entrada para garantir que está na lista
// ------------------------------
std::string lerMoeda(std::string tipo) {
    std::string moeda;
    std::string moedasValidas[] = {"USD", "BRL", "EUR", "JPY"};

    bool valido = false;
    while (!valido) {
        std::cout << "Digite a moeda de " << tipo << " (ex: USD): ";
        std::cin >> moeda;

        for (const auto& m : moedasValidas) {
            if (moeda == m) {
                valido = true;
                break;
            }
        }

        if (!valido) {
            std::cout << "Moeda Inválida. Tente Novamente. \n";
        }
    }
    return moeda;
}

// ------------------------------
// Função que lê o valor a ser convertido
// Garante que é um número positivo
// ------------------------------
double lerValor() {
    double valor;
    bool valido = false;

    while (!valido) {
        std::cout << "Digite o valor a ser convertido: ";
        std::cin >> valor;

        if (std::cin.fail() || valor <= 0) {
            std::cin.clear();                // Limpa erro de entrada
            std::cin.ignore(1000, '\n');     // Descarta entrada inválida
            std::cout << "Valor inválido. Digite um número positivo.\n";
        } else {
            valido = true;
        }
    }
    return valor;
}

// ------------------------------
// Função principal do programa
// Executa as etapas de mostrar moedas, ler dados e exibir informações
// ------------------------------

double obterTaxa(std::string origem, std::string destino) {
    // Mapeia pares de moedas para suas respectivas taxas
    std::map<std::pair<std::string, std::string>, double> taxas = {
        {{"USD", "BRL"}, 5.30},
        {{"BRL", "USD"}, 0.19},
        {{"USD", "EUR"}, 0.93},
        {{"EUR", "USD"}, 1.07},
        {{"BRL", "EUR"}, 0.175},
        {{"EUR", "BRL"}, 5.70},
        {{"USD", "JPY"}, 157.4},
        {{"JPY", "USD"}, 0.0064},
        {{"BRL", "JPY"}, 29.45},
        {{"JPY", "BRL"}, 0.034},
        {{"EUR", "JPY"}, 168.3},
        {{"JPY", "EUR"}, 0.0059},
        {{"BRL", "BRL"}, 1.0},
        {{"USD", "USD"}, 1.0},
        {{"EUR", "EUR"}, 1.0},
        {{"JPY", "JPY"}, 1.0},
    };

    std::pair<std::string, std::string> chave = {origem, destino};

    // Verifica se o par está no mapa
    if (taxas.find(chave) != taxas.end()) {
        return taxas[chave];
    } else {
        std::cout << "Taxa de conversão não definida entre essas moedas.\n";
        return 0.0; // Ou lançar erro/tratar diferente se quiser
    }
}

// ______________________________________________________
// função simples para mostrar o símbolo correto da moeda:
// ______________________________________________________
std::string simboloMoeda(std::string moeda) {
    if (moeda == "BRL") return "R$";
    if (moeda == "USD") return "US$";
    if (moeda == "EUR") return "€";
    if (moeda == "JPY") return "¥";
    return "";
}

int main() {
    std::cout << "Conversor de moedas\n";

    mostrarMoedas();  // Exibe as moedas suportadas

    std::string origem = lerMoeda("origem");     // Lê moeda de origem
    std::string destino = lerMoeda("destino");   // Lê moeda de destino
    double valor = lerValor();                    // Lê o valor a converter

    // Exibe os dados informados
    std::cout << "Moeda origem: " << origem << "\n";
    std::cout << "Moeda destino: " << destino << "\n";
    std::cout << "Valor: " << std::fixed << std::setprecision(2) << valor << "\n";

    double taxa = obterTaxa(origem, destino);
    if (taxa == 0.0) {
        std::cout << "Não foi possível obter a taxa de conversão.\n";
        return 1; // Encerra com erro
    }

    double valorConvertido = valor * taxa;

    std::cout << "Valor convertido: " << simboloMoeda(destino) << " "
              << std::fixed << std::setprecision(2) << valorConvertido << "\n";

    return 0; // Fim do programa
}

