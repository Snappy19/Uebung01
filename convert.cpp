#include <iostream>

int main(int argc, char* argv[])
{
	if(argc < 3) {
		std::cerr << "Not enough arguments!\nUsage:\n\t" << argv[0]
		          << " chr1.fa chr1.fa.2bit\nor\n\t" << argv[0]
		          << " chr1.fa.2bit chr1.fa\n";

		return -1;
	}

	return 0;
}

