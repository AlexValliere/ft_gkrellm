# ft_gkrellm
hostname - #include <unistd.h> - gethostname() / uname -n

username - #include <unistd.h> - getlogin_r() / exec - whoami

OS info - #include <sys/utsname.h> - uname() / exec - uname -sri

Date/Time - #include <unistd.h> - time() / exec - timedatectl

----------

CPU : Model, clock speed, number of cores, activity, ...

	cpu usage : http://stackoverflow.com/questions/3017162/how-to-get-total-cpu-usage-in-linux-c
	
	model/number of cores/speed cpu : cat /proc/cpuinfo (http://stackoverflow.com/questions/9629850/how-to-get-cpu-info-in-c-on-linux-such-as-number-of-cores)
	
RAM : - #include <sys/sysinfo.h> - sysinfo / exec - cat /proc/meminfo

	exec - free -m (http://askubuntu.com/questions/9642/how-can-i-monitor-the-memory-usage)
	
----------

Network throughput

	exec - iconfig -a ou iconfig interface (interface from iconfig) (http://askubuntu.com/questions/257263/how-to-display-network-traffic-in-terminal)
	
----------

Cool things
