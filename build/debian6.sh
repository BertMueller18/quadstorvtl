#!/bin/sh
set -x
version="3.0.26"
sh buildinit.sh debian6
sh debiancore.sh
mv debian.deb quadstor-vtl-core-$version-x86_64.deb
sh debianitf.sh
mv debian.deb quadstor-vtl-itf-$version-x86_64.deb
