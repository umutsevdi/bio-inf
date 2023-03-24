#!/usr/bin/perl

use strict;
use warnings;
#******************************************************************************
#
# * File: io.pl
#
# * Author:  Umut Sevdi
# * Created: 03/24/23
# * Description: Input-Output operations of this amazing language
#*****************************************************************************

# <> gets an input from the standard output
# $line = <>
# print $line

# chomp operator removes the new line from the end of the line
my $line = "This has too many new lines\n";
chomp $line;
print "[", $line, "]\n";

#******************************************************************************
#                           File Status Commands
#******************************************************************************

# Opening a file
my $f = "../data.txt";
if (-e $f) {
    print "File exists\n";
} else {
    print "File doesn't exist\n"; }

# File commands
# -e if exists
# -r is readable
# -w is writable
# -x is executable
# -o is owned by user
# -z is empty
# -f is file
# -d is directory

# can use multiple operators
if(-e $f && -f _ && -r _ ){
   print("File $f exists and readable\n");	
}

#******************************************************************************
#                           Reading & Writing on Files
#******************************************************************************

# opening file in read mode
open(my $FH, $f) or die $!;
print "opened $f\n";

# or non-existing file in write mode
open(my $FH2, '>', "./non-existing-file") or die $!;
print "opened ./non-existing-file\n";

# reading
my $contents = "";
while (my $line = <$FH>) {
    $contents .= $line;
    print "-$line-";
}

# print allow us to write FH2
print $FH2 "Writing to this file\n";
print $FH2 "Appending it";
# close a file
close($FH2);
close($FH);
system('rm ./non-existing-file');


system("vim");
