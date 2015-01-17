#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>


int	main() {
	std::ifstream						fileInput("/proc/cpuinfo");
	std::string							fileLine;
	std::map<std::string, std::string>	cpu_info;
	std::vector<std::string>			cpu_cores_speed;
	std::string							data;

	std::size_t	index;

	while (std::getline(fileInput, fileLine))
	{
		index = fileLine.find("model name");
		if (index != std::string::npos)
		{
			index = fileLine.find(":");
			cpu_info["model_name"] = fileLine.substr(index + 2);
		}

		index = fileLine.find("cpu cores");
		if (index != std::string::npos)
		{
			index = fileLine.find(":");
			cpu_info["cores"] = fileLine.substr(index + 2);
		}

		
		index = fileLine.find("vendor_id");
		if (index != std::string::npos)
		{
			index = fileLine.find(":");
			cpu_info["vendor_id"] = fileLine.substr(index + 2);
		}

		index = fileLine.find("cpu MHz");
		if (index != std::string::npos)
		{
			index = fileLine.find(":");
			cpu_cores_speed.push_back(fileLine.substr(index + 2));
		}
	}

	data =  "CPU name : " + cpu_info["model_name"] + " | ";
	data = data + "CPU vendor ID : " + cpu_info["vendor_id"] + " | ";
	data = data + "CPU cores : " + cpu_info["cores"] + " | ";

	if (atoi(cpu_info["cores"].c_str()) > 0)
	{
		std::vector<std::string>::iterator	it;
		int	coreId = 0;

		for (it = cpu_cores_speed.begin(); it != cpu_cores_speed.end(); it++)
		{
			data =  data + "CPU speed core #" + ft_itoa(coreId) + " : " + *it;
			++coreId;
		}
	}

	std::cout << data << std::endl;

	return 0;
}