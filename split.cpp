#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> split(std::string toSplit, std::string delimeter)
{
	std::vector<std::string> ret;
	std::string token = "";
	size_t pos = 0;

	while ((pos = toSplit.find(delimeter)) != std::string::npos)
	{
		token = toSplit.substr(0, pos);
		ret.push_back(token);
		toSplit.erase(0, pos + delimeter.length());
	}
	ret.push_back(toSplit);
	return (ret);
}

int main(void)
{
	const std::string toSplit = "123 456 789";
	const std::string delimeter = " ";
	std::vector<std::string> ret;
	ret = split(toSplit, delimeter);

	for (auto i : ret)
		std::cout << i << std::endl;

	return (0);
}