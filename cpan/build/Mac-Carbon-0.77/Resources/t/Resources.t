#!/usr/bin/perl -w
use Test::More;
use strict;

BEGIN { plan tests => 1 }

use Mac::Resources;

SKIP: {
#	skip "Mac::Resources", 1;
	ok(1);
}

__END__

Perl -Sx "{0}" {"Parameters"}; Exit {Status}

#!perl
#
# Resources.t - Demonstrate Resources
#

use Mac::Resources;
use Mac::Memory;
use Mac::StandardFile;

$file = $ARGV[0] || StandardGetFile(0, '');
$res = OpenResFile($file->sfFile) || die "$^E";

print "Types: ", Count1Types(), "\n\n";

for ($types = Count1Types(); $types; --$types) {
	$type = Get1IndType($types);
	print "Resources of type �$type�: ", Count1Resources($type), "\n";
	for ($rsrcs = Count1Resources($type); $rsrcs; --$rsrcs) {
		$rsrc = Get1IndResource($type, $rsrcs);
		my($id, $type, $name) = GetResInfo($rsrc);
		printf("%4s %6d %s\n", $type, $id, $name);
	}
}

CloseResFile($res);
