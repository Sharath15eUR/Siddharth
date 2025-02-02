Create a Bash script 'file_analyzer.sh', to demonstrate the following concepts: 

1. Recursive functions:
   
- Write a recursive function to search for files in a directory and its subdirectories containing a specific keyword.

2. Redirection and error handling:
   
- Log errors (e.g., invalid arguments, missing files) to 'errors.log' and display them in the terminal.

3. Here document and here string:
   
- Use a here document to display a help menu when the '--help' option is passed.
  
- Search for a keyword in a specified file using a here string.

4. Special parameters- Use parameters like '$0', '$#', '$?' and '$@' to provide meaningful feedback.

5. Regular expressions:
- Validate inputs with regular expressions (Check if the file exists and the keyword is not empty and valid)

6. Command-line arguments using getopts:
- Use 'getopts' to handle:
  
'-d <directory>': Directory to search.

 '-k <keyword>': Keyword to search.
 
 '-f <file>': File to search directly.
 
 '--help': Display the help menu.
 

Example usage:

#Recursively search a directory for a keyword  ./file_analyzer.sh -d logs -k error

#Search for a keyword in a file  ./file_analyzer.sh -f script.sh -k TODO

#Display the help menu  ./file_analyzer.sh --help


![Screenshot 2025-02-02 180440](https://github.com/user-attachments/assets/585e02bc-27d3-4b9f-a0a8-7a091a4e52fe)


![Screenshot 2025-02-02 180502](https://github.com/user-attachments/assets/4becffa0-a14a-49d6-9c95-486dd2907bd7)

![Screenshot 2025-02-02 180514](https://github.com/user-attachments/assets/67508076-ae97-48b6-972f-7e8a8028cc66)

![Screenshot 2025-02-02 180536](https://github.com/user-attachments/assets/4ee6010c-a4df-45f5-a3bd-47cd2188c09a)

![Screenshot 2025-02-02 180554](https://github.com/user-attachments/assets/a34524e1-8d5f-45ea-bf46-7c47c42019d9)

![Screenshot 2025-02-02 180604](https://github.com/user-attachments/assets/b4bc9649-6b37-4f14-a11e-c1be564c1148)







