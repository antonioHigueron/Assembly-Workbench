# Assembly-Workbench
IDE to program in Assembly Language

SETTINGS
--------
* Colors for every style.
* Open layout
* Open last projects and files
* Show line numbers
* Font to use by the editor.
* Enable code/comments/preproc folding
* See end line 
* Caret Line visible

BUGS
----

* When building projects with whitespaces into the name, it doesn't builds anything.
* On Windows there is a bug when using wxExecute with environment variables. It doesn't recognise the ml64.exe from the PATH environment variable. So, right now it's hardcoded.
* We shouldn't ask for save changes when closing the application without any modification in the files.
* On the settings window we need to pass arrays of strings to paths instead of a single string in one line.
* We need more control over the environment variables. We need to get/set them for the different kind of assemblers and options.

TODO
----

* Make available the possibility of update settings for files and projects from Settings Window.
* Think about how to integrate git/github into Assembly Workbench
* Add Github/Git window to control the changes
* Integratte GIT/GitHUB/Bitbucket/Any other CVS into the IDE
* Add the possibility to add/remove/modify files to the project in run time. This means that the editor will check such files and will show a pop up with a message in case some files had been added/removed/modified into the project directory. (look for wxFileSystemWatcher)
* Add the possibility to save/reload the layout of the IDE and set the default option in the menu.
* Change paths to files and directories from strings to wxFileName
* Spanish accents are not supported by the controls of wxWidgets, we need to add support to them.
* Think about different templates to use when creating new projects/files.
* Think about how to autodetect the different assemblers and linkers installed into the system.
* Add a Window which holds a list of all symbols defined in a project or file.
* Add support to international (Spanish, English)
* Add general Settings (see section Settings)
* When building the file/project, save automatically all changes made into files before doing it.

Tomorrow
--------

* Improve the way we store code files.
* Add Basic Find/Replace tools with windows.
	* When finding over open files, don't find anything from real file cause you have to find into buffer.
* Configure the tool chain based on the configuration file.
* Ensure every file outside the project has an absolute path. When file is absolute, we should set up this configuration on the project file.
* Implement a Console Log to log the output of the assembler, linker, and compiler.
* Implement Rebuild and Clean.
* When there is no change in the project, we shouldn't rewrite the project file because. When it does, the order of the files is different.
* When there is just one project open, whe should build it whether is open a file or not.
