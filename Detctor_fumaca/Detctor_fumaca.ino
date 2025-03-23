//inicializa variavel com o pino D4 da placa que recebe um sinal analogico do sensor e transforma em digital
#define MQ2_PIN 4
//define nivel de fumaça para comparação
#define GAS_THRESHOLD 600
//inicializa na placa
void setup() {
  //monitor e porta serial, na ide do arduino monitora informações digitais recebidas na frequencia 9600 baud(frequencia de picos de alteração de sinal em estado alto ou baixo)
  Serial.begin(9600);
  //limita para 10 bits de cada vez lidos na porta analogica
  analogReadResolution(10);
  // exibe no monitor serial que o sensor foi inicializado
  Serial.println("MQ-2 Sensor Initialized!");
  // define o pino D4 da placa como input (vai receber dados do sensor)
  pinMode(MQ2_PIN, INPUT);
}
//repete enquanto a placa estiver ligada
void loop() {
  // exibe no monitor serial a frase gas value: "valor detectado de fumaça ou gas aqui"
  Serial.print("Gas Value: ");
  Serial.println(analogRead(MQ2_PIN));
  //se o valor detectado for maior que o valor de comparação, emite um aviso
   if (MQ2_PIN > GAS_THRESHOLD) {
    Serial.println("Warning! High gas or smoke levels detected!");
   }
  //pausa por 500 millisegundos (meio segundo) antes de repetir o loop
   delay(500);
}
