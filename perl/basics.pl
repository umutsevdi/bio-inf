#!/usr/bin/perl -w

use warnings;
#******************************************************************************
#
# * File: basics.pl
#
# * Author:  Umut Sevdi
# * Created: 03/21/23
# * Description: An introduction to the most amazing programming language ever
# existed
#*****************************************************************************

# Welcome to Perl, most amazing programming language in the world.

#******************************************************************************
#                               Introduction
#******************************************************************************

# Of course Perl won't place a new line character for you. Do it yourself lazy
# pal.

print "This piece of text wont place new line at the end. ";
print "Hello World\n";

# Assign a variable using $ sign 
$x = 20;
if ($x>20) {
    print "greater\n";
} elsif ($x < 20) {
    print "lesser\n";
}else {
    print "equal\n";
}

# This section of perl makes some sense. It works like a normal language.

$v1 = 7;
$v2 = 3;

# Classic for loop example
for ($i=0; $i<$v1; $i++) {
    print "$i ";
}
print "\n";

print "Arithmetic Operators\n";
print "$v1 +  $v2 = ", $v1 +  $v2, "\n";
print "$v1 -  $v2 = ", $v1 -  $v2, "\n";
print "$v1 *  $v2 = ", $v1 *  $v2, "\n";
print "$v1 ** $v2 = ", $v1 ** $v2, "\n"; # ex
print "$v1 /  $v2 = ", $v1 /  $v2, "\n";
print "$v1 %  $v2 = ", $v1 %  $v2, "\n";

print "Logic Operators\n";
print "$v1 == $v2 = ", $v1 == $v2, "\n";
print "$v1 != $v2 = ", $v1 != $v2, "\n";
print "$v1 >  $v2 = ", $v1 >  $v2, "\n";
print "$v1 <  $v2 = ", $v1 <  $v2, "\n";
print "$v1 >= $v2 = ", $v1 >= $v2, "\n";
print "$v1 <= $v2 = ", $v1 <= $v2, "\n";
print "$v1 && $v2 = ", $v1 && $v2, "\n";
print "$v1 || $v2 = ", $v1 || $v2, "\n";

# Normal part ends here.
# In Perl arrays start with a cool @ symbol. We can access values using [].
# Using the array as itself return it's length.
print "Array\n";
@number = (40, 55, 63, 17, 22, 68, 89, 97, 89);

foreach $i (@number) {
    print "$i ";
}
print "\n";

# Hashmaps don't have a cool symbol. But the way you access them is weird af.
# Because Perl can never be normal.
$Fruit{'Mango'} = 10; 
$Fruit{'Apple'} = 20; 
$Fruit{'Strawberry'} = 30; 
  
# printing elements of Hash
print "Printing values of Hash:\n";
print "$Fruit{'Mango'}\n";
print "$Fruit{'Apple'}\n";
print "$Fruit{'Strawberry'}\n";
  
# Perl also have a more weird Initialization syntax when it comes to 
# initialization. Initializing is done on Hash using '=>'
%Fruit2 = ('Mango' => 45, 'Apple' => 42, 'Strawberry' => 35);
  
print "\nPrinting values of Hash:\n";
print "$Fruit2{'Mango'}\n";
print "$Fruit2{'Apple'}\n";
print "$Fruit2{'Strawberry'}\n", "";

# Functions are called subroutines because why not
sub ask_user() {
    print "Hello from subroutine!\n";
} 
ask_user();

# Who needs explicitly defined parameters?
sub print_values {
    my ($value1, $value2) = @_;

    if (defined $value2) {
        print "Value1: $value1, Value2: $value2\n";
    } else {
        print "Value1: $value1\n";
    }
}

print_values(10);     # prints "Value1: 10"
print_values(10, 20); # prints "Value1: 10, Value2: 20"
