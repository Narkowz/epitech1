<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Home</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <header class="header">
        <a href="home.php" class="home-button">🏠 Home</a>
        <nav>
            <ul>
                <li><a href="#">Products</a></li>
                <li><a href="#">Categories</a></li>
                <li><a href="#">About Us</a></li>
                <li><a href="#">Contact</a></li>
                <li><a href="../register_login/index.html">Sign In</a></li>
            </ul>
        </nav>
    </header>
    <main>
        <section class="hero">
            <div class="hero-content">
                <h1>Discover the Best Products at Unbeatable Prices</h1>
                <p>Your one-stop shop for quality and affordability.</p>
                <a href="#" class="btn">Shop Now</a>
            </div>
            <div class="hero-image">
                <img src="logo.png" alt="Products Image">
            </div>
        </section>
        <section class="featured-products">
            <h2>Featured Products</h2>
            <div class="product-grid">
            <?php
                include '../config.php';

                $sql = "SELECT product_id, product_name, price, stock, image_path FROM products";
                $result = $conn->query($sql);

                if ($result->num_rows > 0) {
                    while($row = $result->fetch_assoc()) {
                        echo '<div class="product-item">';

                        // Vérifiez si le chemin de l'image n'est pas vide et que le fichier existe
                        if (!empty($row["image_path"]) && file_exists($row["image_path"])) {
                            echo '<img src="' . $row["image_path"] . '" alt="' . $row["product_name"] . '">';
                        } else {
                            echo '<img src="path/to/default-image.png" alt="Image not available">';
                        }

                        echo '<h3>' . $row["product_name"] . '</h3>';
                        if ($row["stock"] == 0) {
                            echo '<p class="out-of-stock">Out of Stock</p>';
                            echo '<p class="price"><s>$' . $row["price"] . '</s></p>';
                        } else {
                            echo '<p class="price">$' . $row["price"] . '</p>';
                        }
                        echo '</div>';
                    }
                } else {
                    echo "0 results";
                }
                $conn->close();
            ?>

            </div>
        </section>
    </main>
    <footer>
        <p>&copy; 2024 Your Website. All rights reserved.</p>
    </footer>
</body>
</html>
