#!/usr/bin/env perl
use v5.14;

my $name = $ARGV[0] // "foobar.h";
my $fh = *STDOUT;
if ($ARGV[0]) {
	my $cname = $name =~ s/\.(h+)/".".("c" x length($1))/er;
	open $fh, ">", $cname unless -f $cname;
}

say $fh "#include \"$name\"";
say $fh "";

my $class;
while (<>) {
	chomp;
	s/\/\/.*$//;
	s/^\s*//;
	s/\s*$//;

	$class = $1 if /^class (\w+)\b/;
	if (/(~?\w+)\s*(\(.*\));$/) {
		my ($type, $fname, $args) = ($`, $1, $2);
		$type =~ s/\s*$//;
		$type =~ s/\s*\bvirtual\b\s*//;
		say $fh "";
		say $fh $type if $type;
		say $fh $class."::".$fname.$args." {";
		say $fh "}";
	}
}
