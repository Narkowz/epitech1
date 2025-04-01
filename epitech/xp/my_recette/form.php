<!DOCTYPE html>
<html>
<head>
    <title>Page de traitement</title>
    <meta charset="utf-8">
</head>
<body>
    <p>Dans le formulaire précédent, vous avez fourni les informations suivantes :</p>

    <?php
    echo 'Nom : ' . htmlspecialchars($_POST["name"]) . '<br>';
    echo 'Ingrédients : ' . nl2br(htmlspecialchars($_POST["ingredients"])) . '<br>';
    echo 'Préparation : ' . nl2br(htmlspecialchars($_POST["prepa"])) . '<br>';

    if (isset($_FILES['image']) && $_FILES['image']['error'] === UPLOAD_ERR_OK) {
        $fileTmpPath = $_FILES['image']['tmp_name'];
        $fileName = $_FILES['image']['name'];
        $uploadFileDir = './uploaded_files/';
        
        if (!is_dir($uploadFileDir)) {
            mkdir($uploadFileDir, 0777, true);
        }

        $dest_path = $uploadFileDir . $fileName;

        echo 'Chemin temporaire : ' . $fileTmpPath . '<br>';
        echo 'Chemin de destination : ' . $dest_path . '<br>';

        if (move_uploaded_file($fileTmpPath, $dest_path)) {
            echo 'Image : <br>';
            echo '<img src="' . $dest_path . '" alt="Image téléchargée" style="max-width:300px;"><br>';
        } else {
            echo 'Il y a eu une erreur lors du téléchargement de l\'image.<br>';
        }
    } else {
        echo 'Erreur lors du téléchargement de l\'image : ' . $_FILES['image']['error'] . '<br>';
    }
    ?>
</body>
</html>
