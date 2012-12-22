#!/usr/bin/env perl
use v5.14;

my $name = $ARGV[0] // "foobar.h";

say "#include \"$name\"";
say "";

my $class;
while (<>) {
	chomp;
	s/\/\/.*$//;
	s/^\s*//;
	s/\s*$//;

	$class = $1 if /^class (\w+)\b/;
	if (/(~?\w+)\s*(\(.*\));$/) {
		say "";
		say $` if $`;
		say $class."::".$1." ".$2." {";
		say "}";
	}
}
