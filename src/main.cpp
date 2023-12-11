#include <Arduino.h>
#include <WebServer.h>
#include <WiFi.h>

const char *ssid = "iPhone de Mathieu";
const char *password = "Azerty123";
WebServer server(80);,

char etatRover = 0;
char texteEtatRover[5][18] = {"ARRÊT!", "AVANCE!", "RECULE!", "TOURNE À DROITE!", "TOURNE À GAUCHE!"};

void handleRoot()
{
  String page = "<!DOCTYPE html>";

  page += "<html lang='fr'>";

  page += "<head>";
  page += "    <title>Serveur ESP32</title>";
  page += "    <meta http-equiv='refresh' content='50' name='viewport' content='width=device-width, initial-scale=1' charset='UTF-8' />";
  page += "    <link rel='stylesheet' href='https://www.w3schools.com/w3css/4/w3.css'>";
  page += "    <style>";
  page += "        .center {";
  page += "            display: flex;";
  page += "            flex-direction: column;";
  page += "            align-items: center;";
  page += "            justify-content: flex-start;";
  page += "            height: 80vh;";
  page += "        }";
  page += "        .w3-card {";
  page += "            background-color: rgb(86, 140, 204);";
  page += "            padding: small;";
  page += "            font-size: 48px;";
  page += "            color: white;";
  page += "            text-align: center;";
  page += "            width: 100%;";
  page += "        }";
  page += "        .arrow-buttons {";
  page += "            display: flex;";
  page += "            flex-wrap: wrap;";
  page += "            justify-content: center;";
  page += "            align-items: center;";
  page += "            position: absolute;";
  page += "            top: 50%;";
  page += "            left: 50%;";
  page += "            transform: translate(-50%, -50%);";
  page += "        }";
  page += "        .arrow-button {";
  page += "            display: flex;";
  page += "            align-items: center;";
  page += "            justify-content: center;";
  page += "            width: 110px;";
  page += "            height: 110px;";
  page += "            font-size: 100px;";
  page += "            border-radius: 50%;";
  page += "            margin: 25px;";
  page += "            text-decoration: none;";
  page += "        }";
  page += "    </style>";
  page += "</head>";

  page += "<body>";
  page += "    <div class='center'>";
  page += "        <div class='w3-card'>";
  page += "            <h2>ÉTAT ROVER :</h2>";
  page += "            <p>";
  page += texteEtatRover[etatRover];
  page += "            </p>";
  page += "        </div>";

  page += "        <div class='arrow-buttons'>";
  page += "            <a href='/gauche' class='arrow-button up-button'>&#8592;</a>";
  page += "            <div>";
  page += "                <a href='/haut' class='arrow-button left-button'>&#8593;</a>";
  page += "                <a href='/arret' class='arrow-button stop-button'>&#9724;</a>";
  page += "                <a href='/bas' class='arrow-button right-button'>&#8595;</a>";
  page += "            </div>";
  page += "            <a href='/droite' class='arrow-button down-button'>&#8594;</a>";
  page += "        </div>";
  page += "    </div>";

  page += "    <div class='w3-center w3-padding-16'>";
  page += "        <p>Ce serveur est hébergé sur un ESP32</p>";
  page += "        <i>AUSY BORDEAUX</i>";
  page += "    </div>";

  page += "</body>";
  page += "</html>";

  server.setContentLength(page.length());
  server.send(200, "text/html", page);
}

void handleNotFound()
{
  server.send(404, "text/plain", "404: Not found");
}

void handleHaut()
{
  Serial.println("⏫");
  server.sendHeader("Location", "/");
  server.send(303);
  etatRover = 1;
}

void handleBas()
{
  Serial.println("⏬");
  server.sendHeader("Location", "/");
  server.send(303);
  etatRover = 2;
}

void handleDroite()
{
  Serial.println("⏩");
  server.sendHeader("Location", "/");
  server.send(303);
  etatRover = 3;
}

void handleGauche()
{
  Serial.println("⏪");
  server.sendHeader("Location", "/");
  server.send(303);
  etatRover = 4;
}

void handleArret()
{
  Serial.println("🅿️");
  server.sendHeader("Location", "/");
  server.send(303);
  etatRover = 0;
}

void setup()
{
  Serial.begin(9600);
  delay(1000);
  Serial.println("\n");

  WiFi.persistent(false);
  WiFi.begin(ssid, password);
  Serial.print("Tentative de connexion...");

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(100);
  }

  Serial.println("Connexion établie!");
  Serial.print("Adresse IP: ");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, handleRoot);
  server.on("/haut", HTTP_GET, handleHaut);
  server.on("/bas", HTTP_GET, handleBas);
  server.on("/droite", HTTP_GET, handleDroite);
  server.on("/gauche", HTTP_GET, handleGauche);
  server.on("/arret", HTTP_GET, handleArret);
  server.onNotFound(handleNotFound);
  server.begin();

  Serial.println("Serveur web actif!");
}

void loop()
{
  server.handleClient();
}