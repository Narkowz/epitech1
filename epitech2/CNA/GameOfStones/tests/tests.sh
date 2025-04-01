#!/bin/bash

print_test() {
    echo "=== Test: $1 ==="
}

assert() {
    if [ $? -eq $2 ]; then
        echo "✅ Success: $1"
    else
        echo "❌ Failure: $1"
        exit 1
    fi
}

cat <<EOF > friends.txt
Jon Snow is friends with Sansa Stark
Missandei is friends with Daenerys Targaryen
Tywin Lannister is friends with Cersei Lannister
Sansa Stark is friends with Cersei Lannister
Lynce Hightower is friends with Jorah Mormont
Daenerys Targaryen is friends with Jorah Mormont
Jeor Mormont is friends with Jorah Mormont
Samwell Tarly is friends with Maester Aemon
Samwell Tarly is friends with Sansa Stark
Maester Aemon is friends with Tywin Lannister
Vere is friends with Samwell Tarly
Theon Greyjoy is friends with Jon Snow
Tyrion Lannister is friends with Cersei Lannister
Samwell Tarly is friends with Jon Snow
The Mountain is friends with Cersei Lannister
Jorah Mormont is friends with Cersei Lannister
EOF

cat <<EOF > plots.txt
Daenerys Targaryen is plotting against Cersei Lannister
Tywin Lannister is plotting against Cersei Lannister
Sansa Stark is plotting against Theon Greyjoy
The Mountain is plotting against Jon Snow
Jon Snow is plotting against Tywin Lannister
Theon Greyjoy is plotting against Sansa Stark
EOF

print_test "Test --links: Jon Snow et Cersei Lannister (connectés)"
./game_of_stones --links friends.txt "Jon Snow" "Cersei Lannister"
assert "Jon Snow et Cersei Lannister sont connectés" 0

print_test "Test --links: Jon Snow et Missandei (non connectés)"
./game_of_stones --links friends.txt "Jon Snow" "Missandei"
assert "Jon Snow et Missandei ne sont pas connectés" 0

print_test "Test --links: Personnage inexistant"
./game_of_stones --links friends.txt "Jon Snow" "Harry Potter"
assert "Personnage inexistant" 0

# # Tester le mode --plots (vérifie seulement que le fichier est lu correctement)
# print_test "Test --plots: Lecture du fichier plots.txt"
# ./game_of_stones --plots friends.txt plots.txt
# assert "Lecture du fichier plots.txt" 0

print_test "Test --links: Fichier mal formaté"
cat <<EOF > mal_formaté.txt
Jon Snow is friends with Sansa Stark
Missandei is friends with Daenerys Targaryen
Tywin Lannister is friends with
EOF
./game_of_stones --links mal_formaté.txt "Jon Snow" "Sansa Stark"
assert "Fichier mal formaté" 84

print_test "Test --links: Nombre d'arguments incorrect"
./game_of_stones --links friends.txt "Jon Snow"
assert "Nombre d'arguments incorrect" 84

print_test "Test --help: Affichage de l'aide"
./game_of_stones --help
assert "Affichage de l'aide" 0

rm friends.txt plots.txt mal_formaté.txt

echo "=== Tous les tests sont terminés ==="