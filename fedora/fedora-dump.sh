#!/bin/bash

# This script automates the installation of various development dependencies 
# and graphical libraries required for EPITECH projects on a Fedora-based system.
#
# It performs the following tasks:
# 1. Updates the package lists using `dnf update`.
# 2. Installs SDL2 and its related dependencies:
#    - SDL2, SDL2-devel, SDL2_image, SDL2_image-devel, SDL2_mixer, SDL2_mixer-devel, SDL2_ttf, SDL2_ttf-devel
#    - Additional libraries: libjpeg-turbo-devel, libwebp-devel, libtiff-devel, libmikmod-devel, libfishsound-devel,
#      smpeg-devel, liboggz-devel, flac-devel, fluidsynth-devel, freetype-devel
# 3. Installs Ncurses development libraries (`ncurses-devel`).
# 4. Installs SFML and its development libraries (`SFML`, `SFML-devel`).
# 5. Installs other essential development tools and utilities:
#    - cmake, git, g++, gcc-c++, make, python3, python3-pip, python3-devel, curl, wget, zsh
# 6. Installs and configures Oh My Zsh for an enhanced shell experience.
# 7. Changes the default shell to Zsh.
# 8. Adds the Visual Studio Code repository, imports its GPG key, and installs VS Code.
#
# The script uses color-coded messages to indicate progress and completion of each step.
# It concludes by advising the user to restart their terminal for the changes to take effect.

GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Step 1: Update the system package lists
echo -e "${GREEN}Updating package lists...${NC}"
echo ""
sudo dnf update -y
echo ""
echo -e "${GREEN}Package lists updated!${NC}"
echo ""

# Step 2: Install EPITECH graphical dependencies
echo -e "${GREEN}Installing all EPITECH graphical dependencies...${NC}"
echo ""

# Step 2a: Install SDL2 and related libraries
echo -e "${GREEN}Installing SDL2 and dependencies...${NC}"
echo ""
sudo dnf install SDL2 SDL2-devel -y
sudo dnf install libjpeg-turbo-devel libwebp-devel libtiff-devel SDL2_image SDL2_image-devel -y
sudo dnf install libmikmod-devel libfishsound-devel smpeg-devel liboggz-devel flac-devel fluidsynth-devel SDL2_mixer SDL2_mixer-devel -y
sudo dnf install freetype-devel SDL2_ttf SDL2_ttf-devel -y
if [ $? -eq 0 ]; then
    echo -e "${GREEN}SDL2 installation complete.${NC}"
else
    echo -e "${RED}Error during SDL2 installation.${NC}"
fi

echo ""

# Step 2b: Install Ncurses
echo -e "${GREEN}Installing Ncurses...${NC}"
echo ""
sudo dnf install ncurses-devel -y
if [ $? -eq 0 ]; then
    echo -e "${GREEN}Ncurses installation complete.${NC}"
else
    echo -e "${RED}Error during Ncurses installation.${NC}"
fi

echo ""

# Step 2c: Install SFML
echo -e "${GREEN}Installing SFML...${NC}"
echo ""
sudo dnf install SFML SFML-devel -y
if [ $? -eq 0 ]; then
    echo -e "${GREEN}SFML installation complete.${NC}"
else
    echo -e "${RED}Error during SFML installation.${NC}"
fi

echo ""

# Step 3: Confirm all graphical dependencies installed
echo -e "${GREEN}All EPITECH graphical dependencies installed successfully!${NC}"
echo ""

# Step 4: Install other essential development dependencies
echo -e "${GREEN}Installing other dependencies...${NC}"
echo ""

# Install development tools and utilities
sudo dnf install cmake -y
sudo dnf install git -y
sudo dnf install g++ -y
sudo dnf install gcc-c++ -y
sudo dnf install make -y
sudo dnf install python3 -y
sudo dnf install python3-pip -y
sudo dnf install python3-devel -y
sudo dnf install curl -y
sudo dnf install wget -y
sudo dnf install zsh -y

# Install Oh My Zsh
echo -e "${GREEN}Installing Oh My Zsh...${NC}"
sh -c "$(curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
chsh -s $(which zsh)
if [ $? -eq 0 ]; then
    echo -e "${GREEN}Oh My Zsh installed and configured successfully.${NC}"
else
    echo -e "${RED}Error during Oh My Zsh installation.${NC}"
fi

# Step 5: Install Visual Studio Code
echo -e "${GREEN}Installing Visual Studio Code...${NC}"
echo ""
sudo rpm --import https://packages.microsoft.com/keys/microsoft.asc
sudo sh -c 'echo -e "[code]\nname=Visual Studio Code\nbaseurl=https://packages.microsoft.com/yumrepos/vscode\nenabled=1\ngpgcheck=1\ngpgkey=https://packages.microsoft.com/keys/microsoft.asc" > /etc/yum.repos.d/vscode.repo'
sudo dnf install code -y
if [ $? -eq 0 ]; then
    echo -e "${GREEN}Visual Studio Code installation complete.${NC}"
else
    echo -e "${RED}Error during VS Code installation.${NC}"
fi

echo ""

# Final success message
echo -e "${GREEN}Other dependencies installed successfully!${NC}"
echo ""
echo -e "${GREEN}All dependencies installed successfully!${NC}"
echo ""
echo -e "${GREEN}Please restart your terminal for the changes to take effect.${NC}"
echo ""
