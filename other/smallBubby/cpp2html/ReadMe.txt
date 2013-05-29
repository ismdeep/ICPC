------------------------------------------
    CPP2HTML command-line transcoder v1.02
          by AngleWyrm, 2004
------------------------------------------

The CPP2HTML command-line transcoder is a small DOS tool for converting CPP code
into tagged HTML files. It is designed to be used automatically as a tool from
your favorite programming IDE. HTML tags are all classes, so that formatting is
entirely left to the programmer.

Installation: The only necessary file is the executable cpp2html.exe.

The output is tagged with <SPAN> tags, where each span is of a class:
    .comment
    .macro
    .keyword
    .literal
    .numeric
    
USAGE:
cpp2html <filename.ext> [moreFileNames]

This produces an output file named "filename.ext.htm" in the current directory.
