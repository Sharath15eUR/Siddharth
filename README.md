# Siddharth Balaji Module 1 Answers

Name: Siddharth Balaji

College: Sona College of Technology

I've uploaded the answers and the screenshots of the outputs to the following questions 
in their respective files and the explanation of those commands below, in this README.md file.

# Q1. Create a file and add executable permission to all users (user, group and others)

Use the 'touch' command to create an empty file.

Use 'chmod' is the command to change file permissions.

'a' stands for all users (user, group, and others).

'+x' adds the executable permission.

'ls -l' command is to verify the permissions.


# Q2. Create a file and remove write permission for group user alone.

Use the 'touch' command to create an empty file

Let's use the 'chmod' command to remove write permission for the group.

'chmod' changes the file permissions.

'g' stands for the group.

'-w' removes the write permission.


# Q3. Create a file and add a softlink to the file in different directory.

Use 'mkdir' command is used to create directories.

-p ensures that both directory1 and directory2 are created.

Use 'touch' command to create the file inside directory1/directory2.

'ln -s' command to create a symbolic (soft) link in directory1.

'ls -l' command ise used to verify the contents of directory1.


# Q4. Use ps command with options to display all active process running on the system.

Use 'ps aux' to view all active processes.

'a' displays processes of all users.

'u' is use to display processes in a user-friendly format with extra details.

'x' Includes processes without a controlling terminal.


# Q5. Create 3 files in a dir1 and re-direct the output of list command with sorted by timestamp 
# of the files to a file.

Use 'mkdir'command to create dir1.

Use 'touch' to create files.

Use 'sleep' to delay file creation.

Use 'ls -lt' command to list files where the newest file is displayed first.
