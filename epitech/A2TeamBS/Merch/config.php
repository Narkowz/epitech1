<?php
$servername = "localhost";
$username = "Lancelot"; // Remplacez par votre nom d'utilisateur de base de données
$password = "new_secure_password"; // Remplacez par votre mot de passe de base de données
$dbname = "APP"; // Remplacez par le nom de votre base de données

// Créer une connexion
$conn = new mysqli($servername, $username, $password, $dbname);

// Vérifier la connexion
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
?>
