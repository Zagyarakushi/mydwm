# My dwm

A customised build of dwm with personal patches and configuration improvements for a minimal, keyboard-driven Linux workflow.

This build extends dwm with additional window management features while maintaining the simplicity and performance of the suckless philosophy.

dwm is a lightweight dynamic window manager from the suckless project.

---

## 📸 Preview

![dwm screenshot](dwm.png)

---

## ✨ Features

- Minimal X11 window manager
- Keyboard-driven workflow
- Custom keybindings
- Personal appearance configuration
- Lightweight and fast desktop environment

---

## 🔧 Included Patches

This build includes the following dwm patches:

- **actualfullscreen**  
  Enables true fullscreen behaviour by removing window borders and gaps.

- **alwaysfullscreen**  
  Keeps fullscreen windows always visible above other windows.

- **movestack**  
  Allows moving windows within the stack using keyboard shortcuts.

- **pertag**  
  Enables separate layouts and settings for each tag/workspace.

- **scratchpad**  
  Adds a hidden terminal or application window that can be toggled quickly.

- **sticky**  
  Allows windows to remain visible across all tags/workspaces.

- **vanitygapsforalllayouts**  
  Adds configurable gaps between windows across all layouts.

---

## 🛠️ Requirements

You need:

- GCC
- Make
- X11 development libraries
- Xft development libraries
- Xinerama development libraries

### Void Linux

```bash
sudo xbps-install -S gcc make libX11-devel libXft-devel libXinerama-devel
```

Other distributions may use different package names.

---

## 🚀 Installation

Clone the repository:

```bash
git clone https://gitlab.com/zagyarakushi/mydwm.git

cd mydwm
```

Build:

```bash
make
```

Install:

```bash
sudo make install
```

---

## ⚙️ Configuration

The main configuration file is:

```
config.h
```

Modify it to customise:

- Keybindings
- Fonts
- Colours
- Layouts
- Window behaviour

After changing configuration:

```bash
make clean
make
sudo make install
```

---

## 📚 About

This repository contains my personal dwm build used as part of my Linux workflow.

The goal is to maintain a lightweight, fast, and keyboard-focused desktop environment while keeping the simplicity of the suckless philosophy.

---

## 📄 License

MIT License