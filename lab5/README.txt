sudo dd if=/dev/zero of=zero.dat bs=1M count=100

sudo dd if=/dev/urandom of=losowy.dat bs=1M count=100

sudo dd if=/dev/urandom of=tmp.dat bs=1M count=10
cat tmp.dat tmp.dat tmp.dat tmp.dat tmp.dat tmp.dat tmp.dat tmp.dat tmp.dat tmp.dat > powielony-10MB.dat
rm tmp.dat

sudo dd if=/dev/urandom of=tmp.dat bs=1K count=1
cat tmp.dat tmp.dat tmp.dat tmp.dat tmp.dat tmp.dat tmp.dat tmp.dat tmp.dat tmp.dat > powielony-1kB.dat
rm tmp.dat

zad 1.1
gzip zero.dat -c > zero.dat.gz
ls -la

zad 1.2
ln -s losowy.dat losowy-soft.dat
ln losowy.dat losowy-hard.dat
ls -lh losowy.dat losowy-soft.dat losowy-hard.dat

zad 1.3
mkfs.ext4 zero.dat
/Documents/lab5/zero.dat /mntpoint ext4 user,noauto 0 0
mount /Documents/lab5/zero.dat
umount /Documents/lab5/zero.dat