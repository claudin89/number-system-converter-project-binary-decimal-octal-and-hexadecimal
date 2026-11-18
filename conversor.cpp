#include <iostream>  // Habilita entrada (cin) e saída (cout)

using namespace std;  // Evita ter que escrever std:: antes de comandos como cout e cin

int main() {
    int numero[10];         // Vetor de 10 posições (índices 0 a 9)
    long long decimal = 0;  // Acumula o resultado em decimal
    long long potencia = 1; // Potência da base atual (começa em base^0 = 1)
    int opEntrada, opSaida; // Guardam as opções escolhidas nos dois menus (switch)
    char texto[50];         // Vetor para ler qualquer entrada com segurança sem travar o cin
    int tam;                // Guarda o tamanho do texto digitado
    bool valido;            // Bandeira de controle para validar as entradas

    // ==================== 1º SWITCH: BASE DE ENTRADA ====================
    cout << "Escolha a base de ENTRADA:" << endl;
    cout << "1 - Binario | 2 - Decimal | 3 - Octal | 4 - Hexadecimal" << endl;
    cin >> opEntrada;

    switch (opEntrada) {
        case 1: // Binário -> Decimal (barra letras, dígitos != 0/1 e > 10 dígitos)
            do {
                valido = true;
                cout << "Digite o numero binario (ate 10 digitos): " << endl;
                cin >> texto;  

                // Conta quantos caracteres foram digitados
                tam = 0;
                while (texto[tam] != '\0') {
                    tam++;
                }

                // Trava 1: Tamanho máximo de 10 dígitos
                if (tam > 10) {
                    cout << "Erro: Digite no maximo 10 digitos!" << endl;
                    valido = false;
                } else {
                    // Trava 2: Só aceita os caracteres '0' ou '1' (barra letras e outros números)
                    for (int i = 0; i < tam; i++) {
                        if (texto[i] != '0' && texto[i] != '1') {
                            valido = false;
                        }
                    }
                    if (!valido) {
                        cout << "Erro: Binario aceita apenas 0 e 1 (sem letras ou outros numeros)!" << endl;
                    }
                }
            } while (!valido);

            // Zera o vetor numero[10] e preenche de trás para frente com os dígitos validados
            for (int i = 0; i < 10; i++) numero[i] = 0;
            for (int i = 0; i < tam; i++) {
                numero[10 - tam + i] = texto[i] - '0';
            }

            // Converte o vetor binário para decimal
            for (int i = 9; i >= 0; i--) {
                if (numero[i] == 1) {
                    decimal += potencia;
                }
                potencia *= 2;
            }
            break;

        case 2: // Decimal -> Decimal (barra letras e > 10 dígitos)
            do {
                valido = true;
                cout << "Digite o numero decimal (ate 10 digitos): " << endl;
                cin >> texto;

                tam = 0;
                while (texto[tam] != '\0') {
                    tam++;
                }

                if (tam > 10) {
                    cout << "Erro: Digite no maximo 10 digitos!" << endl;
                    valido = false;
                } else {
                    for (int i = 0; i < tam; i++) {
                        if (texto[i] < '0' || texto[i] > '9') {
                            valido = false;
                        }
                    }
                    if (!valido) {
                        cout << "Erro: Decimal aceita apenas numeros de 0 a 9!" << endl;
                    }
                }
            } while (!valido);

            // Monta o valor decimal a partir dos caracteres validados
            decimal = 0;
            for (int i = 0; i < tam; i++) {
                decimal = decimal * 10 + (texto[i] - '0');
            }
            break;

        case 3: // Octal -> Decimal (barra letras, dígitos > 7 e > 10 dígitos)
            do {
                valido = true;
                cout << "Digite o numero octal (ate 10 digitos): " << endl;
                cin >> texto;

                tam = 0;
                while (texto[tam] != '\0') {
                    tam++;
                }

                if (tam > 10) {
                    cout << "Erro: Digite no maximo 10 digitos!" << endl;
                    valido = false;
                } else {
                    for (int i = 0; i < tam; i++) {
                        if (texto[i] < '0' || texto[i] > '7') {
                            valido = false;
                        }
                    }
                    if (!valido) {
                        cout << "Erro: Octal aceita apenas numeros de 0 a 7!" << endl;
                    }
                }
            } while (!valido);

            // Preenche o vetor numero[10] de trás para frente
            for (int i = 0; i < 10; i++) numero[i] = 0;
            for (int i = 0; i < tam; i++) {
                numero[10 - tam + i] = texto[i] - '0';
            }

            // Converte o vetor octal para decimal
            for (int i = 9; i >= 0; i--) {
                decimal += numero[i] * potencia;
                potencia *= 8;
            }
            break;

        case 4: // Hexadecimal -> Decimal (barra letras > F, símbolos e > 10 dígitos)
            do {
                valido = true;
                cout << "Digite o numero hexadecimal (ate 10 digitos): " << endl;
                cin >> texto;

                tam = 0;
                while (texto[tam] != '\0') {
                    tam++;
                }

                if (tam > 10) {
                    cout << "Erro: Digite no maximo 10 digitos!" << endl;
                    valido = false;
                } else {
                    for (int i = 0; i < tam; i++) {
                        bool ehNumero = (texto[i] >= '0' && texto[i] <= '9');
                        bool ehMaiuscula = (texto[i] >= 'A' && texto[i] <= 'F');
                        bool ehMinuscula = (texto[i] >= 'a' && texto[i] <= 'f');

                        if (!ehNumero && !ehMaiuscula && !ehMinuscula) {
                            valido = false;
                        }
                    }
                    if (!valido) {
                        cout << "Erro: Hexadecimal aceita apenas numeros (0-9) e letras de A ate F!" << endl;
                    }
                }
            } while (!valido);

            // Converte de trás para frente usando potência de 16
            for (int i = tam - 1; i >= 0; i--) {
                int valorDigito = 0;
                if (texto[i] >= '0' && texto[i] <= '9') {
                    valorDigito = texto[i] - '0';
                } else if (texto[i] >= 'A' && texto[i] <= 'F') {
                    valorDigito = texto[i] - 'A' + 10;
                } else if (texto[i] >= 'a' && texto[i] <= 'f') {
                    valorDigito = texto[i] - 'a' + 10;
                }
                decimal += valorDigito * potencia;
                potencia *= 16;
            }
            break;

        default:
            cout << "Opcao invalida!" << endl;
            return 0;
    }

    // ==================== 2º SWITCH: BASE DE SAÍDA ====================
    cout << "\nEscolha a base de SAIDA:" << endl;
    cout << "1 - Binario | 2 - Decimal | 3 - Octal | 4 - Hexadecimal" << endl;
    cin >> opSaida;

    int resultado[64];
    int qtd = 0;

    switch (opSaida) {
        case 1: // Decimal -> Binário
            if (decimal == 0) cout << "Binario: 0" << endl;
            else {
                while (decimal > 0) {
                    resultado[qtd] = decimal % 2;
                    decimal = decimal / 2;
                    qtd++;
                }
                cout << "Binario: ";
                for (int i = qtd - 1; i >= 0; i--) cout << resultado[i];
                cout << endl;
            }
            break;

        case 2: // Decimal -> Decimal
            cout << "Decimal: " << decimal << endl;
            break;

        case 3: // Decimal -> Octal
            if (decimal == 0) cout << "Octal: 0" << endl;
            else {
                while (decimal > 0) {
                    resultado[qtd] = decimal % 8;
                    decimal = decimal / 8;
                    qtd++;
                }
                cout << "Octal: ";
                for (int i = qtd - 1; i >= 0; i--) cout << resultado[i];
                cout << endl;
            }
            break;

        case 4: // Decimal -> Hexadecimal
            if (decimal == 0) cout << "Hexadecimal: 0" << endl;
            else {
                while (decimal > 0) {
                    resultado[qtd] = decimal % 16;
                    decimal = decimal / 16;
                    qtd++;
                }
                cout << "Hexadecimal: ";
                for (int i = qtd - 1; i >= 0; i--) {
                    if (resultado[i] < 10) cout << resultado[i];
                    else if (resultado[i] == 10) cout << "A";
                    else if (resultado[i] == 11) cout << "B";
                    else if (resultado[i] == 12) cout << "C";
                    else if (resultado[i] == 13) cout << "D";
                    else if (resultado[i] == 14) cout << "E";
                    else if (resultado[i] == 15) cout << "F";
                }
                cout << endl;
            }
            break;

        default:
            cout << "Opcao invalida!" << endl;
            break;
    }

   cout << "\nPressione ENTER para sair...";
cin.ignore();
cin.get();
return 0;
}