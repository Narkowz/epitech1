#!/bin/bash

GREEN='\033[0;32m'
NC='\033[0m' # No Color

echo -e "${GREEN}Updating package lists...${NC}"
echo ""
sudo dnf update -y

echo ""

echo -e "${GREEN}Installing SDL2 and dependencies...${NC}"
echo ""
sudo dnf install SDL2 SDL2-devel -y
sudo dnf install libjpeg-turbo-devel libwebp-devel libtiff-devel SDL2_image SDL2_image-devel -y
sudo dnf install libmikmod-devel libfishsound-devel smpeg-devel liboggz-devel flac-devel fluidsynth-devel SDL2_mixer SDL2_mixer-devel -y
sudo dnf install freetype-devel SDL2_ttf SDL2_ttf-devel -y
echo ""
echo -e "${GREEN}SDL2 installation complete.${NC}"

echo ""

echo -e "${GREEN}Installing Ncurses...${NC}"
echo ""
sudo dnf install ncurses-devel -y
echo ""
echo -e "${GREEN}Ncurses installation complete.${NC}"

echo ""

echo -e "${GREEN}Installing SFML...${NC}"
echo ""
sudo dnf install SFML SFML-devel -y
echo ""
echo -e "${GREEN}SFML installation complete.${NC}"

echo ""

echo -e "${GREEN}All dependencies installed successfully!${NC}"