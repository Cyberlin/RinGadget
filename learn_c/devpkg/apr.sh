set -e
# go somewhere safe ,i.e /tmp
cd /tmp/
# get the source of apr
curl -L -O http://archive.apache.org/dist/apr/apr-1.4.6.tar.gz
# tar the package and go into it
tar -xvzf apr-1.4.6.tar.gz
cd apr-1.4.6
#configure and make and make install
./configure  --build=aarch64-unknown-linux-gnu
make
make install

cd /tmp
rm -rf apr-1.4.6 apr-1.4.6.tar.gz
#apr-utils
curl -L -O http://archive.apache.org/dist/apr/apr-util-1.4.1.tar.gz

# extract
tar -xzvf apr-util-1.4.1.tar.gz
cd apr-util-1.4.1

# configure, make, make install
./configure --with-apr=/usr/local/apr  --build=aarch64-unknown-linux-gnu
# you need that extra parameter to configure because
# apr-util can't really find it because...who knows.

make
make install

#cleanup
cd /tmp
rm -rf apr-util-1.4.1* apr-1.4.6*

