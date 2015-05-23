

markdown-cpp: all

all:
	g++ markdown2html.cpp -o md2html -std=c++1y -g
	g++ markdown2latex.cpp -o md2tex -std=c++1y -g
