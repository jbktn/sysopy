zad1.
pidof stackheap
cat /proc/[pid]/smaps | grep -i rss | awk '{sum += $2} END {print sum " KB"}'
htop

zad2.
vmstat -t 1
free -s 1

zad3.
Dotyczy sesji użytkownika
ulimit -v 1000000

zad4.
strace date
strace ./test
pokaże komunikację programu z jądrem systemu w formie tekstu
