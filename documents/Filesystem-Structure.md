# Filesystem Structure

```/```

This is the root directory.

```/usr```

Despite its name, this operates like the /home directory in *nix systems. It has subdirectories that corrospond to users on the system.

```/tmp```

This is the usr tmp directory.

```/sys```

This is the directory where non-executable, non-configuration files are stored.

```/sys/tmp```

This is the tmp directory that the system uses. 

```/sys/headers```

This is where the development headers of the current build of TS/OS are stored.

```/sys/info```

This is where the info files for the program info are stored.

```/sys/trash```

Files and directories being deleted are moved here.

```/lib```

This is where the library files are stored. There are subdirectories corresponding to the arch of the library files in the directory.

```/bin```

This is the only directory where files can be executed from. It holds all executable files

```/cfg```

This is where all the configuration files are stored.
