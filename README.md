# Hello World Kernel Driver

Welcome to the **Hello World Kernel Driver**! This is a simple Windows kernel-mode driver that prints "Hello, World!" to the kernel debugger. The project is built using **Visual Studio 2022**.

## 🚀 Features
- Basic Windows kernel-mode driver
- Prints "Hello, World!" in the debugger
- Built with Visual Studio 2022

## 🛠️ Build Instructions

Follow these steps to build the driver in **Visual Studio 2022**:

1. **Install Visual Studio 2022**
   - Make sure you have the "Windows Driver Kit (WDK)" installed.

2. **Clone the repository**
   ```sh
   git clone https://github.com/kaveOO/KERNEL-DRIVER.git
   cd KERNEL-DRIVER
   ```

3. **Open the project**
   - Launch **Visual Studio 2022**
   - Open the `.sln` file

4. **Set the Configuration**
   - Change the build configuration to **Release**
   - Set the platform to **x64** (or your desired target)

5. **Build the Driver**
   - Press **Ctrl + Shift + B** or go to `Build > Build Solution`
   
Your driver (`.sys` file) will be generated in the `x64/Release` directory.

## 🖥️ Loading the Driver

To load the driver, you will need to:

- Have **test signing mode enabled** if you're not using a properly signed driver.
- Use `sc.exe` or a similar tool to load the `.sys` file into the Windows kernel.

## 🧐 Debugging

This driver prints messages to the **kernel debugger**. However, I will **not** be explaining the debugging setup here since it is extremely long. If you are unfamiliar with kernel debugging, you may need to research **WinDbg** and other debugging tools.

## ⚠️ Disclaimer
This project is for educational purposes only. Running kernel-mode drivers can crash your system if not handled properly. Proceed with caution!

## 📜 License
MIT License. Feel free to use, modify, and distribute this project.

---

**Happy coding! 🎯**

