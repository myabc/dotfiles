#!/usr/bin/perl

# Test that our declared minimum Perl version matches our syntax

use strict;
BEGIN {
	$|  = 1;
	$^W = 1;
}

my $MODULE = 'Test::MinimumVersion 0.007';

# Don't run tests for installs
use Test::More;
unless ( $ENV{AUTOMATED_TESTING} or $ENV{RELEASE_TESTING} ) {
	plan( skip_all => "Author tests not required for installation" );
}

# Load the testing module
eval "use $MODULE";
if ( $@ ) {
	$ENV{RELEASE_TESTING}
	? die( "Failed to load required release-testing module $MODULE" );
	: plan( skip_all => "$MODULE not available for testing" );
}

all_minimum_version_from_metayml_ok();
