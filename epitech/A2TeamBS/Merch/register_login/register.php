<?php
// Logic for registering a user
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $name = $_POST['name'];
    $email = $_POST['email'];
    $password = $_POST['password'];
    
    // Here, you would typically hash the password and save the user to a database
    // Example (using PDO for database interaction):
    // $hashed_password = password_hash($password, PASSWORD_DEFAULT);
    // $pdo = new PDO('mysql:host=localhost;dbname=test', 'username', 'password');
    // $stmt = $pdo->prepare("INSERT INTO users (name, email, password) VALUES (?, ?, ?)");
    // $stmt->execute([$name, $email, $hashed_password]);

    echo "User registered successfully!";
}
?>
