<?php
include '../config.php';


if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $product_name = $_POST['product_name'];
    $price = $_POST['price'];
    $stock = $_POST['stock'];

    // Vérifiez si le fichier a été uploadé sans erreur
    if (isset($_FILES['image']) && $_FILES['image']['error'] == 0) {
        $target_dir = "../image_upload/uploads/";
        $target_file = $target_dir . basename($_FILES["image"]["name"]);

        // Déplacez le fichier uploadé vers le répertoire de destination
        if (move_uploaded_file($_FILES["image"]["tmp_name"], $target_file)) {
            // Insérez le chemin de l'image dans la base de données
            $sql = "INSERT INTO products (product_name, price, stock, image_path) VALUES ('$product_name', '$price', '$stock', '$target_file')";

            if ($conn->query($sql) === TRUE) {
                echo "New record created successfully";
            } else {
                echo "Error: " . $sql . "<br>" . $conn->error;
            }
        } else {
            echo "Sorry, there was an error uploading your file.";
        }
    } else {
        echo "File upload error";
    }
    $conn->close();
}
?>
