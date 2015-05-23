
Markdown converter
===============

A program for converting markdown files to different formats. This file is used for testing


Lists
------
* Item
* Item 2
* etc


Numbered lists
---------
1. hello
2. good bye


Gedit script
------------
The program can be used with gedits external tools to compile markdown file. (Requires pdflatex)

> #!/bin/sh
> /change/this/path/to/md2tex $GEDIT_CURRENT_DOCUMENT_PATH | pdflatex
> gnome-open texput.pdf







