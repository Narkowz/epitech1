#!/bin/bash

GREEN='\033[0;32m'
NC='\033[0m' # No Color

echo -e "${GREEN}Updating package lists...${NC}"
echo ""
sudo apt update -y

echo ""

echo -e "${GREEN}Installing SDL2 and dependencies...${NC}"
echo ""
sudo apt install libsdl2-dev libsdl2-2.0-0 -y
sudo apt install libjpeg-dev libwebp-dev libtiff5-dev libsdl2-image-dev libsdl2-image-2.0-0 -y
sudo apt install libmikmod-dev libfishsound1-dev libsmpeg-dev liboggz2-dev libflac-dev libfluidsynth-dev libsdl2-mixer-dev libsdl2-mixer-2.0-0 -y
sudo apt install libfreetype6-dev libsdl2-ttf-dev libsdl2-ttf-2.0-0 -y
echo ""
echo -e "${GREEN}SDL2 installation complete.${NC}"

echo ""

echo -e "${GREEN}Installing Ncurses...${NC}"
echo ""
sudo apt install libncurses5-dev libncursesw5-dev -y
echo ""
echo -e "${GREEN}Ncurses installation complete.${NC}"

echo ""

echo -e "${GREEN}Installing SFML...${NC}"
echo ""
sudo apt install libsfml-dev -y
echo ""
echo -e "${GREEN}SFML installation complete.${NC}"

echo ""

echo -e "${GREEN}All dependencies installed successfully!${NC}"
