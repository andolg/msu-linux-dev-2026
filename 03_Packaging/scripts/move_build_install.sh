#!/bin/bash

mkdir -p ~/RPM/{SOURCES,SPECS}

cp show-example-0.1.tar.gz ~/RPM/SOURCES/
cp show-example.spec ~/RPM/SPECS/

rpmbuild --define '_allow_root_build 1' -ba ~/RPM/SPECS/show-example.spec

apt-get install /root/RPM/RPMS/x86_64/show-example-0.1-alt1.x86_64.rpm