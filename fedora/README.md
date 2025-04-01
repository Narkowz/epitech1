# README - Epitech Graphical Dependencies Installer

## Description
This script automates the installation of all graphical dependencies and other essential tools for Epitech projects on a **Fedora** system. It installs **SDL2, Ncurses, SFML**, as well as development tools like **CMake, Git, GCC, Python3, Zsh, and VS Code**.

## Prerequisites
- A Fedora system (or a compatible distribution using `dnf`)
- Administrator access (`sudo`)
- An active internet connection

## Installation
1. **Download the script**
   ```bash
   git clone https://github.com/Narkowz/Fedora-dump.git fedora-dump
   cd fedora-dump
   ```

2. **Make it executable**
   ```bash
   chmod +x fedora-dump.sh
   ```

3. **Run the script**
   ```bash
   ./fedora-dump.sh
   ```

## Script Contents
The script performs the following actions:

### 🔹 System Update
- Updates all existing packages using `dnf update`

### 🔹 Installation of Graphical Dependencies
- **SDL2** and related libraries: `SDL2`, `SDL2-devel`, `SDL2_image`, `SDL2_mixer`, `SDL2_ttf`
- **Ncurses**: `ncurses-devel`
- **SFML**: `SFML`, `SFML-devel`

### 🔹 Installation of Development Tools
- **Compilers and build tools**: `cmake`, `g++`, `gcc-c++`, `make`
- **Version control**: `git`
- **Python 3 and its modules**: `python3`, `python3-pip`, `python3-devel`
- **Utilities**: `curl`, `wget`

### 🔹 Installation of Zsh and Oh My Zsh
- Installs `zsh` and configures it with **Oh My Zsh**
- Sets `zsh` as the default shell

### 🔹 Installation of Visual Studio Code
- Adds the official Microsoft repository
- Installs `code` (VS Code)

## Notes
After running the script, **restart your terminal** to apply the changes:
```bash
exec zsh
```

## Uninstallation
If you wish to remove some of the installed dependencies, use `dnf remove`. Example:
```bash
sudo dnf remove SDL2 SDL2-devel SFML SFML-devel ncurses-devel code
```

## License
This script is open-source. You may modify and adapt it according to your needs.

---

✨ **Tested on Fedora. Use at your own risk!**

