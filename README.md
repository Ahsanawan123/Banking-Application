# Banking-Application
  This C++ console-based banking system simulates key operations like account management, deposits, withdrawals, and        transfers, using an interactive menu. It showcases object-oriented programming and file management by storing account     data in a text file, serving as an educational tool for basic banking functionalities.

# Ideal Environment
  The program is developed and tested with Visual Studio 2022 on Windows. It is recommended to run it in a similar setup    for the best compatibility.

#Setup Instructions
  To run this program in Visual Studio 2022, follow these steps:

    1.) Clone or Download the Repository

    2.) Clone this repository or download the source code to your local machine.

    3.) Open the Project

    4.) Open Visual Studio 2022, and select File > Open > Project/Solution. Navigate to the downloaded project directory     and open the project file.

    5.) Build the Project

    6.) In Visual Studio, build the project by clicking on Build > Build Solution.

    7.) Run the Program: After a successful build, run the program by pressing F5 or clicking on the Start button in          Visual Studio.
    

# Preloaded Accounts
  The program uses a text file (Accounts.txt) to store and load account data. For the program to function correctly, this   file must be present in the same directory as the executable or specified correctly within the program.
![image](https://github.com/Ahsanawan123/Banking-Application/assets/98630461/63c589f6-a318-4ff3-9f6b-b6f6295c03f3)

  format: accnt#:balance(00.00),name,address,pin
  If not in this format program will throw erreneous input error

# Creating Your Own Account Data File

  If you choose not to use the provided Accounts.txt file, you can create your own. 
  Ensure the data in the file is formatted as follows:
    Acct #(int):balance(double),name(string),address(string),pin(int)
  Note: Make sure the file does not end with two newlines/enters. The cursor should end on or right after the last line     to ensure proper reading of the file by the program.
# Enabling Filename Extensions
  To create or rename your text file with a .txt extension, ensure "Show filename extensions" is turned on in your File     Explorer options. This will allow you to specify the file type explicitly when creating or renaming the file.
![BankingApplication 4_7_2024 11_43_50 PM](https://github.com/Ahsanawan123/Banking-Application/assets/98630461/6ef2dcfe-d3e9-4bb8-af0f-bfbe141d4741)

  ![image](https://github.com/Ahsanawan123/Banking-Application/assets/98630461/066b85ce-6e27-4ea9-a0d3-4c8a1956b821)
