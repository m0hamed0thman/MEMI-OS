run:
	./mime-os

build:
	g++ /home/mohamed-othman/CLionProjects/MIME_OS/src/main.cpp /home/mohamed-othman/CLionProjects/MIME_OS/src/kernel/process/Process.cpp -Iinclude -o main

runmy:
	g++ /home/mohamed-othman/CLionProjects/MIME_OS/src/main.cpp /home/mohamed-othman/CLionProjects/MIME_OS/src/kernel/logging/Logger.cpp -o mime-os

buildshell:
	g++ /home/mohamed-othman/CLionProjects/MIME_OS/src/main.cpp /home/mohamed-othman/CLionProjects/MIME_OS/src/kernel/logging/Logger.cpp /home/mohamed-othman/CLionProjects/MIME_OS/src/utils/StringUtils.cpp /home/mohamed-othman/CLionProjects/MIME_OS/src/shell/Shell.cpp /home/mohamed-othman/CLionProjects/MIME_OS/src/shell/Commands.cpp -o mime-os