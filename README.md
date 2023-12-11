<div id="top"></div>

# ESP Controller

<details>
  <summary>Table des matières</summary>
  <ol>
    <li>
      <a href="#Présentation">Présentation</a>
    </li>
    <li>
      <a href="#Installation ">Installation</a>
    </li>
    <li>
      <a href="#Résultats ">Résultats</a>
    </li>
    <li>
      <a href="#Plus ">Plus</a>
    </li>
    <li>
      <a href="#Autres ">Autres</a>
    </li>
  </ol>
</details>

## Présentation

Ce projet constitue une évolution et une continuité de notre précédent projet basé sur l'ESP32 et le contrôle de direction d'un véhicule. Dans cette nouvelle version, nous avons ajouté la possibilité de contrôler le rover à distance à l'aide d'un téléphone portable, en établissant une connexion Wi-Fi entre l'ESP32 et le téléphone. Cette amélioration offre une interface utilisateur conviviale et permet de visualiser l'état du rover en temps réel.
Le système est composé de l'ESP32, qui est utilisé comme microcontrôleur et point d'accès Wi-Fi, et d'un téléphone portable. Le téléphone portable est utilisé pour établir un partage de connexion et fournir un réseau Wi-Fi auquel l'ESP32 se connecte. L'ESP32 héberge une page web intégrée qui affiche l'état du rover, ainsi que des commandes de direction comprenant quatre flèches (haut, bas, gauche, droite) et un bouton d'arrêt pour immobiliser le véhicule.

<div align="center">
    <img src="Images/SchemaCom.png" width="687" height="175">
  </br></br>
</div>

L'utilisateur se connecte au réseau Wi-Fi généré par le téléphone portable, ce qui permet à l'ESP32 de se connecter au téléphone et d'accéder à la page web hébergée. Sur cette page, l'utilisateur peut visualiser en temps réel l'état du rover, tel que sa position. De plus, les flèches directionnelles permettent de contrôler le mouvement du rover dans différentes directions en fonction des commandes de l'utilisateur.

## Installation 

Pour installer le programme, vous pouvez cloner le dépôt git :

```
$ git clone https://gitlab.ausy.com/ausy/embedded-bdx-rd/drone.git
```
Ensuite, aller sur la branche "dev-mathieu" :

```
$ cd drone
$ git checkout "dev-mathieu"
$ git pull
```
Maintenant, vous pouvez installer VS Code :

```
$ sudo snap install snap-store
$ snao install code
```
Pour finir, aller à l'emplacement du fichier et ouvrez le avec VS Code :

```
$ cd drone
$ code ESP_Controller
```
Ou ouvrez le projet depuis l'accueil de PlatformIO :

<div>
    <img src="Images/home.png" width="606" height="321">
  </br></br>
</div>

## Résultats 

Vous pouvez maintenant déplacer le rover à l'aide de votre smartphone, en vous aidant des flèches directionnelles :

<div>
    <img src="Images/AppWeb.png" width="207" height="355">
  </br></br>
</div>


Un moniteur série est mis à disposition pour afficher les déplacements du véhicule en temps réel :

<div>
    <img src="Images/Terminal.png" width="652" height="128">
  </br></br>
</div>

⏫ : Le véhicule avance

⏬ : Le véhicule recule

⏩ : Le véhicule tourne à droite

⏪ : Le véhicule tourne à gauche

🅿️ : Le véhicule est à l'arrêt 

## Plus

Erreur de permission lors de la téléversement du code sur l'ESP32 : Comment résoudre le problème ?

Lors du téléversement du code sur l'ESP32, il peut arriver que vous rencontriez une erreur du type "could not open port /dev/ttyUSB0; permissions denied". Cette erreur se produit généralement en raison de problèmes de permission qui empêchent l'accès au port série utilisé pour communiquer avec l'ESP32. Heureusement, il existe une solution simple pour contourner cette erreur.

<div>
    <img src="Images/errorport.png" width="700" height="130">
  </br></br>
</div>

Voici les étapes à suivre pour résoudre le problème de permission :

Ouvrez un terminal sur votre système d'exploitation.
Tapez la commande suivante : 
```
$ sudo usermod -a -G dialout $USER.
```
"**sudo**" est utilisé pour exécuter la commande avec des privilèges administratifs.

"**usermod**" est la commande pour modifier les paramètres de l'utilisateur.

"**-a**" indique que nous ajoutons un groupe supplémentaire à l'utilisateur.

"**-G**" dialout spécifie que nous ajoutons l'utilisateur au groupe "dialout", qui est généralement associé aux ports série.

"**$USER**" représente le nom de l'utilisateur actuel.

Appuyez sur Entrée et entrez le mot de passe administrateur si cela vous est demandé.
Après avoir exécuté cette commande, vous devriez pouvoir accéder au port série sans rencontrer l'erreur de permission.

En ajoutant votre utilisateur au groupe "dialout", vous lui donnez les permissions nécessaires pour accéder aux ports série, ce qui permet de résoudre l'erreur de permission lors du téléversement du code sur l'ESP32.
En suivant ces étapes, vous devriez pouvoir contourner l'erreur de permission lors du téléversement du code sur l'ESP32 et poursuivre le développement de votre projet en toute fluidité.

## Autres 

[Home](https://gitlab.ausy.com/ausy/embedded-bdx-rd/drone/-/tree/dev-mathieu/)

[Joystick Arduino](https://gitlab.ausy.com/ausy/embedded-bdx-rd/drone/-/tree/dev-mathieu/Joystick_Ard)

[Joystick ESP32](https://gitlab.ausy.com/ausy/embedded-bdx-rd/drone/-/tree/dev-mathieu/Joystick_ESP32)