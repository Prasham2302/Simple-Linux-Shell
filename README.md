# Simple-Linux-Shell
Simple Linux shell using C
COMPUTER ARCHITECTURE AND OPERATING SYSTEMS

Commands available in my shell are:

External Command:
  ●	Ls
  ●	Rm
  ●	Mkdir
  ●	Cat
  ●	Date

Internal Command:
  ●	History
  ●	Cd
  ●	Pwd
  ●	Exit
  ●	Echo

Assumptions one must keep in mind while using my shell:
  ●	Use only one option at a time for the commands provided below.
  ●	Don’t use tab to complete sentences.
  ●	Follow the syntax provided below.
  ●	Don’t use spaces at the start of the command.
  ●	Don’t use any of the arrow keys.



My commands and its available options with Descriptions:

  ●	Ls: Use this file to list contents in the directory of files and directories. Syntax: ls [options]
    ○	-a: Use this option to list all files including all hidden files.
    ○ -l: This option is used to list files in long listing format.

  ●	Rm: Use this command to remove file specified on the command line. Syntax: rm [options] [filename]
    ○	-r: Use this command to delete directories and their contents.
    ○	-v: Use this command to delete in Verbose mode, which explains what is being currently done.

  ●	Mkdir: Use this command to make directories. Syntax: mkdir [options] [directory name]
    ○	-v: Use this to create the directory in verbose mode, explains what is being done.
    ○	-p: Use this to create parent directories and if the directory exists then no error is displayed.

  ●	Cat: Use this to read data from the file and output its contents. Syntax: cat [options] [Filename]
    ○	-e: This command displays “$” at the end of every line.
    ○	-A: This command is combination of -vET, where it will display “^I” for every tab used, “$” at the end of each line, use this “^”           and M- notations.

  ●	Date: Use this command to print or set date and time. Syntax: date [options]
    ○	-u: Use this command to print date and time in Universal time format.
    ○	-R: Use this command to print current date and time in RFC 5322 format.

  ●	Echo: Use this command to display a line of text in the command line. Syntax: echo [option] [Text to be displayed]
    ○	*: Use this command to print all files and folders in the current working directory.
    ○	-E: Default echo mode.

  ●	History: Use this to print the list of all commands entered in the shell.Syntax: history [options]
    ○	-c: Use this command to clean the current history.


  ●	Cd: Use this command to change directories. If you don’t provide any name/ “..” then it will change the directory to the initial              working directory. Syntax: cd [directory name or “..”], use “..” to go to the previous directory and to go to a certain                  directory use its name.

  ●	Pwd: It prints the name of the current directories.

  ●	Exit: Use this command to exit from shell.
