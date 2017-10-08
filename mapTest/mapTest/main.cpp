#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>

using namespace std;



map<string,string> getArea(map<string, string> mapped) {

	string line;
	ifstream myfile("adventure.txt");

	// add in whats left of line into mapped <map>
	string a = line;

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			// find all the 'name'  metadat until you reach the end
			if (line.find("name") != std::string::npos) {

				// print it out 
				std::cout << line << std::endl;

				// erase line meta data from front to x 
				line.erase(line.begin(), line.end() - 15);

				//erase line metadata from x to end
				line.erase(line.begin() + 8, line.end());

				string a = line;

				// add in whats left of line into mapped <map>
				mapped[a] = "c";
			}
		}

		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				if (line.find("direction") != std::string::npos) {

					// print it out 
					std::cout << line << std::endl;

					// erase line meta data from front to x 
					line.erase(line.begin(), line.end() - 15);

					//erase line metadata from x to end
					line.erase(line.begin() + 8, line.end());

					// add in whats left of line into mapped <map>
					string b = line;

					// add in whats left of line into mapped <map>
					mapped[a] = b;

					//itreate from the start of the line to the end 
					for (auto it = mapped.begin(); it != mapped.end() ; ++it) {
						std::cout << it->first << it->second << "  = a map entry into the map." << endl;
					}
				}
			}
		}
		myfile.close();
	}
	return mapped;
};

unordered_multimap<string, string> getMap( unordered_multimap<string, string> mapped2)
{
	string line;
	ifstream myfile("adventure.txt");

	// add in whats left of line into mapped <map>
	string a = line;
	// add in whats left of line into mapped <map>
	//typedef unordered_multimap<string, string> defineArea; defineArea ;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			// find all the 'name'  metadat until you reach the end
			if (line.find("name") != std::string::npos) {
				// print it out 
				std::cout << line << std::endl;

				// erase line meta data from front to x 
				line.erase(line.begin(), line.end() - 15);

				//erase line metadata from x to end
				line.erase(line.begin() + 8, line.end());

				// add in whats left of line into mapped <map>
				string a = line;

				// add in whats left of line into mapped <map>
				mapped2.insert({ a, "b" });
				mapped2.insert({ a, "c" });

				//itreate from the start of the line to the end 
				for (auto it = mapped2.begin(); it != mapped2.end(); ++it) {
					std::cout << it->first << " " << it->second << "  = a map entry into the map." << endl;
				}
				}
			}
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				// find all the 'name'  metadat until you reach the end
				if (line.find("name") != std::string::npos) {
					// print it out 
					std::cout << line << std::endl;

					// erase line meta data from front to x 
					line.erase(line.begin(), line.end() - 15);

					//erase line metadata from x to end
					line.erase(line.begin() + 8, line.end());

					// add in whats left of line into mapped <map>
					string b = line;

					// add in whats left of line into mapped <map>
					mapped2.insert({ a, b });
					//mapped2.insert("a", "b");

					//itreate from the start of the line to the end 
					for (auto it = mapped2.begin(); it != mapped2.end(); ++it) {
						std::cout << it->first << " " << it->second << "  = a map entry into the map." << endl;
					}
				}
			}
		}
			
		}
std::cout << "end of the line";
	myfile.close();
		return mapped2;
};



int main() {

	string mystring;
	typedef unordered_multimap<string, string> defineArea;
	map<string, string> mapped;

	mapped ["one","cat"];
	mapped ["egg", "bat"];

	defineArea mapped2;
	mapped2.insert(defineArea::value_type("a", "b"));
	mapped2.insert(defineArea::value_type("a", "c"));
	mapped2.insert(defineArea::value_type("b", "b"));
	getMap( mapped2);

	for (auto it = mapped2.begin(); it != mapped2.end(); it++) {
		cout << it->first << '\t';
		cout << it->second << endl;
	}

	for (auto it = mapped.begin(); it != mapped.end(); ++it) {
		cout << it->first << "  = map entry into the map." << endl;
		cout << it->second << " = 2nd entry" << endl;
	}

	cout << "Entries with a:";
	auto range = mapped2.equal_range("a");
	for_each(
		range.first,
		range.second,
		[](defineArea::value_type& x) {std::cout << " " << x.second << endl; }
	);

	mapped = getArea(mapped);
	
	cout << mapped.size()<< " entries into the map ." << endl;

	auto it2 = mapped.find("cat");
	
	cout << "we found with it2->first : " << it2->first << endl;
	cout << "we found with move 'one' : " << move(mapped["one"]) << endl;

	for (auto it = mapped.begin(); it != mapped.end(); ++it) {
		cout  << it->first  << " entry into the map." << endl;
	}
	cin >> mystring;

	return 0;
};