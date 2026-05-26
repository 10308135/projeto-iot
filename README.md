Este projeto consiste em um protótipo de iluminação inteligente baseado em IoT, desenvolvido com uma placa ESP32, um sensor de luminosidade LDR e um LED.
O sistema monitora continuamente a luminosidade do ambiente e aciona automaticamente a iluminação quando a intensidade luminosa fica abaixo de um valor de referência configurado. Além do controle automático, o dispositivo envia informações por meio do protocolo MQTT para um broker HiveMQ, permitindo o monitoramento na plataforma Node-RED. O valor limite utilizado para o acionamento do LED também pode ser alterado remotamente.


Hardware Utilizado:
  Placa ESP32: Microcontrolador responsável pelo processamento dos dados, conexão Wi-Fi e comunicação MQTT.
  Módulo sensor LDR: Sensor utilizado para detectar a luminosidade do ambiente.
  LED: Para representar a iluminação.

Plataformas de Desenvolvimento: 
  Arduino IDE: Ambiente utilizado para desenvolvimento, compilação e envio do código para a ESP32.
  Node-RED: Plataforma para visualização dos dados e pelo envio de comandos para a placa ESP32.

Ambiente de Simulação: O projeto foi desenvolvido na plataforma WOKWI, mas o código pode ser carregado, com as devidas mudanças, para uma placa física através do Arduino IDE.

Interface Analógica:
  Entrada: Pino 34. Utilizada para leitura do valor fornecido pelo módulo LDR.

Interface Digital:
  Saída: Pino 2. Utilizada para controle do LED.

Protocolo de comunicação:
  MQTT. Utilizado entre o dispositivo e os serviços de monitoramento.
  
Módulos de comunicação:
  Broker HiveMQ. Responsável pela troca de mensagens.
