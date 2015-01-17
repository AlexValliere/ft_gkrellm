# ft_gkrellm

hostname - #include <unistd.h> - gethostname() / uname -n
username - #include <unistd.h> - getlogin_r() / exec - whoami
OS info - #include <sys/utsname.h> - uname() / exec - uname -sri
Time data -  timedatectl
CPU - cat /proc/cpuinfo
ram - #include <sys/sysinfo.h> sysinfo() / cat /proc/meminfo  / free -m
network - ifconfig -a

   
