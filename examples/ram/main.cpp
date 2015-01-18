/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qde-vial <qde-vial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 12:46:47 by hades             #+#    #+#             */
/*   Updated: 2015/01/18 16:54:22 by qde-vial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include <sys/types.h>
 #include <sys/sysctl.h>
#include <unistd.h>
#include <iostream>
#include <mach/vm_param.h>
#include <sys/gmon.h>
#include <sys/socket.h>
#include <mach/vm_statistics.h>
#include <mach/mach_types.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>

// int main(void)
// {
// 	size_t c;
// 	int mib[5];
// 	mib[0] = CTL_HW;
// 	mib[1] = HW_MEMSIZE;		/* OSX. --------------------- */
// 	mib[2] = HW_PHYSMEM;		/* OSX. --------------------- */
// 	mib[3] = VM_V_PAGEOUT_FREE_MIN;		/* OSX. --------------------- */
// 	int64_t size = 0;		/* 64-bit */
// 	size_t len = sizeof( size );
// 	if ( sysctl( mib, 2, &size, &len, NULL, 0 ) == 0 ){
// 		c = (size_t)size;
// 		std::cout << mib[0] << std::endl;
// 		std::cout << mib[1] << std::endl;
// 		std::cout << mib[2] << std::endl;
// 		std::cout << mib[3] << std::endl;
// 		return (size_t)size;
// 	}
// 	return 0L;
// }


int main(int argc, const char * argv[]) {
    vm_size_t page_size;
    mach_port_t mach_port;
    mach_msg_type_number_t count;
    vm_statistics64_data_t vm_stats;

    mach_port = mach_host_self();
    count = sizeof(vm_stats) / sizeof(natural_t);
    if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
        KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
                                        (host_info64_t)&vm_stats, &count))
    {
        long long free_memory = (int64_t)vm_stats.free_count * (int64_t)page_size;

        long long used_memory = ((int64_t)vm_stats.active_count +
                                 (int64_t)vm_stats.inactive_count +
                                 (int64_t)vm_stats.wire_count) *  (int64_t)page_size;
        printf("free memory: %lld\nused memory: %lld\n", free_memory, used_memory);
    }

    int mib[2];
	int64_t physical_memory;
	mib[0] = CTL_HW;
	mib[1] = HW_MEMSIZE;
	size_t length = sizeof(int64_t);
	sysctl(mib, 2, &physical_memory, &length, NULL, 0);
	std::cout << "total ram available : " << physical_memory << std::endl;

    return 0;
}

