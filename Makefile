run:
	g++ /home/mohamed-othman/CLionProjects/MIME_OS/src/main.cpp \
        /home/mohamed-othman/CLionProjects/MIME_OS/src/kernel/process/Process.cpp -o main

build:
	g++ /home/mohamed-othman/CLionProjects/MIME_OS/src/main.cpp /home/mohamed-othman/CLionProjects/MIME_OS/src/kernel/process/Process.cpp -Iinclude -o main
