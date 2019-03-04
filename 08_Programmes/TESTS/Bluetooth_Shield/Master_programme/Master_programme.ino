#include <SoftwareSerial.h> 

#include "CommunicationProtocol.h"

/*********** DEBUT BLUETOOTH ***********/
#define RxD 2 // Cette pin doit être connectée à la pin TX du Bluetooth
#define TxD 3 // Cette pin doit être connectée à la pin RX du Bluetooth
SoftwareSerial blueToothSerial(RxD, TxD); // Communication RX/TX vers le Shield Seeedstudio 2.x

CommunicationProtocol communicationProtocol;
int sendBlueToothCommand(char command[], int size = -1);
#define MASTER 1 // On change cette valeur à 1 si on est sur le Master ou à 0 si on est sur le Slave !

String received = "";
char recvChar;
int sizeOfData = 0;
char recv_str[100];
/*-------------FIN BLUETOOTH-----------*/


void setup() {

  Serial.begin(9600);

  /*********** DEBUT BLUETOOTH ***********/
  blueToothSerial.begin(9600); // On initialise une communication à 9600 baud avec le bluetooth. Attention, si le Bluetooth est configuré sous un autre Baudrate (par exemple 38400) il faut mettre ce baudrate là à la palce de 9600
  blueToothSerial.print("AT"); // On envoie une petite commande AT au Bluetooth (sans attendre de réponse. Je ne sais pas si c'est obligatoire de faire ceci mais dans l'exemple donné par Seedstudio, il y avait toujours cette commande au début).
  
  setupBlueToothConnection(); // On initialise les configurations par défaut du Bluetooth. Mettre en commentaire cette ligne quand le Bluetooth a déjà été configuré pour éviter de perdre du temps.
  
  communicationProtocol.addSoftwareSerialBluetooth(&blueToothSerial); // On ajoute le Bluetooth comme argument à la librairie
  
  // On définit notre liste de packet ID (se référer au rapport si vous ne savez pas ce que c'est)
  // Attention, cette liste doit être exactement la même sur le Slave ! (Dans le même ordre avec les mêmes noms de packet id)
  communicationProtocol.addPacketID("packetID1"); // Le packet ID de packetID1 sera de 0 étant donné que c'est le premier packet ID
  communicationProtocol.addPacketID("packetID2"); // Le packet ID de packetID2 sera de 1 étant donné que c'est le deuxième packet ID
  /*-------------FIN BLUETOOTH-----------*/
}

void loop() {
  // Si on reçoit des données par Bluetooth (byte par byte)
  while (blueToothSerial.available()){
    // On place le byte reçu par Bluetooth dans recvChar
    recvChar = blueToothSerial.read();
    // On envoie ce byte à la classe CommunicationProtocol qui va s'occuper de décomposer tous les prochains bytes reçus jusqu'à la fin du message qui fera en sorte de renvoyer VRAI à communicationProtocol.isAvailable()
    communicationProtocol.parseBytePerByte(recvChar);
  }
  
  // Tout le message a été reçu
  if (communicationProtocol.isAvailable() > 0)
  {
    sizeOfData      = communicationProtocol.getDataSize(); // On place la taille du message reçu dans sizeOfData
    received        = communicationProtocol.getData(); // On place le message reçu dans received

    switch (communicationProtocol.getLastPacketID())
    {
      case 0: // packetID1
        Serial.println(received);
      break;
    case 1: // packetID2
    Serial.println(received);
    break;
    }
  }
  
  // Envoyer des données par Bluetooth
  communicationProtocol.clearData("packetID1");
  communicationProtocol.addData("packetID1", "Dis-moi bonjour stp");
  communicationProtocol.send("packetID1");
  
   // Envoyer d'autres données par Bluetooth
  communicationProtocol.clearData("packetID2");
  communicationProtocol.addData("packetID2", "Dis-moi aurevoir stp");
  communicationProtocol.send("packetID2");

}

//used for compare two string, return 0 if one equals to each other
int strcmp(char *a, char *b)
{
  unsigned int ptr = 0;
  while (a[ptr] != '\0')
  {
    if (a[ptr] != b[ptr]) return -1;
    ptr++;
  }
  return 0;
}


int setupBlueToothConnection()
{
#if MASTER
  Serial.println("this is MASTER\r\n");
#else
  Serial.println("this is SLAVE\r\n");
#endif

  sendBlueToothCommand("AT");

  sendBlueToothCommand("AT+CLEAR"); // On efface l'adresse du dernier Bluetooth avec lequel on s'est connecté
  delay(1000);
  sendBlueToothCommand("AT+AUTH1");
  delay(1000);
  sendBlueToothCommand("AT+PIN6789"); // On définit le pincode à 6789
  delay(1000);
  sendBlueToothCommand("AT+NOTI1"); // On définit qu'on veut être notifié lorsqu'il y a une connexion/déconnexion
  delay(1000);

  sendBlueToothCommand("AT+BAUD4"); // On veut que le baudrate soti de 9600
  delay(400);

#if MASTER
  sendBlueToothCommand("AT+ROLEM"); // On définit le Bluetooth en tant que master
  delay(1000);
  sendBlueToothCommand("AT+NAMEMaster"); // On définit le nom de notre Bluetooth comme étant "Master"
  delay(2000);
#else
  sendBlueToothCommand("AT+ROLES"); // On définit le Bluetooth en tant que Slave
  delay(1000);
  sendBlueToothCommand("AT+NAMESlave"); // On définit le nom de notre Bluetooth comme étant "Slave"
  delay(1000);
#endif
  sendBlueToothCommand("AT+RESTART"); // On restarte le Bluetooth afin que nos changements prennent effet
  delay(2000);

  sendBlueToothCommand("AT");
  delay(1000);
  return 0;
}


//send command to Bluetooth and return if there is a response received
int sendBlueToothCommand(char command[], int size = -1)
{
  Serial.print("send: ");
  Serial.print(command);
  Serial.println("");

  if (size == -1)
    blueToothSerial.print(command);
  else
    blueToothSerial.write(command, size);

  delay(300);

  if (recvMsg(1000) != 0) return -1;

  Serial.print("recv: ");
  Serial.print(recv_str);
  Serial.println("");
  return 0;
}

//receive message from Bluetooth with time out
int recvMsg(unsigned int timeout)
{
  //wait for feedback
  unsigned int time = 0;
  unsigned char num;
  unsigned char i;

  //waiting for the first character with time out
  i = 0;
  while (1)
  {
    delay(50);
    if (blueToothSerial.available())
    {
      recv_str[i] = char(blueToothSerial.read());
      i++;
      break;
    }
    time++;
    if (time > (timeout / 50)) return -1;
  }

  //read other characters from uart buffer to string
  while (blueToothSerial.available() && (i < 100))
  {
    recv_str[i] = char(blueToothSerial.read());
    i++;
  }
  recv_str[i] = '\0';

  return 0;
}
