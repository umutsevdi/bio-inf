#!/usr/bin/perl -w

use warnings;
#******************************************************************************
#
# * File: regex.pl
#
# * Author:  Umut Sevdi
# * Created: 03/23/23
# * Description: Introduction to /regex/ capabilities of this most amazing
# language
#*****************************************************************************

# In perl there is a built in regex operator. ~=
# Then you can do all the regex shenanigans.
$a = "LookAt this text";
if ($a =~ m/oo/) {
    print "Match Found\n";
} else {
    print "Match Not Found\n";
}

$b = "How many e in this text? eee";
# Exactly 3 times
if ($b =~ m/e{3}/) {
    print "Exactly 3 times\n";
} else {
    print "Not 3 times\n";
}

# String concat operator
$b .= "e";
# At least 3 times
if ($b =~ m/e{3,}/) {
    print "More than 3 times\n";
} else {
    print "No more than 3 times\n";
}

# Less than 4 times
if ($b =~ m/e{,4}/) {
    print "Less than 4 times\n";
} else {
    print "No less than 4 times\n";
}

# In-between 2,5 times
if ($b =~ m/e{2,5}/) {
    print "In-between 2,5 times\n";
} else {
    print "Not in-between 2,5 times\n";
}

# Include man then whatever
if ($b =~ m/man*/) {
    print "Includes\n";
} else {
    print "Doesn't include\n";
}

# Include an e then whatever then another e
if ($b =~ m/e*e/) {
    print "Includes\n";
} else {
    print "Doesn't include\n";
}

# g must exist then at least one o letter followed by an optional g
$c = "go gooo gone begun begone";
$j=0;
foreach $i (split(' ',$c)) {
    if ($i =~ m/go+g?/) {
        print "+ ";
        $j+=1;
    }else {
        print "- ";
    }
    print "$i\n";
}
print $c, ":", $j, "\n";


#******************************************************************************
#                               String Operators
#******************************************************************************
#
# Operator | Function
# eq       | ==
# ne       | !=
# gt       | >
# ge       | >=
# lt       | <
# le       | <=


$v1 = "Hello World";
$v2 = "Hello Everyone";

print "Logic Operators\n";
print "$v1 eq $v2 = ", $v1 eq $v2, "\n";
print "$v1 ne $v2 = ", $v1 ne  $v2, "\n";
print "$v1 gt $v2 = ", $v1 gt  $v2, "\n";
print "$v1 lt $v2 = ", $v1  lt $v2, "\n";
print "$v1 ge $v2 = ", $v1 ge  $v2, "\n";
print "$v1 le $v2 = ", $v1 le  $v2, "\n";
