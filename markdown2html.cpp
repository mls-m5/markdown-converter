#include <iostream>
#include <fstream>
#include <string>

using namespace std;


string listTag = "";



string beginTag(string tag) {
	return "<" + tag + ">";
}

string endTag(string tag) {
	return "</" + tag + ">";
}

string encapsulate(string text, string tag) {
	return "<" + tag + ">" + text + "</" + tag + ">";
}



string tryBeginList(string tag) {
	if (listTag.empty()) {
		listTag = tag;
		return beginTag(tag) + "\n";
	}
	return "";
}

string tryEndList() {
	if (not listTag.empty()){
		auto tag = listTag;
		listTag = "";
		return endTag(tag) + "\n";
	}
	return "";
}



string processLine(string line, string nextLine) {
	auto c = line[0];
	auto nc = nextLine[0];
	string returnString;
	if (c == '=' or c == '-') {
		return "";
	}
	else if (c == '#') {
		int headerLevel = 0;
		auto headerContent = line;
		while (headerContent.front() == '#') {
			headerContent = headerContent.substr(1);
			headerLevel ++;
		}

		while (headerContent.back() == '#' or isspace(headerContent.back())) {
			headerContent.pop_back();
		}

		auto tagName = to_string(headerLevel);

		return encapsulate(headerContent, "h" + tagName);
	}
	else if (c == '*') {
		auto listHead = tryBeginList("ul");
		auto content = line.substr(1);

		return listHead + encapsulate(content, "li");
	}
	else if (isdigit(c) and line.find('.') != string::npos) {
		auto listHead = tryBeginList("ol");
		auto f = line.find('.');
		auto content = line.substr(f + 1);

		return listHead + encapsulate(content, "li");
	}
	else {
		returnString += tryEndList();
	}

	if (nc == '=') {
		return returnString + encapsulate(line, "h1");
	}
	else if (nc == '-') {
		return returnString + encapsulate(line, "h2");
	}
	return returnString + "<p>" + line + "</p>";
}


int main() {
	fstream file("README.md");
	
	string line;
	string previousLine;
	
	while (file) {
		getline(file, line);
		cout << processLine(previousLine, line) << endl;
		
		
		
		previousLine = line;
	}
}
